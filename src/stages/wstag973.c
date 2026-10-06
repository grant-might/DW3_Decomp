#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x695;
    D_800990B4.sheetEntry = 0x9490004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x948;
    D_800990B4.start = (Vec2){0x18200, 0x7E00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1E;
    D_800990B4.music = 0x60780000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9490006);
    D_8009A70C.setFile(7, 0x9490007);
    D_8009A70C.setFile(4, 0x9490005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60D8;
extern StagePoint D_800A60E8;
extern StagePoint D_800A60F8;
extern StagePoint D_800A6110;
extern StagePoint D_800A6120;
extern StagePoint D_800A6130;
extern StagePoint D_800A6148;
extern StagePoint D_800A6158;
extern StagePoint D_800A6168;
extern StagePoint D_800A6180;
extern StagePoint D_800A6190;
extern StagePoint D_800A61A0;
extern StagePoint D_800A61B8;
extern StagePoint D_800A61C8;
extern StagePoint D_800A61D8;
extern StagePoint D_800A61F0;
extern StagePoint D_800A6200;
extern StagePoint D_800A6210;
extern StagePoint D_800A6228;
extern StagePoint D_800A6238;
extern StagePoint D_800A6248;
extern StagePoint D_800A6260;
extern StagePoint D_800A6270;
extern StagePoint D_800A6280;
extern StagePoint D_800A6298;
extern StagePoint D_800A62A8;
extern StagePoint D_800A62B8;
extern StagePoint D_800A62D0;
extern StagePoint D_800A62E0;
extern StagePoint D_800A62F0;
extern StagePoint D_800A6308;
extern StagePoint D_800A6318;
extern StagePoint D_800A6328;
extern StagePoint D_800A6340;
extern StagePoint D_800A6350;
extern StagePoint D_800A6360;
extern StagePoint D_800A6378;
extern StagePoint D_800A6388;
extern StagePoint D_800A6398;
extern StagePoint D_800A63B0;
extern StagePoint D_800A63C0;
extern StagePoint D_800A63D0;
extern StagePoint D_800A63E8;
extern StagePoint D_800A63F8;
extern StagePoint D_800A6408;
extern StagePoint D_800A6420;
extern StagePoint D_800A6430;
extern StagePoint D_800A6440;
extern StagePoint D_800A6458;
extern StagePoint D_800A6468;
extern StagePoint D_800A6478;
extern StagePoint D_800A6490;
extern StagePoint D_800A64A0;
extern StagePoint D_800A64B0;
extern StagePoint D_800A64C8;
extern StagePoint D_800A64D8;
extern StagePoint D_800A64E8;
extern StagePoint D_800A6500;
extern StagePoint D_800A6510;
extern StagePoint D_800A6520;
extern StagePoint D_800A6538;
extern StagePoint D_800A6548;
extern StagePoint D_800A6558;
extern StagePoint D_800A6570;
extern StagePoint D_800A6580;
extern StagePoint D_800A6590;
extern StagePoint D_800A65A8;
extern StagePoint D_800A65B8;
extern StagePoint D_800A65C8;
extern StagePoint D_800A65E0;
extern StagePoint D_800A65F0;
extern StagePoint D_800A6600;
extern StagePoint D_800A6618;
extern StagePoint D_800A6628;
extern StagePoint D_800A6638;
extern StagePoint D_800A6650;
extern StagePoint D_800A6660;
extern StagePoint D_800A6670;
extern StagePoint D_800A6688;
extern StagePoint D_800A6698;
extern StagePoint D_800A66A8;
extern StagePoint D_800A66C0;
extern StagePoint D_800A66D0;
extern StagePoint D_800A66E0;
extern StagePoint D_800A66F8;
extern StagePoint D_800A6708;
extern StagePoint D_800A6718;
extern StagePoints D_800A6108;
extern StagePoints D_800A6140;
extern StagePoints D_800A6178;
extern StagePoints D_800A61B0;
extern StagePoints D_800A61E8;
extern StagePoints D_800A6220;
extern StagePoints D_800A6258;
extern StagePoints D_800A6290;
extern StagePoints D_800A62C8;
extern StagePoints D_800A6300;
extern StagePoints D_800A6338;
extern StagePoints D_800A6370;
extern StagePoints D_800A63A8;
extern StagePoints D_800A63E0;
extern StagePoints D_800A6418;
extern StagePoints D_800A6450;
extern StagePoints D_800A6488;
extern StagePoints D_800A64C0;
extern StagePoints D_800A64F8;
extern StagePoints D_800A6530;
extern StagePoints D_800A6568;
extern StagePoints D_800A65A0;
extern StagePoints D_800A65D8;
extern StagePoints D_800A6610;
extern StagePoints D_800A6648;
extern StagePoints D_800A6680;
extern StagePoints D_800A66B8;
extern StagePoints D_800A66F0;
extern StagePoints D_800A6728;
extern u16 D_800A6888[];
extern u16 D_800A6894[];
extern u16 D_800A68A0[];
extern u16 D_800A68AC[];
extern u16 D_800A68B8[];
extern u16 D_800A68C0[];
extern u16 D_800A68C8[];
extern u16 D_800A68D0[];
extern u16 D_800A68DC[];
extern u16 D_800A68E4[];
extern u16 D_800A68EC[];
extern u16 D_800A68F4[];
extern u16 D_800A6900[];
extern u16 D_800A6908[];
extern u16 D_800A6910[];
extern u16 D_800A6918[];
extern u16 D_800A6924[];
extern u16 D_800A692C[];
extern u16 D_800A6934[];
extern u16 D_800A693C[];
extern u16 D_800A6A38[];
extern FieldTalk D_800A6948[];
extern u16 D_800A6A48[];
extern FieldTalk D_800A6960[];
extern u16 D_800A6A58[];
extern FieldTalk D_800A6978[];
extern u16 D_800A6A68[];
extern FieldTalk D_800A6990[];
extern u16 D_800A6A7C[];
extern u16 D_800A6A8C[];
extern u16 D_800A6A9C[];
extern u16 D_800A6AAC[];
extern u16 D_800A6ABC[];
extern u16 D_800A6ACC[];
extern u16 D_800A6AD8[];
extern u16 D_800A6AE4[];
extern u16 D_800A6AF0[];
extern u16 D_800A6B00[];
extern u16 D_800A6B10[];
extern u16 D_800A6B20[];
extern u16 D_800A6B30[];
extern u16 D_800A6B40[];
extern FieldTalk D_800A69A8[];
extern u16 D_800A6B50[];
extern FieldTalk D_800A69CC[];
extern u16 D_800A6B60[];
extern FieldTalk D_800A69F0[];
extern u16 D_800A6B70[];
extern FieldTalk D_800A6A14[];
extern FieldActorEntry D_800A6B80;
extern FieldActorEntry D_800A6B94;
extern FieldActorEntry D_800A6BA8;
extern FieldActorEntry D_800A6BBC;
extern FieldActorEntry D_800A6BD0;
extern FieldActorEntry D_800A6BE4;
extern FieldActorEntry D_800A6BF8;
extern FieldActorEntry D_800A6C0C;
extern FieldActorEntry D_800A6C20;
extern FieldActorEntry D_800A6C34;
extern FieldActorEntry D_800A6C48;
extern FieldActorEntry D_800A6C5C;
extern FieldActorEntry D_800A6C70;
extern FieldActorEntry D_800A6C84;
extern FieldActorEntry D_800A6C98;
extern FieldActorEntry D_800A6CAC;
extern FieldActorEntry D_800A6CC0;
extern FieldActorEntry D_800A6CD4;
extern FieldActorEntry D_800A6CE8;
extern FieldActorEntry D_800A6CFC;
extern FieldActorEntry D_800A6D10;
extern FieldActorEntry D_800A6D24;
extern Battle D_800A6E0C;
extern Battle D_800A6E18;
extern Battle D_800A6E24;
extern Battle D_800A6E30;
extern Battle D_800A6E3C;
extern Battle D_800A6E48;
extern Battle D_800A6E54;
extern Battle D_800A6E60;
extern Battle D_800A6E90;
extern Battle D_800A6E9C;
extern Battle D_800A6EA8;
extern Battle D_800A6EB4;
extern Battle D_800A6EC0;
extern Battle D_800A6ECC;
extern Battle D_800A6ED8;
extern Battle D_800A6EE4;
extern Battle D_800A6F14;
extern Battle D_800A6F20;
extern Battle D_800A6F2C;
extern Battle D_800A6F38;
extern Battle D_800A6F44;
extern Battle D_800A6F50;
extern Battle D_800A6F5C;
extern Battle D_800A6F68;
extern Battle D_800A6F98;
extern Battle D_800A6FA4;
extern Battle D_800A6FB0;
extern Battle D_800A6FBC;
extern Battle D_800A6FC8;
extern Battle D_800A6FD4;
extern Battle D_800A6FE0;
extern Battle D_800A6FEC;
extern Battle D_800A701C;
extern Battle D_800A7028;
extern Battle D_800A7034;
extern Battle D_800A7040;
extern Battle D_800A704C;
extern Battle D_800A7058;
extern Battle D_800A7064;
extern Battle D_800A7070;
extern Battle D_800A70A0;
extern Battle D_800A70AC;
extern Battle D_800A70B8;
extern Battle D_800A70C4;
extern Battle D_800A70D0;
extern Battle D_800A70DC;
extern Battle D_800A70E8;
extern Battle D_800A70F4;
extern Battle D_800A7124;
extern Battle D_800A7130;
extern Battle D_800A713C;
extern Battle D_800A7148;
extern Battle D_800A7154;
extern Battle D_800A7160;
extern Battle D_800A716C;
extern Battle D_800A7178;
extern Battle D_800A71A8;
extern Battle D_800A71B4;
extern Battle D_800A71C0;
extern Battle D_800A71CC;
extern Battle D_800A71D8;
extern Battle D_800A71E4;
extern Battle D_800A71F0;
extern Battle D_800A71FC;
extern Battle D_800A722C;
extern Battle D_800A7238;
extern Battle D_800A7244;
extern Battle D_800A7250;
extern Battle D_800A725C;
extern Battle D_800A7268;
extern Battle D_800A7274;
extern Battle D_800A7280;
extern Battle D_800A72B0;
extern Battle D_800A72BC;
extern Battle D_800A72C8;
extern Battle D_800A72D4;
extern Battle D_800A72E0;
extern Battle D_800A72EC;
extern Battle D_800A72F8;
extern Battle D_800A7304;
extern Battle D_800A7334;
extern Battle D_800A7340;
extern Battle D_800A734C;
extern Battle D_800A7358;
extern Battle D_800A7364;
extern Battle D_800A7370;
extern Battle D_800A737C;
extern Battle D_800A7388;
extern Battle D_800A73B8;
extern Battle D_800A73C4;
extern Battle D_800A73D0;
extern Battle D_800A73DC;
extern Battle D_800A73E8;
extern Battle D_800A73F4;
extern Battle D_800A7400;
extern Battle D_800A740C;
extern Battle D_800A743C;
extern Battle D_800A7448;
extern Battle D_800A7454;
extern Battle D_800A7460;
extern Battle D_800A746C;
extern Battle D_800A7478;
extern Battle D_800A7484;
extern Battle D_800A7490;
extern Battle D_800A74C0;
extern Battle D_800A74CC;
extern Battle D_800A74D8;
extern Battle D_800A74E4;
extern Battle D_800A74F0;
extern Battle D_800A74FC;
extern Battle D_800A7508;
extern Battle D_800A7514;
extern Battle D_800A7544;
extern Battle D_800A7550;
extern Battle D_800A755C;
extern Battle D_800A7568;
extern Battle D_800A7574;
extern Battle D_800A7580;
extern Battle D_800A758C;
extern Battle D_800A7598;
extern Battle D_800A75C8;
extern Battle D_800A75D4;
extern Battle D_800A75E0;
extern Battle D_800A75EC;
extern Battle D_800A75F8;
extern Battle D_800A7604;
extern Battle D_800A7610;
extern Battle D_800A761C;
extern Battle D_800A764C;
extern Battle D_800A7658;
extern Battle D_800A7664;
extern Battle D_800A7670;
extern Battle D_800A767C;
extern Battle D_800A7688;
extern Battle D_800A7694;
extern Battle D_800A76A0;
extern Battle D_800A76D0;
extern Battle D_800A76DC;
extern Battle D_800A76E8;
extern Battle D_800A76F4;
extern Battle D_800A7700;
extern Battle D_800A770C;
extern Battle D_800A7718;
extern Battle D_800A7724;
extern Battle D_800A7754;
extern Battle D_800A7760;
extern Battle D_800A776C;
extern Battle D_800A7778;
extern Battle D_800A7784;
extern Battle D_800A7790;
extern Battle D_800A779C;
extern Battle D_800A77A8;
extern Battle D_800A77D8;
extern Battle D_800A77E4;
extern Battle D_800A77F0;
extern Battle D_800A77FC;
extern Battle D_800A7808;
extern Battle D_800A7814;
extern Battle D_800A7820;
extern Battle D_800A782C;
extern Battle D_800A785C;
extern Battle D_800A7868;
extern Battle D_800A7874;
extern Battle D_800A7880;
extern Battle D_800A788C;
extern Battle D_800A7898;
extern Battle D_800A78A4;
extern Battle D_800A78B0;
extern Battle D_800A78E0;
extern Battle D_800A78EC;
extern Battle D_800A78F8;
extern Battle D_800A7904;
extern Battle D_800A7910;
extern Battle D_800A791C;
extern Battle D_800A7928;
extern Battle D_800A7934;
extern Battle D_800A7964;
extern Battle D_800A7970;
extern Battle D_800A797C;
extern Battle D_800A7988;
extern Battle D_800A7994;
extern Battle D_800A79A0;
extern Battle D_800A79AC;
extern Battle D_800A79B8;
extern Battle D_800A79E8;
extern Battle D_800A79F4;
extern Battle D_800A7A00;
extern Battle D_800A7A0C;
extern Battle D_800A7A18;
extern Battle D_800A7A24;
extern Battle D_800A7A30;
extern Battle D_800A7A3C;
extern BattleList D_800A6E6C;
extern BattleList D_800A6EF0;
extern BattleList D_800A6F74;
extern BattleList D_800A6FF8;
extern BattleList D_800A707C;
extern BattleList D_800A7100;
extern BattleList D_800A7184;
extern BattleList D_800A7208;
extern BattleList D_800A728C;
extern BattleList D_800A7310;
extern BattleList D_800A7394;
extern BattleList D_800A7418;
extern BattleList D_800A749C;
extern BattleList D_800A7520;
extern BattleList D_800A75A4;
extern BattleList D_800A7628;
extern BattleList D_800A76AC;
extern BattleList D_800A7730;
extern BattleList D_800A77B4;
extern BattleList D_800A7838;
extern BattleList D_800A78BC;
extern BattleList D_800A7940;
extern BattleList D_800A79C4;
extern BattleList D_800A7A48;

StagePoint D_800A60D8 = { 0x2EB, 1, 2, 0x240, 160, 1, NULL };
StagePoint D_800A60E8 = { 0x2EE, 1, 1, 0x130, 200, 1, &D_800A60D8 };
StagePoint D_800A60F8 = { 0x2EC, 1, 1, 240, 0x1D8, 5, &D_800A60E8 };
StagePoints D_800A6108 = { 1, 1, &D_800A60F8 };
StagePoint D_800A6110 = { 0x2EB, 1, 3, 0x240, 160, 1, NULL };
StagePoint D_800A6120 = { 0x2EC, 1, 2, 0x3B0, 120, 1, &D_800A6110 };
StagePoint D_800A6130 = { 0x2EC, 1, 3, 240, 0x1D8, 5, &D_800A6120 };
StagePoints D_800A6140 = { 1, 2, &D_800A6130 };
StagePoint D_800A6148 = { 0x2EC, 1, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A6158 = { 0x2EC, 1, 4, 0x3B0, 120, 1, &D_800A6148 };
StagePoint D_800A6168 = { 0x2EA, 1, 1, 224, 0x200, 5, &D_800A6158 };
StagePoints D_800A6178 = { 1, 3, &D_800A6168 };
StagePoint D_800A6180 = { 0x2EC, 1, 5, 0x3B0, 120, 1, NULL };
StagePoint D_800A6190 = { 0x2EE, 1, 3, 0x130, 200, 1, &D_800A6180 };
StagePoint D_800A61A0 = { 0x2EA, 1, 2, 224, 0x200, 5, &D_800A6190 };
StagePoints D_800A61B0 = { 1, 4, &D_800A61A0 };
StagePoint D_800A61B8 = { 0x2EB, 1, 5, 0x240, 160, 1, NULL };
StagePoint D_800A61C8 = { 0x2EE, 1, 4, 0x130, 200, 1, &D_800A61B8 };
StagePoint D_800A61D8 = { 0x2EC, 1, 6, 240, 0x1D8, 5, &D_800A61C8 };
StagePoints D_800A61E8 = { 1, 5, &D_800A61D8 };
StagePoint D_800A61F0 = { 0x2EE, 2, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6200 = { 0x2EE, 2, 3, 0x130, 200, 1, &D_800A61F0 };
StagePoint D_800A6210 = { 0x2EE, 2, 1, 224, 0x240, 5, &D_800A6200 };
StagePoints D_800A6220 = { 2, 1, &D_800A6210 };
StagePoint D_800A6228 = { 0x2EE, 2, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6238 = { 0x2EE, 2, 4, 0x130, 200, 1, &D_800A6228 };
StagePoint D_800A6248 = { 0x2EA, 2, 3, 224, 0x200, 5, &D_800A6238 };
StagePoints D_800A6258 = { 2, 2, &D_800A6248 };
StagePoint D_800A6260 = { 0x2EE, 2, 5, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6270 = { 0x2ED, 2, 4, 0x3A0, 128, 1, &D_800A6260 };
StagePoint D_800A6280 = { 0x2EE, 2, 2, 224, 0x240, 5, &D_800A6270 };
StagePoints D_800A6290 = { 2, 3, &D_800A6280 };
StagePoint D_800A6298 = { 0x2EE, 2, 7, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A62A8 = { 0x2EE, 2, 8, 0x130, 200, 1, &D_800A6298 };
StagePoint D_800A62B8 = { 0x2ED, 2, 3, 0x350, 0x1F8, 5, &D_800A62A8 };
StagePoints D_800A62C8 = { 2, 4, &D_800A62B8 };
StagePoint D_800A62D0 = { 0x2EC, 3, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A62E0 = { 0x2ED, 3, 2, 0x3A0, 128, 1, &D_800A62D0 };
StagePoint D_800A62F0 = { 0x2EC, 3, 1, 240, 0x1D8, 5, &D_800A62E0 };
StagePoints D_800A6300 = { 3, 1, &D_800A62F0 };
StagePoint D_800A6308 = { 0x2EC, 3, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A6318 = { 0x2ED, 3, 3, 0x3A0, 128, 1, &D_800A6308 };
StagePoint D_800A6328 = { 0x2ED, 3, 1, 0x350, 0x1F8, 5, &D_800A6318 };
StagePoints D_800A6338 = { 3, 2, &D_800A6328 };
StagePoint D_800A6340 = { 0x2EE, 3, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6350 = { 0x2EC, 3, 6, 0x3B0, 120, 1, &D_800A6340 };
StagePoint D_800A6360 = { 0x2ED, 3, 2, 0x350, 0x1F8, 5, &D_800A6350 };
StagePoints D_800A6370 = { 3, 3, &D_800A6360 };
StagePoint D_800A6378 = { 0x2EC, 4, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A6388 = { 0x2EC, 4, 3, 0x3B0, 120, 1, &D_800A6378 };
StagePoint D_800A6398 = { 0x2EA, 4, 1, 224, 0x200, 5, &D_800A6388 };
StagePoints D_800A63A8 = { 4, 1, &D_800A6398 };
StagePoint D_800A63B0 = { 0x2EC, 4, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A63C0 = { 0x2EC, 4, 5, 0x3B0, 120, 1, &D_800A63B0 };
StagePoint D_800A63D0 = { 0x2EC, 4, 3, 240, 0x1D8, 5, &D_800A63C0 };
StagePoints D_800A63E0 = { 4, 2, &D_800A63D0 };
StagePoint D_800A63E8 = { 0x2EC, 4, 6, 0x3B0, 120, 1, NULL };
StagePoint D_800A63F8 = { 0x2EC, 4, 7, 0x3B0, 120, 1, &D_800A63E8 };
StagePoint D_800A6408 = { 0x2EE, 4, 1, 224, 0x240, 5, &D_800A63F8 };
StagePoints D_800A6418 = { 4, 3, &D_800A6408 };
StagePoint D_800A6420 = { 0x2EC, 5, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A6430 = { 0x2ED, 5, 2, 0x3A0, 128, 1, &D_800A6420 };
StagePoint D_800A6440 = { 0x2E8, 5, 1, 176, 0x168, 5, &D_800A6430 };
StagePoints D_800A6450 = { 5, 1, &D_800A6440 };
StagePoint D_800A6458 = { 0x2EC, 5, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A6468 = { 0x2ED, 5, 4, 0x3A0, 128, 1, &D_800A6458 };
StagePoint D_800A6478 = { 0x2ED, 5, 1, 0x350, 0x1F8, 5, &D_800A6468 };
StagePoints D_800A6488 = { 5, 2, &D_800A6478 };
StagePoint D_800A6490 = { 0x2ED, 5, 5, 0x3A0, 128, 1, NULL };
StagePoint D_800A64A0 = { 0x2EE, 5, 1, 0x130, 200, 1, &D_800A6490 };
StagePoint D_800A64B0 = { 0x2EC, 5, 1, 240, 0x1D8, 5, &D_800A64A0 };
StagePoints D_800A64C0 = { 5, 3, &D_800A64B0 };
StagePoint D_800A64C8 = { 0x2EB, 5, 1, 0x240, 160, 1, NULL };
StagePoint D_800A64D8 = { 0x2EC, 5, 3, 0x3B0, 120, 1, &D_800A64C8 };
StagePoint D_800A64E8 = { 0x2ED, 5, 2, 0x350, 0x1F8, 5, &D_800A64D8 };
StagePoints D_800A64F8 = { 5, 4, &D_800A64E8 };
StagePoint D_800A6500 = { 0x2EB, 5, 2, 0x240, 160, 1, NULL };
StagePoint D_800A6510 = { 0x2EE, 5, 2, 0x130, 200, 1, &D_800A6500 };
StagePoint D_800A6520 = { 0x2ED, 5, 3, 224, 192, 5, &D_800A6510 };
StagePoints D_800A6530 = { 5, 5, &D_800A6520 };
StagePoint D_800A6538 = { 0x2EE, 5, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6548 = { 0x2EB, 5, 3, 0x240, 160, 1, &D_800A6538 };
StagePoint D_800A6558 = { 0x2EC, 5, 3, 240, 0x1D8, 5, &D_800A6548 };
StagePoints D_800A6568 = { 5, 6, &D_800A6558 };
StagePoint D_800A6570 = { 0x2EC, 6, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A6580 = { 0x2EE, 6, 1, 0x130, 200, 1, &D_800A6570 };
StagePoint D_800A6590 = { 0x2EC, 6, 1, 240, 0x1D8, 5, &D_800A6580 };
StagePoints D_800A65A0 = { 6, 1, &D_800A6590 };
StagePoint D_800A65A8 = { 0x2EE, 6, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A65B8 = { 0x2EC, 6, 3, 0x3B0, 120, 1, &D_800A65A8 };
StagePoint D_800A65C8 = { 0x2EA, 6, 1, 224, 0x200, 5, &D_800A65B8 };
StagePoints D_800A65D8 = { 6, 2, &D_800A65C8 };
StagePoint D_800A65E0 = { 0x2ED, 6, 4, 0x3A0, 128, 1, NULL };
StagePoint D_800A65F0 = { 0x2ED, 6, 5, 0x3A0, 128, 1, &D_800A65E0 };
StagePoint D_800A6600 = { 0x2EC, 6, 2, 240, 0x1D8, 5, &D_800A65F0 };
StagePoints D_800A6610 = { 6, 3, &D_800A6600 };
StagePoint D_800A6618 = { 0x2EB, 6, 1, 0x240, 160, 1, NULL };
StagePoint D_800A6628 = { 0x2EE, 6, 3, 0x130, 200, 1, &D_800A6618 };
StagePoint D_800A6638 = { 0x2ED, 6, 3, 224, 192, 5, &D_800A6628 };
StagePoints D_800A6648 = { 6, 4, &D_800A6638 };
StagePoint D_800A6650 = { 0x2EE, 6, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6660 = { 0x2EE, 6, 4, 0x130, 200, 1, &D_800A6650 };
StagePoint D_800A6670 = { 0x2ED, 6, 3, 0x350, 0x1F8, 5, &D_800A6660 };
StagePoints D_800A6680 = { 6, 5, &D_800A6670 };
StagePoint D_800A6688 = { 0x2EE, 6, 4, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6698 = { 0x2ED, 6, 7, 0x3A0, 128, 1, &D_800A6688 };
StagePoint D_800A66A8 = { 0x2EE, 6, 2, 224, 0x240, 5, &D_800A6698 };
StagePoints D_800A66B8 = { 6, 6, &D_800A66A8 };
StagePoint D_800A66C0 = { 0x2ED, 6, 8, 0x3A0, 128, 1, NULL };
StagePoint D_800A66D0 = { 0x2EE, 6, 6, 0x130, 200, 1, &D_800A66C0 };
StagePoint D_800A66E0 = { 0x2ED, 6, 6, 0x350, 0x1F8, 5, &D_800A66D0 };
StagePoints D_800A66F0 = { 6, 7, &D_800A66E0 };
StagePoint D_800A66F8 = { 0x2EE, 6, 7, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6708 = { 0x2EE, 6, 8, 0x130, 200, 1, &D_800A66F8 };
StagePoint D_800A6718 = { 0x2ED, 6, 7, 224, 192, 5, &D_800A6708 };
StagePoints D_800A6728 = { 6, 8, &D_800A6718 };
StagePoints *placePoints[] = {
    &D_800A6108, &D_800A6140, &D_800A6178, &D_800A61B0,
    &D_800A61E8, &D_800A6220, &D_800A6258, &D_800A6290,
    &D_800A62C8, &D_800A6300, &D_800A6338, &D_800A6370,
    &D_800A63A8, &D_800A63E0, &D_800A6418, &D_800A6450,
    &D_800A6488, &D_800A64C0, &D_800A64F8, &D_800A6530,
    &D_800A6568, &D_800A65A0, &D_800A65D8, &D_800A6610,
    &D_800A6648, &D_800A6680, &D_800A66B8, &D_800A66F0,
    &D_800A6728, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x16E, 0x170, 0xB8, 0x70, 0x140, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x140, 0xB8, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FF },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x152, 0x140, 0x48, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x150, 0x1FE },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x160, 0x1FE },
    { 0x140, 0x100, 0x160, 0x140, 0x80, 0x40, 0x170, 0x1FE },
};
u16 D_800A6888[] = { 0x276, 1, 0x848B, 1, 0xFFFF };
u16 D_800A6894[] = { 0x275, 1, 0x847E, 1, 0xFFFF };
u16 D_800A68A0[] = { 0x274, 1, 0x8497, 1, 0xFFFF };
u16 D_800A68AC[] = { 0x279, 1, 0x8029, 1, 0xFFFF };
u16 D_800A68B8[] = { 0, 0, 0xFFFF };
u16 D_800A68C0[] = { 0, 1, 0xFFFF };
u16 D_800A68C8[] = { 0, 1, 0xFFFF };
u16 D_800A68D0[] = { 0x7400, 1, 0xA0E, 1, 0xFFFF };
u16 D_800A68DC[] = { 0, 0, 0xFFFF };
u16 D_800A68E4[] = { 0, 1, 0xFFFF };
u16 D_800A68EC[] = { 0, 1, 0xFFFF };
u16 D_800A68F4[] = { 0x7401, 1, 0xA0F, 1, 0xFFFF };
u16 D_800A6900[] = { 0, 0, 0xFFFF };
u16 D_800A6908[] = { 0, 1, 0xFFFF };
u16 D_800A6910[] = { 0, 1, 0xFFFF };
u16 D_800A6918[] = { 0xA11, 1, 0x7402, 1, 0xFFFF };
u16 D_800A6924[] = { 0, 0, 0xFFFF };
u16 D_800A692C[] = { 0, 1, 0xFFFF };
u16 D_800A6934[] = { 0, 1, 0xFFFF };
u16 D_800A693C[] = { 0x7403, 1, 0xA12, 1, 0xFFFF };
FieldTalk D_800A6948[] = {
    { NULL, D_800A6888, 0xE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6960[] = {
    { NULL, D_800A6894, 0xD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6978[] = {
    { NULL, D_800A68A0, 0xC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6990[] = {
    { NULL, D_800A68AC, 0x11 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69A8[] = {
    { D_800A68B8, D_800A68C0, 0xF1 },
    { D_800A68C8, D_800A68D0, 0xF2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69CC[] = {
    { D_800A68DC, D_800A68E4, 0xF3 },
    { D_800A68EC, D_800A68F4, 0xF4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A69F0[] = {
    { D_800A6900, D_800A6908, 0xF7 },
    { D_800A6910, D_800A6918, 0xF8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6A14[] = {
    { D_800A6924, D_800A692C, 0xF9 },
    { D_800A6934, D_800A693C, 0xFA },
    { NULL, NULL, 0 },
};
u16 D_800A6A38[] = { 0x7E04, 1, 0x7E22, 1, 0x276, 0, 0xFFFF };
u16 D_800A6A48[] = { 0x7E04, 1, 0x7E23, 1, 0x275, 0, 0xFFFF };
u16 D_800A6A58[] = { 0x7E05, 1, 0x7E20, 1, 0x274, 0, 0xFFFF };
u16 D_800A6A68[] = { 0x7E05, 1, 0x7E23, 1, 0x279, 0, 0x8029, 0, 0xFFFF };
u16 D_800A6A7C[] = { 0x7E00, 1, 0x7E1E, 1, 8, 0, 0xFFFF };
u16 D_800A6A8C[] = { 0x7E00, 1, 0x7E1F, 1, 8, 0, 0xFFFF };
u16 D_800A6A9C[] = { 0x7E00, 1, 0x7E20, 1, 8, 0, 0xFFFF };
u16 D_800A6AAC[] = { 0x7E00, 1, 0x7E21, 1, 8, 0, 0xFFFF };
u16 D_800A6ABC[] = { 0x7E00, 1, 0x7E22, 1, 8, 0, 0xFFFF };
u16 D_800A6ACC[] = { 0x7E01, 1, 8, 0, 0xFFFF };
u16 D_800A6AD8[] = { 0x7E04, 1, 8, 0, 0xFFFF };
u16 D_800A6AE4[] = { 0x7E05, 1, 8, 0, 0xFFFF };
u16 D_800A6AF0[] = { 0x7E00, 0, 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A6B00[] = { 0x7E00, 0, 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A6B10[] = { 0x7E00, 0, 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A6B20[] = { 0x7E00, 0, 0x7E21, 1, 9, 0, 0xFFFF };
u16 D_800A6B30[] = { 0x7E00, 0, 0x7E22, 1, 9, 0, 0xFFFF };
u16 D_800A6B40[] = { 0x7E00, 1, 0x7E1E, 1, 0xA0E, 0, 0xFFFF };
u16 D_800A6B50[] = { 0x7E00, 1, 0x7E1F, 1, 0xA0F, 0, 0xFFFF };
u16 D_800A6B60[] = { 0x7E00, 1, 0x7E21, 1, 0xA11, 0, 0xFFFF };
u16 D_800A6B70[] = { 0x7E00, 1, 0x7E22, 1, 0xA12, 0, 0xFFFF };
FieldActorEntry D_800A6B80 = { D_800A6A38, D_800A6948, 0x21, 4, 672, 216, 1 };
FieldActorEntry D_800A6B94 = { D_800A6A48, D_800A6960, 0x21, 4, 672, 216, 1 };
FieldActorEntry D_800A6BA8 = { D_800A6A58, D_800A6978, 0x21, 4, 672, 216, 1 };
FieldActorEntry D_800A6BBC = { D_800A6A68, D_800A6990, 0x21, 4, 672, 216, 1 };
FieldActorEntry D_800A6BD0 = { NULL, NULL, 0x146, 5, 0, 0, 0 };
FieldActorEntry D_800A6BE4 = { D_800A6A7C, NULL, 0x148, 6, 488, 164, 1 };
FieldActorEntry D_800A6BF8 = { D_800A6A8C, NULL, 0x148, 6, 488, 164, 1 };
FieldActorEntry D_800A6C0C = { D_800A6A9C, NULL, 0x148, 6, 784, 200, 1 };
FieldActorEntry D_800A6C20 = { D_800A6AAC, NULL, 0x148, 6, 784, 200, 1 };
FieldActorEntry D_800A6C34 = { D_800A6ABC, NULL, 0x148, 6, 488, 164, 1 };
FieldActorEntry D_800A6C48 = { D_800A6ACC, NULL, 0x148, 6, 768, 352, 1 };
FieldActorEntry D_800A6C5C = { D_800A6AD8, NULL, 0x148, 6, 488, 164, 1 };
FieldActorEntry D_800A6C70 = { D_800A6AE4, NULL, 0x148, 6, 456, 340, 1 };
FieldActorEntry D_800A6C84 = { D_800A6AF0, NULL, 0x15F, 7, 448, 384, 1 };
FieldActorEntry D_800A6C98 = { D_800A6B00, NULL, 0x15F, 7, 880, 408, 1 };
FieldActorEntry D_800A6CAC = { D_800A6B10, NULL, 0x15F, 7, 880, 152, 1 };
FieldActorEntry D_800A6CC0 = { D_800A6B20, NULL, 0x15F, 7, 784, 200, 1 };
FieldActorEntry D_800A6CD4 = { D_800A6B30, NULL, 0x15F, 7, 272, 168, 1 };
FieldActorEntry D_800A6CE8 = { D_800A6B40, D_800A69A8, 0x189, 8, 480, 256, 1 };
FieldActorEntry D_800A6CFC = { D_800A6B50, D_800A69CC, 0x18A, 9, 480, 256, 1 };
FieldActorEntry D_800A6D10 = { D_800A6B60, D_800A69F0, 0x18C, 0xA, 640, 416, 1 };
FieldActorEntry D_800A6D24 = { D_800A6B70, D_800A6A14, 0x18D, 0xB, 640, 416, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6B80,
    &D_800A6B94,
    &D_800A6BA8,
    &D_800A6BBC,
    &D_800A6BD0,
    &D_800A6BE4,
    &D_800A6BF8,
    &D_800A6C0C,
    &D_800A6C20,
    &D_800A6C34,
    &D_800A6C48,
    &D_800A6C5C,
    &D_800A6C70,
    &D_800A6C84,
    &D_800A6C98,
    &D_800A6CAC,
    &D_800A6CC0,
    &D_800A6CD4,
    &D_800A6CE8,
    &D_800A6CFC,
    &D_800A6D10,
    &D_800A6D24,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2ED, 0x3A0, 0x80, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2ED, 0x350, 0x1F8, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2ED, 0xE0, 0xC0, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A6E0C = { 38, 10, 0x60080000 };
Battle D_800A6E18 = { 56, 10, 0x60080000 };
Battle D_800A6E24 = { 107, 10, 0x60080000 };
Battle D_800A6E30 = { 155, 10, 0x60080000 };
Battle D_800A6E3C = { 120, 10, 0x60080000 };
Battle D_800A6E48 = { 181, 10, 0x60080000 };
Battle D_800A6E54 = { 142, 10, 0x60080000 };
Battle D_800A6E60 = { 143, 10, 0x60080000 };
BattleList D_800A6E6C = {
    3,
    { &D_800A6E0C, &D_800A6E18, &D_800A6E24, &D_800A6E30,
      &D_800A6E3C, &D_800A6E48, &D_800A6E54, &D_800A6E60 },
};
Battle D_800A6E90 = { 0, 0, 0x60040000 };
Battle D_800A6E9C = { 0, 0, 0x60040000 };
Battle D_800A6EA8 = { 0, 0, 0x60040000 };
Battle D_800A6EB4 = { 0, 0, 0x60040000 };
Battle D_800A6EC0 = { 0, 0, 0x60040000 };
Battle D_800A6ECC = { 0, 0, 0x60040000 };
Battle D_800A6ED8 = { 0, 0, 0x60040000 };
Battle D_800A6EE4 = { 0, 0, 0x60040000 };
BattleList D_800A6EF0 = {
    0,
    { &D_800A6E90, &D_800A6E9C, &D_800A6EA8, &D_800A6EB4,
      &D_800A6EC0, &D_800A6ECC, &D_800A6ED8, &D_800A6EE4 },
};
Battle D_800A6F14 = { 0, 0, 0x60040000 };
Battle D_800A6F20 = { 0, 0, 0x60040000 };
Battle D_800A6F2C = { 0, 0, 0x60040000 };
Battle D_800A6F38 = { 0, 0, 0x60040000 };
Battle D_800A6F44 = { 0, 0, 0x60040000 };
Battle D_800A6F50 = { 0, 0, 0x60040000 };
Battle D_800A6F5C = { 0, 0, 0x60040000 };
Battle D_800A6F68 = { 0, 0, 0x60040000 };
BattleList D_800A6F74 = {
    0,
    { &D_800A6F14, &D_800A6F20, &D_800A6F2C, &D_800A6F38,
      &D_800A6F44, &D_800A6F50, &D_800A6F5C, &D_800A6F68 },
};
Battle D_800A6F98 = { 316, 19, 0x60880000 };
Battle D_800A6FA4 = { 317, 19, 0x60880000 };
Battle D_800A6FB0 = { 319, 19, 0x60880000 };
Battle D_800A6FBC = { 321, 19, 0x60880000 };
Battle D_800A6FC8 = { 0, 0, 0x60040000 };
Battle D_800A6FD4 = { 0, 0, 0x60040000 };
Battle D_800A6FE0 = { 0, 0, 0x60040000 };
Battle D_800A6FEC = { 0, 0, 0x60040000 };
BattleList D_800A6FF8 = {
    0,
    { &D_800A6F98, &D_800A6FA4, &D_800A6FB0, &D_800A6FBC,
      &D_800A6FC8, &D_800A6FD4, &D_800A6FE0, &D_800A6FEC },
};
Battle D_800A701C = { 81, 10, 0x60080000 };
Battle D_800A7028 = { 81, 10, 0x60080000 };
Battle D_800A7034 = { 165, 10, 0x60080000 };
Battle D_800A7040 = { 165, 10, 0x60080000 };
Battle D_800A704C = { 166, 10, 0x60080000 };
Battle D_800A7058 = { 166, 10, 0x60080000 };
Battle D_800A7064 = { 169, 10, 0x60080000 };
Battle D_800A7070 = { 169, 10, 0x60080000 };
BattleList D_800A707C = {
    3,
    { &D_800A701C, &D_800A7028, &D_800A7034, &D_800A7040,
      &D_800A704C, &D_800A7058, &D_800A7064, &D_800A7070 },
};
Battle D_800A70A0 = { 0, 0, 0x60040000 };
Battle D_800A70AC = { 0, 0, 0x60040000 };
Battle D_800A70B8 = { 0, 0, 0x60040000 };
Battle D_800A70C4 = { 0, 0, 0x60040000 };
Battle D_800A70D0 = { 0, 0, 0x60040000 };
Battle D_800A70DC = { 0, 0, 0x60040000 };
Battle D_800A70E8 = { 0, 0, 0x60040000 };
Battle D_800A70F4 = { 0, 0, 0x60040000 };
BattleList D_800A7100 = {
    0,
    { &D_800A70A0, &D_800A70AC, &D_800A70B8, &D_800A70C4,
      &D_800A70D0, &D_800A70DC, &D_800A70E8, &D_800A70F4 },
};
Battle D_800A7124 = { 0, 0, 0x60040000 };
Battle D_800A7130 = { 0, 0, 0x60040000 };
Battle D_800A713C = { 0, 0, 0x60040000 };
Battle D_800A7148 = { 0, 0, 0x60040000 };
Battle D_800A7154 = { 0, 0, 0x60040000 };
Battle D_800A7160 = { 0, 0, 0x60040000 };
Battle D_800A716C = { 0, 0, 0x60040000 };
Battle D_800A7178 = { 0, 0, 0x60040000 };
BattleList D_800A7184 = {
    0,
    { &D_800A7124, &D_800A7130, &D_800A713C, &D_800A7148,
      &D_800A7154, &D_800A7160, &D_800A716C, &D_800A7178 },
};
Battle D_800A71A8 = { 0, 0, 0x60040000 };
Battle D_800A71B4 = { 0, 0, 0x60040000 };
Battle D_800A71C0 = { 0, 0, 0x60040000 };
Battle D_800A71CC = { 0, 0, 0x60040000 };
Battle D_800A71D8 = { 0, 0, 0x60040000 };
Battle D_800A71E4 = { 0, 0, 0x60040000 };
Battle D_800A71F0 = { 0, 0, 0x60040000 };
Battle D_800A71FC = { 0, 0, 0x60040000 };
BattleList D_800A7208 = {
    0,
    { &D_800A71A8, &D_800A71B4, &D_800A71C0, &D_800A71CC,
      &D_800A71D8, &D_800A71E4, &D_800A71F0, &D_800A71FC },
};
Battle D_800A722C = { 136, 10, 0x60080000 };
Battle D_800A7238 = { 136, 10, 0x60080000 };
Battle D_800A7244 = { 137, 10, 0x60080000 };
Battle D_800A7250 = { 137, 10, 0x60080000 };
Battle D_800A725C = { 183, 10, 0x60080000 };
Battle D_800A7268 = { 183, 10, 0x60080000 };
Battle D_800A7274 = { 118, 10, 0x60080000 };
Battle D_800A7280 = { 118, 10, 0x60080000 };
BattleList D_800A728C = {
    3,
    { &D_800A722C, &D_800A7238, &D_800A7244, &D_800A7250,
      &D_800A725C, &D_800A7268, &D_800A7274, &D_800A7280 },
};
Battle D_800A72B0 = { 0, 0, 0x60040000 };
Battle D_800A72BC = { 0, 0, 0x60040000 };
Battle D_800A72C8 = { 0, 0, 0x60040000 };
Battle D_800A72D4 = { 0, 0, 0x60040000 };
Battle D_800A72E0 = { 0, 0, 0x60040000 };
Battle D_800A72EC = { 0, 0, 0x60040000 };
Battle D_800A72F8 = { 0, 0, 0x60040000 };
Battle D_800A7304 = { 0, 0, 0x60040000 };
BattleList D_800A7310 = {
    0,
    { &D_800A72B0, &D_800A72BC, &D_800A72C8, &D_800A72D4,
      &D_800A72E0, &D_800A72EC, &D_800A72F8, &D_800A7304 },
};
Battle D_800A7334 = { 0, 0, 0x60040000 };
Battle D_800A7340 = { 0, 0, 0x60040000 };
Battle D_800A734C = { 0, 0, 0x60040000 };
Battle D_800A7358 = { 0, 0, 0x60040000 };
Battle D_800A7364 = { 0, 0, 0x60040000 };
Battle D_800A7370 = { 0, 0, 0x60040000 };
Battle D_800A737C = { 0, 0, 0x60040000 };
Battle D_800A7388 = { 0, 0, 0x60040000 };
BattleList D_800A7394 = {
    0,
    { &D_800A7334, &D_800A7340, &D_800A734C, &D_800A7358,
      &D_800A7364, &D_800A7370, &D_800A737C, &D_800A7388 },
};
Battle D_800A73B8 = { 0, 0, 0x60040000 };
Battle D_800A73C4 = { 0, 0, 0x60040000 };
Battle D_800A73D0 = { 0, 0, 0x60040000 };
Battle D_800A73DC = { 0, 0, 0x60040000 };
Battle D_800A73E8 = { 0, 0, 0x60040000 };
Battle D_800A73F4 = { 0, 0, 0x60040000 };
Battle D_800A7400 = { 0, 0, 0x60040000 };
Battle D_800A740C = { 0, 0, 0x60040000 };
BattleList D_800A7418 = {
    0,
    { &D_800A73B8, &D_800A73C4, &D_800A73D0, &D_800A73DC,
      &D_800A73E8, &D_800A73F4, &D_800A7400, &D_800A740C },
};
Battle D_800A743C = { 117, 10, 0x60080000 };
Battle D_800A7448 = { 117, 10, 0x60080000 };
Battle D_800A7454 = { 184, 10, 0x60080000 };
Battle D_800A7460 = { 184, 10, 0x60080000 };
Battle D_800A746C = { 187, 10, 0x60080000 };
Battle D_800A7478 = { 187, 10, 0x60080000 };
Battle D_800A7484 = { 187, 10, 0x60080000 };
Battle D_800A7490 = { 187, 10, 0x60080000 };
BattleList D_800A749C = {
    3,
    { &D_800A743C, &D_800A7448, &D_800A7454, &D_800A7460,
      &D_800A746C, &D_800A7478, &D_800A7484, &D_800A7490 },
};
Battle D_800A74C0 = { 0, 0, 0x60040000 };
Battle D_800A74CC = { 0, 0, 0x60040000 };
Battle D_800A74D8 = { 0, 0, 0x60040000 };
Battle D_800A74E4 = { 0, 0, 0x60040000 };
Battle D_800A74F0 = { 0, 0, 0x60040000 };
Battle D_800A74FC = { 0, 0, 0x60040000 };
Battle D_800A7508 = { 0, 0, 0x60040000 };
Battle D_800A7514 = { 0, 0, 0x60040000 };
BattleList D_800A7520 = {
    0,
    { &D_800A74C0, &D_800A74CC, &D_800A74D8, &D_800A74E4,
      &D_800A74F0, &D_800A74FC, &D_800A7508, &D_800A7514 },
};
Battle D_800A7544 = { 0, 0, 0x60040000 };
Battle D_800A7550 = { 0, 0, 0x60040000 };
Battle D_800A755C = { 0, 0, 0x60040000 };
Battle D_800A7568 = { 0, 0, 0x60040000 };
Battle D_800A7574 = { 0, 0, 0x60040000 };
Battle D_800A7580 = { 0, 0, 0x60040000 };
Battle D_800A758C = { 0, 0, 0x60040000 };
Battle D_800A7598 = { 0, 0, 0x60040000 };
BattleList D_800A75A4 = {
    0,
    { &D_800A7544, &D_800A7550, &D_800A755C, &D_800A7568,
      &D_800A7574, &D_800A7580, &D_800A758C, &D_800A7598 },
};
Battle D_800A75C8 = { 0, 0, 0x60040000 };
Battle D_800A75D4 = { 0, 0, 0x60040000 };
Battle D_800A75E0 = { 0, 0, 0x60040000 };
Battle D_800A75EC = { 0, 0, 0x60040000 };
Battle D_800A75F8 = { 0, 0, 0x60040000 };
Battle D_800A7604 = { 0, 0, 0x60040000 };
Battle D_800A7610 = { 0, 0, 0x60040000 };
Battle D_800A761C = { 0, 0, 0x60040000 };
BattleList D_800A7628 = {
    0,
    { &D_800A75C8, &D_800A75D4, &D_800A75E0, &D_800A75EC,
      &D_800A75F8, &D_800A7604, &D_800A7610, &D_800A761C },
};
Battle D_800A764C = { 74, 10, 0x60080000 };
Battle D_800A7658 = { 77, 10, 0x60080000 };
Battle D_800A7664 = { 78, 10, 0x60080000 };
Battle D_800A7670 = { 79, 10, 0x60080000 };
Battle D_800A767C = { 80, 10, 0x60080000 };
Battle D_800A7688 = { 75, 10, 0x60080000 };
Battle D_800A7694 = { 76, 10, 0x60080000 };
Battle D_800A76A0 = { 89, 10, 0x60080000 };
BattleList D_800A76AC = {
    3,
    { &D_800A764C, &D_800A7658, &D_800A7664, &D_800A7670,
      &D_800A767C, &D_800A7688, &D_800A7694, &D_800A76A0 },
};
Battle D_800A76D0 = { 0, 0, 0x60040000 };
Battle D_800A76DC = { 0, 0, 0x60040000 };
Battle D_800A76E8 = { 0, 0, 0x60040000 };
Battle D_800A76F4 = { 0, 0, 0x60040000 };
Battle D_800A7700 = { 0, 0, 0x60040000 };
Battle D_800A770C = { 0, 0, 0x60040000 };
Battle D_800A7718 = { 0, 0, 0x60040000 };
Battle D_800A7724 = { 0, 0, 0x60040000 };
BattleList D_800A7730 = {
    0,
    { &D_800A76D0, &D_800A76DC, &D_800A76E8, &D_800A76F4,
      &D_800A7700, &D_800A770C, &D_800A7718, &D_800A7724 },
};
Battle D_800A7754 = { 0, 0, 0x60040000 };
Battle D_800A7760 = { 0, 0, 0x60040000 };
Battle D_800A776C = { 0, 0, 0x60040000 };
Battle D_800A7778 = { 0, 0, 0x60040000 };
Battle D_800A7784 = { 0, 0, 0x60040000 };
Battle D_800A7790 = { 0, 0, 0x60040000 };
Battle D_800A779C = { 0, 0, 0x60040000 };
Battle D_800A77A8 = { 0, 0, 0x60040000 };
BattleList D_800A77B4 = {
    0,
    { &D_800A7754, &D_800A7760, &D_800A776C, &D_800A7778,
      &D_800A7784, &D_800A7790, &D_800A779C, &D_800A77A8 },
};
Battle D_800A77D8 = { 0, 0, 0x60040000 };
Battle D_800A77E4 = { 0, 0, 0x60040000 };
Battle D_800A77F0 = { 0, 0, 0x60040000 };
Battle D_800A77FC = { 0, 0, 0x60040000 };
Battle D_800A7808 = { 0, 0, 0x60040000 };
Battle D_800A7814 = { 0, 0, 0x60040000 };
Battle D_800A7820 = { 0, 0, 0x60040000 };
Battle D_800A782C = { 0, 0, 0x60040000 };
BattleList D_800A7838 = {
    0,
    { &D_800A77D8, &D_800A77E4, &D_800A77F0, &D_800A77FC,
      &D_800A7808, &D_800A7814, &D_800A7820, &D_800A782C },
};
Battle D_800A785C = { 110, 10, 0x60080000 };
Battle D_800A7868 = { 110, 10, 0x60080000 };
Battle D_800A7874 = { 71, 10, 0x60080000 };
Battle D_800A7880 = { 71, 10, 0x60080000 };
Battle D_800A788C = { 121, 10, 0x60080000 };
Battle D_800A7898 = { 121, 10, 0x60080000 };
Battle D_800A78A4 = { 182, 10, 0x60080000 };
Battle D_800A78B0 = { 182, 10, 0x60080000 };
BattleList D_800A78BC = {
    3,
    { &D_800A785C, &D_800A7868, &D_800A7874, &D_800A7880,
      &D_800A788C, &D_800A7898, &D_800A78A4, &D_800A78B0 },
};
Battle D_800A78E0 = { 0, 0, 0x60040000 };
Battle D_800A78EC = { 0, 0, 0x60040000 };
Battle D_800A78F8 = { 0, 0, 0x60040000 };
Battle D_800A7904 = { 0, 0, 0x60040000 };
Battle D_800A7910 = { 0, 0, 0x60040000 };
Battle D_800A791C = { 0, 0, 0x60040000 };
Battle D_800A7928 = { 0, 0, 0x60040000 };
Battle D_800A7934 = { 0, 0, 0x60040000 };
BattleList D_800A7940 = {
    0,
    { &D_800A78E0, &D_800A78EC, &D_800A78F8, &D_800A7904,
      &D_800A7910, &D_800A791C, &D_800A7928, &D_800A7934 },
};
Battle D_800A7964 = { 0, 0, 0x60040000 };
Battle D_800A7970 = { 0, 0, 0x60040000 };
Battle D_800A797C = { 0, 0, 0x60040000 };
Battle D_800A7988 = { 0, 0, 0x60040000 };
Battle D_800A7994 = { 0, 0, 0x60040000 };
Battle D_800A79A0 = { 0, 0, 0x60040000 };
Battle D_800A79AC = { 0, 0, 0x60040000 };
Battle D_800A79B8 = { 0, 0, 0x60040000 };
BattleList D_800A79C4 = {
    0,
    { &D_800A7964, &D_800A7970, &D_800A797C, &D_800A7988,
      &D_800A7994, &D_800A79A0, &D_800A79AC, &D_800A79B8 },
};
Battle D_800A79E8 = { 0, 0, 0x60040000 };
Battle D_800A79F4 = { 0, 0, 0x60040000 };
Battle D_800A7A00 = { 0, 0, 0x60040000 };
Battle D_800A7A0C = { 0, 0, 0x60040000 };
Battle D_800A7A18 = { 0, 0, 0x60040000 };
Battle D_800A7A24 = { 0, 0, 0x60040000 };
Battle D_800A7A30 = { 0, 0, 0x60040000 };
Battle D_800A7A3C = { 0, 0, 0x60040000 };
BattleList D_800A7A48 = {
    0,
    { &D_800A79E8, &D_800A79F4, &D_800A7A00, &D_800A7A0C,
      &D_800A7A18, &D_800A7A24, &D_800A7A30, &D_800A7A3C },
};
FieldBattles stageBattles[] = {
    { 418, 1, 0, { &D_800A6E6C, &D_800A6EF0, &D_800A6F74, &D_800A6FF8 } },
    { 423, 2, 0, { &D_800A707C, &D_800A7100, &D_800A7184, &D_800A7208 } },
    { 429, 3, 0, { &D_800A728C, &D_800A7310, &D_800A7394, &D_800A7418 } },
    { 435, 4, 0, { &D_800A749C, &D_800A7520, &D_800A75A4, &D_800A7628 } },
    { 441, 5, 0, { &D_800A76AC, &D_800A7730, &D_800A77B4, &D_800A7838 } },
    { 447, 6, 0, { &D_800A78BC, &D_800A7940, &D_800A79C4, &D_800A7A48 } },
};
