.EXTRA_PREREQS := $(abspath $(lastword $(MAKEFILE_LIST)))

.DEFAULT_GOAL := all

# A rule whose check fails deletes what it made, so that make runs it again
.DELETE_ON_ERROR:

-include local.mk

# The version of the game to build. Each one has its settings in
# mk/version/<version>.mk: the executable's name, the disc, the overlays and
# the source files. The C and the assembly see VERSION_US and VERSION_EU, the
# one being built as 1 and the other as 0 (include/version.h).
VERSION ?= eu
VERSIONS := eu us
ifeq ($(filter $(VERSION),$(VERSIONS)),)
$(error unsupported VERSION $(VERSION); supported: $(VERSIONS))
endif
VERSION_UPPER := $(shell echo $(VERSION) | tr a-z A-Z)
include mk/version/$(VERSION).mk
# the tools read it too (tools/version.py)
export VERSION

TOOLCHAIN ?= mipsel-linux-gnu-

# splat configs, symbols and checksums
CONFIG_DIR := config/$(VERSION)
BUILDDIR := build/$(VERSION)
ASM_DIR := asm/$(VERSION)
ASSETS_DIR := assets/$(VERSION)
EXPECTEDDIR := expected/$(VERSION)
GENDIR := $(BUILDDIR)/generated

# A padding build (make padcheck) links every binary PAD bytes higher, from
# the same objects, into its own directory
PAD := 0
LINKDIR := $(BUILDDIR)$(if $(filter-out 0,$(PAD)),/pad$(PAD))

ELF := $(LINKDIR)/$(EXE_NAME).elf
EXE := $(LINKDIR)/$(EXE_NAME)
MAP := $(LINKDIR)/$(EXE_NAME).map

CPP := $(TOOLCHAIN)cpp
AS := $(TOOLCHAIN)as
LD := $(TOOLCHAIN)ld
OBJCOPY := $(TOOLCHAIN)objcopy

PYTHON := python3
SPLAT := $(PYTHON) -m splat split

# the prebuilt compiler and tools that tools/dl_deps.sh downloads; the
# Docker image keeps its own outside the repository and sets BIN_DIR
BIN_DIR ?= bin

GCC_VERSION ?= 2.8.1
CC1 ?= $(BIN_DIR)/gcc-$(GCC_VERSION)-psx/cc1

MASPSX := $(PYTHON) external/maspsx/maspsx.py
OBJDIFF ?= $(BIN_DIR)/objdiff-cli-linux-x86_64

INC := -Iinclude -Iexternal/psyq_headers/psyq_lib47/include

# -DVERSION_<VERSION>: include/version.h turns it into VERSION_US and
# VERSION_EU, each 0 or 1, for #if; -Wundef warns about an #if on a name
# that isn't defined, such as a misspelt version
CPPFLAGS = $(INC) -undef -nostdinc -Wundef \
	    -D__GNUC__=2 -D__GNUC_MINOR__=$(word 2,$(subst ., ,$(GCC_VERSION))) -Dmips -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx \
	    -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C \
	    -DVERSION_$(VERSION_UPPER) -DASM_DIR='"$(ASM_DIR)"'
# -membedded-data: the game's code puts a small const in .rodata, not .sdata,
# and reads it with lui/lw even at -G8 (OVERLAY_ADDRESS in system.c); it
# changes nothing else
CC1FLAGS = -quiet -O2 -G$(SDATA_LIMIT) -mips1 -mcpu=3000 -mgas -msoft-float \
	    -fgnu-linker -fsigned-char -fno-builtin -fdollars-in-identifiers -Wall -Wno-unused -membedded-data
MASPSXFLAGS = --aspsx-version=2.86 -G$(SDATA_LIMIT) --use-comm-section --use-comm-for-lcomm

