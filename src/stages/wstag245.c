#include "common.h"
#include "stage.h"

#include "common/update_stage.inc.c"
#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xF0
#define EVENT_TEXT_FILE 0x10B
#define STAGE_FILE 0x199
#define STAGE_ARCHIVE 0x314
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE8)
#define EVENT_TEXT_FILE 0x112
#define STAGE_FILE 0x1A7
#define STAGE_ARCHIVE 0x323
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_ARCHIVE;
    D_800990B4.start = (Vec2){0x15A00, 0x18E00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 7;
    D_800990B4.music = 0x601C0000;
    D_800990B4.actors = stageActors;
    D_800990B4.startDir = 0;
    D_800990B4.events = stageEvents;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 1);
    D_8009A70C.unk50(0);
}

extern u16 D_800A5060[];
extern u16 D_800A5068[];
extern u16 D_800A5070[];
extern u16 D_800A5078[];
extern u16 D_800A5080[];
extern u16 D_800A5088[];
extern u16 D_800A5090[];
extern u16 D_800A5098[];
extern u16 D_800A50A0[];
extern u16 D_800A50A8[];
extern u16 D_800A50B0[];
extern u16 D_800A50BC[];
extern u16 D_800A50CC[];
extern u16 D_800A50D8[];
extern u16 D_800A50E8[];
extern u16 D_800A50F0[];
extern u16 D_800A50FC[];
extern u16 D_800A5108[];
extern u16 D_800A5114[];
extern u16 D_800A511C[];
extern u16 D_800A5124[];
extern u16 D_800A5130[];
extern u16 D_800A5140[];
extern u16 D_800A514C[];
extern u16 D_800A515C[];
extern u16 D_800A5164[];
extern u16 D_800A5170[];
extern u16 D_800A517C[];
extern u16 D_800A5188[];
extern u16 D_800A5190[];
extern u16 D_800A519C[];
extern u16 D_800A51A8[];
extern u16 D_800A51B4[];
extern u16 D_800A51BC[];
extern u16 D_800A51C8[];
extern u16 D_800A51D4[];
extern u16 D_800A51E0[];
extern u16 D_800A51E8[];
extern u16 D_800A51F4[];
extern u16 D_800A5200[];
extern u16 D_800A520C[];
extern u16 D_800A5214[];
extern u16 D_800A5220[];
extern u16 D_800A522C[];
extern u16 D_800A5238[];
extern u16 D_800A5240[];
extern u16 D_800A524C[];
extern u16 D_800A5258[];
extern u16 D_800A5264[];
extern u16 D_800A526C[];
extern u16 D_800A5278[];
extern u16 D_800A5284[];
extern u16 D_800A5290[];
extern u16 D_800A5298[];
extern u16 D_800A52A4[];
extern u16 D_800A52B0[];
extern u16 D_800A52BC[];
extern u16 D_800A52C4[];
extern u16 D_800A52D0[];
extern u16 D_800A52DC[];
extern u16 D_800A52E8[];
extern u16 D_800A52F0[];
extern u16 D_800A52FC[];
extern u16 D_800A5308[];
extern u16 D_800A5314[];
extern u16 D_800A531C[];
extern u16 D_800A5328[];
extern u16 D_800A5334[];
extern u16 D_800A5340[];
extern u16 D_800A5348[];
extern u16 D_800A5354[];
extern u16 D_800A5360[];
extern u16 D_800A536C[];
extern u16 D_800A5374[];
extern u16 D_800A5380[];
extern u16 D_800A538C[];
extern u16 D_800A5398[];
extern u16 D_800A53A0[];
extern u16 D_800A53A8[];
extern u16 D_800A53B0[];
extern u16 D_800A53B8[];
extern u16 D_800A53C0[];
extern u16 D_800A53CC[];
extern u16 D_800A53D8[];
extern u16 D_800A53E4[];
extern u16 D_800A53EC[];
extern u16 D_800A53F8[];
extern u16 D_800A5404[];
extern u16 D_800A5410[];
extern u16 D_800A5418[];
extern u16 D_800A5424[];
extern u16 D_800A5430[];
extern u16 D_800A543C[];
extern u16 D_800A5444[];
extern u16 D_800A5450[];
extern u16 D_800A545C[];
extern u16 D_800A5464[];
extern u16 D_800A546C[];
extern u16 D_800A5478[];
extern u16 D_800A5484[];
extern u16 D_800A5490[];
extern u16 D_800A5498[];
extern u16 D_800A54A4[];
extern u16 D_800A54B0[];
extern u16 D_800A54BC[];
extern u16 D_800A54C4[];
extern u16 D_800A54D0[];
extern u16 D_800A54DC[];
extern u16 D_800A54E8[];
extern u16 D_800A54F0[];
extern u16 D_800A54FC[];
extern u16 D_800A5508[];
extern u16 D_800A5514[];
extern u16 D_800A551C[];
extern u16 D_800A5528[];
extern u16 D_800A5534[];
extern u16 D_800A5540[];
extern u16 D_800A5548[];
extern u16 D_800A5554[];
extern u16 D_800A5560[];
extern u16 D_800A556C[];
extern u16 D_800A5574[];
extern u16 D_800A5580[];
extern u16 D_800A558C[];
extern u16 D_800A5598[];
extern u16 D_800A55A0[];
extern u16 D_800A55AC[];
extern u16 D_800A55B8[];
extern u16 D_800A55C4[];
extern u16 D_800A55CC[];
extern u16 D_800A55D8[];
extern u16 D_800A55E4[];
extern u16 D_800A55F0[];
extern u16 D_800A55F8[];
extern u16 D_800A5604[];
extern u16 D_800A5610[];
extern u16 D_800A561C[];
extern u16 D_800A5624[];
extern u16 D_800A5630[];
extern u16 D_800A563C[];
extern FieldTalk D_800A5648[];
extern FieldTalk D_800A566C[];
extern u16 D_800A6224[];
extern FieldTalk D_800A5690[];
extern u16 D_800A6230[];
extern FieldTalk D_800A56CC[];
extern u16 D_800A623C[];
extern FieldTalk D_800A56FC[];
extern u16 D_800A6248[];
extern FieldTalk D_800A5738[];
extern u16 D_800A6254[];
extern FieldTalk D_800A5768[];
extern u16 D_800A6260[];
extern FieldTalk D_800A5798[];
extern u16 D_800A626C[];
extern FieldTalk D_800A57C8[];
extern u16 D_800A6278[];
extern FieldTalk D_800A57F8[];
extern u16 D_800A6284[];
extern FieldTalk D_800A5828[];
extern u16 D_800A6290[];
extern FieldTalk D_800A5858[];
extern u16 D_800A629C[];
extern FieldTalk D_800A5888[];
extern u16 D_800A62A8[];
extern FieldTalk D_800A58B8[];
extern u16 D_800A62B4[];
extern FieldTalk D_800A58E8[];
extern u16 D_800A62C0[];
extern FieldTalk D_800A5918[];
extern u16 D_800A62CC[];
extern FieldTalk D_800A5948[];
extern u16 D_800A62D8[];
extern FieldTalk D_800A5978[];
extern u16 D_800A62E4[];
extern FieldTalk D_800A5990[];
extern u16 D_800A62F0[];
extern FieldTalk D_800A59A8[];
extern u16 D_800A62FC[];
extern FieldTalk D_800A59C0[];
extern u16 D_800A6308[];
extern FieldTalk D_800A59D8[];
extern u16 D_800A6314[];
extern FieldTalk D_800A59F0[];
extern u16 D_800A6320[];
extern FieldTalk D_800A5A08[];
extern u16 D_800A632C[];
extern FieldTalk D_800A5A20[];
extern u16 D_800A6338[];
extern FieldTalk D_800A5A38[];
extern u16 D_800A6344[];
extern FieldTalk D_800A5A50[];
extern u16 D_800A6350[];
extern FieldTalk D_800A5A68[];
extern u16 D_800A635C[];
extern FieldTalk D_800A5A80[];
extern u16 D_800A6368[];
extern FieldTalk D_800A5A98[];
extern u16 D_800A6374[];
extern FieldTalk D_800A5AB0[];
extern u16 D_800A6380[];
extern FieldTalk D_800A5AC8[];
extern u16 D_800A638C[];
extern FieldTalk D_800A5AE0[];
extern u16 D_800A6398[];
extern FieldTalk D_800A5B10[];
extern u16 D_800A63A4[];
extern FieldTalk D_800A5B28[];
extern u16 D_800A63AC[];
extern u16 D_800A63B4[];
extern FieldTalk D_800A5B40[];
extern u16 D_800A63BC[];
extern FieldTalk D_800A5B58[];
extern u16 D_800A63C4[];
extern FieldTalk D_800A5B70[];
extern u16 D_800A63CC[];
extern FieldTalk D_800A5B88[];
extern u16 D_800A63D4[];
extern FieldTalk D_800A5BA0[];
extern u16 D_800A63DC[];
extern FieldTalk D_800A5BB8[];
extern u16 D_800A63E4[];
extern FieldTalk D_800A5BD0[];
extern u16 D_800A63EC[];
extern FieldTalk D_800A5BE8[];
extern u16 D_800A63F4[];
extern FieldTalk D_800A5C00[];
extern u16 D_800A63FC[];
extern FieldTalk D_800A5C18[];
extern u16 D_800A6404[];
extern FieldTalk D_800A5C30[];
extern u16 D_800A640C[];
extern FieldTalk D_800A5C48[];
extern u16 D_800A6414[];
extern FieldTalk D_800A5C60[];
extern u16 D_800A641C[];
extern FieldTalk D_800A5C78[];
extern u16 D_800A6428[];
extern FieldTalk D_800A5C90[];
extern u16 D_800A6434[];
extern FieldTalk D_800A5CA8[];
extern u16 D_800A6440[];
extern FieldTalk D_800A5CC0[];
extern u16 D_800A644C[];
extern FieldTalk D_800A5CD8[];
extern u16 D_800A6458[];
extern FieldTalk D_800A5CF0[];
extern u16 D_800A6464[];
extern FieldTalk D_800A5D08[];
extern u16 D_800A6470[];
extern FieldTalk D_800A5D20[];
extern u16 D_800A647C[];
extern FieldTalk D_800A5D38[];
extern u16 D_800A6488[];
extern FieldTalk D_800A5D50[];
extern u16 D_800A6494[];
extern FieldTalk D_800A5D68[];
extern u16 D_800A64A0[];
extern FieldTalk D_800A5D80[];
extern u16 D_800A64AC[];
extern FieldTalk D_800A5D98[];
extern u16 D_800A64B8[];
extern FieldTalk D_800A5DB0[];
extern u16 D_800A64C4[];
extern FieldTalk D_800A5DC8[];
extern u16 D_800A64D0[];
extern FieldTalk D_800A5DE0[];
extern u16 D_800A64D8[];
extern FieldTalk D_800A5DF8[];
extern u16 D_800A64E0[];
extern FieldTalk D_800A5E10[];
extern u16 D_800A64E8[];
extern FieldTalk D_800A5E28[];
extern u16 D_800A64F0[];
extern FieldTalk D_800A5E40[];
extern u16 D_800A64F8[];
extern FieldTalk D_800A5E58[];
extern u16 D_800A6500[];
extern FieldTalk D_800A5E70[];
extern u16 D_800A6508[];
extern FieldTalk D_800A5E88[];
extern u16 D_800A6510[];
extern FieldTalk D_800A5EA0[];
extern u16 D_800A6518[];
extern FieldTalk D_800A5EB8[];
extern u16 D_800A6520[];
extern FieldTalk D_800A5ED0[];
extern u16 D_800A652C[];
extern FieldTalk D_800A5EE8[];
extern FieldTalk D_800A5F00[];
extern u16 D_800A6534[];
extern FieldTalk D_800A5F24[];
extern u16 D_800A6540[];
extern FieldTalk D_800A5F3C[];
extern u16 D_800A654C[];
extern FieldTalk D_800A5F6C[];
extern u16 D_800A6558[];
extern FieldTalk D_800A5F9C[];
extern u16 D_800A6564[];
extern FieldTalk D_800A5FCC[];
extern u16 D_800A6570[];
extern FieldTalk D_800A5FFC[];
extern u16 D_800A657C[];
extern FieldTalk D_800A602C[];
extern u16 D_800A6588[];
extern FieldTalk D_800A605C[];
extern u16 D_800A6594[];
extern FieldTalk D_800A608C[];
extern u16 D_800A65A0[];
extern FieldTalk D_800A60BC[];
extern u16 D_800A65AC[];
extern FieldTalk D_800A60EC[];
extern u16 D_800A65B8[];
extern FieldTalk D_800A611C[];
extern u16 D_800A65C4[];
extern FieldTalk D_800A614C[];
extern u16 D_800A65D0[];
extern FieldTalk D_800A617C[];
extern u16 D_800A65DC[];
extern FieldTalk D_800A61AC[];
extern u16 D_800A65E8[];
extern FieldTalk D_800A61DC[];
extern u16 D_800A65F4[];
extern FieldTalk D_800A620C[];
extern FieldActorEntry D_800A65FC;
extern FieldActorEntry D_800A6610;
extern FieldActorEntry D_800A6624;
extern FieldActorEntry D_800A6638;
extern FieldActorEntry D_800A664C;
extern FieldActorEntry D_800A6660;
extern FieldActorEntry D_800A6674;
extern FieldActorEntry D_800A6688;
extern FieldActorEntry D_800A669C;
extern FieldActorEntry D_800A66B0;
extern FieldActorEntry D_800A66C4;
extern FieldActorEntry D_800A66D8;
extern FieldActorEntry D_800A66EC;
extern FieldActorEntry D_800A6700;
extern FieldActorEntry D_800A6714;
extern FieldActorEntry D_800A6728;
extern FieldActorEntry D_800A673C;
extern FieldActorEntry D_800A6750;
extern FieldActorEntry D_800A6764;
extern FieldActorEntry D_800A6778;
extern FieldActorEntry D_800A678C;
extern FieldActorEntry D_800A67A0;
extern FieldActorEntry D_800A67B4;
extern FieldActorEntry D_800A67C8;
extern FieldActorEntry D_800A67DC;
extern FieldActorEntry D_800A67F0;
extern FieldActorEntry D_800A6804;
extern FieldActorEntry D_800A6818;
extern FieldActorEntry D_800A682C;
extern FieldActorEntry D_800A6840;
extern FieldActorEntry D_800A6854;
extern FieldActorEntry D_800A6868;
extern FieldActorEntry D_800A687C;
extern FieldActorEntry D_800A6890;
extern FieldActorEntry D_800A68A4;
extern FieldActorEntry D_800A68B8;
extern FieldActorEntry D_800A68CC;
extern FieldActorEntry D_800A68E0;
extern FieldActorEntry D_800A68F4;
extern FieldActorEntry D_800A6908;
extern FieldActorEntry D_800A691C;
extern FieldActorEntry D_800A6930;
extern FieldActorEntry D_800A6944;
extern FieldActorEntry D_800A6958;
extern FieldActorEntry D_800A696C;
extern FieldActorEntry D_800A6980;
extern FieldActorEntry D_800A6994;
extern FieldActorEntry D_800A69A8;
extern FieldActorEntry D_800A69BC;
extern FieldActorEntry D_800A69D0;
extern FieldActorEntry D_800A69E4;
extern FieldActorEntry D_800A69F8;
extern FieldActorEntry D_800A6A0C;
extern FieldActorEntry D_800A6A20;
extern FieldActorEntry D_800A6A34;
extern FieldActorEntry D_800A6A48;
extern FieldActorEntry D_800A6A5C;
extern FieldActorEntry D_800A6A70;
extern FieldActorEntry D_800A6A84;
extern FieldActorEntry D_800A6A98;
extern FieldActorEntry D_800A6AAC;
extern FieldActorEntry D_800A6AC0;
extern FieldActorEntry D_800A6AD4;
extern FieldActorEntry D_800A6AE8;
extern FieldActorEntry D_800A6AFC;
extern FieldActorEntry D_800A6B10;
extern FieldActorEntry D_800A6B24;
extern FieldActorEntry D_800A6B38;
extern FieldActorEntry D_800A6B4C;
extern FieldActorEntry D_800A6B60;
extern FieldActorEntry D_800A6B74;
extern FieldActorEntry D_800A6B88;
extern FieldActorEntry D_800A6B9C;
extern FieldActorEntry D_800A6BB0;
extern FieldActorEntry D_800A6BC4;
extern FieldActorEntry D_800A6BD8;
extern FieldActorEntry D_800A6BEC;
extern FieldActorEntry D_800A6C00;
extern FieldActorEntry D_800A6C14;
extern FieldActorEntry D_800A6C28;
extern FieldActorEntry D_800A6C3C;
extern FieldActorEntry D_800A6C50;
extern FieldActorEntry D_800A6C64;
extern FieldActorEntry D_800A6C78;
extern FieldActorEntry D_800A6C8C;
extern FieldActorEntry D_800A6CA0;
extern FieldActorEntry D_800A6CB4;
extern FieldActorEntry D_800A6CC8;
extern FieldActorEntry D_800A6CDC;
extern FieldActorEntry D_800A6CF0;
extern FieldActorEntry D_800A6D04;
extern FieldActorEntry D_800A6D18;
extern FieldActorEntry D_800A6D2C;
extern FieldActorEntry D_800A6D40;
extern s16 D_800A4E38[];
extern s16 D_800A4EC4[];

