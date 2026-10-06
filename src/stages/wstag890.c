#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x686
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x696
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x18200, 0x7E00};
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

extern StagePoint D_800A4F90;
extern StagePoint D_800A4FA0;
extern StagePoint D_800A4FB0;
extern StagePoint D_800A4FC8;
extern StagePoint D_800A4FD8;
extern StagePoint D_800A4FE8;
extern StagePoint D_800A5000;
extern StagePoint D_800A5010;
extern StagePoint D_800A5020;
extern StagePoint D_800A5038;
extern StagePoint D_800A5048;
extern StagePoint D_800A5058;
extern StagePoint D_800A5070;
extern StagePoint D_800A5080;
extern StagePoint D_800A5090;
extern StagePoint D_800A50A8;
extern StagePoint D_800A50B8;
extern StagePoint D_800A50C8;
extern StagePoint D_800A50E0;
extern StagePoint D_800A50F0;
extern StagePoint D_800A5100;
extern StagePoint D_800A5118;
extern StagePoint D_800A5128;
extern StagePoint D_800A5138;
extern StagePoint D_800A5150;
extern StagePoint D_800A5160;
extern StagePoint D_800A5170;
extern StagePoint D_800A5188;
extern StagePoint D_800A5198;
extern StagePoint D_800A51A8;
extern StagePoint D_800A51C0;
extern StagePoint D_800A51D0;
extern StagePoint D_800A51E0;
extern StagePoint D_800A51F8;
extern StagePoint D_800A5208;
extern StagePoint D_800A5218;
extern StagePoint D_800A5230;
extern StagePoint D_800A5240;
extern StagePoint D_800A5250;
extern StagePoint D_800A5268;
extern StagePoint D_800A5278;
extern StagePoint D_800A5288;
extern StagePoint D_800A52A0;
extern StagePoint D_800A52B0;
extern StagePoint D_800A52C0;
extern StagePoint D_800A52D8;
extern StagePoint D_800A52E8;
extern StagePoint D_800A52F8;
extern StagePoint D_800A5310;
extern StagePoint D_800A5320;
extern StagePoint D_800A5330;
extern StagePoint D_800A5348;
extern StagePoint D_800A5358;
extern StagePoint D_800A5368;
extern StagePoint D_800A5380;
extern StagePoint D_800A5390;
extern StagePoint D_800A53A0;
extern StagePoint D_800A53B8;
extern StagePoint D_800A53C8;
extern StagePoint D_800A53D8;
extern StagePoint D_800A53F0;
extern StagePoint D_800A5400;
extern StagePoint D_800A5410;
extern StagePoint D_800A5428;
extern StagePoint D_800A5438;
extern StagePoint D_800A5448;
extern StagePoint D_800A5460;
extern StagePoint D_800A5470;
extern StagePoint D_800A5480;
extern StagePoint D_800A5498;
extern StagePoint D_800A54A8;
extern StagePoint D_800A54B8;
extern StagePoint D_800A54D0;
extern StagePoint D_800A54E0;
extern StagePoint D_800A54F0;
extern StagePoint D_800A5508;
extern StagePoint D_800A5518;
extern StagePoint D_800A5528;
extern StagePoint D_800A5540;
extern StagePoint D_800A5550;
extern StagePoint D_800A5560;
extern StagePoint D_800A5578;
extern StagePoint D_800A5588;
extern StagePoint D_800A5598;
extern StagePoint D_800A55B0;
extern StagePoint D_800A55C0;
extern StagePoint D_800A55D0;
extern StagePoint D_800A55E8;
extern StagePoint D_800A55F8;
extern StagePoint D_800A5608;
extern StagePoint D_800A5620;
extern StagePoint D_800A5630;
extern StagePoint D_800A5640;
extern StagePoint D_800A5658;
extern StagePoint D_800A5668;
extern StagePoint D_800A5678;
extern StagePoint D_800A5690;
extern StagePoint D_800A56A0;
extern StagePoint D_800A56B0;
extern StagePoint D_800A56C8;
extern StagePoint D_800A56D8;
extern StagePoint D_800A56E8;
extern StagePoint D_800A5700;
extern StagePoint D_800A5710;
extern StagePoint D_800A5720;
extern StagePoint D_800A5738;
extern StagePoint D_800A5748;
extern StagePoint D_800A5758;
extern StagePoint D_800A5770;
extern StagePoint D_800A5780;
extern StagePoint D_800A5790;
extern StagePoint D_800A57A8;
extern StagePoint D_800A57B8;
extern StagePoint D_800A57C8;
extern StagePoint D_800A57E0;
extern StagePoint D_800A57F0;
extern StagePoint D_800A5800;
extern StagePoint D_800A5818;
extern StagePoint D_800A5828;
extern StagePoint D_800A5838;
extern StagePoint D_800A5850;
extern StagePoint D_800A5860;
extern StagePoint D_800A5870;
extern StagePoint D_800A5888;
extern StagePoint D_800A5898;
extern StagePoint D_800A58A8;
extern StagePoint D_800A58C0;
extern StagePoint D_800A58D0;
extern StagePoint D_800A58E0;
extern StagePoint D_800A58F8;
extern StagePoint D_800A5908;
extern StagePoint D_800A5918;
extern StagePoint D_800A5930;
extern StagePoint D_800A5940;
extern StagePoint D_800A5950;
extern StagePoint D_800A5968;
extern StagePoint D_800A5978;
extern StagePoint D_800A5988;
extern StagePoint D_800A59A0;
extern StagePoint D_800A59B0;
extern StagePoint D_800A59C0;
extern StagePoints D_800A4FC0;
extern StagePoints D_800A4FF8;
extern StagePoints D_800A5030;
extern StagePoints D_800A5068;
extern StagePoints D_800A50A0;
extern StagePoints D_800A50D8;
extern StagePoints D_800A5110;
extern StagePoints D_800A5148;
extern StagePoints D_800A5180;
extern StagePoints D_800A51B8;
extern StagePoints D_800A51F0;
extern StagePoints D_800A5228;
extern StagePoints D_800A5260;
extern StagePoints D_800A5298;
extern StagePoints D_800A52D0;
extern StagePoints D_800A5308;
extern StagePoints D_800A5340;
extern StagePoints D_800A5378;
extern StagePoints D_800A53B0;
extern StagePoints D_800A53E8;
extern StagePoints D_800A5420;
extern StagePoints D_800A5458;
extern StagePoints D_800A5490;
extern StagePoints D_800A54C8;
extern StagePoints D_800A5500;
extern StagePoints D_800A5538;
extern StagePoints D_800A5570;
extern StagePoints D_800A55A8;
extern StagePoints D_800A55E0;
extern StagePoints D_800A5618;
extern StagePoints D_800A5650;
extern StagePoints D_800A5688;
extern StagePoints D_800A56C0;
extern StagePoints D_800A56F8;
extern StagePoints D_800A5730;
extern StagePoints D_800A5768;
extern StagePoints D_800A57A0;
extern StagePoints D_800A57D8;
extern StagePoints D_800A5810;
extern StagePoints D_800A5848;
extern StagePoints D_800A5880;
extern StagePoints D_800A58B8;
extern StagePoints D_800A58F0;
extern StagePoints D_800A5928;
extern StagePoints D_800A5960;
extern StagePoints D_800A5998;
extern StagePoints D_800A59D0;
extern Battle D_800A5A98;
extern Battle D_800A5AA4;
extern Battle D_800A5AB0;
extern Battle D_800A5ABC;
extern Battle D_800A5AC8;
extern Battle D_800A5AD4;
extern Battle D_800A5AE0;
extern Battle D_800A5AEC;
extern Battle D_800A5B1C;
extern Battle D_800A5B28;
extern Battle D_800A5B34;
extern Battle D_800A5B40;
extern Battle D_800A5B4C;
extern Battle D_800A5B58;
extern Battle D_800A5B64;
extern Battle D_800A5B70;
extern Battle D_800A5BA0;
extern Battle D_800A5BAC;
extern Battle D_800A5BB8;
extern Battle D_800A5BC4;
extern Battle D_800A5BD0;
extern Battle D_800A5BDC;
extern Battle D_800A5BE8;
extern Battle D_800A5BF4;
extern Battle D_800A5C24;
extern Battle D_800A5C30;
extern Battle D_800A5C3C;
extern Battle D_800A5C48;
extern Battle D_800A5C54;
extern Battle D_800A5C60;
extern Battle D_800A5C6C;
extern Battle D_800A5C78;
extern Battle D_800A5CA8;
extern Battle D_800A5CB4;
extern Battle D_800A5CC0;
extern Battle D_800A5CCC;
extern Battle D_800A5CD8;
extern Battle D_800A5CE4;
extern Battle D_800A5CF0;
extern Battle D_800A5CFC;
extern Battle D_800A5D2C;
extern Battle D_800A5D38;
extern Battle D_800A5D44;
extern Battle D_800A5D50;
extern Battle D_800A5D5C;
extern Battle D_800A5D68;
extern Battle D_800A5D74;
extern Battle D_800A5D80;
extern Battle D_800A5DB0;
extern Battle D_800A5DBC;
extern Battle D_800A5DC8;
extern Battle D_800A5DD4;
extern Battle D_800A5DE0;
extern Battle D_800A5DEC;
extern Battle D_800A5DF8;
extern Battle D_800A5E04;
extern Battle D_800A5E34;
extern Battle D_800A5E40;
extern Battle D_800A5E4C;
extern Battle D_800A5E58;
extern Battle D_800A5E64;
extern Battle D_800A5E70;
extern Battle D_800A5E7C;
extern Battle D_800A5E88;
extern Battle D_800A5EB8;
extern Battle D_800A5EC4;
extern Battle D_800A5ED0;
extern Battle D_800A5EDC;
extern Battle D_800A5EE8;
extern Battle D_800A5EF4;
extern Battle D_800A5F00;
extern Battle D_800A5F0C;
extern Battle D_800A5F3C;
extern Battle D_800A5F48;
extern Battle D_800A5F54;
extern Battle D_800A5F60;
extern Battle D_800A5F6C;
extern Battle D_800A5F78;
extern Battle D_800A5F84;
extern Battle D_800A5F90;
extern Battle D_800A5FC0;
extern Battle D_800A5FCC;
extern Battle D_800A5FD8;
extern Battle D_800A5FE4;
extern Battle D_800A5FF0;
extern Battle D_800A5FFC;
extern Battle D_800A6008;
extern Battle D_800A6014;
extern Battle D_800A6044;
extern Battle D_800A6050;
extern Battle D_800A605C;
extern Battle D_800A6068;
extern Battle D_800A6074;
extern Battle D_800A6080;
extern Battle D_800A608C;
extern Battle D_800A6098;
extern Battle D_800A60C8;
extern Battle D_800A60D4;
extern Battle D_800A60E0;
extern Battle D_800A60EC;
extern Battle D_800A60F8;
extern Battle D_800A6104;
extern Battle D_800A6110;
extern Battle D_800A611C;
extern Battle D_800A614C;
extern Battle D_800A6158;
extern Battle D_800A6164;
extern Battle D_800A6170;
extern Battle D_800A617C;
extern Battle D_800A6188;
extern Battle D_800A6194;
extern Battle D_800A61A0;
extern Battle D_800A61D0;
extern Battle D_800A61DC;
extern Battle D_800A61E8;
extern Battle D_800A61F4;
extern Battle D_800A6200;
extern Battle D_800A620C;
extern Battle D_800A6218;
extern Battle D_800A6224;
extern Battle D_800A6254;
extern Battle D_800A6260;
extern Battle D_800A626C;
extern Battle D_800A6278;
extern Battle D_800A6284;
extern Battle D_800A6290;
extern Battle D_800A629C;
extern Battle D_800A62A8;
extern Battle D_800A62D8;
extern Battle D_800A62E4;
extern Battle D_800A62F0;
extern Battle D_800A62FC;
extern Battle D_800A6308;
extern Battle D_800A6314;
extern Battle D_800A6320;
extern Battle D_800A632C;
extern Battle D_800A635C;
extern Battle D_800A6368;
extern Battle D_800A6374;
extern Battle D_800A6380;
extern Battle D_800A638C;
extern Battle D_800A6398;
extern Battle D_800A63A4;
extern Battle D_800A63B0;
extern Battle D_800A63E0;
extern Battle D_800A63EC;
extern Battle D_800A63F8;
extern Battle D_800A6404;
extern Battle D_800A6410;
extern Battle D_800A641C;
extern Battle D_800A6428;
extern Battle D_800A6434;
extern Battle D_800A6464;
extern Battle D_800A6470;
extern Battle D_800A647C;
extern Battle D_800A6488;
extern Battle D_800A6494;
extern Battle D_800A64A0;
extern Battle D_800A64AC;
extern Battle D_800A64B8;
extern Battle D_800A64E8;
extern Battle D_800A64F4;
extern Battle D_800A6500;
extern Battle D_800A650C;
extern Battle D_800A6518;
extern Battle D_800A6524;
extern Battle D_800A6530;
extern Battle D_800A653C;
extern Battle D_800A656C;
extern Battle D_800A6578;
extern Battle D_800A6584;
extern Battle D_800A6590;
extern Battle D_800A659C;
extern Battle D_800A65A8;
extern Battle D_800A65B4;
extern Battle D_800A65C0;
extern Battle D_800A65F0;
extern Battle D_800A65FC;
extern Battle D_800A6608;
extern Battle D_800A6614;
extern Battle D_800A6620;
extern Battle D_800A662C;
extern Battle D_800A6638;
extern Battle D_800A6644;
extern Battle D_800A6674;
extern Battle D_800A6680;
extern Battle D_800A668C;
extern Battle D_800A6698;
extern Battle D_800A66A4;
extern Battle D_800A66B0;
extern Battle D_800A66BC;
extern Battle D_800A66C8;
extern Battle D_800A66F8;
extern Battle D_800A6704;
extern Battle D_800A6710;
extern Battle D_800A671C;
extern Battle D_800A6728;
extern Battle D_800A6734;
extern Battle D_800A6740;
extern Battle D_800A674C;
extern Battle D_800A677C;
extern Battle D_800A6788;
extern Battle D_800A6794;
extern Battle D_800A67A0;
extern Battle D_800A67AC;
extern Battle D_800A67B8;
extern Battle D_800A67C4;
extern Battle D_800A67D0;
extern Battle D_800A6800;
extern Battle D_800A680C;
extern Battle D_800A6818;
extern Battle D_800A6824;
extern Battle D_800A6830;
extern Battle D_800A683C;
extern Battle D_800A6848;
extern Battle D_800A6854;
extern Battle D_800A6884;
extern Battle D_800A6890;
extern Battle D_800A689C;
extern Battle D_800A68A8;
extern Battle D_800A68B4;
extern Battle D_800A68C0;
extern Battle D_800A68CC;
extern Battle D_800A68D8;
extern Battle D_800A6908;
extern Battle D_800A6914;
extern Battle D_800A6920;
extern Battle D_800A692C;
extern Battle D_800A6938;
extern Battle D_800A6944;
extern Battle D_800A6950;
extern Battle D_800A695C;
extern Battle D_800A698C;
extern Battle D_800A6998;
extern Battle D_800A69A4;
extern Battle D_800A69B0;
extern Battle D_800A69BC;
extern Battle D_800A69C8;
extern Battle D_800A69D4;
extern Battle D_800A69E0;
extern Battle D_800A6A10;
extern Battle D_800A6A1C;
extern Battle D_800A6A28;
extern Battle D_800A6A34;
extern Battle D_800A6A40;
extern Battle D_800A6A4C;
extern Battle D_800A6A58;
extern Battle D_800A6A64;
extern Battle D_800A6A94;
extern Battle D_800A6AA0;
extern Battle D_800A6AAC;
extern Battle D_800A6AB8;
extern Battle D_800A6AC4;
extern Battle D_800A6AD0;
extern Battle D_800A6ADC;
extern Battle D_800A6AE8;
extern Battle D_800A6B18;
extern Battle D_800A6B24;
extern Battle D_800A6B30;
extern Battle D_800A6B3C;
extern Battle D_800A6B48;
extern Battle D_800A6B54;
extern Battle D_800A6B60;
extern Battle D_800A6B6C;
extern Battle D_800A6B9C;
extern Battle D_800A6BA8;
extern Battle D_800A6BB4;
extern Battle D_800A6BC0;
extern Battle D_800A6BCC;
extern Battle D_800A6BD8;
extern Battle D_800A6BE4;
extern Battle D_800A6BF0;
extern Battle D_800A6C20;
extern Battle D_800A6C2C;
extern Battle D_800A6C38;
extern Battle D_800A6C44;
extern Battle D_800A6C50;
extern Battle D_800A6C5C;
extern Battle D_800A6C68;
extern Battle D_800A6C74;
extern Battle D_800A6CA4;
extern Battle D_800A6CB0;
extern Battle D_800A6CBC;
extern Battle D_800A6CC8;
extern Battle D_800A6CD4;
extern Battle D_800A6CE0;
extern Battle D_800A6CEC;
extern Battle D_800A6CF8;
extern Battle D_800A6D28;
extern Battle D_800A6D34;
extern Battle D_800A6D40;
extern Battle D_800A6D4C;
extern Battle D_800A6D58;
extern Battle D_800A6D64;
extern Battle D_800A6D70;
extern Battle D_800A6D7C;
extern Battle D_800A6DAC;
extern Battle D_800A6DB8;
extern Battle D_800A6DC4;
extern Battle D_800A6DD0;
extern Battle D_800A6DDC;
extern Battle D_800A6DE8;
extern Battle D_800A6DF4;
extern Battle D_800A6E00;
extern Battle D_800A6E30;
extern Battle D_800A6E3C;
extern Battle D_800A6E48;
extern Battle D_800A6E54;
extern Battle D_800A6E60;
extern Battle D_800A6E6C;
extern Battle D_800A6E78;
extern Battle D_800A6E84;
extern Battle D_800A6EB4;
extern Battle D_800A6EC0;
extern Battle D_800A6ECC;
extern Battle D_800A6ED8;
extern Battle D_800A6EE4;
extern Battle D_800A6EF0;
extern Battle D_800A6EFC;
extern Battle D_800A6F08;
extern Battle D_800A6F38;
extern Battle D_800A6F44;
extern Battle D_800A6F50;
extern Battle D_800A6F5C;
extern Battle D_800A6F68;
extern Battle D_800A6F74;
extern Battle D_800A6F80;
extern Battle D_800A6F8C;
extern Battle D_800A6FBC;
extern Battle D_800A6FC8;
extern Battle D_800A6FD4;
extern Battle D_800A6FE0;
extern Battle D_800A6FEC;
extern Battle D_800A6FF8;
extern Battle D_800A7004;
extern Battle D_800A7010;
extern Battle D_800A7040;
extern Battle D_800A704C;
extern Battle D_800A7058;
extern Battle D_800A7064;
extern Battle D_800A7070;
extern Battle D_800A707C;
extern Battle D_800A7088;
extern Battle D_800A7094;
extern Battle D_800A70C4;
extern Battle D_800A70D0;
extern Battle D_800A70DC;
extern Battle D_800A70E8;
extern Battle D_800A70F4;
extern Battle D_800A7100;
extern Battle D_800A710C;
extern Battle D_800A7118;
extern Battle D_800A7148;
extern Battle D_800A7154;
extern Battle D_800A7160;
extern Battle D_800A716C;
extern Battle D_800A7178;
extern Battle D_800A7184;
extern Battle D_800A7190;
extern Battle D_800A719C;
extern Battle D_800A71CC;
extern Battle D_800A71D8;
extern Battle D_800A71E4;
extern Battle D_800A71F0;
extern Battle D_800A71FC;
extern Battle D_800A7208;
extern Battle D_800A7214;
extern Battle D_800A7220;
extern Battle D_800A7250;
extern Battle D_800A725C;
extern Battle D_800A7268;
extern Battle D_800A7274;
extern Battle D_800A7280;
extern Battle D_800A728C;
extern Battle D_800A7298;
extern Battle D_800A72A4;
extern Battle D_800A72D4;
extern Battle D_800A72E0;
extern Battle D_800A72EC;
extern Battle D_800A72F8;
extern Battle D_800A7304;
extern Battle D_800A7310;
extern Battle D_800A731C;
extern Battle D_800A7328;
extern Battle D_800A7358;
extern Battle D_800A7364;
extern Battle D_800A7370;
extern Battle D_800A737C;
extern Battle D_800A7388;
extern Battle D_800A7394;
extern Battle D_800A73A0;
extern Battle D_800A73AC;
extern Battle D_800A73DC;
extern Battle D_800A73E8;
extern Battle D_800A73F4;
extern Battle D_800A7400;
extern Battle D_800A740C;
extern Battle D_800A7418;
extern Battle D_800A7424;
extern Battle D_800A7430;
extern Battle D_800A7460;
extern Battle D_800A746C;
extern Battle D_800A7478;
extern Battle D_800A7484;
extern Battle D_800A7490;
extern Battle D_800A749C;
extern Battle D_800A74A8;
extern Battle D_800A74B4;
extern Battle D_800A74E4;
extern Battle D_800A74F0;
extern Battle D_800A74FC;
extern Battle D_800A7508;
extern Battle D_800A7514;
extern Battle D_800A7520;
extern Battle D_800A752C;
extern Battle D_800A7538;
extern Battle D_800A7568;
extern Battle D_800A7574;
extern Battle D_800A7580;
extern Battle D_800A758C;
extern Battle D_800A7598;
extern Battle D_800A75A4;
extern Battle D_800A75B0;
extern Battle D_800A75BC;
extern Battle D_800A75EC;
extern Battle D_800A75F8;
extern Battle D_800A7604;
extern Battle D_800A7610;
extern Battle D_800A761C;
extern Battle D_800A7628;
extern Battle D_800A7634;
extern Battle D_800A7640;
extern Battle D_800A7670;
extern Battle D_800A767C;
extern Battle D_800A7688;
extern Battle D_800A7694;
extern Battle D_800A76A0;
extern Battle D_800A76AC;
extern Battle D_800A76B8;
extern Battle D_800A76C4;
extern Battle D_800A76F4;
extern Battle D_800A7700;
extern Battle D_800A770C;
extern Battle D_800A7718;
extern Battle D_800A7724;
extern Battle D_800A7730;
extern Battle D_800A773C;
extern Battle D_800A7748;
extern Battle D_800A7778;
extern Battle D_800A7784;
extern Battle D_800A7790;
extern Battle D_800A779C;
extern Battle D_800A77A8;
extern Battle D_800A77B4;
extern Battle D_800A77C0;
extern Battle D_800A77CC;
extern Battle D_800A77FC;
extern Battle D_800A7808;
extern Battle D_800A7814;
extern Battle D_800A7820;
extern Battle D_800A782C;
extern Battle D_800A7838;
extern Battle D_800A7844;
extern Battle D_800A7850;
extern Battle D_800A7880;
extern Battle D_800A788C;
extern Battle D_800A7898;
extern Battle D_800A78A4;
extern Battle D_800A78B0;
extern Battle D_800A78BC;
extern Battle D_800A78C8;
extern Battle D_800A78D4;
extern Battle D_800A7904;
extern Battle D_800A7910;
extern Battle D_800A791C;
extern Battle D_800A7928;
extern Battle D_800A7934;
extern Battle D_800A7940;
extern Battle D_800A794C;
extern Battle D_800A7958;
extern Battle D_800A7988;
extern Battle D_800A7994;
extern Battle D_800A79A0;
extern Battle D_800A79AC;
extern Battle D_800A79B8;
extern Battle D_800A79C4;
extern Battle D_800A79D0;
extern Battle D_800A79DC;
extern Battle D_800A7A0C;
extern Battle D_800A7A18;
extern Battle D_800A7A24;
extern Battle D_800A7A30;
extern Battle D_800A7A3C;
extern Battle D_800A7A48;
extern Battle D_800A7A54;
extern Battle D_800A7A60;
extern Battle D_800A7A90;
extern Battle D_800A7A9C;
extern Battle D_800A7AA8;
extern Battle D_800A7AB4;
extern Battle D_800A7AC0;
extern Battle D_800A7ACC;
extern Battle D_800A7AD8;
extern Battle D_800A7AE4;
extern Battle D_800A7B14;
extern Battle D_800A7B20;
extern Battle D_800A7B2C;
extern Battle D_800A7B38;
extern Battle D_800A7B44;
extern Battle D_800A7B50;
extern Battle D_800A7B5C;
extern Battle D_800A7B68;
extern Battle D_800A7B98;
extern Battle D_800A7BA4;
extern Battle D_800A7BB0;
extern Battle D_800A7BBC;
extern Battle D_800A7BC8;
extern Battle D_800A7BD4;
extern Battle D_800A7BE0;
extern Battle D_800A7BEC;
extern Battle D_800A7C1C;
extern Battle D_800A7C28;
extern Battle D_800A7C34;
extern Battle D_800A7C40;
extern Battle D_800A7C4C;
extern Battle D_800A7C58;
extern Battle D_800A7C64;
extern Battle D_800A7C70;
extern Battle D_800A7CA0;
extern Battle D_800A7CAC;
extern Battle D_800A7CB8;
extern Battle D_800A7CC4;
extern Battle D_800A7CD0;
extern Battle D_800A7CDC;
extern Battle D_800A7CE8;
extern Battle D_800A7CF4;
extern Battle D_800A7D24;
extern Battle D_800A7D30;
extern Battle D_800A7D3C;
extern Battle D_800A7D48;
extern Battle D_800A7D54;
extern Battle D_800A7D60;
extern Battle D_800A7D6C;
extern Battle D_800A7D78;
extern Battle D_800A7DA8;
extern Battle D_800A7DB4;
extern Battle D_800A7DC0;
extern Battle D_800A7DCC;
extern Battle D_800A7DD8;
extern Battle D_800A7DE4;
extern Battle D_800A7DF0;
extern Battle D_800A7DFC;
extern Battle D_800A7E2C;
extern Battle D_800A7E38;
extern Battle D_800A7E44;
extern Battle D_800A7E50;
extern Battle D_800A7E5C;
extern Battle D_800A7E68;
extern Battle D_800A7E74;
extern Battle D_800A7E80;
extern Battle D_800A7EB0;
extern Battle D_800A7EBC;
extern Battle D_800A7EC8;
extern Battle D_800A7ED4;
extern Battle D_800A7EE0;
extern Battle D_800A7EEC;
extern Battle D_800A7EF8;
extern Battle D_800A7F04;
extern Battle D_800A7F34;
extern Battle D_800A7F40;
extern Battle D_800A7F4C;
extern Battle D_800A7F58;
extern Battle D_800A7F64;
extern Battle D_800A7F70;
extern Battle D_800A7F7C;
extern Battle D_800A7F88;
extern Battle D_800A7FB8;
extern Battle D_800A7FC4;
extern Battle D_800A7FD0;
extern Battle D_800A7FDC;
extern Battle D_800A7FE8;
extern Battle D_800A7FF4;
extern Battle D_800A8000;
extern Battle D_800A800C;
extern Battle D_800A803C;
extern Battle D_800A8048;
extern Battle D_800A8054;
extern Battle D_800A8060;
extern Battle D_800A806C;
extern Battle D_800A8078;
extern Battle D_800A8084;
extern Battle D_800A8090;
extern Battle D_800A80C0;
extern Battle D_800A80CC;
extern Battle D_800A80D8;
extern Battle D_800A80E4;
extern Battle D_800A80F0;
extern Battle D_800A80FC;
extern Battle D_800A8108;
extern Battle D_800A8114;
extern Battle D_800A8144;
extern Battle D_800A8150;
extern Battle D_800A815C;
extern Battle D_800A8168;
extern Battle D_800A8174;
extern Battle D_800A8180;
extern Battle D_800A818C;
extern Battle D_800A8198;
extern Battle D_800A81C8;
extern Battle D_800A81D4;
extern Battle D_800A81E0;
extern Battle D_800A81EC;
extern Battle D_800A81F8;
extern Battle D_800A8204;
extern Battle D_800A8210;
extern Battle D_800A821C;
extern Battle D_800A824C;
extern Battle D_800A8258;
extern Battle D_800A8264;
extern Battle D_800A8270;
extern Battle D_800A827C;
extern Battle D_800A8288;
extern Battle D_800A8294;
extern Battle D_800A82A0;
extern Battle D_800A82D0;
extern Battle D_800A82DC;
extern Battle D_800A82E8;
extern Battle D_800A82F4;
extern Battle D_800A8300;
extern Battle D_800A830C;
extern Battle D_800A8318;
extern Battle D_800A8324;
extern Battle D_800A8354;
extern Battle D_800A8360;
extern Battle D_800A836C;
extern Battle D_800A8378;
extern Battle D_800A8384;
extern Battle D_800A8390;
extern Battle D_800A839C;
extern Battle D_800A83A8;
extern Battle D_800A83D8;
extern Battle D_800A83E4;
extern Battle D_800A83F0;
extern Battle D_800A83FC;
extern Battle D_800A8408;
extern Battle D_800A8414;
extern Battle D_800A8420;
extern Battle D_800A842C;
extern Battle D_800A845C;
extern Battle D_800A8468;
extern Battle D_800A8474;
extern Battle D_800A8480;
extern Battle D_800A848C;
extern Battle D_800A8498;
extern Battle D_800A84A4;
extern Battle D_800A84B0;
extern Battle D_800A84E0;
extern Battle D_800A84EC;
extern Battle D_800A84F8;
extern Battle D_800A8504;
extern Battle D_800A8510;
extern Battle D_800A851C;
extern Battle D_800A8528;
extern Battle D_800A8534;
extern Battle D_800A8564;
extern Battle D_800A8570;
extern Battle D_800A857C;
extern Battle D_800A8588;
extern Battle D_800A8594;
extern Battle D_800A85A0;
extern Battle D_800A85AC;
extern Battle D_800A85B8;
extern BattleList D_800A5AF8;
extern BattleList D_800A5B7C;
extern BattleList D_800A5C00;
extern BattleList D_800A5C84;
extern BattleList D_800A5D08;
extern BattleList D_800A5D8C;
extern BattleList D_800A5E10;
extern BattleList D_800A5E94;
extern BattleList D_800A5F18;
extern BattleList D_800A5F9C;
extern BattleList D_800A6020;
extern BattleList D_800A60A4;
extern BattleList D_800A6128;
extern BattleList D_800A61AC;
extern BattleList D_800A6230;
extern BattleList D_800A62B4;
extern BattleList D_800A6338;
extern BattleList D_800A63BC;
extern BattleList D_800A6440;
extern BattleList D_800A64C4;
extern BattleList D_800A6548;
extern BattleList D_800A65CC;
extern BattleList D_800A6650;
extern BattleList D_800A66D4;
extern BattleList D_800A6758;
extern BattleList D_800A67DC;
extern BattleList D_800A6860;
extern BattleList D_800A68E4;
extern BattleList D_800A6968;
extern BattleList D_800A69EC;
extern BattleList D_800A6A70;
extern BattleList D_800A6AF4;
extern BattleList D_800A6B78;
extern BattleList D_800A6BFC;
extern BattleList D_800A6C80;
extern BattleList D_800A6D04;
extern BattleList D_800A6D88;
extern BattleList D_800A6E0C;
extern BattleList D_800A6E90;
extern BattleList D_800A6F14;
extern BattleList D_800A6F98;
extern BattleList D_800A701C;
extern BattleList D_800A70A0;
extern BattleList D_800A7124;
extern BattleList D_800A71A8;
extern BattleList D_800A722C;
extern BattleList D_800A72B0;
extern BattleList D_800A7334;
extern BattleList D_800A73B8;
extern BattleList D_800A743C;
extern BattleList D_800A74C0;
extern BattleList D_800A7544;
extern BattleList D_800A75C8;
extern BattleList D_800A764C;
extern BattleList D_800A76D0;
extern BattleList D_800A7754;
extern BattleList D_800A77D8;
extern BattleList D_800A785C;
extern BattleList D_800A78E0;
extern BattleList D_800A7964;
extern BattleList D_800A79E8;
extern BattleList D_800A7A6C;
extern BattleList D_800A7AF0;
extern BattleList D_800A7B74;
extern BattleList D_800A7BF8;
extern BattleList D_800A7C7C;
extern BattleList D_800A7D00;
extern BattleList D_800A7D84;
extern BattleList D_800A7E08;
extern BattleList D_800A7E8C;
extern BattleList D_800A7F10;
extern BattleList D_800A7F94;
extern BattleList D_800A8018;
extern BattleList D_800A809C;
extern BattleList D_800A8120;
extern BattleList D_800A81A4;
extern BattleList D_800A8228;
extern BattleList D_800A82AC;
extern BattleList D_800A8330;
extern BattleList D_800A83B4;
extern BattleList D_800A8438;
extern BattleList D_800A84BC;
extern BattleList D_800A8540;
extern BattleList D_800A85C4;
extern u16 D_800A8B1C[];
extern FieldTalk D_800A8954[];
extern u16 D_800A8B28[];
extern FieldTalk D_800A896C[];
extern u16 D_800A8B34[];
extern FieldTalk D_800A8984[];
extern u16 D_800A8B40[];
extern FieldTalk D_800A899C[];
extern u16 D_800A8B4C[];
extern FieldTalk D_800A89B4[];
extern u16 D_800A8B58[];
extern FieldTalk D_800A89CC[];
extern u16 D_800A8B64[];
extern FieldTalk D_800A89E4[];
extern u16 D_800A8B70[];
extern FieldTalk D_800A89FC[];
extern u16 D_800A8B7C[];
extern FieldTalk D_800A8A14[];
extern u16 D_800A8B88[];
extern FieldTalk D_800A8A2C[];
extern u16 D_800A8B94[];
extern FieldTalk D_800A8A44[];
extern u16 D_800A8BA0[];
extern FieldTalk D_800A8A5C[];
extern u16 D_800A8BAC[];
extern FieldTalk D_800A8A74[];
extern u16 D_800A8BB8[];
extern FieldTalk D_800A8A8C[];
extern u16 D_800A8BC4[];
extern FieldTalk D_800A8AA4[];
extern u16 D_800A8BD0[];
extern FieldTalk D_800A8ABC[];
extern u16 D_800A8BDC[];
extern FieldTalk D_800A8AD4[];
extern u16 D_800A8BE8[];
extern FieldTalk D_800A8AEC[];
extern u16 D_800A8BF4[];
extern FieldTalk D_800A8B04[];
extern u16 D_800A8C00[];
extern u16 D_800A8C0C[];
extern u16 D_800A8C18[];
extern u16 D_800A8C24[];
extern u16 D_800A8C30[];
extern u16 D_800A8C3C[];
extern u16 D_800A8C48[];
extern u16 D_800A8C54[];
extern u16 D_800A8C60[];
extern u16 D_800A8C6C[];
extern u16 D_800A8C78[];
extern u16 D_800A8C84[];
extern u16 D_800A8C90[];
extern FieldActorEntry D_800A8C9C;
extern FieldActorEntry D_800A8CB0;
extern FieldActorEntry D_800A8CC4;
extern FieldActorEntry D_800A8CD8;
extern FieldActorEntry D_800A8CEC;
extern FieldActorEntry D_800A8D00;
extern FieldActorEntry D_800A8D14;
extern FieldActorEntry D_800A8D28;
extern FieldActorEntry D_800A8D3C;
extern FieldActorEntry D_800A8D50;
extern FieldActorEntry D_800A8D64;
extern FieldActorEntry D_800A8D78;
extern FieldActorEntry D_800A8D8C;
extern FieldActorEntry D_800A8DA0;
extern FieldActorEntry D_800A8DB4;
extern FieldActorEntry D_800A8DC8;
extern FieldActorEntry D_800A8DDC;
extern FieldActorEntry D_800A8DF0;
extern FieldActorEntry D_800A8E04;
extern FieldActorEntry D_800A8E18;
extern FieldActorEntry D_800A8E2C;
extern FieldActorEntry D_800A8E40;
extern FieldActorEntry D_800A8E54;
extern FieldActorEntry D_800A8E68;
extern FieldActorEntry D_800A8E7C;
extern FieldActorEntry D_800A8E90;
extern FieldActorEntry D_800A8EA4;
extern FieldActorEntry D_800A8EB8;
extern FieldActorEntry D_800A8ECC;
extern FieldActorEntry D_800A8EE0;
extern FieldActorEntry D_800A8EF4;
extern FieldActorEntry D_800A8F08;
extern FieldActorEntry D_800A8F1C;

