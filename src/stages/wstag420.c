#include "common.h"
#include "stage.h"

/* Creates the event object of progress 4 when flag 0x4012 is set */
void updateStage(StageTask *task, void **children) {
    switch (task->state) {
    case TASK_INIT:
    default:
        if (GAME.progress == 4 && FLAGS_00.checkCondition(0x4012, 1)) {
            children[0] = FIELDSTG_startEvent(0x47);
        }
        task->nextState(task);
        break;
    case TASK_RUN:
    case TASK_DONE:
    case TASK_KILL:
        break;
    }
}

#define STAGE_CHILDREN_SIZE 4
#include "common/start_stage.inc.c"

void func_800A4D94(void) {
    FLAGS_00.applyAction(0x4012, 1);
    FLAGS_00.applyAction(0x7401, 1);
}

/* Sets flags 0x8028 and 0x8009 and the story progress to 5 */
void func_800A4DE0(void) {
    FLAGS_00.applyAction(0x8028, 1);
    FLAGS_00.applyAction(0x8009, 1);
    GAME.progress = 5;
}

#if VERSION_US
#define STAGE_TEXT 0xD4
#define EVENT_TEXT_FILE 0x12E
#define STAGE_FILE 0x775
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xCC)
#define EVENT_TEXT_FILE 0x135
#define STAGE_FILE 0x784
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x1D100, 0x1F600};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0xC;
    D_800990B4.music = 0x60300000;
    D_800990B4.actors = stageActors;
    D_800990B4.events = stageEvents;
    D_800990B4.startDir = 0;
    D_800990B4.battles = stageBattles;
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.unk50(0);
    if (GAME.progress >= 0x27 && GAME.progress < 0x29) {
        D_800990B4.soundBank = 0x1F;
        D_800990B4.music = 0x607C0000;
    }
}

