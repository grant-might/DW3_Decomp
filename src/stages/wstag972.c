#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

void setupStage(void) {
    D_800990B4.textFile = LANGUAGE + 0x104;
    D_800990B4.mapFile = 0x692;
    D_800990B4.sheetEntry = 0x9470004;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = 0x946;
    D_800990B4.start = (Vec2){0x37200, 0x1CE00};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1E;
    D_800990B4.music = 0x60780000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, 0x9470006);
    D_8009A70C.setFile(7, 0x9470007);
    D_8009A70C.setFile(4, 0x9470005);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A60DC;
extern StagePoint D_800A60EC;
extern StagePoint D_800A6104;
extern StagePoint D_800A6114;
extern StagePoint D_800A612C;
extern StagePoint D_800A613C;
extern StagePoint D_800A6154;
extern StagePoint D_800A6164;
extern StagePoint D_800A617C;
extern StagePoint D_800A618C;
extern StagePoint D_800A61A4;
extern StagePoint D_800A61B4;
extern StagePoint D_800A61CC;
extern StagePoint D_800A61DC;
extern StagePoint D_800A61F4;
extern StagePoint D_800A6204;
extern StagePoint D_800A621C;
extern StagePoint D_800A622C;
extern StagePoint D_800A6244;
extern StagePoint D_800A6254;
extern StagePoint D_800A626C;
extern StagePoint D_800A627C;
extern StagePoint D_800A6294;
extern StagePoint D_800A62A4;
extern StagePoint D_800A62BC;
extern StagePoint D_800A62CC;
extern StagePoint D_800A62E4;
extern StagePoint D_800A62F4;
extern StagePoint D_800A630C;
extern StagePoint D_800A631C;
extern StagePoint D_800A6334;
extern StagePoint D_800A6344;
extern StagePoint D_800A635C;
extern StagePoint D_800A636C;
extern StagePoint D_800A6384;
extern StagePoint D_800A6394;
extern StagePoint D_800A63AC;
extern StagePoint D_800A63BC;
extern StagePoint D_800A63D4;
extern StagePoint D_800A63E4;
extern StagePoint D_800A63FC;
extern StagePoint D_800A640C;
extern StagePoint D_800A6424;
extern StagePoint D_800A6434;
extern StagePoint D_800A644C;
extern StagePoint D_800A645C;
extern StagePoint D_800A6474;
extern StagePoint D_800A6484;
extern StagePoint D_800A649C;
extern StagePoint D_800A64AC;
extern StagePoint D_800A64C4;
extern StagePoint D_800A64D4;
extern StagePoint D_800A64EC;
extern StagePoint D_800A64FC;
extern StagePoint D_800A6514;
extern StagePoint D_800A6524;
extern StagePoint D_800A653C;
extern StagePoint D_800A654C;
extern StagePoint D_800A6564;
extern StagePoint D_800A6574;
extern StagePoint D_800A658C;
extern StagePoint D_800A659C;
extern StagePoint D_800A65B4;
extern StagePoint D_800A65C4;
extern StagePoint D_800A65DC;
extern StagePoint D_800A65EC;
extern StagePoint D_800A6604;
extern StagePoint D_800A6614;
extern StagePoints D_800A60FC;
extern StagePoints D_800A6124;
extern StagePoints D_800A614C;
extern StagePoints D_800A6174;
extern StagePoints D_800A619C;
extern StagePoints D_800A61C4;
extern StagePoints D_800A61EC;
extern StagePoints D_800A6214;
extern StagePoints D_800A623C;
extern StagePoints D_800A6264;
extern StagePoints D_800A628C;
extern StagePoints D_800A62B4;
extern StagePoints D_800A62DC;
extern StagePoints D_800A6304;
extern StagePoints D_800A632C;
extern StagePoints D_800A6354;
extern StagePoints D_800A637C;
extern StagePoints D_800A63A4;
extern StagePoints D_800A63CC;
extern StagePoints D_800A63F4;
extern StagePoints D_800A641C;
extern StagePoints D_800A6444;
extern StagePoints D_800A646C;
extern StagePoints D_800A6494;
extern StagePoints D_800A64BC;
extern StagePoints D_800A64E4;
extern StagePoints D_800A650C;
extern StagePoints D_800A6534;
extern StagePoints D_800A655C;
extern StagePoints D_800A6584;
extern StagePoints D_800A65AC;
extern StagePoints D_800A65D4;
extern StagePoints D_800A65FC;
extern StagePoints D_800A6624;
extern u16 D_800A67C8[];
extern u16 D_800A67D4[];
extern u16 D_800A67E0[];
extern u16 D_800A67EC[];
extern u16 D_800A67F4[];
extern u16 D_800A6800[];
extern u16 D_800A6808[];
extern u16 D_800A6818[];
extern u16 D_800A6820[];
extern u16 D_800A6834[];
extern u16 D_800A6840[];
extern u16 D_800A6858[];
extern u16 D_800A686C[];
extern u16 D_800A6884[];
extern u16 D_800A6894[];
extern u16 D_800A689C[];
extern u16 D_800A68A8[];
extern u16 D_800A68B0[];
extern u16 D_800A68C0[];
extern u16 D_800A68C8[];
extern u16 D_800A68DC[];
extern u16 D_800A68E8[];
extern u16 D_800A6900[];
extern u16 D_800A6914[];
extern u16 D_800A692C[];
extern u16 D_800A693C[];
extern u16 D_800A6944[];
extern u16 D_800A6950[];
extern u16 D_800A6958[];
extern u16 D_800A6968[];
extern u16 D_800A6970[];
extern u16 D_800A6984[];
extern u16 D_800A6990[];
extern u16 D_800A69A8[];
extern u16 D_800A69BC[];
extern u16 D_800A69D4[];
extern u16 D_800A69E4[];
extern u16 D_800A69EC[];
extern u16 D_800A69F8[];
extern u16 D_800A6A00[];
extern u16 D_800A6A10[];
extern u16 D_800A6A18[];
extern u16 D_800A6A2C[];
extern u16 D_800A6A38[];
extern u16 D_800A6A50[];
extern u16 D_800A6A64[];
extern u16 D_800A6A7C[];
extern u16 D_800A6A8C[];
extern u16 D_800A6A94[];
extern u16 D_800A6AA0[];
extern u16 D_800A6AA8[];
extern u16 D_800A6AB8[];
extern u16 D_800A6AC0[];
extern u16 D_800A6AD4[];
extern u16 D_800A6AE0[];
extern u16 D_800A6AF8[];
extern u16 D_800A6B0C[];
extern u16 D_800A6B24[];
extern u16 D_800A6B34[];
extern u16 D_800A6B3C[];
extern u16 D_800A6B48[];
extern u16 D_800A6B50[];
extern u16 D_800A6B60[];
extern u16 D_800A6B68[];
extern u16 D_800A6B7C[];
extern u16 D_800A6B88[];
extern u16 D_800A6BA0[];
extern u16 D_800A6BB4[];
extern u16 D_800A6BCC[];
extern u16 D_800A6BDC[];
extern u16 D_800A6BE4[];
extern u16 D_800A6BF0[];
extern u16 D_800A6BF8[];
extern u16 D_800A6C08[];
extern u16 D_800A6C10[];
extern u16 D_800A6C24[];
extern u16 D_800A6C30[];
extern u16 D_800A6C48[];
extern u16 D_800A6C5C[];
extern u16 D_800A6C74[];
extern u16 D_800A6C84[];
extern u16 D_800A6C8C[];
extern u16 D_800A6C98[];
extern u16 D_800A6CA0[];
extern u16 D_800A6CB0[];
extern u16 D_800A6CB8[];
extern u16 D_800A6CCC[];
extern u16 D_800A6CD8[];
extern u16 D_800A6CF0[];
extern u16 D_800A6D04[];
extern u16 D_800A6D1C[];
extern u16 D_800A6D2C[];
extern u16 D_800A6D34[];
extern u16 D_800A6D40[];
extern u16 D_800A6D48[];
extern u16 D_800A6D58[];
extern u16 D_800A6D60[];
extern u16 D_800A6D74[];
extern u16 D_800A6D80[];
extern u16 D_800A6D98[];
extern u16 D_800A6DAC[];
extern u16 D_800A6DC4[];
extern u16 D_800A6DD4[];
extern u16 D_800A6DDC[];
extern u16 D_800A6DE8[];
extern u16 D_800A6DF0[];
extern u16 D_800A6E00[];
extern u16 D_800A6E08[];
extern u16 D_800A6E1C[];
extern u16 D_800A6E28[];
extern u16 D_800A6E40[];
extern u16 D_800A6E54[];
extern u16 D_800A6E6C[];
extern u16 D_800A6E7C[];
extern u16 D_800A6E84[];
extern u16 D_800A6E90[];
extern u16 D_800A6E98[];
extern u16 D_800A6EA8[];
extern u16 D_800A6EB0[];
extern u16 D_800A6EC4[];
extern u16 D_800A6ED0[];
extern u16 D_800A6EE8[];
extern u16 D_800A6EFC[];
extern u16 D_800A6F14[];
extern u16 D_800A6F24[];
extern u16 D_800A6F2C[];
extern u16 D_800A6F38[];
extern u16 D_800A6F40[];
extern u16 D_800A6F50[];
extern u16 D_800A6F58[];
extern u16 D_800A6F6C[];
extern u16 D_800A6F78[];
extern u16 D_800A6F90[];
extern u16 D_800A6FA4[];
extern u16 D_800A6FBC[];
extern u16 D_800A6FCC[];
extern u16 D_800A6FD4[];
extern u16 D_800A6FE0[];
extern u16 D_800A6FE8[];
extern u16 D_800A6FF8[];
extern u16 D_800A7000[];
extern u16 D_800A7014[];
extern u16 D_800A7020[];
extern u16 D_800A7038[];
extern u16 D_800A704C[];
extern u16 D_800A7064[];
extern u16 D_800A7074[];
extern u16 D_800A707C[];
extern u16 D_800A7088[];
extern u16 D_800A7090[];
extern u16 D_800A70A0[];
extern u16 D_800A70A8[];
extern u16 D_800A70BC[];
extern u16 D_800A70C8[];
extern u16 D_800A70E0[];
extern u16 D_800A70F4[];
extern u16 D_800A710C[];
extern u16 D_800A711C[];
extern u16 D_800A7124[];
extern u16 D_800A7130[];
extern u16 D_800A7138[];
extern u16 D_800A7148[];
extern u16 D_800A7150[];
extern u16 D_800A7164[];
extern u16 D_800A7170[];
extern u16 D_800A7188[];
extern u16 D_800A719C[];
extern u16 D_800A71B4[];
extern u16 D_800A71C4[];
extern u16 D_800A71CC[];
extern u16 D_800A71D4[];
extern u16 D_800A71DC[];
extern u16 D_800A71E8[];
extern u16 D_800A71F0[];
extern u16 D_800A71F8[];
extern u16 D_800A7200[];
extern u16 D_800A7788[];
extern FieldTalk D_800A720C[];
extern u16 D_800A7798[];
extern FieldTalk D_800A7224[];
extern u16 D_800A77B8[];
extern FieldTalk D_800A723C[];
extern u16 D_800A77D8[];
extern FieldTalk D_800A7254[];
extern u16 D_800A77E4[];
extern FieldTalk D_800A72A8[];
extern u16 D_800A77F0[];
extern FieldTalk D_800A72FC[];
extern u16 D_800A77FC[];
extern FieldTalk D_800A7350[];
extern u16 D_800A7808[];
extern FieldTalk D_800A73A4[];
extern u16 D_800A7814[];
extern u16 D_800A7820[];
extern u16 D_800A782C[];
extern u16 D_800A7838[];
extern FieldTalk D_800A73F8[];
extern u16 D_800A7844[];
extern FieldTalk D_800A744C[];
extern u16 D_800A7850[];
extern FieldTalk D_800A74A0[];
extern u16 D_800A785C[];
extern FieldTalk D_800A74F4[];
extern u16 D_800A7868[];
extern FieldTalk D_800A7548[];
extern u16 D_800A7874[];
extern FieldTalk D_800A759C[];
extern u16 D_800A7880[];
extern FieldTalk D_800A75F0[];
extern u16 D_800A788C[];
extern FieldTalk D_800A7644[];
extern u16 D_800A7898[];
extern FieldTalk D_800A7698[];
extern u16 D_800A78A4[];
extern FieldTalk D_800A76EC[];
extern u16 D_800A78B0[];
extern u16 D_800A78C0[];
extern u16 D_800A78D0[];
extern u16 D_800A78E0[];
extern u16 D_800A78F0[];
extern FieldTalk D_800A7740[];
extern u16 D_800A7900[];
extern FieldTalk D_800A7764[];
extern FieldActorEntry D_800A7910;
extern FieldActorEntry D_800A7924;
extern FieldActorEntry D_800A7938;
extern FieldActorEntry D_800A794C;
extern FieldActorEntry D_800A7960;
extern FieldActorEntry D_800A7974;
extern FieldActorEntry D_800A7988;
extern FieldActorEntry D_800A799C;
extern FieldActorEntry D_800A79B0;
extern FieldActorEntry D_800A79C4;
extern FieldActorEntry D_800A79D8;
extern FieldActorEntry D_800A79EC;
extern FieldActorEntry D_800A7A00;
extern FieldActorEntry D_800A7A14;
extern FieldActorEntry D_800A7A28;
extern FieldActorEntry D_800A7A3C;
extern FieldActorEntry D_800A7A50;
extern FieldActorEntry D_800A7A64;
extern FieldActorEntry D_800A7A78;
extern FieldActorEntry D_800A7A8C;
extern FieldActorEntry D_800A7AA0;
extern FieldActorEntry D_800A7AB4;
extern FieldActorEntry D_800A7AC8;
extern FieldActorEntry D_800A7ADC;
extern FieldActorEntry D_800A7AF0;
extern FieldActorEntry D_800A7B04;
extern FieldActorEntry D_800A7B18;
extern FieldActorEntry D_800A7B2C;
extern Battle D_800A7C14;
extern Battle D_800A7C20;
extern Battle D_800A7C2C;
extern Battle D_800A7C38;
extern Battle D_800A7C44;
extern Battle D_800A7C50;
extern Battle D_800A7C5C;
extern Battle D_800A7C68;
extern Battle D_800A7C98;
extern Battle D_800A7CA4;
extern Battle D_800A7CB0;
extern Battle D_800A7CBC;
extern Battle D_800A7CC8;
extern Battle D_800A7CD4;
extern Battle D_800A7CE0;
extern Battle D_800A7CEC;
extern Battle D_800A7D1C;
extern Battle D_800A7D28;
extern Battle D_800A7D34;
extern Battle D_800A7D40;
extern Battle D_800A7D4C;
extern Battle D_800A7D58;
extern Battle D_800A7D64;
extern Battle D_800A7D70;
extern Battle D_800A7DA0;
extern Battle D_800A7DAC;
extern Battle D_800A7DB8;
extern Battle D_800A7DC4;
extern Battle D_800A7DD0;
extern Battle D_800A7DDC;
extern Battle D_800A7DE8;
extern Battle D_800A7DF4;
extern Battle D_800A7E24;
extern Battle D_800A7E30;
extern Battle D_800A7E3C;
extern Battle D_800A7E48;
extern Battle D_800A7E54;
extern Battle D_800A7E60;
extern Battle D_800A7E6C;
extern Battle D_800A7E78;
extern Battle D_800A7EA8;
extern Battle D_800A7EB4;
extern Battle D_800A7EC0;
extern Battle D_800A7ECC;
extern Battle D_800A7ED8;
extern Battle D_800A7EE4;
extern Battle D_800A7EF0;
extern Battle D_800A7EFC;
extern Battle D_800A7F2C;
extern Battle D_800A7F38;
extern Battle D_800A7F44;
extern Battle D_800A7F50;
extern Battle D_800A7F5C;
extern Battle D_800A7F68;
extern Battle D_800A7F74;
extern Battle D_800A7F80;
extern Battle D_800A7FB0;
extern Battle D_800A7FBC;
extern Battle D_800A7FC8;
extern Battle D_800A7FD4;
extern Battle D_800A7FE0;
extern Battle D_800A7FEC;
extern Battle D_800A7FF8;
extern Battle D_800A8004;
extern Battle D_800A8034;
extern Battle D_800A8040;
extern Battle D_800A804C;
extern Battle D_800A8058;
extern Battle D_800A8064;
extern Battle D_800A8070;
extern Battle D_800A807C;
extern Battle D_800A8088;
extern Battle D_800A80B8;
extern Battle D_800A80C4;
extern Battle D_800A80D0;
extern Battle D_800A80DC;
extern Battle D_800A80E8;
extern Battle D_800A80F4;
extern Battle D_800A8100;
extern Battle D_800A810C;
extern Battle D_800A813C;
extern Battle D_800A8148;
extern Battle D_800A8154;
extern Battle D_800A8160;
extern Battle D_800A816C;
extern Battle D_800A8178;
extern Battle D_800A8184;
extern Battle D_800A8190;
extern Battle D_800A81C0;
extern Battle D_800A81CC;
extern Battle D_800A81D8;
extern Battle D_800A81E4;
extern Battle D_800A81F0;
extern Battle D_800A81FC;
extern Battle D_800A8208;
extern Battle D_800A8214;
extern Battle D_800A8244;
extern Battle D_800A8250;
extern Battle D_800A825C;
extern Battle D_800A8268;
extern Battle D_800A8274;
extern Battle D_800A8280;
extern Battle D_800A828C;
extern Battle D_800A8298;
extern Battle D_800A82C8;
extern Battle D_800A82D4;
extern Battle D_800A82E0;
extern Battle D_800A82EC;
extern Battle D_800A82F8;
extern Battle D_800A8304;
extern Battle D_800A8310;
extern Battle D_800A831C;
extern Battle D_800A834C;
extern Battle D_800A8358;
extern Battle D_800A8364;
extern Battle D_800A8370;
extern Battle D_800A837C;
extern Battle D_800A8388;
extern Battle D_800A8394;
extern Battle D_800A83A0;
extern Battle D_800A83D0;
extern Battle D_800A83DC;
extern Battle D_800A83E8;
extern Battle D_800A83F4;
extern Battle D_800A8400;
extern Battle D_800A840C;
extern Battle D_800A8418;
extern Battle D_800A8424;
extern Battle D_800A8454;
extern Battle D_800A8460;
extern Battle D_800A846C;
extern Battle D_800A8478;
extern Battle D_800A8484;
extern Battle D_800A8490;
extern Battle D_800A849C;
extern Battle D_800A84A8;
extern Battle D_800A84D8;
extern Battle D_800A84E4;
extern Battle D_800A84F0;
extern Battle D_800A84FC;
extern Battle D_800A8508;
extern Battle D_800A8514;
extern Battle D_800A8520;
extern Battle D_800A852C;
extern Battle D_800A855C;
extern Battle D_800A8568;
extern Battle D_800A8574;
extern Battle D_800A8580;
extern Battle D_800A858C;
extern Battle D_800A8598;
extern Battle D_800A85A4;
extern Battle D_800A85B0;
extern Battle D_800A85E0;
extern Battle D_800A85EC;
extern Battle D_800A85F8;
extern Battle D_800A8604;
extern Battle D_800A8610;
extern Battle D_800A861C;
extern Battle D_800A8628;
extern Battle D_800A8634;
extern Battle D_800A8664;
extern Battle D_800A8670;
extern Battle D_800A867C;
extern Battle D_800A8688;
extern Battle D_800A8694;
extern Battle D_800A86A0;
extern Battle D_800A86AC;
extern Battle D_800A86B8;
extern Battle D_800A86E8;
extern Battle D_800A86F4;
extern Battle D_800A8700;
extern Battle D_800A870C;
extern Battle D_800A8718;
extern Battle D_800A8724;
extern Battle D_800A8730;
extern Battle D_800A873C;
extern Battle D_800A876C;
extern Battle D_800A8778;
extern Battle D_800A8784;
extern Battle D_800A8790;
extern Battle D_800A879C;
extern Battle D_800A87A8;
extern Battle D_800A87B4;
extern Battle D_800A87C0;
extern Battle D_800A87F0;
extern Battle D_800A87FC;
extern Battle D_800A8808;
extern Battle D_800A8814;
extern Battle D_800A8820;
extern Battle D_800A882C;
extern Battle D_800A8838;
extern Battle D_800A8844;
extern BattleList D_800A7C74;
extern BattleList D_800A7CF8;
extern BattleList D_800A7D7C;
extern BattleList D_800A7E00;
extern BattleList D_800A7E84;
extern BattleList D_800A7F08;
extern BattleList D_800A7F8C;
extern BattleList D_800A8010;
extern BattleList D_800A8094;
extern BattleList D_800A8118;
extern BattleList D_800A819C;
extern BattleList D_800A8220;
extern BattleList D_800A82A4;
extern BattleList D_800A8328;
extern BattleList D_800A83AC;
extern BattleList D_800A8430;
extern BattleList D_800A84B4;
extern BattleList D_800A8538;
extern BattleList D_800A85BC;
extern BattleList D_800A8640;
extern BattleList D_800A86C4;
extern BattleList D_800A8748;
extern BattleList D_800A87CC;
extern BattleList D_800A8850;

