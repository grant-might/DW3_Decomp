# Digimon World 2003, Europe (SLES-03936)
#
# Plain values: tools/version.py reads EXE_NAME and DISK_DIR from here too.

# the release, as the configs' headers name it
VERSION_NAME := Digimon World 2003, Europe (SLES-03936)

# the executable, as it is on the disc
EXE_NAME := SLES_039.36

# where the extracted disc is (tools/extract_disc.py): the executable and
# AAA/, whose PRO/ directory holds the overlays
DISK_DIR := disks/eu

# The overlays the build links and checks, AAA/PRO/<FILE>.PRO: each one has
# its splat config, config/<version>/<name>.yaml. The stage overlays are
# added from config/<version>/stages.txt: the USA version's and 55 more.
OVERLAYS := cardgame cnty_sel fieldstg fightstg shocktst soundtst stagslct \
	stcrdabm stcrddek stcrdshp stdgname stdwtitl stfgtrep stgdglab \
	stgmcard stgtrain stitshop stplnmet ststatus wfightmn wfightts

# where the executable loads (main.yaml)
EXE_VRAM := 0x80010000

# where the overlays load, after the executable's .bss, and where the stage
# overlays and WFIGHTMN/WFIGHTTS load, after CARDGAME, the largest
OVERLAY_VRAM := 0x80082CB0
STAGE_VRAM := 0x800A5DE0

# $gp, as crt0 sets it: main.yaml's gp_value, which tools/match_versions.py
# reads too (the overlays don't use $gp)
GP_VALUE := 0x8005CB50

# The C files this version builds: every module of the USA version, from the
# same C at this version's addresses (tools/version_symbols.py names what they
# use), and the stages only this version has. The executable and the overlays
# are split into the USA version's modules (tools/split_version.py), so that
# their asm lands at the same paths under asm/eu/ as under asm/us/; only the
# PsyQ libraries and the functions behind INCLUDE_ASM stay asm.
C_SRC := src/main/game3_2.c src/soundtst/soundtst.c

# game
C_SRC += src/main/inn.c src/main/system.c src/main/memcard.c src/main/game3.c src/main/text_window.c src/main/pad.c src/main/graphics.c src/main/sound.c src/main/overlay.c
C_SRC += src/main/data/matrices.c src/main/data/game_3.c src/main/data/game_bss.c

# menus
C_SRC += src/stitshop/stitshop.c src/stgdglab/stgdglab.c src/ststatus/ststatus.c
# stgdglab's other objects
C_SRC += $(addprefix src/stgdglab/, stgdglab_2.c stgdglab_3.c stgdglab_4.c stgdglab_5.c)
# ststatus's other objects
C_SRC += $(addprefix src/ststatus/, ststatus_2.c ststatus_3.c ststatus_4.c ststatus_5.c ststatus_6.c ststatus_7.c ststatus_8.c ststatus_9.c ststatus_10.c)

# cardgame
C_SRC += src/cardgame/cardgame.c
C_SRC += src/cardgame/cardgame_2.c
C_SRC += src/cardgame/cardgame_3.c
C_SRC += src/cardgame/cardgame_4.c

# fightstg's other objects (fightstg.c is with the overlays)
C_SRC += $(addprefix src/fightstg/, fightstg_2.c fightstg_3.c fightstg_4.c fightstg_5.c fightstg_6.c fightstg_7.c)

# small overlays
C_SRC += src/stgmcard/stgmcard.c src/stfgtrep/stfgtrep.c src/wfightmn/wfightmn.c src/wfightmn/wfightmn_2.c src/stcrdshp/stcrdshp.c src/stplnmet/stplnmet.c src/wfightts/wfightts.c
# stcrdshp's other objects
C_SRC += src/stcrdshp/stcrdshp_2.c src/stcrdshp/stcrdshp_3.c

# overlays
C_SRC += src/shocktst/shocktst.c src/cnty_sel/cnty_sel.c src/stcrdabm/stcrdabm.c
C_SRC += src/stagslct/stagslct.c src/stdgname/stdgname.c src/stdgname/stdgname_2.c
C_SRC += src/stdwtitl/stdwtitl.c src/stdwtitl/stdwtitl_2.c src/stdwtitl/data/movie.c
C_SRC += src/fieldstg/fieldstg.c
C_SRC += src/stcrddek/stcrddek.c src/stgtrain/stgtrain.c src/fightstg/fightstg.c
# fieldstg's other objects
C_SRC += $(addprefix src/fieldstg/, fieldstg_2.c fieldstg_3.c fieldstg_4.c fieldstg_5.c)
# stgtrain's other objects
C_SRC += src/stgtrain/stgtrain_2.c src/stgtrain/stgtrain_3.c