# Most of the game is built with -G0; graphics.c reads its own small variables
# through $gp. GFX_STARTED is its one .sdata variable; the .sbss pointers are
# declared static, so maspsx emits them as common symbols that resolve to the
# definitions in data/game_bss.c, 8 bytes apart as the linker laid them. With
# -G8 GCC leaves the address of a small extern (LANGUAGE in inn.c,
# memcard.c and game3.c, in the European version) to the assembler, which loads it
# again for each read.
SDATA_LIMIT := 0
$(BUILDDIR)/src/main/inn.c.o: SDATA_LIMIT := 8
$(BUILDDIR)/src/main/memcard.c.o: SDATA_LIMIT := 8
$(BUILDDIR)/src/main/game3.c.o: SDATA_LIMIT := 8
$(BUILDDIR)/src/main/system.c.o: SDATA_LIMIT := 8
$(BUILDDIR)/src/main/graphics.c.o: SDATA_LIMIT := 8
$(BUILDDIR)/src/main/sound.c.o: SDATA_LIMIT := 8
$(BUILDDIR)/src/main/overlay.c.o: SDATA_LIMIT := 8
$(BUILDDIR)/src/main/game3_2.c.o: SDATA_LIMIT := 8
# the assembly sees every version as 0 or 1 too: .if VERSION_EU
ASFLAGS := -EL -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0 $(INC) \
	   $(foreach v,$(VERSIONS),--defsym VERSION_$(shell echo $(v) | tr a-z A-Z)=$(if $(filter $(v),$(VERSION)),1,0))
# the hand-written symbols the executable links with (a version that is
# still blobs has none)
UNDEFINED_SYMS := $(wildcard $(CONFIG_DIR)/undefined_syms.txt)
# Every binary links with the memory map's addresses (EXE_VRAM,
# OVERLAY_VRAM, STAGE_VRAM, from mk/version/<version>.mk): where the
# executable loads, where it loads the overlays, and where they link
MEMORY_MAP := $(foreach a,EXE_VRAM OVERLAY_VRAM STAGE_VRAM,--defsym $(a)=$($(a))+$(PAD))
# The executable links with its children's symbols too (CHILDREN_template)
MAIN_AUTO_SYMS := $(GENDIR)/undefined_syms_auto_main.txt $(GENDIR)/undefined_funcs_auto_main.txt
MAIN_IMPORTS := $(LINKDIR)/main_imports.ld
LDFLAGS := -nostdlib --no-check-sections --emit-relocs -Map $(MAP) \
	   $(MEMORY_MAP) -T $(GENDIR)/main.ld \
	   $(addprefix -T ,$(UNDEFINED_SYMS) $(MAIN_AUTO_SYMS) $(MAIN_IMPORTS))

# The stage overlays the version has, from $(CONFIG_DIR)/stages.txt
STAGES := $(shell awk '!/^\#/ && NF { print tolower($$1) }' $(CONFIG_DIR)/stages.txt)

# C_SRC, from mk/version/<version>.mk, has every binary's C files, but of
# src/stages/ only the version's stages' (the USA version hasn't the European
# stages), with the head a stage may have (<name>_head.c, see
# tools/stage_yaml.py)
STAGE_C_SRC := $(STAGES:%=src/stages/%.c) $(STAGES:%=src/stages/%_head.c)
ALL_C_SRC := $(filter-out $(filter-out $(STAGE_C_SRC),$(filter src/stages/%,$(C_SRC))),$(C_SRC))
MAIN_C_SRC := $(filter src/main/%,$(ALL_C_SRC))

# Target objects for objdiff: splat's full disassembly of every C unit (the
# data files, src/<binary>/data/, and the stages with no code, "data" in
# $(CONFIG_DIR)/stages.txt, have none: objdiff_generate.py compares them with
# splat's data files), and a stage's head's rodata
STAGE_HEADS := $(filter src/stages/%_head.c,$(ALL_C_SRC))
DATA_STAGES := $(shell awk '!/^\#/ && $$2 == "data" { print tolower($$1) }' $(CONFIG_DIR)/stages.txt)
TARGET_ASM := $(filter-out $(foreach b,main $(OVERLAYS),$(ASM_DIR)/$(b)/data/%) $(DATA_STAGES:%=$(ASM_DIR)/stages/%.s),\
	      $(patsubst src/%.c,$(ASM_DIR)/%.s,$(filter-out $(STAGE_HEADS),$(ALL_C_SRC)))) \
	      $(STAGE_HEADS:src/stages/%.c=$(ASM_DIR)/stages/data/%.rodata.s)