StagePoint D_800A4F90 = { 0x2EB, 1, 1, 0x240, 160, 1, NULL };
StagePoint D_800A4FA0 = { 0x2EE, 1, 1, 0x130, 200, 1, &D_800A4F90 };
StagePoint D_800A4FB0 = { 0x2E8, 1, 2, 176, 0x168, 5, &D_800A4FA0 };
StagePoints D_800A4FC0 = { 1, 1, &D_800A4FB0 };
StagePoint D_800A4FC8 = { 0x2EE, 1, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A4FD8 = { 0x2E9, 1, 1, 0x240, 240, 1, &D_800A4FC8 };
StagePoint D_800A4FE8 = { 0x2EC, 1, 1, 240, 0x1D8, 5, &D_800A4FD8 };
StagePoints D_800A4FF8 = { 1, 2, &D_800A4FE8 };
StagePoint D_800A5000 = { 0x2EE, 2, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5010 = { 0x2E9, 2, 1, 0x240, 240, 1, &D_800A5000 };
StagePoint D_800A5020 = { 0x2EA, 2, 1, 224, 0x200, 5, &D_800A5010 };
StagePoints D_800A5030 = { 2, 1, &D_800A5020 };
StagePoint D_800A5038 = { 0x2EE, 2, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5048 = { 0x2E9, 2, 2, 0x240, 240, 1, &D_800A5038 };
StagePoint D_800A5058 = { 0x2EE, 2, 1, 224, 0x240, 5, &D_800A5048 };
StagePoints D_800A5068 = { 2, 2, &D_800A5058 };
StagePoint D_800A5070 = { 0x2EE, 3, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5080 = { 0x2EE, 3, 2, 0x130, 200, 1, &D_800A5070 };
StagePoint D_800A5090 = { 0x2E8, 3, 2, 176, 0x168, 5, &D_800A5080 };
StagePoints D_800A50A0 = { 3, 1, &D_800A5090 };
StagePoint D_800A50A8 = { 0x2EC, 3, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A50B8 = { 0x2EE, 3, 3, 0x130, 200, 1, &D_800A50A8 };
StagePoint D_800A50C8 = { 0x2EE, 3, 1, 224, 0x240, 5, &D_800A50B8 };
StagePoints D_800A50D8 = { 3, 2, &D_800A50C8 };
StagePoint D_800A50E0 = { 0x2EE, 3, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A50F0 = { 0x2EE, 3, 4, 0x130, 200, 1, &D_800A50E0 };
StagePoint D_800A5100 = { 0x2EE, 3, 2, 224, 0x240, 5, &D_800A50F0 };
StagePoints D_800A5110 = { 3, 3, &D_800A5100 };
StagePoint D_800A5118 = { 0x2EE, 3, 4, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5128 = { 0x2EE, 3, 5, 0x130, 200, 1, &D_800A5118 };
StagePoint D_800A5138 = { 0x2E8, 3, 4, 176, 0x168, 5, &D_800A5128 };
StagePoints D_800A5148 = { 3, 4, &D_800A5138 };
StagePoint D_800A5150 = { 0x2EE, 4, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5160 = { 0x2E9, 4, 1, 0x240, 240, 1, &D_800A5150 };
StagePoint D_800A5170 = { 0x2EE, 4, 1, 224, 0x240, 5, &D_800A5160 };
StagePoints D_800A5180 = { 4, 1, &D_800A5170 };
StagePoint D_800A5188 = { 0x2EB, 4, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5198 = { 0x2E9, 4, 2, 0x240, 240, 1, &D_800A5188 };
StagePoint D_800A51A8 = { 0x2EE, 4, 2, 224, 0x240, 5, &D_800A5198 };
StagePoints D_800A51B8 = { 4, 2, &D_800A51A8 };
StagePoint D_800A51C0 = { 0x2EE, 5, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A51D0 = { 0x2EE, 5, 2, 0x130, 200, 1, &D_800A51C0 };
StagePoint D_800A51E0 = { 0x2EA, 5, 1, 224, 0x200, 5, &D_800A51D0 };
StagePoints D_800A51F0 = { 5, 1, &D_800A51E0 };
StagePoint D_800A51F8 = { 0x2E9, 5, 1, 0x240, 240, 1, NULL };
StagePoint D_800A5208 = { 0x2EE, 5, 3, 0x130, 200, 1, &D_800A51F8 };
StagePoint D_800A5218 = { 0x2EE, 5, 1, 224, 0x240, 5, &D_800A5208 };
StagePoints D_800A5228 = { 5, 2, &D_800A5218 };
StagePoint D_800A5230 = { 0x2EE, 5, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5240 = { 0x2EE, 5, 4, 0x130, 200, 1, &D_800A5230 };
StagePoint D_800A5250 = { 0x2EE, 5, 2, 224, 0x240, 5, &D_800A5240 };
StagePoints D_800A5260 = { 5, 3, &D_800A5250 };
StagePoint D_800A5268 = { 0x2EE, 5, 4, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5278 = { 0x2EC, 5, 1, 0x3B0, 120, 1, &D_800A5268 };
StagePoint D_800A5288 = { 0x2E8, 5, 3, 176, 0x168, 5, &D_800A5278 };
StagePoints D_800A5298 = { 5, 4, &D_800A5288 };
StagePoint D_800A52A0 = { 0x2EE, 6, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A52B0 = { 0x2EE, 6, 2, 0x130, 200, 1, &D_800A52A0 };
StagePoint D_800A52C0 = { 0x2E8, 6, 1, 176, 0x168, 5, &D_800A52B0 };
StagePoints D_800A52D0 = { 6, 1, &D_800A52C0 };
StagePoint D_800A52D8 = { 0x2EE, 6, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A52E8 = { 0x2EC, 6, 2, 0x3B0, 120, 1, &D_800A52D8 };
StagePoint D_800A52F8 = { 0x2EA, 6, 2, 224, 0x200, 5, &D_800A52E8 };
StagePoints D_800A5308 = { 6, 2, &D_800A52F8 };
StagePoint D_800A5310 = { 0x2E9, 8, 1, 0x240, 240, 1, NULL };
StagePoint D_800A5320 = { 0x2EE, 8, 1, 0x130, 200, 1, &D_800A5310 };
StagePoint D_800A5330 = { 0x2E8, 8, 1, 176, 0x168, 5, &D_800A5320 };
StagePoints D_800A5340 = { 8, 1, &D_800A5330 };
StagePoint D_800A5348 = { 0x2EE, 8, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5358 = { 0x2E9, 8, 3, 0x240, 240, 1, &D_800A5348 };
StagePoint D_800A5368 = { 0x2EC, 8, 1, 240, 0x1D8, 5, &D_800A5358 };
StagePoints D_800A5378 = { 8, 2, &D_800A5368 };
StagePoint D_800A5380 = { 0x2EE, 9, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5390 = { 0x2E9, 9, 1, 0x240, 240, 1, &D_800A5380 };
StagePoint D_800A53A0 = { 0x2EA, 9, 1, 224, 0x200, 5, &D_800A5390 };
StagePoints D_800A53B0 = { 9, 1, &D_800A53A0 };
StagePoint D_800A53B8 = { 0x2EE, 9, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A53C8 = { 0x2E9, 9, 3, 0x240, 240, 1, &D_800A53B8 };
StagePoint D_800A53D8 = { 0x2EE, 9, 1, 224, 0x240, 5, &D_800A53C8 };
StagePoints D_800A53E8 = { 9, 2, &D_800A53D8 };
StagePoint D_800A53F0 = { 0x2EE, 10, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5400 = { 0x2EC, 10, 2, 0x3B0, 120, 1, &D_800A53F0 };
StagePoint D_800A5410 = { 0x2E8, 10, 2, 176, 0x168, 5, &D_800A5400 };
StagePoints D_800A5420 = { 10, 1, &D_800A5410 };
StagePoint D_800A5428 = { 0x2EE, 11, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5438 = { 0x2EC, 11, 2, 0x3B0, 120, 1, &D_800A5428 };
StagePoint D_800A5448 = { 0x2E8, 11, 2, 176, 0x168, 5, &D_800A5438 };
StagePoints D_800A5458 = { 11, 1, &D_800A5448 };
StagePoint D_800A5460 = { 0x2EC, 12, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A5470 = { 0x2EE, 12, 1, 0x130, 200, 1, &D_800A5460 };
StagePoint D_800A5480 = { 0x2E8, 12, 1, 176, 0x168, 5, &D_800A5470 };
StagePoints D_800A5490 = { 12, 1, &D_800A5480 };
StagePoint D_800A5498 = { 0x2EE, 12, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A54A8 = { 0x2EE, 12, 2, 0x130, 200, 1, &D_800A5498 };
StagePoint D_800A54B8 = { 0x2EC, 12, 1, 240, 0x1D8, 5, &D_800A54A8 };
StagePoints D_800A54C8 = { 12, 2, &D_800A54B8 };
StagePoint D_800A54D0 = { 0x2EC, 13, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A54E0 = { 0x2EE, 13, 1, 0x130, 200, 1, &D_800A54D0 };
StagePoint D_800A54F0 = { 0x2EA, 13, 2, 224, 0x200, 5, &D_800A54E0 };
StagePoints D_800A5500 = { 13, 1, &D_800A54F0 };
StagePoint D_800A5508 = { 0x2EE, 13, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5518 = { 0x2EE, 13, 2, 0x130, 200, 1, &D_800A5508 };
StagePoint D_800A5528 = { 0x2EC, 13, 1, 240, 0x1D8, 5, &D_800A5518 };
StagePoints D_800A5538 = { 13, 2, &D_800A5528 };
StagePoint D_800A5540 = { 0x2EB, 14, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5550 = { 0x2ED, 14, 2, 0x3A0, 128, 1, &D_800A5540 };
StagePoint D_800A5560 = { 0x2EA, 14, 1, 224, 0x200, 5, &D_800A5550 };
StagePoints D_800A5570 = { 14, 1, &D_800A5560 };
StagePoint D_800A5578 = { 0x2E9, 14, 1, 0x240, 240, 1, NULL };
StagePoint D_800A5588 = { 0x2EB, 14, 2, 0x240, 160, 1, &D_800A5578 };
StagePoint D_800A5598 = { 0x2ED, 14, 1, 0x350, 0x1F8, 5, &D_800A5588 };
StagePoints D_800A55A8 = { 14, 2, &D_800A5598 };
StagePoint D_800A55B0 = { 0x2EB, 16, 1, 0x240, 160, 1, NULL };
StagePoint D_800A55C0 = { 0x2EB, 16, 2, 0x240, 160, 1, &D_800A55B0 };
StagePoint D_800A55D0 = { 0x2EE, 16, 1, 224, 0x240, 5, &D_800A55C0 };
StagePoints D_800A55E0 = { 16, 1, &D_800A55D0 };
StagePoint D_800A55E8 = { 0x2EC, 19, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A55F8 = { 0x2ED, 19, 2, 0x3A0, 128, 1, &D_800A55E8 };
StagePoint D_800A5608 = { 0x2EE, 19, 2, 224, 0x240, 5, &D_800A55F8 };
StagePoints D_800A5618 = { 19, 1, &D_800A5608 };
StagePoint D_800A5620 = { 0x2EB, 19, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5630 = { 0x2EB, 19, 2, 0x240, 160, 1, &D_800A5620 };
StagePoint D_800A5640 = { 0x2ED, 19, 1, 0x350, 0x1F8, 5, &D_800A5630 };
StagePoints D_800A5650 = { 19, 2, &D_800A5640 };
StagePoint D_800A5658 = { 0x2EB, 19, 3, 0x240, 160, 1, NULL };
StagePoint D_800A5668 = { 0x2EC, 19, 5, 0x3B0, 120, 1, &D_800A5658 };
StagePoint D_800A5678 = { 0x2EC, 19, 4, 240, 0x1D8, 5, &D_800A5668 };
StagePoints D_800A5688 = { 19, 3, &D_800A5678 };
StagePoint D_800A5690 = { 0x2EC, 20, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A56A0 = { 0x2ED, 20, 2, 0x3A0, 128, 1, &D_800A5690 };
StagePoint D_800A56B0 = { 0x2EE, 20, 2, 224, 0x240, 5, &D_800A56A0 };
StagePoints D_800A56C0 = { 20, 1, &D_800A56B0 };
StagePoint D_800A56C8 = { 0x2EB, 20, 1, 0x240, 160, 1, NULL };
StagePoint D_800A56D8 = { 0x2EC, 20, 4, 0x3B0, 120, 1, &D_800A56C8 };
StagePoint D_800A56E8 = { 0x2ED, 20, 1, 0x350, 0x1F8, 5, &D_800A56D8 };
StagePoints D_800A56F8 = { 20, 2, &D_800A56E8 };
StagePoint D_800A5700 = { 0x2EB, 20, 2, 0x240, 160, 1, NULL };
StagePoint D_800A5710 = { 0x2EC, 20, 5, 0x3B0, 120, 1, &D_800A5700 };
StagePoint D_800A5720 = { 0x2EC, 20, 3, 240, 0x1D8, 5, &D_800A5710 };
StagePoints D_800A5730 = { 20, 3, &D_800A5720 };
StagePoint D_800A5738 = { 0x2EB, 20, 3, 0x240, 160, 1, NULL };
StagePoint D_800A5748 = { 0x2EC, 20, 6, 0x3B0, 120, 1, &D_800A5738 };
StagePoint D_800A5758 = { 0x2EC, 20, 4, 240, 0x1D8, 5, &D_800A5748 };
StagePoints D_800A5768 = { 20, 4, &D_800A5758 };
StagePoint D_800A5770 = { 0x2EC, 20, 7, 0x3B0, 120, 1, NULL };
StagePoint D_800A5780 = { 0x2EC, 20, 8, 0x3B0, 120, 1, &D_800A5770 };
StagePoint D_800A5790 = { 0x2EC, 20, 5, 240, 0x1D8, 5, &D_800A5780 };
StagePoints D_800A57A0 = { 20, 5, &D_800A5790 };
StagePoint D_800A57A8 = { 0x2EC, 20, 9, 0x3B0, 120, 1, NULL };
StagePoint D_800A57B8 = { 0x2EB, 20, 7, 0x240, 160, 1, &D_800A57A8 };
StagePoint D_800A57C8 = { 0x2EC, 20, 7, 240, 0x1D8, 5, &D_800A57B8 };
StagePoints D_800A57D8 = { 20, 6, &D_800A57C8 };
StagePoint D_800A57E0 = { 0x2EB, 25, 1, 0x240, 160, 1, NULL };
StagePoint D_800A57F0 = { 0x2EB, 25, 2, 0x240, 160, 1, &D_800A57E0 };
StagePoint D_800A5800 = { 0x2EE, 25, 1, 224, 0x240, 5, &D_800A57F0 };
StagePoints D_800A5810 = { 25, 1, &D_800A5800 };
StagePoint D_800A5818 = { 0x2EB, 27, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5828 = { 0x2ED, 27, 2, 0x3A0, 128, 1, &D_800A5818 };
StagePoint D_800A5838 = { 0x2EA, 27, 1, 224, 0x200, 5, &D_800A5828 };
StagePoints D_800A5848 = { 27, 1, &D_800A5838 };
StagePoint D_800A5850 = { 0x2E9, 27, 1, 0x240, 240, 1, NULL };
StagePoint D_800A5860 = { 0x2EB, 27, 2, 0x240, 160, 1, &D_800A5850 };
StagePoint D_800A5870 = { 0x2ED, 27, 1, 0x350, 0x1F8, 5, &D_800A5860 };
StagePoints D_800A5880 = { 27, 2, &D_800A5870 };
StagePoint D_800A5888 = { 0x2EC, 28, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A5898 = { 0x2EE, 28, 1, 0x130, 200, 1, &D_800A5888 };
StagePoint D_800A58A8 = { 0x2E8, 28, 1, 176, 0x168, 5, &D_800A5898 };
StagePoints D_800A58B8 = { 28, 1, &D_800A58A8 };
StagePoint D_800A58C0 = { 0x2EE, 28, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A58D0 = { 0x2EE, 28, 2, 0x130, 200, 1, &D_800A58C0 };
StagePoint D_800A58E0 = { 0x2EC, 28, 1, 240, 0x1D8, 5, &D_800A58D0 };
StagePoints D_800A58F0 = { 28, 2, &D_800A58E0 };
StagePoint D_800A58F8 = { 0x2EB, 29, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5908 = { 0x2ED, 29, 2, 0x3A0, 128, 1, &D_800A58F8 };
StagePoint D_800A5918 = { 0x2EE, 29, 1, 224, 0x240, 5, &D_800A5908 };
StagePoints D_800A5928 = { 29, 1, &D_800A5918 };
StagePoint D_800A5930 = { 0x2EB, 29, 2, 0x240, 160, 1, NULL };
StagePoint D_800A5940 = { 0x2EB, 29, 3, 0x240, 160, 1, &D_800A5930 };
StagePoint D_800A5950 = { 0x2ED, 29, 1, 0x350, 0x1F8, 5, &D_800A5940 };
StagePoints D_800A5960 = { 29, 2, &D_800A5950 };
StagePoint D_800A5968 = { 0x2EC, 30, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5978 = { 0x2EE, 30, 1, 0x130, 200, 1, &D_800A5968 };
StagePoint D_800A5988 = { 0x2E8, 30, 1, 176, 0x168, 5, &D_800A5978 };
StagePoints D_800A5998 = { 30, 1, &D_800A5988 };
StagePoint D_800A59A0 = { 0x2EE, 30, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A59B0 = { 0x2EE, 30, 2, 0x130, 200, 1, &D_800A59A0 };
StagePoint D_800A59C0 = { 0x2E8, 30, 2, 176, 0x168, 5, &D_800A59B0 };
StagePoints D_800A59D0 = { 30, 2, &D_800A59C0 };
StagePoints *placePoints[] = {
    &D_800A4FC0, &D_800A4FF8, &D_800A5030, &D_800A5068,
    &D_800A50A0, &D_800A50D8, &D_800A5110, &D_800A5148,
    &D_800A5180, &D_800A51B8, &D_800A51F0, &D_800A5228,
    &D_800A5260, &D_800A5298, &D_800A52D0, &D_800A5308,
    &D_800A5340, &D_800A5378, &D_800A53B0, &D_800A53E8,
    &D_800A5420, &D_800A5458, &D_800A5490, &D_800A54C8,
    &D_800A5500, &D_800A5538, &D_800A5570, &D_800A55A8,
    &D_800A55E0, &D_800A5618, &D_800A5650, &D_800A5688,
    &D_800A56C0, &D_800A56F8, &D_800A5730, &D_800A5768,
    &D_800A57A0, &D_800A57D8, &D_800A5810, &D_800A5848,
    &D_800A5880, &D_800A58B8, &D_800A58F0, &D_800A5928,
    &D_800A5960, &D_800A5998, &D_800A59D0, NULL,
};
Battle D_800A5A98 = { 174, 10, 0x60080000 };
Battle D_800A5AA4 = { 174, 10, 0x60080000 };
Battle D_800A5AB0 = { 170, 10, 0x60080000 };
Battle D_800A5ABC = { 170, 10, 0x60080000 };
Battle D_800A5AC8 = { 170, 10, 0x60080000 };
Battle D_800A5AD4 = { 170, 10, 0x60080000 };
Battle D_800A5AE0 = { 170, 10, 0x60080000 };
Battle D_800A5AEC = { 170, 10, 0x60080000 };
BattleList D_800A5AF8 = {
    1,
    { &D_800A5A98, &D_800A5AA4, &D_800A5AB0, &D_800A5ABC,
      &D_800A5AC8, &D_800A5AD4, &D_800A5AE0, &D_800A5AEC },
};
Battle D_800A5B1C = { 0, 0, 0x60040000 };
Battle D_800A5B28 = { 0, 0, 0x60040000 };
Battle D_800A5B34 = { 0, 0, 0x60040000 };
Battle D_800A5B40 = { 0, 0, 0x60040000 };
Battle D_800A5B4C = { 0, 0, 0x60040000 };
Battle D_800A5B58 = { 0, 0, 0x60040000 };
Battle D_800A5B64 = { 0, 0, 0x60040000 };
Battle D_800A5B70 = { 0, 0, 0x60040000 };
BattleList D_800A5B7C = {
    0,
    { &D_800A5B1C, &D_800A5B28, &D_800A5B34, &D_800A5B40,
      &D_800A5B4C, &D_800A5B58, &D_800A5B64, &D_800A5B70 },
};
Battle D_800A5BA0 = { 0, 0, 0x60040000 };
Battle D_800A5BAC = { 0, 0, 0x60040000 };
Battle D_800A5BB8 = { 0, 0, 0x60040000 };
Battle D_800A5BC4 = { 0, 0, 0x60040000 };
Battle D_800A5BD0 = { 0, 0, 0x60040000 };
Battle D_800A5BDC = { 0, 0, 0x60040000 };
Battle D_800A5BE8 = { 0, 0, 0x60040000 };
Battle D_800A5BF4 = { 0, 0, 0x60040000 };
BattleList D_800A5C00 = {
    0,
    { &D_800A5BA0, &D_800A5BAC, &D_800A5BB8, &D_800A5BC4,
      &D_800A5BD0, &D_800A5BDC, &D_800A5BE8, &D_800A5BF4 },
};
Battle D_800A5C24 = { 0, 0, 0x60040000 };
Battle D_800A5C30 = { 0, 0, 0x60040000 };
Battle D_800A5C3C = { 0, 0, 0x60040000 };
Battle D_800A5C48 = { 0, 0, 0x60040000 };
Battle D_800A5C54 = { 0, 0, 0x60040000 };
Battle D_800A5C60 = { 0, 0, 0x60040000 };
Battle D_800A5C6C = { 0, 0, 0x60040000 };
Battle D_800A5C78 = { 0, 0, 0x60040000 };
BattleList D_800A5C84 = {
    0,
    { &D_800A5C24, &D_800A5C30, &D_800A5C3C, &D_800A5C48,
      &D_800A5C54, &D_800A5C60, &D_800A5C6C, &D_800A5C78 },
};
Battle D_800A5CA8 = { 174, 10, 0x60080000 };
Battle D_800A5CB4 = { 174, 10, 0x60080000 };
Battle D_800A5CC0 = { 170, 10, 0x60080000 };
Battle D_800A5CCC = { 170, 10, 0x60080000 };
Battle D_800A5CD8 = { 170, 10, 0x60080000 };
Battle D_800A5CE4 = { 110, 10, 0x60080000 };
Battle D_800A5CF0 = { 110, 10, 0x60080000 };
Battle D_800A5CFC = { 110, 10, 0x60080000 };
BattleList D_800A5D08 = {
    1,
    { &D_800A5CA8, &D_800A5CB4, &D_800A5CC0, &D_800A5CCC,
      &D_800A5CD8, &D_800A5CE4, &D_800A5CF0, &D_800A5CFC },
};
Battle D_800A5D2C = { 0, 0, 0x60040000 };
Battle D_800A5D38 = { 0, 0, 0x60040000 };
Battle D_800A5D44 = { 0, 0, 0x60040000 };
Battle D_800A5D50 = { 0, 0, 0x60040000 };
Battle D_800A5D5C = { 0, 0, 0x60040000 };
Battle D_800A5D68 = { 0, 0, 0x60040000 };
Battle D_800A5D74 = { 0, 0, 0x60040000 };
Battle D_800A5D80 = { 0, 0, 0x60040000 };
BattleList D_800A5D8C = {
    0,
    { &D_800A5D2C, &D_800A5D38, &D_800A5D44, &D_800A5D50,
      &D_800A5D5C, &D_800A5D68, &D_800A5D74, &D_800A5D80 },
};
Battle D_800A5DB0 = { 0, 0, 0x60040000 };
Battle D_800A5DBC = { 0, 0, 0x60040000 };
Battle D_800A5DC8 = { 0, 0, 0x60040000 };
Battle D_800A5DD4 = { 0, 0, 0x60040000 };
Battle D_800A5DE0 = { 0, 0, 0x60040000 };
Battle D_800A5DEC = { 0, 0, 0x60040000 };
Battle D_800A5DF8 = { 0, 0, 0x60040000 };
Battle D_800A5E04 = { 0, 0, 0x60040000 };
BattleList D_800A5E10 = {
    0,
    { &D_800A5DB0, &D_800A5DBC, &D_800A5DC8, &D_800A5DD4,
      &D_800A5DE0, &D_800A5DEC, &D_800A5DF8, &D_800A5E04 },
};
Battle D_800A5E34 = { 0, 0, 0x60040000 };
Battle D_800A5E40 = { 0, 0, 0x60040000 };
Battle D_800A5E4C = { 0, 0, 0x60040000 };
Battle D_800A5E58 = { 0, 0, 0x60040000 };
Battle D_800A5E64 = { 0, 0, 0x60040000 };
Battle D_800A5E70 = { 0, 0, 0x60040000 };
Battle D_800A5E7C = { 0, 0, 0x60040000 };
Battle D_800A5E88 = { 0, 0, 0x60040000 };
BattleList D_800A5E94 = {
    0,
    { &D_800A5E34, &D_800A5E40, &D_800A5E4C, &D_800A5E58,
      &D_800A5E64, &D_800A5E70, &D_800A5E7C, &D_800A5E88 },
};
Battle D_800A5EB8 = { 174, 10, 0x60080000 };
Battle D_800A5EC4 = { 174, 10, 0x60080000 };
Battle D_800A5ED0 = { 170, 10, 0x60080000 };
Battle D_800A5EDC = { 170, 10, 0x60080000 };
Battle D_800A5EE8 = { 182, 10, 0x60080000 };
Battle D_800A5EF4 = { 182, 10, 0x60080000 };
Battle D_800A5F00 = { 71, 10, 0x60080000 };
Battle D_800A5F0C = { 71, 10, 0x60080000 };
BattleList D_800A5F18 = {
    1,
    { &D_800A5EB8, &D_800A5EC4, &D_800A5ED0, &D_800A5EDC,
      &D_800A5EE8, &D_800A5EF4, &D_800A5F00, &D_800A5F0C },
};
Battle D_800A5F3C = { 0, 0, 0x60040000 };
Battle D_800A5F48 = { 0, 0, 0x60040000 };
Battle D_800A5F54 = { 0, 0, 0x60040000 };
Battle D_800A5F60 = { 0, 0, 0x60040000 };
Battle D_800A5F6C = { 0, 0, 0x60040000 };
Battle D_800A5F78 = { 0, 0, 0x60040000 };
Battle D_800A5F84 = { 0, 0, 0x60040000 };
Battle D_800A5F90 = { 0, 0, 0x60040000 };
BattleList D_800A5F9C = {
    0,
    { &D_800A5F3C, &D_800A5F48, &D_800A5F54, &D_800A5F60,
      &D_800A5F6C, &D_800A5F78, &D_800A5F84, &D_800A5F90 },
};
Battle D_800A5FC0 = { 0, 0, 0x60040000 };
Battle D_800A5FCC = { 0, 0, 0x60040000 };
Battle D_800A5FD8 = { 0, 0, 0x60040000 };
Battle D_800A5FE4 = { 0, 0, 0x60040000 };
Battle D_800A5FF0 = { 0, 0, 0x60040000 };
Battle D_800A5FFC = { 0, 0, 0x60040000 };
Battle D_800A6008 = { 0, 0, 0x60040000 };
Battle D_800A6014 = { 0, 0, 0x60040000 };
BattleList D_800A6020 = {
    0,
    { &D_800A5FC0, &D_800A5FCC, &D_800A5FD8, &D_800A5FE4,
      &D_800A5FF0, &D_800A5FFC, &D_800A6008, &D_800A6014 },
};
Battle D_800A6044 = { 0, 0, 0x60040000 };
Battle D_800A6050 = { 0, 0, 0x60040000 };
Battle D_800A605C = { 0, 0, 0x60040000 };
Battle D_800A6068 = { 0, 0, 0x60040000 };
Battle D_800A6074 = { 0, 0, 0x60040000 };
Battle D_800A6080 = { 0, 0, 0x60040000 };
Battle D_800A608C = { 0, 0, 0x60040000 };
Battle D_800A6098 = { 0, 0, 0x60040000 };
BattleList D_800A60A4 = {
    0,
    { &D_800A6044, &D_800A6050, &D_800A605C, &D_800A6068,
      &D_800A6074, &D_800A6080, &D_800A608C, &D_800A6098 },
};
Battle D_800A60C8 = { 174, 10, 0x60080000 };
Battle D_800A60D4 = { 174, 10, 0x60080000 };
Battle D_800A60E0 = { 170, 10, 0x60080000 };
Battle D_800A60EC = { 170, 10, 0x60080000 };
Battle D_800A60F8 = { 182, 10, 0x60080000 };
Battle D_800A6104 = { 182, 10, 0x60080000 };
Battle D_800A6110 = { 71, 10, 0x60080000 };
Battle D_800A611C = { 71, 10, 0x60080000 };
BattleList D_800A6128 = {
    1,
    { &D_800A60C8, &D_800A60D4, &D_800A60E0, &D_800A60EC,
      &D_800A60F8, &D_800A6104, &D_800A6110, &D_800A611C },
};
Battle D_800A614C = { 0, 0, 0x60040000 };
Battle D_800A6158 = { 0, 0, 0x60040000 };
Battle D_800A6164 = { 0, 0, 0x60040000 };
Battle D_800A6170 = { 0, 0, 0x60040000 };
Battle D_800A617C = { 0, 0, 0x60040000 };
Battle D_800A6188 = { 0, 0, 0x60040000 };
Battle D_800A6194 = { 0, 0, 0x60040000 };
Battle D_800A61A0 = { 0, 0, 0x60040000 };
BattleList D_800A61AC = {
    0,
    { &D_800A614C, &D_800A6158, &D_800A6164, &D_800A6170,
      &D_800A617C, &D_800A6188, &D_800A6194, &D_800A61A0 },
};
Battle D_800A61D0 = { 0, 0, 0x60040000 };
Battle D_800A61DC = { 0, 0, 0x60040000 };
Battle D_800A61E8 = { 0, 0, 0x60040000 };
Battle D_800A61F4 = { 0, 0, 0x60040000 };
Battle D_800A6200 = { 0, 0, 0x60040000 };
Battle D_800A620C = { 0, 0, 0x60040000 };
Battle D_800A6218 = { 0, 0, 0x60040000 };
Battle D_800A6224 = { 0, 0, 0x60040000 };
BattleList D_800A6230 = {
    0,
    { &D_800A61D0, &D_800A61DC, &D_800A61E8, &D_800A61F4,
      &D_800A6200, &D_800A620C, &D_800A6218, &D_800A6224 },
};
Battle D_800A6254 = { 0, 0, 0x60040000 };
Battle D_800A6260 = { 0, 0, 0x60040000 };
Battle D_800A626C = { 0, 0, 0x60040000 };
Battle D_800A6278 = { 0, 0, 0x60040000 };
Battle D_800A6284 = { 0, 0, 0x60040000 };
Battle D_800A6290 = { 0, 0, 0x60040000 };
Battle D_800A629C = { 0, 0, 0x60040000 };
Battle D_800A62A8 = { 0, 0, 0x60040000 };
BattleList D_800A62B4 = {
    0,
    { &D_800A6254, &D_800A6260, &D_800A626C, &D_800A6278,
      &D_800A6284, &D_800A6290, &D_800A629C, &D_800A62A8 },
};
Battle D_800A62D8 = { 174, 10, 0x60080000 };
Battle D_800A62E4 = { 170, 10, 0x60080000 };
Battle D_800A62F0 = { 110, 10, 0x60080000 };
Battle D_800A62FC = { 110, 10, 0x60080000 };
Battle D_800A6308 = { 182, 10, 0x60080000 };
Battle D_800A6314 = { 182, 10, 0x60080000 };
Battle D_800A6320 = { 71, 10, 0x60080000 };
Battle D_800A632C = { 71, 10, 0x60080000 };
BattleList D_800A6338 = {
    1,
    { &D_800A62D8, &D_800A62E4, &D_800A62F0, &D_800A62FC,
      &D_800A6308, &D_800A6314, &D_800A6320, &D_800A632C },
};
Battle D_800A635C = { 0, 0, 0x60040000 };
Battle D_800A6368 = { 0, 0, 0x60040000 };
Battle D_800A6374 = { 0, 0, 0x60040000 };
Battle D_800A6380 = { 0, 0, 0x60040000 };
Battle D_800A638C = { 0, 0, 0x60040000 };
Battle D_800A6398 = { 0, 0, 0x60040000 };
Battle D_800A63A4 = { 0, 0, 0x60040000 };
Battle D_800A63B0 = { 0, 0, 0x60040000 };
BattleList D_800A63BC = {
    0,
    { &D_800A635C, &D_800A6368, &D_800A6374, &D_800A6380,
      &D_800A638C, &D_800A6398, &D_800A63A4, &D_800A63B0 },
};
Battle D_800A63E0 = { 0, 0, 0x60040000 };
Battle D_800A63EC = { 0, 0, 0x60040000 };
Battle D_800A63F8 = { 0, 0, 0x60040000 };
Battle D_800A6404 = { 0, 0, 0x60040000 };
Battle D_800A6410 = { 0, 0, 0x60040000 };
Battle D_800A641C = { 0, 0, 0x60040000 };
Battle D_800A6428 = { 0, 0, 0x60040000 };
Battle D_800A6434 = { 0, 0, 0x60040000 };
BattleList D_800A6440 = {
    0,
    { &D_800A63E0, &D_800A63EC, &D_800A63F8, &D_800A6404,
      &D_800A6410, &D_800A641C, &D_800A6428, &D_800A6434 },
};
Battle D_800A6464 = { 0, 0, 0x60040000 };
Battle D_800A6470 = { 0, 0, 0x60040000 };
Battle D_800A647C = { 0, 0, 0x60040000 };
Battle D_800A6488 = { 0, 0, 0x60040000 };
Battle D_800A6494 = { 0, 0, 0x60040000 };
Battle D_800A64A0 = { 0, 0, 0x60040000 };
Battle D_800A64AC = { 0, 0, 0x60040000 };
Battle D_800A64B8 = { 0, 0, 0x60040000 };
BattleList D_800A64C4 = {
    0,
    { &D_800A6464, &D_800A6470, &D_800A647C, &D_800A6488,
      &D_800A6494, &D_800A64A0, &D_800A64AC, &D_800A64B8 },
};
Battle D_800A64E8 = { 174, 10, 0x60080000 };
Battle D_800A64F4 = { 170, 10, 0x60080000 };
Battle D_800A6500 = { 110, 10, 0x60080000 };
Battle D_800A650C = { 110, 10, 0x60080000 };
Battle D_800A6518 = { 182, 10, 0x60080000 };
Battle D_800A6524 = { 182, 10, 0x60080000 };
Battle D_800A6530 = { 71, 10, 0x60080000 };
Battle D_800A653C = { 71, 10, 0x60080000 };
BattleList D_800A6548 = {
    1,
    { &D_800A64E8, &D_800A64F4, &D_800A6500, &D_800A650C,
      &D_800A6518, &D_800A6524, &D_800A6530, &D_800A653C },
};
Battle D_800A656C = { 0, 0, 0x60040000 };
Battle D_800A6578 = { 0, 0, 0x60040000 };
Battle D_800A6584 = { 0, 0, 0x60040000 };
Battle D_800A6590 = { 0, 0, 0x60040000 };
Battle D_800A659C = { 0, 0, 0x60040000 };
Battle D_800A65A8 = { 0, 0, 0x60040000 };
Battle D_800A65B4 = { 0, 0, 0x60040000 };
Battle D_800A65C0 = { 0, 0, 0x60040000 };
BattleList D_800A65CC = {
    0,
    { &D_800A656C, &D_800A6578, &D_800A6584, &D_800A6590,
      &D_800A659C, &D_800A65A8, &D_800A65B4, &D_800A65C0 },
};
Battle D_800A65F0 = { 0, 0, 0x60040000 };
Battle D_800A65FC = { 0, 0, 0x60040000 };
Battle D_800A6608 = { 0, 0, 0x60040000 };
Battle D_800A6614 = { 0, 0, 0x60040000 };
Battle D_800A6620 = { 0, 0, 0x60040000 };
Battle D_800A662C = { 0, 0, 0x60040000 };
Battle D_800A6638 = { 0, 0, 0x60040000 };
Battle D_800A6644 = { 0, 0, 0x60040000 };
BattleList D_800A6650 = {
    0,
    { &D_800A65F0, &D_800A65FC, &D_800A6608, &D_800A6614,
      &D_800A6620, &D_800A662C, &D_800A6638, &D_800A6644 },
};
Battle D_800A6674 = { 0, 0, 0x60040000 };
Battle D_800A6680 = { 0, 0, 0x60040000 };
Battle D_800A668C = { 0, 0, 0x60040000 };
Battle D_800A6698 = { 0, 0, 0x60040000 };
Battle D_800A66A4 = { 0, 0, 0x60040000 };
Battle D_800A66B0 = { 0, 0, 0x60040000 };
Battle D_800A66BC = { 0, 0, 0x60040000 };
Battle D_800A66C8 = { 0, 0, 0x60040000 };
BattleList D_800A66D4 = {
    0,
    { &D_800A6674, &D_800A6680, &D_800A668C, &D_800A6698,
      &D_800A66A4, &D_800A66B0, &D_800A66BC, &D_800A66C8 },
};
Battle D_800A66F8 = { 182, 10, 0x60080000 };
Battle D_800A6704 = { 182, 10, 0x60080000 };
Battle D_800A6710 = { 182, 10, 0x60080000 };
Battle D_800A671C = { 182, 10, 0x60080000 };
Battle D_800A6728 = { 71, 10, 0x60080000 };
Battle D_800A6734 = { 71, 10, 0x60080000 };
Battle D_800A6740 = { 71, 10, 0x60080000 };
Battle D_800A674C = { 71, 10, 0x60080000 };
BattleList D_800A6758 = {
    1,
    { &D_800A66F8, &D_800A6704, &D_800A6710, &D_800A671C,
      &D_800A6728, &D_800A6734, &D_800A6740, &D_800A674C },
};
Battle D_800A677C = { 0, 0, 0x60040000 };
Battle D_800A6788 = { 0, 0, 0x60040000 };
Battle D_800A6794 = { 0, 0, 0x60040000 };
Battle D_800A67A0 = { 0, 0, 0x60040000 };
Battle D_800A67AC = { 0, 0, 0x60040000 };
Battle D_800A67B8 = { 0, 0, 0x60040000 };
Battle D_800A67C4 = { 0, 0, 0x60040000 };
Battle D_800A67D0 = { 0, 0, 0x60040000 };
BattleList D_800A67DC = {
    0,
    { &D_800A677C, &D_800A6788, &D_800A6794, &D_800A67A0,
      &D_800A67AC, &D_800A67B8, &D_800A67C4, &D_800A67D0 },
};
Battle D_800A6800 = { 0, 0, 0x60040000 };
Battle D_800A680C = { 0, 0, 0x60040000 };
Battle D_800A6818 = { 0, 0, 0x60040000 };
Battle D_800A6824 = { 0, 0, 0x60040000 };
Battle D_800A6830 = { 0, 0, 0x60040000 };
Battle D_800A683C = { 0, 0, 0x60040000 };
Battle D_800A6848 = { 0, 0, 0x60040000 };
Battle D_800A6854 = { 0, 0, 0x60040000 };
BattleList D_800A6860 = {
    0,
    { &D_800A6800, &D_800A680C, &D_800A6818, &D_800A6824,
      &D_800A6830, &D_800A683C, &D_800A6848, &D_800A6854 },
};
Battle D_800A6884 = { 0, 0, 0x60040000 };
Battle D_800A6890 = { 0, 0, 0x60040000 };
Battle D_800A689C = { 0, 0, 0x60040000 };
Battle D_800A68A8 = { 0, 0, 0x60040000 };
Battle D_800A68B4 = { 0, 0, 0x60040000 };
Battle D_800A68C0 = { 0, 0, 0x60040000 };
Battle D_800A68CC = { 0, 0, 0x60040000 };
Battle D_800A68D8 = { 0, 0, 0x60040000 };
BattleList D_800A68E4 = {
    0,
    { &D_800A6884, &D_800A6890, &D_800A689C, &D_800A68A8,
      &D_800A68B4, &D_800A68C0, &D_800A68CC, &D_800A68D8 },
};
Battle D_800A6908 = { 182, 10, 0x60080000 };
Battle D_800A6914 = { 182, 10, 0x60080000 };
Battle D_800A6920 = { 182, 10, 0x60080000 };
Battle D_800A692C = { 182, 10, 0x60080000 };
Battle D_800A6938 = { 71, 10, 0x60080000 };
Battle D_800A6944 = { 71, 10, 0x60080000 };
Battle D_800A6950 = { 71, 10, 0x60080000 };
Battle D_800A695C = { 71, 10, 0x60080000 };
BattleList D_800A6968 = {
    1,
    { &D_800A6908, &D_800A6914, &D_800A6920, &D_800A692C,
      &D_800A6938, &D_800A6944, &D_800A6950, &D_800A695C },
};
Battle D_800A698C = { 0, 0, 0x60040000 };
Battle D_800A6998 = { 0, 0, 0x60040000 };
Battle D_800A69A4 = { 0, 0, 0x60040000 };
Battle D_800A69B0 = { 0, 0, 0x60040000 };
Battle D_800A69BC = { 0, 0, 0x60040000 };
Battle D_800A69C8 = { 0, 0, 0x60040000 };
Battle D_800A69D4 = { 0, 0, 0x60040000 };
Battle D_800A69E0 = { 0, 0, 0x60040000 };
BattleList D_800A69EC = {
    0,
    { &D_800A698C, &D_800A6998, &D_800A69A4, &D_800A69B0,
      &D_800A69BC, &D_800A69C8, &D_800A69D4, &D_800A69E0 },
};
Battle D_800A6A10 = { 0, 0, 0x60040000 };
Battle D_800A6A1C = { 0, 0, 0x60040000 };
Battle D_800A6A28 = { 0, 0, 0x60040000 };
Battle D_800A6A34 = { 0, 0, 0x60040000 };
Battle D_800A6A40 = { 0, 0, 0x60040000 };
Battle D_800A6A4C = { 0, 0, 0x60040000 };
Battle D_800A6A58 = { 0, 0, 0x60040000 };
Battle D_800A6A64 = { 0, 0, 0x60040000 };
BattleList D_800A6A70 = {
    0,
    { &D_800A6A10, &D_800A6A1C, &D_800A6A28, &D_800A6A34,
      &D_800A6A40, &D_800A6A4C, &D_800A6A58, &D_800A6A64 },
};
Battle D_800A6A94 = { 0, 0, 0x60040000 };
Battle D_800A6AA0 = { 0, 0, 0x60040000 };
Battle D_800A6AAC = { 0, 0, 0x60040000 };
Battle D_800A6AB8 = { 0, 0, 0x60040000 };
Battle D_800A6AC4 = { 0, 0, 0x60040000 };
Battle D_800A6AD0 = { 0, 0, 0x60040000 };
Battle D_800A6ADC = { 0, 0, 0x60040000 };
Battle D_800A6AE8 = { 0, 0, 0x60040000 };
BattleList D_800A6AF4 = {
    0,
    { &D_800A6A94, &D_800A6AA0, &D_800A6AAC, &D_800A6AB8,
      &D_800A6AC4, &D_800A6AD0, &D_800A6ADC, &D_800A6AE8 },
};
Battle D_800A6B18 = { 174, 10, 0x60080000 };
Battle D_800A6B24 = { 174, 10, 0x60080000 };
Battle D_800A6B30 = { 170, 10, 0x60080000 };
Battle D_800A6B3C = { 170, 10, 0x60080000 };
Battle D_800A6B48 = { 170, 10, 0x60080000 };
Battle D_800A6B54 = { 110, 10, 0x60080000 };
Battle D_800A6B60 = { 110, 10, 0x60080000 };
Battle D_800A6B6C = { 110, 10, 0x60080000 };
BattleList D_800A6B78 = {
    2,
    { &D_800A6B18, &D_800A6B24, &D_800A6B30, &D_800A6B3C,
      &D_800A6B48, &D_800A6B54, &D_800A6B60, &D_800A6B6C },
};
Battle D_800A6B9C = { 0, 0, 0x60040000 };
Battle D_800A6BA8 = { 0, 0, 0x60040000 };
Battle D_800A6BB4 = { 0, 0, 0x60040000 };
Battle D_800A6BC0 = { 0, 0, 0x60040000 };
Battle D_800A6BCC = { 0, 0, 0x60040000 };
Battle D_800A6BD8 = { 0, 0, 0x60040000 };
Battle D_800A6BE4 = { 0, 0, 0x60040000 };
Battle D_800A6BF0 = { 0, 0, 0x60040000 };
BattleList D_800A6BFC = {
    0,
    { &D_800A6B9C, &D_800A6BA8, &D_800A6BB4, &D_800A6BC0,
      &D_800A6BCC, &D_800A6BD8, &D_800A6BE4, &D_800A6BF0 },
};
Battle D_800A6C20 = { 0, 0, 0x60040000 };
Battle D_800A6C2C = { 0, 0, 0x60040000 };
Battle D_800A6C38 = { 0, 0, 0x60040000 };
Battle D_800A6C44 = { 0, 0, 0x60040000 };
Battle D_800A6C50 = { 0, 0, 0x60040000 };
Battle D_800A6C5C = { 0, 0, 0x60040000 };
Battle D_800A6C68 = { 0, 0, 0x60040000 };
Battle D_800A6C74 = { 0, 0, 0x60040000 };
BattleList D_800A6C80 = {
    0,
    { &D_800A6C20, &D_800A6C2C, &D_800A6C38, &D_800A6C44,
      &D_800A6C50, &D_800A6C5C, &D_800A6C68, &D_800A6C74 },
};
Battle D_800A6CA4 = { 0, 0, 0x60040000 };
Battle D_800A6CB0 = { 0, 0, 0x60040000 };
Battle D_800A6CBC = { 0, 0, 0x60040000 };
Battle D_800A6CC8 = { 0, 0, 0x60040000 };
Battle D_800A6CD4 = { 0, 0, 0x60040000 };
Battle D_800A6CE0 = { 0, 0, 0x60040000 };
Battle D_800A6CEC = { 0, 0, 0x60040000 };
Battle D_800A6CF8 = { 0, 0, 0x60040000 };
BattleList D_800A6D04 = {
    0,
    { &D_800A6CA4, &D_800A6CB0, &D_800A6CBC, &D_800A6CC8,
      &D_800A6CD4, &D_800A6CE0, &D_800A6CEC, &D_800A6CF8 },
};
Battle D_800A6D28 = { 182, 10, 0x60080000 };
Battle D_800A6D34 = { 182, 10, 0x60080000 };
Battle D_800A6D40 = { 182, 10, 0x60080000 };
Battle D_800A6D4C = { 182, 10, 0x60080000 };
Battle D_800A6D58 = { 71, 10, 0x60080000 };
Battle D_800A6D64 = { 71, 10, 0x60080000 };
Battle D_800A6D70 = { 71, 10, 0x60080000 };
Battle D_800A6D7C = { 71, 10, 0x60080000 };
BattleList D_800A6D88 = {
    2,
    { &D_800A6D28, &D_800A6D34, &D_800A6D40, &D_800A6D4C,
      &D_800A6D58, &D_800A6D64, &D_800A6D70, &D_800A6D7C },
};
Battle D_800A6DAC = { 0, 0, 0x60040000 };
Battle D_800A6DB8 = { 0, 0, 0x60040000 };
Battle D_800A6DC4 = { 0, 0, 0x60040000 };
Battle D_800A6DD0 = { 0, 0, 0x60040000 };
Battle D_800A6DDC = { 0, 0, 0x60040000 };
Battle D_800A6DE8 = { 0, 0, 0x60040000 };
Battle D_800A6DF4 = { 0, 0, 0x60040000 };
Battle D_800A6E00 = { 0, 0, 0x60040000 };
BattleList D_800A6E0C = {
    0,
    { &D_800A6DAC, &D_800A6DB8, &D_800A6DC4, &D_800A6DD0,
      &D_800A6DDC, &D_800A6DE8, &D_800A6DF4, &D_800A6E00 },
};
Battle D_800A6E30 = { 0, 0, 0x60040000 };
Battle D_800A6E3C = { 0, 0, 0x60040000 };
Battle D_800A6E48 = { 0, 0, 0x60040000 };
Battle D_800A6E54 = { 0, 0, 0x60040000 };
Battle D_800A6E60 = { 0, 0, 0x60040000 };
Battle D_800A6E6C = { 0, 0, 0x60040000 };
Battle D_800A6E78 = { 0, 0, 0x60040000 };
Battle D_800A6E84 = { 0, 0, 0x60040000 };
BattleList D_800A6E90 = {
    0,
    { &D_800A6E30, &D_800A6E3C, &D_800A6E48, &D_800A6E54,
      &D_800A6E60, &D_800A6E6C, &D_800A6E78, &D_800A6E84 },
};
Battle D_800A6EB4 = { 0, 0, 0x60040000 };
Battle D_800A6EC0 = { 0, 0, 0x60040000 };
Battle D_800A6ECC = { 0, 0, 0x60040000 };
Battle D_800A6ED8 = { 0, 0, 0x60040000 };
Battle D_800A6EE4 = { 0, 0, 0x60040000 };
Battle D_800A6EF0 = { 0, 0, 0x60040000 };
Battle D_800A6EFC = { 0, 0, 0x60040000 };
Battle D_800A6F08 = { 0, 0, 0x60040000 };
BattleList D_800A6F14 = {
    0,
    { &D_800A6EB4, &D_800A6EC0, &D_800A6ECC, &D_800A6ED8,
      &D_800A6EE4, &D_800A6EF0, &D_800A6EFC, &D_800A6F08 },
};
Battle D_800A6F38 = { 110, 10, 0x60080000 };
Battle D_800A6F44 = { 110, 10, 0x60080000 };
Battle D_800A6F50 = { 110, 10, 0x60080000 };
Battle D_800A6F5C = { 110, 10, 0x60080000 };
Battle D_800A6F68 = { 110, 10, 0x60080000 };
Battle D_800A6F74 = { 110, 10, 0x60080000 };
Battle D_800A6F80 = { 110, 10, 0x60080000 };
Battle D_800A6F8C = { 110, 10, 0x60080000 };
BattleList D_800A6F98 = {
    1,
    { &D_800A6F38, &D_800A6F44, &D_800A6F50, &D_800A6F5C,
      &D_800A6F68, &D_800A6F74, &D_800A6F80, &D_800A6F8C },
};
Battle D_800A6FBC = { 0, 0, 0x60040000 };
Battle D_800A6FC8 = { 0, 0, 0x60040000 };
Battle D_800A6FD4 = { 0, 0, 0x60040000 };
Battle D_800A6FE0 = { 0, 0, 0x60040000 };
Battle D_800A6FEC = { 0, 0, 0x60040000 };
Battle D_800A6FF8 = { 0, 0, 0x60040000 };
Battle D_800A7004 = { 0, 0, 0x60040000 };
Battle D_800A7010 = { 0, 0, 0x60040000 };
BattleList D_800A701C = {
    0,
    { &D_800A6FBC, &D_800A6FC8, &D_800A6FD4, &D_800A6FE0,
      &D_800A6FEC, &D_800A6FF8, &D_800A7004, &D_800A7010 },
};
Battle D_800A7040 = { 0, 0, 0x60040000 };
Battle D_800A704C = { 0, 0, 0x60040000 };
Battle D_800A7058 = { 0, 0, 0x60040000 };
Battle D_800A7064 = { 0, 0, 0x60040000 };
Battle D_800A7070 = { 0, 0, 0x60040000 };
Battle D_800A707C = { 0, 0, 0x60040000 };
Battle D_800A7088 = { 0, 0, 0x60040000 };
Battle D_800A7094 = { 0, 0, 0x60040000 };
BattleList D_800A70A0 = {
    0,
    { &D_800A7040, &D_800A704C, &D_800A7058, &D_800A7064,
      &D_800A7070, &D_800A707C, &D_800A7088, &D_800A7094 },
};
Battle D_800A70C4 = { 0, 0, 0x60040000 };
Battle D_800A70D0 = { 0, 0, 0x60040000 };
Battle D_800A70DC = { 0, 0, 0x60040000 };
Battle D_800A70E8 = { 0, 0, 0x60040000 };
Battle D_800A70F4 = { 0, 0, 0x60040000 };
Battle D_800A7100 = { 0, 0, 0x60040000 };
Battle D_800A710C = { 0, 0, 0x60040000 };
Battle D_800A7118 = { 0, 0, 0x60040000 };
BattleList D_800A7124 = {
    0,
    { &D_800A70C4, &D_800A70D0, &D_800A70DC, &D_800A70E8,
      &D_800A70F4, &D_800A7100, &D_800A710C, &D_800A7118 },
};
Battle D_800A7148 = { 182, 10, 0x60080000 };
Battle D_800A7154 = { 182, 10, 0x60080000 };
Battle D_800A7160 = { 182, 10, 0x60080000 };
Battle D_800A716C = { 182, 10, 0x60080000 };
Battle D_800A7178 = { 71, 10, 0x60080000 };
Battle D_800A7184 = { 71, 10, 0x60080000 };
Battle D_800A7190 = { 71, 10, 0x60080000 };
Battle D_800A719C = { 71, 10, 0x60080000 };
BattleList D_800A71A8 = {
    1,
    { &D_800A7148, &D_800A7154, &D_800A7160, &D_800A716C,
      &D_800A7178, &D_800A7184, &D_800A7190, &D_800A719C },
};
Battle D_800A71CC = { 0, 0, 0x60040000 };
Battle D_800A71D8 = { 0, 0, 0x60040000 };
Battle D_800A71E4 = { 0, 0, 0x60040000 };
Battle D_800A71F0 = { 0, 0, 0x60040000 };
Battle D_800A71FC = { 0, 0, 0x60040000 };
Battle D_800A7208 = { 0, 0, 0x60040000 };
Battle D_800A7214 = { 0, 0, 0x60040000 };
Battle D_800A7220 = { 0, 0, 0x60040000 };
BattleList D_800A722C = {
    0,
    { &D_800A71CC, &D_800A71D8, &D_800A71E4, &D_800A71F0,
      &D_800A71FC, &D_800A7208, &D_800A7214, &D_800A7220 },
};
Battle D_800A7250 = { 0, 0, 0x60040000 };
Battle D_800A725C = { 0, 0, 0x60040000 };
Battle D_800A7268 = { 0, 0, 0x60040000 };
Battle D_800A7274 = { 0, 0, 0x60040000 };
Battle D_800A7280 = { 0, 0, 0x60040000 };
Battle D_800A728C = { 0, 0, 0x60040000 };
Battle D_800A7298 = { 0, 0, 0x60040000 };
Battle D_800A72A4 = { 0, 0, 0x60040000 };
BattleList D_800A72B0 = {
    0,
    { &D_800A7250, &D_800A725C, &D_800A7268, &D_800A7274,
      &D_800A7280, &D_800A728C, &D_800A7298, &D_800A72A4 },
};
Battle D_800A72D4 = { 0, 0, 0x60040000 };
Battle D_800A72E0 = { 0, 0, 0x60040000 };
Battle D_800A72EC = { 0, 0, 0x60040000 };
Battle D_800A72F8 = { 0, 0, 0x60040000 };
Battle D_800A7304 = { 0, 0, 0x60040000 };
Battle D_800A7310 = { 0, 0, 0x60040000 };
Battle D_800A731C = { 0, 0, 0x60040000 };
Battle D_800A7328 = { 0, 0, 0x60040000 };
BattleList D_800A7334 = {
    0,
    { &D_800A72D4, &D_800A72E0, &D_800A72EC, &D_800A72F8,
      &D_800A7304, &D_800A7310, &D_800A731C, &D_800A7328 },
};
Battle D_800A7358 = { 174, 10, 0x60080000 };
Battle D_800A7364 = { 174, 10, 0x60080000 };
Battle D_800A7370 = { 170, 10, 0x60080000 };
Battle D_800A737C = { 170, 10, 0x60080000 };
Battle D_800A7388 = { 170, 10, 0x60080000 };
Battle D_800A7394 = { 170, 10, 0x60080000 };
Battle D_800A73A0 = { 170, 10, 0x60080000 };
Battle D_800A73AC = { 170, 10, 0x60080000 };
BattleList D_800A73B8 = {
    4,
    { &D_800A7358, &D_800A7364, &D_800A7370, &D_800A737C,
      &D_800A7388, &D_800A7394, &D_800A73A0, &D_800A73AC },
};
Battle D_800A73DC = { 0, 0, 0x60040000 };
Battle D_800A73E8 = { 0, 0, 0x60040000 };
Battle D_800A73F4 = { 0, 0, 0x60040000 };
Battle D_800A7400 = { 0, 0, 0x60040000 };
Battle D_800A740C = { 0, 0, 0x60040000 };
Battle D_800A7418 = { 0, 0, 0x60040000 };
Battle D_800A7424 = { 0, 0, 0x60040000 };
Battle D_800A7430 = { 0, 0, 0x60040000 };
BattleList D_800A743C = {
    0,
    { &D_800A73DC, &D_800A73E8, &D_800A73F4, &D_800A7400,
      &D_800A740C, &D_800A7418, &D_800A7424, &D_800A7430 },
};
Battle D_800A7460 = { 0, 0, 0x60040000 };
Battle D_800A746C = { 0, 0, 0x60040000 };
Battle D_800A7478 = { 0, 0, 0x60040000 };
Battle D_800A7484 = { 0, 0, 0x60040000 };
Battle D_800A7490 = { 0, 0, 0x60040000 };
Battle D_800A749C = { 0, 0, 0x60040000 };
Battle D_800A74A8 = { 0, 0, 0x60040000 };
Battle D_800A74B4 = { 0, 0, 0x60040000 };
BattleList D_800A74C0 = {
    0,
    { &D_800A7460, &D_800A746C, &D_800A7478, &D_800A7484,
      &D_800A7490, &D_800A749C, &D_800A74A8, &D_800A74B4 },
};
Battle D_800A74E4 = { 0, 0, 0x60040000 };
Battle D_800A74F0 = { 0, 0, 0x60040000 };
Battle D_800A74FC = { 0, 0, 0x60040000 };
Battle D_800A7508 = { 0, 0, 0x60040000 };
Battle D_800A7514 = { 0, 0, 0x60040000 };
Battle D_800A7520 = { 0, 0, 0x60040000 };
Battle D_800A752C = { 0, 0, 0x60040000 };
Battle D_800A7538 = { 0, 0, 0x60040000 };
BattleList D_800A7544 = {
    0,
    { &D_800A74E4, &D_800A74F0, &D_800A74FC, &D_800A7508,
      &D_800A7514, &D_800A7520, &D_800A752C, &D_800A7538 },
};
Battle D_800A7568 = { 174, 10, 0x60080000 };
Battle D_800A7574 = { 174, 10, 0x60080000 };
Battle D_800A7580 = { 170, 10, 0x60080000 };
Battle D_800A758C = { 170, 10, 0x60080000 };
Battle D_800A7598 = { 170, 10, 0x60080000 };
Battle D_800A75A4 = { 170, 10, 0x60080000 };
Battle D_800A75B0 = { 170, 10, 0x60080000 };
Battle D_800A75BC = { 170, 10, 0x60080000 };
BattleList D_800A75C8 = {
    4,
    { &D_800A7568, &D_800A7574, &D_800A7580, &D_800A758C,
      &D_800A7598, &D_800A75A4, &D_800A75B0, &D_800A75BC },
};
Battle D_800A75EC = { 0, 0, 0x60040000 };
Battle D_800A75F8 = { 0, 0, 0x60040000 };
Battle D_800A7604 = { 0, 0, 0x60040000 };
Battle D_800A7610 = { 0, 0, 0x60040000 };
Battle D_800A761C = { 0, 0, 0x60040000 };
Battle D_800A7628 = { 0, 0, 0x60040000 };
Battle D_800A7634 = { 0, 0, 0x60040000 };
Battle D_800A7640 = { 0, 0, 0x60040000 };
BattleList D_800A764C = {
    0,
    { &D_800A75EC, &D_800A75F8, &D_800A7604, &D_800A7610,
      &D_800A761C, &D_800A7628, &D_800A7634, &D_800A7640 },
};
Battle D_800A7670 = { 0, 0, 0x60040000 };
Battle D_800A767C = { 0, 0, 0x60040000 };
Battle D_800A7688 = { 0, 0, 0x60040000 };
Battle D_800A7694 = { 0, 0, 0x60040000 };
Battle D_800A76A0 = { 0, 0, 0x60040000 };
Battle D_800A76AC = { 0, 0, 0x60040000 };
Battle D_800A76B8 = { 0, 0, 0x60040000 };
Battle D_800A76C4 = { 0, 0, 0x60040000 };
BattleList D_800A76D0 = {
    0,
    { &D_800A7670, &D_800A767C, &D_800A7688, &D_800A7694,
      &D_800A76A0, &D_800A76AC, &D_800A76B8, &D_800A76C4 },
};
Battle D_800A76F4 = { 0, 0, 0x60040000 };
Battle D_800A7700 = { 0, 0, 0x60040000 };
Battle D_800A770C = { 0, 0, 0x60040000 };
Battle D_800A7718 = { 0, 0, 0x60040000 };
Battle D_800A7724 = { 0, 0, 0x60040000 };
Battle D_800A7730 = { 0, 0, 0x60040000 };
Battle D_800A773C = { 0, 0, 0x60040000 };
Battle D_800A7748 = { 0, 0, 0x60040000 };
BattleList D_800A7754 = {
    0,
    { &D_800A76F4, &D_800A7700, &D_800A770C, &D_800A7718,
      &D_800A7724, &D_800A7730, &D_800A773C, &D_800A7748 },
};
Battle D_800A7778 = { 110, 10, 0x60080000 };
Battle D_800A7784 = { 110, 10, 0x60080000 };
Battle D_800A7790 = { 110, 10, 0x60080000 };
Battle D_800A779C = { 110, 10, 0x60080000 };
Battle D_800A77A8 = { 110, 10, 0x60080000 };
Battle D_800A77B4 = { 110, 10, 0x60080000 };
Battle D_800A77C0 = { 110, 10, 0x60080000 };
Battle D_800A77CC = { 110, 10, 0x60080000 };
BattleList D_800A77D8 = {
    1,
    { &D_800A7778, &D_800A7784, &D_800A7790, &D_800A779C,
      &D_800A77A8, &D_800A77B4, &D_800A77C0, &D_800A77CC },
};
Battle D_800A77FC = { 0, 0, 0x60040000 };
Battle D_800A7808 = { 0, 0, 0x60040000 };
Battle D_800A7814 = { 0, 0, 0x60040000 };
Battle D_800A7820 = { 0, 0, 0x60040000 };
Battle D_800A782C = { 0, 0, 0x60040000 };
Battle D_800A7838 = { 0, 0, 0x60040000 };
Battle D_800A7844 = { 0, 0, 0x60040000 };
Battle D_800A7850 = { 0, 0, 0x60040000 };
BattleList D_800A785C = {
    0,
    { &D_800A77FC, &D_800A7808, &D_800A7814, &D_800A7820,
      &D_800A782C, &D_800A7838, &D_800A7844, &D_800A7850 },
};
Battle D_800A7880 = { 0, 0, 0x60040000 };
Battle D_800A788C = { 0, 0, 0x60040000 };
Battle D_800A7898 = { 0, 0, 0x60040000 };
Battle D_800A78A4 = { 0, 0, 0x60040000 };
Battle D_800A78B0 = { 0, 0, 0x60040000 };
Battle D_800A78BC = { 0, 0, 0x60040000 };
Battle D_800A78C8 = { 0, 0, 0x60040000 };
Battle D_800A78D4 = { 0, 0, 0x60040000 };
BattleList D_800A78E0 = {
    0,
    { &D_800A7880, &D_800A788C, &D_800A7898, &D_800A78A4,
      &D_800A78B0, &D_800A78BC, &D_800A78C8, &D_800A78D4 },
};
Battle D_800A7904 = { 0, 0, 0x60040000 };
Battle D_800A7910 = { 0, 0, 0x60040000 };
Battle D_800A791C = { 0, 0, 0x60040000 };
Battle D_800A7928 = { 0, 0, 0x60040000 };
Battle D_800A7934 = { 0, 0, 0x60040000 };
Battle D_800A7940 = { 0, 0, 0x60040000 };
Battle D_800A794C = { 0, 0, 0x60040000 };
Battle D_800A7958 = { 0, 0, 0x60040000 };
BattleList D_800A7964 = {
    0,
    { &D_800A7904, &D_800A7910, &D_800A791C, &D_800A7928,
      &D_800A7934, &D_800A7940, &D_800A794C, &D_800A7958 },
};
Battle D_800A7988 = { 182, 10, 0x60080000 };
Battle D_800A7994 = { 182, 10, 0x60080000 };
Battle D_800A79A0 = { 182, 10, 0x60080000 };
Battle D_800A79AC = { 182, 10, 0x60080000 };
Battle D_800A79B8 = { 71, 10, 0x60080000 };
Battle D_800A79C4 = { 71, 10, 0x60080000 };
Battle D_800A79D0 = { 71, 10, 0x60080000 };
Battle D_800A79DC = { 71, 10, 0x60080000 };
BattleList D_800A79E8 = {
    1,
    { &D_800A7988, &D_800A7994, &D_800A79A0, &D_800A79AC,
      &D_800A79B8, &D_800A79C4, &D_800A79D0, &D_800A79DC },
};
Battle D_800A7A0C = { 0, 0, 0x60040000 };
Battle D_800A7A18 = { 0, 0, 0x60040000 };
Battle D_800A7A24 = { 0, 0, 0x60040000 };
Battle D_800A7A30 = { 0, 0, 0x60040000 };
Battle D_800A7A3C = { 0, 0, 0x60040000 };
Battle D_800A7A48 = { 0, 0, 0x60040000 };
Battle D_800A7A54 = { 0, 0, 0x60040000 };
Battle D_800A7A60 = { 0, 0, 0x60040000 };
BattleList D_800A7A6C = {
    0,
    { &D_800A7A0C, &D_800A7A18, &D_800A7A24, &D_800A7A30,
      &D_800A7A3C, &D_800A7A48, &D_800A7A54, &D_800A7A60 },
};
Battle D_800A7A90 = { 0, 0, 0x60040000 };
Battle D_800A7A9C = { 0, 0, 0x60040000 };
Battle D_800A7AA8 = { 0, 0, 0x60040000 };
Battle D_800A7AB4 = { 0, 0, 0x60040000 };
Battle D_800A7AC0 = { 0, 0, 0x60040000 };
Battle D_800A7ACC = { 0, 0, 0x60040000 };
Battle D_800A7AD8 = { 0, 0, 0x60040000 };
Battle D_800A7AE4 = { 0, 0, 0x60040000 };
BattleList D_800A7AF0 = {
    0,
    { &D_800A7A90, &D_800A7A9C, &D_800A7AA8, &D_800A7AB4,
      &D_800A7AC0, &D_800A7ACC, &D_800A7AD8, &D_800A7AE4 },
};
Battle D_800A7B14 = { 0, 0, 0x60040000 };
Battle D_800A7B20 = { 0, 0, 0x60040000 };
Battle D_800A7B2C = { 0, 0, 0x60040000 };
Battle D_800A7B38 = { 0, 0, 0x60040000 };
Battle D_800A7B44 = { 0, 0, 0x60040000 };
Battle D_800A7B50 = { 0, 0, 0x60040000 };
Battle D_800A7B5C = { 0, 0, 0x60040000 };
Battle D_800A7B68 = { 0, 0, 0x60040000 };
BattleList D_800A7B74 = {
    0,
    { &D_800A7B14, &D_800A7B20, &D_800A7B2C, &D_800A7B38,
      &D_800A7B44, &D_800A7B50, &D_800A7B5C, &D_800A7B68 },
};
Battle D_800A7B98 = { 182, 10, 0x60080000 };
Battle D_800A7BA4 = { 182, 10, 0x60080000 };
Battle D_800A7BB0 = { 182, 10, 0x60080000 };
Battle D_800A7BBC = { 182, 10, 0x60080000 };
Battle D_800A7BC8 = { 71, 10, 0x60080000 };
Battle D_800A7BD4 = { 71, 10, 0x60080000 };
Battle D_800A7BE0 = { 71, 10, 0x60080000 };
Battle D_800A7BEC = { 71, 10, 0x60080000 };
BattleList D_800A7BF8 = {
    4,
    { &D_800A7B98, &D_800A7BA4, &D_800A7BB0, &D_800A7BBC,
      &D_800A7BC8, &D_800A7BD4, &D_800A7BE0, &D_800A7BEC },
};
Battle D_800A7C1C = { 0, 0, 0x60040000 };
Battle D_800A7C28 = { 0, 0, 0x60040000 };
Battle D_800A7C34 = { 0, 0, 0x60040000 };
Battle D_800A7C40 = { 0, 0, 0x60040000 };
Battle D_800A7C4C = { 0, 0, 0x60040000 };
Battle D_800A7C58 = { 0, 0, 0x60040000 };
Battle D_800A7C64 = { 0, 0, 0x60040000 };
Battle D_800A7C70 = { 0, 0, 0x60040000 };
BattleList D_800A7C7C = {
    0,
    { &D_800A7C1C, &D_800A7C28, &D_800A7C34, &D_800A7C40,
      &D_800A7C4C, &D_800A7C58, &D_800A7C64, &D_800A7C70 },
};
Battle D_800A7CA0 = { 0, 0, 0x60040000 };
Battle D_800A7CAC = { 0, 0, 0x60040000 };
Battle D_800A7CB8 = { 0, 0, 0x60040000 };
Battle D_800A7CC4 = { 0, 0, 0x60040000 };
Battle D_800A7CD0 = { 0, 0, 0x60040000 };
Battle D_800A7CDC = { 0, 0, 0x60040000 };
Battle D_800A7CE8 = { 0, 0, 0x60040000 };
Battle D_800A7CF4 = { 0, 0, 0x60040000 };
BattleList D_800A7D00 = {
    0,
    { &D_800A7CA0, &D_800A7CAC, &D_800A7CB8, &D_800A7CC4,
      &D_800A7CD0, &D_800A7CDC, &D_800A7CE8, &D_800A7CF4 },
};
Battle D_800A7D24 = { 0, 0, 0x60040000 };
Battle D_800A7D30 = { 0, 0, 0x60040000 };
Battle D_800A7D3C = { 0, 0, 0x60040000 };
Battle D_800A7D48 = { 0, 0, 0x60040000 };
Battle D_800A7D54 = { 0, 0, 0x60040000 };
Battle D_800A7D60 = { 0, 0, 0x60040000 };
Battle D_800A7D6C = { 0, 0, 0x60040000 };
Battle D_800A7D78 = { 0, 0, 0x60040000 };
BattleList D_800A7D84 = {
    0,
    { &D_800A7D24, &D_800A7D30, &D_800A7D3C, &D_800A7D48,
      &D_800A7D54, &D_800A7D60, &D_800A7D6C, &D_800A7D78 },
};
Battle D_800A7DA8 = { 174, 10, 0x60080000 };
Battle D_800A7DB4 = { 174, 10, 0x60080000 };
Battle D_800A7DC0 = { 170, 10, 0x60080000 };
Battle D_800A7DCC = { 170, 10, 0x60080000 };
Battle D_800A7DD8 = { 170, 10, 0x60080000 };
Battle D_800A7DE4 = { 170, 10, 0x60080000 };
Battle D_800A7DF0 = { 170, 10, 0x60080000 };
Battle D_800A7DFC = { 170, 10, 0x60080000 };
BattleList D_800A7E08 = {
    2,
    { &D_800A7DA8, &D_800A7DB4, &D_800A7DC0, &D_800A7DCC,
      &D_800A7DD8, &D_800A7DE4, &D_800A7DF0, &D_800A7DFC },
};
Battle D_800A7E2C = { 0, 0, 0x60040000 };
Battle D_800A7E38 = { 0, 0, 0x60040000 };
Battle D_800A7E44 = { 0, 0, 0x60040000 };
Battle D_800A7E50 = { 0, 0, 0x60040000 };
Battle D_800A7E5C = { 0, 0, 0x60040000 };
Battle D_800A7E68 = { 0, 0, 0x60040000 };
Battle D_800A7E74 = { 0, 0, 0x60040000 };
Battle D_800A7E80 = { 0, 0, 0x60040000 };
BattleList D_800A7E8C = {
    0,
    { &D_800A7E2C, &D_800A7E38, &D_800A7E44, &D_800A7E50,
      &D_800A7E5C, &D_800A7E68, &D_800A7E74, &D_800A7E80 },
};
Battle D_800A7EB0 = { 0, 0, 0x60040000 };
Battle D_800A7EBC = { 0, 0, 0x60040000 };
Battle D_800A7EC8 = { 0, 0, 0x60040000 };
Battle D_800A7ED4 = { 0, 0, 0x60040000 };
Battle D_800A7EE0 = { 0, 0, 0x60040000 };
Battle D_800A7EEC = { 0, 0, 0x60040000 };
Battle D_800A7EF8 = { 0, 0, 0x60040000 };
Battle D_800A7F04 = { 0, 0, 0x60040000 };
BattleList D_800A7F10 = {
    0,
    { &D_800A7EB0, &D_800A7EBC, &D_800A7EC8, &D_800A7ED4,
      &D_800A7EE0, &D_800A7EEC, &D_800A7EF8, &D_800A7F04 },
};
Battle D_800A7F34 = { 0, 0, 0x60040000 };
Battle D_800A7F40 = { 0, 0, 0x60040000 };
Battle D_800A7F4C = { 0, 0, 0x60040000 };
Battle D_800A7F58 = { 0, 0, 0x60040000 };
Battle D_800A7F64 = { 0, 0, 0x60040000 };
Battle D_800A7F70 = { 0, 0, 0x60040000 };
Battle D_800A7F7C = { 0, 0, 0x60040000 };
Battle D_800A7F88 = { 0, 0, 0x60040000 };
BattleList D_800A7F94 = {
    0,
    { &D_800A7F34, &D_800A7F40, &D_800A7F4C, &D_800A7F58,
      &D_800A7F64, &D_800A7F70, &D_800A7F7C, &D_800A7F88 },
};
Battle D_800A7FB8 = { 182, 10, 0x60080000 };
Battle D_800A7FC4 = { 182, 10, 0x60080000 };
Battle D_800A7FD0 = { 182, 10, 0x60080000 };
Battle D_800A7FDC = { 182, 10, 0x60080000 };
Battle D_800A7FE8 = { 71, 10, 0x60080000 };
Battle D_800A7FF4 = { 71, 10, 0x60080000 };
Battle D_800A8000 = { 71, 10, 0x60080000 };
Battle D_800A800C = { 71, 10, 0x60080000 };
BattleList D_800A8018 = {
    1,
    { &D_800A7FB8, &D_800A7FC4, &D_800A7FD0, &D_800A7FDC,
      &D_800A7FE8, &D_800A7FF4, &D_800A8000, &D_800A800C },
};
Battle D_800A803C = { 0, 0, 0x60040000 };
Battle D_800A8048 = { 0, 0, 0x60040000 };
Battle D_800A8054 = { 0, 0, 0x60040000 };
Battle D_800A8060 = { 0, 0, 0x60040000 };
Battle D_800A806C = { 0, 0, 0x60040000 };
Battle D_800A8078 = { 0, 0, 0x60040000 };
Battle D_800A8084 = { 0, 0, 0x60040000 };
Battle D_800A8090 = { 0, 0, 0x60040000 };
BattleList D_800A809C = {
    0,
    { &D_800A803C, &D_800A8048, &D_800A8054, &D_800A8060,
      &D_800A806C, &D_800A8078, &D_800A8084, &D_800A8090 },
};
Battle D_800A80C0 = { 0, 0, 0x60040000 };
Battle D_800A80CC = { 0, 0, 0x60040000 };
Battle D_800A80D8 = { 0, 0, 0x60040000 };
Battle D_800A80E4 = { 0, 0, 0x60040000 };
Battle D_800A80F0 = { 0, 0, 0x60040000 };
Battle D_800A80FC = { 0, 0, 0x60040000 };
Battle D_800A8108 = { 0, 0, 0x60040000 };
Battle D_800A8114 = { 0, 0, 0x60040000 };
BattleList D_800A8120 = {
    0,
    { &D_800A80C0, &D_800A80CC, &D_800A80D8, &D_800A80E4,
      &D_800A80F0, &D_800A80FC, &D_800A8108, &D_800A8114 },
};
Battle D_800A8144 = { 0, 0, 0x60040000 };
Battle D_800A8150 = { 0, 0, 0x60040000 };
Battle D_800A815C = { 0, 0, 0x60040000 };
Battle D_800A8168 = { 0, 0, 0x60040000 };
Battle D_800A8174 = { 0, 0, 0x60040000 };
Battle D_800A8180 = { 0, 0, 0x60040000 };
Battle D_800A818C = { 0, 0, 0x60040000 };
Battle D_800A8198 = { 0, 0, 0x60040000 };
BattleList D_800A81A4 = {
    0,
    { &D_800A8144, &D_800A8150, &D_800A815C, &D_800A8168,
      &D_800A8174, &D_800A8180, &D_800A818C, &D_800A8198 },
};
Battle D_800A81C8 = { 182, 10, 0x60080000 };
Battle D_800A81D4 = { 182, 10, 0x60080000 };
Battle D_800A81E0 = { 182, 10, 0x60080000 };
Battle D_800A81EC = { 182, 10, 0x60080000 };
Battle D_800A81F8 = { 71, 10, 0x60080000 };
Battle D_800A8204 = { 71, 10, 0x60080000 };
Battle D_800A8210 = { 71, 10, 0x60080000 };
Battle D_800A821C = { 71, 10, 0x60080000 };
BattleList D_800A8228 = {
    1,
    { &D_800A81C8, &D_800A81D4, &D_800A81E0, &D_800A81EC,
      &D_800A81F8, &D_800A8204, &D_800A8210, &D_800A821C },
};
Battle D_800A824C = { 0, 0, 0x60040000 };
Battle D_800A8258 = { 0, 0, 0x60040000 };
Battle D_800A8264 = { 0, 0, 0x60040000 };
Battle D_800A8270 = { 0, 0, 0x60040000 };
Battle D_800A827C = { 0, 0, 0x60040000 };
Battle D_800A8288 = { 0, 0, 0x60040000 };
Battle D_800A8294 = { 0, 0, 0x60040000 };
Battle D_800A82A0 = { 0, 0, 0x60040000 };
BattleList D_800A82AC = {
    0,
    { &D_800A824C, &D_800A8258, &D_800A8264, &D_800A8270,
      &D_800A827C, &D_800A8288, &D_800A8294, &D_800A82A0 },
};
Battle D_800A82D0 = { 0, 0, 0x60040000 };
Battle D_800A82DC = { 0, 0, 0x60040000 };
Battle D_800A82E8 = { 0, 0, 0x60040000 };
Battle D_800A82F4 = { 0, 0, 0x60040000 };
Battle D_800A8300 = { 0, 0, 0x60040000 };
Battle D_800A830C = { 0, 0, 0x60040000 };
Battle D_800A8318 = { 0, 0, 0x60040000 };
Battle D_800A8324 = { 0, 0, 0x60040000 };
BattleList D_800A8330 = {
    0,
    { &D_800A82D0, &D_800A82DC, &D_800A82E8, &D_800A82F4,
      &D_800A8300, &D_800A830C, &D_800A8318, &D_800A8324 },
};
Battle D_800A8354 = { 0, 0, 0x60040000 };
Battle D_800A8360 = { 0, 0, 0x60040000 };
Battle D_800A836C = { 0, 0, 0x60040000 };
Battle D_800A8378 = { 0, 0, 0x60040000 };
Battle D_800A8384 = { 0, 0, 0x60040000 };
Battle D_800A8390 = { 0, 0, 0x60040000 };
Battle D_800A839C = { 0, 0, 0x60040000 };
Battle D_800A83A8 = { 0, 0, 0x60040000 };
BattleList D_800A83B4 = {
    0,
    { &D_800A8354, &D_800A8360, &D_800A836C, &D_800A8378,
      &D_800A8384, &D_800A8390, &D_800A839C, &D_800A83A8 },
};
Battle D_800A83D8 = { 174, 10, 0x60080000 };
Battle D_800A83E4 = { 174, 10, 0x60080000 };
Battle D_800A83F0 = { 170, 10, 0x60080000 };
Battle D_800A83FC = { 170, 10, 0x60080000 };
Battle D_800A8408 = { 182, 10, 0x60080000 };
Battle D_800A8414 = { 182, 10, 0x60080000 };
Battle D_800A8420 = { 71, 10, 0x60080000 };
Battle D_800A842C = { 71, 10, 0x60080000 };
BattleList D_800A8438 = {
    1,
    { &D_800A83D8, &D_800A83E4, &D_800A83F0, &D_800A83FC,
      &D_800A8408, &D_800A8414, &D_800A8420, &D_800A842C },
};
Battle D_800A845C = { 0, 0, 0x60040000 };
Battle D_800A8468 = { 0, 0, 0x60040000 };
Battle D_800A8474 = { 0, 0, 0x60040000 };
Battle D_800A8480 = { 0, 0, 0x60040000 };
Battle D_800A848C = { 0, 0, 0x60040000 };
Battle D_800A8498 = { 0, 0, 0x60040000 };
Battle D_800A84A4 = { 0, 0, 0x60040000 };
Battle D_800A84B0 = { 0, 0, 0x60040000 };
BattleList D_800A84BC = {
    0,
    { &D_800A845C, &D_800A8468, &D_800A8474, &D_800A8480,
      &D_800A848C, &D_800A8498, &D_800A84A4, &D_800A84B0 },
};
Battle D_800A84E0 = { 0, 0, 0x60040000 };
Battle D_800A84EC = { 0, 0, 0x60040000 };
Battle D_800A84F8 = { 0, 0, 0x60040000 };
Battle D_800A8504 = { 0, 0, 0x60040000 };
Battle D_800A8510 = { 0, 0, 0x60040000 };
Battle D_800A851C = { 0, 0, 0x60040000 };
Battle D_800A8528 = { 0, 0, 0x60040000 };
Battle D_800A8534 = { 0, 0, 0x60040000 };
BattleList D_800A8540 = {
    0,
    { &D_800A84E0, &D_800A84EC, &D_800A84F8, &D_800A8504,
      &D_800A8510, &D_800A851C, &D_800A8528, &D_800A8534 },
};
Battle D_800A8564 = { 0, 0, 0x60040000 };
Battle D_800A8570 = { 0, 0, 0x60040000 };
Battle D_800A857C = { 0, 0, 0x60040000 };
Battle D_800A8588 = { 0, 0, 0x60040000 };
Battle D_800A8594 = { 0, 0, 0x60040000 };
Battle D_800A85A0 = { 0, 0, 0x60040000 };
Battle D_800A85AC = { 0, 0, 0x60040000 };
Battle D_800A85B8 = { 0, 0, 0x60040000 };
BattleList D_800A85C4 = {
    0,
    { &D_800A8564, &D_800A8570, &D_800A857C, &D_800A8588,
      &D_800A8594, &D_800A85A0, &D_800A85AC, &D_800A85B8 },
};
FieldBattles stageBattles[] = {
    { 231, 1, 0, { &D_800A5AF8, &D_800A5B7C, &D_800A5C00, &D_800A5C84 } },
    { 238, 2, 0, { &D_800A5D08, &D_800A5D8C, &D_800A5E10, &D_800A5E94 } },
    { 243, 3, 0, { &D_800A5F18, &D_800A5F9C, &D_800A6020, &D_800A60A4 } },
    { 249, 4, 0, { &D_800A6128, &D_800A61AC, &D_800A6230, &D_800A62B4 } },
    { 254, 5, 0, { &D_800A6338, &D_800A63BC, &D_800A6440, &D_800A64C4 } },
    { 261, 6, 0, { &D_800A6548, &D_800A65CC, &D_800A6650, &D_800A66D4 } },
    { 270, 8, 0, { &D_800A6758, &D_800A67DC, &D_800A6860, &D_800A68E4 } },
    { 276, 9, 0, { &D_800A6968, &D_800A69EC, &D_800A6A70, &D_800A6AF4 } },
    { 281, 10, 0, { &D_800A6B78, &D_800A6BFC, &D_800A6C80, &D_800A6D04 } },
    { 286, 11, 0, { &D_800A6D88, &D_800A6E0C, &D_800A6E90, &D_800A6F14 } },
    { 291, 12, 0, { &D_800A6F98, &D_800A701C, &D_800A70A0, &D_800A7124 } },
    { 298, 13, 0, { &D_800A71A8, &D_800A722C, &D_800A72B0, &D_800A7334 } },
    { 302, 14, 0, { &D_800A73B8, &D_800A743C, &D_800A74C0, &D_800A7544 } },
    { 310, 16, 0, { &D_800A75C8, &D_800A764C, &D_800A76D0, &D_800A7754 } },
    { 321, 19, 0, { &D_800A77D8, &D_800A785C, &D_800A78E0, &D_800A7964 } },
    { 327, 20, 0, { &D_800A79E8, &D_800A7A6C, &D_800A7AF0, &D_800A7B74 } },
    { 348, 25, 0, { &D_800A7BF8, &D_800A7C7C, &D_800A7D00, &D_800A7D84 } },
    { 353, 27, 0, { &D_800A7E08, &D_800A7E8C, &D_800A7F10, &D_800A7F94 } },
    { 359, 28, 0, { &D_800A8018, &D_800A809C, &D_800A8120, &D_800A81A4 } },
    { 366, 29, 0, { &D_800A8228, &D_800A82AC, &D_800A8330, &D_800A83B4 } },
    { 369, 30, 0, { &D_800A8438, &D_800A84BC, &D_800A8540, &D_800A85C4 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x140, 0x1FF },
    { 0x140, 0x100, 0x170, 0x140, 0xC0, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x168, 0x140, 0xA0, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x148, 0x140, 0x20, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x150, 0x140, 0x40, 0x40, 0x150, 0x1FE },
    { 0x140, 0x100, 0x158, 0x140, 0x60, 0x40, 0x160, 0x1FE },
    { 0x140, 0x100, 0x160, 0x140, 0x80, 0x40, 0x170, 0x1FE },
    { 0x140, 0x100, 0x174, 0x120, 0xD0, 0x20, 0x140, 0x1FD },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x150, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x160, 0x1FD },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x170, 0x1FD },
};
FieldTalk D_800A8954[] = {
    { NULL, NULL, 0x3B2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A896C[] = {
    { NULL, NULL, 0x3B3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8984[] = {
    { NULL, NULL, 0x3BA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A899C[] = {
    { NULL, NULL, 0x359 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A89B4[] = {
    { NULL, NULL, 0x3B6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A89CC[] = {
    { NULL, NULL, 0x3B7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A89E4[] = {
    { NULL, NULL, 0x3B9 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A89FC[] = {
    { NULL, NULL, 0x355 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8A14[] = {
    { NULL, NULL, 0x3B8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8A2C[] = {
    { NULL, NULL, 0x3BB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8A44[] = {
    { NULL, NULL, 0x35C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8A5C[] = {
    { NULL, NULL, 0x35A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8A74[] = {
    { NULL, NULL, 0x3B4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8A8C[] = {
    { NULL, NULL, 0x3BC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8AA4[] = {
    { NULL, NULL, 0x357 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8ABC[] = {
    { NULL, NULL, 0x356 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8AD4[] = {
    { NULL, NULL, 0x35D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8AEC[] = {
    { NULL, NULL, 0x358 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8B04[] = {
    { NULL, NULL, 0x35B },
    { NULL, NULL, 0 },
};
u16 D_800A8B1C[] = { 0x7E00, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8B28[] = { 0x7E03, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8B34[] = { 0x7E21, 1, 0x7E13, 1, 0xFFFF };
u16 D_800A8B40[] = { 0x7E04, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8B4C[] = { 0x7E0B, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8B58[] = { 0x7E0C, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8B64[] = { 0x7E12, 1, 0x7E20, 1, 0xFFFF };
u16 D_800A8B70[] = { 0x7E02, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8B7C[] = { 0x7E0D, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8B88[] = { 0x7E13, 1, 0x7E22, 1, 0xFFFF };
u16 D_800A8B94[] = { 0x7E01, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8BA0[] = { 0x7E02, 1, 0x7E21, 1, 0xFFFF };
u16 D_800A8BAC[] = { 0x7E07, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8BB8[] = { 0x7E1B, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8BC4[] = { 0x7E04, 1, 0x7E20, 1, 0xFFFF };
u16 D_800A8BD0[] = { 0x7E08, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8BDC[] = { 0x7E13, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8BE8[] = { 0x7E04, 1, 0x7E21, 1, 0xFFFF };
u16 D_800A8BF4[] = { 0x7E05, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8C00[] = { 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A8C0C[] = { 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A8C18[] = { 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A8C24[] = { 0x7E0B, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C30[] = { 0x7E12, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C3C[] = { 0x7E13, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C48[] = { 0x7E1A, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C54[] = { 0x7E1B, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C60[] = { 0x7E00, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C6C[] = { 0x7E02, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C78[] = { 0x7E03, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C84[] = { 0x7E04, 1, 0xA, 0, 0xFFFF };
u16 D_800A8C90[] = { 0x7E07, 1, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A8C9C = { D_800A8B1C, D_800A8954, 0x23, 4, 984, 448, 1 };
FieldActorEntry D_800A8CB0 = { D_800A8B28, D_800A896C, 0x23, 4, 984, 448, 1 };
FieldActorEntry D_800A8CC4 = { D_800A8B34, D_800A8984, 0x23, 4, 672, 216, 7 };
FieldActorEntry D_800A8CD8 = { D_800A8B40, D_800A899C, 0x23, 4, 672, 216, 7 };
FieldActorEntry D_800A8CEC = { D_800A8B4C, D_800A89B4, 0x40, 5, 672, 216, 7 };
FieldActorEntry D_800A8D00 = { D_800A8B58, D_800A89CC, 0x40, 5, 384, 100, 1 };
FieldActorEntry D_800A8D14 = { D_800A8B64, D_800A89E4, 0x40, 5, 672, 216, 7 };
FieldActorEntry D_800A8D28 = { D_800A8B70, D_800A89FC, 0x40, 5, 672, 216, 7 };
FieldActorEntry D_800A8D3C = { D_800A8B7C, D_800A8A14, 0x41, 6, 672, 216, 7 };
FieldActorEntry D_800A8D50 = { D_800A8B88, D_800A8A2C, 0x41, 6, 672, 216, 7 };
FieldActorEntry D_800A8D64 = { D_800A8B94, D_800A8A44, 0x41, 6, 672, 216, 7 };
FieldActorEntry D_800A8D78 = { D_800A8BA0, D_800A8A5C, 0xB4, 7, 672, 216, 7 };
FieldActorEntry D_800A8D8C = { D_800A8BAC, D_800A8A74, 0xB5, 8, 984, 448, 1 };
FieldActorEntry D_800A8DA0 = { D_800A8BB8, D_800A8A8C, 0xB5, 8, 384, 100, 1 };
FieldActorEntry D_800A8DB4 = { D_800A8BC4, D_800A8AA4, 0xB5, 8, 672, 216, 7 };
FieldActorEntry D_800A8DC8 = { D_800A8BD0, D_800A8ABC, 0xE7, 9, 672, 216, 7 };
FieldActorEntry D_800A8DDC = { D_800A8BDC, D_800A8AD4, 0xEB, 0xA, 672, 216, 7 };
FieldActorEntry D_800A8DF0 = { D_800A8BE8, D_800A8AEC, 0xEF, 0xB, 672, 216, 7 };
FieldActorEntry D_800A8E04 = { D_800A8BF4, D_800A8B04, 0xF1, 0xC, 672, 216, 7 };
FieldActorEntry D_800A8E18 = { NULL, NULL, 0x146, 0xD, 0, 0, 0 };
FieldActorEntry D_800A8E2C = { D_800A8C00, NULL, 0x15F, 0xE, 768, 352, 1 };
FieldActorEntry D_800A8E40 = { D_800A8C0C, NULL, 0x15F, 0xE, 456, 340, 1 };
FieldActorEntry D_800A8E54 = { D_800A8C18, NULL, 0x15F, 0xE, 448, 384, 1 };
FieldActorEntry D_800A8E68 = { D_800A8C24, NULL, 0x160, 0xF, 272, 168, 1 };
FieldActorEntry D_800A8E7C = { D_800A8C30, NULL, 0x160, 0xF, 880, 152, 1 };
FieldActorEntry D_800A8E90 = { D_800A8C3C, NULL, 0x160, 0xF, 480, 256, 1 };
FieldActorEntry D_800A8EA4 = { D_800A8C48, NULL, 0x160, 0xF, 640, 416, 1 };
FieldActorEntry D_800A8EB8 = { D_800A8C54, NULL, 0x160, 0xF, 784, 200, 1 };
FieldActorEntry D_800A8ECC = { D_800A8C60, NULL, 0x160, 0xF, 784, 200, 1 };
FieldActorEntry D_800A8EE0 = { D_800A8C6C, NULL, 0x160, 0xF, 488, 164, 1 };
FieldActorEntry D_800A8EF4 = { D_800A8C78, NULL, 0x160, 0xF, 784, 200, 1 };
FieldActorEntry D_800A8F08 = { D_800A8C84, NULL, 0x160, 0xF, 880, 408, 1 };
FieldActorEntry D_800A8F1C = { D_800A8C90, NULL, 0x160, 0xF, 480, 256, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A8C9C,
    &D_800A8CB0,
    &D_800A8CC4,
    &D_800A8CD8,
    &D_800A8CEC,
    &D_800A8D00,
    &D_800A8D14,
    &D_800A8D28,
    &D_800A8D3C,
    &D_800A8D50,
    &D_800A8D64,
    &D_800A8D78,
    &D_800A8D8C,
    &D_800A8DA0,
    &D_800A8DB4,
    &D_800A8DC8,
    &D_800A8DDC,
    &D_800A8DF0,
    &D_800A8E04,
    &D_800A8E18,
    &D_800A8E2C,
    &D_800A8E40,
    &D_800A8E54,
    &D_800A8E68,
    &D_800A8E7C,
    &D_800A8E90,
    &D_800A8EA4,
    &D_800A8EB8,
    &D_800A8ECC,
    &D_800A8EE0,
    &D_800A8EF4,
    &D_800A8F08,
    &D_800A8F1C,
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