void func_800A4DE0();
extern Battle D_800A50A0;
extern Battle D_800A50AC;
extern Battle D_800A50B8;
extern Battle D_800A50C4;
extern Battle D_800A50D0;
extern Battle D_800A50DC;
extern Battle D_800A50E8;
extern Battle D_800A50F4;
extern Battle D_800A5124;
extern Battle D_800A5130;
extern Battle D_800A513C;
extern Battle D_800A5148;
extern Battle D_800A5154;
extern Battle D_800A5160;
extern Battle D_800A516C;
extern Battle D_800A5178;
extern Battle D_800A51A8;
extern Battle D_800A51B4;
extern Battle D_800A51C0;
extern Battle D_800A51CC;
extern Battle D_800A51D8;
extern Battle D_800A51E4;
extern Battle D_800A51F0;
extern Battle D_800A51FC;
extern Battle D_800A522C;
extern Battle D_800A5238;
extern Battle D_800A5244;
extern Battle D_800A5250;
extern Battle D_800A525C;
extern Battle D_800A5268;
extern Battle D_800A5274;
extern Battle D_800A5280;
extern BattleList D_800A5100;
extern BattleList D_800A5184;
extern BattleList D_800A5208;
extern BattleList D_800A528C;
extern u16 D_800A53FC[];
extern u16 D_800A5404[];
extern u16 D_800A540C[];
extern u16 D_800A5418[];
extern u16 D_800A5428[];
extern u16 D_800A543C[];
extern u16 D_800A5444[];
extern u16 D_800A5458[];
extern u16 D_800A5460[];
extern u16 D_800A546C[];
extern u16 D_800A5474[];
extern u16 D_800A547C[];
extern u16 D_800A5484[];
extern u16 D_800A5490[];
extern u16 D_800A54A0[];
extern u16 D_800A54B4[];
extern u16 D_800A54BC[];
extern u16 D_800A54D0[];
extern u16 D_800A54D8[];
extern u16 D_800A54E4[];
extern u16 D_800A54EC[];
extern u16 D_800A54F4[];
extern u16 D_800A5500[];
extern u16 D_800A5508[];
extern u16 D_800A5514[];
extern u16 D_800A5520[];
extern u16 D_800A5528[];
extern u16 D_800A5530[];
extern u16 D_800A553C[];
extern u16 D_800A554C[];
extern u16 D_800A5554[];
extern u16 D_800A5568[];
extern u16 D_800A5574[];
extern u16 D_800A558C[];
extern u16 D_800A55A8[];
extern u16 D_800A55C4[];
extern u16 D_800A55CC[];
extern u16 D_800A55D4[];
extern u16 D_800A55DC[];
extern u16 D_800A55E8[];
extern u16 D_800A55F8[];
extern u16 D_800A5600[];
extern u16 D_800A5614[];
extern u16 D_800A5620[];
extern u16 D_800A5638[];
extern u16 D_800A5654[];
extern u16 D_800A5670[];
extern u16 D_800A5678[];
extern u16 D_800A5680[];
extern u16 D_800A5688[];
extern u16 D_800A5694[];
extern u16 D_800A56A4[];
extern u16 D_800A56AC[];
extern u16 D_800A56C0[];
extern u16 D_800A56CC[];
extern u16 D_800A56E4[];
extern u16 D_800A5700[];
extern u16 D_800A571C[];
extern u16 D_800A5724[];
extern u16 D_800A5738[];
extern u16 D_800A5740[];
extern u16 D_800A5754[];
extern u16 D_800A575C[];
extern u16 D_800A5764[];
extern u16 D_800A5770[];
extern u16 D_800A5778[];
extern u16 D_800A5780[];
extern u16 D_800A578C[];
extern u16 D_800A579C[];
extern u16 D_800A57A4[];
extern u16 D_800A57B8[];
extern u16 D_800A57C0[];
extern u16 D_800A57D8[];
extern u16 D_800A57F4[];
extern u16 D_800A5810[];
extern u16 D_800A5818[];
extern u16 D_800A5820[];
extern u16 D_800A5828[];
extern u16 D_800A5830[];
extern u16 D_800A5838[];
extern u16 D_800A5844[];
extern u16 D_800A60B4[];
extern FieldTalk D_800A5850[];
extern u16 D_800A60C4[];
extern FieldTalk D_800A5898[];
extern u16 D_800A60D4[];
extern FieldTalk D_800A58BC[];
extern u16 D_800A60E0[];
extern FieldTalk D_800A5904[];
extern u16 D_800A60EC[];
extern FieldTalk D_800A5928[];
extern u16 D_800A60F4[];
extern FieldTalk D_800A5940[];
extern u16 D_800A60FC[];
extern FieldTalk D_800A5958[];
extern u16 D_800A6104[];
extern u16 D_800A610C[];
extern FieldTalk D_800A5970[];
extern u16 D_800A6114[];
extern FieldTalk D_800A5988[];
extern u16 D_800A611C[];
extern FieldTalk D_800A59A0[];
extern u16 D_800A6124[];
extern FieldTalk D_800A59B8[];
extern u16 D_800A612C[];
extern FieldTalk D_800A59D0[];
extern u16 D_800A6134[];
extern FieldTalk D_800A59E8[];
extern u16 D_800A613C[];
extern FieldTalk D_800A5A00[];
extern u16 D_800A614C[];
extern FieldTalk D_800A5A30[];
extern u16 D_800A615C[];
extern FieldTalk D_800A5A90[];
extern u16 D_800A616C[];
extern FieldTalk D_800A5AF0[];
extern u16 D_800A617C[];
extern FieldTalk D_800A5B08[];
extern u16 D_800A618C[];
extern FieldTalk D_800A5B68[];
extern u16 D_800A6194[];
extern FieldTalk D_800A5B80[];
extern u16 D_800A619C[];
extern FieldTalk D_800A5B98[];
extern u16 D_800A61A4[];
extern FieldTalk D_800A5BB0[];
extern u16 D_800A61AC[];
extern FieldTalk D_800A5BC8[];
extern u16 D_800A61B4[];
extern FieldTalk D_800A5BE0[];
extern u16 D_800A61BC[];
extern FieldTalk D_800A5BF8[];
extern u16 D_800A61C4[];
extern FieldTalk D_800A5C10[];
extern u16 D_800A61CC[];
extern FieldTalk D_800A5C28[];
extern u16 D_800A61D4[];
extern FieldTalk D_800A5C40[];
extern u16 D_800A61DC[];
extern FieldTalk D_800A5C58[];
extern u16 D_800A61E4[];
extern FieldTalk D_800A5C70[];
extern u16 D_800A61EC[];
extern FieldTalk D_800A5C88[];
extern u16 D_800A61F4[];
extern FieldTalk D_800A5CD0[];
extern u16 D_800A61FC[];
extern FieldTalk D_800A5CE8[];
extern u16 D_800A6204[];
extern FieldTalk D_800A5D00[];
extern u16 D_800A620C[];
extern FieldTalk D_800A5D18[];
extern u16 D_800A6214[];
extern FieldTalk D_800A5D30[];
extern u16 D_800A621C[];
extern FieldTalk D_800A5D48[];
extern u16 D_800A6224[];
extern FieldTalk D_800A5D60[];
extern u16 D_800A6230[];
extern u16 D_800A6238[];
extern FieldTalk D_800A5D78[];
extern u16 D_800A6240[];
extern FieldTalk D_800A5D90[];
extern u16 D_800A6248[];
extern FieldTalk D_800A5DF0[];
extern u16 D_800A6250[];
extern FieldTalk D_800A5E08[];
extern u16 D_800A6258[];
extern FieldTalk D_800A5E20[];
extern u16 D_800A6260[];
extern FieldTalk D_800A5E38[];
extern u16 D_800A6268[];
extern FieldTalk D_800A5E5C[];
extern u16 D_800A6274[];
extern FieldTalk D_800A5E74[];
extern u16 D_800A6280[];
extern FieldTalk D_800A5E8C[];
extern u16 D_800A6288[];
extern FieldTalk D_800A5EA4[];
extern u16 D_800A6290[];
extern FieldTalk D_800A5EBC[];
extern u16 D_800A6298[];
extern FieldTalk D_800A5ED4[];
extern u16 D_800A62A0[];
extern FieldTalk D_800A5EEC[];
extern u16 D_800A62A8[];
extern FieldTalk D_800A5F04[];
extern u16 D_800A62B0[];
extern FieldTalk D_800A5F1C[];
extern u16 D_800A62B8[];
extern FieldTalk D_800A5F34[];
extern u16 D_800A62C4[];
extern FieldTalk D_800A5F4C[];
extern u16 D_800A62D0[];
extern FieldTalk D_800A5F64[];
extern u16 D_800A62DC[];
extern FieldTalk D_800A5F7C[];
extern u16 D_800A62E8[];
extern FieldTalk D_800A5FAC[];
extern u16 D_800A62F4[];
extern FieldTalk D_800A5FC4[];
extern u16 D_800A6304[];
extern FieldTalk D_800A5FDC[];
extern u16 D_800A630C[];
extern FieldTalk D_800A5FF4[];
extern u16 D_800A6314[];
extern FieldTalk D_800A600C[];
extern u16 D_800A631C[];
extern FieldTalk D_800A6024[];
extern u16 D_800A6324[];
extern FieldTalk D_800A603C[];
extern u16 D_800A632C[];
extern FieldTalk D_800A6054[];
extern u16 D_800A6334[];
extern FieldTalk D_800A606C[];
extern u16 D_800A633C[];
extern FieldTalk D_800A6084[];
extern u16 D_800A6344[];
extern FieldTalk D_800A609C[];
extern FieldActorEntry D_800A634C;
extern FieldActorEntry D_800A6360;
extern FieldActorEntry D_800A6374;
extern FieldActorEntry D_800A6388;
extern FieldActorEntry D_800A639C;
extern FieldActorEntry D_800A63B0;
extern FieldActorEntry D_800A63C4;
extern FieldActorEntry D_800A63D8;
extern FieldActorEntry D_800A63EC;
extern FieldActorEntry D_800A6400;
extern FieldActorEntry D_800A6414;
extern FieldActorEntry D_800A6428;
extern FieldActorEntry D_800A643C;
extern FieldActorEntry D_800A6450;
extern FieldActorEntry D_800A6464;
extern FieldActorEntry D_800A6478;
extern FieldActorEntry D_800A648C;
extern FieldActorEntry D_800A64A0;
extern FieldActorEntry D_800A64B4;
extern FieldActorEntry D_800A64C8;
extern FieldActorEntry D_800A64DC;
extern FieldActorEntry D_800A64F0;
extern FieldActorEntry D_800A6504;
extern FieldActorEntry D_800A6518;
extern FieldActorEntry D_800A652C;
extern FieldActorEntry D_800A6540;
extern FieldActorEntry D_800A6554;
extern FieldActorEntry D_800A6568;
extern FieldActorEntry D_800A657C;
extern FieldActorEntry D_800A6590;
extern FieldActorEntry D_800A65A4;
extern FieldActorEntry D_800A65B8;
extern FieldActorEntry D_800A65CC;
extern FieldActorEntry D_800A65E0;
extern FieldActorEntry D_800A65F4;
extern FieldActorEntry D_800A6608;
extern FieldActorEntry D_800A661C;
extern FieldActorEntry D_800A6630;
extern FieldActorEntry D_800A6644;
extern FieldActorEntry D_800A6658;
extern FieldActorEntry D_800A666C;
extern FieldActorEntry D_800A6680;
extern FieldActorEntry D_800A6694;
extern FieldActorEntry D_800A66A8;
extern FieldActorEntry D_800A66BC;
extern FieldActorEntry D_800A66D0;
extern FieldActorEntry D_800A66E4;
extern FieldActorEntry D_800A66F8;
extern FieldActorEntry D_800A670C;
extern FieldActorEntry D_800A6720;
extern FieldActorEntry D_800A6734;
extern FieldActorEntry D_800A6748;
extern FieldActorEntry D_800A675C;
extern FieldActorEntry D_800A6770;
extern FieldActorEntry D_800A6784;
extern FieldActorEntry D_800A6798;
extern FieldActorEntry D_800A67AC;
extern FieldActorEntry D_800A67C0;
extern FieldActorEntry D_800A67D4;
extern FieldActorEntry D_800A67E8;
extern FieldActorEntry D_800A67FC;
extern FieldActorEntry D_800A6810;
extern FieldActorEntry D_800A6824;
extern FieldActorEntry D_800A6838;
extern FieldActorEntry D_800A684C;
extern FieldActorEntry D_800A6860;
extern FieldActorEntry D_800A6874;
extern FieldActorEntry D_800A6888;
extern FieldActorEntry D_800A689C;
extern FieldActorEntry D_800A68B0;
extern s16 D_800A4F64[];
extern s16 D_800A4FC8[];

