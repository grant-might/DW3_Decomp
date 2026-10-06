#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x67C
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x68C
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x20000, 0xB900};
    D_800990B4.images.actors = stageImages;
    D_800990B4.soundBank = 0x1E;
    D_800990B4.music = 0x60780000;
    D_800990B4.startDir = 0;
    D_800990B4.actors = stageActors;
    D_800990B4.battles = D_800990B4.findBattles(stageBattles, GAME.unk44);
    D_8009A70C.setFile(0, STAGE_FILE << 16 | 1);
    D_8009A70C.setFile(7, STAGE_FILE << 16 | 2);
    D_8009A70C.setFile(4, STAGE_FILE << 16 | 3);
    D_8009A70C.unk50(0);
}

extern StagePoint D_800A4F8C;
extern StagePoint D_800A4FA4;
extern StagePoint D_800A4FBC;
extern StagePoint D_800A4FD4;
extern StagePoint D_800A4FEC;
extern StagePoint D_800A5004;
extern StagePoint D_800A501C;
extern StagePoint D_800A5034;
extern StagePoint D_800A504C;
extern StagePoint D_800A5064;
extern StagePoint D_800A507C;
extern StagePoint D_800A5094;
extern StagePoint D_800A50AC;
extern StagePoint D_800A50C4;
extern StagePoint D_800A50DC;
extern StagePoint D_800A50F4;
extern StagePoint D_800A510C;
extern StagePoint D_800A5124;
extern StagePoint D_800A513C;
extern StagePoint D_800A5154;
extern StagePoint D_800A516C;
extern StagePoint D_800A5184;
extern StagePoint D_800A519C;
extern StagePoint D_800A51B4;
extern StagePoint D_800A51CC;
extern StagePoints D_800A4F9C;
extern StagePoints D_800A4FB4;
extern StagePoints D_800A4FCC;
extern StagePoints D_800A4FE4;
extern StagePoints D_800A4FFC;
extern StagePoints D_800A5014;
extern StagePoints D_800A502C;
extern StagePoints D_800A5044;
extern StagePoints D_800A505C;
extern StagePoints D_800A5074;
extern StagePoints D_800A508C;
extern StagePoints D_800A50A4;
extern StagePoints D_800A50BC;
extern StagePoints D_800A50D4;
extern StagePoints D_800A50EC;
extern StagePoints D_800A5104;
extern StagePoints D_800A511C;
extern StagePoints D_800A5134;
extern StagePoints D_800A514C;
extern StagePoints D_800A5164;
extern StagePoints D_800A517C;
extern StagePoints D_800A5194;
extern StagePoints D_800A51AC;
extern StagePoints D_800A51C4;
extern StagePoints D_800A51DC;
extern Battle D_800A524C;
extern Battle D_800A5258;
extern Battle D_800A5264;
extern Battle D_800A5270;
extern Battle D_800A527C;
extern Battle D_800A5288;
extern Battle D_800A5294;
extern Battle D_800A52A0;
extern Battle D_800A52D0;
extern Battle D_800A52DC;
extern Battle D_800A52E8;
extern Battle D_800A52F4;
extern Battle D_800A5300;
extern Battle D_800A530C;
extern Battle D_800A5318;
extern Battle D_800A5324;
extern Battle D_800A5354;
extern Battle D_800A5360;
extern Battle D_800A536C;
extern Battle D_800A5378;
extern Battle D_800A5384;
extern Battle D_800A5390;
extern Battle D_800A539C;
extern Battle D_800A53A8;
extern Battle D_800A53D8;
extern Battle D_800A53E4;
extern Battle D_800A53F0;
extern Battle D_800A53FC;
extern Battle D_800A5408;
extern Battle D_800A5414;
extern Battle D_800A5420;
extern Battle D_800A542C;
extern Battle D_800A545C;
extern Battle D_800A5468;
extern Battle D_800A5474;
extern Battle D_800A5480;
extern Battle D_800A548C;
extern Battle D_800A5498;
extern Battle D_800A54A4;
extern Battle D_800A54B0;
extern Battle D_800A54E0;
extern Battle D_800A54EC;
extern Battle D_800A54F8;
extern Battle D_800A5504;
extern Battle D_800A5510;
extern Battle D_800A551C;
extern Battle D_800A5528;
extern Battle D_800A5534;
extern Battle D_800A5564;
extern Battle D_800A5570;
extern Battle D_800A557C;
extern Battle D_800A5588;
extern Battle D_800A5594;
extern Battle D_800A55A0;
extern Battle D_800A55AC;
extern Battle D_800A55B8;
extern Battle D_800A55E8;
extern Battle D_800A55F4;
extern Battle D_800A5600;
extern Battle D_800A560C;
extern Battle D_800A5618;
extern Battle D_800A5624;
extern Battle D_800A5630;
extern Battle D_800A563C;
extern Battle D_800A566C;
extern Battle D_800A5678;
extern Battle D_800A5684;
extern Battle D_800A5690;
extern Battle D_800A569C;
extern Battle D_800A56A8;
extern Battle D_800A56B4;
extern Battle D_800A56C0;
extern Battle D_800A56F0;
extern Battle D_800A56FC;
extern Battle D_800A5708;
extern Battle D_800A5714;
extern Battle D_800A5720;
extern Battle D_800A572C;
extern Battle D_800A5738;
extern Battle D_800A5744;
extern Battle D_800A5774;
extern Battle D_800A5780;
extern Battle D_800A578C;
extern Battle D_800A5798;
extern Battle D_800A57A4;
extern Battle D_800A57B0;
extern Battle D_800A57BC;
extern Battle D_800A57C8;
extern Battle D_800A57F8;
extern Battle D_800A5804;
extern Battle D_800A5810;
extern Battle D_800A581C;
extern Battle D_800A5828;
extern Battle D_800A5834;
extern Battle D_800A5840;
extern Battle D_800A584C;
extern Battle D_800A587C;
extern Battle D_800A5888;
extern Battle D_800A5894;
extern Battle D_800A58A0;
extern Battle D_800A58AC;
extern Battle D_800A58B8;
extern Battle D_800A58C4;
extern Battle D_800A58D0;
extern Battle D_800A5900;
extern Battle D_800A590C;
extern Battle D_800A5918;
extern Battle D_800A5924;
extern Battle D_800A5930;
extern Battle D_800A593C;
extern Battle D_800A5948;
extern Battle D_800A5954;
extern Battle D_800A5984;
extern Battle D_800A5990;
extern Battle D_800A599C;
extern Battle D_800A59A8;
extern Battle D_800A59B4;
extern Battle D_800A59C0;
extern Battle D_800A59CC;
extern Battle D_800A59D8;
extern Battle D_800A5A08;
extern Battle D_800A5A14;
extern Battle D_800A5A20;
extern Battle D_800A5A2C;
extern Battle D_800A5A38;
extern Battle D_800A5A44;
extern Battle D_800A5A50;
extern Battle D_800A5A5C;
extern Battle D_800A5A8C;
extern Battle D_800A5A98;
extern Battle D_800A5AA4;
extern Battle D_800A5AB0;
extern Battle D_800A5ABC;
extern Battle D_800A5AC8;
extern Battle D_800A5AD4;
extern Battle D_800A5AE0;
extern Battle D_800A5B10;
extern Battle D_800A5B1C;
extern Battle D_800A5B28;
extern Battle D_800A5B34;
extern Battle D_800A5B40;
extern Battle D_800A5B4C;
extern Battle D_800A5B58;
extern Battle D_800A5B64;
extern Battle D_800A5B94;
extern Battle D_800A5BA0;
extern Battle D_800A5BAC;
extern Battle D_800A5BB8;
extern Battle D_800A5BC4;
extern Battle D_800A5BD0;
extern Battle D_800A5BDC;
extern Battle D_800A5BE8;
extern Battle D_800A5C18;
extern Battle D_800A5C24;
extern Battle D_800A5C30;
extern Battle D_800A5C3C;
extern Battle D_800A5C48;
extern Battle D_800A5C54;
extern Battle D_800A5C60;
extern Battle D_800A5C6C;
extern Battle D_800A5C9C;
extern Battle D_800A5CA8;
extern Battle D_800A5CB4;
extern Battle D_800A5CC0;
extern Battle D_800A5CCC;
extern Battle D_800A5CD8;
extern Battle D_800A5CE4;
extern Battle D_800A5CF0;
extern Battle D_800A5D20;
extern Battle D_800A5D2C;
extern Battle D_800A5D38;
extern Battle D_800A5D44;
extern Battle D_800A5D50;
extern Battle D_800A5D5C;
extern Battle D_800A5D68;
extern Battle D_800A5D74;
extern Battle D_800A5DA4;
extern Battle D_800A5DB0;
extern Battle D_800A5DBC;
extern Battle D_800A5DC8;
extern Battle D_800A5DD4;
extern Battle D_800A5DE0;
extern Battle D_800A5DEC;
extern Battle D_800A5DF8;
extern Battle D_800A5E28;
extern Battle D_800A5E34;
extern Battle D_800A5E40;
extern Battle D_800A5E4C;
extern Battle D_800A5E58;
extern Battle D_800A5E64;
extern Battle D_800A5E70;
extern Battle D_800A5E7C;
extern Battle D_800A5EAC;
extern Battle D_800A5EB8;
extern Battle D_800A5EC4;
extern Battle D_800A5ED0;
extern Battle D_800A5EDC;
extern Battle D_800A5EE8;
extern Battle D_800A5EF4;
extern Battle D_800A5F00;
extern Battle D_800A5F30;
extern Battle D_800A5F3C;
extern Battle D_800A5F48;
extern Battle D_800A5F54;
extern Battle D_800A5F60;
extern Battle D_800A5F6C;
extern Battle D_800A5F78;
extern Battle D_800A5F84;
extern Battle D_800A5FB4;
extern Battle D_800A5FC0;
extern Battle D_800A5FCC;
extern Battle D_800A5FD8;
extern Battle D_800A5FE4;
extern Battle D_800A5FF0;
extern Battle D_800A5FFC;
extern Battle D_800A6008;
extern Battle D_800A6038;
extern Battle D_800A6044;
extern Battle D_800A6050;
extern Battle D_800A605C;
extern Battle D_800A6068;
extern Battle D_800A6074;
extern Battle D_800A6080;
extern Battle D_800A608C;
extern Battle D_800A60BC;
extern Battle D_800A60C8;
extern Battle D_800A60D4;
extern Battle D_800A60E0;
extern Battle D_800A60EC;
extern Battle D_800A60F8;
extern Battle D_800A6104;
extern Battle D_800A6110;
extern Battle D_800A6140;
extern Battle D_800A614C;
extern Battle D_800A6158;
extern Battle D_800A6164;
extern Battle D_800A6170;
extern Battle D_800A617C;
extern Battle D_800A6188;
extern Battle D_800A6194;
extern Battle D_800A61C4;
extern Battle D_800A61D0;
extern Battle D_800A61DC;
extern Battle D_800A61E8;
extern Battle D_800A61F4;
extern Battle D_800A6200;
extern Battle D_800A620C;
extern Battle D_800A6218;
extern Battle D_800A6248;
extern Battle D_800A6254;
extern Battle D_800A6260;
extern Battle D_800A626C;
extern Battle D_800A6278;
extern Battle D_800A6284;
extern Battle D_800A6290;
extern Battle D_800A629C;
extern Battle D_800A62CC;
extern Battle D_800A62D8;
extern Battle D_800A62E4;
extern Battle D_800A62F0;
extern Battle D_800A62FC;
extern Battle D_800A6308;
extern Battle D_800A6314;
extern Battle D_800A6320;
extern Battle D_800A6350;
extern Battle D_800A635C;
extern Battle D_800A6368;
extern Battle D_800A6374;
extern Battle D_800A6380;
extern Battle D_800A638C;
extern Battle D_800A6398;
extern Battle D_800A63A4;
extern Battle D_800A63D4;
extern Battle D_800A63E0;
extern Battle D_800A63EC;
extern Battle D_800A63F8;
extern Battle D_800A6404;
extern Battle D_800A6410;
extern Battle D_800A641C;
extern Battle D_800A6428;
extern Battle D_800A6458;
extern Battle D_800A6464;
extern Battle D_800A6470;
extern Battle D_800A647C;
extern Battle D_800A6488;
extern Battle D_800A6494;
extern Battle D_800A64A0;
extern Battle D_800A64AC;
extern Battle D_800A64DC;
extern Battle D_800A64E8;
extern Battle D_800A64F4;
extern Battle D_800A6500;
extern Battle D_800A650C;
extern Battle D_800A6518;
extern Battle D_800A6524;
extern Battle D_800A6530;
extern Battle D_800A6560;
extern Battle D_800A656C;
extern Battle D_800A6578;
extern Battle D_800A6584;
extern Battle D_800A6590;
extern Battle D_800A659C;
extern Battle D_800A65A8;
extern Battle D_800A65B4;
extern Battle D_800A65E4;
extern Battle D_800A65F0;
extern Battle D_800A65FC;
extern Battle D_800A6608;
extern Battle D_800A6614;
extern Battle D_800A6620;
extern Battle D_800A662C;
extern Battle D_800A6638;
extern Battle D_800A6668;
extern Battle D_800A6674;
extern Battle D_800A6680;
extern Battle D_800A668C;
extern Battle D_800A6698;
extern Battle D_800A66A4;
extern Battle D_800A66B0;
extern Battle D_800A66BC;
extern Battle D_800A66EC;
extern Battle D_800A66F8;
extern Battle D_800A6704;
extern Battle D_800A6710;
extern Battle D_800A671C;
extern Battle D_800A6728;
extern Battle D_800A6734;
extern Battle D_800A6740;
extern Battle D_800A6770;
extern Battle D_800A677C;
extern Battle D_800A6788;
extern Battle D_800A6794;
extern Battle D_800A67A0;
extern Battle D_800A67AC;
extern Battle D_800A67B8;
extern Battle D_800A67C4;
extern Battle D_800A67F4;
extern Battle D_800A6800;
extern Battle D_800A680C;
extern Battle D_800A6818;
extern Battle D_800A6824;
extern Battle D_800A6830;
extern Battle D_800A683C;
extern Battle D_800A6848;
extern Battle D_800A6878;
extern Battle D_800A6884;
extern Battle D_800A6890;
extern Battle D_800A689C;
extern Battle D_800A68A8;
extern Battle D_800A68B4;
extern Battle D_800A68C0;
extern Battle D_800A68CC;
extern Battle D_800A68FC;
extern Battle D_800A6908;
extern Battle D_800A6914;
extern Battle D_800A6920;
extern Battle D_800A692C;
extern Battle D_800A6938;
extern Battle D_800A6944;
extern Battle D_800A6950;
extern Battle D_800A6980;
extern Battle D_800A698C;
extern Battle D_800A6998;
extern Battle D_800A69A4;
extern Battle D_800A69B0;
extern Battle D_800A69BC;
extern Battle D_800A69C8;
extern Battle D_800A69D4;
extern Battle D_800A6A04;
extern Battle D_800A6A10;
extern Battle D_800A6A1C;
extern Battle D_800A6A28;
extern Battle D_800A6A34;
extern Battle D_800A6A40;
extern Battle D_800A6A4C;
extern Battle D_800A6A58;
extern Battle D_800A6A88;
extern Battle D_800A6A94;
extern Battle D_800A6AA0;
extern Battle D_800A6AAC;
extern Battle D_800A6AB8;
extern Battle D_800A6AC4;
extern Battle D_800A6AD0;
extern Battle D_800A6ADC;
extern Battle D_800A6B0C;
extern Battle D_800A6B18;
extern Battle D_800A6B24;
extern Battle D_800A6B30;
extern Battle D_800A6B3C;
extern Battle D_800A6B48;
extern Battle D_800A6B54;
extern Battle D_800A6B60;
extern Battle D_800A6B90;
extern Battle D_800A6B9C;
extern Battle D_800A6BA8;
extern Battle D_800A6BB4;
extern Battle D_800A6BC0;
extern Battle D_800A6BCC;
extern Battle D_800A6BD8;
extern Battle D_800A6BE4;
extern Battle D_800A6C14;
extern Battle D_800A6C20;
extern Battle D_800A6C2C;
extern Battle D_800A6C38;
extern Battle D_800A6C44;
extern Battle D_800A6C50;
extern Battle D_800A6C5C;
extern Battle D_800A6C68;
extern Battle D_800A6C98;
extern Battle D_800A6CA4;
extern Battle D_800A6CB0;
extern Battle D_800A6CBC;
extern Battle D_800A6CC8;
extern Battle D_800A6CD4;
extern Battle D_800A6CE0;
extern Battle D_800A6CEC;
extern Battle D_800A6D1C;
extern Battle D_800A6D28;
extern Battle D_800A6D34;
extern Battle D_800A6D40;
extern Battle D_800A6D4C;
extern Battle D_800A6D58;
extern Battle D_800A6D64;
extern Battle D_800A6D70;
extern Battle D_800A6DA0;
extern Battle D_800A6DAC;
extern Battle D_800A6DB8;
extern Battle D_800A6DC4;
extern Battle D_800A6DD0;
extern Battle D_800A6DDC;
extern Battle D_800A6DE8;
extern Battle D_800A6DF4;
extern Battle D_800A6E24;
extern Battle D_800A6E30;
extern Battle D_800A6E3C;
extern Battle D_800A6E48;
extern Battle D_800A6E54;
extern Battle D_800A6E60;
extern Battle D_800A6E6C;
extern Battle D_800A6E78;
extern Battle D_800A6EA8;
extern Battle D_800A6EB4;
extern Battle D_800A6EC0;
extern Battle D_800A6ECC;
extern Battle D_800A6ED8;
extern Battle D_800A6EE4;
extern Battle D_800A6EF0;
extern Battle D_800A6EFC;
extern Battle D_800A6F2C;
extern Battle D_800A6F38;
extern Battle D_800A6F44;
extern Battle D_800A6F50;
extern Battle D_800A6F5C;
extern Battle D_800A6F68;
extern Battle D_800A6F74;
extern Battle D_800A6F80;
extern Battle D_800A6FB0;
extern Battle D_800A6FBC;
extern Battle D_800A6FC8;
extern Battle D_800A6FD4;
extern Battle D_800A6FE0;
extern Battle D_800A6FEC;
extern Battle D_800A6FF8;
extern Battle D_800A7004;
extern Battle D_800A7034;
extern Battle D_800A7040;
extern Battle D_800A704C;
extern Battle D_800A7058;
extern Battle D_800A7064;
extern Battle D_800A7070;
extern Battle D_800A707C;
extern Battle D_800A7088;
extern Battle D_800A70B8;
extern Battle D_800A70C4;
extern Battle D_800A70D0;
extern Battle D_800A70DC;
extern Battle D_800A70E8;
extern Battle D_800A70F4;
extern Battle D_800A7100;
extern Battle D_800A710C;
extern Battle D_800A713C;
extern Battle D_800A7148;
extern Battle D_800A7154;
extern Battle D_800A7160;
extern Battle D_800A716C;
extern Battle D_800A7178;
extern Battle D_800A7184;
extern Battle D_800A7190;
extern Battle D_800A71C0;
extern Battle D_800A71CC;
extern Battle D_800A71D8;
extern Battle D_800A71E4;
extern Battle D_800A71F0;
extern Battle D_800A71FC;
extern Battle D_800A7208;
extern Battle D_800A7214;
extern Battle D_800A7244;
extern Battle D_800A7250;
extern Battle D_800A725C;
extern Battle D_800A7268;
extern Battle D_800A7274;
extern Battle D_800A7280;
extern Battle D_800A728C;
extern Battle D_800A7298;
extern Battle D_800A72C8;
extern Battle D_800A72D4;
extern Battle D_800A72E0;
extern Battle D_800A72EC;
extern Battle D_800A72F8;
extern Battle D_800A7304;
extern Battle D_800A7310;
extern Battle D_800A731C;
extern Battle D_800A734C;
extern Battle D_800A7358;
extern Battle D_800A7364;
extern Battle D_800A7370;
extern Battle D_800A737C;
extern Battle D_800A7388;
extern Battle D_800A7394;
extern Battle D_800A73A0;
extern Battle D_800A73D0;
extern Battle D_800A73DC;
extern Battle D_800A73E8;
extern Battle D_800A73F4;
extern Battle D_800A7400;
extern Battle D_800A740C;
extern Battle D_800A7418;
extern Battle D_800A7424;
extern Battle D_800A7454;
extern Battle D_800A7460;
extern Battle D_800A746C;
extern Battle D_800A7478;
extern Battle D_800A7484;
extern Battle D_800A7490;
extern Battle D_800A749C;
extern Battle D_800A74A8;
extern Battle D_800A74D8;
extern Battle D_800A74E4;
extern Battle D_800A74F0;
extern Battle D_800A74FC;
extern Battle D_800A7508;
extern Battle D_800A7514;
extern Battle D_800A7520;
extern Battle D_800A752C;
extern BattleList D_800A52AC;
extern BattleList D_800A5330;
extern BattleList D_800A53B4;
extern BattleList D_800A5438;
extern BattleList D_800A54BC;
extern BattleList D_800A5540;
extern BattleList D_800A55C4;
extern BattleList D_800A5648;
extern BattleList D_800A56CC;
extern BattleList D_800A5750;
extern BattleList D_800A57D4;
extern BattleList D_800A5858;
extern BattleList D_800A58DC;
extern BattleList D_800A5960;
extern BattleList D_800A59E4;
extern BattleList D_800A5A68;
extern BattleList D_800A5AEC;
extern BattleList D_800A5B70;
extern BattleList D_800A5BF4;
extern BattleList D_800A5C78;
extern BattleList D_800A5CFC;
extern BattleList D_800A5D80;
extern BattleList D_800A5E04;
extern BattleList D_800A5E88;
extern BattleList D_800A5F0C;
extern BattleList D_800A5F90;
extern BattleList D_800A6014;
extern BattleList D_800A6098;
extern BattleList D_800A611C;
extern BattleList D_800A61A0;
extern BattleList D_800A6224;
extern BattleList D_800A62A8;
extern BattleList D_800A632C;
extern BattleList D_800A63B0;
extern BattleList D_800A6434;
extern BattleList D_800A64B8;
extern BattleList D_800A653C;
extern BattleList D_800A65C0;
extern BattleList D_800A6644;
extern BattleList D_800A66C8;
extern BattleList D_800A674C;
extern BattleList D_800A67D0;
extern BattleList D_800A6854;
extern BattleList D_800A68D8;
extern BattleList D_800A695C;
extern BattleList D_800A69E0;
extern BattleList D_800A6A64;
extern BattleList D_800A6AE8;
extern BattleList D_800A6B6C;
extern BattleList D_800A6BF0;
extern BattleList D_800A6C74;
extern BattleList D_800A6CF8;
extern BattleList D_800A6D7C;
extern BattleList D_800A6E00;
extern BattleList D_800A6E84;
extern BattleList D_800A6F08;
extern BattleList D_800A6F8C;
extern BattleList D_800A7010;
extern BattleList D_800A7094;
extern BattleList D_800A7118;
extern BattleList D_800A719C;
extern BattleList D_800A7220;
extern BattleList D_800A72A4;
extern BattleList D_800A7328;
extern BattleList D_800A73AC;
extern BattleList D_800A7430;
extern BattleList D_800A74B4;
extern BattleList D_800A7538;
extern u16 D_800A7858[];
extern u16 D_800A7864[];
extern u16 D_800A786C[];
extern u16 D_800A7878[];
extern u16 D_800A7884[];
extern u16 D_800A788C[];
extern u16 D_800A7898[];
extern u16 D_800A78A8[];
extern u16 D_800A78B4[];
extern u16 D_800A78BC[];
extern u16 D_800A78C8[];
extern u16 D_800A78D4[];
extern u16 D_800A78DC[];
extern u16 D_800A78E8[];
extern u16 D_800A78FC[];
extern u16 D_800A7908[];
extern u16 D_800A7910[];
extern u16 D_800A791C[];
extern u16 D_800A7928[];
extern u16 D_800A7930[];
extern u16 D_800A793C[];
extern u16 D_800A794C[];
extern u16 D_800A7958[];
extern u16 D_800A7960[];
extern u16 D_800A796C[];
extern u16 D_800A7978[];
extern u16 D_800A7980[];
extern u16 D_800A798C[];
extern u16 D_800A799C[];
extern u16 D_800A79A8[];
extern u16 D_800A79B0[];
extern u16 D_800A79BC[];
extern u16 D_800A79C8[];
extern u16 D_800A79D0[];
extern u16 D_800A79DC[];
extern u16 D_800A79EC[];
extern u16 D_800A79F8[];
extern u16 D_800A7A00[];
extern u16 D_800A7A0C[];
extern u16 D_800A7A18[];
extern u16 D_800A7A20[];
extern u16 D_800A7A2C[];
extern u16 D_800A7A3C[];
extern u16 D_800A7A48[];
extern u16 D_800A7A50[];
extern u16 D_800A7A5C[];
extern u16 D_800A7A68[];
extern u16 D_800A7A70[];
extern u16 D_800A7A7C[];
extern u16 D_800A7A8C[];
extern u16 D_800A7A98[];
extern u16 D_800A7AA0[];
extern u16 D_800A7AAC[];
extern u16 D_800A7AB8[];
extern u16 D_800A7AC0[];
extern u16 D_800A7ACC[];
extern u16 D_800A7CBC[];
extern u16 D_800A7CC8[];
extern FieldTalk D_800A7ADC[];
extern u16 D_800A7CDC[];
extern FieldTalk D_800A7B18[];
extern u16 D_800A7CF0[];
extern FieldTalk D_800A7B54[];
extern u16 D_800A7D04[];
extern FieldTalk D_800A7B90[];
extern u16 D_800A7D18[];
extern FieldTalk D_800A7BCC[];
extern u16 D_800A7D2C[];
extern FieldTalk D_800A7C08[];
extern u16 D_800A7D40[];
extern FieldTalk D_800A7C44[];
extern u16 D_800A7D54[];
extern FieldTalk D_800A7C80[];
extern u16 D_800A7D68[];
extern u16 D_800A7D74[];
extern u16 D_800A7D80[];
extern u16 D_800A7D8C[];
extern u16 D_800A7D98[];
extern u16 D_800A7DA4[];
extern u16 D_800A7DB0[];
extern u16 D_800A7DBC[];
extern u16 D_800A7DC8[];
extern u16 D_800A7DD4[];
extern u16 D_800A7DE0[];
extern FieldActorEntry D_800A7DEC;
extern FieldActorEntry D_800A7E00;
extern FieldActorEntry D_800A7E14;
extern FieldActorEntry D_800A7E28;
extern FieldActorEntry D_800A7E3C;
extern FieldActorEntry D_800A7E50;
extern FieldActorEntry D_800A7E64;
extern FieldActorEntry D_800A7E78;
extern FieldActorEntry D_800A7E8C;
extern FieldActorEntry D_800A7EA0;
extern FieldActorEntry D_800A7EB4;
extern FieldActorEntry D_800A7EC8;
extern FieldActorEntry D_800A7EDC;
extern FieldActorEntry D_800A7EF0;
extern FieldActorEntry D_800A7F04;
extern FieldActorEntry D_800A7F18;
extern FieldActorEntry D_800A7F2C;
extern FieldActorEntry D_800A7F40;
extern FieldActorEntry D_800A7F54;
extern FieldActorEntry D_800A7F68;
extern FieldActorEntry D_800A7F7C;

