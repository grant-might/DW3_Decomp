#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x698;
    D_800990B4.sheetEntry = 0x94B0004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x94A;
    D_800990B4.start = (Vec2){0x13B00, 0x21000};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1E;
    D_800990B4.music = 0x60780000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x94B0006);
    D_8009A70C.setFile(7, 0x94B0007);
    D_8009A70C.setFile(4, 0x94B0005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60DC;
extern StagePoint D_800A60EC;
extern StagePoint D_800A60FC;
extern StagePoint D_800A6114;
extern StagePoint D_800A6124;
extern StagePoint D_800A6134;
extern StagePoint D_800A614C;
extern StagePoint D_800A615C;
extern StagePoint D_800A616C;
extern StagePoint D_800A6184;
extern StagePoint D_800A6194;
extern StagePoint D_800A61A4;
extern StagePoint D_800A61BC;
extern StagePoint D_800A61CC;
extern StagePoint D_800A61DC;
extern StagePoint D_800A61F4;
extern StagePoint D_800A6204;
extern StagePoint D_800A6214;
extern StagePoint D_800A622C;
extern StagePoint D_800A623C;
extern StagePoint D_800A624C;
extern StagePoint D_800A6264;
extern StagePoint D_800A6274;
extern StagePoint D_800A6284;
extern StagePoint D_800A629C;
extern StagePoint D_800A62AC;
extern StagePoint D_800A62BC;
extern StagePoint D_800A62D4;
extern StagePoint D_800A62E4;
extern StagePoint D_800A62F4;
extern StagePoint D_800A630C;
extern StagePoint D_800A631C;
extern StagePoint D_800A632C;
extern StagePoint D_800A6344;
extern StagePoint D_800A6354;
extern StagePoint D_800A6364;
extern StagePoint D_800A637C;
extern StagePoint D_800A638C;
extern StagePoint D_800A639C;
extern StagePoint D_800A63B4;
extern StagePoint D_800A63C4;
extern StagePoint D_800A63D4;
extern StagePoint D_800A63EC;
extern StagePoint D_800A63FC;
extern StagePoint D_800A640C;
extern StagePoint D_800A6424;
extern StagePoint D_800A6434;
extern StagePoint D_800A6444;
extern StagePoint D_800A645C;
extern StagePoint D_800A646C;
extern StagePoint D_800A647C;
extern StagePoint D_800A6494;
extern StagePoint D_800A64A4;
extern StagePoint D_800A64B4;
extern StagePoint D_800A64CC;
extern StagePoint D_800A64DC;
extern StagePoint D_800A64EC;
extern StagePoint D_800A6504;
extern StagePoint D_800A6514;
extern StagePoint D_800A6524;
extern StagePoint D_800A653C;
extern StagePoint D_800A654C;
extern StagePoint D_800A655C;
extern StagePoint D_800A6574;
extern StagePoint D_800A6584;
extern StagePoint D_800A6594;
extern StagePoint D_800A65AC;
extern StagePoint D_800A65BC;
extern StagePoint D_800A65CC;
extern StagePoint D_800A65E4;
extern StagePoint D_800A65F4;
extern StagePoint D_800A6604;
extern StagePoint D_800A661C;
extern StagePoint D_800A662C;
extern StagePoint D_800A663C;
extern StagePoint D_800A6654;
extern StagePoint D_800A6664;
extern StagePoint D_800A6674;
extern StagePoint D_800A668C;
extern StagePoint D_800A669C;
extern StagePoint D_800A66AC;
extern StagePoint D_800A66C4;
extern StagePoint D_800A66D4;
extern StagePoint D_800A66E4;
extern StagePoint D_800A66FC;
extern StagePoint D_800A670C;
extern StagePoint D_800A671C;
extern StagePoint D_800A6734;
extern StagePoint D_800A6744;
extern StagePoint D_800A6754;
extern StagePoint D_800A676C;
extern StagePoint D_800A677C;
extern StagePoint D_800A678C;
extern StagePoint D_800A67A4;
extern StagePoint D_800A67B4;
extern StagePoint D_800A67C4;
extern StagePoint D_800A67DC;
extern StagePoint D_800A67EC;
extern StagePoint D_800A67FC;
extern StagePoint D_800A6814;
extern StagePoint D_800A6824;
extern StagePoint D_800A6834;
extern StagePoint D_800A684C;
extern StagePoint D_800A685C;
extern StagePoint D_800A686C;
extern StagePoints D_800A610C;
extern StagePoints D_800A6144;
extern StagePoints D_800A617C;
extern StagePoints D_800A61B4;
extern StagePoints D_800A61EC;
extern StagePoints D_800A6224;
extern StagePoints D_800A625C;
extern StagePoints D_800A6294;
extern StagePoints D_800A62CC;
extern StagePoints D_800A6304;
extern StagePoints D_800A633C;
extern StagePoints D_800A6374;
extern StagePoints D_800A63AC;
extern StagePoints D_800A63E4;
extern StagePoints D_800A641C;
extern StagePoints D_800A6454;
extern StagePoints D_800A648C;
extern StagePoints D_800A64C4;
extern StagePoints D_800A64FC;
extern StagePoints D_800A6534;
extern StagePoints D_800A656C;
extern StagePoints D_800A65A4;
extern StagePoints D_800A65DC;
extern StagePoints D_800A6614;
extern StagePoints D_800A664C;
extern StagePoints D_800A6684;
extern StagePoints D_800A66BC;
extern StagePoints D_800A66F4;
extern StagePoints D_800A672C;
extern StagePoints D_800A6764;
extern StagePoints D_800A679C;
extern StagePoints D_800A67D4;
extern StagePoints D_800A680C;
extern StagePoints D_800A6844;
extern StagePoints D_800A687C;
extern u16 D_800A6A04[];
extern u16 D_800A6A0C[];
extern u16 D_800A6A18[];
extern u16 D_800A6A20[];
extern u16 D_800A6A30[];
extern u16 D_800A6A40[];
extern u16 D_800A6A50[];
extern u16 D_800A6A58[];
extern u16 D_800A6A64[];
extern u16 D_800A6A6C[];
extern u16 D_800A6A7C[];
extern u16 D_800A6A8C[];
extern u16 D_800A6A9C[];
extern u16 D_800A6AA4[];
extern u16 D_800A6AB0[];
extern u16 D_800A6AB8[];
extern u16 D_800A6AC8[];
extern u16 D_800A6AD8[];
extern u16 D_800A6AE8[];
extern u16 D_800A6AF0[];
extern u16 D_800A6AFC[];
extern u16 D_800A6B04[];
extern u16 D_800A6B14[];
extern u16 D_800A6B24[];
extern u16 D_800A6B34[];
extern u16 D_800A6B3C[];
extern u16 D_800A6B48[];
extern u16 D_800A6B50[];
extern u16 D_800A6B60[];
extern u16 D_800A6B70[];
extern u16 D_800A6B80[];
extern u16 D_800A6B88[];
extern u16 D_800A6B94[];
extern u16 D_800A6B9C[];
extern u16 D_800A6BAC[];
extern u16 D_800A6BBC[];
extern u16 D_800A6BCC[];
extern u16 D_800A6BD4[];
extern u16 D_800A6BE0[];
extern u16 D_800A6BE8[];
extern u16 D_800A6BF8[];
extern u16 D_800A6C08[];
extern u16 D_800A6DBC[];
extern FieldTalk D_800A6C18[];
extern u16 D_800A6DD8[];
extern FieldTalk D_800A6C54[];
extern u16 D_800A6DF4[];
extern FieldTalk D_800A6C90[];
extern u16 D_800A6E10[];
extern FieldTalk D_800A6CCC[];
extern u16 D_800A6E2C[];
extern FieldTalk D_800A6D08[];
extern u16 D_800A6E48[];
extern FieldTalk D_800A6D44[];
extern u16 D_800A6E64[];
extern FieldTalk D_800A6D80[];
extern u16 D_800A6E80[];
extern u16 D_800A6E8C[];
extern u16 D_800A6E98[];
extern u16 D_800A6EA4[];
extern u16 D_800A6EB0[];
extern u16 D_800A6EBC[];
extern u16 D_800A6EC8[];
extern u16 D_800A6ED8[];
extern u16 D_800A6EE8[];
extern u16 D_800A6EF8[];
extern u16 D_800A6F08[];
extern u16 D_800A6F18[];
extern u16 D_800A6F28[];
extern u16 D_800A6F38[];
extern FieldActorEntry D_800A6F48;
extern FieldActorEntry D_800A6F5C;
extern FieldActorEntry D_800A6F70;
extern FieldActorEntry D_800A6F84;
extern FieldActorEntry D_800A6F98;
extern FieldActorEntry D_800A6FAC;
extern FieldActorEntry D_800A6FC0;
extern FieldActorEntry D_800A6FD4;
extern FieldActorEntry D_800A6FE8;
extern FieldActorEntry D_800A6FFC;
extern FieldActorEntry D_800A7010;
extern FieldActorEntry D_800A7024;
extern FieldActorEntry D_800A7038;
extern FieldActorEntry D_800A704C;
extern FieldActorEntry D_800A7060;
extern FieldActorEntry D_800A7074;
extern FieldActorEntry D_800A7088;
extern FieldActorEntry D_800A709C;
extern FieldActorEntry D_800A70B0;
extern FieldActorEntry D_800A70C4;
extern FieldActorEntry D_800A70D8;
extern FieldActorEntry D_800A70EC;
extern Battle D_800A71D4;
extern Battle D_800A71E0;
extern Battle D_800A71EC;
extern Battle D_800A71F8;
extern Battle D_800A7204;
extern Battle D_800A7210;
extern Battle D_800A721C;
extern Battle D_800A7228;
extern Battle D_800A7258;
extern Battle D_800A7264;
extern Battle D_800A7270;
extern Battle D_800A727C;
extern Battle D_800A7288;
extern Battle D_800A7294;
extern Battle D_800A72A0;
extern Battle D_800A72AC;
extern Battle D_800A72DC;
extern Battle D_800A72E8;
extern Battle D_800A72F4;
extern Battle D_800A7300;
extern Battle D_800A730C;
extern Battle D_800A7318;
extern Battle D_800A7324;
extern Battle D_800A7330;
extern Battle D_800A7360;
extern Battle D_800A736C;
extern Battle D_800A7378;
extern Battle D_800A7384;
extern Battle D_800A7390;
extern Battle D_800A739C;
extern Battle D_800A73A8;
extern Battle D_800A73B4;
extern Battle D_800A73E4;
extern Battle D_800A73F0;
extern Battle D_800A73FC;
extern Battle D_800A7408;
extern Battle D_800A7414;
extern Battle D_800A7420;
extern Battle D_800A742C;
extern Battle D_800A7438;
extern Battle D_800A7468;
extern Battle D_800A7474;
extern Battle D_800A7480;
extern Battle D_800A748C;
extern Battle D_800A7498;
extern Battle D_800A74A4;
extern Battle D_800A74B0;
extern Battle D_800A74BC;
extern Battle D_800A74EC;
extern Battle D_800A74F8;
extern Battle D_800A7504;
extern Battle D_800A7510;
extern Battle D_800A751C;
extern Battle D_800A7528;
extern Battle D_800A7534;
extern Battle D_800A7540;
extern Battle D_800A7570;
extern Battle D_800A757C;
extern Battle D_800A7588;
extern Battle D_800A7594;
extern Battle D_800A75A0;
extern Battle D_800A75AC;
extern Battle D_800A75B8;
extern Battle D_800A75C4;
extern Battle D_800A75F4;
extern Battle D_800A7600;
extern Battle D_800A760C;
extern Battle D_800A7618;
extern Battle D_800A7624;
extern Battle D_800A7630;
extern Battle D_800A763C;
extern Battle D_800A7648;
extern Battle D_800A7678;
extern Battle D_800A7684;
extern Battle D_800A7690;
extern Battle D_800A769C;
extern Battle D_800A76A8;
extern Battle D_800A76B4;
extern Battle D_800A76C0;
extern Battle D_800A76CC;
extern Battle D_800A76FC;
extern Battle D_800A7708;
extern Battle D_800A7714;
extern Battle D_800A7720;
extern Battle D_800A772C;
extern Battle D_800A7738;
extern Battle D_800A7744;
extern Battle D_800A7750;
extern Battle D_800A7780;
extern Battle D_800A778C;
extern Battle D_800A7798;
extern Battle D_800A77A4;
extern Battle D_800A77B0;
extern Battle D_800A77BC;
extern Battle D_800A77C8;
extern Battle D_800A77D4;
extern Battle D_800A7804;
extern Battle D_800A7810;
extern Battle D_800A781C;
extern Battle D_800A7828;
extern Battle D_800A7834;
extern Battle D_800A7840;
extern Battle D_800A784C;
extern Battle D_800A7858;
extern Battle D_800A7888;
extern Battle D_800A7894;
extern Battle D_800A78A0;
extern Battle D_800A78AC;
extern Battle D_800A78B8;
extern Battle D_800A78C4;
extern Battle D_800A78D0;
extern Battle D_800A78DC;
extern Battle D_800A790C;
extern Battle D_800A7918;
extern Battle D_800A7924;
extern Battle D_800A7930;
extern Battle D_800A793C;
extern Battle D_800A7948;
extern Battle D_800A7954;
extern Battle D_800A7960;
extern Battle D_800A7990;
extern Battle D_800A799C;
extern Battle D_800A79A8;
extern Battle D_800A79B4;
extern Battle D_800A79C0;
extern Battle D_800A79CC;
extern Battle D_800A79D8;
extern Battle D_800A79E4;
extern Battle D_800A7A14;
extern Battle D_800A7A20;
extern Battle D_800A7A2C;
extern Battle D_800A7A38;
extern Battle D_800A7A44;
extern Battle D_800A7A50;
extern Battle D_800A7A5C;
extern Battle D_800A7A68;
extern Battle D_800A7A98;
extern Battle D_800A7AA4;
extern Battle D_800A7AB0;
extern Battle D_800A7ABC;
extern Battle D_800A7AC8;
extern Battle D_800A7AD4;
extern Battle D_800A7AE0;
extern Battle D_800A7AEC;
extern Battle D_800A7B1C;
extern Battle D_800A7B28;
extern Battle D_800A7B34;
extern Battle D_800A7B40;
extern Battle D_800A7B4C;
extern Battle D_800A7B58;
extern Battle D_800A7B64;
extern Battle D_800A7B70;
extern Battle D_800A7BA0;
extern Battle D_800A7BAC;
extern Battle D_800A7BB8;
extern Battle D_800A7BC4;
extern Battle D_800A7BD0;
extern Battle D_800A7BDC;
extern Battle D_800A7BE8;
extern Battle D_800A7BF4;
extern Battle D_800A7C24;
extern Battle D_800A7C30;
extern Battle D_800A7C3C;
extern Battle D_800A7C48;
extern Battle D_800A7C54;
extern Battle D_800A7C60;
extern Battle D_800A7C6C;
extern Battle D_800A7C78;
extern Battle D_800A7CA8;
extern Battle D_800A7CB4;
extern Battle D_800A7CC0;
extern Battle D_800A7CCC;
extern Battle D_800A7CD8;
extern Battle D_800A7CE4;
extern Battle D_800A7CF0;
extern Battle D_800A7CFC;
extern Battle D_800A7D2C;
extern Battle D_800A7D38;
extern Battle D_800A7D44;
extern Battle D_800A7D50;
extern Battle D_800A7D5C;
extern Battle D_800A7D68;
extern Battle D_800A7D74;
extern Battle D_800A7D80;
extern Battle D_800A7DB0;
extern Battle D_800A7DBC;
extern Battle D_800A7DC8;
extern Battle D_800A7DD4;
extern Battle D_800A7DE0;
extern Battle D_800A7DEC;
extern Battle D_800A7DF8;
extern Battle D_800A7E04;
extern BattleList D_800A7234;
extern BattleList D_800A72B8;
extern BattleList D_800A733C;
extern BattleList D_800A73C0;
extern BattleList D_800A7444;
extern BattleList D_800A74C8;
extern BattleList D_800A754C;
extern BattleList D_800A75D0;
extern BattleList D_800A7654;
extern BattleList D_800A76D8;
extern BattleList D_800A775C;
extern BattleList D_800A77E0;
extern BattleList D_800A7864;
extern BattleList D_800A78E8;
extern BattleList D_800A796C;
extern BattleList D_800A79F0;
extern BattleList D_800A7A74;
extern BattleList D_800A7AF8;
extern BattleList D_800A7B7C;
extern BattleList D_800A7C00;
extern BattleList D_800A7C84;
extern BattleList D_800A7D08;
extern BattleList D_800A7D8C;
extern BattleList D_800A7E10;

StagePoint D_800A60DC = { 0x2EB, 1, 1, 0x240, 160, 1, NULL };
StagePoint D_800A60EC = { 0x2ED, 1, 1, 0x350, 0x1F8, 5, &D_800A60DC };
StagePoint D_800A60FC = { 0x2E8, 1, 1, 176, 0x168, 5, &D_800A60EC };
StagePoints D_800A610C = { 1, 1, &D_800A60FC };
StagePoint D_800A6114 = { 0x2EB, 1, 4, 0x240, 160, 1, NULL };
StagePoint D_800A6124 = { 0x2EC, 1, 4, 240, 0x1D8, 5, &D_800A6114 };
StagePoint D_800A6134 = { 0x2EC, 1, 5, 240, 0x1D8, 5, &D_800A6124 };
StagePoints D_800A6144 = { 1, 2, &D_800A6134 };
StagePoint D_800A614C = { 0x2EC, 1, 6, 0x3B0, 120, 1, NULL };
StagePoint D_800A615C = { 0x2ED, 1, 4, 0x350, 0x1F8, 5, &D_800A614C };
StagePoint D_800A616C = { 0x2EA, 1, 3, 224, 0x200, 5, &D_800A615C };
StagePoints D_800A617C = { 1, 3, &D_800A616C };
StagePoint D_800A6184 = { 0x2EB, 1, 6, 0x240, 160, 1, NULL };
StagePoint D_800A6194 = { 0x2ED, 1, 5, 0x350, 0x1F8, 5, &D_800A6184 };
StagePoint D_800A61A4 = { 0x2EC, 1, 7, 240, 0x1D8, 5, &D_800A6194 };
StagePoints D_800A61B4 = { 1, 4, &D_800A61A4 };
StagePoint D_800A61BC = { 0x2ED, 2, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A61CC = { 0x2EA, 2, 1, 224, 0x200, 5, &D_800A61BC };
StagePoint D_800A61DC = { 0x2EA, 2, 2, 224, 0x200, 5, &D_800A61CC };
StagePoints D_800A61EC = { 2, 1, &D_800A61DC };
StagePoint D_800A61F4 = { 0x2ED, 2, 3, 0x3A0, 128, 1, NULL };
StagePoint D_800A6204 = { 0x2EA, 2, 4, 224, 0x200, 5, &D_800A61F4 };
StagePoint D_800A6214 = { 0x2ED, 2, 1, 224, 192, 5, &D_800A6204 };
StagePoints D_800A6224 = { 2, 2, &D_800A6214 };
StagePoint D_800A622C = { 0x2EC, 2, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A623C = { 0x2ED, 2, 1, 0x350, 0x1F8, 5, &D_800A622C };
StagePoint D_800A624C = { 0x2ED, 2, 2, 224, 192, 5, &D_800A623C };
StagePoints D_800A625C = { 2, 3, &D_800A624C };
StagePoint D_800A6264 = { 0x2EC, 2, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A6274 = { 0x2ED, 2, 2, 0x350, 0x1F8, 5, &D_800A6264 };
StagePoint D_800A6284 = { 0x2EA, 2, 5, 224, 0x200, 5, &D_800A6274 };
StagePoints D_800A6294 = { 2, 4, &D_800A6284 };
StagePoint D_800A629C = { 0x2EE, 2, 7, 0x130, 200, 1, NULL };
StagePoint D_800A62AC = { 0x2EA, 2, 6, 224, 0x200, 5, &D_800A629C };
StagePoint D_800A62BC = { 0x2ED, 2, 3, 224, 192, 5, &D_800A62AC };
StagePoints D_800A62CC = { 2, 5, &D_800A62BC };
StagePoint D_800A62D4 = { 0x2EE, 2, 8, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A62E4 = { 0x2EC, 2, 1, 240, 0x1D8, 5, &D_800A62D4 };
StagePoint D_800A62F4 = { 0x2EC, 2, 2, 240, 0x1D8, 5, &D_800A62E4 };
StagePoints D_800A6304 = { 2, 6, &D_800A62F4 };
StagePoint D_800A630C = { 0x2EE, 2, 9, 0x130, 200, 1, NULL };
StagePoint D_800A631C = { 0x2EE, 2, 5, 224, 0x240, 5, &D_800A630C };
StagePoint D_800A632C = { 0x2ED, 2, 4, 224, 192, 5, &D_800A631C };
StagePoints D_800A633C = { 2, 7, &D_800A632C };
StagePoint D_800A6344 = { 0x2EE, 2, 9, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6354 = { 0x2ED, 2, 4, 0x350, 0x1F8, 5, &D_800A6344 };
StagePoint D_800A6364 = { 0x2EE, 2, 6, 224, 0x240, 5, &D_800A6354 };
StagePoints D_800A6374 = { 2, 8, &D_800A6364 };
StagePoint D_800A637C = { 0x2E9, 2, 1, 0x240, 240, 1, NULL };
StagePoint D_800A638C = { 0x2EE, 2, 7, 224, 0x240, 5, &D_800A637C };
StagePoint D_800A639C = { 0x2EE, 2, 8, 224, 0x240, 5, &D_800A638C };
StagePoints D_800A63AC = { 2, 9, &D_800A639C };
StagePoint D_800A63B4 = { 0x2EC, 3, 5, 0x3B0, 120, 1, NULL };
StagePoint D_800A63C4 = { 0x2EC, 3, 2, 240, 0x1D8, 5, &D_800A63B4 };
StagePoint D_800A63D4 = { 0x2EC, 3, 3, 240, 0x1D8, 5, &D_800A63C4 };
StagePoints D_800A63E4 = { 3, 1, &D_800A63D4 };
StagePoint D_800A63EC = { 0x2EE, 3, 3, 0x130, 200, 1, NULL };
StagePoint D_800A63FC = { 0x2EC, 3, 4, 240, 0x1D8, 5, &D_800A63EC };
StagePoint D_800A640C = { 0x2ED, 3, 3, 224, 192, 5, &D_800A63FC };
StagePoints D_800A641C = { 3, 2, &D_800A640C };
StagePoint D_800A6424 = { 0x2EC, 3, 8, 0x3B0, 120, 1, NULL };
StagePoint D_800A6434 = { 0x2EE, 3, 2, 224, 0x240, 5, &D_800A6424 };
StagePoint D_800A6444 = { 0x2EC, 3, 6, 240, 0x1D8, 5, &D_800A6434 };
StagePoints D_800A6454 = { 3, 3, &D_800A6444 };
StagePoint D_800A645C = { 0x2EE, 3, 5, 0x130, 200, 1, NULL };
StagePoint D_800A646C = { 0x2EC, 3, 7, 240, 0x1D8, 5, &D_800A645C };
StagePoint D_800A647C = { 0x2EA, 3, 1, 224, 0x200, 5, &D_800A646C };
StagePoints D_800A648C = { 3, 4, &D_800A647C };
StagePoint D_800A6494 = { 0x2E9, 3, 1, 0x240, 240, 1, NULL };
StagePoint D_800A64A4 = { 0x2EE, 3, 4, 224, 0x240, 5, &D_800A6494 };
StagePoint D_800A64B4 = { 0x2EC, 3, 8, 240, 0x1D8, 5, &D_800A64A4 };
StagePoints D_800A64C4 = { 3, 5, &D_800A64B4 };
StagePoint D_800A64CC = { 0x2ED, 4, 3, 0x3A0, 128, 1, NULL };
StagePoint D_800A64DC = { 0x2EC, 4, 1, 240, 0x1D8, 5, &D_800A64CC };
StagePoint D_800A64EC = { 0x2EC, 4, 2, 240, 0x1D8, 5, &D_800A64DC };
StagePoints D_800A64FC = { 4, 1, &D_800A64EC };
StagePoint D_800A6504 = { 0x2EE, 4, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6514 = { 0x2EC, 4, 4, 240, 0x1D8, 5, &D_800A6504 };
StagePoint D_800A6524 = { 0x2EC, 4, 5, 240, 0x1D8, 5, &D_800A6514 };
StagePoints D_800A6534 = { 4, 2, &D_800A6524 };
StagePoint D_800A653C = { 0x2E9, 4, 1, 0x240, 240, 1, NULL };
StagePoint D_800A654C = { 0x2EC, 4, 7, 240, 0x1D8, 5, &D_800A653C };
StagePoint D_800A655C = { 0x2EE, 4, 2, 224, 0x240, 5, &D_800A654C };
StagePoints D_800A656C = { 4, 3, &D_800A655C };
StagePoint D_800A6574 = { 0x2EE, 5, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6584 = { 0x2ED, 5, 3, 0x350, 0x1F8, 5, &D_800A6574 };
StagePoint D_800A6594 = { 0x2EC, 5, 2, 240, 0x1D8, 5, &D_800A6584 };
StagePoints D_800A65A4 = { 5, 1, &D_800A6594 };
StagePoint D_800A65AC = { 0x2EC, 6, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A65BC = { 0x2ED, 5, 5, 0x350, 0x1F8, 5, &D_800A65AC };
StagePoint D_800A65CC = { 0x2EE, 5, 1, 224, 0x240, 5, &D_800A65BC };
StagePoints D_800A65DC = { 5, 2, &D_800A65CC };
StagePoint D_800A65E4 = { 0x2EC, 5, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A65F4 = { 0x2EA, 5, 1, 224, 0x200, 5, &D_800A65E4 };
StagePoint D_800A6604 = { 0x2ED, 5, 6, 224, 192, 5, &D_800A65F4 };
StagePoints D_800A6614 = { 5, 3, &D_800A6604 };
StagePoint D_800A661C = { 0x2EC, 5, 5, 0x3B0, 120, 1, NULL };
StagePoint D_800A662C = { 0x2EC, 5, 4, 240, 0x1D8, 5, &D_800A661C };
StagePoint D_800A663C = { 0x2EA, 5, 2, 224, 0x200, 5, &D_800A662C };
StagePoints D_800A664C = { 5, 4, &D_800A663C };
StagePoint D_800A6654 = { 0x2EC, 6, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A6664 = { 0x2EA, 5, 3, 224, 0x200, 5, &D_800A6654 };
StagePoint D_800A6674 = { 0x2EC, 5, 5, 240, 0x1D8, 5, &D_800A6664 };
StagePoints D_800A6684 = { 5, 5, &D_800A6674 };
StagePoint D_800A668C = { 0x2EE, 6, 2, 0x130, 200, 1, NULL };
StagePoint D_800A669C = { 0x2ED, 6, 1, 0x350, 0x1F8, 5, &D_800A668C };
StagePoint D_800A66AC = { 0x2ED, 6, 2, 224, 192, 5, &D_800A669C };
StagePoints D_800A66BC = { 6, 1, &D_800A66AC };
StagePoint D_800A66C4 = { 0x2ED, 6, 6, 0x3A0, 128, 1, NULL };
StagePoint D_800A66D4 = { 0x2EE, 6, 1, 224, 0x240, 5, &D_800A66C4 };
StagePoint D_800A66E4 = { 0x2EC, 6, 3, 240, 0x1D8, 5, &D_800A66D4 };
StagePoints D_800A66F4 = { 6, 2, &D_800A66E4 };
StagePoint D_800A66FC = { 0x2EE, 6, 5, 0x130, 200, 1, NULL };
StagePoint D_800A670C = { 0x2ED, 6, 4, 0x350, 0x1F8, 5, &D_800A66FC };
StagePoint D_800A671C = { 0x2ED, 6, 5, 224, 192, 5, &D_800A670C };
StagePoints D_800A672C = { 6, 3, &D_800A671C };
StagePoint D_800A6734 = { 0x2EE, 6, 5, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6744 = { 0x2ED, 6, 5, 0x350, 0x1F8, 5, &D_800A6734 };
StagePoint D_800A6754 = { 0x2ED, 6, 6, 224, 192, 5, &D_800A6744 };
StagePoints D_800A6764 = { 6, 4, &D_800A6754 };
StagePoint D_800A676C = { 0x2EE, 6, 7, 0x130, 200, 1, NULL };
StagePoint D_800A677C = { 0x2EE, 6, 3, 224, 0x240, 5, &D_800A676C };
StagePoint D_800A678C = { 0x2EE, 6, 4, 224, 0x240, 5, &D_800A677C };
StagePoints D_800A679C = { 6, 5, &D_800A678C };
StagePoint D_800A67A4 = { 0x2EE, 6, 8, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A67B4 = { 0x2ED, 6, 7, 0x350, 0x1F8, 5, &D_800A67A4 };
StagePoint D_800A67C4 = { 0x2EC, 6, 4, 240, 0x1D8, 5, &D_800A67B4 };
StagePoints D_800A67D4 = { 6, 6, &D_800A67C4 };
StagePoint D_800A67DC = { 0x2EE, 6, 9, 0x130, 200, 1, NULL };
StagePoint D_800A67EC = { 0x2EE, 6, 5, 224, 0x240, 5, &D_800A67DC };
StagePoint D_800A67FC = { 0x2ED, 6, 8, 224, 192, 5, &D_800A67EC };
StagePoints D_800A680C = { 6, 7, &D_800A67FC };
StagePoint D_800A6814 = { 0x2EE, 6, 9, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6824 = { 0x2ED, 6, 8, 0x350, 0x1F8, 5, &D_800A6814 };
StagePoint D_800A6834 = { 0x2EE, 6, 6, 224, 0x240, 5, &D_800A6824 };
StagePoints D_800A6844 = { 6, 8, &D_800A6834 };
StagePoint D_800A684C = { 0x2E9, 6, 1, 0x240, 240, 1, NULL };
StagePoint D_800A685C = { 0x2EE, 6, 7, 224, 0x240, 5, &D_800A684C };
StagePoint D_800A686C = { 0x2EE, 6, 8, 224, 0x240, 5, &D_800A685C };
StagePoints D_800A687C = { 6, 9, &D_800A686C };
StagePoints *placePoints[] = {
    &D_800A610C, &D_800A6144, &D_800A617C, &D_800A61B4,
    &D_800A61EC, &D_800A6224, &D_800A625C, &D_800A6294,
    &D_800A62CC, &D_800A6304, &D_800A633C, &D_800A6374,
    &D_800A63AC, &D_800A63E4, &D_800A641C, &D_800A6454,
    &D_800A648C, &D_800A64C4, &D_800A64FC, &D_800A6534,
    &D_800A656C, &D_800A65A4, &D_800A65DC, &D_800A6614,
    &D_800A664C, &D_800A6684, &D_800A66BC, &D_800A66F4,
    &D_800A672C, &D_800A6764, &D_800A679C, &D_800A67D4,
    &D_800A680C, &D_800A6844, &D_800A687C, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x15E, 0x140, 0x78, 0x40, 0x140, 0x1FF },
    { 0x140, 0x100, 0x14C, 0x140, 0x30, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x166, 0x140, 0x98, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x16E, 0x140, 0xB8, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x156, 0x140, 0x58, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x150, 0x1FE },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x170, 0x1FE },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x140, 0x1FD },
};
u16 D_800A6A04[] = { 0x868E, 1, 0xFFFF };
u16 D_800A6A0C[] = { 0x868E, 0, 2, 0, 0xFFFF };
u16 D_800A6A18[] = { 2, 1, 0xFFFF };
u16 D_800A6A20[] = { 0x868E, 0, 2, 1, 0x848A, 0, 0xFFFF };
u16 D_800A6A30[] = { 0x868E, 0, 2, 1, 0x848A, 1, 0xFFFF };
u16 D_800A6A40[] = { 0x868E, 1, 0x868D, 0, 0x848A, 0, 0xFFFF };
u16 D_800A6A50[] = { 0x868F, 1, 0xFFFF };
u16 D_800A6A58[] = { 0x868F, 0, 0, 0, 0xFFFF };
u16 D_800A6A64[] = { 0, 1, 0xFFFF };
u16 D_800A6A6C[] = { 0x868F, 0, 0, 1, 0x848B, 0, 0xFFFF };
u16 D_800A6A7C[] = { 0x868F, 0, 0, 1, 0x848B, 1, 0xFFFF };
u16 D_800A6A8C[] = { 0x868F, 1, 0x868E, 0, 0x848B, 0, 0xFFFF };
u16 D_800A6A9C[] = { 0x8690, 1, 0xFFFF };
u16 D_800A6AA4[] = { 0x8690, 0, 1, 0, 0xFFFF };
u16 D_800A6AB0[] = { 1, 1, 0xFFFF };
u16 D_800A6AB8[] = { 0x8690, 0, 1, 1, 0x848C, 0, 0xFFFF };
u16 D_800A6AC8[] = { 0x8690, 0, 1, 1, 0x848C, 1, 0xFFFF };
u16 D_800A6AD8[] = { 0x8690, 1, 0x868F, 0, 0x848C, 0, 0xFFFF };
u16 D_800A6AE8[] = { 0x8667, 1, 0xFFFF };
u16 D_800A6AF0[] = { 0x8667, 0, 0, 0, 0xFFFF };
u16 D_800A6AFC[] = { 0, 1, 0xFFFF };
u16 D_800A6B04[] = { 0x8667, 0, 0, 1, 0x8463, 0, 0xFFFF };
u16 D_800A6B14[] = { 0x8667, 0, 0, 1, 0x8463, 1, 0xFFFF };
u16 D_800A6B24[] = { 0x8667, 1, 0x8666, 0, 0x8463, 0, 0xFFFF };
u16 D_800A6B34[] = { 0x8681, 1, 0xFFFF };
u16 D_800A6B3C[] = { 0x8681, 0, 0, 0, 0xFFFF };
u16 D_800A6B48[] = { 0, 1, 0xFFFF };
u16 D_800A6B50[] = { 0x8681, 0, 0, 1, 0x847D, 0, 0xFFFF };
u16 D_800A6B60[] = { 0x8681, 0, 0, 1, 0x847D, 1, 0xFFFF };
u16 D_800A6B70[] = { 0x8681, 1, 0x8680, 0, 0x847D, 0, 0xFFFF };
u16 D_800A6B80[] = { 0x8677, 1, 0xFFFF };
u16 D_800A6B88[] = { 0x8677, 0, 0, 0, 0xFFFF };
u16 D_800A6B94[] = { 0, 1, 0xFFFF };
u16 D_800A6B9C[] = { 0x8677, 0, 0, 1, 0x8473, 0, 0xFFFF };
u16 D_800A6BAC[] = { 0x8677, 0, 0, 1, 0x8473, 1, 0xFFFF };
u16 D_800A6BBC[] = { 0x8677, 1, 0x8676, 0, 0x8473, 0, 0xFFFF };
u16 D_800A6BCC[] = { 0x8675, 1, 0xFFFF };
u16 D_800A6BD4[] = { 0x8675, 0, 0, 0, 0xFFFF };
u16 D_800A6BE0[] = { 0, 1, 0xFFFF };
u16 D_800A6BE8[] = { 0x8675, 0, 0, 1, 0x8471, 0, 0xFFFF };
u16 D_800A6BF8[] = { 0x8675, 0, 0, 1, 0x8471, 1, 0xFFFF };
u16 D_800A6C08[] = { 0x8471, 0, 0x8675, 1, 0x8674, 0, 0xFFFF };
FieldTalk D_800A6C18[] = {
    { D_800A6A04, NULL, 0xA5 },
    { D_800A6A0C, D_800A6A18, 0xA6 },
    { D_800A6A20, NULL, 0xA7 },
    { D_800A6A30, D_800A6A40, 0xA8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6C54[] = {
    { D_800A6A50, NULL, 0xB9 },
    { D_800A6A58, D_800A6A64, 0xBA },
    { D_800A6A6C, NULL, 0xBB },
    { D_800A6A7C, D_800A6A8C, 0xBC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6C90[] = {
    { D_800A6A9C, NULL, 0xCD },
    { D_800A6AA4, D_800A6AB0, 0xCE },
    { D_800A6AB8, NULL, 0xCF },
    { D_800A6AC8, D_800A6AD8, 0xD0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6CCC[] = {
    { D_800A6AE8, NULL, 0x95 },
    { D_800A6AF0, D_800A6AFC, 0x96 },
    { D_800A6B04, NULL, 0x97 },
    { D_800A6B14, D_800A6B24, 0x98 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6D08[] = {
    { D_800A6B34, NULL, 0x99 },
    { D_800A6B3C, D_800A6B48, 0x9A },
    { D_800A6B50, NULL, 0x9B },
    { D_800A6B60, D_800A6B70, 0x9C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6D44[] = {
    { D_800A6B80, NULL, 0xC5 },
    { D_800A6B88, D_800A6B94, 0xC6 },
    { D_800A6B9C, NULL, 0xC7 },
    { D_800A6BAC, D_800A6BBC, 0xC8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A6D80[] = {
    { D_800A6BCC, NULL, 0x9D },
    { D_800A6BD4, D_800A6BE0, 0x9E },
    { D_800A6BE8, NULL, 0x9F },
    { D_800A6BF8, D_800A6C08, 0xA0 },
    { NULL, NULL, 0 },
};
u16 D_800A6DBC[] = {
    0x7E01, 1, 0x7E23, 1, 0x7055, 1, 0x7095, 1,
    0x868E, 0, 0x868D, 1, 0xFFFF,
};
u16 D_800A6DD8[] = {
    0x7E01, 1, 0x7E21, 1, 0x7055, 1, 0x7095, 1,
    0x868E, 1, 0x868F, 0, 0xFFFF,
};
u16 D_800A6DF4[] = {
    0x7E01, 1, 0x7E22, 1, 0x7055, 1, 0x7095, 1,
    0x868F, 1, 0x8690, 0, 0xFFFF,
};
u16 D_800A6E10[] = {
    0x7E01, 1, 0x7E20, 1, 0x7055, 1, 0x7095, 1,
    0x8666, 1, 0x8667, 0, 0xFFFF,
};
u16 D_800A6E2C[] = {
    0x7E01, 1, 0x7E1E, 1, 0x7055, 1, 0x7095, 1,
    0x8680, 1, 0x8681, 0, 0xFFFF,
};
u16 D_800A6E48[] = {
    0x7E01, 1, 0x7E1F, 1, 0x7055, 1, 0x7095, 1,
    0x8676, 1, 0x8677, 0, 0xFFFF,
};
u16 D_800A6E64[] = {
    0x7E01, 1, 0x7E25, 1, 0x7055, 1, 0x7095, 1,
    0x8674, 1, 0x8675, 0, 0xFFFF,
};
u16 D_800A6E80[] = { 0x7E00, 1, 8, 0, 0xFFFF };
u16 D_800A6E8C[] = { 0x7E01, 1, 8, 0, 0xFFFF };
u16 D_800A6E98[] = { 0x7E02, 1, 8, 0, 0xFFFF };
u16 D_800A6EA4[] = { 0x7E03, 1, 8, 0, 0xFFFF };
u16 D_800A6EB0[] = { 0x7E04, 1, 8, 0, 0xFFFF };
u16 D_800A6EBC[] = { 0x7E05, 1, 8, 0, 0xFFFF };
u16 D_800A6EC8[] = { 0x7E00, 1, 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A6ED8[] = { 0x7E00, 1, 0x7E20, 0, 9, 0, 0xFFFF };
u16 D_800A6EE8[] = { 0x7E00, 0, 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A6EF8[] = { 0x7E00, 0, 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A6F08[] = { 0x7E00, 0, 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A6F18[] = { 0x7E00, 0, 0x7E21, 1, 9, 0, 0xFFFF };
u16 D_800A6F28[] = { 0x7E00, 1, 0x7E20, 1, 0xA, 0, 0xFFFF };
u16 D_800A6F38[] = { 0x7E00, 1, 0x7E20, 0, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A6F48 = { D_800A6DBC, D_800A6C18, 0x1C, 4, 624, 304, 1 };
FieldActorEntry D_800A6F5C = { D_800A6DD8, D_800A6C54, 0x1F, 5, 624, 304, 1 };
FieldActorEntry D_800A6F70 = { D_800A6DF4, D_800A6C90, 0x1F, 5, 624, 304, 1 };
FieldActorEntry D_800A6F84 = { D_800A6E10, D_800A6CCC, 0xA6, 6, 624, 304, 1 };
FieldActorEntry D_800A6F98 = { D_800A6E2C, D_800A6D08, 0xAB, 7, 624, 304, 1 };
FieldActorEntry D_800A6FAC = { D_800A6E48, D_800A6D44, 0xAD, 8, 624, 304, 1 };
FieldActorEntry D_800A6FC0 = { D_800A6E64, D_800A6D80, 0xAD, 8, 624, 304, 1 };
FieldActorEntry D_800A6FD4 = { NULL, NULL, 0x146, 9, 0, 0, 0 };
FieldActorEntry D_800A6FE8 = { D_800A6E80, NULL, 0x148, 0xA, 448, 528, 1 };
FieldActorEntry D_800A6FFC = { D_800A6E8C, NULL, 0x148, 0xA, 608, 512, 1 };
FieldActorEntry D_800A7010 = { D_800A6E98, NULL, 0x148, 0xA, 704, 416, 1 };
FieldActorEntry D_800A7024 = { D_800A6EA4, NULL, 0x148, 0xA, 720, 544, 1 };
FieldActorEntry D_800A7038 = { D_800A6EB0, NULL, 0x148, 0xA, 280, 300, 1 };
FieldActorEntry D_800A704C = { D_800A6EBC, NULL, 0x148, 0xA, 440, 324, 1 };
FieldActorEntry D_800A7060 = { D_800A6EC8, NULL, 0x15F, 0xB, 440, 324, 1 };
FieldActorEntry D_800A7074 = { D_800A6ED8, NULL, 0x15F, 0xB, 288, 544, 1 };
FieldActorEntry D_800A7088 = { D_800A6EE8, NULL, 0x15F, 0xB, 448, 528, 1 };
FieldActorEntry D_800A709C = { D_800A6EF8, NULL, 0x15F, 0xB, 864, 448, 1 };
FieldActorEntry D_800A70B0 = { D_800A6F08, NULL, 0x15F, 0xB, 288, 544, 1 };
FieldActorEntry D_800A70C4 = { D_800A6F18, NULL, 0x15F, 0xB, 256, 224, 1 };
FieldActorEntry D_800A70D8 = { D_800A6F28, NULL, 0x160, 0xC, 864, 448, 1 };
FieldActorEntry D_800A70EC = { D_800A6F38, NULL, 0x160, 0xC, 784, 488, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A6F48,
    &D_800A6F5C,
    &D_800A6F70,
    &D_800A6F84,
    &D_800A6F98,
    &D_800A6FAC,
    &D_800A6FC0,
    &D_800A6FD4,
    &D_800A6FE8,
    &D_800A6FFC,
    &D_800A7010,
    &D_800A7024,
    &D_800A7038,
    &D_800A704C,
    &D_800A7060,
    &D_800A7074,
    &D_800A7088,
    &D_800A709C,
    &D_800A70B0,
    &D_800A70C4,
    &D_800A70D8,
    &D_800A70EC,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2EE, 0x3A0, 0x1A0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2EE, 0x130, 0xC8, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2EE, 0xE0, 0x240, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A71D4 = { 38, 10, 0x60080000 };
Battle D_800A71E0 = { 56, 10, 0x60080000 };
Battle D_800A71EC = { 107, 10, 0x60080000 };
Battle D_800A71F8 = { 155, 10, 0x60080000 };
Battle D_800A7204 = { 120, 10, 0x60080000 };
Battle D_800A7210 = { 181, 10, 0x60080000 };
Battle D_800A721C = { 142, 10, 0x60080000 };
Battle D_800A7228 = { 143, 10, 0x60080000 };
BattleList D_800A7234 = {
    3,
    { &D_800A71D4, &D_800A71E0, &D_800A71EC, &D_800A71F8,
      &D_800A7204, &D_800A7210, &D_800A721C, &D_800A7228 },
};
Battle D_800A7258 = { 0, 0, 0x60040000 };
Battle D_800A7264 = { 0, 0, 0x60040000 };
Battle D_800A7270 = { 0, 0, 0x60040000 };
Battle D_800A727C = { 0, 0, 0x60040000 };
Battle D_800A7288 = { 0, 0, 0x60040000 };
Battle D_800A7294 = { 0, 0, 0x60040000 };
Battle D_800A72A0 = { 0, 0, 0x60040000 };
Battle D_800A72AC = { 0, 0, 0x60040000 };
BattleList D_800A72B8 = {
    0,
    { &D_800A7258, &D_800A7264, &D_800A7270, &D_800A727C,
      &D_800A7288, &D_800A7294, &D_800A72A0, &D_800A72AC },
};
Battle D_800A72DC = { 0, 0, 0x60040000 };
Battle D_800A72E8 = { 0, 0, 0x60040000 };
Battle D_800A72F4 = { 0, 0, 0x60040000 };
Battle D_800A7300 = { 0, 0, 0x60040000 };
Battle D_800A730C = { 0, 0, 0x60040000 };
Battle D_800A7318 = { 0, 0, 0x60040000 };
Battle D_800A7324 = { 0, 0, 0x60040000 };
Battle D_800A7330 = { 0, 0, 0x60040000 };
BattleList D_800A733C = {
    0,
    { &D_800A72DC, &D_800A72E8, &D_800A72F4, &D_800A7300,
      &D_800A730C, &D_800A7318, &D_800A7324, &D_800A7330 },
};
Battle D_800A7360 = { 0, 0, 0x60040000 };
Battle D_800A736C = { 0, 0, 0x60040000 };
Battle D_800A7378 = { 0, 0, 0x60040000 };
Battle D_800A7384 = { 0, 0, 0x60040000 };
Battle D_800A7390 = { 0, 0, 0x60040000 };
Battle D_800A739C = { 0, 0, 0x60040000 };
Battle D_800A73A8 = { 0, 0, 0x60040000 };
Battle D_800A73B4 = { 0, 0, 0x60040000 };
BattleList D_800A73C0 = {
    0,
    { &D_800A7360, &D_800A736C, &D_800A7378, &D_800A7384,
      &D_800A7390, &D_800A739C, &D_800A73A8, &D_800A73B4 },
};
Battle D_800A73E4 = { 82, 10, 0x60080000 };
Battle D_800A73F0 = { 82, 10, 0x60080000 };
Battle D_800A73FC = { 108, 10, 0x60080000 };
Battle D_800A7408 = { 108, 10, 0x60080000 };
Battle D_800A7414 = { 129, 10, 0x60080000 };
Battle D_800A7420 = { 129, 10, 0x60080000 };
Battle D_800A742C = { 91, 10, 0x60080000 };
Battle D_800A7438 = { 173, 10, 0x60080000 };
BattleList D_800A7444 = {
    3,
    { &D_800A73E4, &D_800A73F0, &D_800A73FC, &D_800A7408,
      &D_800A7414, &D_800A7420, &D_800A742C, &D_800A7438 },
};
Battle D_800A7468 = { 0, 0, 0x60040000 };
Battle D_800A7474 = { 0, 0, 0x60040000 };
Battle D_800A7480 = { 0, 0, 0x60040000 };
Battle D_800A748C = { 0, 0, 0x60040000 };
Battle D_800A7498 = { 0, 0, 0x60040000 };
Battle D_800A74A4 = { 0, 0, 0x60040000 };
Battle D_800A74B0 = { 0, 0, 0x60040000 };
Battle D_800A74BC = { 0, 0, 0x60040000 };
BattleList D_800A74C8 = {
    0,
    { &D_800A7468, &D_800A7474, &D_800A7480, &D_800A748C,
      &D_800A7498, &D_800A74A4, &D_800A74B0, &D_800A74BC },
};
Battle D_800A74EC = { 0, 0, 0x60040000 };
Battle D_800A74F8 = { 0, 0, 0x60040000 };
Battle D_800A7504 = { 0, 0, 0x60040000 };
Battle D_800A7510 = { 0, 0, 0x60040000 };
Battle D_800A751C = { 0, 0, 0x60040000 };
Battle D_800A7528 = { 0, 0, 0x60040000 };
Battle D_800A7534 = { 0, 0, 0x60040000 };
Battle D_800A7540 = { 0, 0, 0x60040000 };
BattleList D_800A754C = {
    0,
    { &D_800A74EC, &D_800A74F8, &D_800A7504, &D_800A7510,
      &D_800A751C, &D_800A7528, &D_800A7534, &D_800A7540 },
};
Battle D_800A7570 = { 0, 0, 0x60040000 };
Battle D_800A757C = { 0, 0, 0x60040000 };
Battle D_800A7588 = { 0, 0, 0x60040000 };
Battle D_800A7594 = { 0, 0, 0x60040000 };
Battle D_800A75A0 = { 0, 0, 0x60040000 };
Battle D_800A75AC = { 0, 0, 0x60040000 };
Battle D_800A75B8 = { 0, 0, 0x60040000 };
Battle D_800A75C4 = { 0, 0, 0x60040000 };
BattleList D_800A75D0 = {
    0,
    { &D_800A7570, &D_800A757C, &D_800A7588, &D_800A7594,
      &D_800A75A0, &D_800A75AC, &D_800A75B8, &D_800A75C4 },
};
Battle D_800A75F4 = { 111, 10, 0x60080000 };
Battle D_800A7600 = { 111, 10, 0x60080000 };
Battle D_800A760C = { 112, 10, 0x60080000 };
Battle D_800A7618 = { 112, 10, 0x60080000 };
Battle D_800A7624 = { 119, 10, 0x60080000 };
Battle D_800A7630 = { 119, 10, 0x60080000 };
Battle D_800A763C = { 168, 10, 0x60080000 };
Battle D_800A7648 = { 168, 10, 0x60080000 };
BattleList D_800A7654 = {
    3,
    { &D_800A75F4, &D_800A7600, &D_800A760C, &D_800A7618,
      &D_800A7624, &D_800A7630, &D_800A763C, &D_800A7648 },
};
Battle D_800A7678 = { 0, 0, 0x60040000 };
Battle D_800A7684 = { 0, 0, 0x60040000 };
Battle D_800A7690 = { 0, 0, 0x60040000 };
Battle D_800A769C = { 0, 0, 0x60040000 };
Battle D_800A76A8 = { 0, 0, 0x60040000 };
Battle D_800A76B4 = { 0, 0, 0x60040000 };
Battle D_800A76C0 = { 0, 0, 0x60040000 };
Battle D_800A76CC = { 0, 0, 0x60040000 };
BattleList D_800A76D8 = {
    0,
    { &D_800A7678, &D_800A7684, &D_800A7690, &D_800A769C,
      &D_800A76A8, &D_800A76B4, &D_800A76C0, &D_800A76CC },
};
Battle D_800A76FC = { 0, 0, 0x60040000 };
Battle D_800A7708 = { 0, 0, 0x60040000 };
Battle D_800A7714 = { 0, 0, 0x60040000 };
Battle D_800A7720 = { 0, 0, 0x60040000 };
Battle D_800A772C = { 0, 0, 0x60040000 };
Battle D_800A7738 = { 0, 0, 0x60040000 };
Battle D_800A7744 = { 0, 0, 0x60040000 };
Battle D_800A7750 = { 0, 0, 0x60040000 };
BattleList D_800A775C = {
    0,
    { &D_800A76FC, &D_800A7708, &D_800A7714, &D_800A7720,
      &D_800A772C, &D_800A7738, &D_800A7744, &D_800A7750 },
};
Battle D_800A7780 = { 0, 0, 0x60040000 };
Battle D_800A778C = { 0, 0, 0x60040000 };
Battle D_800A7798 = { 0, 0, 0x60040000 };
Battle D_800A77A4 = { 0, 0, 0x60040000 };
Battle D_800A77B0 = { 0, 0, 0x60040000 };
Battle D_800A77BC = { 0, 0, 0x60040000 };
Battle D_800A77C8 = { 0, 0, 0x60040000 };
Battle D_800A77D4 = { 0, 0, 0x60040000 };
BattleList D_800A77E0 = {
    0,
    { &D_800A7780, &D_800A778C, &D_800A7798, &D_800A77A4,
      &D_800A77B0, &D_800A77BC, &D_800A77C8, &D_800A77D4 },
};
Battle D_800A7804 = { 117, 10, 0x60080000 };
Battle D_800A7810 = { 117, 10, 0x60080000 };
Battle D_800A781C = { 184, 10, 0x60080000 };
Battle D_800A7828 = { 184, 10, 0x60080000 };
Battle D_800A7834 = { 187, 10, 0x60080000 };
Battle D_800A7840 = { 187, 10, 0x60080000 };
Battle D_800A784C = { 187, 10, 0x60080000 };
Battle D_800A7858 = { 187, 10, 0x60080000 };
BattleList D_800A7864 = {
    3,
    { &D_800A7804, &D_800A7810, &D_800A781C, &D_800A7828,
      &D_800A7834, &D_800A7840, &D_800A784C, &D_800A7858 },
};
Battle D_800A7888 = { 0, 0, 0x60040000 };
Battle D_800A7894 = { 0, 0, 0x60040000 };
Battle D_800A78A0 = { 0, 0, 0x60040000 };
Battle D_800A78AC = { 0, 0, 0x60040000 };
Battle D_800A78B8 = { 0, 0, 0x60040000 };
Battle D_800A78C4 = { 0, 0, 0x60040000 };
Battle D_800A78D0 = { 0, 0, 0x60040000 };
Battle D_800A78DC = { 0, 0, 0x60040000 };
BattleList D_800A78E8 = {
    0,
    { &D_800A7888, &D_800A7894, &D_800A78A0, &D_800A78AC,
      &D_800A78B8, &D_800A78C4, &D_800A78D0, &D_800A78DC },
};
Battle D_800A790C = { 0, 0, 0x60040000 };
Battle D_800A7918 = { 0, 0, 0x60040000 };
Battle D_800A7924 = { 0, 0, 0x60040000 };
Battle D_800A7930 = { 0, 0, 0x60040000 };
Battle D_800A793C = { 0, 0, 0x60040000 };
Battle D_800A7948 = { 0, 0, 0x60040000 };
Battle D_800A7954 = { 0, 0, 0x60040000 };
Battle D_800A7960 = { 0, 0, 0x60040000 };
BattleList D_800A796C = {
    0,
    { &D_800A790C, &D_800A7918, &D_800A7924, &D_800A7930,
      &D_800A793C, &D_800A7948, &D_800A7954, &D_800A7960 },
};
Battle D_800A7990 = { 0, 0, 0x60040000 };
Battle D_800A799C = { 0, 0, 0x60040000 };
Battle D_800A79A8 = { 0, 0, 0x60040000 };
Battle D_800A79B4 = { 0, 0, 0x60040000 };
Battle D_800A79C0 = { 0, 0, 0x60040000 };
Battle D_800A79CC = { 0, 0, 0x60040000 };
Battle D_800A79D8 = { 0, 0, 0x60040000 };
Battle D_800A79E4 = { 0, 0, 0x60040000 };
BattleList D_800A79F0 = {
    0,
    { &D_800A7990, &D_800A799C, &D_800A79A8, &D_800A79B4,
      &D_800A79C0, &D_800A79CC, &D_800A79D8, &D_800A79E4 },
};
Battle D_800A7A14 = { 171, 10, 0x60080000 };
Battle D_800A7A20 = { 171, 10, 0x60080000 };
Battle D_800A7A2C = { 171, 10, 0x60080000 };
Battle D_800A7A38 = { 172, 10, 0x60080000 };
Battle D_800A7A44 = { 172, 10, 0x60080000 };
Battle D_800A7A50 = { 87, 10, 0x60080000 };
Battle D_800A7A5C = { 87, 10, 0x60080000 };
Battle D_800A7A68 = { 87, 10, 0x60080000 };
BattleList D_800A7A74 = {
    3,
    { &D_800A7A14, &D_800A7A20, &D_800A7A2C, &D_800A7A38,
      &D_800A7A44, &D_800A7A50, &D_800A7A5C, &D_800A7A68 },
};
Battle D_800A7A98 = { 0, 0, 0x60040000 };
Battle D_800A7AA4 = { 0, 0, 0x60040000 };
Battle D_800A7AB0 = { 0, 0, 0x60040000 };
Battle D_800A7ABC = { 0, 0, 0x60040000 };
Battle D_800A7AC8 = { 0, 0, 0x60040000 };
Battle D_800A7AD4 = { 0, 0, 0x60040000 };
Battle D_800A7AE0 = { 0, 0, 0x60040000 };
Battle D_800A7AEC = { 0, 0, 0x60040000 };
BattleList D_800A7AF8 = {
    0,
    { &D_800A7A98, &D_800A7AA4, &D_800A7AB0, &D_800A7ABC,
      &D_800A7AC8, &D_800A7AD4, &D_800A7AE0, &D_800A7AEC },
};
Battle D_800A7B1C = { 0, 0, 0x60040000 };
Battle D_800A7B28 = { 0, 0, 0x60040000 };
Battle D_800A7B34 = { 0, 0, 0x60040000 };
Battle D_800A7B40 = { 0, 0, 0x60040000 };
Battle D_800A7B4C = { 0, 0, 0x60040000 };
Battle D_800A7B58 = { 0, 0, 0x60040000 };
Battle D_800A7B64 = { 0, 0, 0x60040000 };
Battle D_800A7B70 = { 0, 0, 0x60040000 };
BattleList D_800A7B7C = {
    0,
    { &D_800A7B1C, &D_800A7B28, &D_800A7B34, &D_800A7B40,
      &D_800A7B4C, &D_800A7B58, &D_800A7B64, &D_800A7B70 },
};
Battle D_800A7BA0 = { 0, 0, 0x60040000 };
Battle D_800A7BAC = { 0, 0, 0x60040000 };
Battle D_800A7BB8 = { 0, 0, 0x60040000 };
Battle D_800A7BC4 = { 0, 0, 0x60040000 };
Battle D_800A7BD0 = { 0, 0, 0x60040000 };
Battle D_800A7BDC = { 0, 0, 0x60040000 };
Battle D_800A7BE8 = { 0, 0, 0x60040000 };
Battle D_800A7BF4 = { 0, 0, 0x60040000 };
BattleList D_800A7C00 = {
    0,
    { &D_800A7BA0, &D_800A7BAC, &D_800A7BB8, &D_800A7BC4,
      &D_800A7BD0, &D_800A7BDC, &D_800A7BE8, &D_800A7BF4 },
};
Battle D_800A7C24 = { 73, 10, 0x60080000 };
Battle D_800A7C30 = { 73, 10, 0x60080000 };
Battle D_800A7C3C = { 86, 10, 0x60080000 };
Battle D_800A7C48 = { 86, 10, 0x60080000 };
Battle D_800A7C54 = { 85, 10, 0x60080000 };
Battle D_800A7C60 = { 170, 10, 0x60080000 };
Battle D_800A7C6C = { 92, 10, 0x60080000 };
Battle D_800A7C78 = { 174, 10, 0x60080000 };
BattleList D_800A7C84 = {
    3,
    { &D_800A7C24, &D_800A7C30, &D_800A7C3C, &D_800A7C48,
      &D_800A7C54, &D_800A7C60, &D_800A7C6C, &D_800A7C78 },
};
Battle D_800A7CA8 = { 0, 0, 0x60040000 };
Battle D_800A7CB4 = { 0, 0, 0x60040000 };
Battle D_800A7CC0 = { 0, 0, 0x60040000 };
Battle D_800A7CCC = { 0, 0, 0x60040000 };
Battle D_800A7CD8 = { 0, 0, 0x60040000 };
Battle D_800A7CE4 = { 0, 0, 0x60040000 };
Battle D_800A7CF0 = { 0, 0, 0x60040000 };
Battle D_800A7CFC = { 0, 0, 0x60040000 };
BattleList D_800A7D08 = {
    0,
    { &D_800A7CA8, &D_800A7CB4, &D_800A7CC0, &D_800A7CCC,
      &D_800A7CD8, &D_800A7CE4, &D_800A7CF0, &D_800A7CFC },
};
Battle D_800A7D2C = { 0, 0, 0x60040000 };
Battle D_800A7D38 = { 0, 0, 0x60040000 };
Battle D_800A7D44 = { 0, 0, 0x60040000 };
Battle D_800A7D50 = { 0, 0, 0x60040000 };
Battle D_800A7D5C = { 0, 0, 0x60040000 };
Battle D_800A7D68 = { 0, 0, 0x60040000 };
Battle D_800A7D74 = { 0, 0, 0x60040000 };
Battle D_800A7D80 = { 0, 0, 0x60040000 };
BattleList D_800A7D8C = {
    0,
    { &D_800A7D2C, &D_800A7D38, &D_800A7D44, &D_800A7D50,
      &D_800A7D5C, &D_800A7D68, &D_800A7D74, &D_800A7D80 },
};
Battle D_800A7DB0 = { 0, 0, 0x60040000 };
Battle D_800A7DBC = { 0, 0, 0x60040000 };
Battle D_800A7DC8 = { 0, 0, 0x60040000 };
Battle D_800A7DD4 = { 0, 0, 0x60040000 };
Battle D_800A7DE0 = { 0, 0, 0x60040000 };
Battle D_800A7DEC = { 0, 0, 0x60040000 };
Battle D_800A7DF8 = { 0, 0, 0x60040000 };
Battle D_800A7E04 = { 0, 0, 0x60040000 };
BattleList D_800A7E10 = {
    0,
    { &D_800A7DB0, &D_800A7DBC, &D_800A7DC8, &D_800A7DD4,
      &D_800A7DE0, &D_800A7DEC, &D_800A7DF8, &D_800A7E04 },
};
FieldBattles stageBattles[] = {
    { 419, 1, 0, { &D_800A7234, &D_800A72B8, &D_800A733C, &D_800A73C0 } },
    { 424, 2, 0, { &D_800A7444, &D_800A74C8, &D_800A754C, &D_800A75D0 } },
    { 430, 3, 0, { &D_800A7654, &D_800A76D8, &D_800A775C, &D_800A77E0 } },
    { 436, 4, 0, { &D_800A7864, &D_800A78E8, &D_800A796C, &D_800A79F0 } },
    { 442, 5, 0, { &D_800A7A74, &D_800A7AF8, &D_800A7B7C, &D_800A7C00 } },
    { 448, 6, 0, { &D_800A7C84, &D_800A7D08, &D_800A7D8C, &D_800A7E10 } },
};