ASM_SRC := $(filter-out $(TARGET_ASM) $(ASM_DIR)/main/header.s,$(shell find $(ASM_DIR)/main -name '*.s' \
	   -not -path '*/nonmatchings/*' -not -path '*/matchings/*' 2> /dev/null))

C_OBJ := $(MAIN_C_SRC:%.c=$(BUILDDIR)/%.c.o)
# The executable's header is source too (src/main/header.s), built where
# main.ld looks for splat's
HEADER_OBJ := $(BUILDDIR)/$(ASM_DIR)/main/header.s.o
ASM_OBJ := $(ASM_SRC:%.s=$(BUILDDIR)/%.s.o) $(HEADER_OBJ)
TARGET_OBJ := $(TARGET_ASM:%.s=$(BUILDDIR)/%.s.o)
# the one blob the build links (tools/inputcheck.py): the executable's tail,
# a picture, which holds no addresses
BIN_OBJ := $(BUILDDIR)/$(ASSETS_DIR)/tail.bin.o
OBJ := $(C_OBJ) $(ASM_OBJ) $(BIN_OBJ)

# Overlays: the game's AAA/PRO/*.PRO files, loaded at 0x80082448 after the
# executable's .bss. Each one, from the version's OVERLAYS, has its own splat
# config ($(CONFIG_DIR)/<name>.yaml), sources (src/<name>, $(ASM_DIR)/<name>)
# and output ($(BUILDDIR)/AAA/PRO/<FILE>.PRO), and is linked against the
# executable's symbols (MAIN_SYMS).
$(foreach o,$(OVERLAYS),$(eval OVL_FILE_$(o) := $(shell echo $(o) | tr a-z A-Z).PRO))
# WFIGHTMN and WFIGHTTS load with FIGHTSTG, after it
OVL_PARENT_wfightmn := fightstg
OVL_PARENT_wfightts := fightstg
# and FIGHTSTG calls their functions (CHILDREN_template)
CHILDREN_fightstg := wfightmn wfightts
# The executable calls the mode overlays' entry points (MODE_ENTRY_POINTS),
# and game3.c FIELDSTG's functions
CHILDREN_main := $(filter-out wfightmn wfightts,$(OVERLAYS))

# The stage overlays (AAA/PRO/WSTAG###.PRO), listed in
# $(CONFIG_DIR)/stages.txt, load on top of FIELDSTG. Their splat configs are
# made by tools/stage_yaml.py and their sources are src/stages/<name>.c and
# $(ASM_DIR)/stages/.
OVERLAYS += $(STAGES)
$(foreach s,$(STAGES),\
	$(eval OVL_FILE_$(s) := $(shell echo $(s) | tr a-z A-Z).PRO)\
	$(eval OVL_PARENT_$(s) := fieldstg)\
	$(eval OVL_YAML_$(s) := $(GENDIR)/stages/$(s).yaml)\
	$(eval OVL_C_SRC_$(s) := src/stages/$(s).c src/stages/$(s)_head.c)\
	$(eval OVL_ASM_SRC_$(s) := $(wildcard $(ASM_DIR)/stages/data/$(s).*.s $(ASM_DIR)/stages/data/$(s).s $(ASM_DIR)/stages/data/$(s)_end.s $(ASM_DIR)/stages/$(s).s))\
	$(eval OVL_SYMBOLS_$(s) := $(wildcard $(CONFIG_DIR)/symbols_fieldstg.txt $(CONFIG_DIR)/stages/$(s).txt)))