s16 D_800A4E38[] = {
    0x600, 1, 2,
    0x102, 2, 0xB0, 0x198, 3,
    0x100, 0x1E, 0x98, 0x18D,
    0x101, 0x1E, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0x1E,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x1E,
    0x300, 0x1E,
    0x200, 0, 1, 0x1E, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0x1E, 0x68, 0x174, 3,
    0x302, 0x1E,
    0x102, 0x1E, 0x90, 0x160, 5,
    0x302, 0x1E,
    0x101, 0x1E, 1, 1,
    0x300, 0x1E,
    0,
};
s16 D_800A4EC4[] = {
    0x600, 1, 2,
    0x102, 2, 0xB0, 0x198, 3,
    0x100, 0x126, 0x98, 0x18D,
    0x101, 0x126, 1, 7,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 3,
    0x300, 0x1E,
    0x101, 0x323, 0x325, 0x126,
    0x300, 0x3C,
    0x101, 0x323, 0x326, 0x126,
    0x300, 0x1E,
    0x200, 0, 1, 0x126, 2,
    0x301,
    0x300, 0x1E,
    0x102, 0x126, 0x68, 0x174, 3,
    0x302, 0x126,
    0x102, 0x126, 0x90, 0x160, 5,
    0x302, 0x126,
    0x101, 0x126, 1, 1,
    0x300, 0x1E,
    0,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x1C0, 0x100, 0x1F4, 0x140, 0x2D0, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x162, 0x1DC, 0x88, 0xDC, 0x160, 0x1FF },
    { 0x1C0, 0x100, 0x1CE, 0x1A4, 0x238, 0xA4, 0x170, 0x1FF },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x150, 0x1FE },
    { 0x1C0, 0x100, 0x1D6, 0x1A9, 0x258, 0xA9, 0x160, 0x1FE },
    { 0x140, 0x100, 0x174, 0x1DC, 0xD0, 0xDC, 0x170, 0x1FE },
    { 0x1C0, 0x100, 0x1C0, 0x1AE, 0x200, 0xAE, 0x140, 0x1FD },
    { 0x1C0, 0x100, 0x1E6, 0x1AF, 0x298, 0xAF, 0x150, 0x1FD },
    { 0x1C0, 0x100, 0x1EE, 0x1AF, 0x2B8, 0xAF, 0x160, 0x1FD },
    { 0x140, 0x100, 0x178, 0x120, 0xE0, 0x20, 0x170, 0x1FD },
    { 0x1C0, 0x100, 0x1DE, 0x1A9, 0x278, 0xA9, 0x140, 0x1FC },
};
u16 D_800A5060[] = { 0x1A0F, 0, 0xFFFF };
u16 D_800A5068[] = { 0x1A0F, 1, 0xFFFF };
u16 D_800A5070[] = { 0x1A0F, 1, 0xFFFF };
u16 D_800A5078[] = { 0x7A02, 1, 0xFFFF };
u16 D_800A5080[] = { 0x1A0E, 0, 0xFFFF };
u16 D_800A5088[] = { 0x1A0E, 1, 0xFFFF };
u16 D_800A5090[] = { 0x1A0E, 1, 0xFFFF };
u16 D_800A5098[] = { 0x7A00, 1, 0xFFFF };
u16 D_800A50A0[] = { 0x1A11, 0, 0xFFFF };
u16 D_800A50A8[] = { 0x1A11, 1, 0xFFFF };
u16 D_800A50B0[] = { 0x1A11, 1, 0x8008, 0, 0xFFFF };
u16 D_800A50BC[] = { 0x1A11, 1, 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A50CC[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A50D8[] = { 0x1A11, 1, 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A50E8[] = { 0x8008, 0, 0xFFFF };
u16 D_800A50F0[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A50FC[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5108[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5114[] = { 0x1A11, 0, 0xFFFF };
u16 D_800A511C[] = { 0x1A11, 1, 0xFFFF };
u16 D_800A5124[] = { 0x8008, 0, 0x1A11, 1, 0xFFFF };
u16 D_800A5130[] = { 0x8008, 1, 0x1A11, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5140[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A514C[] = { 0x1A11, 1, 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A515C[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5164[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5170[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A517C[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5188[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5190[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A519C[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A51A8[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A51B4[] = { 0x8008, 0, 0xFFFF };
u16 D_800A51BC[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A51C8[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A51D4[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A51E0[] = { 0x8008, 0, 0xFFFF };
u16 D_800A51E8[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A51F4[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5200[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A520C[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5214[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5220[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A522C[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5238[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5240[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A524C[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5258[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5264[] = { 0x8008, 0, 0xFFFF };
u16 D_800A526C[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5278[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5284[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5290[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5298[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A52A4[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A52B0[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A52BC[] = { 0x8008, 0, 0xFFFF };
u16 D_800A52C4[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A52D0[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A52DC[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A52E8[] = { 0x8008, 0, 0xFFFF };
u16 D_800A52F0[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A52FC[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5308[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5314[] = { 0x8008, 0, 0xFFFF };
u16 D_800A531C[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5328[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5334[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5340[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5348[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5354[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5360[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A536C[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5374[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5380[] = { 0x901D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A538C[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5398[] = { 0x1A10, 0, 0xFFFF };
u16 D_800A53A0[] = { 0x1A10, 1, 0xFFFF };
u16 D_800A53A8[] = { 0x1A10, 1, 0xFFFF };
u16 D_800A53B0[] = { 0x7A01, 1, 0xFFFF };
u16 D_800A53B8[] = { 0x8008, 0, 0xFFFF };
u16 D_800A53C0[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A53CC[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A53D8[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A53E4[] = { 0x8008, 0, 0xFFFF };
u16 D_800A53EC[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A53F8[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5404[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5410[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5418[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5424[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5430[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A543C[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5444[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5450[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A545C[] = { 0x8008, 1, 0xFFFF };
u16 D_800A5464[] = { 0x8008, 0, 0xFFFF };
u16 D_800A546C[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5478[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5484[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5490[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5498[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A54A4[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A54B0[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A54BC[] = { 0x8008, 0, 0xFFFF };
u16 D_800A54C4[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A54D0[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A54DC[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A54E8[] = { 0x8008, 0, 0xFFFF };
u16 D_800A54F0[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A54FC[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5508[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5514[] = { 0x8008, 0, 0xFFFF };
u16 D_800A551C[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5528[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5534[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5540[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5548[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5554[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5560[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A556C[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5574[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5580[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A558C[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5598[] = { 0x8008, 0, 0xFFFF };
u16 D_800A55A0[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A55AC[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A55B8[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A55C4[] = { 0x8008, 0, 0xFFFF };
u16 D_800A55CC[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A55D8[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A55E4[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A55F0[] = { 0x8008, 0, 0xFFFF };
u16 D_800A55F8[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5604[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A5610[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A561C[] = { 0x8008, 0, 0xFFFF };
u16 D_800A5624[] = { 0x8008, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A5630[] = { 0x901E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A563C[] = { 0x8008, 1, 0x1C1E, 1, 0xFFFF };
FieldTalk D_800A5648[] = {
    { D_800A5060, D_800A5068, 0x42 },
    { D_800A5070, D_800A5078, 0x26 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A566C[] = {
    { D_800A5080, D_800A5088, 0x43 },
    { D_800A5090, D_800A5098, 0x25 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5690[] = {
    { D_800A50A0, D_800A50A8, 0x45 },
    { D_800A50B0, NULL, 0x46 },
    { D_800A50BC, D_800A50CC, 0x47 },
    { D_800A50D8, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56CC[] = {
    { D_800A50E8, NULL, 0x46 },
    { D_800A50F0, D_800A50FC, 0x47 },
    { D_800A5108, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A56FC[] = {
    { D_800A5114, D_800A511C, 0x45 },
    { D_800A5124, NULL, 0x46 },
    { D_800A5130, D_800A5140, 0x47 },
    { D_800A514C, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5738[] = {
    { D_800A515C, NULL, 0x46 },
    { D_800A5164, D_800A5170, 0x47 },
    { D_800A517C, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5768[] = {
    { D_800A5188, NULL, 0x46 },
    { D_800A5190, D_800A519C, 0x47 },
    { D_800A51A8, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5798[] = {
    { D_800A51B4, NULL, 0x46 },
    { D_800A51BC, D_800A51C8, 0x47 },
    { D_800A51D4, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57C8[] = {
    { D_800A51E0, NULL, 0x46 },
    { D_800A51E8, D_800A51F4, 0x47 },
    { D_800A5200, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A57F8[] = {
    { D_800A520C, NULL, 0x46 },
    { D_800A5214, D_800A5220, 0x47 },
    { D_800A522C, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5828[] = {
    { D_800A5238, NULL, 0x46 },
    { D_800A5240, D_800A524C, 0x47 },
    { D_800A5258, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5858[] = {
    { D_800A5264, NULL, 0x46 },
    { D_800A526C, D_800A5278, 0x47 },
    { D_800A5284, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5888[] = {
    { D_800A5290, NULL, 0x46 },
    { D_800A5298, D_800A52A4, 0x47 },
    { D_800A52B0, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58B8[] = {
    { D_800A52BC, NULL, 0x46 },
    { D_800A52C4, D_800A52D0, 0x47 },
    { D_800A52DC, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58E8[] = {
    { D_800A52E8, NULL, 0x46 },
    { D_800A52F0, D_800A52FC, 0x47 },
    { D_800A5308, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5918[] = {
    { D_800A5314, NULL, 0x46 },
    { D_800A531C, D_800A5328, 0x47 },
    { D_800A5334, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5948[] = {
    { D_800A5340, NULL, 0x46 },
    { D_800A5348, D_800A5354, 0x47 },
    { D_800A5360, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5978[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5990[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59A8[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59C0[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59D8[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59F0[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A08[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A20[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A38[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A50[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A68[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A80[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A98[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AB0[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AC8[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AE0[] = {
    { D_800A536C, NULL, 0x46 },
    { D_800A5374, D_800A5380, 0x47 },
    { D_800A538C, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B10[] = {
    { NULL, NULL, 0xBB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B28[] = {
    { NULL, NULL, 0x21C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B40[] = {
    { NULL, NULL, 0x212 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B58[] = {
    { NULL, NULL, 0x213 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B70[] = {
    { NULL, NULL, 0x214 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B88[] = {
    { NULL, NULL, 0x215 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BA0[] = {
    { NULL, NULL, 0x216 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BB8[] = {
    { NULL, NULL, 0x217 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BD0[] = {
    { NULL, NULL, 0x218 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BE8[] = {
    { NULL, NULL, 0x219 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C00[] = {
    { NULL, NULL, 0x212 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C18[] = {
    { NULL, NULL, 0x212 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C30[] = {
    { NULL, NULL, 0x212 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C48[] = {
    { NULL, NULL, 0x212 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C60[] = {
    { NULL, NULL, 0x212 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C78[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C90[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CA8[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CC0[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CD8[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CF0[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D08[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D20[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D38[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D50[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D68[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D80[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D98[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DB0[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DC8[] = {
    { NULL, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DE0[] = {
    { NULL, NULL, 0x212 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DF8[] = {
    { NULL, NULL, 0x211 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E10[] = {
    { NULL, NULL, 0x208 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E28[] = {
    { NULL, NULL, 0x209 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E40[] = {
    { NULL, NULL, 0x20A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E58[] = {
    { NULL, NULL, 0x20B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E70[] = {
    { NULL, NULL, 0x20C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E88[] = {
    { NULL, NULL, 0x20D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EA0[] = {
    { NULL, NULL, 0x20E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EB8[] = {
    { NULL, NULL, 0x20F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5ED0[] = {
    { NULL, NULL, 0x436 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EE8[] = {
    { NULL, NULL, 0x210 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F00[] = {
    { D_800A5398, D_800A53A0, 0x44 },
    { D_800A53A8, D_800A53B0, 0x27 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F24[] = {
    { NULL, NULL, 0x436 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F3C[] = {
    { D_800A53B8, NULL, 0x48 },
    { D_800A53C0, D_800A53CC, 0x49 },
    { D_800A53D8, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F6C[] = {
    { D_800A53E4, NULL, 0x48 },
    { D_800A53EC, D_800A53F8, 0x49 },
    { D_800A5404, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F9C[] = {
    { D_800A5410, NULL, 0x48 },
    { D_800A5418, D_800A5424, 0x49 },
    { D_800A5430, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FCC[] = {
    { D_800A543C, NULL, 0x48 },
    { D_800A5444, D_800A5450, 0x49 },
    { D_800A545C, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FFC[] = {
    { D_800A5464, NULL, 0x48 },
    { D_800A546C, D_800A5478, 0x49 },
    { D_800A5484, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A602C[] = {
    { D_800A5490, NULL, 0x48 },
    { D_800A5498, D_800A54A4, 0x49 },
    { D_800A54B0, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A605C[] = {
    { D_800A54BC, NULL, 0x48 },
    { D_800A54C4, D_800A54D0, 0x49 },
    { D_800A54DC, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A608C[] = {
    { D_800A54E8, NULL, 0x48 },
    { D_800A54F0, D_800A54FC, 0x49 },
    { D_800A5508, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60BC[] = {
    { D_800A5514, NULL, 0x48 },
    { D_800A551C, D_800A5528, 0x49 },
    { D_800A5534, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A60EC[] = {
    { D_800A5540, NULL, 0x48 },
    { D_800A5548, D_800A5554, 0x49 },
    { D_800A5560, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A611C[] = {
    { D_800A556C, NULL, 0x48 },
    { D_800A5574, D_800A5580, 0x49 },
    { D_800A558C, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A614C[] = {
    { D_800A5598, NULL, 0x48 },
    { D_800A55A0, D_800A55AC, 0x49 },
    { D_800A55B8, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A617C[] = {
    { D_800A55C4, NULL, 0x48 },
    { D_800A55CC, D_800A55D8, 0x49 },
    { D_800A55E4, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61AC[] = {
    { D_800A55F0, NULL, 0x48 },
    { D_800A55F8, D_800A5604, 0x49 },
    { D_800A5610, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A61DC[] = {
    { D_800A561C, NULL, 0x48 },
    { D_800A5624, D_800A5630, 0x49 },
    { D_800A563C, NULL, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A620C[] = {
    { NULL, NULL, 0x24 },
    { NULL, NULL, 0 },
};
u16 D_800A6224[] = { 0x1C1E, 0, 0x6004, 1, 0xFFFF };
u16 D_800A6230[] = { 0x1C1E, 0, 0x602B, 1, 0xFFFF };
u16 D_800A623C[] = { 0x1C1E, 0, 0x6006, 1, 0xFFFF };
u16 D_800A6248[] = { 0x1C1E, 0, 0x6007, 1, 0xFFFF };
u16 D_800A6254[] = { 0x1C1E, 0, 0x6009, 1, 0xFFFF };
u16 D_800A6260[] = { 0x1C1E, 0, 0x600A, 1, 0xFFFF };
u16 D_800A626C[] = { 0x1C1E, 0, 0x600F, 1, 0xFFFF };
u16 D_800A6278[] = { 0x1C1E, 0, 0x6011, 1, 0xFFFF };
u16 D_800A6284[] = { 0x1C1E, 0, 0x6012, 1, 0xFFFF };
u16 D_800A6290[] = { 0x1C1E, 0, 0x6014, 1, 0xFFFF };
u16 D_800A629C[] = { 0x1C1E, 0, 0x6015, 1, 0xFFFF };
u16 D_800A62A8[] = { 0x1C1E, 0, 0x6019, 1, 0xFFFF };
u16 D_800A62B4[] = { 0x1C1E, 0, 0x601B, 1, 0xFFFF };
u16 D_800A62C0[] = { 0x1C1E, 0, 0x601D, 1, 0xFFFF };
u16 D_800A62CC[] = { 0x1C1E, 0, 0x6021, 1, 0xFFFF };
u16 D_800A62D8[] = { 0x6006, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A62E4[] = { 0x602B, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A62F0[] = { 0x6004, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A62FC[] = { 0x6007, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6308[] = { 0x6009, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6314[] = { 0x600A, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6320[] = { 0x600F, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A632C[] = { 0x6011, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6338[] = { 0x6012, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6344[] = { 0x6014, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6350[] = { 0x6015, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A635C[] = { 0x6019, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6368[] = { 0x601B, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6374[] = { 0x601D, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6380[] = { 0x6021, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A638C[] = { 0x6023, 1, 0x1C1E, 0, 0xFFFF };
u16 D_800A6398[] = { 0x6023, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A63A4[] = { 0x6004, 1, 0xFFFF };
u16 D_800A63AC[] = { 0x602B, 1, 0xFFFF };
u16 D_800A63B4[] = { 0x6006, 1, 0xFFFF };
u16 D_800A63BC[] = { 0x6007, 1, 0xFFFF };
u16 D_800A63C4[] = { 0x6009, 1, 0xFFFF };
u16 D_800A63CC[] = { 0x600A, 1, 0xFFFF };
u16 D_800A63D4[] = { 0x600F, 1, 0xFFFF };
u16 D_800A63DC[] = { 0x6011, 1, 0xFFFF };
u16 D_800A63E4[] = { 0x6019, 1, 0xFFFF };
u16 D_800A63EC[] = { 0x6014, 1, 0xFFFF };
u16 D_800A63F4[] = { 0x6012, 1, 0xFFFF };
u16 D_800A63FC[] = { 0x6021, 1, 0xFFFF };
u16 D_800A6404[] = { 0x601D, 1, 0xFFFF };
u16 D_800A640C[] = { 0x601B, 1, 0xFFFF };
u16 D_800A6414[] = { 0x6015, 1, 0xFFFF };
u16 D_800A641C[] = { 0x6005, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6428[] = { 0x6026, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6434[] = { 0x6008, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6440[] = { 0x1C1E, 1, 0x600C, 1, 0xFFFF };
u16 D_800A644C[] = { 0x600E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6458[] = { 0x6010, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6464[] = { 0x6016, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6470[] = { 0x601A, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A647C[] = { 0x601C, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6488[] = { 0x601E, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A6494[] = { 0x601F, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A64A0[] = { 0x6022, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A64AC[] = { 0x6024, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A64B8[] = { 0x6025, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A64C4[] = { 0x6018, 1, 0x1C1E, 1, 0xFFFF };
u16 D_800A64D0[] = { 0x6023, 1, 0xFFFF };
u16 D_800A64D8[] = { 0x602B, 1, 0xFFFF };
u16 D_800A64E0[] = { 0x7015, 1, 0xFFFF };
u16 D_800A64E8[] = { 0x600C, 1, 0xFFFF };
u16 D_800A64F0[] = { 0x600E, 1, 0xFFFF };
u16 D_800A64F8[] = { 0x7016, 1, 0xFFFF };
u16 D_800A6500[] = { 0x6016, 1, 0xFFFF };
u16 D_800A6508[] = { 0x7018, 1, 0xFFFF };
u16 D_800A6510[] = { 0x7019, 1, 0xFFFF };
u16 D_800A6518[] = { 0x6026, 1, 0xFFFF };
u16 D_800A6520[] = { 0x701A, 1, 0x8008, 1, 0xFFFF };
u16 D_800A652C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6534[] = { 0x701A, 1, 0x8008, 0, 0xFFFF };
u16 D_800A6540[] = { 0x1C1E, 0, 0x600E, 1, 0xFFFF };
u16 D_800A654C[] = { 0x1C1E, 0, 0x6016, 1, 0xFFFF };
u16 D_800A6558[] = { 0x1C1E, 0, 0x6018, 1, 0xFFFF };
u16 D_800A6564[] = { 0x1C1E, 0, 0x601A, 1, 0xFFFF };
u16 D_800A6570[] = { 0x1C1E, 0, 0x6010, 1, 0xFFFF };
u16 D_800A657C[] = { 0x1C1E, 0, 0x601C, 1, 0xFFFF };
u16 D_800A6588[] = { 0x1C1E, 0, 0x601E, 1, 0xFFFF };
u16 D_800A6594[] = { 0x1C1E, 0, 0x6008, 1, 0xFFFF };
u16 D_800A65A0[] = { 0x1C1E, 0, 0x6025, 1, 0xFFFF };
u16 D_800A65AC[] = { 0x1C1E, 0, 0x601F, 1, 0xFFFF };
u16 D_800A65B8[] = { 0x1C1E, 0, 0x6005, 1, 0xFFFF };
u16 D_800A65C4[] = { 0x1C1E, 0, 0x600C, 1, 0xFFFF };
u16 D_800A65D0[] = { 0x1C1E, 0, 0x6022, 1, 0xFFFF };
u16 D_800A65DC[] = { 0x1C1E, 0, 0x6024, 1, 0xFFFF };
u16 D_800A65E8[] = { 0x1C1E, 0, 0x6026, 1, 0xFFFF };
u16 D_800A65F4[] = { 0x6004, 1, 0xFFFF };
FieldActorEntry D_800A65FC = { NULL, D_800A5648, 0x16, 4, 449, 281, 7 };
FieldActorEntry D_800A6610 = { NULL, D_800A566C, 0x17, 5, 304, 369, 7 };
FieldActorEntry D_800A6624 = { D_800A6224, D_800A5690, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6638 = { D_800A6230, D_800A56CC, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A664C = { D_800A623C, D_800A56FC, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6660 = { D_800A6248, D_800A5738, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6674 = { D_800A6254, D_800A5768, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6688 = { D_800A6260, D_800A5798, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A669C = { D_800A626C, D_800A57C8, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A66B0 = { D_800A6278, D_800A57F8, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A66C4 = { D_800A6284, D_800A5828, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A66D8 = { D_800A6290, D_800A5858, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A66EC = { D_800A629C, D_800A5888, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6700 = { D_800A62A8, D_800A58B8, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6714 = { D_800A62B4, D_800A58E8, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6728 = { D_800A62C0, D_800A5918, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A673C = { D_800A62CC, D_800A5948, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6750 = { D_800A62D8, D_800A5978, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A6764 = { D_800A62E4, D_800A5990, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A6778 = { D_800A62F0, D_800A59A8, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A678C = { D_800A62FC, D_800A59C0, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A67A0 = { D_800A6308, D_800A59D8, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A67B4 = { D_800A6314, D_800A59F0, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A67C8 = { D_800A6320, D_800A5A08, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A67DC = { D_800A632C, D_800A5A20, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A67F0 = { D_800A6338, D_800A5A38, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A6804 = { D_800A6344, D_800A5A50, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A6818 = { D_800A6350, D_800A5A68, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A682C = { D_800A635C, D_800A5A80, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A6840 = { D_800A6368, D_800A5A98, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A6854 = { D_800A6374, D_800A5AB0, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A6868 = { D_800A6380, D_800A5AC8, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A687C = { D_800A638C, D_800A5AE0, 0x1E, 6, 152, 397, 7 };
FieldActorEntry D_800A6890 = { D_800A6398, D_800A5B10, 0x1E, 6, 144, 352, 1 };
FieldActorEntry D_800A68A4 = { D_800A63A4, D_800A5B28, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A68B8 = { D_800A63AC, NULL, 0x2D, 7, 287, 432, 5 };
FieldActorEntry D_800A68CC = { D_800A63B4, D_800A5B40, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A68E0 = { D_800A63BC, D_800A5B58, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A68F4 = { D_800A63C4, D_800A5B70, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A6908 = { D_800A63CC, D_800A5B88, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A691C = { D_800A63D4, D_800A5BA0, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A6930 = { D_800A63DC, D_800A5BB8, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A6944 = { D_800A63E4, D_800A5BD0, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A6958 = { D_800A63EC, D_800A5BE8, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A696C = { D_800A63F4, D_800A5C00, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A6980 = { D_800A63FC, D_800A5C18, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A6994 = { D_800A6404, D_800A5C30, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A69A8 = { D_800A640C, D_800A5C48, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A69BC = { D_800A6414, D_800A5C60, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A69D0 = { D_800A641C, D_800A5C78, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A69E4 = { D_800A6428, D_800A5C90, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A69F8 = { D_800A6434, D_800A5CA8, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6A0C = { D_800A6440, D_800A5CC0, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6A20 = { D_800A644C, D_800A5CD8, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6A34 = { D_800A6458, D_800A5CF0, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6A48 = { D_800A6464, D_800A5D08, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6A5C = { D_800A6470, D_800A5D20, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6A70 = { D_800A647C, D_800A5D38, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6A84 = { D_800A6488, D_800A5D50, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6A98 = { D_800A6494, D_800A5D68, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6AAC = { D_800A64A0, D_800A5D80, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6AC0 = { D_800A64AC, D_800A5D98, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6AD4 = { D_800A64B8, D_800A5DB0, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6AE8 = { D_800A64C4, D_800A5DC8, 0x2D, 7, 144, 352, 1 };
FieldActorEntry D_800A6AFC = { D_800A64D0, D_800A5DE0, 0x2D, 7, 336, 206, 7 };
FieldActorEntry D_800A6B10 = { D_800A64D8, D_800A5DF8, 0x33, 8, 480, 336, 3 };
FieldActorEntry D_800A6B24 = { D_800A64E0, D_800A5E10, 0x33, 8, 287, 432, 5 };
FieldActorEntry D_800A6B38 = { D_800A64E8, D_800A5E28, 0x33, 8, 287, 432, 5 };
FieldActorEntry D_800A6B4C = { D_800A64F0, D_800A5E40, 0x33, 8, 287, 432, 5 };
FieldActorEntry D_800A6B60 = { D_800A64F8, D_800A5E58, 0x33, 8, 287, 432, 5 };
FieldActorEntry D_800A6B74 = { D_800A6500, D_800A5E70, 0x33, 8, 287, 432, 5 };
FieldActorEntry D_800A6B88 = { D_800A6508, D_800A5E88, 0x33, 8, 287, 432, 5 };
FieldActorEntry D_800A6B9C = { D_800A6510, D_800A5EA0, 0x33, 8, 287, 432, 5 };
FieldActorEntry D_800A6BB0 = { D_800A6518, D_800A5EB8, 0x33, 8, 287, 432, 5 };
FieldActorEntry D_800A6BC4 = { D_800A6520, D_800A5ED0, 0x9D, 9, 144, 352, 1 };
FieldActorEntry D_800A6BD8 = { D_800A652C, D_800A5EE8, 0x9E, 0xA, 287, 432, 5 };
FieldActorEntry D_800A6BEC = { NULL, D_800A5F00, 0xB7, 0xB, 359, 308, 7 };
FieldActorEntry D_800A6C00 = { D_800A6534, D_800A5F24, 0x119, 0xC, 152, 397, 7 };
FieldActorEntry D_800A6C14 = { D_800A6540, D_800A5F3C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6C28 = { D_800A654C, D_800A5F6C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6C3C = { D_800A6558, D_800A5F9C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6C50 = { D_800A6564, D_800A5FCC, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6C64 = { D_800A6570, D_800A5FFC, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6C78 = { D_800A657C, D_800A602C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6C8C = { D_800A6588, D_800A605C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6CA0 = { D_800A6594, D_800A608C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6CB4 = { D_800A65A0, D_800A60BC, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6CC8 = { D_800A65AC, D_800A60EC, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6CDC = { D_800A65B8, D_800A611C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6CF0 = { D_800A65C4, D_800A614C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6D04 = { D_800A65D0, D_800A617C, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6D18 = { D_800A65DC, D_800A61AC, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6D2C = { D_800A65E8, D_800A61DC, 0x126, 0xD, 152, 397, 7 };
FieldActorEntry D_800A6D40 = { D_800A65F4, D_800A620C, 0x13B, 0xE, 186, 413, 3 };
FieldActorEntry *stageActors[] = {
    &D_800A65FC,
    &D_800A6610,
    &D_800A6624,
    &D_800A6638,
    &D_800A664C,
    &D_800A6660,
    &D_800A6674,
    &D_800A6688,
    &D_800A669C,
    &D_800A66B0,
    &D_800A66C4,
    &D_800A66D8,
    &D_800A66EC,
    &D_800A6700,
    &D_800A6714,
    &D_800A6728,
    &D_800A673C,
    &D_800A6750,
    &D_800A6764,
    &D_800A6778,
    &D_800A678C,
    &D_800A67A0,
    &D_800A67B4,
    &D_800A67C8,
    &D_800A67DC,
    &D_800A67F0,
    &D_800A6804,
    &D_800A6818,
    &D_800A682C,
    &D_800A6840,
    &D_800A6854,
    &D_800A6868,
    &D_800A687C,
    &D_800A6890,
    &D_800A68A4,
    &D_800A68B8,
    &D_800A68CC,
    &D_800A68E0,
    &D_800A68F4,
    &D_800A6908,
    &D_800A691C,
    &D_800A6930,
    &D_800A6944,
    &D_800A6958,
    &D_800A696C,
    &D_800A6980,
    &D_800A6994,
    &D_800A69A8,
    &D_800A69BC,
    &D_800A69D0,
    &D_800A69E4,
    &D_800A69F8,
    &D_800A6A0C,
    &D_800A6A20,
    &D_800A6A34,
    &D_800A6A48,
    &D_800A6A5C,
    &D_800A6A70,
    &D_800A6A84,
    &D_800A6A98,
    &D_800A6AAC,
    &D_800A6AC0,
    &D_800A6AD4,
    &D_800A6AE8,
    &D_800A6AFC,
    &D_800A6B10,
    &D_800A6B24,
    &D_800A6B38,
    &D_800A6B4C,
    &D_800A6B60,
    &D_800A6B74,
    &D_800A6B88,
    &D_800A6B9C,
    &D_800A6BB0,
    &D_800A6BC4,
    &D_800A6BD8,
    &D_800A6BEC,
    &D_800A6C00,
    &D_800A6C14,
    &D_800A6C28,
    &D_800A6C3C,
    &D_800A6C50,
    &D_800A6C64,
    &D_800A6C78,
    &D_800A6C8C,
    &D_800A6CA0,
    &D_800A6CB4,
    &D_800A6CC8,
    &D_800A6CDC,
    &D_800A6CF0,
    &D_800A6D04,
    &D_800A6D18,
    &D_800A6D2C,
    &D_800A6D40,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 384, 79, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 492, 137, 0, 0 },
    { 1, 0, 0x40, 2, 0x11, 2, 0, 1, 4, 0, 548, 165, 0, 0 },
    { 1, 0, 0x40, 6, 3, 1, 3, 8, 4, 0, 485, 145, 0, 0 },
    { 1, 0, 0x40, 6, 9, 1, 9, 0xE, 4, 0, 541, 172, 0, 0 },
    { 1, 0x64, 0x40, 6, 0x12, 0, 0, 0, 0, 0, 304, 99, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x13, 0, 0, 0, 0, 0, 64, 285, 0, 0 },
    { 1, 0, 0xA0, 4, 0, 0, 0, 0, 0, 0, 144, 257, 380, 0 },
    { 1, 0, 0xA0, 4, 1, 0, 0, 0, 0, 0, 256, 257, 337, 0 },
    { 1, 0, 0xA0, 4, 2, 0, 0, 0, 0, 0, 384, 261, 287, 0 },
    { 1, 0, 0x60, 4, 0xF, 0, 0, 0, 0, 0, 240, 73, 150, 0 },
    { 1, 0, 0x60, 4, 0x10, 0, 0, 0, 0, 0, 0, 255, 335, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x200, 0x1E0, 0x1DA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x200, 0x240, 0x1AA, 7, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20E, 0x218, 0xE4, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x20E, 0x128, 0x19C, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 4, 0x11F, 0xBA, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 4, 0x110, 0xFE, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 1250, D_800A4E38, EVENT_TEXT(0x2C), NULL, NULL },
    { 1251, D_800A4EC4, EVENT_TEXT(0x2D), NULL, NULL },
    { -1, NULL, 0, NULL, NULL },
};