StagePoint D_800A60DC = { 0x2ED, 1, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A60EC = { 0x2EC, 1, 2, 240, 0x1D8, 5, &D_800A60DC };
StagePoints D_800A60FC = { 1, 1, &D_800A60EC };
StagePoint D_800A6104 = { 0x2EC, 1, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A6114 = { 0x2ED, 1, 2, 0x350, 0x1F8, 5, &D_800A6104 };
StagePoints D_800A6124 = { 1, 2, &D_800A6114 };
StagePoint D_800A612C = { 0x2ED, 1, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A613C = { 0x2ED, 1, 3, 224, 192, 5, &D_800A612C };
StagePoints D_800A614C = { 1, 3, &D_800A613C };
StagePoint D_800A6154 = { 0x2EE, 1, 2, 0x130, 200, 1, NULL };
StagePoint D_800A6164 = { 0x2ED, 1, 3, 0x350, 0x1F8, 5, &D_800A6154 };
StagePoints D_800A6174 = { 1, 4, &D_800A6164 };
StagePoint D_800A617C = { 0x2EE, 1, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A618C = { 0x2ED, 1, 4, 224, 192, 5, &D_800A617C };
StagePoints D_800A619C = { 1, 5, &D_800A618C };
StagePoint D_800A61A4 = { 0x2ED, 1, 5, 0x3A0, 128, 1, NULL };
StagePoint D_800A61B4 = { 0x2EE, 1, 3, 224, 0x240, 5, &D_800A61A4 };
StagePoints D_800A61C4 = { 1, 6, &D_800A61B4 };
StagePoint D_800A61CC = { 0x2EE, 1, 4, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A61DC = { 0x2EC, 1, 8, 240, 0x1D8, 5, &D_800A61CC };
StagePoints D_800A61EC = { 1, 7, &D_800A61DC };
StagePoint D_800A61F4 = { 0x2EC, 1, 7, 0x3B0, 120, 1, NULL };
StagePoint D_800A6204 = { 0x2E8, 1, 2, 176, 0x168, 5, &D_800A61F4 };
StagePoints D_800A6214 = { 1, 8, &D_800A6204 };
StagePoint D_800A621C = { 0x2EE, 2, 6, 0x130, 200, 1, NULL };
StagePoint D_800A622C = { 0x2EE, 2, 3, 224, 0x240, 5, &D_800A621C };
StagePoints D_800A623C = { 2, 1, &D_800A622C };
StagePoint D_800A6244 = { 0x2EE, 2, 6, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6254 = { 0x2EE, 2, 4, 224, 0x240, 5, &D_800A6244 };
StagePoints D_800A6264 = { 2, 2, &D_800A6254 };
StagePoint D_800A626C = { 0x2ED, 3, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A627C = { 0x2EC, 4, 6, 240, 0x1D8, 5, &D_800A626C };
StagePoints D_800A628C = { 3, 1, &D_800A627C };
StagePoint D_800A6294 = { 0x2EE, 3, 1, 0x130, 200, 1, NULL };
StagePoint D_800A62A4 = { 0x2E8, 3, 1, 176, 0x168, 5, &D_800A6294 };
StagePoints D_800A62B4 = { 3, 2, &D_800A62A4 };
StagePoint D_800A62BC = { 0x2EE, 3, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A62CC = { 0x2ED, 3, 1, 224, 192, 5, &D_800A62BC };
StagePoints D_800A62DC = { 3, 3, &D_800A62CC };
StagePoint D_800A62E4 = { 0x2EE, 3, 2, 0x130, 200, 1, NULL };
StagePoint D_800A62F4 = { 0x2ED, 3, 2, 224, 192, 5, &D_800A62E4 };
StagePoints D_800A6304 = { 3, 4, &D_800A62F4 };
StagePoint D_800A630C = { 0x2EC, 3, 7, 0x3B0, 120, 1, NULL };
StagePoint D_800A631C = { 0x2EE, 3, 1, 224, 0x240, 5, &D_800A630C };
StagePoints D_800A632C = { 3, 5, &D_800A631C };
StagePoint D_800A6334 = { 0x2EE, 3, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6344 = { 0x2ED, 3, 3, 0x350, 0x1F8, 5, &D_800A6334 };
StagePoints D_800A6354 = { 3, 6, &D_800A6344 };
StagePoint D_800A635C = { 0x2EE, 3, 4, 0x130, 200, 1, NULL };
StagePoint D_800A636C = { 0x2EC, 3, 5, 240, 0x1D8, 5, &D_800A635C };
StagePoints D_800A637C = { 3, 7, &D_800A636C };
StagePoint D_800A6384 = { 0x2EE, 3, 5, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6394 = { 0x2EE, 3, 3, 224, 0x240, 5, &D_800A6384 };
StagePoints D_800A63A4 = { 3, 8, &D_800A6394 };
StagePoint D_800A63AC = { 0x2EE, 4, 1, 0x130, 200, 1, NULL };
StagePoint D_800A63BC = { 0x2E8, 4, 1, 176, 0x168, 5, &D_800A63AC };
StagePoints D_800A63CC = { 4, 1, &D_800A63BC };
StagePoint D_800A63D4 = { 0x2EE, 4, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A63E4 = { 0x2ED, 4, 1, 224, 192, 5, &D_800A63D4 };
StagePoints D_800A63F4 = { 4, 2, &D_800A63E4 };
StagePoint D_800A63FC = { 0x2ED, 4, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A640C = { 0x2ED, 4, 1, 0x350, 0x1F8, 5, &D_800A63FC };
StagePoints D_800A641C = { 4, 3, &D_800A640C };
StagePoint D_800A6424 = { 0x2EE, 4, 2, 0x130, 200, 1, NULL };
StagePoint D_800A6434 = { 0x2ED, 4, 2, 224, 192, 5, &D_800A6424 };
StagePoints D_800A6444 = { 4, 4, &D_800A6434 };
StagePoint D_800A644C = { 0x2EE, 4, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A645C = { 0x2ED, 4, 2, 0x350, 0x1F8, 5, &D_800A644C };
StagePoints D_800A646C = { 4, 5, &D_800A645C };
StagePoint D_800A6474 = { 0x2EC, 3, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A6484 = { 0x2ED, 4, 3, 224, 192, 5, &D_800A6474 };
StagePoints D_800A6494 = { 4, 6, &D_800A6484 };
StagePoint D_800A649C = { 0x2EE, 4, 3, 0x130, 200, 1, NULL };
StagePoint D_800A64AC = { 0x2ED, 4, 3, 0x350, 0x1F8, 5, &D_800A649C };
StagePoints D_800A64BC = { 4, 7, &D_800A64AC };
StagePoint D_800A64C4 = { 0x2ED, 5, 3, 0x3A0, 128, 1, NULL };
StagePoint D_800A64D4 = { 0x2ED, 5, 1, 224, 192, 5, &D_800A64C4 };
StagePoints D_800A64E4 = { 5, 1, &D_800A64D4 };
StagePoint D_800A64EC = { 0x2EE, 5, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A64FC = { 0x2ED, 5, 2, 224, 192, 5, &D_800A64EC };
StagePoints D_800A650C = { 5, 2, &D_800A64FC };
StagePoint D_800A6514 = { 0x2ED, 5, 6, 0x3A0, 128, 1, NULL };
StagePoint D_800A6524 = { 0x2ED, 5, 4, 0x350, 0x1F8, 5, &D_800A6514 };
StagePoints D_800A6534 = { 5, 3, &D_800A6524 };
StagePoint D_800A653C = { 0x2EE, 5, 4, 0x130, 200, 1, NULL };
StagePoint D_800A654C = { 0x2EE, 5, 3, 224, 0x240, 5, &D_800A653C };
StagePoints D_800A655C = { 5, 4, &D_800A654C };
StagePoint D_800A6564 = { 0x2EE, 5, 5, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6574 = { 0x2EE, 5, 4, 224, 0x240, 5, &D_800A6564 };
StagePoints D_800A6584 = { 5, 5, &D_800A6574 };
StagePoint D_800A658C = { 0x2ED, 6, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A659C = { 0x2EE, 5, 2, 224, 0x240, 5, &D_800A658C };
StagePoints D_800A65AC = { 6, 1, &D_800A659C };
StagePoint D_800A65B4 = { 0x2ED, 6, 3, 0x3A0, 128, 1, NULL };
StagePoint D_800A65C4 = { 0x2ED, 6, 1, 224, 192, 5, &D_800A65B4 };
StagePoints D_800A65D4 = { 6, 2, &D_800A65C4 };
StagePoint D_800A65DC = { 0x2EE, 6, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A65EC = { 0x2ED, 6, 2, 0x350, 0x1F8, 5, &D_800A65DC };
StagePoints D_800A65FC = { 6, 3, &D_800A65EC };
StagePoint D_800A6604 = { 0x2EE, 6, 6, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A6614 = { 0x2EE, 5, 5, 224, 0x240, 5, &D_800A6604 };
StagePoints D_800A6624 = { 6, 4, &D_800A6614 };
StagePoints *placePoints[] = {
    &D_800A60FC, &D_800A6124, &D_800A614C, &D_800A6174,
    &D_800A619C, &D_800A61C4, &D_800A61EC, &D_800A6214,
    &D_800A623C, &D_800A6264, &D_800A628C, &D_800A62B4,
    &D_800A62DC, &D_800A6304, &D_800A632C, &D_800A6354,
    &D_800A637C, &D_800A63A4, &D_800A63CC, &D_800A63F4,
    &D_800A641C, &D_800A6444, &D_800A646C, &D_800A6494,
    &D_800A64BC, &D_800A64E4, &D_800A650C, &D_800A6534,
    &D_800A655C, &D_800A6584, &D_800A65AC, &D_800A65D4,
    &D_800A65FC, &D_800A6624, NULL,
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x178, 0x100, 0xE0, 0, 0x140, 0x1FF },
    { 0x140, 0x100, 0x178, 0x120, 0xE0, 0x20, 0x150, 0x1FF },
    { 0x140, 0x100, 0x172, 0x140, 0xC8, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x15A, 0x140, 0x68, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x14E, 0x140, 0x38, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x150, 0x1FE },
    { 0x140, 0x100, 0x162, 0x140, 0x88, 0x40, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x140, 0xA8, 0x40, 0x170, 0x1FE },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x140, 0x1FD },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x150, 0x1FD },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x160, 0x1FD },
};
u16 D_800A67C8[] = { 0x278, 1, 0x8472, 1, 0xFFFF };
u16 D_800A67D4[] = { 0x27B, 1, 0x8666, 1, 0xFFFF };
u16 D_800A67E0[] = { 0x27C, 1, 0x868D, 1, 0xFFFF };
u16 D_800A67EC[] = { 0x8192, 0, 0xFFFF };
u16 D_800A67F4[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6800[] = { 0, 1, 0xFFFF };
u16 D_800A6808[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6818[] = { 0x7817, 1, 0xFFFF };
u16 D_800A6820[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6834[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6840[] = {
    0x9213, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6858[] = { 0x9213, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A686C[] = {
    0x9213, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6884[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6894[] = { 0x8192, 0, 0xFFFF };
u16 D_800A689C[] = { 0x8192, 1, 1, 0, 0xFFFF };
u16 D_800A68A8[] = { 1, 1, 0xFFFF };
u16 D_800A68B0[] = { 0x11, 0, 1, 1, 0x8192, 1, 0xFFFF };
u16 D_800A68C0[] = { 0x781A, 1, 0xFFFF };
u16 D_800A68C8[] = { 0x10, 0, 0x11, 1, 1, 1, 0x8192, 1, 0xFFFF };
u16 D_800A68DC[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A68E8[] = {
    0x9201, 0, 0x10, 1, 0x11, 1, 1, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6900[] = { 0x9201, 1, 0x10, 0, 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A6914[] = {
    0x9201, 1, 0x10, 1, 0x11, 1, 1, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A692C[] = { 0x10, 0, 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A693C[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6944[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6950[] = { 0, 1, 0xFFFF };
u16 D_800A6958[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6968[] = { 0x7806, 1, 0xFFFF };
u16 D_800A6970[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6984[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6990[] = {
    0x920D, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A69A8[] = { 0x920D, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A69BC[] = {
    0x920D, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A69D4[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A69E4[] = { 0x8192, 0, 0xFFFF };
u16 D_800A69EC[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A69F8[] = { 0, 1, 0xFFFF };
u16 D_800A6A00[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6A10[] = { 0x7821, 1, 0xFFFF };
u16 D_800A6A18[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6A2C[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6A38[] = {
    0x9219, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6A50[] = { 0x9219, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6A64[] = {
    0x9219, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6A7C[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6A8C[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6A94[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6AA0[] = { 0, 1, 0xFFFF };
u16 D_800A6AA8[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6AB8[] = { 0x7811, 1, 0xFFFF };
u16 D_800A6AC0[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6AD4[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6AE0[] = {
    0x9207, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6AF8[] = { 0x9207, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6B0C[] = {
    0x9207, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6B24[] = { 0, 0, 0x10, 0, 0x11, 0, 0xFFFF };
u16 D_800A6B34[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6B3C[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6B48[] = { 0, 1, 0xFFFF };
u16 D_800A6B50[] = { 0, 1, 0x11, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6B60[] = { 0x764A, 1, 0xFFFF };
u16 D_800A6B68[] = { 0, 1, 0x11, 1, 0x10, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6B7C[] = { 0, 0, 0x11, 0, 0xFFFF };
u16 D_800A6B88[] = {
    0, 1, 0x11, 1, 0x10, 1, 0x9221, 0,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6BA0[] = { 0, 0, 0x11, 0, 0x10, 0, 0x9221, 1, 0xFFFF };
u16 D_800A6BB4[] = {
    0, 1, 0x11, 1, 0x10, 1, 0x9221, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6BCC[] = { 0, 0, 0x11, 0, 0x10, 0, 0xFFFF };
u16 D_800A6BDC[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6BE4[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6BF0[] = { 0, 1, 0xFFFF };
u16 D_800A6BF8[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6C08[] = { 0x7648, 1, 0xFFFF };
u16 D_800A6C10[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6C24[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6C30[] = {
    0x9222, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6C48[] = { 0x9222, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6C5C[] = {
    0x9222, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6C74[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6C84[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6C8C[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6C98[] = { 0, 1, 0xFFFF };
u16 D_800A6CA0[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6CB0[] = { 0x7649, 1, 0xFFFF };
u16 D_800A6CB8[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6CCC[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6CD8[] = {
    0x9223, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6CF0[] = { 0x9223, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6D04[] = {
    0x9223, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6D1C[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6D2C[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6D34[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6D40[] = { 0, 1, 0xFFFF };
u16 D_800A6D48[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6D58[] = { 0x764B, 1, 0xFFFF };
u16 D_800A6D60[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6D74[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6D80[] = {
    0x921F, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6D98[] = { 0x921F, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6DAC[] = {
    0x921F, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6DC4[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6DD4[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6DDC[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6DE8[] = { 0, 1, 0xFFFF };
u16 D_800A6DF0[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6E00[] = { 0x7647, 1, 0xFFFF };
u16 D_800A6E08[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6E1C[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6E28[] = {
    0x9220, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6E40[] = { 0x9220, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6E54[] = {
    0x9220, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6E6C[] = { 0x11, 0, 0, 0, 0x10, 0, 0xFFFF };
u16 D_800A6E7C[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6E84[] = { 1, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6E90[] = { 1, 1, 0xFFFF };
u16 D_800A6E98[] = { 0x11, 0, 1, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6EA8[] = { 0x764F, 1, 0xFFFF };
u16 D_800A6EB0[] = { 0x11, 1, 1, 1, 0x8192, 1, 0x10, 0, 0xFFFF };
u16 D_800A6EC4[] = { 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A6ED0[] = {
    0x92F1, 0, 0x10, 1, 0x11, 1, 1, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6EE8[] = { 0x92F1, 1, 0x10, 0, 0x11, 0, 1, 0, 0xFFFF };
u16 D_800A6EFC[] = {
    0x92F1, 1, 0x10, 1, 0x11, 1, 1, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6F14[] = { 0x11, 0, 1, 0, 0x10, 0, 0xFFFF };
u16 D_800A6F24[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6F2C[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6F38[] = { 0, 1, 0xFFFF };
u16 D_800A6F40[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6F50[] = { 0x764E, 1, 0xFFFF };
u16 D_800A6F58[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6F6C[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6F78[] = {
    0x10, 1, 0x11, 1, 0, 1, 0x8192, 1,
    0x9245, 0, 0xFFFF,
};
u16 D_800A6F90[] = { 0x9245, 1, 0x11, 0, 0x10, 0, 0, 0, 0xFFFF };
u16 D_800A6FA4[] = {
    0x9245, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A6FBC[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A6FCC[] = { 0x8192, 0, 0xFFFF };
u16 D_800A6FD4[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A6FE0[] = { 0, 1, 0xFFFF };
u16 D_800A6FE8[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A6FF8[] = { 0x764D, 1, 0xFFFF };
u16 D_800A7000[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7014[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A7020[] = {
    0x929B, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A7038[] = { 0x929B, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A704C[] = {
    0x929B, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A7064[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A7074[] = { 0x8192, 0, 0xFFFF };
u16 D_800A707C[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A7088[] = { 0, 1, 0xFFFF };
u16 D_800A7090[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A70A0[] = { 0x764C, 1, 0xFFFF };
u16 D_800A70A8[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A70BC[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A70C8[] = {
    0x92C6, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A70E0[] = { 0x92C6, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A70F4[] = {
    0x92C6, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A710C[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A711C[] = { 0x8192, 0, 0xFFFF };
u16 D_800A7124[] = { 0, 0, 0x8192, 1, 0xFFFF };
u16 D_800A7130[] = { 0, 1, 0xFFFF };
u16 D_800A7138[] = { 0x11, 0, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7148[] = { 0x7650, 1, 0xFFFF };
u16 D_800A7150[] = { 0x10, 0, 0x11, 1, 0, 1, 0x8192, 1, 0xFFFF };
u16 D_800A7164[] = { 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A7170[] = {
    0x9270, 0, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A7188[] = { 0x9270, 1, 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A719C[] = {
    0x9270, 1, 0x10, 1, 0x11, 1, 0, 1,
    0x8192, 1, 0xFFFF,
};
u16 D_800A71B4[] = { 0x10, 0, 0x11, 0, 0, 0, 0xFFFF };
u16 D_800A71C4[] = { 0, 0, 0xFFFF };
u16 D_800A71CC[] = { 0, 1, 0xFFFF };
u16 D_800A71D4[] = { 0, 1, 0xFFFF };
u16 D_800A71DC[] = { 0x7400, 1, 0xA10, 1, 0xFFFF };
u16 D_800A71E8[] = { 0, 0, 0xFFFF };
u16 D_800A71F0[] = { 0, 1, 0xFFFF };
u16 D_800A71F8[] = { 0, 1, 0xFFFF };
u16 D_800A7200[] = { 0xA13, 1, 0x7401, 1, 0xFFFF };
FieldTalk D_800A720C[] = {
    { NULL, D_800A67C8, 0x10 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7224[] = {
    { NULL, D_800A67D4, 0x13 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A723C[] = {
    { NULL, D_800A67E0, 0x14 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7254[] = {
    { D_800A67EC, NULL, 0x10A },
    { D_800A67F4, D_800A6800, 0x10A },
    { D_800A6808, D_800A6818, 0x10E },
    { D_800A6820, D_800A6834, 0x111 },
    { D_800A6840, D_800A6858, 0x122 },
    { D_800A686C, D_800A6884, 0x114 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A72A8[] = {
    { D_800A6894, NULL, 0x107 },
    { D_800A689C, D_800A68A8, 0x107 },
    { D_800A68B0, D_800A68C0, 0x10E },
    { D_800A68C8, D_800A68DC, 0x111 },
    { D_800A68E8, D_800A6900, 0x11F },
    { D_800A6914, D_800A692C, 0x114 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A72FC[] = {
    { D_800A693C, NULL, 0x109 },
    { D_800A6944, D_800A6950, 0x109 },
    { D_800A6958, D_800A6968, 0x10E },
    { D_800A6970, D_800A6984, 0x111 },
    { D_800A6990, D_800A69A8, 0x121 },
    { D_800A69BC, D_800A69D4, 0x114 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7350[] = {
    { D_800A69E4, NULL, 0x10B },
    { D_800A69EC, D_800A69F8, 0x10B },
    { D_800A6A00, D_800A6A10, 0x10E },
    { D_800A6A18, D_800A6A2C, 0x111 },
    { D_800A6A38, D_800A6A50, 0x123 },
    { D_800A6A64, D_800A6A7C, 0x114 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A73A4[] = {
    { D_800A6A8C, NULL, 0x108 },
    { D_800A6A94, D_800A6AA0, 0x108 },
    { D_800A6AA8, D_800A6AB8, 0x10E },
    { D_800A6AC0, D_800A6AD4, 0x111 },
    { D_800A6AE0, D_800A6AF8, 0x120 },
    { D_800A6B0C, D_800A6B24, 0x114 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A73F8[] = {
    { D_800A6B34, NULL, 0xFF },
    { D_800A6B3C, D_800A6B48, 0xFF },
    { D_800A6B50, D_800A6B60, 0x10C },
    { D_800A6B68, D_800A6B7C, 0x10F },
    { D_800A6B88, D_800A6BA0, 0x117 },
    { D_800A6BB4, D_800A6BCC, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A744C[] = {
    { D_800A6BDC, NULL, 0x100 },
    { D_800A6BE4, D_800A6BF0, 0x100 },
    { D_800A6BF8, D_800A6C08, 0x10C },
    { D_800A6C10, D_800A6C24, 0x10F },
    { D_800A6C30, D_800A6C48, 0x118 },
    { D_800A6C5C, D_800A6C74, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A74A0[] = {
    { D_800A6C84, NULL, 0x101 },
    { D_800A6C8C, D_800A6C98, 0x101 },
    { D_800A6CA0, D_800A6CB0, 0x10C },
    { D_800A6CB8, D_800A6CCC, 0x10F },
    { D_800A6CD8, D_800A6CF0, 0x119 },
    { D_800A6D04, D_800A6D1C, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A74F4[] = {
    { D_800A6D2C, NULL, 0xFD },
    { D_800A6D34, D_800A6D40, 0xFD },
    { D_800A6D48, D_800A6D58, 0x10C },
    { D_800A6D60, D_800A6D74, 0x10F },
    { D_800A6D80, D_800A6D98, 0x115 },
    { D_800A6DAC, D_800A6DC4, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7548[] = {
    { D_800A6DD4, NULL, 0xFE },
    { D_800A6DDC, D_800A6DE8, 0xFE },
    { D_800A6DF0, D_800A6E00, 0x10C },
    { D_800A6E08, D_800A6E1C, 0x10F },
    { D_800A6E28, D_800A6E40, 0x116 },
    { D_800A6E54, D_800A6E6C, 0x112 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A759C[] = {
    { D_800A6E7C, NULL, 0x106 },
    { D_800A6E84, D_800A6E90, 0x106 },
    { D_800A6E98, D_800A6EA8, 0x10D },
    { D_800A6EB0, D_800A6EC4, 0x110 },
    { D_800A6ED0, D_800A6EE8, 0x11E },
    { D_800A6EFC, D_800A6F14, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A75F0[] = {
    { D_800A6F24, NULL, 0x102 },
    { D_800A6F2C, D_800A6F38, 0x102 },
    { D_800A6F40, D_800A6F50, 0x10D },
    { D_800A6F58, D_800A6F6C, 0x110 },
    { D_800A6F78, D_800A6F90, 0x11A },
    { D_800A6FA4, D_800A6FBC, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7644[] = {
    { D_800A6FCC, NULL, 0x104 },
    { D_800A6FD4, D_800A6FE0, 0x104 },
    { D_800A6FE8, D_800A6FF8, 0x10D },
    { D_800A7000, D_800A7014, 0x110 },
    { D_800A7020, D_800A7038, 0x11C },
    { D_800A704C, D_800A7064, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7698[] = {
    { D_800A7074, NULL, 0x105 },
    { D_800A707C, D_800A7088, 0x105 },
    { D_800A7090, D_800A70A0, 0x10D },
    { D_800A70A8, D_800A70BC, 0x110 },
    { D_800A70C8, D_800A70E0, 0x11D },
    { D_800A70F4, D_800A710C, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76EC[] = {
    { D_800A711C, NULL, 0x103 },
    { D_800A7124, D_800A7130, 0x103 },
    { D_800A7138, D_800A7148, 0x10D },
    { D_800A7150, D_800A7164, 0x110 },
    { D_800A7170, D_800A7188, 0x11B },
    { D_800A719C, D_800A71B4, 0x113 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7740[] = {
    { D_800A71C4, D_800A71CC, 0xF5 },
    { D_800A71D4, D_800A71DC, 0xF6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7764[] = {
    { D_800A71E8, D_800A71F0, 0xFB },
    { D_800A71F8, D_800A7200, 0xFC },
    { NULL, NULL, 0 },
};
u16 D_800A7788[] = { 0x7E00, 1, 0x7E25, 1, 0x278, 0, 0xFFFF };
u16 D_800A7798[] = {
    0x7E00, 1, 0x7E25, 1, 0x27B, 0, 0x8666, 0,
    0x8667, 0, 0x8668, 0, 0x8669, 0, 0xFFFF,
};
u16 D_800A77B8[] = {
    0x7E00, 1, 0x7E25, 1, 0x27C, 0, 0x868D, 0,
    0x868E, 0, 0x868F, 0, 0x8690, 0, 0xFFFF,
};
u16 D_800A77D8[] = { 0x7E02, 1, 0x7E20, 1, 0xFFFF };
u16 D_800A77E4[] = { 0x7E02, 1, 0x7E24, 1, 0xFFFF };
u16 D_800A77F0[] = { 0x7E03, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A77FC[] = { 0x7E03, 1, 0x7E22, 1, 0xFFFF };
u16 D_800A7808[] = { 0x7E03, 1, 0x7E24, 1, 0xFFFF };
u16 D_800A7814[] = { 0x7E00, 1, 8, 0, 0xFFFF };
u16 D_800A7820[] = { 0x7E02, 1, 8, 0, 0xFFFF };
u16 D_800A782C[] = { 0x7E04, 1, 8, 0, 0xFFFF };
u16 D_800A7838[] = { 0x7E02, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A7844[] = { 0x7E02, 1, 0x7E25, 1, 0xFFFF };
u16 D_800A7850[] = { 0x7E03, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A785C[] = { 0x7E03, 1, 0x7E21, 1, 0xFFFF };
u16 D_800A7868[] = { 0x7E03, 1, 0x7E23, 1, 0xFFFF };
u16 D_800A7874[] = { 0x7E02, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A7880[] = { 0x7E02, 1, 0x7E21, 1, 0xFFFF };
u16 D_800A788C[] = { 0x7E02, 1, 0x7E22, 1, 0xFFFF };
u16 D_800A7898[] = { 0x7E02, 1, 0x7E23, 1, 0xFFFF };
u16 D_800A78A4[] = { 0x7E03, 1, 0x7E20, 1, 0xFFFF };
u16 D_800A78B0[] = { 0x7E00, 0, 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A78C0[] = { 0x7E00, 0, 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A78D0[] = { 0x7E00, 0, 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A78E0[] = { 0x7E00, 0, 0x7E21, 1, 9, 0, 0xFFFF };
u16 D_800A78F0[] = { 0x7E00, 1, 0x7E21, 1, 0xA10, 0, 0xFFFF };
u16 D_800A7900[] = { 0x7E00, 1, 0x7E25, 1, 0xA13, 0, 0xFFFF };
FieldActorEntry D_800A7910 = { D_800A7788, D_800A720C, 0x21, 4, 800, 344, 1 };
FieldActorEntry D_800A7924 = { D_800A7798, D_800A7224, 0x4D, 5, 704, 352, 1 };
FieldActorEntry D_800A7938 = { D_800A77B8, D_800A723C, 0x4E, 6, 616, 272, 1 };
FieldActorEntry D_800A794C = { D_800A77D8, D_800A7254, 0xC1, 7, 448, 200, 1 };
FieldActorEntry D_800A7960 = { D_800A77E4, D_800A72A8, 0xC1, 7, 448, 200, 1 };
FieldActorEntry D_800A7974 = { D_800A77F0, D_800A72FC, 0xC1, 7, 800, 344, 1 };
FieldActorEntry D_800A7988 = { D_800A77FC, D_800A7350, 0xC1, 7, 448, 200, 1 };
FieldActorEntry D_800A799C = { D_800A7808, D_800A73A4, 0xC1, 7, 888, 460, 1 };
FieldActorEntry D_800A79B0 = { NULL, NULL, 0x146, 8, 0, 0, 0 };
FieldActorEntry D_800A79C4 = { D_800A7814, NULL, 0x148, 9, 736, 416, 1 };
FieldActorEntry D_800A79D8 = { D_800A7820, NULL, 0x148, 9, 800, 448, 1 };
FieldActorEntry D_800A79EC = { D_800A782C, NULL, 0x148, 9, 736, 416, 1 };
FieldActorEntry D_800A7A00 = { D_800A7838, D_800A73F8, 0x14D, 0xA, 448, 200, 1 };
FieldActorEntry D_800A7A14 = { D_800A7844, D_800A744C, 0x14D, 0xA, 888, 460, 1 };
FieldActorEntry D_800A7A28 = { D_800A7850, D_800A74A0, 0x14D, 0xA, 888, 460, 1 };
FieldActorEntry D_800A7A3C = { D_800A785C, D_800A74F4, 0x14D, 0xA, 448, 200, 1 };
FieldActorEntry D_800A7A50 = { D_800A7868, D_800A7548, 0x14D, 0xA, 448, 200, 1 };
FieldActorEntry D_800A7A64 = { D_800A7874, D_800A759C, 0x159, 0xB, 448, 200, 1 };
FieldActorEntry D_800A7A78 = { D_800A7880, D_800A75F0, 0x159, 0xB, 448, 200, 1 };
FieldActorEntry D_800A7A8C = { D_800A788C, D_800A7644, 0x159, 0xB, 888, 460, 1 };
FieldActorEntry D_800A7AA0 = { D_800A7898, D_800A7698, 0x159, 0xB, 888, 460, 1 };
FieldActorEntry D_800A7AB4 = { D_800A78A4, D_800A76EC, 0x159, 0xB, 800, 344, 1 };
FieldActorEntry D_800A7AC8 = { D_800A78B0, NULL, 0x15F, 0xC, 784, 200, 1 };
FieldActorEntry D_800A7ADC = { D_800A78C0, NULL, 0x15F, 0xC, 304, 440, 1 };
FieldActorEntry D_800A7AF0 = { D_800A78D0, NULL, 0x15F, 0xC, 880, 152, 1 };
FieldActorEntry D_800A7B04 = { D_800A78E0, NULL, 0x15F, 0xC, 736, 272, 1 };
FieldActorEntry D_800A7B18 = { D_800A78F0, D_800A7740, 0x18B, 0xD, 464, 424, 7 };
FieldActorEntry D_800A7B2C = { D_800A7900, D_800A7764, 0x18E, 0xE, 592, 440, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A7910,
    &D_800A7924,
    &D_800A7938,
    &D_800A794C,
    &D_800A7960,
    &D_800A7974,
    &D_800A7988,
    &D_800A799C,
    &D_800A79B0,
    &D_800A79C4,
    &D_800A79D8,
    &D_800A79EC,
    &D_800A7A00,
    &D_800A7A14,
    &D_800A7A28,
    &D_800A7A3C,
    &D_800A7A50,
    &D_800A7A64,
    &D_800A7A78,
    &D_800A7A8C,
    &D_800A7AA0,
    &D_800A7AB4,
    &D_800A7AC8,
    &D_800A7ADC,
    &D_800A7AF0,
    &D_800A7B04,
    &D_800A7B18,
    &D_800A7B2C,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2EC, 0x3B0, 0x78, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2EC, 0xF0, 0x1D8, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
Battle D_800A7C14 = { 38, 10, 0x60080000 };
Battle D_800A7C20 = { 56, 10, 0x60080000 };
Battle D_800A7C2C = { 107, 10, 0x60080000 };
Battle D_800A7C38 = { 155, 10, 0x60080000 };
Battle D_800A7C44 = { 120, 10, 0x60080000 };
Battle D_800A7C50 = { 181, 10, 0x60080000 };
Battle D_800A7C5C = { 142, 10, 0x60080000 };
Battle D_800A7C68 = { 143, 10, 0x60080000 };
BattleList D_800A7C74 = {
    3,
    { &D_800A7C14, &D_800A7C20, &D_800A7C2C, &D_800A7C38,
      &D_800A7C44, &D_800A7C50, &D_800A7C5C, &D_800A7C68 },
};
Battle D_800A7C98 = { 0, 0, 0x60040000 };
Battle D_800A7CA4 = { 0, 0, 0x60040000 };
Battle D_800A7CB0 = { 0, 0, 0x60040000 };
Battle D_800A7CBC = { 0, 0, 0x60040000 };
Battle D_800A7CC8 = { 0, 0, 0x60040000 };
Battle D_800A7CD4 = { 0, 0, 0x60040000 };
Battle D_800A7CE0 = { 0, 0, 0x60040000 };
Battle D_800A7CEC = { 0, 0, 0x60040000 };
BattleList D_800A7CF8 = {
    0,
    { &D_800A7C98, &D_800A7CA4, &D_800A7CB0, &D_800A7CBC,
      &D_800A7CC8, &D_800A7CD4, &D_800A7CE0, &D_800A7CEC },
};
Battle D_800A7D1C = { 0, 0, 0x60040000 };
Battle D_800A7D28 = { 0, 0, 0x60040000 };
Battle D_800A7D34 = { 0, 0, 0x60040000 };
Battle D_800A7D40 = { 0, 0, 0x60040000 };
Battle D_800A7D4C = { 0, 0, 0x60040000 };
Battle D_800A7D58 = { 0, 0, 0x60040000 };
Battle D_800A7D64 = { 0, 0, 0x60040000 };
Battle D_800A7D70 = { 0, 0, 0x60040000 };
BattleList D_800A7D7C = {
    0,
    { &D_800A7D1C, &D_800A7D28, &D_800A7D34, &D_800A7D40,
      &D_800A7D4C, &D_800A7D58, &D_800A7D64, &D_800A7D70 },
};
Battle D_800A7DA0 = { 318, 19, 0x60880000 };
Battle D_800A7DAC = { 320, 19, 0x60880000 };
Battle D_800A7DB8 = { 0, 0, 0x60040000 };
Battle D_800A7DC4 = { 0, 0, 0x60040000 };
Battle D_800A7DD0 = { 0, 0, 0x60040000 };
Battle D_800A7DDC = { 0, 0, 0x60040000 };
Battle D_800A7DE8 = { 0, 0, 0x60040000 };
Battle D_800A7DF4 = { 0, 0, 0x60040000 };
BattleList D_800A7E00 = {
    0,
    { &D_800A7DA0, &D_800A7DAC, &D_800A7DB8, &D_800A7DC4,
      &D_800A7DD0, &D_800A7DDC, &D_800A7DE8, &D_800A7DF4 },
};
Battle D_800A7E24 = { 81, 10, 0x60080000 };
Battle D_800A7E30 = { 81, 10, 0x60080000 };
Battle D_800A7E3C = { 165, 10, 0x60080000 };
Battle D_800A7E48 = { 165, 10, 0x60080000 };
Battle D_800A7E54 = { 166, 10, 0x60080000 };
Battle D_800A7E60 = { 166, 10, 0x60080000 };
Battle D_800A7E6C = { 169, 10, 0x60080000 };
Battle D_800A7E78 = { 169, 10, 0x60080000 };
BattleList D_800A7E84 = {
    3,
    { &D_800A7E24, &D_800A7E30, &D_800A7E3C, &D_800A7E48,
      &D_800A7E54, &D_800A7E60, &D_800A7E6C, &D_800A7E78 },
};
Battle D_800A7EA8 = { 0, 0, 0x60040000 };
Battle D_800A7EB4 = { 0, 0, 0x60040000 };
Battle D_800A7EC0 = { 0, 0, 0x60040000 };
Battle D_800A7ECC = { 0, 0, 0x60040000 };
Battle D_800A7ED8 = { 0, 0, 0x60040000 };
Battle D_800A7EE4 = { 0, 0, 0x60040000 };
Battle D_800A7EF0 = { 0, 0, 0x60040000 };
Battle D_800A7EFC = { 0, 0, 0x60040000 };
BattleList D_800A7F08 = {
    0,
    { &D_800A7EA8, &D_800A7EB4, &D_800A7EC0, &D_800A7ECC,
      &D_800A7ED8, &D_800A7EE4, &D_800A7EF0, &D_800A7EFC },
};
Battle D_800A7F2C = { 0, 0, 0x60040000 };
Battle D_800A7F38 = { 0, 0, 0x60040000 };
Battle D_800A7F44 = { 0, 0, 0x60040000 };
Battle D_800A7F50 = { 0, 0, 0x60040000 };
Battle D_800A7F5C = { 0, 0, 0x60040000 };
Battle D_800A7F68 = { 0, 0, 0x60040000 };
Battle D_800A7F74 = { 0, 0, 0x60040000 };
Battle D_800A7F80 = { 0, 0, 0x60040000 };
BattleList D_800A7F8C = {
    0,
    { &D_800A7F2C, &D_800A7F38, &D_800A7F44, &D_800A7F50,
      &D_800A7F5C, &D_800A7F68, &D_800A7F74, &D_800A7F80 },
};
Battle D_800A7FB0 = { 0, 0, 0x60040000 };
Battle D_800A7FBC = { 0, 0, 0x60040000 };
Battle D_800A7FC8 = { 0, 0, 0x60040000 };
Battle D_800A7FD4 = { 0, 0, 0x60040000 };
Battle D_800A7FE0 = { 0, 0, 0x60040000 };
Battle D_800A7FEC = { 0, 0, 0x60040000 };
Battle D_800A7FF8 = { 0, 0, 0x60040000 };
Battle D_800A8004 = { 0, 0, 0x60040000 };
BattleList D_800A8010 = {
    0,
    { &D_800A7FB0, &D_800A7FBC, &D_800A7FC8, &D_800A7FD4,
      &D_800A7FE0, &D_800A7FEC, &D_800A7FF8, &D_800A8004 },
};
Battle D_800A8034 = { 136, 10, 0x60080000 };
Battle D_800A8040 = { 136, 10, 0x60080000 };
Battle D_800A804C = { 137, 10, 0x60080000 };
Battle D_800A8058 = { 137, 10, 0x60080000 };
Battle D_800A8064 = { 183, 10, 0x60080000 };
Battle D_800A8070 = { 183, 10, 0x60080000 };
Battle D_800A807C = { 118, 10, 0x60080000 };
Battle D_800A8088 = { 118, 10, 0x60080000 };
BattleList D_800A8094 = {
    3,
    { &D_800A8034, &D_800A8040, &D_800A804C, &D_800A8058,
      &D_800A8064, &D_800A8070, &D_800A807C, &D_800A8088 },
};
Battle D_800A80B8 = { 0, 0, 0x60040000 };
Battle D_800A80C4 = { 0, 0, 0x60040000 };
Battle D_800A80D0 = { 0, 0, 0x60040000 };
Battle D_800A80DC = { 0, 0, 0x60040000 };
Battle D_800A80E8 = { 0, 0, 0x60040000 };
Battle D_800A80F4 = { 0, 0, 0x60040000 };
Battle D_800A8100 = { 0, 0, 0x60040000 };
Battle D_800A810C = { 0, 0, 0x60040000 };
BattleList D_800A8118 = {
    0,
    { &D_800A80B8, &D_800A80C4, &D_800A80D0, &D_800A80DC,
      &D_800A80E8, &D_800A80F4, &D_800A8100, &D_800A810C },
};
Battle D_800A813C = { 0, 0, 0x60040000 };
Battle D_800A8148 = { 0, 0, 0x60040000 };
Battle D_800A8154 = { 0, 0, 0x60040000 };
Battle D_800A8160 = { 0, 0, 0x60040000 };
Battle D_800A816C = { 0, 0, 0x60040000 };
Battle D_800A8178 = { 0, 0, 0x60040000 };
Battle D_800A8184 = { 0, 0, 0x60040000 };
Battle D_800A8190 = { 0, 0, 0x60040000 };
BattleList D_800A819C = {
    0,
    { &D_800A813C, &D_800A8148, &D_800A8154, &D_800A8160,
      &D_800A816C, &D_800A8178, &D_800A8184, &D_800A8190 },
};
Battle D_800A81C0 = { 0, 0, 0x60040000 };
Battle D_800A81CC = { 0, 0, 0x60040000 };
Battle D_800A81D8 = { 0, 0, 0x60040000 };
Battle D_800A81E4 = { 0, 0, 0x60040000 };
Battle D_800A81F0 = { 0, 0, 0x60040000 };
Battle D_800A81FC = { 0, 0, 0x60040000 };
Battle D_800A8208 = { 0, 0, 0x60040000 };
Battle D_800A8214 = { 0, 0, 0x60040000 };
BattleList D_800A8220 = {
    0,
    { &D_800A81C0, &D_800A81CC, &D_800A81D8, &D_800A81E4,
      &D_800A81F0, &D_800A81FC, &D_800A8208, &D_800A8214 },
};
Battle D_800A8244 = { 113, 10, 0x60080000 };
Battle D_800A8250 = { 113, 10, 0x60080000 };
Battle D_800A825C = { 114, 10, 0x60080000 };
Battle D_800A8268 = { 114, 10, 0x60080000 };
Battle D_800A8274 = { 115, 10, 0x60080000 };
Battle D_800A8280 = { 115, 10, 0x60080000 };
Battle D_800A828C = { 167, 10, 0x60080000 };
Battle D_800A8298 = { 167, 10, 0x60080000 };
BattleList D_800A82A4 = {
    3,
    { &D_800A8244, &D_800A8250, &D_800A825C, &D_800A8268,
      &D_800A8274, &D_800A8280, &D_800A828C, &D_800A8298 },
};
Battle D_800A82C8 = { 0, 0, 0x60040000 };
Battle D_800A82D4 = { 0, 0, 0x60040000 };
Battle D_800A82E0 = { 0, 0, 0x60040000 };
Battle D_800A82EC = { 0, 0, 0x60040000 };
Battle D_800A82F8 = { 0, 0, 0x60040000 };
Battle D_800A8304 = { 0, 0, 0x60040000 };
Battle D_800A8310 = { 0, 0, 0x60040000 };
Battle D_800A831C = { 0, 0, 0x60040000 };
BattleList D_800A8328 = {
    0,
    { &D_800A82C8, &D_800A82D4, &D_800A82E0, &D_800A82EC,
      &D_800A82F8, &D_800A8304, &D_800A8310, &D_800A831C },
};
Battle D_800A834C = { 0, 0, 0x60040000 };
Battle D_800A8358 = { 0, 0, 0x60040000 };
Battle D_800A8364 = { 0, 0, 0x60040000 };
Battle D_800A8370 = { 0, 0, 0x60040000 };
Battle D_800A837C = { 0, 0, 0x60040000 };
Battle D_800A8388 = { 0, 0, 0x60040000 };
Battle D_800A8394 = { 0, 0, 0x60040000 };
Battle D_800A83A0 = { 0, 0, 0x60040000 };
BattleList D_800A83AC = {
    0,
    { &D_800A834C, &D_800A8358, &D_800A8364, &D_800A8370,
      &D_800A837C, &D_800A8388, &D_800A8394, &D_800A83A0 },
};
Battle D_800A83D0 = { 0, 0, 0x60040000 };
Battle D_800A83DC = { 0, 0, 0x60040000 };
Battle D_800A83E8 = { 0, 0, 0x60040000 };
Battle D_800A83F4 = { 0, 0, 0x60040000 };
Battle D_800A8400 = { 0, 0, 0x60040000 };
Battle D_800A840C = { 0, 0, 0x60040000 };
Battle D_800A8418 = { 0, 0, 0x60040000 };
Battle D_800A8424 = { 0, 0, 0x60040000 };
BattleList D_800A8430 = {
    0,
    { &D_800A83D0, &D_800A83DC, &D_800A83E8, &D_800A83F4,
      &D_800A8400, &D_800A840C, &D_800A8418, &D_800A8424 },
};
Battle D_800A8454 = { 74, 10, 0x60080000 };
Battle D_800A8460 = { 77, 10, 0x60080000 };
Battle D_800A846C = { 78, 10, 0x60080000 };
Battle D_800A8478 = { 79, 10, 0x60080000 };
Battle D_800A8484 = { 80, 10, 0x60080000 };
Battle D_800A8490 = { 75, 10, 0x60080000 };
Battle D_800A849C = { 76, 10, 0x60080000 };
Battle D_800A84A8 = { 89, 10, 0x60080000 };
BattleList D_800A84B4 = {
    3,
    { &D_800A8454, &D_800A8460, &D_800A846C, &D_800A8478,
      &D_800A8484, &D_800A8490, &D_800A849C, &D_800A84A8 },
};
Battle D_800A84D8 = { 0, 0, 0x60040000 };
Battle D_800A84E4 = { 0, 0, 0x60040000 };
Battle D_800A84F0 = { 0, 0, 0x60040000 };
Battle D_800A84FC = { 0, 0, 0x60040000 };
Battle D_800A8508 = { 0, 0, 0x60040000 };
Battle D_800A8514 = { 0, 0, 0x60040000 };
Battle D_800A8520 = { 0, 0, 0x60040000 };
Battle D_800A852C = { 0, 0, 0x60040000 };
BattleList D_800A8538 = {
    0,
    { &D_800A84D8, &D_800A84E4, &D_800A84F0, &D_800A84FC,
      &D_800A8508, &D_800A8514, &D_800A8520, &D_800A852C },
};
Battle D_800A855C = { 0, 0, 0x60040000 };
Battle D_800A8568 = { 0, 0, 0x60040000 };
Battle D_800A8574 = { 0, 0, 0x60040000 };
Battle D_800A8580 = { 0, 0, 0x60040000 };
Battle D_800A858C = { 0, 0, 0x60040000 };
Battle D_800A8598 = { 0, 0, 0x60040000 };
Battle D_800A85A4 = { 0, 0, 0x60040000 };
Battle D_800A85B0 = { 0, 0, 0x60040000 };
BattleList D_800A85BC = {
    0,
    { &D_800A855C, &D_800A8568, &D_800A8574, &D_800A8580,
      &D_800A858C, &D_800A8598, &D_800A85A4, &D_800A85B0 },
};
Battle D_800A85E0 = { 0, 0, 0x60040000 };
Battle D_800A85EC = { 0, 0, 0x60040000 };
Battle D_800A85F8 = { 0, 0, 0x60040000 };
Battle D_800A8604 = { 0, 0, 0x60040000 };
Battle D_800A8610 = { 0, 0, 0x60040000 };
Battle D_800A861C = { 0, 0, 0x60040000 };
Battle D_800A8628 = { 0, 0, 0x60040000 };
Battle D_800A8634 = { 0, 0, 0x60040000 };
BattleList D_800A8640 = {
    0,
    { &D_800A85E0, &D_800A85EC, &D_800A85F8, &D_800A8604,
      &D_800A8610, &D_800A861C, &D_800A8628, &D_800A8634 },
};
Battle D_800A8664 = { 162, 10, 0x60080000 };
Battle D_800A8670 = { 162, 10, 0x60080000 };
Battle D_800A867C = { 162, 10, 0x60080000 };
Battle D_800A8688 = { 162, 10, 0x60080000 };
Battle D_800A8694 = { 135, 10, 0x60080000 };
Battle D_800A86A0 = { 135, 10, 0x60080000 };
Battle D_800A86AC = { 135, 10, 0x60080000 };
Battle D_800A86B8 = { 135, 10, 0x60080000 };
BattleList D_800A86C4 = {
    3,
    { &D_800A8664, &D_800A8670, &D_800A867C, &D_800A8688,
      &D_800A8694, &D_800A86A0, &D_800A86AC, &D_800A86B8 },
};
Battle D_800A86E8 = { 0, 0, 0x60040000 };
Battle D_800A86F4 = { 0, 0, 0x60040000 };
Battle D_800A8700 = { 0, 0, 0x60040000 };
Battle D_800A870C = { 0, 0, 0x60040000 };
Battle D_800A8718 = { 0, 0, 0x60040000 };
Battle D_800A8724 = { 0, 0, 0x60040000 };
Battle D_800A8730 = { 0, 0, 0x60040000 };
Battle D_800A873C = { 0, 0, 0x60040000 };
BattleList D_800A8748 = {
    0,
    { &D_800A86E8, &D_800A86F4, &D_800A8700, &D_800A870C,
      &D_800A8718, &D_800A8724, &D_800A8730, &D_800A873C },
};
Battle D_800A876C = { 0, 0, 0x60040000 };
Battle D_800A8778 = { 0, 0, 0x60040000 };
Battle D_800A8784 = { 0, 0, 0x60040000 };
Battle D_800A8790 = { 0, 0, 0x60040000 };
Battle D_800A879C = { 0, 0, 0x60040000 };
Battle D_800A87A8 = { 0, 0, 0x60040000 };
Battle D_800A87B4 = { 0, 0, 0x60040000 };
Battle D_800A87C0 = { 0, 0, 0x60040000 };
BattleList D_800A87CC = {
    0,
    { &D_800A876C, &D_800A8778, &D_800A8784, &D_800A8790,
      &D_800A879C, &D_800A87A8, &D_800A87B4, &D_800A87C0 },
};
Battle D_800A87F0 = { 0, 0, 0x60040000 };
Battle D_800A87FC = { 0, 0, 0x60040000 };
Battle D_800A8808 = { 0, 0, 0x60040000 };
Battle D_800A8814 = { 0, 0, 0x60040000 };
Battle D_800A8820 = { 0, 0, 0x60040000 };
Battle D_800A882C = { 0, 0, 0x60040000 };
Battle D_800A8838 = { 0, 0, 0x60040000 };
Battle D_800A8844 = { 0, 0, 0x60040000 };
BattleList D_800A8850 = {
    0,
    { &D_800A87F0, &D_800A87FC, &D_800A8808, &D_800A8814,
      &D_800A8820, &D_800A882C, &D_800A8838, &D_800A8844 },
};
FieldBattles stageBattles[] = {
    { 417, 1, 0, { &D_800A7C74, &D_800A7CF8, &D_800A7D7C, &D_800A7E00 } },
    { 422, 2, 0, { &D_800A7E84, &D_800A7F08, &D_800A7F8C, &D_800A8010 } },
    { 428, 3, 0, { &D_800A8094, &D_800A8118, &D_800A819C, &D_800A8220 } },
    { 434, 4, 0, { &D_800A82A4, &D_800A8328, &D_800A83AC, &D_800A8430 } },
    { 440, 5, 0, { &D_800A84B4, &D_800A8538, &D_800A85BC, &D_800A8640 } },
    { 446, 6, 0, { &D_800A86C4, &D_800A8748, &D_800A87CC, &D_800A8850 } },
};