# FIELDSTG starts the stages (FIELDSTG_stages), and links against their
# symbols (CHILDREN_template). The stages name theirs alike, so each stage
# gives its own prefixed with its name: WSTAG931_startStage (include/stages.h).
CHILDREN_fieldstg := $(STAGES)
$(STAGES:%=$(LINKDIR)/%_syms.ld): $(LINKDIR)/%_syms.ld: $(LINKDIR)/%.elf
	$(NM) $< | awk -v stage=$* '$$2 ~ /^[TDRBSG]$$/ { printf "%s_%s = 0x%s;\n", toupper(stage), $$3, $$1 }' > $@

$(GENDIR)/stages/%.yaml: $(CONFIG_DIR)/stages.txt tools/stage_yaml.py tools/version.py mk/version/$(VERSION).mk
	$(PYTHON) tools/stage_yaml.py $* $@

# The executable's own symbols for the overlays to link against (not the
# absolute ones it only references), from its layout link (CHILDREN_template)
NM := $(TOOLCHAIN)nm
NM_SYMS = $(NM) $< | awk '$$2 ~ /^[TDRBSG]$$/ { printf "%s = 0x%s;\n", $$3, $$1 }' > $@
MAIN_SYMS := $(LINKDIR)/main_syms.ld

# An overlay loaded on top of another one (OVL_PARENT_<name>) also links
# against its parent's symbols.
$(LINKDIR)/%_syms.ld: $(LINKDIR)/%.elf
	$(NM_SYMS)

# A binary that points into binaries that load after it, its children
# (CHILDREN_<name>), links against their symbols too: tools/link_imports.py
# picks those its objects use into $(BUILDDIR)/<name>_imports.ld. The
# children link against the binary's own symbols, so those come from a
# layout link of the binary alone, which gives the names its objects use
# placeholders ($(BUILDDIR)/layout/<name>.elf): MIPS links don't relax, and
# a binary's addresses don't depend on what it imports.
# $(1): the binary, $(2): its objects, $(3): its linker script, $(4): the
# other linker scripts it links with
define CHILDREN_template
$(LINKDIR)/$(1)_imports.ld: $(2) $(3) $(CHILDREN_$(1):%=$(LINKDIR)/%_syms.ld) tools/link_imports.py
	$(PYTHON) tools/link_imports.py $$@ $(2) --from $(CHILDREN_$(1):%=$(LINKDIR)/%_syms.ld) --linked $(4)

$(LINKDIR)/layout/$(1).ld: $(2) tools/link_imports.py
	@mkdir -p $$(dir $$@)
	$(PYTHON) tools/link_imports.py --placeholders $$@ $(2)

$(LINKDIR)/layout/$(1).elf: $(2) $(3) $(LINKDIR)/layout/$(1).ld
	$(LD) -nostdlib --no-check-sections $(MEMORY_MAP) -T $(3) -T $(LINKDIR)/layout/$(1).ld -o $$@

$(LINKDIR)/$(1)_syms.ld: $(LINKDIR)/layout/$(1).elf
	$$(NM_SYMS)
endef
$(eval $(call CHILDREN_template,main,$(OBJ),$(GENDIR)/main.ld,$(UNDEFINED_SYMS) $(MAIN_AUTO_SYMS)))

define OVERLAY_template
$(1)_C_SRC := $$(filter $$(or $$(OVL_C_SRC_$(1)),src/$(1)/%),$$(ALL_C_SRC))
$(1)_ASM_SRC := $$(filter-out $$(TARGET_ASM),$$(if $$(OVL_YAML_$(1)),$$(OVL_ASM_SRC_$(1)),\
	$$(shell find $$(ASM_DIR)/$(1) -name '*.s' \
	-not -path '*/nonmatchings/*' -not -path '*/matchings/*' 2> /dev/null)))
$(1)_OBJ := $$($(1)_C_SRC:%.c=$$(BUILDDIR)/%.c.o) $$($(1)_ASM_SRC:%.s=$$(BUILDDIR)/%.s.o)
C_OVL_OBJ += $$(filter %.c.o,$$($(1)_OBJ))

