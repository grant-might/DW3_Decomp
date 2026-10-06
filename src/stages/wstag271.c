#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE2
#define STAGE_FILE 0x6F9
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xDA)
#define STAGE_FILE 0x709
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xC000, 0x11D00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 8;
    D_800990B4.music = 0x60200000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
}

extern u16 D_800A4F88[];
extern u16 D_800A4F90[];
extern u16 D_800A4F98[];
extern u16 D_800A4FA0[];
extern u16 D_800A4FA8[];
extern u16 D_800A4FB4[];
extern u16 D_800A4FC0[];
extern u16 D_800A4FCC[];
extern u16 D_800A4FD8[];
extern u16 D_800A4FE0[];
extern u16 D_800A4FEC[];
extern u16 D_800A4FF4[];
extern u16 D_800A5004[];
extern u16 D_800A5018[];
extern u16 D_800A5020[];
extern u16 D_800A5034[];
extern u16 D_800A503C[];
extern u16 D_800A5044[];
extern u16 D_800A504C[];
extern u16 D_800A5054[];
extern u16 D_800A505C[];
extern u16 D_800A5068[];
extern u16 D_800A5074[];
extern u16 D_800A5080[];
extern u16 D_800A508C[];
extern u16 D_800A5094[];
extern u16 D_800A50A0[];
extern u16 D_800A50A8[];
extern u16 D_800A50B8[];
extern u16 D_800A50CC[];
extern u16 D_800A50D4[];
extern u16 D_800A50E8[];
extern u16 D_800A50F0[];
extern u16 D_800A50F8[];
extern u16 D_800A5100[];
extern u16 D_800A5108[];
extern u16 D_800A5110[];
extern u16 D_800A511C[];
extern u16 D_800A5128[];
extern u16 D_800A5134[];
extern u16 D_800A5140[];
extern u16 D_800A5148[];
extern u16 D_800A5154[];
extern u16 D_800A515C[];
extern u16 D_800A516C[];
extern u16 D_800A5180[];
extern u16 D_800A5188[];
extern u16 D_800A519C[];
extern u16 D_800A51A4[];
extern u16 D_800A51AC[];
extern u16 D_800A51B4[];
extern u16 D_800A51BC[];
extern u16 D_800A51C4[];
extern u16 D_800A51D0[];
extern u16 D_800A51DC[];
extern u16 D_800A51E8[];
extern u16 D_800A51F4[];
extern u16 D_800A51FC[];
extern u16 D_800A5208[];
extern u16 D_800A5210[];
extern u16 D_800A5220[];
extern u16 D_800A5234[];
extern u16 D_800A523C[];
extern u16 D_800A5250[];
extern u16 D_800A5258[];
extern u16 D_800A5264[];
extern u16 D_800A5270[];
extern u16 D_800A5674[];
extern FieldTalk D_800A5278[];
extern u16 D_800A567C[];
extern FieldTalk D_800A5290[];
extern u16 D_800A5688[];
extern FieldTalk D_800A52A8[];
extern u16 D_800A5694[];
extern FieldTalk D_800A52D8[];
extern u16 D_800A56A4[];
extern FieldTalk D_800A532C[];
extern u16 D_800A56B4[];
extern FieldTalk D_800A5344[];
extern u16 D_800A56C0[];
extern FieldTalk D_800A5374[];
extern u16 D_800A56D0[];
extern FieldTalk D_800A53C8[];
extern u16 D_800A56E0[];
extern FieldTalk D_800A53E0[];
extern u16 D_800A56EC[];
extern FieldTalk D_800A5410[];
extern u16 D_800A56FC[];
extern FieldTalk D_800A5464[];
extern u16 D_800A570C[];
extern FieldTalk D_800A547C[];
extern u16 D_800A5718[];
extern u16 D_800A5720[];
extern FieldTalk D_800A5494[];
extern u16 D_800A572C[];
extern FieldTalk D_800A54C4[];
extern u16 D_800A573C[];
extern FieldTalk D_800A5518[];
extern u16 D_800A574C[];
extern FieldTalk D_800A5530[];
extern u16 D_800A5758[];
extern FieldTalk D_800A5548[];
extern u16 D_800A5760[];
extern FieldTalk D_800A5560[];
extern u16 D_800A576C[];
extern FieldTalk D_800A5578[];
extern u16 D_800A5774[];
extern FieldTalk D_800A5590[];
extern u16 D_800A5780[];
extern FieldTalk D_800A55A8[];
extern u16 D_800A5788[];
extern FieldTalk D_800A55C0[];
extern u16 D_800A5794[];
extern FieldTalk D_800A55D8[];
extern u16 D_800A579C[];
extern FieldTalk D_800A55F0[];
extern u16 D_800A57A8[];
extern FieldTalk D_800A5608[];
extern u16 D_800A57B0[];
extern FieldTalk D_800A5620[];
extern u16 D_800A57BC[];
extern FieldTalk D_800A5638[];
extern FieldTalk D_800A5650[];
extern u16 D_800A57C4[];
extern u16 D_800A57D0[];
extern u16 D_800A57DC[];
extern FieldActorEntry D_800A57E4;
extern FieldActorEntry D_800A57F8;
extern FieldActorEntry D_800A580C;
extern FieldActorEntry D_800A5820;
extern FieldActorEntry D_800A5834;
extern FieldActorEntry D_800A5848;
extern FieldActorEntry D_800A585C;
extern FieldActorEntry D_800A5870;
extern FieldActorEntry D_800A5884;
extern FieldActorEntry D_800A5898;
extern FieldActorEntry D_800A58AC;
extern FieldActorEntry D_800A58C0;
extern FieldActorEntry D_800A58D4;
extern FieldActorEntry D_800A58E8;
extern FieldActorEntry D_800A58FC;
extern FieldActorEntry D_800A5910;
extern FieldActorEntry D_800A5924;
extern FieldActorEntry D_800A5938;
extern FieldActorEntry D_800A594C;
extern FieldActorEntry D_800A5960;
extern FieldActorEntry D_800A5974;
extern FieldActorEntry D_800A5988;
extern FieldActorEntry D_800A599C;
extern FieldActorEntry D_800A59B0;
extern FieldActorEntry D_800A59C4;
extern FieldActorEntry D_800A59D8;
extern FieldActorEntry D_800A59EC;
extern FieldActorEntry D_800A5A00;
extern FieldActorEntry D_800A5A14;
extern FieldActorEntry D_800A5A28;
extern FieldActorEntry D_800A5A3C;
extern FieldActorEntry D_800A5A50;
extern FieldActorEntry D_800A5A64;

ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x1D8, 0, 0xD8, 0x160, 0x1FB },
    { 0x180, 0x100, 0x1B0, 0x159, 0x1C0, 0x59, 0x170, 0x1FB },
    { 0x180, 0x100, 0x1A0, 0x15D, 0x180, 0x5D, 0x150, 0x1FA },
    { 0x180, 0x100, 0x1A8, 0x15D, 0x1A0, 0x5D, 0x160, 0x1FA },
    { 0x180, 0x100, 0x190, 0x171, 0x140, 0x71, 0x170, 0x1FA },
    { 0x180, 0x100, 0x198, 0x171, 0x160, 0x71, 0x140, 0x1F9 },
    { 0x180, 0x100, 0x180, 0x172, 0x100, 0x72, 0x150, 0x1F9 },
    { 0x180, 0x100, 0x188, 0x172, 0x120, 0x72, 0x160, 0x1F9 },
    { 0x180, 0x100, 0x1B0, 0x181, 0x1C0, 0x81, 0x170, 0x1F9 },
    { 0x180, 0x100, 0x1A0, 0x185, 0x180, 0x85, 0x140, 0x1F8 },
    { 0x180, 0x100, 0x1A8, 0x185, 0x1A0, 0x85, 0x150, 0x1F8 },
    { 0x180, 0x100, 0x180, 0x192, 0x100, 0x92, 0x160, 0x1F8 },
    { 0x180, 0x100, 0x1B4, 0x100, 0x1D0, 0, 0x170, 0x1F8 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};