# The stages the USA version has, built from its C
C_SRC += $(addprefix src/stages/, \
	wstag200.c wstag201.c wstag202.c wstag203.c wstag205.c wstag206.c \
	wstag210.c wstag211.c wstag212.c wstag218.c wstag219.c wstag220.c \
	wstag221.c wstag225.c wstag226.c wstag230.c wstag231.c wstag232.c \
	wstag233.c wstag235.c wstag236.c wstag237.c wstag238.c wstag240.c \
	wstag241.c wstag245.c wstag246.c wstag250.c wstag251.c wstag255.c \
	wstag256.c wstag260.c wstag261.c wstag270.c wstag271.c wstag275.c wstag276.c \
	wstag280.c wstag281.c wstag285.c wstag286.c wstag290.c wstag291.c \
	wstag295.c wstag296.c wstag300.c wstag301.c wstag305.c wstag306.c \
	wstag310.c wstag311.c wstag315.c wstag316.c wstag320.c wstag321.c \
	wstag325.c wstag326.c wstag330.c wstag331.c wstag335.c wstag336.c \
	wstag340.c wstag341.c wstag345.c wstag346.c wstag350.c wstag351.c \
	wstag355.c wstag356.c wstag360.c wstag361.c wstag365.c wstag366.c \
	wstag370.c wstag371.c wstag375.c wstag376.c wstag380.c wstag381.c \
	wstag385.c wstag386.c wstag395.c wstag396.c wstag400.c wstag401.c \
	wstag405.c wstag406.c wstag410.c wstag411.c wstag415.c wstag420.c \
	wstag421.c wstag425.c wstag426.c wstag430.c wstag431.c wstag435.c \
	wstag436.c wstag440.c wstag441.c wstag445.c wstag446.c wstag450.c \
	wstag451.c wstag455.c wstag456.c wstag460.c wstag465.c wstag466.c \
	wstag470.c wstag471.c wstag475.c wstag476.c wstag480.c wstag481.c \
	wstag485.c wstag486.c wstag490.c wstag491.c wstag495.c wstag496.c \
	wstag500.c wstag501.c wstag505.c wstag506.c wstag520.c wstag521.c \
	wstag525.c wstag526.c wstag530.c wstag531.c wstag535.c wstag537.c \
	wstag538.c wstag540.c wstag545.c wstag550.c wstag551.c wstag555.c \
	wstag556.c wstag560.c wstag561.c wstag565.c wstag566.c wstag570.c \
	wstag571.c wstag575.c wstag576.c wstag580.c wstag581.c wstag585.c \
	wstag586.c wstag590.c wstag591.c wstag595.c wstag596.c wstag600.c \
	wstag601.c wstag605.c wstag606.c wstag610.c wstag611.c wstag615.c \
	wstag616.c wstag620.c wstag621.c wstag625.c wstag630.c wstag631.c \
	wstag635.c wstag636.c wstag640.c wstag641.c wstag645.c wstag646.c \
	wstag650.c wstag651.c wstag655.c wstag656.c wstag660.c wstag661.c \
	wstag675.c wstag676.c wstag680.c wstag685.c wstag686.c wstag690.c \
	wstag691.c wstag695.c wstag696.c wstag700.c wstag701.c wstag705.c \
	wstag706.c wstag710.c wstag711.c wstag715.c wstag716.c wstag720.c \
	wstag721.c wstag725.c wstag726.c wstag730.c wstag731.c wstag735.c \
	wstag736.c wstag740.c wstag741.c wstag745.c wstag746.c wstag750.c \
	wstag755.c wstag756.c wstag760.c wstag761.c wstag780.c wstag785.c \
	wstag790.c wstag795.c wstag800.c wstag805.c wstag810.c wstag815.c \
	wstag820.c wstag825.c wstag830.c wstag835.c wstag840.c wstag845.c \
	wstag850.c wstag855.c wstag860.c wstag865.c wstag870.c wstag875.c \
	wstag880.c wstag885.c wstag890.c wstag895.c)

# The stages the USA version doesn't have
C_SRC += $(addprefix src/stages/, \
	wstag920.c wstag921.c wstag922.c wstag923.c wstag924.c wstag925.c \
	wstag926.c wstag927.c wstag928.c wstag929.c wstag930.c wstag931.c \
	wstag932.c wstag933.c wstag934.c wstag935.c wstag936.c wstag937.c \
	wstag938.c wstag939.c wstag940.c wstag941.c wstag942.c wstag943.c \
	wstag944.c wstag945.c wstag946.c wstag947.c wstag948.c wstag949.c \
	wstag950.c wstag951.c wstag952.c wstag953.c wstag954.c wstag955.c \
	wstag956.c wstag957.c wstag958.c wstag959.c wstag960.c wstag961.c \
	wstag962.c wstag963.c wstag964.c wstag965.c wstag966.c wstag967.c \
	wstag968.c wstag969.c wstag970.c wstag971.c wstag972.c wstag973.c \
	wstag974.c)
# WSTAG924's color, in a file of its own before the stage's jump tables
# (tools/stage_yaml.py)
C_SRC += src/stages/wstag924_head.c