$$(GENDIR)/$(1).ld: .EXTRA_PREREQS :=
$$(GENDIR)/$(1).ld: $$(or $$(OVL_YAML_$(1)),$$(CONFIG_DIR)/$(1).yaml) $$(CONFIG_DIR)/symbols.txt \
		$$(or $$(OVL_SYMBOLS_$(1)),$$(wildcard $$(CONFIG_DIR)/symbols_$(1).txt))
	$$(SPLAT) $$< --disassemble-all --make-full-disasm-for-code
	@touch $$@

# what the overlay links with: the executable's symbols, its parent's and its
# own hand-written ones ($(CONFIG_DIR)/undefined_syms_<name>.txt)
$(1)_SYMS := $$(MAIN_SYMS) $$(if $$(OVL_PARENT_$(1)),$$(LINKDIR)/$$(OVL_PARENT_$(1))_syms.ld) \
	$$(wildcard $$(CONFIG_DIR)/undefined_syms_$(1).txt)
$(1)_AUTO_SYMS := $$(GENDIR)/undefined_syms_auto_$(1).txt $$(GENDIR)/undefined_funcs_auto_$(1).txt
# and its children's (CHILDREN_template)
$(1)_IMPORTS := $$(if $$(CHILDREN_$(1)),$$(LINKDIR)/$(1)_imports.ld)
$$(LINKDIR)/$(1).elf: $$($(1)_OBJ) $$(GENDIR)/$(1).ld $$($(1)_SYMS) $$($(1)_IMPORTS)
	@mkdir -p $$(dir $$@)
	$$(LD) -nostdlib --no-check-sections --emit-relocs -Map $$(LINKDIR)/$(1).map \
		$$(MEMORY_MAP) -T $$(GENDIR)/$(1).ld $$(addprefix -T ,$$($(1)_SYMS) $$($(1)_AUTO_SYMS) $$($(1)_IMPORTS)) -o $$@
	$$(PYTHON) tools/inputcheck.py $$(LINKDIR)/$(1).map $$($(1)_OBJ)

$$(LINKDIR)/AAA/PRO/$$(OVL_FILE_$(1)): $$(LINKDIR)/$(1).elf
	@mkdir -p $$(dir $$@)
	$$(OBJCOPY) -O binary $$< $$@
endef
$(foreach o,$(OVERLAYS),$(eval $(call OVERLAY_template,$(o))))
$(foreach o,$(OVERLAYS),$(if $(CHILDREN_$(o)),\
	$(eval $(call CHILDREN_template,$(o),$($(o)_OBJ),$(GENDIR)/$(o).ld,$($(o)_SYMS) $($(o)_AUTO_SYMS)))))
OVL_BIN := $(foreach o,$(OVERLAYS),$(LINKDIR)/AAA/PRO/$(OVL_FILE_$(o)))
OVL_ELF := $(OVERLAYS:%=$(LINKDIR)/%.elf)

all: $(EXE) $(OVL_BIN)

# Only rerun splat when its own inputs change, never for Makefile edits. splat
# leaves an unchanged linker script alone, so touch it or it reruns every time.
$(GENDIR)/main.ld: .EXTRA_PREREQS :=
$(GENDIR)/main.ld: $(CONFIG_DIR)/main.yaml $(CONFIG_DIR)/symbols.txt $(CONFIG_DIR)/symbols_main.txt
	$(SPLAT) $< --disassemble-all --make-full-disasm-for-code
	@touch $@

generate: $(GENDIR)/main.ld $(OVERLAYS:%=$(GENDIR)/%.ld)

regenerate: reset
	$(MAKE) generate

compare: $(EXE) $(OVL_BIN)
	@sha1sum -c $(CONFIG_DIR)/$(EXE_NAME).sha1 $(CONFIG_DIR)/overlays.sha1 $(CONFIG_DIR)/stages.sha1

$(EXE): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@truncate -s %2048 $@

$(ELF): $(OBJ) $(GENDIR)/main.ld $(UNDEFINED_SYMS) $(MAIN_IMPORTS)
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -o $@
	$(PYTHON) tools/inputcheck.py $(MAP) $(OBJ) --blobs $(BIN_OBJ)