u16 D_800A4F88[] = { 0x11, 0, 0xFFFF };
u16 D_800A4F90[] = { 0x10, 0, 0xFFFF };
u16 D_800A4F98[] = { 0x11, 0, 0xFFFF };
u16 D_800A4FA0[] = { 0x10, 1, 0xFFFF };
u16 D_800A4FA8[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A4FB4[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A4FC0[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A4FCC[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A4FD8[] = { 0x11, 0, 0xFFFF };
u16 D_800A4FE0[] = { 2, 0, 0x11, 0, 0xFFFF };
u16 D_800A4FEC[] = { 2, 1, 0xFFFF };
u16 D_800A4FF4[] = { 2, 1, 0x720B, 0, 0x11, 0, 0xFFFF };
u16 D_800A5004[] = { 2, 1, 0x720B, 1, 0x720D, 0, 0x11, 0, 0xFFFF };
u16 D_800A5018[] = { 0x7653, 1, 0xFFFF };
u16 D_800A5020[] = { 2, 1, 0x720B, 1, 0x720D, 1, 0x11, 0, 0xFFFF };
u16 D_800A5034[] = { 0x7853, 1, 0xFFFF };
u16 D_800A503C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5044[] = { 0x10, 0, 0xFFFF };
u16 D_800A504C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5054[] = { 0x10, 1, 0xFFFF };
u16 D_800A505C[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5068[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A5074[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5080[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A508C[] = { 0x11, 0, 0xFFFF };
u16 D_800A5094[] = { 3, 0, 0x11, 0, 0xFFFF };
u16 D_800A50A0[] = { 3, 1, 0xFFFF };
u16 D_800A50A8[] = { 3, 1, 0x720B, 0, 0x11, 0, 0xFFFF };
u16 D_800A50B8[] = { 3, 1, 0x720B, 1, 0x720D, 0, 0x11, 0, 0xFFFF };
u16 D_800A50CC[] = { 0x7654, 1, 0xFFFF };
u16 D_800A50D4[] = { 3, 1, 0x720B, 1, 0x720D, 1, 0x11, 0, 0xFFFF };
u16 D_800A50E8[] = { 0x7854, 1, 0xFFFF };
u16 D_800A50F0[] = { 0x11, 0, 0xFFFF };
u16 D_800A50F8[] = { 0x10, 0, 0xFFFF };
u16 D_800A5100[] = { 0x11, 0, 0xFFFF };
u16 D_800A5108[] = { 0x10, 1, 0xFFFF };
u16 D_800A5110[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A511C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A5128[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5134[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A5140[] = { 0x11, 0, 0xFFFF };
u16 D_800A5148[] = { 0, 0, 0x11, 0, 0xFFFF };
u16 D_800A5154[] = { 0, 1, 0xFFFF };
u16 D_800A515C[] = { 0, 1, 0x720B, 0, 0x11, 0, 0xFFFF };
u16 D_800A516C[] = { 0, 1, 0x720B, 1, 0x720D, 0, 0x11, 0, 0xFFFF };
u16 D_800A5180[] = { 0x7651, 1, 0xFFFF };
u16 D_800A5188[] = { 0, 1, 0x720B, 1, 0x720D, 1, 0x11, 0, 0xFFFF };
u16 D_800A519C[] = { 0x7851, 1, 0xFFFF };
u16 D_800A51A4[] = { 0x11, 0, 0xFFFF };
u16 D_800A51AC[] = { 0x10, 0, 0xFFFF };
u16 D_800A51B4[] = { 0x11, 0, 0xFFFF };
u16 D_800A51BC[] = { 0x10, 1, 0xFFFF };
u16 D_800A51C4[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A51D0[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A51DC[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A51E8[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A51F4[] = { 0x11, 0, 0xFFFF };
u16 D_800A51FC[] = { 1, 0, 0x11, 0, 0xFFFF };
u16 D_800A5208[] = { 1, 1, 0xFFFF };
u16 D_800A5210[] = { 1, 1, 0x720B, 0, 0x11, 0, 0xFFFF };
u16 D_800A5220[] = { 1, 1, 0x720B, 1, 0x720D, 0, 0x11, 0, 0xFFFF };
u16 D_800A5234[] = { 0x7652, 1, 0xFFFF };
u16 D_800A523C[] = { 1, 1, 0x720B, 1, 0x720D, 1, 0x11, 0, 0xFFFF };
u16 D_800A5250[] = { 0x7852, 1, 0xFFFF };
u16 D_800A5258[] = { 0x7008, 1, 0x8192, 0, 0xFFFF };
u16 D_800A5264[] = { 0x7008, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5270[] = { 0x7A43, 1, 0xFFFF };
FieldTalk D_800A5278[] = {
    { NULL, NULL, 0x26 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5290[] = {
    { NULL, NULL, 0x25 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52A8[] = {
    { D_800A4F88, NULL, 0x1A0 },
    { D_800A4F90, D_800A4F98, 0x1A },
    { D_800A4FA0, D_800A4FA8, 0x1B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A52D8[] = {
    { D_800A4FB4, D_800A4FC0, 0x1B },
    { D_800A4FCC, D_800A4FD8, 0x1A },
    { D_800A4FE0, D_800A4FEC, 0x15 },
    { D_800A4FF4, NULL, 0x17 },
    { D_800A5004, D_800A5018, 0x18 },
    { D_800A5020, D_800A5034, 0x19 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A532C[] = {
    { NULL, NULL, 0x1A0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5344[] = {
    { D_800A503C, NULL, 0x1A1 },
    { D_800A5044, D_800A504C, 0x21 },
    { D_800A5054, D_800A505C, 0x22 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5374[] = {
    { D_800A5068, D_800A5074, 0x22 },
    { D_800A5080, D_800A508C, 0x21 },
    { D_800A5094, D_800A50A0, 0x1C },
    { D_800A50A8, NULL, 0x1E },
    { D_800A50B8, D_800A50CC, 0x1F },
    { D_800A50D4, D_800A50E8, 0x20 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53C8[] = {
    { NULL, NULL, 0x1A1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A53E0[] = {
    { D_800A50F0, NULL, 0x19E },
    { D_800A50F8, D_800A5100, 0xC },
    { D_800A5108, D_800A5110, 0xD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5410[] = {
    { D_800A511C, D_800A5128, 0xD },
    { D_800A5134, D_800A5140, 0xC },
    { D_800A5148, D_800A5154, 7 },
    { D_800A515C, NULL, 9 },
    { D_800A516C, D_800A5180, 0xA },
    { D_800A5188, D_800A519C, 0xB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5464[] = {
    { NULL, NULL, 0x19E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A547C[] = {
    { NULL, NULL, 0x23 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5494[] = {
    { D_800A51A4, NULL, 0x19F },
    { D_800A51AC, D_800A51B4, 0x13 },
    { D_800A51BC, D_800A51C4, 0x14 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A54C4[] = {
    { D_800A51D0, D_800A51DC, 0x14 },
    { D_800A51E8, D_800A51F4, 0x13 },
    { D_800A51FC, D_800A5208, 0xE },
    { D_800A5210, NULL, 0x10 },
    { D_800A5220, D_800A5234, 0x11 },
    { D_800A523C, D_800A5250, 0x12 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5518[] = {
    { NULL, NULL, 0x19F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5530[] = {
    { NULL, NULL, 0x27 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5548[] = {
    { NULL, NULL, 0x2D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5560[] = {
    { NULL, NULL, 0x29 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5578[] = {
    { NULL, NULL, 0x2F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5590[] = {
    { NULL, NULL, 0x2A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55A8[] = {
    { NULL, NULL, 0x30 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55C0[] = {
    { NULL, NULL, 0x2B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55D8[] = {
    { NULL, NULL, 0x31 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A55F0[] = {
    { NULL, NULL, 0x2C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5608[] = {
    { NULL, NULL, 0x32 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5620[] = {
    { NULL, NULL, 0x28 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5638[] = {
    { NULL, NULL, 0x2E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5650[] = {
    { D_800A5258, NULL, 0x20D },
    { D_800A5264, D_800A5270, 0x1A7 },
    { NULL, NULL, 0 },
};
u16 D_800A5674[] = { 0x602B, 1, 0xFFFF };
u16 D_800A567C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5688[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A5694[] = { 0x6026, 1, 0x1A0A, 1, 0x8192, 1, 0xFFFF };
u16 D_800A56A4[] = { 0x8192, 0, 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A56B4[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A56C0[] = { 0x6026, 1, 0x1A0A, 1, 0x8192, 1, 0xFFFF };
u16 D_800A56D0[] = { 0x8192, 0, 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A56E0[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A56EC[] = { 0x6026, 1, 0x1A0A, 1, 0x8192, 1, 0xFFFF };
u16 D_800A56FC[] = { 0x8192, 0, 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A570C[] = { 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A5718[] = { 0x602B, 1, 0xFFFF };
u16 D_800A5720[] = { 0x602B, 1, 0x8192, 1, 0xFFFF };
u16 D_800A572C[] = { 0x6026, 1, 0x1A0A, 1, 0x8192, 1, 0xFFFF };
u16 D_800A573C[] = { 0x8192, 0, 0x6026, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A574C[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5758[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5760[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A576C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5774[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5780[] = { 0x701A, 1, 0xFFFF };
u16 D_800A5788[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A5794[] = { 0x701A, 1, 0xFFFF };
u16 D_800A579C[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57A8[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57B0[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57BC[] = { 0x701A, 1, 0xFFFF };
u16 D_800A57C4[] = { 0x701C, 1, 0x1A0A, 1, 0xFFFF };
u16 D_800A57D0[] = { 0x701C, 1, 0x1A0A, 0, 0xFFFF };
u16 D_800A57DC[] = { 0x701A, 1, 0xFFFF };
FieldActorEntry D_800A57E4 = { D_800A5674, D_800A5278, 0x2E, 4, 255, 176, 3 };
FieldActorEntry D_800A57F8 = { D_800A567C, D_800A5290, 0x2E, 4, 255, 176, 3 };
FieldActorEntry D_800A580C = { D_800A5688, D_800A52A8, 0x30, 5, 198, 219, 7 };
FieldActorEntry D_800A5820 = { D_800A5694, D_800A52D8, 0x30, 5, 198, 219, 7 };
FieldActorEntry D_800A5834 = { D_800A56A4, D_800A532C, 0x30, 5, 198, 219, 7 };
FieldActorEntry D_800A5848 = { D_800A56B4, D_800A5344, 0x31, 6, 173, 231, 7 };
FieldActorEntry D_800A585C = { D_800A56C0, D_800A5374, 0x31, 6, 173, 231, 7 };
FieldActorEntry D_800A5870 = { D_800A56D0, D_800A53C8, 0x31, 6, 173, 231, 7 };
FieldActorEntry D_800A5884 = { D_800A56E0, D_800A53E0, 0x33, 7, 250, 244, 3 };
FieldActorEntry D_800A5898 = { D_800A56EC, D_800A5410, 0x33, 7, 250, 244, 3 };
FieldActorEntry D_800A58AC = { D_800A56FC, D_800A5464, 0x33, 7, 250, 244, 3 };
FieldActorEntry D_800A58C0 = { D_800A570C, D_800A547C, 0x34, 8, 348, 147, 1 };
FieldActorEntry D_800A58D4 = { D_800A5718, NULL, 0x34, 8, 348, 147, 1 };
FieldActorEntry D_800A58E8 = { D_800A5720, D_800A5494, 0x36, 9, 224, 257, 3 };
FieldActorEntry D_800A58FC = { D_800A572C, D_800A54C4, 0x36, 9, 224, 257, 3 };
FieldActorEntry D_800A5910 = { D_800A573C, D_800A5518, 0x36, 9, 224, 257, 3 };
FieldActorEntry D_800A5924 = { D_800A574C, D_800A5530, 0x9D, 0xA, 348, 147, 1 };
FieldActorEntry D_800A5938 = { D_800A5758, D_800A5548, 0x9D, 0xA, 348, 147, 1 };
FieldActorEntry D_800A594C = { D_800A5760, D_800A5560, 0x9E, 0xB, 250, 244, 3 };
FieldActorEntry D_800A5960 = { D_800A576C, D_800A5578, 0x9E, 0xB, 250, 244, 3 };
FieldActorEntry D_800A5974 = { D_800A5774, D_800A5590, 0x9F, 0xC, 224, 257, 3 };
FieldActorEntry D_800A5988 = { D_800A5780, D_800A55A8, 0x9F, 0xC, 224, 257, 3 };
FieldActorEntry D_800A599C = { D_800A5788, D_800A55C0, 0xA0, 0xD, 198, 219, 7 };
FieldActorEntry D_800A59B0 = { D_800A5794, D_800A55D8, 0xA0, 0xD, 198, 219, 7 };
FieldActorEntry D_800A59C4 = { D_800A579C, D_800A55F0, 0xA1, 0xE, 173, 231, 7 };
FieldActorEntry D_800A59D8 = { D_800A57A8, D_800A5608, 0xA1, 0xE, 173, 231, 7 };
FieldActorEntry D_800A59EC = { D_800A57B0, D_800A5620, 0xA2, 0xF, 255, 176, 3 };
FieldActorEntry D_800A5A00 = { D_800A57BC, D_800A5638, 0xA2, 0xF, 255, 176, 3 };
FieldActorEntry D_800A5A14 = { NULL, D_800A5650, 0xCE, 0x10, 379, 147, 7 };
FieldActorEntry D_800A5A28 = { NULL, NULL, 0xDC, 0x11, 379, 163, 7 };
FieldActorEntry D_800A5A3C = { D_800A57C4, NULL, 0x100, 0x12, 347, 158, 1 };
FieldActorEntry D_800A5A50 = { D_800A57D0, NULL, 0x10E, 0x13, 347, 158, 1 };
FieldActorEntry D_800A5A64 = { D_800A57DC, NULL, 0x10E, 0x13, 347, 158, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A57E4,
    &D_800A57F8,
    &D_800A580C,
    &D_800A5820,
    &D_800A5834,
    &D_800A5848,
    &D_800A585C,
    &D_800A5870,
    &D_800A5884,
    &D_800A5898,
    &D_800A58AC,
    &D_800A58C0,
    &D_800A58D4,
    &D_800A58E8,
    &D_800A58FC,
    &D_800A5910,
    &D_800A5924,
    &D_800A5938,
    &D_800A594C,
    &D_800A5960,
    &D_800A5974,
    &D_800A5988,
    &D_800A599C,
    &D_800A59B0,
    &D_800A59C4,
    &D_800A59D8,
    &D_800A59EC,
    &D_800A5A00,
    &D_800A5A14,
    &D_800A5A28,
    &D_800A5A3C,
    &D_800A5A50,
    &D_800A5A64,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 6, 0x3B, 2, 0, 5, 8, 0, 428, 75, 0, 0 },
    { 1, 0, 0x40, 6, 0x3D, 2, 0, 3, 8, 0, 65, 176, 0, 0 },
    { 1, 0, 0x40, 6, 0x3A, 2, 0, 3, 8, 0, 425, 67, 0, 0 },
    { 1, 0, 0x40, 6, 0x32, 1, 0x32, 0x39, 8, 0, 428, 75, 0, 0 },
    { 1, 0, 0x40, 4, 0x3C, 2, 0, 3, 8, 0, 470, 149, 176, 0 },
    { 1, 0, 0x40, 4, 0, 0, 0, 0, 0, 0, 86, 239, 258, 0 },
    { 1, 0, 0x40, 4, 1, 0, 0, 0, 0, 0, 160, 220, 248, 0 },
    { 1, 0, 0x40, 4, 2, 0, 0, 0, 0, 0, 192, 204, 232, 0 },
    { 1, 0, 0x40, 4, 3, 0, 0, 0, 0, 0, 320, 201, 231, 0 },
    { 1, 0, 0x40, 4, 4, 0, 0, 0, 0, 0, 291, 185, 209, 0 },
    { 1, 0, 0x40, 4, 5, 0, 0, 0, 0, 0, 352, 147, 168, 0 },
    { 1, 0, 0x40, 4, 6, 0, 0, 0, 0, 0, 371, 140, 160, 0 },
    { 1, 0, 0x40, 4, 7, 0, 0, 0, 0, 0, 336, 139, 160, 0 },
    { 1, 0, 0x40, 4, 8, 0, 0, 0, 0, 0, 385, 131, 153, 0 },
    { 1, 0, 0x40, 4, 9, 0, 0, 0, 0, 0, 320, 131, 153, 0 },
    { 1, 0, 0x40, 4, 0xA, 0, 0, 0, 0, 0, 401, 123, 144, 0 },
    { 1, 0, 0x40, 4, 0xB, 0, 0, 0, 0, 0, 304, 117, 144, 0 },
    { 1, 0, 0x40, 4, 0xC, 0, 0, 0, 0, 0, 464, 149, 176, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x271, 0x1F0, 0xA0, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