StagePoint D_800A4F8C = { 0x2ED, 2, 1, 0x3A0, 128, 1, NULL };
StagePoints D_800A4F9C = { 2, 1, &D_800A4F8C };
StagePoint D_800A4FA4 = { 0x2EE, 2, 2, 0x130, 200, 1, NULL };
StagePoints D_800A4FB4 = { 2, 2, &D_800A4FA4 };
StagePoint D_800A4FBC = { 0x2EE, 4, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoints D_800A4FCC = { 4, 1, &D_800A4FBC };
StagePoint D_800A4FD4 = { 0x2ED, 5, 1, 0x3A0, 128, 1, NULL };
StagePoints D_800A4FE4 = { 5, 1, &D_800A4FD4 };
StagePoint D_800A4FEC = { 0x2EC, 6, 1, 0x3B0, 120, 1, NULL };
StagePoints D_800A4FFC = { 6, 1, &D_800A4FEC };
StagePoint D_800A5004 = { 0x2ED, 6, 2, 0x3A0, 128, 1, NULL };
StagePoints D_800A5014 = { 6, 2, &D_800A5004 };
StagePoint D_800A501C = { 0x2ED, 9, 1, 0x3A0, 128, 1, NULL };
StagePoints D_800A502C = { 9, 1, &D_800A501C };
StagePoint D_800A5034 = { 0x2EE, 9, 2, 0x130, 200, 1, NULL };
StagePoints D_800A5044 = { 9, 2, &D_800A5034 };
StagePoint D_800A504C = { 0x2EC, 12, 1, 0x3B0, 120, 1, NULL };
StagePoints D_800A505C = { 12, 1, &D_800A504C };
StagePoint D_800A5064 = { 0x2EC, 12, 2, 0x3B0, 120, 1, NULL };
StagePoints D_800A5074 = { 12, 2, &D_800A5064 };
StagePoint D_800A507C = { 0x2EC, 13, 1, 0x3B0, 120, 1, NULL };
StagePoints D_800A508C = { 13, 1, &D_800A507C };
StagePoint D_800A5094 = { 0x2ED, 13, 1, 0x3A0, 128, 1, NULL };
StagePoints D_800A50A4 = { 13, 2, &D_800A5094 };
StagePoint D_800A50AC = { 0x2ED, 14, 1, 0x3A0, 128, 1, NULL };
StagePoints D_800A50BC = { 14, 1, &D_800A50AC };
StagePoint D_800A50C4 = { 0x2EE, 16, 1, 0x130, 200, 1, NULL };
StagePoints D_800A50D4 = { 16, 1, &D_800A50C4 };
StagePoint D_800A50DC = { 0x2EC, 19, 1, 0x3B0, 120, 1, NULL };
StagePoints D_800A50EC = { 19, 1, &D_800A50DC };
StagePoint D_800A50F4 = { 0x2EE, 19, 1, 0x130, 200, 1, NULL };
StagePoints D_800A5104 = { 19, 2, &D_800A50F4 };
StagePoint D_800A510C = { 0x2EE, 20, 1, 0x130, 200, 1, NULL };
StagePoints D_800A511C = { 20, 1, &D_800A510C };
StagePoint D_800A5124 = { 0x2EC, 20, 1, 0x3B0, 120, 1, NULL };
StagePoints D_800A5134 = { 20, 2, &D_800A5124 };
StagePoint D_800A513C = { 0x2EC, 21, 1, 0x3B0, 120, 1, NULL };
StagePoints D_800A514C = { 21, 1, &D_800A513C };
StagePoint D_800A5154 = { 0x2EE, 25, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoints D_800A5164 = { 25, 1, &D_800A5154 };
StagePoint D_800A516C = { 0x2ED, 27, 1, 0x3A0, 128, 1, NULL };
StagePoints D_800A517C = { 27, 1, &D_800A516C };
StagePoint D_800A5184 = { 0x2EC, 28, 1, 0x3B0, 120, 1, NULL };
StagePoints D_800A5194 = { 28, 1, &D_800A5184 };
StagePoint D_800A519C = { 0x2EC, 28, 2, 0x3B0, 120, 1, NULL };
StagePoints D_800A51AC = { 28, 2, &D_800A519C };
StagePoint D_800A51B4 = { 0x2EC, 29, 2, 0x3B0, 120, 1, NULL };
StagePoints D_800A51C4 = { 29, 1, &D_800A51B4 };
StagePoint D_800A51CC = { 0x2EE, 30, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoints D_800A51DC = { 30, 1, &D_800A51CC };
StagePoints *placePoints[] = {
    &D_800A4F9C, &D_800A4FB4, &D_800A4FCC, &D_800A4FE4,
    &D_800A4FFC, &D_800A5014, &D_800A502C, &D_800A5044,
    &D_800A505C, &D_800A5074, &D_800A508C, &D_800A50A4,
    &D_800A50BC, &D_800A50D4, &D_800A50EC, &D_800A5104,
    &D_800A511C, &D_800A5134, &D_800A514C, &D_800A5164,
    &D_800A517C, &D_800A5194, &D_800A51AC, &D_800A51C4,
    &D_800A51DC, NULL,
};
Battle D_800A524C = { 174, 10, 0x60080000 };
Battle D_800A5258 = { 174, 10, 0x60080000 };
Battle D_800A5264 = { 170, 10, 0x60080000 };
Battle D_800A5270 = { 170, 10, 0x60080000 };
Battle D_800A527C = { 170, 10, 0x60080000 };
Battle D_800A5288 = { 110, 10, 0x60080000 };
Battle D_800A5294 = { 110, 10, 0x60080000 };
Battle D_800A52A0 = { 110, 10, 0x60080000 };
BattleList D_800A52AC = {
    1,
    { &D_800A524C, &D_800A5258, &D_800A5264, &D_800A5270,
      &D_800A527C, &D_800A5288, &D_800A5294, &D_800A52A0 },
};
Battle D_800A52D0 = { 0, 0, 0x60040000 };
Battle D_800A52DC = { 0, 0, 0x60040000 };
Battle D_800A52E8 = { 0, 0, 0x60040000 };
Battle D_800A52F4 = { 0, 0, 0x60040000 };
Battle D_800A5300 = { 0, 0, 0x60040000 };
Battle D_800A530C = { 0, 0, 0x60040000 };
Battle D_800A5318 = { 0, 0, 0x60040000 };
Battle D_800A5324 = { 0, 0, 0x60040000 };
BattleList D_800A5330 = {
    0,
    { &D_800A52D0, &D_800A52DC, &D_800A52E8, &D_800A52F4,
      &D_800A5300, &D_800A530C, &D_800A5318, &D_800A5324 },
};
Battle D_800A5354 = { 0, 0, 0x60040000 };
Battle D_800A5360 = { 0, 0, 0x60040000 };
Battle D_800A536C = { 0, 0, 0x60040000 };
Battle D_800A5378 = { 0, 0, 0x60040000 };
Battle D_800A5384 = { 0, 0, 0x60040000 };
Battle D_800A5390 = { 0, 0, 0x60040000 };
Battle D_800A539C = { 0, 0, 0x60040000 };
Battle D_800A53A8 = { 0, 0, 0x60040000 };
BattleList D_800A53B4 = {
    0,
    { &D_800A5354, &D_800A5360, &D_800A536C, &D_800A5378,
      &D_800A5384, &D_800A5390, &D_800A539C, &D_800A53A8 },
};
Battle D_800A53D8 = { 0, 0, 0x60040000 };
Battle D_800A53E4 = { 0, 0, 0x60040000 };
Battle D_800A53F0 = { 0, 0, 0x60040000 };
Battle D_800A53FC = { 0, 0, 0x60040000 };
Battle D_800A5408 = { 0, 0, 0x60040000 };
Battle D_800A5414 = { 0, 0, 0x60040000 };
Battle D_800A5420 = { 0, 0, 0x60040000 };
Battle D_800A542C = { 0, 0, 0x60040000 };
BattleList D_800A5438 = {
    0,
    { &D_800A53D8, &D_800A53E4, &D_800A53F0, &D_800A53FC,
      &D_800A5408, &D_800A5414, &D_800A5420, &D_800A542C },
};
Battle D_800A545C = { 174, 10, 0x60080000 };
Battle D_800A5468 = { 174, 10, 0x60080000 };
Battle D_800A5474 = { 170, 10, 0x60080000 };
Battle D_800A5480 = { 170, 10, 0x60080000 };
Battle D_800A548C = { 182, 10, 0x60080000 };
Battle D_800A5498 = { 182, 10, 0x60080000 };
Battle D_800A54A4 = { 71, 10, 0x60080000 };
Battle D_800A54B0 = { 71, 10, 0x60080000 };
BattleList D_800A54BC = {
    1,
    { &D_800A545C, &D_800A5468, &D_800A5474, &D_800A5480,
      &D_800A548C, &D_800A5498, &D_800A54A4, &D_800A54B0 },
};
Battle D_800A54E0 = { 0, 0, 0x60040000 };
Battle D_800A54EC = { 0, 0, 0x60040000 };
Battle D_800A54F8 = { 0, 0, 0x60040000 };
Battle D_800A5504 = { 0, 0, 0x60040000 };
Battle D_800A5510 = { 0, 0, 0x60040000 };
Battle D_800A551C = { 0, 0, 0x60040000 };
Battle D_800A5528 = { 0, 0, 0x60040000 };
Battle D_800A5534 = { 0, 0, 0x60040000 };
BattleList D_800A5540 = {
    0,
    { &D_800A54E0, &D_800A54EC, &D_800A54F8, &D_800A5504,
      &D_800A5510, &D_800A551C, &D_800A5528, &D_800A5534 },
};
Battle D_800A5564 = { 0, 0, 0x60040000 };
Battle D_800A5570 = { 0, 0, 0x60040000 };
Battle D_800A557C = { 0, 0, 0x60040000 };
Battle D_800A5588 = { 0, 0, 0x60040000 };
Battle D_800A5594 = { 0, 0, 0x60040000 };
Battle D_800A55A0 = { 0, 0, 0x60040000 };
Battle D_800A55AC = { 0, 0, 0x60040000 };
Battle D_800A55B8 = { 0, 0, 0x60040000 };
BattleList D_800A55C4 = {
    0,
    { &D_800A5564, &D_800A5570, &D_800A557C, &D_800A5588,
      &D_800A5594, &D_800A55A0, &D_800A55AC, &D_800A55B8 },
};
Battle D_800A55E8 = { 0, 0, 0x60040000 };
Battle D_800A55F4 = { 0, 0, 0x60040000 };
Battle D_800A5600 = { 0, 0, 0x60040000 };
Battle D_800A560C = { 0, 0, 0x60040000 };
Battle D_800A5618 = { 0, 0, 0x60040000 };
Battle D_800A5624 = { 0, 0, 0x60040000 };
Battle D_800A5630 = { 0, 0, 0x60040000 };
Battle D_800A563C = { 0, 0, 0x60040000 };
BattleList D_800A5648 = {
    0,
    { &D_800A55E8, &D_800A55F4, &D_800A5600, &D_800A560C,
      &D_800A5618, &D_800A5624, &D_800A5630, &D_800A563C },
};
Battle D_800A566C = { 174, 10, 0x60080000 };
Battle D_800A5678 = { 170, 10, 0x60080000 };
Battle D_800A5684 = { 110, 10, 0x60080000 };
Battle D_800A5690 = { 110, 10, 0x60080000 };
Battle D_800A569C = { 182, 10, 0x60080000 };
Battle D_800A56A8 = { 182, 10, 0x60080000 };
Battle D_800A56B4 = { 71, 10, 0x60080000 };
Battle D_800A56C0 = { 71, 10, 0x60080000 };
BattleList D_800A56CC = {
    1,
    { &D_800A566C, &D_800A5678, &D_800A5684, &D_800A5690,
      &D_800A569C, &D_800A56A8, &D_800A56B4, &D_800A56C0 },
};
Battle D_800A56F0 = { 0, 0, 0x60040000 };
Battle D_800A56FC = { 0, 0, 0x60040000 };
Battle D_800A5708 = { 0, 0, 0x60040000 };
Battle D_800A5714 = { 0, 0, 0x60040000 };
Battle D_800A5720 = { 0, 0, 0x60040000 };
Battle D_800A572C = { 0, 0, 0x60040000 };
Battle D_800A5738 = { 0, 0, 0x60040000 };
Battle D_800A5744 = { 0, 0, 0x60040000 };
BattleList D_800A5750 = {
    0,
    { &D_800A56F0, &D_800A56FC, &D_800A5708, &D_800A5714,
      &D_800A5720, &D_800A572C, &D_800A5738, &D_800A5744 },
};
Battle D_800A5774 = { 0, 0, 0x60040000 };
Battle D_800A5780 = { 0, 0, 0x60040000 };
Battle D_800A578C = { 0, 0, 0x60040000 };
Battle D_800A5798 = { 0, 0, 0x60040000 };
Battle D_800A57A4 = { 0, 0, 0x60040000 };
Battle D_800A57B0 = { 0, 0, 0x60040000 };
Battle D_800A57BC = { 0, 0, 0x60040000 };
Battle D_800A57C8 = { 0, 0, 0x60040000 };
BattleList D_800A57D4 = {
    0,
    { &D_800A5774, &D_800A5780, &D_800A578C, &D_800A5798,
      &D_800A57A4, &D_800A57B0, &D_800A57BC, &D_800A57C8 },
};
Battle D_800A57F8 = { 0, 0, 0x60040000 };
Battle D_800A5804 = { 0, 0, 0x60040000 };
Battle D_800A5810 = { 0, 0, 0x60040000 };
Battle D_800A581C = { 0, 0, 0x60040000 };
Battle D_800A5828 = { 0, 0, 0x60040000 };
Battle D_800A5834 = { 0, 0, 0x60040000 };
Battle D_800A5840 = { 0, 0, 0x60040000 };
Battle D_800A584C = { 0, 0, 0x60040000 };
BattleList D_800A5858 = {
    0,
    { &D_800A57F8, &D_800A5804, &D_800A5810, &D_800A581C,
      &D_800A5828, &D_800A5834, &D_800A5840, &D_800A584C },
};
Battle D_800A587C = { 174, 10, 0x60080000 };
Battle D_800A5888 = { 170, 10, 0x60080000 };
Battle D_800A5894 = { 110, 10, 0x60080000 };
Battle D_800A58A0 = { 110, 10, 0x60080000 };
Battle D_800A58AC = { 182, 10, 0x60080000 };
Battle D_800A58B8 = { 182, 10, 0x60080000 };
Battle D_800A58C4 = { 71, 10, 0x60080000 };
Battle D_800A58D0 = { 71, 10, 0x60080000 };
BattleList D_800A58DC = {
    1,
    { &D_800A587C, &D_800A5888, &D_800A5894, &D_800A58A0,
      &D_800A58AC, &D_800A58B8, &D_800A58C4, &D_800A58D0 },
};
Battle D_800A5900 = { 0, 0, 0x60040000 };
Battle D_800A590C = { 0, 0, 0x60040000 };
Battle D_800A5918 = { 0, 0, 0x60040000 };
Battle D_800A5924 = { 0, 0, 0x60040000 };
Battle D_800A5930 = { 0, 0, 0x60040000 };
Battle D_800A593C = { 0, 0, 0x60040000 };
Battle D_800A5948 = { 0, 0, 0x60040000 };
Battle D_800A5954 = { 0, 0, 0x60040000 };
BattleList D_800A5960 = {
    0,
    { &D_800A5900, &D_800A590C, &D_800A5918, &D_800A5924,
      &D_800A5930, &D_800A593C, &D_800A5948, &D_800A5954 },
};
Battle D_800A5984 = { 0, 0, 0x60040000 };
Battle D_800A5990 = { 0, 0, 0x60040000 };
Battle D_800A599C = { 0, 0, 0x60040000 };
Battle D_800A59A8 = { 0, 0, 0x60040000 };
Battle D_800A59B4 = { 0, 0, 0x60040000 };
Battle D_800A59C0 = { 0, 0, 0x60040000 };
Battle D_800A59CC = { 0, 0, 0x60040000 };
Battle D_800A59D8 = { 0, 0, 0x60040000 };
BattleList D_800A59E4 = {
    0,
    { &D_800A5984, &D_800A5990, &D_800A599C, &D_800A59A8,
      &D_800A59B4, &D_800A59C0, &D_800A59CC, &D_800A59D8 },
};
Battle D_800A5A08 = { 0, 0, 0x60040000 };
Battle D_800A5A14 = { 0, 0, 0x60040000 };
Battle D_800A5A20 = { 0, 0, 0x60040000 };
Battle D_800A5A2C = { 0, 0, 0x60040000 };
Battle D_800A5A38 = { 0, 0, 0x60040000 };
Battle D_800A5A44 = { 0, 0, 0x60040000 };
Battle D_800A5A50 = { 0, 0, 0x60040000 };
Battle D_800A5A5C = { 0, 0, 0x60040000 };
BattleList D_800A5A68 = {
    0,
    { &D_800A5A08, &D_800A5A14, &D_800A5A20, &D_800A5A2C,
      &D_800A5A38, &D_800A5A44, &D_800A5A50, &D_800A5A5C },
};
Battle D_800A5A8C = { 182, 10, 0x60080000 };
Battle D_800A5A98 = { 182, 10, 0x60080000 };
Battle D_800A5AA4 = { 182, 10, 0x60080000 };
Battle D_800A5AB0 = { 182, 10, 0x60080000 };
Battle D_800A5ABC = { 71, 10, 0x60080000 };
Battle D_800A5AC8 = { 71, 10, 0x60080000 };
Battle D_800A5AD4 = { 71, 10, 0x60080000 };
Battle D_800A5AE0 = { 71, 10, 0x60080000 };
BattleList D_800A5AEC = {
    1,
    { &D_800A5A8C, &D_800A5A98, &D_800A5AA4, &D_800A5AB0,
      &D_800A5ABC, &D_800A5AC8, &D_800A5AD4, &D_800A5AE0 },
};
Battle D_800A5B10 = { 0, 0, 0x60040000 };
Battle D_800A5B1C = { 0, 0, 0x60040000 };
Battle D_800A5B28 = { 0, 0, 0x60040000 };
Battle D_800A5B34 = { 0, 0, 0x60040000 };
Battle D_800A5B40 = { 0, 0, 0x60040000 };
Battle D_800A5B4C = { 0, 0, 0x60040000 };
Battle D_800A5B58 = { 0, 0, 0x60040000 };
Battle D_800A5B64 = { 0, 0, 0x60040000 };
BattleList D_800A5B70 = {
    0,
    { &D_800A5B10, &D_800A5B1C, &D_800A5B28, &D_800A5B34,
      &D_800A5B40, &D_800A5B4C, &D_800A5B58, &D_800A5B64 },
};
Battle D_800A5B94 = { 0, 0, 0x60040000 };
Battle D_800A5BA0 = { 0, 0, 0x60040000 };
Battle D_800A5BAC = { 0, 0, 0x60040000 };
Battle D_800A5BB8 = { 0, 0, 0x60040000 };
Battle D_800A5BC4 = { 0, 0, 0x60040000 };
Battle D_800A5BD0 = { 0, 0, 0x60040000 };
Battle D_800A5BDC = { 0, 0, 0x60040000 };
Battle D_800A5BE8 = { 0, 0, 0x60040000 };
BattleList D_800A5BF4 = {
    0,
    { &D_800A5B94, &D_800A5BA0, &D_800A5BAC, &D_800A5BB8,
      &D_800A5BC4, &D_800A5BD0, &D_800A5BDC, &D_800A5BE8 },
};
Battle D_800A5C18 = { 0, 0, 0x60040000 };
Battle D_800A5C24 = { 0, 0, 0x60040000 };
Battle D_800A5C30 = { 0, 0, 0x60040000 };
Battle D_800A5C3C = { 0, 0, 0x60040000 };
Battle D_800A5C48 = { 0, 0, 0x60040000 };
Battle D_800A5C54 = { 0, 0, 0x60040000 };
Battle D_800A5C60 = { 0, 0, 0x60040000 };
Battle D_800A5C6C = { 0, 0, 0x60040000 };
BattleList D_800A5C78 = {
    0,
    { &D_800A5C18, &D_800A5C24, &D_800A5C30, &D_800A5C3C,
      &D_800A5C48, &D_800A5C54, &D_800A5C60, &D_800A5C6C },
};
Battle D_800A5C9C = { 182, 10, 0x60080000 };
Battle D_800A5CA8 = { 182, 10, 0x60080000 };
Battle D_800A5CB4 = { 182, 10, 0x60080000 };
Battle D_800A5CC0 = { 182, 10, 0x60080000 };
Battle D_800A5CCC = { 71, 10, 0x60080000 };
Battle D_800A5CD8 = { 71, 10, 0x60080000 };
Battle D_800A5CE4 = { 71, 10, 0x60080000 };
Battle D_800A5CF0 = { 71, 10, 0x60080000 };
BattleList D_800A5CFC = {
    1,
    { &D_800A5C9C, &D_800A5CA8, &D_800A5CB4, &D_800A5CC0,
      &D_800A5CCC, &D_800A5CD8, &D_800A5CE4, &D_800A5CF0 },
};
Battle D_800A5D20 = { 0, 0, 0x60040000 };
Battle D_800A5D2C = { 0, 0, 0x60040000 };
Battle D_800A5D38 = { 0, 0, 0x60040000 };
Battle D_800A5D44 = { 0, 0, 0x60040000 };
Battle D_800A5D50 = { 0, 0, 0x60040000 };
Battle D_800A5D5C = { 0, 0, 0x60040000 };
Battle D_800A5D68 = { 0, 0, 0x60040000 };
Battle D_800A5D74 = { 0, 0, 0x60040000 };
BattleList D_800A5D80 = {
    0,
    { &D_800A5D20, &D_800A5D2C, &D_800A5D38, &D_800A5D44,
      &D_800A5D50, &D_800A5D5C, &D_800A5D68, &D_800A5D74 },
};
Battle D_800A5DA4 = { 0, 0, 0x60040000 };
Battle D_800A5DB0 = { 0, 0, 0x60040000 };
Battle D_800A5DBC = { 0, 0, 0x60040000 };
Battle D_800A5DC8 = { 0, 0, 0x60040000 };
Battle D_800A5DD4 = { 0, 0, 0x60040000 };
Battle D_800A5DE0 = { 0, 0, 0x60040000 };
Battle D_800A5DEC = { 0, 0, 0x60040000 };
Battle D_800A5DF8 = { 0, 0, 0x60040000 };
BattleList D_800A5E04 = {
    0,
    { &D_800A5DA4, &D_800A5DB0, &D_800A5DBC, &D_800A5DC8,
      &D_800A5DD4, &D_800A5DE0, &D_800A5DEC, &D_800A5DF8 },
};
Battle D_800A5E28 = { 0, 0, 0x60040000 };
Battle D_800A5E34 = { 0, 0, 0x60040000 };
Battle D_800A5E40 = { 0, 0, 0x60040000 };
Battle D_800A5E4C = { 0, 0, 0x60040000 };
Battle D_800A5E58 = { 0, 0, 0x60040000 };
Battle D_800A5E64 = { 0, 0, 0x60040000 };
Battle D_800A5E70 = { 0, 0, 0x60040000 };
Battle D_800A5E7C = { 0, 0, 0x60040000 };
BattleList D_800A5E88 = {
    0,
    { &D_800A5E28, &D_800A5E34, &D_800A5E40, &D_800A5E4C,
      &D_800A5E58, &D_800A5E64, &D_800A5E70, &D_800A5E7C },
};
Battle D_800A5EAC = { 174, 10, 0x60080000 };
Battle D_800A5EB8 = { 174, 10, 0x60080000 };
Battle D_800A5EC4 = { 170, 10, 0x60080000 };
Battle D_800A5ED0 = { 170, 10, 0x60080000 };
Battle D_800A5EDC = { 170, 10, 0x60080000 };
Battle D_800A5EE8 = { 170, 10, 0x60080000 };
Battle D_800A5EF4 = { 170, 10, 0x60080000 };
Battle D_800A5F00 = { 170, 10, 0x60080000 };
BattleList D_800A5F0C = {
    4,
    { &D_800A5EAC, &D_800A5EB8, &D_800A5EC4, &D_800A5ED0,
      &D_800A5EDC, &D_800A5EE8, &D_800A5EF4, &D_800A5F00 },
};
Battle D_800A5F30 = { 0, 0, 0x60040000 };
Battle D_800A5F3C = { 0, 0, 0x60040000 };
Battle D_800A5F48 = { 0, 0, 0x60040000 };
Battle D_800A5F54 = { 0, 0, 0x60040000 };
Battle D_800A5F60 = { 0, 0, 0x60040000 };
Battle D_800A5F6C = { 0, 0, 0x60040000 };
Battle D_800A5F78 = { 0, 0, 0x60040000 };
Battle D_800A5F84 = { 0, 0, 0x60040000 };
BattleList D_800A5F90 = {
    0,
    { &D_800A5F30, &D_800A5F3C, &D_800A5F48, &D_800A5F54,
      &D_800A5F60, &D_800A5F6C, &D_800A5F78, &D_800A5F84 },
};
Battle D_800A5FB4 = { 0, 0, 0x60040000 };
Battle D_800A5FC0 = { 0, 0, 0x60040000 };
Battle D_800A5FCC = { 0, 0, 0x60040000 };
Battle D_800A5FD8 = { 0, 0, 0x60040000 };
Battle D_800A5FE4 = { 0, 0, 0x60040000 };
Battle D_800A5FF0 = { 0, 0, 0x60040000 };
Battle D_800A5FFC = { 0, 0, 0x60040000 };
Battle D_800A6008 = { 0, 0, 0x60040000 };
BattleList D_800A6014 = {
    0,
    { &D_800A5FB4, &D_800A5FC0, &D_800A5FCC, &D_800A5FD8,
      &D_800A5FE4, &D_800A5FF0, &D_800A5FFC, &D_800A6008 },
};
Battle D_800A6038 = { 0, 0, 0x60040000 };
Battle D_800A6044 = { 0, 0, 0x60040000 };
Battle D_800A6050 = { 0, 0, 0x60040000 };
Battle D_800A605C = { 0, 0, 0x60040000 };
Battle D_800A6068 = { 0, 0, 0x60040000 };
Battle D_800A6074 = { 0, 0, 0x60040000 };
Battle D_800A6080 = { 0, 0, 0x60040000 };
Battle D_800A608C = { 0, 0, 0x60040000 };
BattleList D_800A6098 = {
    0,
    { &D_800A6038, &D_800A6044, &D_800A6050, &D_800A605C,
      &D_800A6068, &D_800A6074, &D_800A6080, &D_800A608C },
};
Battle D_800A60BC = { 110, 10, 0x60080000 };
Battle D_800A60C8 = { 110, 10, 0x60080000 };
Battle D_800A60D4 = { 110, 10, 0x60080000 };
Battle D_800A60E0 = { 110, 10, 0x60080000 };
Battle D_800A60EC = { 110, 10, 0x60080000 };
Battle D_800A60F8 = { 110, 10, 0x60080000 };
Battle D_800A6104 = { 110, 10, 0x60080000 };
Battle D_800A6110 = { 110, 10, 0x60080000 };
BattleList D_800A611C = {
    1,
    { &D_800A60BC, &D_800A60C8, &D_800A60D4, &D_800A60E0,
      &D_800A60EC, &D_800A60F8, &D_800A6104, &D_800A6110 },
};
Battle D_800A6140 = { 0, 0, 0x60040000 };
Battle D_800A614C = { 0, 0, 0x60040000 };
Battle D_800A6158 = { 0, 0, 0x60040000 };
Battle D_800A6164 = { 0, 0, 0x60040000 };
Battle D_800A6170 = { 0, 0, 0x60040000 };
Battle D_800A617C = { 0, 0, 0x60040000 };
Battle D_800A6188 = { 0, 0, 0x60040000 };
Battle D_800A6194 = { 0, 0, 0x60040000 };
BattleList D_800A61A0 = {
    0,
    { &D_800A6140, &D_800A614C, &D_800A6158, &D_800A6164,
      &D_800A6170, &D_800A617C, &D_800A6188, &D_800A6194 },
};
Battle D_800A61C4 = { 0, 0, 0x60040000 };
Battle D_800A61D0 = { 0, 0, 0x60040000 };
Battle D_800A61DC = { 0, 0, 0x60040000 };
Battle D_800A61E8 = { 0, 0, 0x60040000 };
Battle D_800A61F4 = { 0, 0, 0x60040000 };
Battle D_800A6200 = { 0, 0, 0x60040000 };
Battle D_800A620C = { 0, 0, 0x60040000 };
Battle D_800A6218 = { 0, 0, 0x60040000 };
BattleList D_800A6224 = {
    0,
    { &D_800A61C4, &D_800A61D0, &D_800A61DC, &D_800A61E8,
      &D_800A61F4, &D_800A6200, &D_800A620C, &D_800A6218 },
};
Battle D_800A6248 = { 0, 0, 0x60040000 };
Battle D_800A6254 = { 0, 0, 0x60040000 };
Battle D_800A6260 = { 0, 0, 0x60040000 };
Battle D_800A626C = { 0, 0, 0x60040000 };
Battle D_800A6278 = { 0, 0, 0x60040000 };
Battle D_800A6284 = { 0, 0, 0x60040000 };
Battle D_800A6290 = { 0, 0, 0x60040000 };
Battle D_800A629C = { 0, 0, 0x60040000 };
BattleList D_800A62A8 = {
    0,
    { &D_800A6248, &D_800A6254, &D_800A6260, &D_800A626C,
      &D_800A6278, &D_800A6284, &D_800A6290, &D_800A629C },
};
Battle D_800A62CC = { 182, 10, 0x60080000 };
Battle D_800A62D8 = { 182, 10, 0x60080000 };
Battle D_800A62E4 = { 182, 10, 0x60080000 };
Battle D_800A62F0 = { 182, 10, 0x60080000 };
Battle D_800A62FC = { 71, 10, 0x60080000 };
Battle D_800A6308 = { 71, 10, 0x60080000 };
Battle D_800A6314 = { 71, 10, 0x60080000 };
Battle D_800A6320 = { 71, 10, 0x60080000 };
BattleList D_800A632C = {
    5,
    { &D_800A62CC, &D_800A62D8, &D_800A62E4, &D_800A62F0,
      &D_800A62FC, &D_800A6308, &D_800A6314, &D_800A6320 },
};
Battle D_800A6350 = { 0, 0, 0x60040000 };
Battle D_800A635C = { 0, 0, 0x60040000 };
Battle D_800A6368 = { 0, 0, 0x60040000 };
Battle D_800A6374 = { 0, 0, 0x60040000 };
Battle D_800A6380 = { 0, 0, 0x60040000 };
Battle D_800A638C = { 0, 0, 0x60040000 };
Battle D_800A6398 = { 0, 0, 0x60040000 };
Battle D_800A63A4 = { 0, 0, 0x60040000 };
BattleList D_800A63B0 = {
    0,
    { &D_800A6350, &D_800A635C, &D_800A6368, &D_800A6374,
      &D_800A6380, &D_800A638C, &D_800A6398, &D_800A63A4 },
};
Battle D_800A63D4 = { 0, 0, 0x60040000 };
Battle D_800A63E0 = { 0, 0, 0x60040000 };
Battle D_800A63EC = { 0, 0, 0x60040000 };
Battle D_800A63F8 = { 0, 0, 0x60040000 };
Battle D_800A6404 = { 0, 0, 0x60040000 };
Battle D_800A6410 = { 0, 0, 0x60040000 };
Battle D_800A641C = { 0, 0, 0x60040000 };
Battle D_800A6428 = { 0, 0, 0x60040000 };
BattleList D_800A6434 = {
    0,
    { &D_800A63D4, &D_800A63E0, &D_800A63EC, &D_800A63F8,
      &D_800A6404, &D_800A6410, &D_800A641C, &D_800A6428 },
};
Battle D_800A6458 = { 0, 0, 0x60040000 };
Battle D_800A6464 = { 0, 0, 0x60040000 };
Battle D_800A6470 = { 0, 0, 0x60040000 };
Battle D_800A647C = { 0, 0, 0x60040000 };
Battle D_800A6488 = { 0, 0, 0x60040000 };
Battle D_800A6494 = { 0, 0, 0x60040000 };
Battle D_800A64A0 = { 0, 0, 0x60040000 };
Battle D_800A64AC = { 0, 0, 0x60040000 };
BattleList D_800A64B8 = {
    0,
    { &D_800A6458, &D_800A6464, &D_800A6470, &D_800A647C,
      &D_800A6488, &D_800A6494, &D_800A64A0, &D_800A64AC },
};
Battle D_800A64DC = { 110, 10, 0x60080000 };
Battle D_800A64E8 = { 110, 10, 0x60080000 };
Battle D_800A64F4 = { 110, 10, 0x60080000 };
Battle D_800A6500 = { 110, 10, 0x60080000 };
Battle D_800A650C = { 110, 10, 0x60080000 };
Battle D_800A6518 = { 110, 10, 0x60080000 };
Battle D_800A6524 = { 110, 10, 0x60080000 };
Battle D_800A6530 = { 110, 10, 0x60080000 };
BattleList D_800A653C = {
    3,
    { &D_800A64DC, &D_800A64E8, &D_800A64F4, &D_800A6500,
      &D_800A650C, &D_800A6518, &D_800A6524, &D_800A6530 },
};
Battle D_800A6560 = { 0, 0, 0x60040000 };
Battle D_800A656C = { 0, 0, 0x60040000 };
Battle D_800A6578 = { 0, 0, 0x60040000 };
Battle D_800A6584 = { 0, 0, 0x60040000 };
Battle D_800A6590 = { 0, 0, 0x60040000 };
Battle D_800A659C = { 0, 0, 0x60040000 };
Battle D_800A65A8 = { 0, 0, 0x60040000 };
Battle D_800A65B4 = { 0, 0, 0x60040000 };
BattleList D_800A65C0 = {
    0,
    { &D_800A6560, &D_800A656C, &D_800A6578, &D_800A6584,
      &D_800A6590, &D_800A659C, &D_800A65A8, &D_800A65B4 },
};
Battle D_800A65E4 = { 0, 0, 0x60040000 };
Battle D_800A65F0 = { 0, 0, 0x60040000 };
Battle D_800A65FC = { 0, 0, 0x60040000 };
Battle D_800A6608 = { 0, 0, 0x60040000 };
Battle D_800A6614 = { 0, 0, 0x60040000 };
Battle D_800A6620 = { 0, 0, 0x60040000 };
Battle D_800A662C = { 0, 0, 0x60040000 };
Battle D_800A6638 = { 0, 0, 0x60040000 };
BattleList D_800A6644 = {
    0,
    { &D_800A65E4, &D_800A65F0, &D_800A65FC, &D_800A6608,
      &D_800A6614, &D_800A6620, &D_800A662C, &D_800A6638 },
};
Battle D_800A6668 = { 0, 0, 0x60040000 };
Battle D_800A6674 = { 0, 0, 0x60040000 };
Battle D_800A6680 = { 0, 0, 0x60040000 };
Battle D_800A668C = { 0, 0, 0x60040000 };
Battle D_800A6698 = { 0, 0, 0x60040000 };
Battle D_800A66A4 = { 0, 0, 0x60040000 };
Battle D_800A66B0 = { 0, 0, 0x60040000 };
Battle D_800A66BC = { 0, 0, 0x60040000 };
BattleList D_800A66C8 = {
    0,
    { &D_800A6668, &D_800A6674, &D_800A6680, &D_800A668C,
      &D_800A6698, &D_800A66A4, &D_800A66B0, &D_800A66BC },
};
Battle D_800A66EC = { 182, 10, 0x60080000 };
Battle D_800A66F8 = { 182, 10, 0x60080000 };
Battle D_800A6704 = { 182, 10, 0x60080000 };
Battle D_800A6710 = { 182, 10, 0x60080000 };
Battle D_800A671C = { 71, 10, 0x60080000 };
Battle D_800A6728 = { 71, 10, 0x60080000 };
Battle D_800A6734 = { 71, 10, 0x60080000 };
Battle D_800A6740 = { 71, 10, 0x60080000 };
BattleList D_800A674C = {
    4,
    { &D_800A66EC, &D_800A66F8, &D_800A6704, &D_800A6710,
      &D_800A671C, &D_800A6728, &D_800A6734, &D_800A6740 },
};
Battle D_800A6770 = { 0, 0, 0x60040000 };
Battle D_800A677C = { 0, 0, 0x60040000 };
Battle D_800A6788 = { 0, 0, 0x60040000 };
Battle D_800A6794 = { 0, 0, 0x60040000 };
Battle D_800A67A0 = { 0, 0, 0x60040000 };
Battle D_800A67AC = { 0, 0, 0x60040000 };
Battle D_800A67B8 = { 0, 0, 0x60040000 };
Battle D_800A67C4 = { 0, 0, 0x60040000 };
BattleList D_800A67D0 = {
    0,
    { &D_800A6770, &D_800A677C, &D_800A6788, &D_800A6794,
      &D_800A67A0, &D_800A67AC, &D_800A67B8, &D_800A67C4 },
};
Battle D_800A67F4 = { 0, 0, 0x60040000 };
Battle D_800A6800 = { 0, 0, 0x60040000 };
Battle D_800A680C = { 0, 0, 0x60040000 };
Battle D_800A6818 = { 0, 0, 0x60040000 };
Battle D_800A6824 = { 0, 0, 0x60040000 };
Battle D_800A6830 = { 0, 0, 0x60040000 };
Battle D_800A683C = { 0, 0, 0x60040000 };
Battle D_800A6848 = { 0, 0, 0x60040000 };
BattleList D_800A6854 = {
    0,
    { &D_800A67F4, &D_800A6800, &D_800A680C, &D_800A6818,
      &D_800A6824, &D_800A6830, &D_800A683C, &D_800A6848 },
};
Battle D_800A6878 = { 0, 0, 0x60040000 };
Battle D_800A6884 = { 0, 0, 0x60040000 };
Battle D_800A6890 = { 0, 0, 0x60040000 };
Battle D_800A689C = { 0, 0, 0x60040000 };
Battle D_800A68A8 = { 0, 0, 0x60040000 };
Battle D_800A68B4 = { 0, 0, 0x60040000 };
Battle D_800A68C0 = { 0, 0, 0x60040000 };
Battle D_800A68CC = { 0, 0, 0x60040000 };
BattleList D_800A68D8 = {
    0,
    { &D_800A6878, &D_800A6884, &D_800A6890, &D_800A689C,
      &D_800A68A8, &D_800A68B4, &D_800A68C0, &D_800A68CC },
};
Battle D_800A68FC = { 174, 10, 0x60080000 };
Battle D_800A6908 = { 174, 10, 0x60080000 };
Battle D_800A6914 = { 170, 10, 0x60080000 };
Battle D_800A6920 = { 170, 10, 0x60080000 };
Battle D_800A692C = { 170, 10, 0x60080000 };
Battle D_800A6938 = { 170, 10, 0x60080000 };
Battle D_800A6944 = { 170, 10, 0x60080000 };
Battle D_800A6950 = { 170, 10, 0x60080000 };
BattleList D_800A695C = {
    2,
    { &D_800A68FC, &D_800A6908, &D_800A6914, &D_800A6920,
      &D_800A692C, &D_800A6938, &D_800A6944, &D_800A6950 },
};
Battle D_800A6980 = { 0, 0, 0x60040000 };
Battle D_800A698C = { 0, 0, 0x60040000 };
Battle D_800A6998 = { 0, 0, 0x60040000 };
Battle D_800A69A4 = { 0, 0, 0x60040000 };
Battle D_800A69B0 = { 0, 0, 0x60040000 };
Battle D_800A69BC = { 0, 0, 0x60040000 };
Battle D_800A69C8 = { 0, 0, 0x60040000 };
Battle D_800A69D4 = { 0, 0, 0x60040000 };
BattleList D_800A69E0 = {
    0,
    { &D_800A6980, &D_800A698C, &D_800A6998, &D_800A69A4,
      &D_800A69B0, &D_800A69BC, &D_800A69C8, &D_800A69D4 },
};
Battle D_800A6A04 = { 0, 0, 0x60040000 };
Battle D_800A6A10 = { 0, 0, 0x60040000 };
Battle D_800A6A1C = { 0, 0, 0x60040000 };
Battle D_800A6A28 = { 0, 0, 0x60040000 };
Battle D_800A6A34 = { 0, 0, 0x60040000 };
Battle D_800A6A40 = { 0, 0, 0x60040000 };
Battle D_800A6A4C = { 0, 0, 0x60040000 };
Battle D_800A6A58 = { 0, 0, 0x60040000 };
BattleList D_800A6A64 = {
    0,
    { &D_800A6A04, &D_800A6A10, &D_800A6A1C, &D_800A6A28,
      &D_800A6A34, &D_800A6A40, &D_800A6A4C, &D_800A6A58 },
};
Battle D_800A6A88 = { 0, 0, 0x60040000 };
Battle D_800A6A94 = { 0, 0, 0x60040000 };
Battle D_800A6AA0 = { 0, 0, 0x60040000 };
Battle D_800A6AAC = { 0, 0, 0x60040000 };
Battle D_800A6AB8 = { 0, 0, 0x60040000 };
Battle D_800A6AC4 = { 0, 0, 0x60040000 };
Battle D_800A6AD0 = { 0, 0, 0x60040000 };
Battle D_800A6ADC = { 0, 0, 0x60040000 };
BattleList D_800A6AE8 = {
    0,
    { &D_800A6A88, &D_800A6A94, &D_800A6AA0, &D_800A6AAC,
      &D_800A6AB8, &D_800A6AC4, &D_800A6AD0, &D_800A6ADC },
};
Battle D_800A6B0C = { 182, 10, 0x60080000 };
Battle D_800A6B18 = { 182, 10, 0x60080000 };
Battle D_800A6B24 = { 182, 10, 0x60080000 };
Battle D_800A6B30 = { 182, 10, 0x60080000 };
Battle D_800A6B3C = { 71, 10, 0x60080000 };
Battle D_800A6B48 = { 71, 10, 0x60080000 };
Battle D_800A6B54 = { 71, 10, 0x60080000 };
Battle D_800A6B60 = { 71, 10, 0x60080000 };
BattleList D_800A6B6C = {
    1,
    { &D_800A6B0C, &D_800A6B18, &D_800A6B24, &D_800A6B30,
      &D_800A6B3C, &D_800A6B48, &D_800A6B54, &D_800A6B60 },
};
Battle D_800A6B90 = { 0, 0, 0x60040000 };
Battle D_800A6B9C = { 0, 0, 0x60040000 };
Battle D_800A6BA8 = { 0, 0, 0x60040000 };
Battle D_800A6BB4 = { 0, 0, 0x60040000 };
Battle D_800A6BC0 = { 0, 0, 0x60040000 };
Battle D_800A6BCC = { 0, 0, 0x60040000 };
Battle D_800A6BD8 = { 0, 0, 0x60040000 };
Battle D_800A6BE4 = { 0, 0, 0x60040000 };
BattleList D_800A6BF0 = {
    0,
    { &D_800A6B90, &D_800A6B9C, &D_800A6BA8, &D_800A6BB4,
      &D_800A6BC0, &D_800A6BCC, &D_800A6BD8, &D_800A6BE4 },
};
Battle D_800A6C14 = { 0, 0, 0x60040000 };
Battle D_800A6C20 = { 0, 0, 0x60040000 };
Battle D_800A6C2C = { 0, 0, 0x60040000 };
Battle D_800A6C38 = { 0, 0, 0x60040000 };
Battle D_800A6C44 = { 0, 0, 0x60040000 };
Battle D_800A6C50 = { 0, 0, 0x60040000 };
Battle D_800A6C5C = { 0, 0, 0x60040000 };
Battle D_800A6C68 = { 0, 0, 0x60040000 };
BattleList D_800A6C74 = {
    0,
    { &D_800A6C14, &D_800A6C20, &D_800A6C2C, &D_800A6C38,
      &D_800A6C44, &D_800A6C50, &D_800A6C5C, &D_800A6C68 },
};
Battle D_800A6C98 = { 0, 0, 0x60040000 };
Battle D_800A6CA4 = { 0, 0, 0x60040000 };
Battle D_800A6CB0 = { 0, 0, 0x60040000 };
Battle D_800A6CBC = { 0, 0, 0x60040000 };
Battle D_800A6CC8 = { 0, 0, 0x60040000 };
Battle D_800A6CD4 = { 0, 0, 0x60040000 };
Battle D_800A6CE0 = { 0, 0, 0x60040000 };
Battle D_800A6CEC = { 0, 0, 0x60040000 };
BattleList D_800A6CF8 = {
    0,
    { &D_800A6C98, &D_800A6CA4, &D_800A6CB0, &D_800A6CBC,
      &D_800A6CC8, &D_800A6CD4, &D_800A6CE0, &D_800A6CEC },
};
Battle D_800A6D1C = { 182, 10, 0x60080000 };
Battle D_800A6D28 = { 182, 10, 0x60080000 };
Battle D_800A6D34 = { 182, 10, 0x60080000 };
Battle D_800A6D40 = { 182, 10, 0x60080000 };
Battle D_800A6D4C = { 71, 10, 0x60080000 };
Battle D_800A6D58 = { 71, 10, 0x60080000 };
Battle D_800A6D64 = { 71, 10, 0x60080000 };
Battle D_800A6D70 = { 71, 10, 0x60080000 };
BattleList D_800A6D7C = {
    1,
    { &D_800A6D1C, &D_800A6D28, &D_800A6D34, &D_800A6D40,
      &D_800A6D4C, &D_800A6D58, &D_800A6D64, &D_800A6D70 },
};
Battle D_800A6DA0 = { 0, 0, 0x60040000 };
Battle D_800A6DAC = { 0, 0, 0x60040000 };
Battle D_800A6DB8 = { 0, 0, 0x60040000 };
Battle D_800A6DC4 = { 0, 0, 0x60040000 };
Battle D_800A6DD0 = { 0, 0, 0x60040000 };
Battle D_800A6DDC = { 0, 0, 0x60040000 };
Battle D_800A6DE8 = { 0, 0, 0x60040000 };
Battle D_800A6DF4 = { 0, 0, 0x60040000 };
BattleList D_800A6E00 = {
    0,
    { &D_800A6DA0, &D_800A6DAC, &D_800A6DB8, &D_800A6DC4,
      &D_800A6DD0, &D_800A6DDC, &D_800A6DE8, &D_800A6DF4 },
};
Battle D_800A6E24 = { 0, 0, 0x60040000 };
Battle D_800A6E30 = { 0, 0, 0x60040000 };
Battle D_800A6E3C = { 0, 0, 0x60040000 };
Battle D_800A6E48 = { 0, 0, 0x60040000 };
Battle D_800A6E54 = { 0, 0, 0x60040000 };
Battle D_800A6E60 = { 0, 0, 0x60040000 };
Battle D_800A6E6C = { 0, 0, 0x60040000 };
Battle D_800A6E78 = { 0, 0, 0x60040000 };
BattleList D_800A6E84 = {
    0,
    { &D_800A6E24, &D_800A6E30, &D_800A6E3C, &D_800A6E48,
      &D_800A6E54, &D_800A6E60, &D_800A6E6C, &D_800A6E78 },
};
Battle D_800A6EA8 = { 0, 0, 0x60040000 };
Battle D_800A6EB4 = { 0, 0, 0x60040000 };
Battle D_800A6EC0 = { 0, 0, 0x60040000 };
Battle D_800A6ECC = { 0, 0, 0x60040000 };
Battle D_800A6ED8 = { 0, 0, 0x60040000 };
Battle D_800A6EE4 = { 0, 0, 0x60040000 };
Battle D_800A6EF0 = { 0, 0, 0x60040000 };
Battle D_800A6EFC = { 0, 0, 0x60040000 };
BattleList D_800A6F08 = {
    0,
    { &D_800A6EA8, &D_800A6EB4, &D_800A6EC0, &D_800A6ECC,
      &D_800A6ED8, &D_800A6EE4, &D_800A6EF0, &D_800A6EFC },
};
Battle D_800A6F2C = { 174, 10, 0x60080000 };
Battle D_800A6F38 = { 174, 10, 0x60080000 };
Battle D_800A6F44 = { 170, 10, 0x60080000 };
Battle D_800A6F50 = { 170, 10, 0x60080000 };
Battle D_800A6F5C = { 182, 10, 0x60080000 };
Battle D_800A6F68 = { 182, 10, 0x60080000 };
Battle D_800A6F74 = { 71, 10, 0x60080000 };
Battle D_800A6F80 = { 71, 10, 0x60080000 };
BattleList D_800A6F8C = {
    1,
    { &D_800A6F2C, &D_800A6F38, &D_800A6F44, &D_800A6F50,
      &D_800A6F5C, &D_800A6F68, &D_800A6F74, &D_800A6F80 },
};
Battle D_800A6FB0 = { 0, 0, 0x60040000 };
Battle D_800A6FBC = { 0, 0, 0x60040000 };
Battle D_800A6FC8 = { 0, 0, 0x60040000 };
Battle D_800A6FD4 = { 0, 0, 0x60040000 };
Battle D_800A6FE0 = { 0, 0, 0x60040000 };
Battle D_800A6FEC = { 0, 0, 0x60040000 };
Battle D_800A6FF8 = { 0, 0, 0x60040000 };
Battle D_800A7004 = { 0, 0, 0x60040000 };
BattleList D_800A7010 = {
    0,
    { &D_800A6FB0, &D_800A6FBC, &D_800A6FC8, &D_800A6FD4,
      &D_800A6FE0, &D_800A6FEC, &D_800A6FF8, &D_800A7004 },
};
Battle D_800A7034 = { 0, 0, 0x60040000 };
Battle D_800A7040 = { 0, 0, 0x60040000 };
Battle D_800A704C = { 0, 0, 0x60040000 };
Battle D_800A7058 = { 0, 0, 0x60040000 };
Battle D_800A7064 = { 0, 0, 0x60040000 };
Battle D_800A7070 = { 0, 0, 0x60040000 };
Battle D_800A707C = { 0, 0, 0x60040000 };
Battle D_800A7088 = { 0, 0, 0x60040000 };
BattleList D_800A7094 = {
    0,
    { &D_800A7034, &D_800A7040, &D_800A704C, &D_800A7058,
      &D_800A7064, &D_800A7070, &D_800A707C, &D_800A7088 },
};
Battle D_800A70B8 = { 0, 0, 0x60040000 };
Battle D_800A70C4 = { 0, 0, 0x60040000 };
Battle D_800A70D0 = { 0, 0, 0x60040000 };
Battle D_800A70DC = { 0, 0, 0x60040000 };
Battle D_800A70E8 = { 0, 0, 0x60040000 };
Battle D_800A70F4 = { 0, 0, 0x60040000 };
Battle D_800A7100 = { 0, 0, 0x60040000 };
Battle D_800A710C = { 0, 0, 0x60040000 };
BattleList D_800A7118 = {
    0,
    { &D_800A70B8, &D_800A70C4, &D_800A70D0, &D_800A70DC,
      &D_800A70E8, &D_800A70F4, &D_800A7100, &D_800A710C },
};
Battle D_800A713C = { 182, 10, 0x60080000 };
Battle D_800A7148 = { 182, 10, 0x60080000 };
Battle D_800A7154 = { 182, 10, 0x60080000 };
Battle D_800A7160 = { 182, 10, 0x60080000 };
Battle D_800A716C = { 71, 10, 0x60080000 };
Battle D_800A7178 = { 71, 10, 0x60080000 };
Battle D_800A7184 = { 71, 10, 0x60080000 };
Battle D_800A7190 = { 71, 10, 0x60080000 };
BattleList D_800A719C = {
    1,
    { &D_800A713C, &D_800A7148, &D_800A7154, &D_800A7160,
      &D_800A716C, &D_800A7178, &D_800A7184, &D_800A7190 },
};
Battle D_800A71C0 = { 0, 0, 0x60040000 };
Battle D_800A71CC = { 0, 0, 0x60040000 };
Battle D_800A71D8 = { 0, 0, 0x60040000 };
Battle D_800A71E4 = { 0, 0, 0x60040000 };
Battle D_800A71F0 = { 0, 0, 0x60040000 };
Battle D_800A71FC = { 0, 0, 0x60040000 };
Battle D_800A7208 = { 0, 0, 0x60040000 };
Battle D_800A7214 = { 0, 0, 0x60040000 };
BattleList D_800A7220 = {
    0,
    { &D_800A71C0, &D_800A71CC, &D_800A71D8, &D_800A71E4,
      &D_800A71F0, &D_800A71FC, &D_800A7208, &D_800A7214 },
};
Battle D_800A7244 = { 0, 0, 0x60040000 };
Battle D_800A7250 = { 0, 0, 0x60040000 };
Battle D_800A725C = { 0, 0, 0x60040000 };
Battle D_800A7268 = { 0, 0, 0x60040000 };
Battle D_800A7274 = { 0, 0, 0x60040000 };
Battle D_800A7280 = { 0, 0, 0x60040000 };
Battle D_800A728C = { 0, 0, 0x60040000 };
Battle D_800A7298 = { 0, 0, 0x60040000 };
BattleList D_800A72A4 = {
    0,
    { &D_800A7244, &D_800A7250, &D_800A725C, &D_800A7268,
      &D_800A7274, &D_800A7280, &D_800A728C, &D_800A7298 },
};
Battle D_800A72C8 = { 0, 0, 0x60040000 };
Battle D_800A72D4 = { 0, 0, 0x60040000 };
Battle D_800A72E0 = { 0, 0, 0x60040000 };
Battle D_800A72EC = { 0, 0, 0x60040000 };
Battle D_800A72F8 = { 0, 0, 0x60040000 };
Battle D_800A7304 = { 0, 0, 0x60040000 };
Battle D_800A7310 = { 0, 0, 0x60040000 };
Battle D_800A731C = { 0, 0, 0x60040000 };
BattleList D_800A7328 = {
    0,
    { &D_800A72C8, &D_800A72D4, &D_800A72E0, &D_800A72EC,
      &D_800A72F8, &D_800A7304, &D_800A7310, &D_800A731C },
};
Battle D_800A734C = { 182, 10, 0x60080000 };
Battle D_800A7358 = { 182, 10, 0x60080000 };
Battle D_800A7364 = { 182, 10, 0x60080000 };
Battle D_800A7370 = { 182, 10, 0x60080000 };
Battle D_800A737C = { 71, 10, 0x60080000 };
Battle D_800A7388 = { 71, 10, 0x60080000 };
Battle D_800A7394 = { 71, 10, 0x60080000 };
Battle D_800A73A0 = { 71, 10, 0x60080000 };
BattleList D_800A73AC = {
    1,
    { &D_800A734C, &D_800A7358, &D_800A7364, &D_800A7370,
      &D_800A737C, &D_800A7388, &D_800A7394, &D_800A73A0 },
};
Battle D_800A73D0 = { 0, 0, 0x60040000 };
Battle D_800A73DC = { 0, 0, 0x60040000 };
Battle D_800A73E8 = { 0, 0, 0x60040000 };
Battle D_800A73F4 = { 0, 0, 0x60040000 };
Battle D_800A7400 = { 0, 0, 0x60040000 };
Battle D_800A740C = { 0, 0, 0x60040000 };
Battle D_800A7418 = { 0, 0, 0x60040000 };
Battle D_800A7424 = { 0, 0, 0x60040000 };
BattleList D_800A7430 = {
    0,
    { &D_800A73D0, &D_800A73DC, &D_800A73E8, &D_800A73F4,
      &D_800A7400, &D_800A740C, &D_800A7418, &D_800A7424 },
};
Battle D_800A7454 = { 0, 0, 0x60040000 };
Battle D_800A7460 = { 0, 0, 0x60040000 };
Battle D_800A746C = { 0, 0, 0x60040000 };
Battle D_800A7478 = { 0, 0, 0x60040000 };
Battle D_800A7484 = { 0, 0, 0x60040000 };
Battle D_800A7490 = { 0, 0, 0x60040000 };
Battle D_800A749C = { 0, 0, 0x60040000 };
Battle D_800A74A8 = { 0, 0, 0x60040000 };
BattleList D_800A74B4 = {
    0,
    { &D_800A7454, &D_800A7460, &D_800A746C, &D_800A7478,
      &D_800A7484, &D_800A7490, &D_800A749C, &D_800A74A8 },
};
Battle D_800A74D8 = { 0, 0, 0x60040000 };
Battle D_800A74E4 = { 0, 0, 0x60040000 };
Battle D_800A74F0 = { 0, 0, 0x60040000 };
Battle D_800A74FC = { 0, 0, 0x60040000 };
Battle D_800A7508 = { 0, 0, 0x60040000 };
Battle D_800A7514 = { 0, 0, 0x60040000 };
Battle D_800A7520 = { 0, 0, 0x60040000 };
Battle D_800A752C = { 0, 0, 0x60040000 };
BattleList D_800A7538 = {
    0,
    { &D_800A74D8, &D_800A74E4, &D_800A74F0, &D_800A74FC,
      &D_800A7508, &D_800A7514, &D_800A7520, &D_800A752C },
};
FieldBattles stageBattles[] = {
    { 236, 2, 0, { &D_800A52AC, &D_800A5330, &D_800A53B4, &D_800A5438 } },
    { 247, 4, 0, { &D_800A54BC, &D_800A5540, &D_800A55C4, &D_800A5648 } },
    { 252, 5, 0, { &D_800A56CC, &D_800A5750, &D_800A57D4, &D_800A5858 } },
    { 258, 6, 0, { &D_800A58DC, &D_800A5960, &D_800A59E4, &D_800A5A68 } },
    { 274, 9, 0, { &D_800A5AEC, &D_800A5B70, &D_800A5BF4, &D_800A5C78 } },
    { 295, 13, 0, { &D_800A5CFC, &D_800A5D80, &D_800A5E04, &D_800A5E88 } },
    { 307, 16, 0, { &D_800A5F0C, &D_800A5F90, &D_800A6014, &D_800A6098 } },
    { 317, 19, 0, { &D_800A611C, &D_800A61A0, &D_800A6224, &D_800A62A8 } },
    { 323, 20, 0, { &D_800A632C, &D_800A63B0, &D_800A6434, &D_800A64B8 } },
    { 329, 21, 0, { &D_800A653C, &D_800A65C0, &D_800A6644, &D_800A66C8 } },
    { 346, 25, 0, { &D_800A674C, &D_800A67D0, &D_800A6854, &D_800A68D8 } },
    { 352, 27, 0, { &D_800A695C, &D_800A69E0, &D_800A6A64, &D_800A6AE8 } },
    { 356, 28, 0, { &D_800A6B6C, &D_800A6BF0, &D_800A6C74, &D_800A6CF8 } },
    { 363, 29, 0, { &D_800A6D7C, &D_800A6E00, &D_800A6E84, &D_800A6F08 } },
    { 370, 30, 0, { &D_800A6F8C, &D_800A7010, &D_800A7094, &D_800A7118 } },
    { 377, 12, 0, { &D_800A719C, &D_800A7220, &D_800A72A4, &D_800A7328 } },
    { 378, 14, 0, { &D_800A73AC, &D_800A7430, &D_800A74B4, &D_800A7538 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x140, 0x1FF },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x14C, 0x140, 0x30, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x154, 0x140, 0x50, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x140, 0x70, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x164, 0x140, 0x90, 0x40, 0x150, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x140, 0xB0, 0x40, 0x160, 0x1FE },
    { 0x140, 0x100, 0x174, 0x140, 0xD0, 0x40, 0x170, 0x1FE },
    { 0x140, 0x100, 0x14C, 0x160, 0x30, 0x60, 0x140, 0x1FD },
    { 0x140, 0x100, 0x154, 0x160, 0x50, 0x60, 0x150, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FD },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x170, 0x1FD },
};
u16 D_800A7858[] = { 0x11, 0, 0x1C3F, 0, 0xFFFF };
u16 D_800A7864[] = { 0x7645, 1, 0xFFFF };
u16 D_800A786C[] = { 0x11, 0, 0x1C3F, 1, 0xFFFF };
u16 D_800A7878[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A7884[] = { 0x11, 0, 0xFFFF };
u16 D_800A788C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A7898[] = { 0x11, 0, 0x10, 0, 0x1C3F, 1, 0xFFFF };
u16 D_800A78A8[] = { 0x1C40, 0, 0x11, 0, 0xFFFF };
u16 D_800A78B4[] = { 0x7646, 1, 0xFFFF };
u16 D_800A78BC[] = { 0x1C40, 1, 0x11, 0, 0xFFFF };
u16 D_800A78C8[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A78D4[] = { 0x11, 0, 0xFFFF };
u16 D_800A78DC[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A78E8[] = { 0x11, 0, 0x10, 0, 0x1C40, 1, 0x818D, 1, 0xFFFF };
u16 D_800A78FC[] = { 0x11, 0, 0x9220, 0, 0xFFFF };
u16 D_800A7908[] = { 0x7647, 1, 0xFFFF };
u16 D_800A7910[] = { 0x11, 0, 0x9220, 1, 0xFFFF };
u16 D_800A791C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A7928[] = { 0x11, 0, 0xFFFF };
u16 D_800A7930[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A793C[] = { 0x11, 0, 0x10, 0, 0x9220, 1, 0xFFFF };
u16 D_800A794C[] = { 0x9222, 0, 0x11, 0, 0xFFFF };
u16 D_800A7958[] = { 0x7648, 1, 0xFFFF };
u16 D_800A7960[] = { 0x11, 0, 0x9222, 1, 0xFFFF };
u16 D_800A796C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A7978[] = { 0x11, 0, 0xFFFF };
u16 D_800A7980[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A798C[] = { 0x11, 0, 0x10, 0, 0x9222, 1, 0xFFFF };
u16 D_800A799C[] = { 0x11, 0, 0x921F, 0, 0xFFFF };
u16 D_800A79A8[] = { 0x764B, 1, 0xFFFF };
u16 D_800A79B0[] = { 0x11, 0, 0x921F, 1, 0xFFFF };
u16 D_800A79BC[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A79C8[] = { 0x11, 0, 0xFFFF };
u16 D_800A79D0[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A79DC[] = { 0x11, 0, 0x10, 0, 0x921F, 1, 0xFFFF };
u16 D_800A79EC[] = { 0x11, 0, 0x9245, 0, 0xFFFF };
u16 D_800A79F8[] = { 0x764E, 1, 0xFFFF };
u16 D_800A7A00[] = { 0x11, 0, 0x9245, 1, 0xFFFF };
u16 D_800A7A0C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A7A18[] = { 0x11, 0, 0xFFFF };
u16 D_800A7A20[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A7A2C[] = { 0x11, 0, 0x10, 0, 0x9245, 1, 0xFFFF };
u16 D_800A7A3C[] = { 0x11, 0, 0x92F1, 0, 0xFFFF };
u16 D_800A7A48[] = { 0x764F, 1, 0xFFFF };
u16 D_800A7A50[] = { 0x11, 0, 0x92F1, 1, 0xFFFF };
u16 D_800A7A5C[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A7A68[] = { 0x11, 0, 0xFFFF };
u16 D_800A7A70[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A7A7C[] = { 0x11, 0, 0x10, 0, 0x92F1, 1, 0xFFFF };
u16 D_800A7A8C[] = { 0x11, 0, 0x9270, 0, 0xFFFF };
u16 D_800A7A98[] = { 0x7650, 1, 0xFFFF };
u16 D_800A7AA0[] = { 0x11, 0, 0x9270, 1, 0xFFFF };
u16 D_800A7AAC[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A7AB8[] = { 0x11, 0, 0xFFFF };
u16 D_800A7AC0[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A7ACC[] = { 0x11, 0, 0x10, 0, 0x9270, 1, 0xFFFF };
FieldTalk D_800A7ADC[] = {
    { D_800A7858, D_800A7864, 0x37F },
    { D_800A786C, NULL, 0x380 },
    { D_800A7878, D_800A7884, 0x381 },
    { D_800A788C, D_800A7898, 0x382 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7B18[] = {
    { D_800A78A8, D_800A78B4, 0x383 },
    { D_800A78BC, NULL, 0x384 },
    { D_800A78C8, D_800A78D4, 0x385 },
    { D_800A78DC, D_800A78E8, 0x386 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7B54[] = {
    { D_800A78FC, D_800A7908, 0x367 },
    { D_800A7910, NULL, 0x368 },
    { D_800A791C, D_800A7928, 0x369 },
    { D_800A7930, D_800A793C, 0x36A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7B90[] = {
    { D_800A794C, D_800A7958, 0x367 },
    { D_800A7960, NULL, 0x368 },
    { D_800A796C, D_800A7978, 0x369 },
    { D_800A7980, D_800A798C, 0x36B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7BCC[] = {
    { D_800A799C, D_800A79A8, 0x367 },
    { D_800A79B0, NULL, 0x368 },
    { D_800A79BC, D_800A79C8, 0x369 },
    { D_800A79D0, D_800A79DC, 0x36E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7C08[] = {
    { D_800A79EC, D_800A79F8, 0x377 },
    { D_800A7A00, NULL, 0x378 },
    { D_800A7A0C, D_800A7A18, 0x379 },
    { D_800A7A20, D_800A7A2C, 0x37C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7C44[] = {
    { D_800A7A3C, D_800A7A48, 0x377 },
    { D_800A7A50, NULL, 0x378 },
    { D_800A7A5C, D_800A7A68, 0x379 },
    { D_800A7A70, D_800A7A7C, 0x37D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7C80[] = {
    { D_800A7A8C, D_800A7A98, 0x377 },
    { D_800A7AA0, NULL, 0x378 },
    { D_800A7AAC, D_800A7AB8, 0x379 },
    { D_800A7AC0, D_800A7ACC, 0x37E },
    { NULL, NULL, 0 },
};
u16 D_800A7CBC[] = { 0x7E08, 1, 8, 0, 0xFFFF };
u16 D_800A7CC8[] = { 0x7E0D, 1, 0x7E1E, 1, 0x1C42, 1, 0x1C3F, 0, 0xFFFF };
u16 D_800A7CDC[] = { 0x7E1B, 1, 0x7E1F, 1, 0x1C3F, 1, 0x1C40, 0, 0xFFFF };
u16 D_800A7CF0[] = { 0x8014, 1, 0x9220, 0, 0x7E1A, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A7D04[] = { 0x7E05, 1, 0x7E1F, 1, 0x8014, 1, 0x9222, 0, 0xFFFF };
u16 D_800A7D18[] = { 0x7E1C, 1, 0x7E1E, 1, 0x8014, 1, 0x921F, 0, 0xFFFF };
u16 D_800A7D2C[] = { 0x7E14, 1, 0x7E1E, 1, 0x8014, 1, 0x9245, 0, 0xFFFF };
u16 D_800A7D40[] = { 0x7E12, 1, 0x7E1E, 1, 0x8014, 1, 0x92F1, 0, 0xFFFF };
u16 D_800A7D54[] = { 0x7E08, 1, 0x7E1F, 1, 0x8014, 1, 0x9270, 0, 0xFFFF };
u16 D_800A7D68[] = { 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A7D74[] = { 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A7D80[] = { 0x7E01, 1, 0xA, 0, 0xFFFF };
u16 D_800A7D8C[] = { 0x7E05, 1, 0xA, 0, 0xFFFF };
u16 D_800A7D98[] = { 0x7E08, 1, 0xA, 0, 0xFFFF };
u16 D_800A7DA4[] = { 0x7E0C, 1, 0xA, 0, 0xFFFF };
u16 D_800A7DB0[] = { 0x7E0D, 1, 0xA, 0, 0xFFFF };
u16 D_800A7DBC[] = { 0x7E12, 1, 0xA, 0, 0xFFFF };
u16 D_800A7DC8[] = { 0x7E13, 1, 0xA, 0, 0xFFFF };
u16 D_800A7DD4[] = { 0x7E14, 1, 0xA, 0, 0xFFFF };
u16 D_800A7DE0[] = { 0x7E1B, 1, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A7DEC = { NULL, NULL, 0x146, 4, 0, 0, 0 };
FieldActorEntry D_800A7E00 = { D_800A7CBC, NULL, 0x148, 5, 368, 440, 1 };
FieldActorEntry D_800A7E14 = { D_800A7CC8, D_800A7ADC, 0x14D, 6, 432, 144, 7 };
FieldActorEntry D_800A7E28 = { D_800A7CDC, D_800A7B18, 0x14E, 7, 432, 144, 7 };
FieldActorEntry D_800A7E3C = { D_800A7CF0, D_800A7B54, 0x14F, 8, 432, 144, 7 };
FieldActorEntry D_800A7E50 = { D_800A7D04, D_800A7B90, 0x150, 9, 432, 144, 7 };
FieldActorEntry D_800A7E64 = { D_800A7D18, D_800A7BCC, 0x153, 0xA, 432, 144, 7 };
FieldActorEntry D_800A7E78 = { D_800A7D2C, D_800A7C08, 0x15C, 0xB, 432, 144, 7 };
FieldActorEntry D_800A7E8C = { D_800A7D40, D_800A7C44, 0x15D, 0xC, 432, 144, 7 };
FieldActorEntry D_800A7EA0 = { D_800A7D54, D_800A7C80, 0x15E, 0xD, 432, 144, 7 };
FieldActorEntry D_800A7EB4 = { D_800A7D68, NULL, 0x15F, 0xE, 384, 336, 1 };
FieldActorEntry D_800A7EC8 = { D_800A7D74, NULL, 0x15F, 0xE, 272, 488, 1 };
FieldActorEntry D_800A7EDC = { D_800A7D80, NULL, 0x160, 0xF, 392, 380, 1 };
FieldActorEntry D_800A7EF0 = { D_800A7D8C, NULL, 0x160, 0xF, 320, 368, 1 };
FieldActorEntry D_800A7F04 = { D_800A7D98, NULL, 0x160, 0xF, 544, 176, 1 };
FieldActorEntry D_800A7F18 = { D_800A7DA4, NULL, 0x160, 0xF, 528, 264, 1 };
FieldActorEntry D_800A7F2C = { D_800A7DB0, NULL, 0x160, 0xF, 520, 220, 1 };
FieldActorEntry D_800A7F40 = { D_800A7DBC, NULL, 0x160, 0xF, 464, 248, 1 };
FieldActorEntry D_800A7F54 = { D_800A7DC8, NULL, 0x160, 0xF, 456, 300, 1 };
FieldActorEntry D_800A7F68 = { D_800A7DD4, NULL, 0x160, 0xF, 480, 192, 1 };
FieldActorEntry D_800A7F7C = { D_800A7DE0, NULL, 0x160, 0xF, 520, 220, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A7DEC,
    &D_800A7E00,
    &D_800A7E14,
    &D_800A7E28,
    &D_800A7E3C,
    &D_800A7E50,
    &D_800A7E64,
    &D_800A7E78,
    &D_800A7E8C,
    &D_800A7EA0,
    &D_800A7EB4,
    &D_800A7EC8,
    &D_800A7EDC,
    &D_800A7EF0,
    &D_800A7F04,
    &D_800A7F18,
    &D_800A7F2C,
    &D_800A7F40,
    &D_800A7F54,
    &D_800A7F68,
    &D_800A7F7C,
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
