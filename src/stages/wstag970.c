#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x68B;
    D_800990B4.sheetEntry = 0x9430004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x942;
    D_800990B4.start = (Vec2){0x20000, 0xB900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1E;
    D_800990B4.music = 0x60780000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9430006);
    D_8009A70C.setFile(7, 0x9430007);
    D_8009A70C.setFile(4, 0x9430005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60D4;
extern StagePoint D_800A60EC;
extern StagePoint D_800A6104;
extern StagePoint D_800A611C;
extern StagePoint D_800A6134;
extern StagePoint D_800A614C;
extern StagePoint D_800A6164;
extern StagePoint D_800A617C;
extern StagePoint D_800A6194;
extern StagePoint D_800A61AC;
extern StagePoint D_800A61C4;
extern StagePoint D_800A61DC;
extern StagePoint D_800A61F4;
extern StagePoint D_800A620C;
extern StagePoint D_800A6224;
extern StagePoints D_800A60E4;
extern StagePoints D_800A60FC;
extern StagePoints D_800A6114;
extern StagePoints D_800A612C;
extern StagePoints D_800A6144;
extern StagePoints D_800A615C;
extern StagePoints D_800A6174;
extern StagePoints D_800A618C;
extern StagePoints D_800A61A4;
extern StagePoints D_800A61BC;
extern StagePoints D_800A61D4;
extern StagePoints D_800A61EC;
extern StagePoints D_800A6204;
extern StagePoints D_800A621C;
extern StagePoints D_800A6234;
extern u16 D_800A639C[];
extern u16 D_800A63A8[];
extern u16 D_800A63B4[];
extern u16 D_800A63BC[];
extern u16 D_800A63C4[];
extern u16 D_800A63D4[];
extern u16 D_800A63DC[];
extern u16 D_800A63EC[];
extern u16 D_800A63F8[];
extern u16 D_800A6408[];
extern u16 D_800A6414[];
extern u16 D_800A6424[];
extern u16 D_800A6430[];
extern u16 D_800A6438[];
extern u16 D_800A6440[];
extern u16 D_800A6450[];
extern u16 D_800A6458[];
extern u16 D_800A6468[];
extern u16 D_800A6474[];
extern u16 D_800A6484[];
extern u16 D_800A6490[];
extern u16 D_800A64A0[];
extern u16 D_800A64AC[];
extern u16 D_800A64B4[];
extern u16 D_800A64BC[];
extern u16 D_800A64CC[];
extern u16 D_800A64D4[];
extern u16 D_800A64E4[];
extern u16 D_800A64F0[];
extern u16 D_800A6500[];
extern u16 D_800A650C[];
extern u16 D_800A651C[];
extern u16 D_800A6528[];
extern u16 D_800A6530[];
extern u16 D_800A6538[];
extern u16 D_800A6548[];
extern u16 D_800A6550[];
extern u16 D_800A6560[];
extern u16 D_800A656C[];
extern u16 D_800A657C[];
extern u16 D_800A6588[];
extern u16 D_800A6598[];
extern u16 D_800A65A4[];
extern u16 D_800A65AC[];
extern u16 D_800A65B8[];
extern u16 D_800A65C0[];
extern u16 D_800A65D0[];
extern u16 D_800A65E0[];
extern u16 D_800A65F0[];
extern u16 D_800A65F8[];
extern u16 D_800A6604[];
extern u16 D_800A660C[];
extern u16 D_800A661C[];
extern u16 D_800A662C[];
extern u16 D_800A663C[];
extern u16 D_800A6644[];
extern u16 D_800A6650[];
extern u16 D_800A6658[];
extern u16 D_800A6668[];
extern u16 D_800A6678[];
extern u16 D_800A6688[];
extern u16 D_800A6690[];
extern u16 D_800A669C[];
extern u16 D_800A66A4[];
extern u16 D_800A66B4[];
extern u16 D_800A66C4[];
extern u16 D_800A66D4[];
extern u16 D_800A66DC[];
extern u16 D_800A66E8[];
extern u16 D_800A66F0[];
extern u16 D_800A6700[];
extern u16 D_800A6710[];
extern u16 D_800A6720[];
extern u16 D_800A6728[];
extern u16 D_800A6734[];
extern u16 D_800A673C[];
extern u16 D_800A674C[];
extern u16 D_800A675C[];
extern u16 D_800A6A24[];
extern FieldTalk D_800A676C[];
extern u16 D_800A6A34[];
extern FieldTalk D_800A6784[];
extern u16 D_800A6A48[];
extern FieldTalk D_800A679C[];
extern u16 D_800A6A5C[];
extern FieldTalk D_800A67E4[];
extern u16 D_800A6A70[];
extern FieldTalk D_800A682C[];
extern u16 D_800A6A84[];
extern FieldTalk D_800A6874[];
extern u16 D_800A6A98[];
extern FieldTalk D_800A68BC[];
extern u16 D_800A6AB4[];
extern FieldTalk D_800A68F8[];
extern u16 D_800A6AD0[];
extern FieldTalk D_800A6934[];
extern u16 D_800A6AEC[];
extern FieldTalk D_800A6970[];
extern u16 D_800A6B08[];
extern FieldTalk D_800A69AC[];
extern u16 D_800A6B24[];
extern FieldTalk D_800A69E8[];
extern u16 D_800A6B40[];
extern u16 D_800A6B4C[];
extern u16 D_800A6B58[];
extern u16 D_800A6B64[];
extern u16 D_800A6B74[];
extern u16 D_800A6B84[];
extern u16 D_800A6B94[];
extern FieldActorEntry D_800A6BA4;
extern FieldActorEntry D_800A6BB8;
extern FieldActorEntry D_800A6BCC;
extern FieldActorEntry D_800A6BE0;
extern FieldActorEntry D_800A6BF4;
extern FieldActorEntry D_800A6C08;
extern FieldActorEntry D_800A6C1C;
extern FieldActorEntry D_800A6C30;
extern FieldActorEntry D_800A6C44;
extern FieldActorEntry D_800A6C58;
extern FieldActorEntry D_800A6C6C;
extern FieldActorEntry D_800A6C80;
extern FieldActorEntry D_800A6C94;
extern FieldActorEntry D_800A6CA8;
extern FieldActorEntry D_800A6CBC;
extern FieldActorEntry D_800A6CD0;
extern FieldActorEntry D_800A6CE4;
extern FieldActorEntry D_800A6CF8;
extern FieldActorEntry D_800A6D0C;
extern FieldActorEntry D_800A6D20;
extern Battle D_800A6DD0;
extern Battle D_800A6DDC;
extern Battle D_800A6DE8;
extern Battle D_800A6DF4;
extern Battle D_800A6E00;
extern Battle D_800A6E0C;
extern Battle D_800A6E18;
extern Battle D_800A6E24;
extern Battle D_800A6E54;
extern Battle D_800A6E60;
extern Battle D_800A6E6C;
extern Battle D_800A6E78;
extern Battle D_800A6E84;
extern Battle D_800A6E90;
extern Battle D_800A6E9C;
extern Battle D_800A6EA8;
extern Battle D_800A6ED8;
extern Battle D_800A6EE4;
extern Battle D_800A6EF0;
extern Battle D_800A6EFC;
extern Battle D_800A6F08;
extern Battle D_800A6F14;
extern Battle D_800A6F20;
extern Battle D_800A6F2C;
extern Battle D_800A6F5C;
extern Battle D_800A6F68;
extern Battle D_800A6F74;
extern Battle D_800A6F80;
extern Battle D_800A6F8C;
extern Battle D_800A6F98;
extern Battle D_800A6FA4;
extern Battle D_800A6FB0;
extern Battle D_800A6FE0;
extern Battle D_800A6FEC;
extern Battle D_800A6FF8;
extern Battle D_800A7004;
extern Battle D_800A7010;
extern Battle D_800A701C;
extern Battle D_800A7028;
extern Battle D_800A7034;
extern Battle D_800A7064;
extern Battle D_800A7070;
extern Battle D_800A707C;
extern Battle D_800A7088;
extern Battle D_800A7094;
extern Battle D_800A70A0;
extern Battle D_800A70AC;
extern Battle D_800A70B8;
extern Battle D_800A70E8;
extern Battle D_800A70F4;
extern Battle D_800A7100;
extern Battle D_800A710C;
extern Battle D_800A7118;
extern Battle D_800A7124;
extern Battle D_800A7130;
extern Battle D_800A713C;
extern Battle D_800A716C;
extern Battle D_800A7178;
extern Battle D_800A7184;
extern Battle D_800A7190;
extern Battle D_800A719C;
extern Battle D_800A71A8;
extern Battle D_800A71B4;
extern Battle D_800A71C0;
extern Battle D_800A71F0;
extern Battle D_800A71FC;
extern Battle D_800A7208;
extern Battle D_800A7214;
extern Battle D_800A7220;
extern Battle D_800A722C;
extern Battle D_800A7238;
extern Battle D_800A7244;
extern Battle D_800A7274;
extern Battle D_800A7280;
extern Battle D_800A728C;
extern Battle D_800A7298;
extern Battle D_800A72A4;
extern Battle D_800A72B0;
extern Battle D_800A72BC;
extern Battle D_800A72C8;
extern Battle D_800A72F8;
extern Battle D_800A7304;
extern Battle D_800A7310;
extern Battle D_800A731C;
extern Battle D_800A7328;
extern Battle D_800A7334;
extern Battle D_800A7340;
extern Battle D_800A734C;
extern Battle D_800A737C;
extern Battle D_800A7388;
extern Battle D_800A7394;
extern Battle D_800A73A0;
extern Battle D_800A73AC;
extern Battle D_800A73B8;
extern Battle D_800A73C4;
extern Battle D_800A73D0;
extern Battle D_800A7400;
extern Battle D_800A740C;
extern Battle D_800A7418;
extern Battle D_800A7424;
extern Battle D_800A7430;
extern Battle D_800A743C;
extern Battle D_800A7448;
extern Battle D_800A7454;
extern Battle D_800A7484;
extern Battle D_800A7490;
extern Battle D_800A749C;
extern Battle D_800A74A8;
extern Battle D_800A74B4;
extern Battle D_800A74C0;
extern Battle D_800A74CC;
extern Battle D_800A74D8;
extern Battle D_800A7508;
extern Battle D_800A7514;
extern Battle D_800A7520;
extern Battle D_800A752C;
extern Battle D_800A7538;
extern Battle D_800A7544;
extern Battle D_800A7550;
extern Battle D_800A755C;
extern Battle D_800A758C;
extern Battle D_800A7598;
extern Battle D_800A75A4;
extern Battle D_800A75B0;
extern Battle D_800A75BC;
extern Battle D_800A75C8;
extern Battle D_800A75D4;
extern Battle D_800A75E0;
extern Battle D_800A7610;
extern Battle D_800A761C;
extern Battle D_800A7628;
extern Battle D_800A7634;
extern Battle D_800A7640;
extern Battle D_800A764C;
extern Battle D_800A7658;
extern Battle D_800A7664;
extern Battle D_800A7694;
extern Battle D_800A76A0;
extern Battle D_800A76AC;
extern Battle D_800A76B8;
extern Battle D_800A76C4;
extern Battle D_800A76D0;
extern Battle D_800A76DC;
extern Battle D_800A76E8;
extern Battle D_800A7718;
extern Battle D_800A7724;
extern Battle D_800A7730;
extern Battle D_800A773C;
extern Battle D_800A7748;
extern Battle D_800A7754;
extern Battle D_800A7760;
extern Battle D_800A776C;
extern Battle D_800A779C;
extern Battle D_800A77A8;
extern Battle D_800A77B4;
extern Battle D_800A77C0;
extern Battle D_800A77CC;
extern Battle D_800A77D8;
extern Battle D_800A77E4;
extern Battle D_800A77F0;
extern Battle D_800A7820;
extern Battle D_800A782C;
extern Battle D_800A7838;
extern Battle D_800A7844;
extern Battle D_800A7850;
extern Battle D_800A785C;
extern Battle D_800A7868;
extern Battle D_800A7874;
extern Battle D_800A78A4;
extern Battle D_800A78B0;
extern Battle D_800A78BC;
extern Battle D_800A78C8;
extern Battle D_800A78D4;
extern Battle D_800A78E0;
extern Battle D_800A78EC;
extern Battle D_800A78F8;
extern Battle D_800A7928;
extern Battle D_800A7934;
extern Battle D_800A7940;
extern Battle D_800A794C;
extern Battle D_800A7958;
extern Battle D_800A7964;
extern Battle D_800A7970;
extern Battle D_800A797C;
extern Battle D_800A79AC;
extern Battle D_800A79B8;
extern Battle D_800A79C4;
extern Battle D_800A79D0;
extern Battle D_800A79DC;
extern Battle D_800A79E8;
extern Battle D_800A79F4;
extern Battle D_800A7A00;
extern BattleList D_800A6E30;
extern BattleList D_800A6EB4;
extern BattleList D_800A6F38;
extern BattleList D_800A6FBC;
extern BattleList D_800A7040;
extern BattleList D_800A70C4;
extern BattleList D_800A7148;
extern BattleList D_800A71CC;
extern BattleList D_800A7250;
extern BattleList D_800A72D4;
extern BattleList D_800A7358;
extern BattleList D_800A73DC;
extern BattleList D_800A7460;
extern BattleList D_800A74E4;
extern BattleList D_800A7568;
extern BattleList D_800A75EC;
extern BattleList D_800A7670;
extern BattleList D_800A76F4;
extern BattleList D_800A7778;
extern BattleList D_800A77FC;
extern BattleList D_800A7880;
extern BattleList D_800A7904;
extern BattleList D_800A7988;
extern BattleList D_800A7A0C;

StagePoint D_800A60D4 = { 0x2ED, 1, 3, 0x3A0, 128, 1, NULL };
StagePoints D_800A60E4 = { 1, 1, &D_800A60D4 };
StagePoint D_800A60EC = { 0x2ED, 1, 4, 0x3A0, 128, 1, NULL };
StagePoints D_800A60FC = { 1, 2, &D_800A60EC };
StagePoint D_800A6104 = { 0x2EE, 1, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoints D_800A6114 = { 1, 3, &D_800A6104 };
StagePoint D_800A611C = { 0x2EE, 2, 1, 0x130, 200, 1, NULL };
StagePoints D_800A612C = { 2, 1, &D_800A611C };
StagePoint D_800A6134 = { 0x2EE, 2, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoints D_800A6144 = { 2, 2, &D_800A6134 };
StagePoint D_800A614C = { 0x2ED, 2, 2, 0x3A0, 128, 1, NULL };
StagePoints D_800A615C = { 2, 3, &D_800A614C };
StagePoint D_800A6164 = { 0x2EE, 2, 2, 0x130, 200, 1, NULL };
StagePoints D_800A6174 = { 2, 4, &D_800A6164 };
StagePoint D_800A617C = { 0x2EE, 2, 4, 0x3A0, 0x1A0, 1, NULL };
StagePoints D_800A618C = { 2, 5, &D_800A617C };
StagePoint D_800A6194 = { 0x2EE, 2, 5, 0x130, 200, 1, NULL };
StagePoints D_800A61A4 = { 2, 6, &D_800A6194 };
StagePoint D_800A61AC = { 0x2EE, 3, 4, 0x3A0, 0x1A0, 1, NULL };
StagePoints D_800A61BC = { 3, 1, &D_800A61AC };
StagePoint D_800A61C4 = { 0x2ED, 4, 1, 0x3A0, 128, 1, NULL };
StagePoints D_800A61D4 = { 4, 1, &D_800A61C4 };
StagePoint D_800A61DC = { 0x2EE, 5, 3, 0x130, 200, 1, NULL };
StagePoints D_800A61EC = { 5, 1, &D_800A61DC };
StagePoint D_800A61F4 = { 0x2EE, 5, 4, 0x3A0, 0x1A0, 1, NULL };
StagePoints D_800A6204 = { 5, 2, &D_800A61F4 };
StagePoint D_800A620C = { 0x2EE, 5, 5, 0x130, 200, 1, NULL };
StagePoints D_800A621C = { 5, 3, &D_800A620C };
StagePoint D_800A6224 = { 0x2ED, 6, 2, 0x3A0, 128, 1, NULL };
StagePoints D_800A6234 = { 6, 1, &D_800A6224 };
StagePoints *placePoints[] = {
    &D_800A60E4, &D_800A60FC, &D_800A6114, &D_800A612C,
    &D_800A6144, &D_800A615C, &D_800A6174, &D_800A618C,
    &D_800A61A4, &D_800A61BC, &D_800A61D4, &D_800A61EC,
    &D_800A6204, &D_800A621C, &D_800A6234, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x148, 0x180, 0x20, 0x80, 0x140, 0x1FF },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x150, 0x140, 0x40, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x160, 0x140, 0x80, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x160, 0x170, 0x80, 0x70, 0x140, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x170, 0xA8, 0x70, 0x150, 0x1FE },
    { 0x140, 0x100, 0x174, 0x170, 0xD0, 0x70, 0x160, 0x1FE },
    { 0x140, 0x100, 0x140, 0x180, 0, 0x80, 0x170, 0x1FE },
    { 0x140, 0x100, 0x170, 0x140, 0xC0, 0x40, 0x140, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x150, 0x1FD },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x160, 0x1FD },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x170, 0x1FD },
};
u16 D_800A639C[] = { 0x277, 1, 0x8464, 1, 0xFFFF };
u16 D_800A63A8[] = { 0x27A, 1, 0x802A, 1, 0xFFFF };
u16 D_800A63B4[] = { 0x8027, 1, 0xFFFF };
u16 D_800A63BC[] = { 0x7034, 1, 0xFFFF };
u16 D_800A63C4[] = { 0x8027, 0, 0, 0, 0xA18, 0, 0xFFFF };
u16 D_800A63D4[] = { 0, 1, 0xFFFF };
u16 D_800A63DC[] = { 0x8027, 0, 0, 1, 0xA18, 0, 0xFFFF };
u16 D_800A63EC[] = { 0x7401, 1, 0xA18, 1, 0xFFFF };
u16 D_800A63F8[] = { 0, 0, 0xA18, 1, 0x8027, 0, 0xFFFF };
u16 D_800A6408[] = { 0x7034, 1, 0x8027, 1, 0xFFFF };
u16 D_800A6414[] = { 0x8027, 0, 0, 1, 0xA18, 1, 0xFFFF };
u16 D_800A6424[] = { 0x8027, 1, 0x7034, 1, 0xFFFF };
u16 D_800A6430[] = { 0x8023, 1, 0xFFFF };
u16 D_800A6438[] = { 0x7032, 1, 0xFFFF };
u16 D_800A6440[] = { 0x8023, 0, 0, 0, 0xA16, 0, 0xFFFF };
u16 D_800A6450[] = { 0, 1, 0xFFFF };
u16 D_800A6458[] = { 0x8023, 0, 0, 1, 0xA16, 0, 0xFFFF };
u16 D_800A6468[] = { 0x7400, 1, 0xA16, 1, 0xFFFF };
u16 D_800A6474[] = { 0, 0, 0xA16, 1, 0x8023, 0, 0xFFFF };
u16 D_800A6484[] = { 0x7032, 1, 0x8023, 1, 0xFFFF };
u16 D_800A6490[] = { 0x8023, 0, 0, 1, 0xA16, 1, 0xFFFF };
u16 D_800A64A0[] = { 0x8023, 1, 0x7032, 1, 0xFFFF };
u16 D_800A64AC[] = { 0x8013, 1, 0xFFFF };
u16 D_800A64B4[] = { 0x7037, 1, 0xFFFF };
u16 D_800A64BC[] = { 0x8013, 0, 0, 0, 0xA19, 0, 0xFFFF };
u16 D_800A64CC[] = { 0, 1, 0xFFFF };
u16 D_800A64D4[] = { 0x8013, 0, 0, 1, 0xA19, 0, 0xFFFF };
u16 D_800A64E4[] = { 0x7402, 1, 0xA19, 1, 0xFFFF };
u16 D_800A64F0[] = { 0x8013, 0, 0, 0, 0xA19, 1, 0xFFFF };
u16 D_800A6500[] = { 0x8013, 1, 0x7037, 1, 0xFFFF };
u16 D_800A650C[] = { 0, 1, 0xA19, 1, 0x8013, 0, 0xFFFF };
u16 D_800A651C[] = { 0x7037, 1, 0x8013, 1, 0xFFFF };
u16 D_800A6528[] = { 0x818B, 1, 0xFFFF };
u16 D_800A6530[] = { 0x7039, 1, 0xFFFF };
u16 D_800A6538[] = { 0x818B, 0, 0, 0, 0xA1B, 0, 0xFFFF };
u16 D_800A6548[] = { 0, 1, 0xFFFF };
u16 D_800A6550[] = { 0x818B, 0, 0, 1, 0xA1B, 0, 0xFFFF };
u16 D_800A6560[] = { 0x7403, 1, 0xA1B, 1, 0xFFFF };
u16 D_800A656C[] = { 0, 0, 0xA1B, 1, 0x818B, 0, 0xFFFF };
u16 D_800A657C[] = { 0x7039, 1, 0x818B, 1, 0xFFFF };
u16 D_800A6588[] = { 0x818B, 0, 0, 1, 0xA1B, 1, 0xFFFF };
u16 D_800A6598[] = { 0x818B, 1, 0x7039, 1, 0xFFFF };
u16 D_800A65A4[] = { 0x8682, 1, 0xFFFF };
u16 D_800A65AC[] = { 0x8682, 0, 0, 0, 0xFFFF };
u16 D_800A65B8[] = { 0, 1, 0xFFFF };
u16 D_800A65C0[] = { 0x8682, 0, 0, 1, 0x847E, 0, 0xFFFF };
u16 D_800A65D0[] = { 0x8682, 0, 0, 1, 0x847E, 1, 0xFFFF };
u16 D_800A65E0[] = { 0x847E, 0, 0x8682, 1, 0x8681, 0, 0xFFFF };
u16 D_800A65F0[] = { 0x8683, 1, 0xFFFF };
u16 D_800A65F8[] = { 0, 0, 0x8683, 0, 0xFFFF };
u16 D_800A6604[] = { 0, 1, 0xFFFF };
u16 D_800A660C[] = { 0, 1, 0x8683, 0, 0x847F, 0, 0xFFFF };
u16 D_800A661C[] = { 0x8683, 0, 0, 1, 0x847F, 1, 0xFFFF };
u16 D_800A662C[] = { 0x8683, 1, 0x847F, 0, 0x8682, 0, 0xFFFF };
u16 D_800A663C[] = { 0x869A, 1, 0xFFFF };
u16 D_800A6644[] = { 0x869A, 0, 0, 0, 0xFFFF };
u16 D_800A6650[] = { 0, 1, 0xFFFF };
u16 D_800A6658[] = { 0x869A, 0, 0, 1, 0x8496, 0, 0xFFFF };
u16 D_800A6668[] = { 0x869A, 0, 0, 1, 0x8496, 1, 0xFFFF };
u16 D_800A6678[] = { 0x869A, 1, 0x8699, 0, 0x8496, 0, 0xFFFF };
u16 D_800A6688[] = { 0x869C, 1, 0xFFFF };
u16 D_800A6690[] = { 0x869C, 0, 0, 0, 0xFFFF };
u16 D_800A669C[] = { 0, 1, 0xFFFF };
u16 D_800A66A4[] = { 0x869C, 0, 0, 1, 0x8498, 0, 0xFFFF };
u16 D_800A66B4[] = { 0x869C, 0, 0, 1, 0x8498, 1, 0xFFFF };
u16 D_800A66C4[] = { 0x869C, 1, 0x869B, 0, 0x8498, 0, 0xFFFF };
u16 D_800A66D4[] = { 0x8669, 1, 0xFFFF };
u16 D_800A66DC[] = { 0x8669, 0, 0, 0, 0xFFFF };
u16 D_800A66E8[] = { 0, 1, 0xFFFF };
u16 D_800A66F0[] = { 0x8669, 0, 0, 1, 0x8465, 0, 0xFFFF };
u16 D_800A6700[] = { 0x8669, 0, 0, 1, 0x8465, 1, 0xFFFF };
u16 D_800A6710[] = { 0x8669, 1, 0x8668, 0, 0x8465, 0, 0xFFFF };
u16 D_800A6720[] = { 0x8668, 1, 0xFFFF };
u16 D_800A6728[] = { 0x8668, 0, 0, 0, 0xFFFF };
u16 D_800A6734[] = { 0, 1, 0xFFFF };
u16 D_800A673C[] = { 0x8668, 0, 0, 1, 0x8464, 0, 0xFFFF };
u16 D_800A674C[] = { 0x8668, 0, 0, 1, 0x8464, 1, 0xFFFF };
u16 D_800A675C[] = { 0x8668, 1, 0x8667, 0, 0x8464, 0, 0xFFFF };
FieldTalk D_800A676C[] = {
    { NULL, D_800A639C, 0xF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6784[] = {
    { NULL, D_800A63A8, 0x12 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A679C[] = {
    { D_800A63B4, D_800A63BC, 0xE1 },
    { D_800A63C4, D_800A63D4, 0xE2 },
    { D_800A63DC, D_800A63EC, 0xE3 },
    { D_800A63F8, D_800A6408, 0xE4 },
    { D_800A6414, D_800A6424, 0xE4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A67E4[] = {
    { D_800A6430, D_800A6438, 0xD9 },
    { D_800A6440, D_800A6450, 0xDA },
    { D_800A6458, D_800A6468, 0xDB },
    { D_800A6474, D_800A6484, 0xDC },
    { D_800A6490, D_800A64A0, 0xDC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A682C[] = {
    { D_800A64AC, D_800A64B4, 0xE5 },
    { D_800A64BC, D_800A64CC, 0xE6 },
    { D_800A64D4, D_800A64E4, 0xE7 },
    { D_800A64F0, D_800A6500, 0xE8 },
    { D_800A650C, D_800A651C, 0xE8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6874[] = {
    { D_800A6528, D_800A6530, 0xED },
    { D_800A6538, D_800A6548, 0xEE },
    { D_800A6550, D_800A6560, 0xEF },
    { D_800A656C, D_800A657C, 0xF0 },
    { D_800A6588, D_800A6598, 0xF0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A68BC[] = {
    { D_800A65A4, NULL, 0xAD },
    { D_800A65AC, D_800A65B8, 0xAE },
    { D_800A65C0, NULL, 0xAF },
    { D_800A65D0, D_800A65E0, 0xB0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A68F8[] = {
    { D_800A65F0, NULL, 0xC1 },
    { D_800A65F8, D_800A6604, 0xC2 },
    { D_800A660C, NULL, 0xC3 },
    { D_800A661C, D_800A662C, 0xC4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6934[] = {
    { D_800A663C, NULL, 0xA1 },
    { D_800A6644, D_800A6650, 0xA2 },
    { D_800A6658, NULL, 0xA3 },
    { D_800A6668, D_800A6678, 0xA4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6970[] = {
    { D_800A6688, NULL, 0xC9 },
    { D_800A6690, D_800A669C, 0xCA },
    { D_800A66A4, NULL, 0xCB },
    { D_800A66B4, D_800A66C4, 0xCC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69AC[] = {
    { D_800A66D4, NULL, 0xBD },
    { D_800A66DC, D_800A66E8, 0xBE },
    { D_800A66F0, NULL, 0xBF },
    { D_800A6700, D_800A6710, 0xC0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69E8[] = {
    { D_800A6720, NULL, 0xA9 },
    { D_800A6728, D_800A6734, 0xAA },
    { D_800A673C, NULL, 0xAB },
    { D_800A674C, D_800A675C, 0xAC },
    { NULL, NULL, 0 },
};
u16 D_800A6A24[] = { 0x7E02, 1, 0x7E1E, 1, 0x277, 0, 0xFFFF };
u16 D_800A6A34[] = { 0x7E03, 1, 0x7E1E, 1, 0x27A, 0, 0x802A, 0, 0xFFFF };
u16 D_800A6A48[] = { 0x7E04, 1, 0x7E1F, 1, 0x7095, 1, 0x700E, 0, 0xFFFF };
u16 D_800A6A5C[] = { 0x7E04, 1, 0x7E1E, 1, 0x7095, 1, 0x700D, 0, 0xFFFF };
u16 D_800A6A70[] = { 0x7E04, 1, 0x7E20, 1, 0x7095, 1, 0x7010, 0, 0xFFFF };
u16 D_800A6A84[] = { 0x7E05, 1, 0x7E1E, 1, 0x7095, 1, 0x7012, 0, 0xFFFF };
u16 D_800A6A98[] = {
    0x7E01, 1, 0x7E20, 1, 0x7055, 1, 0x7095, 1,
    0x8681, 1, 0x8682, 0, 0xFFFF,
};
u16 D_800A6AB4[] = {
    0x7E01, 1, 0x7E22, 1, 0x7055, 1, 0x7095, 1,
    0x8682, 1, 0x8683, 0, 0xFFFF,
};
u16 D_800A6AD0[] = {
    0x7E01, 1, 0x7E1F, 1, 0x7055, 1, 0x7095, 1,
    0x8699, 1, 0x869A, 0, 0xFFFF,
};
u16 D_800A6AEC[] = {
    0x7E01, 1, 0x7E23, 1, 0x7055, 1, 0x7095, 1,
    0x869B, 1, 0x869C, 0, 0xFFFF,
};
u16 D_800A6B08[] = {
    0x7E01, 1, 0x7E1E, 1, 0x7055, 1, 0x7095, 1,
    0x8668, 1, 0x8669, 0, 0xFFFF,
};
u16 D_800A6B24[] = {
    0x7E01, 1, 0x7E21, 1, 0x7055, 1, 0x7095, 1,
    0x8667, 1, 0x8668, 0, 0xFFFF,
};
u16 D_800A6B40[] = { 0x7E00, 1, 8, 0, 0xFFFF };
u16 D_800A6B4C[] = { 0x7E00, 0, 8, 0, 0xFFFF };
u16 D_800A6B58[] = { 0x7E00, 1, 9, 0, 0xFFFF };
u16 D_800A6B64[] = { 0x7E00, 0, 9, 0, 0x7E1E, 1, 0xFFFF };
u16 D_800A6B74[] = { 0x7E00, 0, 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A6B84[] = { 0x7E00, 0, 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A6B94[] = { 0x7E00, 0, 0x7E1E, 1, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A6BA4 = { D_800A6A24, D_800A676C, 0x21, 4, 432, 144, 1 };
FieldActorEntry D_800A6BB8 = { D_800A6A34, D_800A6784, 0x21, 4, 432, 144, 1 };
FieldActorEntry D_800A6BCC = { D_800A6A48, D_800A679C, 0x7C, 5, 432, 144, 7 };
FieldActorEntry D_800A6BE0 = { D_800A6A5C, D_800A67E4, 0x7F, 6, 432, 144, 7 };
FieldActorEntry D_800A6BF4 = { D_800A6A70, D_800A682C, 0x80, 7, 432, 144, 7 };
FieldActorEntry D_800A6C08 = { D_800A6A84, D_800A6874, 0x81, 8, 432, 144, 7 };
FieldActorEntry D_800A6C1C = { D_800A6A98, D_800A68BC, 0xA7, 9, 432, 144, 7 };
FieldActorEntry D_800A6C30 = { D_800A6AB4, D_800A68F8, 0xA7, 9, 432, 144, 7 };
FieldActorEntry D_800A6C44 = { D_800A6AD0, D_800A6934, 0xA9, 0xA, 432, 144, 7 };
FieldActorEntry D_800A6C58 = { D_800A6AEC, D_800A6970, 0xA9, 0xA, 432, 144, 7 };
FieldActorEntry D_800A6C6C = { D_800A6B08, D_800A69AC, 0xAC, 0xB, 432, 144, 7 };
FieldActorEntry D_800A6C80 = { D_800A6B24, D_800A69E8, 0xAC, 0xB, 432, 144, 7 };
FieldActorEntry D_800A6C94 = { NULL, NULL, 0x146, 0xC, 0, 0, 0 };
FieldActorEntry D_800A6CA8 = { D_800A6B40, NULL, 0x148, 0xD, 272, 488, 1 };
FieldActorEntry D_800A6CBC = { D_800A6B4C, NULL, 0x148, 0xD, 392, 380, 1 };
FieldActorEntry D_800A6CD0 = { D_800A6B58, NULL, 0x15F, 0xE, 368, 440, 1 };
FieldActorEntry D_800A6CE4 = { D_800A6B64, NULL, 0x15F, 0xE, 464, 248, 1 };
FieldActorEntry D_800A6CF8 = { D_800A6B74, NULL, 0x15F, 0xE, 384, 336, 1 };
FieldActorEntry D_800A6D0C = { D_800A6B84, NULL, 0x15F, 0xE, 456, 300, 1 };
FieldActorEntry D_800A6D20 = { D_800A6B94, NULL, 0x160, 0xF, 528, 264, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6BA4,
    &D_800A6BB8,
    &D_800A6BCC,
    &D_800A6BE0,
    &D_800A6BF4,
    &D_800A6C08,
    &D_800A6C1C,
    &D_800A6C30,
    &D_800A6C44,
    &D_800A6C58,
    &D_800A6C6C,
    &D_800A6C80,
    &D_800A6C94,
    &D_800A6CA8,
    &D_800A6CBC,
    &D_800A6CD0,
    &D_800A6CE4,
    &D_800A6CF8,
    &D_800A6D0C,
    &D_800A6D20,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2EA, 0xE0, 0x200, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6DD0 = { 140, 10, 0x60080000 };
Battle D_800A6DDC = { 140, 10, 0x60080000 };
Battle D_800A6DE8 = { 140, 10, 0x60080000 };
Battle D_800A6DF4 = { 140, 10, 0x60080000 };
Battle D_800A6E00 = { 141, 10, 0x60080000 };
Battle D_800A6E0C = { 141, 10, 0x60080000 };
Battle D_800A6E18 = { 141, 10, 0x60080000 };
Battle D_800A6E24 = { 141, 10, 0x60080000 };
BattleList D_800A6E30 = {
    3,
    { &D_800A6DD0, &D_800A6DDC, &D_800A6DE8, &D_800A6DF4,
      &D_800A6E00, &D_800A6E0C, &D_800A6E18, &D_800A6E24 },
};
Battle D_800A6E54 = { 0, 0, 0x60040000 };
Battle D_800A6E60 = { 0, 0, 0x60040000 };
Battle D_800A6E6C = { 0, 0, 0x60040000 };
Battle D_800A6E78 = { 0, 0, 0x60040000 };
Battle D_800A6E84 = { 0, 0, 0x60040000 };
Battle D_800A6E90 = { 0, 0, 0x60040000 };
Battle D_800A6E9C = { 0, 0, 0x60040000 };
Battle D_800A6EA8 = { 0, 0, 0x60040000 };
BattleList D_800A6EB4 = {
    0,
    { &D_800A6E54, &D_800A6E60, &D_800A6E6C, &D_800A6E78,
      &D_800A6E84, &D_800A6E90, &D_800A6E9C, &D_800A6EA8 },
};
Battle D_800A6ED8 = { 0, 0, 0x60040000 };
Battle D_800A6EE4 = { 0, 0, 0x60040000 };
Battle D_800A6EF0 = { 0, 0, 0x60040000 };
Battle D_800A6EFC = { 0, 0, 0x60040000 };
Battle D_800A6F08 = { 0, 0, 0x60040000 };
Battle D_800A6F14 = { 0, 0, 0x60040000 };
Battle D_800A6F20 = { 0, 0, 0x60040000 };
Battle D_800A6F2C = { 0, 0, 0x60040000 };
BattleList D_800A6F38 = {
    0,
    { &D_800A6ED8, &D_800A6EE4, &D_800A6EF0, &D_800A6EFC,
      &D_800A6F08, &D_800A6F14, &D_800A6F20, &D_800A6F2C },
};
Battle D_800A6F5C = { 0, 0, 0x60040000 };
Battle D_800A6F68 = { 0, 0, 0x60040000 };
Battle D_800A6F74 = { 0, 0, 0x60040000 };
Battle D_800A6F80 = { 0, 0, 0x60040000 };
Battle D_800A6F8C = { 0, 0, 0x60040000 };
Battle D_800A6F98 = { 0, 0, 0x60040000 };
Battle D_800A6FA4 = { 0, 0, 0x60040000 };
Battle D_800A6FB0 = { 0, 0, 0x60040000 };
BattleList D_800A6FBC = {
    0,
    { &D_800A6F5C, &D_800A6F68, &D_800A6F74, &D_800A6F80,
      &D_800A6F8C, &D_800A6F98, &D_800A6FA4, &D_800A6FB0 },
};
Battle D_800A6FE0 = { 83, 10, 0x60080000 };
Battle D_800A6FEC = { 83, 10, 0x60080000 };
Battle D_800A6FF8 = { 83, 10, 0x60080000 };
Battle D_800A7004 = { 83, 10, 0x60080000 };
Battle D_800A7010 = { 84, 10, 0x60080000 };
Battle D_800A701C = { 84, 10, 0x60080000 };
Battle D_800A7028 = { 84, 10, 0x60080000 };
Battle D_800A7034 = { 84, 10, 0x60080000 };
BattleList D_800A7040 = {
    3,
    { &D_800A6FE0, &D_800A6FEC, &D_800A6FF8, &D_800A7004,
      &D_800A7010, &D_800A701C, &D_800A7028, &D_800A7034 },
};
Battle D_800A7064 = { 0, 0, 0x60040000 };
Battle D_800A7070 = { 0, 0, 0x60040000 };
Battle D_800A707C = { 0, 0, 0x60040000 };
Battle D_800A7088 = { 0, 0, 0x60040000 };
Battle D_800A7094 = { 0, 0, 0x60040000 };
Battle D_800A70A0 = { 0, 0, 0x60040000 };
Battle D_800A70AC = { 0, 0, 0x60040000 };
Battle D_800A70B8 = { 0, 0, 0x60040000 };
BattleList D_800A70C4 = {
    0,
    { &D_800A7064, &D_800A7070, &D_800A707C, &D_800A7088,
      &D_800A7094, &D_800A70A0, &D_800A70AC, &D_800A70B8 },
};
Battle D_800A70E8 = { 0, 0, 0x60040000 };
Battle D_800A70F4 = { 0, 0, 0x60040000 };
Battle D_800A7100 = { 0, 0, 0x60040000 };
Battle D_800A710C = { 0, 0, 0x60040000 };
Battle D_800A7118 = { 0, 0, 0x60040000 };
Battle D_800A7124 = { 0, 0, 0x60040000 };
Battle D_800A7130 = { 0, 0, 0x60040000 };
Battle D_800A713C = { 0, 0, 0x60040000 };
BattleList D_800A7148 = {
    0,
    { &D_800A70E8, &D_800A70F4, &D_800A7100, &D_800A710C,
      &D_800A7118, &D_800A7124, &D_800A7130, &D_800A713C },
};
Battle D_800A716C = { 0, 0, 0x60040000 };
Battle D_800A7178 = { 0, 0, 0x60040000 };
Battle D_800A7184 = { 0, 0, 0x60040000 };
Battle D_800A7190 = { 0, 0, 0x60040000 };
Battle D_800A719C = { 0, 0, 0x60040000 };
Battle D_800A71A8 = { 0, 0, 0x60040000 };
Battle D_800A71B4 = { 0, 0, 0x60040000 };
Battle D_800A71C0 = { 0, 0, 0x60040000 };
BattleList D_800A71CC = {
    0,
    { &D_800A716C, &D_800A7178, &D_800A7184, &D_800A7190,
      &D_800A719C, &D_800A71A8, &D_800A71B4, &D_800A71C0 },
};
Battle D_800A71F0 = { 136, 10, 0x60080000 };
Battle D_800A71FC = { 136, 10, 0x60080000 };
Battle D_800A7208 = { 137, 10, 0x60080000 };
Battle D_800A7214 = { 137, 10, 0x60080000 };
Battle D_800A7220 = { 183, 10, 0x60080000 };
Battle D_800A722C = { 183, 10, 0x60080000 };
Battle D_800A7238 = { 118, 10, 0x60080000 };
Battle D_800A7244 = { 118, 10, 0x60080000 };
BattleList D_800A7250 = {
    3,
    { &D_800A71F0, &D_800A71FC, &D_800A7208, &D_800A7214,
      &D_800A7220, &D_800A722C, &D_800A7238, &D_800A7244 },
};
Battle D_800A7274 = { 0, 0, 0x60040000 };
Battle D_800A7280 = { 0, 0, 0x60040000 };
Battle D_800A728C = { 0, 0, 0x60040000 };
Battle D_800A7298 = { 0, 0, 0x60040000 };
Battle D_800A72A4 = { 0, 0, 0x60040000 };
Battle D_800A72B0 = { 0, 0, 0x60040000 };
Battle D_800A72BC = { 0, 0, 0x60040000 };
Battle D_800A72C8 = { 0, 0, 0x60040000 };
BattleList D_800A72D4 = {
    0,
    { &D_800A7274, &D_800A7280, &D_800A728C, &D_800A7298,
      &D_800A72A4, &D_800A72B0, &D_800A72BC, &D_800A72C8 },
};
Battle D_800A72F8 = { 0, 0, 0x60040000 };
Battle D_800A7304 = { 0, 0, 0x60040000 };
Battle D_800A7310 = { 0, 0, 0x60040000 };
Battle D_800A731C = { 0, 0, 0x60040000 };
Battle D_800A7328 = { 0, 0, 0x60040000 };
Battle D_800A7334 = { 0, 0, 0x60040000 };
Battle D_800A7340 = { 0, 0, 0x60040000 };
Battle D_800A734C = { 0, 0, 0x60040000 };
BattleList D_800A7358 = {
    0,
    { &D_800A72F8, &D_800A7304, &D_800A7310, &D_800A731C,
      &D_800A7328, &D_800A7334, &D_800A7340, &D_800A734C },
};
Battle D_800A737C = { 0, 0, 0x60040000 };
Battle D_800A7388 = { 0, 0, 0x60040000 };
Battle D_800A7394 = { 0, 0, 0x60040000 };
Battle D_800A73A0 = { 0, 0, 0x60040000 };
Battle D_800A73AC = { 0, 0, 0x60040000 };
Battle D_800A73B8 = { 0, 0, 0x60040000 };
Battle D_800A73C4 = { 0, 0, 0x60040000 };
Battle D_800A73D0 = { 0, 0, 0x60040000 };
BattleList D_800A73DC = {
    0,
    { &D_800A737C, &D_800A7388, &D_800A7394, &D_800A73A0,
      &D_800A73AC, &D_800A73B8, &D_800A73C4, &D_800A73D0 },
};
Battle D_800A7400 = { 117, 10, 0x60080000 };
Battle D_800A740C = { 117, 10, 0x60080000 };
Battle D_800A7418 = { 184, 10, 0x60080000 };
Battle D_800A7424 = { 184, 10, 0x60080000 };
Battle D_800A7430 = { 187, 10, 0x60080000 };
Battle D_800A743C = { 187, 10, 0x60080000 };
Battle D_800A7448 = { 187, 10, 0x60080000 };
Battle D_800A7454 = { 187, 10, 0x60080000 };
BattleList D_800A7460 = {
    3,
    { &D_800A7400, &D_800A740C, &D_800A7418, &D_800A7424,
      &D_800A7430, &D_800A743C, &D_800A7448, &D_800A7454 },
};
Battle D_800A7484 = { 0, 0, 0x60040000 };
Battle D_800A7490 = { 0, 0, 0x60040000 };
Battle D_800A749C = { 0, 0, 0x60040000 };
Battle D_800A74A8 = { 0, 0, 0x60040000 };
Battle D_800A74B4 = { 0, 0, 0x60040000 };
Battle D_800A74C0 = { 0, 0, 0x60040000 };
Battle D_800A74CC = { 0, 0, 0x60040000 };
Battle D_800A74D8 = { 0, 0, 0x60040000 };
BattleList D_800A74E4 = {
    0,
    { &D_800A7484, &D_800A7490, &D_800A749C, &D_800A74A8,
      &D_800A74B4, &D_800A74C0, &D_800A74CC, &D_800A74D8 },
};
Battle D_800A7508 = { 0, 0, 0x60040000 };
Battle D_800A7514 = { 0, 0, 0x60040000 };
Battle D_800A7520 = { 0, 0, 0x60040000 };
Battle D_800A752C = { 0, 0, 0x60040000 };
Battle D_800A7538 = { 0, 0, 0x60040000 };
Battle D_800A7544 = { 0, 0, 0x60040000 };
Battle D_800A7550 = { 0, 0, 0x60040000 };
Battle D_800A755C = { 0, 0, 0x60040000 };
BattleList D_800A7568 = {
    0,
    { &D_800A7508, &D_800A7514, &D_800A7520, &D_800A752C,
      &D_800A7538, &D_800A7544, &D_800A7550, &D_800A755C },
};
Battle D_800A758C = { 0, 0, 0x60040000 };
Battle D_800A7598 = { 0, 0, 0x60040000 };
Battle D_800A75A4 = { 0, 0, 0x60040000 };
Battle D_800A75B0 = { 0, 0, 0x60040000 };
Battle D_800A75BC = { 0, 0, 0x60040000 };
Battle D_800A75C8 = { 0, 0, 0x60040000 };
Battle D_800A75D4 = { 0, 0, 0x60040000 };
Battle D_800A75E0 = { 0, 0, 0x60040000 };
BattleList D_800A75EC = {
    0,
    { &D_800A758C, &D_800A7598, &D_800A75A4, &D_800A75B0,
      &D_800A75BC, &D_800A75C8, &D_800A75D4, &D_800A75E0 },
};
Battle D_800A7610 = { 116, 10, 0x60080000 };
Battle D_800A761C = { 116, 10, 0x60080000 };
Battle D_800A7628 = { 164, 10, 0x60080000 };
Battle D_800A7634 = { 164, 10, 0x60080000 };
Battle D_800A7640 = { 139, 10, 0x60080000 };
Battle D_800A764C = { 139, 10, 0x60080000 };
Battle D_800A7658 = { 163, 10, 0x60080000 };
Battle D_800A7664 = { 163, 10, 0x60080000 };
BattleList D_800A7670 = {
    3,
    { &D_800A7610, &D_800A761C, &D_800A7628, &D_800A7634,
      &D_800A7640, &D_800A764C, &D_800A7658, &D_800A7664 },
};
Battle D_800A7694 = { 0, 0, 0x60040000 };
Battle D_800A76A0 = { 0, 0, 0x60040000 };
Battle D_800A76AC = { 0, 0, 0x60040000 };
Battle D_800A76B8 = { 0, 0, 0x60040000 };
Battle D_800A76C4 = { 0, 0, 0x60040000 };
Battle D_800A76D0 = { 0, 0, 0x60040000 };
Battle D_800A76DC = { 0, 0, 0x60040000 };
Battle D_800A76E8 = { 0, 0, 0x60040000 };
BattleList D_800A76F4 = {
    0,
    { &D_800A7694, &D_800A76A0, &D_800A76AC, &D_800A76B8,
      &D_800A76C4, &D_800A76D0, &D_800A76DC, &D_800A76E8 },
};
Battle D_800A7718 = { 0, 0, 0x60040000 };
Battle D_800A7724 = { 0, 0, 0x60040000 };
Battle D_800A7730 = { 0, 0, 0x60040000 };
Battle D_800A773C = { 0, 0, 0x60040000 };
Battle D_800A7748 = { 0, 0, 0x60040000 };
Battle D_800A7754 = { 0, 0, 0x60040000 };
Battle D_800A7760 = { 0, 0, 0x60040000 };
Battle D_800A776C = { 0, 0, 0x60040000 };
BattleList D_800A7778 = {
    0,
    { &D_800A7718, &D_800A7724, &D_800A7730, &D_800A773C,
      &D_800A7748, &D_800A7754, &D_800A7760, &D_800A776C },
};
Battle D_800A779C = { 303, 10, 0x60880000 };
Battle D_800A77A8 = { 309, 10, 0x60880000 };
Battle D_800A77B4 = { 310, 10, 0x60880000 };
Battle D_800A77C0 = { 312, 10, 0x60880000 };
Battle D_800A77CC = { 0, 0, 0x60040000 };
Battle D_800A77D8 = { 0, 0, 0x60040000 };
Battle D_800A77E4 = { 0, 0, 0x60040000 };
Battle D_800A77F0 = { 0, 0, 0x60040000 };
BattleList D_800A77FC = {
    0,
    { &D_800A779C, &D_800A77A8, &D_800A77B4, &D_800A77C0,
      &D_800A77CC, &D_800A77D8, &D_800A77E4, &D_800A77F0 },
};
Battle D_800A7820 = { 162, 10, 0x60080000 };
Battle D_800A782C = { 162, 10, 0x60080000 };
Battle D_800A7838 = { 162, 10, 0x60080000 };
Battle D_800A7844 = { 162, 10, 0x60080000 };
Battle D_800A7850 = { 135, 10, 0x60080000 };
Battle D_800A785C = { 135, 10, 0x60080000 };
Battle D_800A7868 = { 135, 10, 0x60080000 };
Battle D_800A7874 = { 135, 10, 0x60080000 };
BattleList D_800A7880 = {
    3,
    { &D_800A7820, &D_800A782C, &D_800A7838, &D_800A7844,
      &D_800A7850, &D_800A785C, &D_800A7868, &D_800A7874 },
};
Battle D_800A78A4 = { 0, 0, 0x60040000 };
Battle D_800A78B0 = { 0, 0, 0x60040000 };
Battle D_800A78BC = { 0, 0, 0x60040000 };
Battle D_800A78C8 = { 0, 0, 0x60040000 };
Battle D_800A78D4 = { 0, 0, 0x60040000 };
Battle D_800A78E0 = { 0, 0, 0x60040000 };
Battle D_800A78EC = { 0, 0, 0x60040000 };
Battle D_800A78F8 = { 0, 0, 0x60040000 };
BattleList D_800A7904 = {
    0,
    { &D_800A78A4, &D_800A78B0, &D_800A78BC, &D_800A78C8,
      &D_800A78D4, &D_800A78E0, &D_800A78EC, &D_800A78F8 },
};
Battle D_800A7928 = { 0, 0, 0x60040000 };
Battle D_800A7934 = { 0, 0, 0x60040000 };
Battle D_800A7940 = { 0, 0, 0x60040000 };
Battle D_800A794C = { 0, 0, 0x60040000 };
Battle D_800A7958 = { 0, 0, 0x60040000 };
Battle D_800A7964 = { 0, 0, 0x60040000 };
Battle D_800A7970 = { 0, 0, 0x60040000 };
Battle D_800A797C = { 0, 0, 0x60040000 };
BattleList D_800A7988 = {
    0,
    { &D_800A7928, &D_800A7934, &D_800A7940, &D_800A794C,
      &D_800A7958, &D_800A7964, &D_800A7970, &D_800A797C },
};
Battle D_800A79AC = { 312, 10, 0x60880000 };
Battle D_800A79B8 = { 312, 10, 0x60880000 };
Battle D_800A79C4 = { 312, 10, 0x60880000 };
Battle D_800A79D0 = { 312, 10, 0x60880000 };
Battle D_800A79DC = { 312, 10, 0x60880000 };
Battle D_800A79E8 = { 312, 10, 0x60880000 };
Battle D_800A79F4 = { 312, 10, 0x60880000 };
Battle D_800A7A00 = { 312, 10, 0x60880000 };
BattleList D_800A7A0C = {
    0,
    { &D_800A79AC, &D_800A79B8, &D_800A79C4, &D_800A79D0,
      &D_800A79DC, &D_800A79E8, &D_800A79F4, &D_800A7A00 },
};
FieldBattles stageBattles[] = {
    { 415, 1, 0, { &D_800A6E30, &D_800A6EB4, &D_800A6F38, &D_800A6FBC } },
    { 421, 2, 0, { &D_800A7040, &D_800A70C4, &D_800A7148, &D_800A71CC } },
    { 427, 3, 0, { &D_800A7250, &D_800A72D4, &D_800A7358, &D_800A73DC } },
    { 433, 4, 0, { &D_800A7460, &D_800A74E4, &D_800A7568, &D_800A75EC } },
    { 438, 5, 0, { &D_800A7670, &D_800A76F4, &D_800A7778, &D_800A77FC } },
    { 444, 6, 0, { &D_800A7880, &D_800A7904, &D_800A7988, &D_800A7A0C } },
};