s16 D_800A4F64[] = {
    0x102, 2, 0x180, 0xDA, 1,
    0x100, 0x3C, 0x160, 0xEA,
    0x101, 0x3C, 1, 5,
    0x101, 0x32D, 0x337, 2,
    0x302, 2,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 1, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 2, 0x3C, 1,
    0x301,
    0x300, 0x1E,
    0,
};
s16 D_800A4FC8[] = {
    0x100, 2, 0x180, 0xDA,
    0x101, 2, 1, 1,
    0x100, 0x3C, 0x160, 0xEA,
    0x101, 0x3C, 1, 5,
    0x300, 0x78,
    0x200, 0, 1, 0x3C, 3,
    0x301,
    0x300, 0x1E,
    0x200, 0, 2, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 3, 0x3C, 3,
    0x301,
    0x101, 0x32D, 0x34A, 2,
    0x300, 0x1E,
    0x200, 0, 4, 2, 0,
    0x101, 2, 7, 1,
    0x301,
    0x101, 2, 1, 1,
    0x300, 0x1E,
    0x200, 0, 5, 0x3C, 3,
    0x301,
    0x300, 0x3C,
    0x200, 0, 6, 2, 0,
    0x301,
    0x300, 0x1E,
    0x200, 0, 7, 0x3C, 3,
    0x301,
    0x300, 0x1E,
    0x102, 2, 0x1E8, 0xA4, 5,
    0x300, 0x3C,
    0x304, 0x230, 0xC8, 0x1A4, 5,
    0,
};
/* the original's padding, which isn't zeros */
#if VERSION_US
__asm__(".section .data\n\t.half 0x882D\n");
#endif
Battle D_800A50A0 = { 0, 0, 0x60040000 };
Battle D_800A50AC = { 0, 0, 0x60040000 };
Battle D_800A50B8 = { 0, 0, 0x60040000 };
Battle D_800A50C4 = { 0, 0, 0x60040000 };
Battle D_800A50D0 = { 0, 0, 0x60040000 };
Battle D_800A50DC = { 0, 0, 0x60040000 };
Battle D_800A50E8 = { 0, 0, 0x60040000 };
Battle D_800A50F4 = { 0, 0, 0x60040000 };
BattleList D_800A5100 = {
    3,
    { &D_800A50A0, &D_800A50AC, &D_800A50B8, &D_800A50C4,
      &D_800A50D0, &D_800A50DC, &D_800A50E8, &D_800A50F4 },
};
Battle D_800A5124 = { 0, 0, 0x60040000 };
Battle D_800A5130 = { 0, 0, 0x60040000 };
Battle D_800A513C = { 0, 0, 0x60040000 };
Battle D_800A5148 = { 0, 0, 0x60040000 };
Battle D_800A5154 = { 0, 0, 0x60040000 };
Battle D_800A5160 = { 0, 0, 0x60040000 };
Battle D_800A516C = { 0, 0, 0x60040000 };
Battle D_800A5178 = { 0, 0, 0x60040000 };
BattleList D_800A5184 = {
    0,
    { &D_800A5124, &D_800A5130, &D_800A513C, &D_800A5148,
      &D_800A5154, &D_800A5160, &D_800A516C, &D_800A5178 },
};
Battle D_800A51A8 = { 0, 0, 0x60040000 };
Battle D_800A51B4 = { 0, 0, 0x60040000 };
Battle D_800A51C0 = { 0, 0, 0x60040000 };
Battle D_800A51CC = { 0, 0, 0x60040000 };
Battle D_800A51D8 = { 0, 0, 0x60040000 };
Battle D_800A51E4 = { 0, 0, 0x60040000 };
Battle D_800A51F0 = { 0, 0, 0x60040000 };
Battle D_800A51FC = { 0, 0, 0x60040000 };
BattleList D_800A5208 = {
    0,
    { &D_800A51A8, &D_800A51B4, &D_800A51C0, &D_800A51CC,
      &D_800A51D8, &D_800A51E4, &D_800A51F0, &D_800A51FC },
};
Battle D_800A522C = { 209, 20, 0x600C0000 };
Battle D_800A5238 = { 3, 18, 0x608C0000 };
Battle D_800A5244 = { 301, 18, 0x608C0000 };
Battle D_800A5250 = { 0, 0, 0x60040000 };
Battle D_800A525C = { 0, 0, 0x60040000 };
Battle D_800A5268 = { 0, 0, 0x60040000 };
Battle D_800A5274 = { 0, 0, 0x60040000 };
Battle D_800A5280 = { 0, 0, 0x60040000 };
BattleList D_800A528C = {
    0,
    { &D_800A522C, &D_800A5238, &D_800A5244, &D_800A5250,
      &D_800A525C, &D_800A5268, &D_800A5274, &D_800A5280 },
};
FieldBattles stageBattles[] = {
    { 155, 0, 0, { &D_800A5100, &D_800A5184, &D_800A5208, &D_800A528C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x180, 0x100, 0x1B0, 0x1D0, 0x1C0, 0xD0, 0x150, 0x1FF },
    { 0x180, 0x100, 0x1A4, 0x140, 0x190, 0x40, 0x160, 0x1FF },
    { 0x1C0, 0x100, 0x1D0, 0x100, 0x240, 0, 0x170, 0x1FF },
    { 0x1C0, 0x100, 0x1D8, 0x100, 0x260, 0, 0x140, 0x1FE },
    { 0x1C0, 0x100, 0x1E0, 0x100, 0x280, 0, 0x150, 0x1FE },
    { 0x1C0, 0x100, 0x1E8, 0x100, 0x2A0, 0, 0x170, 0x1FE },
    { 0x1C0, 0x100, 0x1D2, 0x128, 0x248, 0x28, 0x140, 0x1FD },
    { 0x1C0, 0x100, 0x1DA, 0x128, 0x268, 0x28, 0x150, 0x1FD },
    { 0x1C0, 0x100, 0x1E2, 0x128, 0x288, 0x28, 0x160, 0x1FD },
    { 0x1C0, 0x100, 0x1EA, 0x132, 0x2A8, 0x32, 0x170, 0x1FD },
    { 0x1C0, 0x100, 0x1F2, 0x132, 0x2C8, 0x32, 0x140, 0x1FC },
    { 0x1C0, 0x100, 0x1C0, 0x13E, 0x200, 0x3E, 0x150, 0x1FC },
    { 0x1C0, 0x100, 0x1C8, 0x148, 0x220, 0x48, 0x160, 0x1FC },
};
u16 D_800A53FC[] = { 0x1A2E, 0, 0xFFFF };
u16 D_800A5404[] = { 0x1A2E, 1, 0xFFFF };
u16 D_800A540C[] = { 0x1A2E, 1, 0x702C, 0, 0xFFFF };
u16 D_800A5418[] = { 0x1A2E, 1, 0x702C, 1, 0x7025, 0, 0xFFFF };
u16 D_800A5428[] = { 0x1A2E, 1, 0x702C, 1, 0x7025, 1, 0x7027, 0, 0xFFFF };
u16 D_800A543C[] = { 0x601, 1, 0xFFFF };
u16 D_800A5444[] = { 0x1A2E, 1, 0x702C, 1, 0x7025, 1, 0x7027, 1, 0xFFFF };
u16 D_800A5458[] = { 0x700C, 0, 0xFFFF };
u16 D_800A5460[] = { 0x7033, 1, 0x7013, 1, 0xFFFF };
u16 D_800A546C[] = { 0x700C, 1, 0xFFFF };
u16 D_800A5474[] = { 0x1A2E, 0, 0xFFFF };
u16 D_800A547C[] = { 0x1A2E, 1, 0xFFFF };
u16 D_800A5484[] = { 0x1A2E, 1, 0x702C, 0, 0xFFFF };
u16 D_800A5490[] = { 0x1A2E, 1, 0x702C, 1, 0x7025, 0, 0xFFFF };
u16 D_800A54A0[] = { 0x1A2E, 1, 0x702C, 1, 0x7025, 1, 0x7027, 0, 0xFFFF };
u16 D_800A54B4[] = { 0x601, 1, 0xFFFF };
u16 D_800A54BC[] = { 0x1A2E, 1, 0x702C, 1, 0x7025, 1, 0x7027, 1, 0xFFFF };
u16 D_800A54D0[] = { 0x700C, 0, 0xFFFF };
u16 D_800A54D8[] = { 0x7033, 1, 0x7013, 1, 0xFFFF };
u16 D_800A54E4[] = { 0x700C, 1, 0xFFFF };
u16 D_800A54EC[] = { 0x11, 0, 0xFFFF };
u16 D_800A54F4[] = { 0x10, 0, 0x11, 1, 0xFFFF };
u16 D_800A5500[] = { 0x11, 0, 0xFFFF };
u16 D_800A5508[] = { 0x10, 1, 0x11, 1, 0xFFFF };
u16 D_800A5514[] = { 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A5520[] = { 0, 0, 0xFFFF };
u16 D_800A5528[] = { 0, 1, 0xFFFF };
u16 D_800A5530[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A553C[] = { 0, 1, 0x7201, 1, 0x7203, 0, 0xFFFF };
u16 D_800A554C[] = { 0x7613, 1, 0xFFFF };
u16 D_800A5554[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE09, 0, 0xFFFF };
u16 D_800A5568[] = { 0x7400, 1, 0xE09, 1, 0xFFFF };
u16 D_800A5574[] = {
    0x7201, 1, 0xE09, 1, 0, 1, 0x7203, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A558C[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE09, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A55A8[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE09, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A55C4[] = { 0x7813, 1, 0xFFFF };
u16 D_800A55CC[] = { 0, 0, 0xFFFF };
u16 D_800A55D4[] = { 0, 1, 0xFFFF };
u16 D_800A55DC[] = { 0, 1, 0x7201, 0, 0xFFFF };
u16 D_800A55E8[] = { 0, 1, 0x7203, 0, 0x7201, 1, 0xFFFF };
u16 D_800A55F8[] = { 0x7613, 1, 0xFFFF };
u16 D_800A5600[] = { 0, 1, 0x7203, 1, 0x7201, 1, 0xE09, 0, 0xFFFF };
u16 D_800A5614[] = { 0xE09, 1, 0x7400, 1, 0xFFFF };
u16 D_800A5620[] = {
    0x7201, 1, 0xE09, 1, 0, 1, 0x7203, 1,
    0x8012, 0, 0xFFFF,
};
u16 D_800A5638[] = {
    0, 1, 0x7203, 1, 0x8012, 1, 0x7201, 1,
    0xE09, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5654[] = {
    0, 1, 0x7203, 1, 0x8012, 1, 0x7201, 1,
    0xE09, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A5670[] = { 0x7813, 1, 0xFFFF };
u16 D_800A5678[] = { 0, 0, 0xFFFF };
u16 D_800A5680[] = { 0, 1, 0xFFFF };
u16 D_800A5688[] = { 0x7201, 0, 0, 1, 0xFFFF };
u16 D_800A5694[] = { 0x7201, 1, 0, 1, 0x7203, 0, 0xFFFF };
u16 D_800A56A4[] = { 0x7613, 1, 0xFFFF };
u16 D_800A56AC[] = { 0, 1, 0x7201, 1, 0x7203, 1, 0xE09, 0, 0xFFFF };
u16 D_800A56C0[] = { 0x7400, 1, 0xE09, 1, 0xFFFF };
u16 D_800A56CC[] = {
    0, 1, 0x7203, 1, 0x8012, 0, 0x7201, 1,
    0xE09, 1, 0xFFFF,
};
u16 D_800A56E4[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE09, 1,
    0x8012, 1, 0x7205, 0, 0xFFFF,
};
u16 D_800A5700[] = {
    0, 1, 0x7201, 1, 0x7203, 1, 0xE09, 1,
    0x8012, 1, 0x7205, 1, 0xFFFF,
};
u16 D_800A571C[] = { 0x7813, 1, 0xFFFF };
u16 D_800A5724[] = { 0x7020, 1, 0x6020, 0, 0x6021, 0, 5, 0, 0xFFFF };
u16 D_800A5738[] = { 5, 1, 0xFFFF };
u16 D_800A5740[] = { 5, 1, 0x7020, 1, 0x6020, 0, 0x6021, 0, 0xFFFF };
u16 D_800A5754[] = { 0x6020, 1, 0xFFFF };
u16 D_800A575C[] = { 0x6021, 1, 0xFFFF };
u16 D_800A5764[] = { 0x7019, 1, 0x7020, 0, 0xFFFF };
u16 D_800A5770[] = { 0x902E, 1, 0xFFFF };
u16 D_800A5778[] = { 0, 0, 0xFFFF };
u16 D_800A5780[] = { 0x7201, 0, 0, 1, 0xFFFF };
u16 D_800A578C[] = { 0x7201, 1, 0, 1, 0x7203, 0, 0xFFFF };
u16 D_800A579C[] = { 0x7613, 1, 0xFFFF };
u16 D_800A57A4[] = { 0x7201, 1, 0xE09, 0, 0, 1, 0x7203, 1, 0xFFFF };
u16 D_800A57B8[] = { 0xE09, 1, 0xFFFF };
u16 D_800A57C0[] = {
    0, 1, 0x7203, 1, 0x8012, 0, 0x7201, 1,
    0xE09, 1, 0xFFFF,
};
u16 D_800A57D8[] = {
    0x7201, 1, 0xE09, 1, 0x7205, 0, 0, 1,
    0x7203, 1, 0x8012, 1, 0xFFFF,
};
u16 D_800A57F4[] = {
    0x7201, 1, 0xE09, 1, 0x7205, 1, 0, 1,
    0x7203, 1, 0x8012, 1, 0xFFFF,
};
u16 D_800A5810[] = { 0x7813, 1, 0xFFFF };
u16 D_800A5818[] = { 0x1C1C, 0, 0xFFFF };
u16 D_800A5820[] = { 0x1C1C, 1, 0xFFFF };
u16 D_800A5828[] = { 0x1C47, 0, 0xFFFF };
u16 D_800A5830[] = { 0x1C47, 1, 0xFFFF };
u16 D_800A5838[] = { 0x1C47, 1, 0x818E, 0, 0xFFFF };
u16 D_800A5844[] = { 0x818E, 1, 0x1C47, 1, 0xFFFF };
FieldTalk D_800A5850[] = {
    { D_800A53FC, D_800A5404, 0x114 },
    { D_800A540C, NULL, 0x11A },
    { D_800A5418, NULL, 0x11C },
    { D_800A5428, D_800A543C, 0x115 },
    { D_800A5444, NULL, 0x11B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5898[] = {
    { D_800A5458, D_800A5460, 0x116 },
    { D_800A546C, NULL, 0x119 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A58BC[] = {
    { D_800A5474, D_800A547C, 0x114 },
    { D_800A5484, NULL, 0x11A },
    { D_800A5490, NULL, 0x11C },
    { D_800A54A0, D_800A54B4, 0x115 },
    { D_800A54BC, NULL, 0x11B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5904[] = {
    { D_800A54D0, D_800A54D8, 0x116 },
    { D_800A54E4, NULL, 0x119 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5928[] = {
    { NULL, NULL, 0x29 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5940[] = {
    { NULL, NULL, 0xA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5958[] = {
    { NULL, NULL, 0x10 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5970[] = {
    { NULL, NULL, 0x33 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5988[] = {
    { NULL, NULL, 0x2E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59A0[] = {
    { NULL, NULL, 0x15 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59B8[] = {
    { NULL, NULL, 0x1A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59D0[] = {
    { NULL, NULL, 0x1F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A59E8[] = {
    { NULL, NULL, 0x24 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A00[] = {
    { D_800A54EC, NULL, 0xD5 },
    { D_800A54F4, D_800A5500, 0xE0 },
    { D_800A5508, D_800A5514, 0xE1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A30[] = {
    { D_800A5520, D_800A5528, 0xD6 },
    { D_800A5530, NULL, 0xDA },
    { D_800A553C, D_800A554C, 0xDB },
    { D_800A5554, D_800A5568, 0xDC },
    { D_800A5574, NULL, 0xDD },
    { D_800A558C, NULL, 0xDE },
    { D_800A55A8, D_800A55C4, 0xDF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5A90[] = {
    { D_800A55CC, D_800A55D4, 0xD7 },
    { D_800A55DC, NULL, 0xDA },
    { D_800A55E8, D_800A55F8, 0xDB },
    { D_800A5600, D_800A5614, 0xDC },
    { D_800A5620, NULL, 0xDD },
    { D_800A5638, NULL, 0xDE },
    { D_800A5654, D_800A5670, 0xDF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5AF0[] = {
    { NULL, NULL, 0x118 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B08[] = {
    { D_800A5678, D_800A5680, 0xD5 },
    { D_800A5688, NULL, 0xDA },
    { D_800A5694, D_800A56A4, 0xDB },
    { D_800A56AC, D_800A56C0, 0xDC },
    { D_800A56CC, NULL, 0xDD },
    { D_800A56E4, NULL, 0xDE },
    { D_800A5700, D_800A571C, 0xDF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B68[] = {
    { NULL, NULL, 0x11 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B80[] = {
    { NULL, NULL, 0x3E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5B98[] = {
    { NULL, NULL, 0x34 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BB0[] = {
    { NULL, NULL, 0x2F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BC8[] = {
    { NULL, NULL, 0xB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BE0[] = {
    { NULL, NULL, 0x2A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5BF8[] = {
    { NULL, NULL, 0x16 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C10[] = {
    { NULL, NULL, 0x1B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C28[] = {
    { NULL, NULL, 0x20 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C40[] = {
    { NULL, NULL, 0x25 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C58[] = {
    { NULL, NULL, 0x2B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C70[] = {
    { NULL, NULL, 0x35 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5C88[] = {
    { D_800A5724, D_800A5738, 0x30 },
    { D_800A5740, NULL, 6 },
    { D_800A5754, NULL, 0x2B },
    { D_800A575C, NULL, 0x2B },
    { D_800A5764, NULL, 0x2B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CD0[] = {
    { NULL, NULL, 0x12 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5CE8[] = {
    { NULL, NULL, 0x17 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D00[] = {
    { NULL, NULL, 0x1C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D18[] = {
    { NULL, NULL, 0x21 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D30[] = {
    { NULL, NULL, 0x26 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D48[] = {
    { NULL, NULL, 0x3F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D60[] = {
    { NULL, D_800A5770, 0x127 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D78[] = {
    { NULL, NULL, 0x3A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5D90[] = {
    { D_800A5778, NULL, 0xD8 },
    { D_800A5780, NULL, 0xD8 },
    { D_800A578C, D_800A579C, 0xD8 },
    { D_800A57A4, D_800A57B8, 0xD8 },
    { D_800A57C0, NULL, 0xD8 },
    { D_800A57D8, NULL, 0xD8 },
    { D_800A57F4, D_800A5810, 0xD8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5DF0[] = {
    { NULL, NULL, 0x39 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E08[] = {
    { NULL, NULL, 0x38 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E20[] = {
    { NULL, NULL, 0x117 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E38[] = {
    { D_800A5818, NULL, 0x23 },
    { D_800A5820, NULL, 0xE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E5C[] = {
    { NULL, NULL, 0xC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E74[] = {
    { NULL, NULL, 0xF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5E8C[] = {
    { NULL, NULL, 0x37 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EA4[] = {
    { NULL, NULL, 0x32 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EBC[] = {
    { NULL, NULL, 0x2D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5ED4[] = {
    { NULL, NULL, 0x28 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5EEC[] = {
    { NULL, NULL, 0x14 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F04[] = {
    { NULL, NULL, 0x19 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F1C[] = {
    { NULL, NULL, 0x1E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F34[] = {
    { NULL, NULL, 0x23 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F4C[] = {
    { NULL, NULL, 0xF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F64[] = {
    { NULL, NULL, 0x175 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5F7C[] = {
    { D_800A5828, D_800A5830, 0x16A },
    { D_800A5838, NULL, 0x16B },
    { D_800A5844, NULL, 0x16D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FAC[] = {
    { NULL, NULL, 0xD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FC4[] = {
    { NULL, NULL, 0x13 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FDC[] = {
    { NULL, NULL, 0x40 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A5FF4[] = {
    { NULL, NULL, 0x3B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A600C[] = {
    { NULL, NULL, 0x36 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6024[] = {
    { NULL, NULL, 0x31 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A603C[] = {
    { NULL, NULL, 0x18 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6054[] = {
    { NULL, NULL, 0x1D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A606C[] = {
    { NULL, NULL, 0x22 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6084[] = {
    { NULL, NULL, 0x2C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A609C[] = {
    { NULL, NULL, 0x27 },
    { NULL, NULL, 0 },
};
u16 D_800A60B4[] = { 0x7022, 1, 0x6004, 0, 0x8022, 0, 0xFFFF };
u16 D_800A60C4[] = { 0x7022, 1, 0x6004, 0, 0x8022, 1, 0xFFFF };
u16 D_800A60D4[] = { 0x602B, 1, 0x8022, 0, 0xFFFF };
u16 D_800A60E0[] = { 0x602B, 1, 0x8022, 1, 0xFFFF };
u16 D_800A60EC[] = { 0x7018, 1, 0xFFFF };
u16 D_800A60F4[] = { 0x6004, 1, 0xFFFF };
u16 D_800A60FC[] = { 0x7015, 1, 0xFFFF };
u16 D_800A6104[] = { 0x602B, 1, 0xFFFF };
u16 D_800A610C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A6114[] = { 0x7019, 1, 0xFFFF };
u16 D_800A611C[] = { 0x600C, 1, 0xFFFF };
u16 D_800A6124[] = { 0x600E, 1, 0xFFFF };
u16 D_800A612C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A6134[] = { 0x7017, 1, 0xFFFF };
u16 D_800A613C[] = { 0x8192, 1, 0x7009, 1, 0x11, 1, 0xFFFF };
u16 D_800A614C[] = { 0x8192, 1, 0x7004, 1, 0x11, 0, 0xFFFF };
u16 D_800A615C[] = { 0x6026, 1, 0x8192, 1, 0x11, 0, 0xFFFF };
u16 D_800A616C[] = { 0x8192, 0, 0x7009, 1, 0x701A, 0, 0xFFFF };
u16 D_800A617C[] = { 0x11, 0, 0x7003, 1, 0x8192, 1, 0xFFFF };
u16 D_800A618C[] = { 0x7015, 1, 0xFFFF };
u16 D_800A6194[] = { 0x602B, 1, 0xFFFF };
u16 D_800A619C[] = { 0x6026, 1, 0xFFFF };
u16 D_800A61A4[] = { 0x7019, 1, 0xFFFF };
u16 D_800A61AC[] = { 0x6004, 1, 0xFFFF };
u16 D_800A61B4[] = { 0x7018, 1, 0xFFFF };
u16 D_800A61BC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A61C4[] = { 0x600E, 1, 0xFFFF };
u16 D_800A61CC[] = { 0x7016, 1, 0xFFFF };
u16 D_800A61D4[] = { 0x7017, 1, 0xFFFF };
u16 D_800A61DC[] = { 0x7018, 1, 0xFFFF };
u16 D_800A61E4[] = { 0x6026, 1, 0xFFFF };
u16 D_800A61EC[] = { 0x7019, 1, 0xFFFF };
u16 D_800A61F4[] = { 0x7015, 1, 0xFFFF };
u16 D_800A61FC[] = { 0x600C, 1, 0xFFFF };
u16 D_800A6204[] = { 0x600E, 1, 0xFFFF };
u16 D_800A620C[] = { 0x7016, 1, 0xFFFF };
u16 D_800A6214[] = { 0x7017, 1, 0xFFFF };
u16 D_800A621C[] = { 0x602B, 1, 0xFFFF };
u16 D_800A6224[] = { 0x6004, 1, 0x1C11, 1, 0xFFFF };
u16 D_800A6230[] = { 0x6004, 1, 0xFFFF };
u16 D_800A6238[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6240[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6248[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6250[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6258[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6260[] = { 0x6014, 1, 0xFFFF };
u16 D_800A6268[] = { 0x6004, 1, 0x1C11, 1, 0xFFFF };
u16 D_800A6274[] = { 0x7015, 1, 0x6008, 0, 0xFFFF };
u16 D_800A6280[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6288[] = { 0x6026, 1, 0xFFFF };
u16 D_800A6290[] = { 0x7019, 1, 0xFFFF };
u16 D_800A6298[] = { 0x7018, 1, 0xFFFF };
u16 D_800A62A0[] = { 0x600C, 1, 0xFFFF };
u16 D_800A62A8[] = { 0x600E, 1, 0xFFFF };
u16 D_800A62B0[] = { 0x7016, 1, 0xFFFF };
u16 D_800A62B8[] = { 0x7017, 1, 0x6014, 0, 0xFFFF };
u16 D_800A62C4[] = { 0x6008, 1, 0x1A17, 0, 0xFFFF };
u16 D_800A62D0[] = { 0x6008, 1, 0x1A17, 1, 0xFFFF };
u16 D_800A62DC[] = { 0x1C46, 1, 0x6006, 1, 0xFFFF };
u16 D_800A62E8[] = { 0x6004, 1, 0x1C11, 1, 0xFFFF };
u16 D_800A62F4[] = { 0x6006, 0, 0x7015, 1, 0x6008, 0, 0xFFFF };
u16 D_800A6304[] = { 0x602B, 1, 0xFFFF };
u16 D_800A630C[] = { 0x701A, 1, 0xFFFF };
u16 D_800A6314[] = { 0x6026, 1, 0xFFFF };
u16 D_800A631C[] = { 0x7019, 1, 0xFFFF };
u16 D_800A6324[] = { 0x600C, 1, 0xFFFF };
u16 D_800A632C[] = { 0x600E, 1, 0xFFFF };
u16 D_800A6334[] = { 0x7016, 1, 0xFFFF };
u16 D_800A633C[] = { 0x7018, 1, 0xFFFF };
u16 D_800A6344[] = { 0x7017, 1, 0xFFFF };
FieldActorEntry D_800A634C = { D_800A60B4, D_800A5850, 0x2B, 4, 1089, 402, 1 };
FieldActorEntry D_800A6360 = { D_800A60C4, D_800A5898, 0x2B, 4, 1089, 402, 1 };
FieldActorEntry D_800A6374 = { D_800A60D4, D_800A58BC, 0x2B, 4, 1089, 402, 1 };
FieldActorEntry D_800A6388 = { D_800A60E0, D_800A5904, 0x2B, 4, 1089, 402, 1 };
FieldActorEntry D_800A639C = { D_800A60EC, D_800A5928, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A63B0 = { D_800A60F4, D_800A5940, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A63C4 = { D_800A60FC, D_800A5958, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A63D8 = { D_800A6104, NULL, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A63EC = { D_800A610C, D_800A5970, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A6400 = { D_800A6114, D_800A5988, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A6414 = { D_800A611C, D_800A59A0, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A6428 = { D_800A6124, D_800A59B8, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A643C = { D_800A612C, D_800A59D0, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A6450 = { D_800A6134, D_800A59E8, 0x2E, 5, 882, 585, 3 };
FieldActorEntry D_800A6464 = { D_800A613C, D_800A5A00, 0x2F, 6, 449, 481, 1 };
FieldActorEntry D_800A6478 = { D_800A614C, D_800A5A30, 0x2F, 6, 449, 481, 1 };
FieldActorEntry D_800A648C = { D_800A615C, D_800A5A90, 0x2F, 6, 449, 481, 1 };
FieldActorEntry D_800A64A0 = { D_800A616C, D_800A5AF0, 0x2F, 6, 449, 481, 1 };
FieldActorEntry D_800A64B4 = { D_800A617C, D_800A5B08, 0x2F, 6, 449, 481, 1 };
FieldActorEntry D_800A64C8 = { D_800A618C, D_800A5B68, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A64DC = { D_800A6194, D_800A5B80, 0x32, 7, 552, 459, 3 };
FieldActorEntry D_800A64F0 = { D_800A619C, D_800A5B98, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A6504 = { D_800A61A4, D_800A5BB0, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A6518 = { D_800A61AC, D_800A5BC8, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A652C = { D_800A61B4, D_800A5BE0, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A6540 = { D_800A61BC, D_800A5BF8, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A6554 = { D_800A61C4, D_800A5C10, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A6568 = { D_800A61CC, D_800A5C28, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A657C = { D_800A61D4, D_800A5C40, 0x32, 7, 914, 344, 7 };
FieldActorEntry D_800A6590 = { D_800A61DC, D_800A5C58, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A65A4 = { D_800A61E4, D_800A5C70, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A65B8 = { D_800A61EC, D_800A5C88, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A65CC = { D_800A61F4, D_800A5CD0, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A65E0 = { D_800A61FC, D_800A5CE8, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A65F4 = { D_800A6204, D_800A5D00, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A6608 = { D_800A620C, D_800A5D18, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A661C = { D_800A6214, D_800A5D30, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A6630 = { D_800A621C, D_800A5D48, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A6644 = { D_800A6224, D_800A5D60, 0x3C, 8, 352, 234, 1 };
FieldActorEntry D_800A6658 = { D_800A6230, NULL, 0x67, 9, 0, 0, 0 };
FieldActorEntry D_800A666C = { D_800A6238, D_800A5D78, 0x9D, 0xA, 352, 234, 1 };
FieldActorEntry D_800A6680 = { D_800A6240, D_800A5D90, 0x9E, 0xB, 449, 481, 1 };
FieldActorEntry D_800A6694 = { D_800A6248, D_800A5DF0, 0x9F, 0xC, 914, 344, 7 };
FieldActorEntry D_800A66A8 = { D_800A6250, D_800A5E08, 0xA0, 0xD, 882, 585, 3 };
FieldActorEntry D_800A66BC = { D_800A6258, D_800A5E20, 0xA1, 0xE, 1089, 402, 1 };
FieldActorEntry D_800A66D0 = { D_800A6260, D_800A5E38, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A66E4 = { D_800A6268, D_800A5E5C, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A66F8 = { D_800A6274, D_800A5E74, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A670C = { D_800A6280, D_800A5E8C, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A6720 = { D_800A6288, D_800A5EA4, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A6734 = { D_800A6290, D_800A5EBC, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A6748 = { D_800A6298, D_800A5ED4, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A675C = { D_800A62A0, D_800A5EEC, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A6770 = { D_800A62A8, D_800A5F04, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A6784 = { D_800A62B0, D_800A5F1C, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A6798 = { D_800A62B8, D_800A5F34, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A67AC = { D_800A62C4, D_800A5F4C, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A67C0 = { D_800A62D0, D_800A5F64, 0x16D, 0xF, 632, 406, 1 };
FieldActorEntry D_800A67D4 = { D_800A62DC, D_800A5F7C, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A67E8 = { D_800A62E8, D_800A5FAC, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A67FC = { D_800A62F4, D_800A5FC4, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A6810 = { D_800A6304, D_800A5FDC, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A6824 = { D_800A630C, D_800A5FF4, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A6838 = { D_800A6314, D_800A600C, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A684C = { D_800A631C, D_800A6024, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A6860 = { D_800A6324, D_800A603C, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A6874 = { D_800A632C, D_800A6054, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A6888 = { D_800A6334, D_800A606C, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A689C = { D_800A633C, D_800A6084, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry D_800A68B0 = { D_800A6344, D_800A609C, 0x171, 0x10, 833, 257, 5 };
FieldActorEntry *stageActors[] = {
    &D_800A634C,
    &D_800A6360,
    &D_800A6374,
    &D_800A6388,
    &D_800A639C,
    &D_800A63B0,
    &D_800A63C4,
    &D_800A63D8,
    &D_800A63EC,
    &D_800A6400,
    &D_800A6414,
    &D_800A6428,
    &D_800A643C,
    &D_800A6450,
    &D_800A6464,
    &D_800A6478,
    &D_800A648C,
    &D_800A64A0,
    &D_800A64B4,
    &D_800A64C8,
    &D_800A64DC,
    &D_800A64F0,
    &D_800A6504,
    &D_800A6518,
    &D_800A652C,
    &D_800A6540,
    &D_800A6554,
    &D_800A6568,
    &D_800A657C,
    &D_800A6590,
    &D_800A65A4,
    &D_800A65B8,
    &D_800A65CC,
    &D_800A65E0,
    &D_800A65F4,
    &D_800A6608,
    &D_800A661C,
    &D_800A6630,
    &D_800A6644,
    &D_800A6658,
    &D_800A666C,
    &D_800A6680,
    &D_800A6694,
    &D_800A66A8,
    &D_800A66BC,
    &D_800A66D0,
    &D_800A66E4,
    &D_800A66F8,
    &D_800A670C,
    &D_800A6720,
    &D_800A6734,
    &D_800A6748,
    &D_800A675C,
    &D_800A6770,
    &D_800A6784,
    &D_800A6798,
    &D_800A67AC,
    &D_800A67C0,
    &D_800A67D4,
    &D_800A67E8,
    &D_800A67FC,
    &D_800A6810,
    &D_800A6824,
    &D_800A6838,
    &D_800A684C,
    &D_800A6860,
    &D_800A6874,
    &D_800A6888,
    &D_800A689C,
    &D_800A68B0,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0x4A, 2, 0, 1, 0, 3, 6, 0, 441, 290, 0, 0 },
    { 1, 0, 0x4A, 2, 0, 1, 0, 3, 6, 0, 817, 114, 0, 0 },
    { 1, 0, 0x4A, 2, 0, 1, 0, 3, 6, 0, 949, 528, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 7, 4, 0, 366, 274, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 7, 4, 0, 446, 241, 0, 0 },
    { 1, 0, 0x40, 2, 4, 1, 4, 7, 4, 0, 1129, 333, 0, 0 },
    { 1, 0, 0x80, 2, 0x24, 0, 0, 0, 0, 0, 469, 191, 0, 0 },
    { 1, 0, 0x80, 2, 0x25, 0, 0, 0, 0, 0, 256, 161, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 411, 424, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 538, 379, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 568, 341, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 607, 347, 0, 0 },
    { 1, 0, 0x40, 6, 8, 1, 8, 0xB, 4, 0, 976, 215, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 544, 363, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 579, 380, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 884, 243, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 913, 244, 0, 0 },
    { 1, 0, 0x40, 6, 0xC, 1, 0xC, 0xF, 4, 0, 1020, 218, 0, 0 },
    { 1, 0, 0x40, 6, 0x10, 1, 0x10, 0x12, 4, 0, 906, 526, 0, 0 },
    { 1, 0x64, 0x40, 6, 0x1B, 0, 0, 0, 0, 0, 721, 200, 0, 0 },
    { 1, 0x65, 0x40, 6, 0x1C, 0, 0, 0, 0, 0, 451, 367, 0, 0 },
    { 1, 0, 0x40, 4, 8, 1, 8, 0xB, 4, 0, 448, 405, 445, 0 },
    { 1, 0, 0x40, 4, 0xC, 1, 0xC, 0xF, 4, 0, 465, 438, 464, 0 },
    { 1, 0, 0x40, 4, 0xC, 1, 0xC, 0xF, 4, 0, 737, 256, 281, 0 },
    { 1, 0, 0x40, 4, 0x18, 0, 0, 0, 0, 0, 898, 552, 576, 0 },
    { 1, 0, 0x40, 4, 0x19, 0, 0, 0, 0, 0, 727, 260, 280, 0 },
    { 1, 0, 0x40, 4, 0x1A, 0, 0, 0, 0, 0, 447, 417, 444, 0 },
    { 1, 0, 0x64, 4, 0x1D, 0, 0, 0, 0, 0, 784, 496, 560, 0 },
    { 1, 0, 0x64, 4, 0x1E, 0, 0, 0, 0, 0, 768, 488, 552, 0 },
    { 1, 0, 0x64, 4, 0x1F, 0, 0, 0, 0, 0, 752, 480, 544, 0 },
    { 1, 0, 0x64, 4, 0x20, 0, 0, 0, 0, 0, 736, 472, 536, 0 },
    { 1, 0, 0x64, 4, 0x21, 0, 0, 0, 0, 0, 720, 464, 528, 0 },
    { 1, 0, 0x64, 4, 0x22, 0, 0, 0, 0, 0, 704, 456, 520, 0 },
    { 1, 0, 0x64, 4, 0x23, 0, 0, 0, 0, 0, 672, 456, 496, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x229, 0x448, 0xF8, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x230, 0xC8, 0x1A4, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x230, 0x1B8, 0x204, 3, 0x64, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x22F, 0x208, 0x1AC, 3, 0x65, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x231, 0x1A7, 0x254, 3, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 3, 6, 0x400, 0x120, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 2, 6, 0x410, 0x188, 0, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
FieldEvent stageEvents[] = {
    { 70, D_800A4F64, EVENT_TEXT(2), NULL, func_800A4D94 },
    { 71, D_800A4FC8, EVENT_TEXT(3), NULL, func_800A4DE0 },
    { -1, NULL, 0, NULL, NULL },
};