# The addresses in the code and data that are numbers, which wouldn't move
# with it (tools/shiftcheck.py reads the relocations that --emit-relocs keeps
# in the ELFs): shiftcheck fails on those that $(CONFIG_DIR)/shiftcheck.txt
# doesn't list, shiftreport lists every one
shiftcheck shiftreport: $(ELF) $(OVL_BIN)
shiftcheck:
	$(PYTHON) tools/shiftcheck.py -v $(VERSION)
shiftreport:
	$(PYTHON) tools/shiftcheck.py -v $(VERSION) --all

# The game C's declarations, checked by a modern GCC that only parses it
# (tools/lint.py): it writes nothing, so the match never depends on it.
# LINT_ARGS: --update, --strict, --base REV
LINT_CC ?= $(TOOLCHAIN)gcc
lint: export LINT_CC := $(LINT_CC)
lint: export LINT_CPPFLAGS = $(CPPFLAGS)
lint: export LINT_SRC = $(ALL_C_SRC)
lint:
	$(PYTHON) tools/lint.py -v $(VERSION) $(LINT_ARGS)

# Padding builds: every binary linked PAD bytes higher, in which only the
# words with a relocation may change (tools/padcheck.py). 0x10004 carries
# into the upper half of every %hi/%lo pair.
PADS := 0x4 0x10004
links: $(ELF) $(OVL_ELF)
padcheck: links
	$(foreach p,$(PADS),$(MAKE) PAD=$(p) links && $(PYTHON) tools/padcheck.py -v $(VERSION) $(p) &&) true

# The executable's .bss in C: maspsx turns its commons into definitions in
# order in .bss when they aren't kept as .comm
$(BUILDDIR)/src/main/data/game_bss.c.o: MASPSXFLAGS := $(filter-out --use-comm-section,$(MASPSXFLAGS))

$(BUILDDIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -MMD -MP -MT $@ -MF $(@:.o=.d) $< -o $(@:.o=.i)
	$(CC1) $(CC1FLAGS) -o $(@:.o=.cc1.s) $(@:.o=.i)
	$(MASPSX) $(MASPSXFLAGS) < $(@:.o=.cc1.s) | $(PYTHON) tools/data_sizes.py | $(PYTHON) tools/comm_align.py > $(@:.o=.s)
	$(AS) $(ASFLAGS) -o $@ $(@:.o=.s)
	@$(OBJCOPY) --set-section-alignment .text=4 --set-section-alignment .rodata=4 $@

$(HEADER_OBJ): src/main/header.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# gas aligns these sections to 16 bytes, psylink packed them to 4
$(BUILDDIR)/%.s.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<
	@$(OBJCOPY) --set-section-alignment .text=4 \
				--set-section-alignment .rodata=4 \
				--set-section-alignment .data=4 \
				--set-section-alignment .bss=4 $@

$(BUILDDIR)/$(ASSETS_DIR)/%.bin.o: $(ASSETS_DIR)/%.bin
	@mkdir -p $(dir $@)
	$(LD) -r -b binary -o $@ $<

expected: $(TARGET_OBJ) $(C_OBJ) $(C_OVL_OBJ)
	rm -rf $(EXPECTEDDIR)
	@mkdir -p $(EXPECTEDDIR)
	cp -r $(BUILDDIR)/$(ASM_DIR) $(EXPECTEDDIR)/asm

objdiff: expected
	$(PYTHON) tools/objdiff_generate.py

report: objdiff
	$(OBJDIFF) report generate -o $(BUILDDIR)/report.json

clean:
	rm -rf $(BUILDDIR)

reset: clean
	rm -rf $(ASM_DIR) $(EXPECTEDDIR) $(ASSETS_DIR)

-include $(C_OBJ:.o=.d) $(C_OVL_OBJ:.o=.d)

.PHONY: all generate regenerate compare expected objdiff report clean reset shiftcheck shiftreport links padcheck lint
