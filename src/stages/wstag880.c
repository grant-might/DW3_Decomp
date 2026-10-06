#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x680
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x690
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xEB00, 0x1F500};
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
extern StagePoint D_800A4FA8;
extern StagePoint D_800A4FC0;
extern StagePoint D_800A4FD8;
extern StagePoint D_800A4FF0;
extern StagePoint D_800A5008;
extern StagePoint D_800A5020;
extern StagePoint D_800A5038;
extern StagePoint D_800A5050;
extern StagePoint D_800A5068;
extern StagePoint D_800A5080;
extern StagePoint D_800A5098;
extern StagePoint D_800A50B0;
extern StagePoint D_800A50C8;
extern StagePoint D_800A50E0;
extern StagePoint D_800A50F8;
extern StagePoint D_800A5110;
extern StagePoint D_800A5128;
extern StagePoint D_800A5140;
extern StagePoint D_800A5158;
extern StagePoint D_800A5170;
extern StagePoint D_800A5188;
extern StagePoint D_800A51A0;
extern StagePoint D_800A51B8;
extern StagePoint D_800A51D0;
extern StagePoint D_800A51E8;
extern StagePoint D_800A5200;
extern StagePoint D_800A5218;
extern StagePoint D_800A5230;
extern StagePoint D_800A5248;
extern StagePoint D_800A5260;
extern StagePoint D_800A5278;
extern StagePoint D_800A5290;
extern StagePoint D_800A52A8;
extern StagePoint D_800A52C0;
extern StagePoint D_800A52D8;
extern StagePoint D_800A52F0;
extern StagePoint D_800A5308;
extern StagePoint D_800A5320;
extern StagePoint D_800A5338;
extern StagePoint D_800A5350;
extern StagePoint D_800A5368;
extern StagePoints D_800A4FA0;
extern StagePoints D_800A4FB8;
extern StagePoints D_800A4FD0;
extern StagePoints D_800A4FE8;
extern StagePoints D_800A5000;
extern StagePoints D_800A5018;
extern StagePoints D_800A5030;
extern StagePoints D_800A5048;
extern StagePoints D_800A5060;
extern StagePoints D_800A5078;
extern StagePoints D_800A5090;
extern StagePoints D_800A50A8;
extern StagePoints D_800A50C0;
extern StagePoints D_800A50D8;
extern StagePoints D_800A50F0;
extern StagePoints D_800A5108;
extern StagePoints D_800A5120;
extern StagePoints D_800A5138;
extern StagePoints D_800A5150;
extern StagePoints D_800A5168;
extern StagePoints D_800A5180;
extern StagePoints D_800A5198;
extern StagePoints D_800A51B0;
extern StagePoints D_800A51C8;
extern StagePoints D_800A51E0;
extern StagePoints D_800A51F8;
extern StagePoints D_800A5210;
extern StagePoints D_800A5228;
extern StagePoints D_800A5240;
extern StagePoints D_800A5258;
extern StagePoints D_800A5270;
extern StagePoints D_800A5288;
extern StagePoints D_800A52A0;
extern StagePoints D_800A52B8;
extern StagePoints D_800A52D0;
extern StagePoints D_800A52E8;
extern StagePoints D_800A5300;
extern StagePoints D_800A5318;
extern StagePoints D_800A5330;
extern StagePoints D_800A5348;
extern StagePoints D_800A5360;
extern StagePoints D_800A5378;
extern Battle D_800A542C;
extern Battle D_800A5438;
extern Battle D_800A5444;
extern Battle D_800A5450;
extern Battle D_800A545C;
extern Battle D_800A5468;
extern Battle D_800A5474;
extern Battle D_800A5480;
extern Battle D_800A54B0;
extern Battle D_800A54BC;
extern Battle D_800A54C8;
extern Battle D_800A54D4;
extern Battle D_800A54E0;
extern Battle D_800A54EC;
extern Battle D_800A54F8;
extern Battle D_800A5504;
extern Battle D_800A5534;
extern Battle D_800A5540;
extern Battle D_800A554C;
extern Battle D_800A5558;
extern Battle D_800A5564;
extern Battle D_800A5570;
extern Battle D_800A557C;
extern Battle D_800A5588;
extern Battle D_800A55B8;
extern Battle D_800A55C4;
extern Battle D_800A55D0;
extern Battle D_800A55DC;
extern Battle D_800A55E8;
extern Battle D_800A55F4;
extern Battle D_800A5600;
extern Battle D_800A560C;
extern Battle D_800A563C;
extern Battle D_800A5648;
extern Battle D_800A5654;
extern Battle D_800A5660;
extern Battle D_800A566C;
extern Battle D_800A5678;
extern Battle D_800A5684;
extern Battle D_800A5690;
extern Battle D_800A56C0;
extern Battle D_800A56CC;
extern Battle D_800A56D8;
extern Battle D_800A56E4;
extern Battle D_800A56F0;
extern Battle D_800A56FC;
extern Battle D_800A5708;
extern Battle D_800A5714;
extern Battle D_800A5744;
extern Battle D_800A5750;
extern Battle D_800A575C;
extern Battle D_800A5768;
extern Battle D_800A5774;
extern Battle D_800A5780;
extern Battle D_800A578C;
extern Battle D_800A5798;
extern Battle D_800A57C8;
extern Battle D_800A57D4;
extern Battle D_800A57E0;
extern Battle D_800A57EC;
extern Battle D_800A57F8;
extern Battle D_800A5804;
extern Battle D_800A5810;
extern Battle D_800A581C;
extern Battle D_800A584C;
extern Battle D_800A5858;
extern Battle D_800A5864;
extern Battle D_800A5870;
extern Battle D_800A587C;
extern Battle D_800A5888;
extern Battle D_800A5894;
extern Battle D_800A58A0;
extern Battle D_800A58D0;
extern Battle D_800A58DC;
extern Battle D_800A58E8;
extern Battle D_800A58F4;
extern Battle D_800A5900;
extern Battle D_800A590C;
extern Battle D_800A5918;
extern Battle D_800A5924;
extern Battle D_800A5954;
extern Battle D_800A5960;
extern Battle D_800A596C;
extern Battle D_800A5978;
extern Battle D_800A5984;
extern Battle D_800A5990;
extern Battle D_800A599C;
extern Battle D_800A59A8;
extern Battle D_800A59D8;
extern Battle D_800A59E4;
extern Battle D_800A59F0;
extern Battle D_800A59FC;
extern Battle D_800A5A08;
extern Battle D_800A5A14;
extern Battle D_800A5A20;
extern Battle D_800A5A2C;
extern Battle D_800A5A5C;
extern Battle D_800A5A68;
extern Battle D_800A5A74;
extern Battle D_800A5A80;
extern Battle D_800A5A8C;
extern Battle D_800A5A98;
extern Battle D_800A5AA4;
extern Battle D_800A5AB0;
extern Battle D_800A5AE0;
extern Battle D_800A5AEC;
extern Battle D_800A5AF8;
extern Battle D_800A5B04;
extern Battle D_800A5B10;
extern Battle D_800A5B1C;
extern Battle D_800A5B28;
extern Battle D_800A5B34;
extern Battle D_800A5B64;
extern Battle D_800A5B70;
extern Battle D_800A5B7C;
extern Battle D_800A5B88;
extern Battle D_800A5B94;
extern Battle D_800A5BA0;
extern Battle D_800A5BAC;
extern Battle D_800A5BB8;
extern Battle D_800A5BE8;
extern Battle D_800A5BF4;
extern Battle D_800A5C00;
extern Battle D_800A5C0C;
extern Battle D_800A5C18;
extern Battle D_800A5C24;
extern Battle D_800A5C30;
extern Battle D_800A5C3C;
extern Battle D_800A5C6C;
extern Battle D_800A5C78;
extern Battle D_800A5C84;
extern Battle D_800A5C90;
extern Battle D_800A5C9C;
extern Battle D_800A5CA8;
extern Battle D_800A5CB4;
extern Battle D_800A5CC0;
extern Battle D_800A5CF0;
extern Battle D_800A5CFC;
extern Battle D_800A5D08;
extern Battle D_800A5D14;
extern Battle D_800A5D20;
extern Battle D_800A5D2C;
extern Battle D_800A5D38;
extern Battle D_800A5D44;
extern Battle D_800A5D74;
extern Battle D_800A5D80;
extern Battle D_800A5D8C;
extern Battle D_800A5D98;
extern Battle D_800A5DA4;
extern Battle D_800A5DB0;
extern Battle D_800A5DBC;
extern Battle D_800A5DC8;
extern Battle D_800A5DF8;
extern Battle D_800A5E04;
extern Battle D_800A5E10;
extern Battle D_800A5E1C;
extern Battle D_800A5E28;
extern Battle D_800A5E34;
extern Battle D_800A5E40;
extern Battle D_800A5E4C;
extern Battle D_800A5E7C;
extern Battle D_800A5E88;
extern Battle D_800A5E94;
extern Battle D_800A5EA0;
extern Battle D_800A5EAC;
extern Battle D_800A5EB8;
extern Battle D_800A5EC4;
extern Battle D_800A5ED0;
extern Battle D_800A5F00;
extern Battle D_800A5F0C;
extern Battle D_800A5F18;
extern Battle D_800A5F24;
extern Battle D_800A5F30;
extern Battle D_800A5F3C;
extern Battle D_800A5F48;
extern Battle D_800A5F54;
extern Battle D_800A5F84;
extern Battle D_800A5F90;
extern Battle D_800A5F9C;
extern Battle D_800A5FA8;
extern Battle D_800A5FB4;
extern Battle D_800A5FC0;
extern Battle D_800A5FCC;
extern Battle D_800A5FD8;
extern Battle D_800A6008;
extern Battle D_800A6014;
extern Battle D_800A6020;
extern Battle D_800A602C;
extern Battle D_800A6038;
extern Battle D_800A6044;
extern Battle D_800A6050;
extern Battle D_800A605C;
extern Battle D_800A608C;
extern Battle D_800A6098;
extern Battle D_800A60A4;
extern Battle D_800A60B0;
extern Battle D_800A60BC;
extern Battle D_800A60C8;
extern Battle D_800A60D4;
extern Battle D_800A60E0;
extern Battle D_800A6110;
extern Battle D_800A611C;
extern Battle D_800A6128;
extern Battle D_800A6134;
extern Battle D_800A6140;
extern Battle D_800A614C;
extern Battle D_800A6158;
extern Battle D_800A6164;
extern Battle D_800A6194;
extern Battle D_800A61A0;
extern Battle D_800A61AC;
extern Battle D_800A61B8;
extern Battle D_800A61C4;
extern Battle D_800A61D0;
extern Battle D_800A61DC;
extern Battle D_800A61E8;
extern Battle D_800A6218;
extern Battle D_800A6224;
extern Battle D_800A6230;
extern Battle D_800A623C;
extern Battle D_800A6248;
extern Battle D_800A6254;
extern Battle D_800A6260;
extern Battle D_800A626C;
extern Battle D_800A629C;
extern Battle D_800A62A8;
extern Battle D_800A62B4;
extern Battle D_800A62C0;
extern Battle D_800A62CC;
extern Battle D_800A62D8;
extern Battle D_800A62E4;
extern Battle D_800A62F0;
extern Battle D_800A6320;
extern Battle D_800A632C;
extern Battle D_800A6338;
extern Battle D_800A6344;
extern Battle D_800A6350;
extern Battle D_800A635C;
extern Battle D_800A6368;
extern Battle D_800A6374;
extern Battle D_800A63A4;
extern Battle D_800A63B0;
extern Battle D_800A63BC;
extern Battle D_800A63C8;
extern Battle D_800A63D4;
extern Battle D_800A63E0;
extern Battle D_800A63EC;
extern Battle D_800A63F8;
extern Battle D_800A6428;
extern Battle D_800A6434;
extern Battle D_800A6440;
extern Battle D_800A644C;
extern Battle D_800A6458;
extern Battle D_800A6464;
extern Battle D_800A6470;
extern Battle D_800A647C;
extern Battle D_800A64AC;
extern Battle D_800A64B8;
extern Battle D_800A64C4;
extern Battle D_800A64D0;
extern Battle D_800A64DC;
extern Battle D_800A64E8;
extern Battle D_800A64F4;
extern Battle D_800A6500;
extern Battle D_800A6530;
extern Battle D_800A653C;
extern Battle D_800A6548;
extern Battle D_800A6554;
extern Battle D_800A6560;
extern Battle D_800A656C;
extern Battle D_800A6578;
extern Battle D_800A6584;
extern Battle D_800A65B4;
extern Battle D_800A65C0;
extern Battle D_800A65CC;
extern Battle D_800A65D8;
extern Battle D_800A65E4;
extern Battle D_800A65F0;
extern Battle D_800A65FC;
extern Battle D_800A6608;
extern Battle D_800A6638;
extern Battle D_800A6644;
extern Battle D_800A6650;
extern Battle D_800A665C;
extern Battle D_800A6668;
extern Battle D_800A6674;
extern Battle D_800A6680;
extern Battle D_800A668C;
extern Battle D_800A66BC;
extern Battle D_800A66C8;
extern Battle D_800A66D4;
extern Battle D_800A66E0;
extern Battle D_800A66EC;
extern Battle D_800A66F8;
extern Battle D_800A6704;
extern Battle D_800A6710;
extern Battle D_800A6740;
extern Battle D_800A674C;
extern Battle D_800A6758;
extern Battle D_800A6764;
extern Battle D_800A6770;
extern Battle D_800A677C;
extern Battle D_800A6788;
extern Battle D_800A6794;
extern Battle D_800A67C4;
extern Battle D_800A67D0;
extern Battle D_800A67DC;
extern Battle D_800A67E8;
extern Battle D_800A67F4;
extern Battle D_800A6800;
extern Battle D_800A680C;
extern Battle D_800A6818;
extern Battle D_800A6848;
extern Battle D_800A6854;
extern Battle D_800A6860;
extern Battle D_800A686C;
extern Battle D_800A6878;
extern Battle D_800A6884;
extern Battle D_800A6890;
extern Battle D_800A689C;
extern Battle D_800A68CC;
extern Battle D_800A68D8;
extern Battle D_800A68E4;
extern Battle D_800A68F0;
extern Battle D_800A68FC;
extern Battle D_800A6908;
extern Battle D_800A6914;
extern Battle D_800A6920;
extern Battle D_800A6950;
extern Battle D_800A695C;
extern Battle D_800A6968;
extern Battle D_800A6974;
extern Battle D_800A6980;
extern Battle D_800A698C;
extern Battle D_800A6998;
extern Battle D_800A69A4;
extern Battle D_800A69D4;
extern Battle D_800A69E0;
extern Battle D_800A69EC;
extern Battle D_800A69F8;
extern Battle D_800A6A04;
extern Battle D_800A6A10;
extern Battle D_800A6A1C;
extern Battle D_800A6A28;
extern Battle D_800A6A58;
extern Battle D_800A6A64;
extern Battle D_800A6A70;
extern Battle D_800A6A7C;
extern Battle D_800A6A88;
extern Battle D_800A6A94;
extern Battle D_800A6AA0;
extern Battle D_800A6AAC;
extern Battle D_800A6ADC;
extern Battle D_800A6AE8;
extern Battle D_800A6AF4;
extern Battle D_800A6B00;
extern Battle D_800A6B0C;
extern Battle D_800A6B18;
extern Battle D_800A6B24;
extern Battle D_800A6B30;
extern Battle D_800A6B60;
extern Battle D_800A6B6C;
extern Battle D_800A6B78;
extern Battle D_800A6B84;
extern Battle D_800A6B90;
extern Battle D_800A6B9C;
extern Battle D_800A6BA8;
extern Battle D_800A6BB4;
extern Battle D_800A6BE4;
extern Battle D_800A6BF0;
extern Battle D_800A6BFC;
extern Battle D_800A6C08;
extern Battle D_800A6C14;
extern Battle D_800A6C20;
extern Battle D_800A6C2C;
extern Battle D_800A6C38;
extern Battle D_800A6C68;
extern Battle D_800A6C74;
extern Battle D_800A6C80;
extern Battle D_800A6C8C;
extern Battle D_800A6C98;
extern Battle D_800A6CA4;
extern Battle D_800A6CB0;
extern Battle D_800A6CBC;
extern Battle D_800A6CEC;
extern Battle D_800A6CF8;
extern Battle D_800A6D04;
extern Battle D_800A6D10;
extern Battle D_800A6D1C;
extern Battle D_800A6D28;
extern Battle D_800A6D34;
extern Battle D_800A6D40;
extern Battle D_800A6D70;
extern Battle D_800A6D7C;
extern Battle D_800A6D88;
extern Battle D_800A6D94;
extern Battle D_800A6DA0;
extern Battle D_800A6DAC;
extern Battle D_800A6DB8;
extern Battle D_800A6DC4;
extern Battle D_800A6DF4;
extern Battle D_800A6E00;
extern Battle D_800A6E0C;
extern Battle D_800A6E18;
extern Battle D_800A6E24;
extern Battle D_800A6E30;
extern Battle D_800A6E3C;
extern Battle D_800A6E48;
extern Battle D_800A6E78;
extern Battle D_800A6E84;
extern Battle D_800A6E90;
extern Battle D_800A6E9C;
extern Battle D_800A6EA8;
extern Battle D_800A6EB4;
extern Battle D_800A6EC0;
extern Battle D_800A6ECC;
extern Battle D_800A6EFC;
extern Battle D_800A6F08;
extern Battle D_800A6F14;
extern Battle D_800A6F20;
extern Battle D_800A6F2C;
extern Battle D_800A6F38;
extern Battle D_800A6F44;
extern Battle D_800A6F50;
extern Battle D_800A6F80;
extern Battle D_800A6F8C;
extern Battle D_800A6F98;
extern Battle D_800A6FA4;
extern Battle D_800A6FB0;
extern Battle D_800A6FBC;
extern Battle D_800A6FC8;
extern Battle D_800A6FD4;
extern Battle D_800A7004;
extern Battle D_800A7010;
extern Battle D_800A701C;
extern Battle D_800A7028;
extern Battle D_800A7034;
extern Battle D_800A7040;
extern Battle D_800A704C;
extern Battle D_800A7058;
extern Battle D_800A7088;
extern Battle D_800A7094;
extern Battle D_800A70A0;
extern Battle D_800A70AC;
extern Battle D_800A70B8;
extern Battle D_800A70C4;
extern Battle D_800A70D0;
extern Battle D_800A70DC;
extern Battle D_800A710C;
extern Battle D_800A7118;
extern Battle D_800A7124;
extern Battle D_800A7130;
extern Battle D_800A713C;
extern Battle D_800A7148;
extern Battle D_800A7154;
extern Battle D_800A7160;
extern Battle D_800A7190;
extern Battle D_800A719C;
extern Battle D_800A71A8;
extern Battle D_800A71B4;
extern Battle D_800A71C0;
extern Battle D_800A71CC;
extern Battle D_800A71D8;
extern Battle D_800A71E4;
extern Battle D_800A7214;
extern Battle D_800A7220;
extern Battle D_800A722C;
extern Battle D_800A7238;
extern Battle D_800A7244;
extern Battle D_800A7250;
extern Battle D_800A725C;
extern Battle D_800A7268;
extern Battle D_800A7298;
extern Battle D_800A72A4;
extern Battle D_800A72B0;
extern Battle D_800A72BC;
extern Battle D_800A72C8;
extern Battle D_800A72D4;
extern Battle D_800A72E0;
extern Battle D_800A72EC;
extern Battle D_800A731C;
extern Battle D_800A7328;
extern Battle D_800A7334;
extern Battle D_800A7340;
extern Battle D_800A734C;
extern Battle D_800A7358;
extern Battle D_800A7364;
extern Battle D_800A7370;
extern Battle D_800A73A0;
extern Battle D_800A73AC;
extern Battle D_800A73B8;
extern Battle D_800A73C4;
extern Battle D_800A73D0;
extern Battle D_800A73DC;
extern Battle D_800A73E8;
extern Battle D_800A73F4;
extern Battle D_800A7424;
extern Battle D_800A7430;
extern Battle D_800A743C;
extern Battle D_800A7448;
extern Battle D_800A7454;
extern Battle D_800A7460;
extern Battle D_800A746C;
extern Battle D_800A7478;
extern Battle D_800A74A8;
extern Battle D_800A74B4;
extern Battle D_800A74C0;
extern Battle D_800A74CC;
extern Battle D_800A74D8;
extern Battle D_800A74E4;
extern Battle D_800A74F0;
extern Battle D_800A74FC;
extern Battle D_800A752C;
extern Battle D_800A7538;
extern Battle D_800A7544;
extern Battle D_800A7550;
extern Battle D_800A755C;
extern Battle D_800A7568;
extern Battle D_800A7574;
extern Battle D_800A7580;
extern Battle D_800A75B0;
extern Battle D_800A75BC;
extern Battle D_800A75C8;
extern Battle D_800A75D4;
extern Battle D_800A75E0;
extern Battle D_800A75EC;
extern Battle D_800A75F8;
extern Battle D_800A7604;
extern Battle D_800A7634;
extern Battle D_800A7640;
extern Battle D_800A764C;
extern Battle D_800A7658;
extern Battle D_800A7664;
extern Battle D_800A7670;
extern Battle D_800A767C;
extern Battle D_800A7688;
extern Battle D_800A76B8;
extern Battle D_800A76C4;
extern Battle D_800A76D0;
extern Battle D_800A76DC;
extern Battle D_800A76E8;
extern Battle D_800A76F4;
extern Battle D_800A7700;
extern Battle D_800A770C;
extern Battle D_800A773C;
extern Battle D_800A7748;
extern Battle D_800A7754;
extern Battle D_800A7760;
extern Battle D_800A776C;
extern Battle D_800A7778;
extern Battle D_800A7784;
extern Battle D_800A7790;
extern Battle D_800A77C0;
extern Battle D_800A77CC;
extern Battle D_800A77D8;
extern Battle D_800A77E4;
extern Battle D_800A77F0;
extern Battle D_800A77FC;
extern Battle D_800A7808;
extern Battle D_800A7814;
extern Battle D_800A7844;
extern Battle D_800A7850;
extern Battle D_800A785C;
extern Battle D_800A7868;
extern Battle D_800A7874;
extern Battle D_800A7880;
extern Battle D_800A788C;
extern Battle D_800A7898;
extern Battle D_800A78C8;
extern Battle D_800A78D4;
extern Battle D_800A78E0;
extern Battle D_800A78EC;
extern Battle D_800A78F8;
extern Battle D_800A7904;
extern Battle D_800A7910;
extern Battle D_800A791C;
extern Battle D_800A794C;
extern Battle D_800A7958;
extern Battle D_800A7964;
extern Battle D_800A7970;
extern Battle D_800A797C;
extern Battle D_800A7988;
extern Battle D_800A7994;
extern Battle D_800A79A0;
extern Battle D_800A79D0;
extern Battle D_800A79DC;
extern Battle D_800A79E8;
extern Battle D_800A79F4;
extern Battle D_800A7A00;
extern Battle D_800A7A0C;
extern Battle D_800A7A18;
extern Battle D_800A7A24;
extern Battle D_800A7A54;
extern Battle D_800A7A60;
extern Battle D_800A7A6C;
extern Battle D_800A7A78;
extern Battle D_800A7A84;
extern Battle D_800A7A90;
extern Battle D_800A7A9C;
extern Battle D_800A7AA8;
extern Battle D_800A7AD8;
extern Battle D_800A7AE4;
extern Battle D_800A7AF0;
extern Battle D_800A7AFC;
extern Battle D_800A7B08;
extern Battle D_800A7B14;
extern Battle D_800A7B20;
extern Battle D_800A7B2C;
extern Battle D_800A7B5C;
extern Battle D_800A7B68;
extern Battle D_800A7B74;
extern Battle D_800A7B80;
extern Battle D_800A7B8C;
extern Battle D_800A7B98;
extern Battle D_800A7BA4;
extern Battle D_800A7BB0;
extern Battle D_800A7BE0;
extern Battle D_800A7BEC;
extern Battle D_800A7BF8;
extern Battle D_800A7C04;
extern Battle D_800A7C10;
extern Battle D_800A7C1C;
extern Battle D_800A7C28;
extern Battle D_800A7C34;
extern Battle D_800A7C64;
extern Battle D_800A7C70;
extern Battle D_800A7C7C;
extern Battle D_800A7C88;
extern Battle D_800A7C94;
extern Battle D_800A7CA0;
extern Battle D_800A7CAC;
extern Battle D_800A7CB8;
extern Battle D_800A7CE8;
extern Battle D_800A7CF4;
extern Battle D_800A7D00;
extern Battle D_800A7D0C;
extern Battle D_800A7D18;
extern Battle D_800A7D24;
extern Battle D_800A7D30;
extern Battle D_800A7D3C;
extern Battle D_800A7D6C;
extern Battle D_800A7D78;
extern Battle D_800A7D84;
extern Battle D_800A7D90;
extern Battle D_800A7D9C;
extern Battle D_800A7DA8;
extern Battle D_800A7DB4;
extern Battle D_800A7DC0;
extern Battle D_800A7DF0;
extern Battle D_800A7DFC;
extern Battle D_800A7E08;
extern Battle D_800A7E14;
extern Battle D_800A7E20;
extern Battle D_800A7E2C;
extern Battle D_800A7E38;
extern Battle D_800A7E44;
extern Battle D_800A7E74;
extern Battle D_800A7E80;
extern Battle D_800A7E8C;
extern Battle D_800A7E98;
extern Battle D_800A7EA4;
extern Battle D_800A7EB0;
extern Battle D_800A7EBC;
extern Battle D_800A7EC8;
extern Battle D_800A7EF8;
extern Battle D_800A7F04;
extern Battle D_800A7F10;
extern Battle D_800A7F1C;
extern Battle D_800A7F28;
extern Battle D_800A7F34;
extern Battle D_800A7F40;
extern Battle D_800A7F4C;
extern Battle D_800A7F7C;
extern Battle D_800A7F88;
extern Battle D_800A7F94;
extern Battle D_800A7FA0;
extern Battle D_800A7FAC;
extern Battle D_800A7FB8;
extern Battle D_800A7FC4;
extern Battle D_800A7FD0;
extern Battle D_800A8000;
extern Battle D_800A800C;
extern Battle D_800A8018;
extern Battle D_800A8024;
extern Battle D_800A8030;
extern Battle D_800A803C;
extern Battle D_800A8048;
extern Battle D_800A8054;
extern Battle D_800A8084;
extern Battle D_800A8090;
extern Battle D_800A809C;
extern Battle D_800A80A8;
extern Battle D_800A80B4;
extern Battle D_800A80C0;
extern Battle D_800A80CC;
extern Battle D_800A80D8;
extern Battle D_800A8108;
extern Battle D_800A8114;
extern Battle D_800A8120;
extern Battle D_800A812C;
extern Battle D_800A8138;
extern Battle D_800A8144;
extern Battle D_800A8150;
extern Battle D_800A815C;
extern BattleList D_800A548C;
extern BattleList D_800A5510;
extern BattleList D_800A5594;
extern BattleList D_800A5618;
extern BattleList D_800A569C;
extern BattleList D_800A5720;
extern BattleList D_800A57A4;
extern BattleList D_800A5828;
extern BattleList D_800A58AC;
extern BattleList D_800A5930;
extern BattleList D_800A59B4;
extern BattleList D_800A5A38;
extern BattleList D_800A5ABC;
extern BattleList D_800A5B40;
extern BattleList D_800A5BC4;
extern BattleList D_800A5C48;
extern BattleList D_800A5CCC;
extern BattleList D_800A5D50;
extern BattleList D_800A5DD4;
extern BattleList D_800A5E58;
extern BattleList D_800A5EDC;
extern BattleList D_800A5F60;
extern BattleList D_800A5FE4;
extern BattleList D_800A6068;
extern BattleList D_800A60EC;
extern BattleList D_800A6170;
extern BattleList D_800A61F4;
extern BattleList D_800A6278;
extern BattleList D_800A62FC;
extern BattleList D_800A6380;
extern BattleList D_800A6404;
extern BattleList D_800A6488;
extern BattleList D_800A650C;
extern BattleList D_800A6590;
extern BattleList D_800A6614;
extern BattleList D_800A6698;
extern BattleList D_800A671C;
extern BattleList D_800A67A0;
extern BattleList D_800A6824;
extern BattleList D_800A68A8;
extern BattleList D_800A692C;
extern BattleList D_800A69B0;
extern BattleList D_800A6A34;
extern BattleList D_800A6AB8;
extern BattleList D_800A6B3C;
extern BattleList D_800A6BC0;
extern BattleList D_800A6C44;
extern BattleList D_800A6CC8;
extern BattleList D_800A6D4C;
extern BattleList D_800A6DD0;
extern BattleList D_800A6E54;
extern BattleList D_800A6ED8;
extern BattleList D_800A6F5C;
extern BattleList D_800A6FE0;
extern BattleList D_800A7064;
extern BattleList D_800A70E8;
extern BattleList D_800A716C;
extern BattleList D_800A71F0;
extern BattleList D_800A7274;
extern BattleList D_800A72F8;
extern BattleList D_800A737C;
extern BattleList D_800A7400;
extern BattleList D_800A7484;
extern BattleList D_800A7508;
extern BattleList D_800A758C;
extern BattleList D_800A7610;
extern BattleList D_800A7694;
extern BattleList D_800A7718;
extern BattleList D_800A779C;
extern BattleList D_800A7820;
extern BattleList D_800A78A4;
extern BattleList D_800A7928;
extern BattleList D_800A79AC;
extern BattleList D_800A7A30;
extern BattleList D_800A7AB4;
extern BattleList D_800A7B38;
extern BattleList D_800A7BBC;
extern BattleList D_800A7C40;
extern BattleList D_800A7CC4;
extern BattleList D_800A7D48;
extern BattleList D_800A7DCC;
extern BattleList D_800A7E50;
extern BattleList D_800A7ED4;
extern BattleList D_800A7F58;
extern BattleList D_800A7FDC;
extern BattleList D_800A8060;
extern BattleList D_800A80E4;
extern BattleList D_800A8168;
extern u16 D_800A85B4[];
extern u16 D_800A85C0[];
extern u16 D_800A85CC[];
extern u16 D_800A85D8[];
extern u16 D_800A85E4[];
extern u16 D_800A85F0[];
extern u16 D_800A85FC[];
extern u16 D_800A8608[];
extern u16 D_800A8614[];
extern u16 D_800A8620[];
extern u16 D_800A862C[];
extern u16 D_800A8638[];
extern u16 D_800A8644[];
extern u16 D_800A8650[];
extern u16 D_800A865C[];
extern u16 D_800A8668[];
extern u16 D_800A8674[];
extern u16 D_800A8680[];
extern u16 D_800A883C[];
extern FieldTalk D_800A868C[];
extern u16 D_800A884C[];
extern FieldTalk D_800A86A4[];
extern u16 D_800A885C[];
extern FieldTalk D_800A86BC[];
extern u16 D_800A886C[];
extern FieldTalk D_800A86D4[];
extern u16 D_800A887C[];
extern FieldTalk D_800A86EC[];
extern u16 D_800A888C[];
extern FieldTalk D_800A8704[];
extern u16 D_800A889C[];
extern FieldTalk D_800A871C[];
extern u16 D_800A88AC[];
extern FieldTalk D_800A8734[];
extern u16 D_800A88BC[];
extern FieldTalk D_800A874C[];
extern u16 D_800A88CC[];
extern FieldTalk D_800A8764[];
extern u16 D_800A88DC[];
extern FieldTalk D_800A877C[];
extern u16 D_800A88EC[];
extern FieldTalk D_800A8794[];
extern u16 D_800A88FC[];
extern u16 D_800A8908[];
extern u16 D_800A8914[];
extern FieldTalk D_800A87AC[];
extern u16 D_800A8924[];
extern FieldTalk D_800A87C4[];
extern u16 D_800A8934[];
extern FieldTalk D_800A87DC[];
extern u16 D_800A8944[];
extern FieldTalk D_800A87F4[];
extern u16 D_800A8954[];
extern FieldTalk D_800A880C[];
extern u16 D_800A8964[];
extern FieldTalk D_800A8824[];
extern u16 D_800A8974[];
extern u16 D_800A8980[];
extern u16 D_800A898C[];
extern u16 D_800A8998[];
extern u16 D_800A89A4[];
extern u16 D_800A89B0[];
extern u16 D_800A89BC[];
extern u16 D_800A89C8[];
extern u16 D_800A89D4[];
extern u16 D_800A89E0[];
extern u16 D_800A89EC[];
extern u16 D_800A89F8[];
extern u16 D_800A8A04[];
extern u16 D_800A8A10[];
extern u16 D_800A8A1C[];
extern u16 D_800A8A28[];
extern u16 D_800A8A34[];
extern u16 D_800A8A40[];
extern FieldActorEntry D_800A8A4C;
extern FieldActorEntry D_800A8A60;
extern FieldActorEntry D_800A8A74;
extern FieldActorEntry D_800A8A88;
extern FieldActorEntry D_800A8A9C;
extern FieldActorEntry D_800A8AB0;
extern FieldActorEntry D_800A8AC4;
extern FieldActorEntry D_800A8AD8;
extern FieldActorEntry D_800A8AEC;
extern FieldActorEntry D_800A8B00;
extern FieldActorEntry D_800A8B14;
extern FieldActorEntry D_800A8B28;
extern FieldActorEntry D_800A8B3C;
extern FieldActorEntry D_800A8B50;
extern FieldActorEntry D_800A8B64;
extern FieldActorEntry D_800A8B78;
extern FieldActorEntry D_800A8B8C;
extern FieldActorEntry D_800A8BA0;
extern FieldActorEntry D_800A8BB4;
extern FieldActorEntry D_800A8BC8;
extern FieldActorEntry D_800A8BDC;
extern FieldActorEntry D_800A8BF0;
extern FieldActorEntry D_800A8C04;
extern FieldActorEntry D_800A8C18;
extern FieldActorEntry D_800A8C2C;
extern FieldActorEntry D_800A8C40;
extern FieldActorEntry D_800A8C54;
extern FieldActorEntry D_800A8C68;
extern FieldActorEntry D_800A8C7C;
extern FieldActorEntry D_800A8C90;
extern FieldActorEntry D_800A8CA4;
extern FieldActorEntry D_800A8CB8;
extern FieldActorEntry D_800A8CCC;
extern FieldActorEntry D_800A8CE0;
extern FieldActorEntry D_800A8CF4;
extern FieldActorEntry D_800A8D08;
extern FieldActorEntry D_800A8D1C;
extern FieldActorEntry D_800A8D30;
extern FieldActorEntry D_800A8D44;

StagePoint D_800A4F90 = { 0x2ED, 1, 1, 224, 192, 5, NULL };
StagePoints D_800A4FA0 = { 1, 1, &D_800A4F90 };
StagePoint D_800A4FA8 = { 0x2ED, 4, 2, 224, 192, 5, NULL };
StagePoints D_800A4FB8 = { 4, 1, &D_800A4FA8 };
StagePoint D_800A4FC0 = { 0x2EE, 7, 2, 224, 0x240, 5, NULL };
StagePoints D_800A4FD0 = { 7, 1, &D_800A4FC0 };
StagePoint D_800A4FD8 = { 0x2EC, 12, 3, 240, 0x1D8, 5, NULL };
StagePoints D_800A4FE8 = { 12, 1, &D_800A4FD8 };
StagePoint D_800A4FF0 = { 0x2EC, 12, 4, 240, 0x1D8, 5, NULL };
StagePoints D_800A5000 = { 12, 2, &D_800A4FF0 };
StagePoint D_800A5008 = { 0x2EC, 13, 5, 240, 0x1D8, 5, NULL };
StagePoints D_800A5018 = { 13, 1, &D_800A5008 };
StagePoint D_800A5020 = { 0x2EC, 13, 6, 240, 0x1D8, 5, NULL };
StagePoints D_800A5030 = { 13, 2, &D_800A5020 };
StagePoint D_800A5038 = { 0x2ED, 14, 1, 224, 192, 5, NULL };
StagePoints D_800A5048 = { 14, 1, &D_800A5038 };
StagePoint D_800A5050 = { 0x2ED, 14, 2, 0x350, 0x1F8, 5, NULL };
StagePoints D_800A5060 = { 14, 2, &D_800A5050 };
StagePoint D_800A5068 = { 0x2E8, 15, 1, 176, 0x168, 5, NULL };
StagePoints D_800A5078 = { 15, 1, &D_800A5068 };
StagePoint D_800A5080 = { 0x2ED, 16, 1, 224, 192, 5, NULL };
StagePoints D_800A5090 = { 16, 1, &D_800A5080 };
StagePoint D_800A5098 = { 0x2ED, 16, 1, 0x350, 0x1F8, 5, NULL };
StagePoints D_800A50A8 = { 16, 2, &D_800A5098 };
StagePoint D_800A50B0 = { 0x2E8, 17, 1, 176, 0x168, 5, NULL };
StagePoints D_800A50C0 = { 17, 1, &D_800A50B0 };
StagePoint D_800A50C8 = { 0x2EC, 18, 1, 240, 0x1D8, 5, NULL };
StagePoints D_800A50D8 = { 18, 1, &D_800A50C8 };
StagePoint D_800A50E0 = { 0x2ED, 19, 2, 224, 192, 5, NULL };
StagePoints D_800A50F0 = { 19, 1, &D_800A50E0 };
StagePoint D_800A50F8 = { 0x2ED, 19, 2, 0x350, 0x1F8, 5, NULL };
StagePoints D_800A5108 = { 19, 2, &D_800A50F8 };
StagePoint D_800A5110 = { 0x2ED, 19, 3, 224, 192, 5, NULL };
StagePoints D_800A5120 = { 19, 3, &D_800A5110 };
StagePoint D_800A5128 = { 0x2EC, 19, 5, 240, 0x1D8, 5, NULL };
StagePoints D_800A5138 = { 19, 4, &D_800A5128 };
StagePoint D_800A5140 = { 0x2ED, 20, 2, 224, 192, 5, NULL };
StagePoints D_800A5150 = { 20, 1, &D_800A5140 };
StagePoint D_800A5158 = { 0x2ED, 20, 3, 224, 192, 5, NULL };
StagePoints D_800A5168 = { 20, 2, &D_800A5158 };
StagePoint D_800A5170 = { 0x2ED, 20, 4, 224, 192, 5, NULL };
StagePoints D_800A5180 = { 20, 3, &D_800A5170 };
StagePoint D_800A5188 = { 0x2EC, 20, 6, 240, 0x1D8, 5, NULL };
StagePoints D_800A5198 = { 20, 4, &D_800A5188 };
StagePoint D_800A51A0 = { 0x2EC, 20, 8, 240, 0x1D8, 5, NULL };
StagePoints D_800A51B0 = { 20, 5, &D_800A51A0 };
StagePoint D_800A51B8 = { 0x2EC, 20, 9, 240, 0x1D8, 5, NULL };
StagePoints D_800A51C8 = { 20, 6, &D_800A51B8 };
StagePoint D_800A51D0 = { 0x2ED, 20, 6, 0x350, 0x1F8, 5, NULL };
StagePoints D_800A51E0 = { 20, 7, &D_800A51D0 };
StagePoint D_800A51E8 = { 0x2EE, 21, 1, 224, 0x240, 5, NULL };
StagePoints D_800A51F8 = { 21, 1, &D_800A51E8 };
StagePoint D_800A5200 = { 0x2EC, 22, 3, 240, 0x1D8, 5, NULL };
StagePoints D_800A5210 = { 22, 1, &D_800A5200 };
StagePoint D_800A5218 = { 0x2EE, 23, 1, 224, 0x240, 5, NULL };
StagePoints D_800A5228 = { 23, 1, &D_800A5218 };
StagePoint D_800A5230 = { 0x2EC, 24, 5, 240, 0x1D8, 5, NULL };
StagePoints D_800A5240 = { 24, 1, &D_800A5230 };
StagePoint D_800A5248 = { 0x2ED, 25, 1, 224, 192, 5, NULL };
StagePoints D_800A5258 = { 25, 1, &D_800A5248 };
StagePoint D_800A5260 = { 0x2ED, 25, 1, 0x350, 0x1F8, 5, NULL };
StagePoints D_800A5270 = { 25, 2, &D_800A5260 };
StagePoint D_800A5278 = { 0x2E8, 26, 1, 176, 0x168, 5, NULL };
StagePoints D_800A5288 = { 26, 1, &D_800A5278 };
StagePoint D_800A5290 = { 0x2ED, 27, 1, 224, 192, 5, NULL };
StagePoints D_800A52A0 = { 27, 1, &D_800A5290 };
StagePoint D_800A52A8 = { 0x2ED, 27, 2, 0x350, 0x1F8, 5, NULL };
StagePoints D_800A52B8 = { 27, 2, &D_800A52A8 };
StagePoint D_800A52C0 = { 0x2EC, 28, 3, 240, 0x1D8, 5, NULL };
StagePoints D_800A52D0 = { 28, 1, &D_800A52C0 };
StagePoint D_800A52D8 = { 0x2EC, 28, 4, 240, 0x1D8, 5, NULL };
StagePoints D_800A52E8 = { 28, 2, &D_800A52D8 };
StagePoint D_800A52F0 = { 0x2EE, 28, 2, 224, 0x240, 5, NULL };
StagePoints D_800A5300 = { 28, 3, &D_800A52F0 };
StagePoint D_800A5308 = { 0x2ED, 29, 1, 224, 192, 5, NULL };
StagePoints D_800A5318 = { 29, 1, &D_800A5308 };
StagePoint D_800A5320 = { 0x2ED, 29, 2, 224, 192, 5, NULL };
StagePoints D_800A5330 = { 29, 2, &D_800A5320 };
StagePoint D_800A5338 = { 0x2ED, 29, 2, 0x350, 0x1F8, 5, NULL };
StagePoints D_800A5348 = { 29, 3, &D_800A5338 };
StagePoint D_800A5350 = { 0x2EC, 30, 1, 240, 0x1D8, 5, NULL };
StagePoints D_800A5360 = { 30, 1, &D_800A5350 };
StagePoint D_800A5368 = { 0x2EE, 30, 2, 224, 0x240, 5, NULL };
StagePoints D_800A5378 = { 30, 2, &D_800A5368 };
StagePoints *placePoints[] = {
    &D_800A4FA0, &D_800A4FB8, &D_800A4FD0, &D_800A4FE8,
    &D_800A5000, &D_800A5018, &D_800A5030, &D_800A5048,
    &D_800A5060, &D_800A5078, &D_800A5090, &D_800A50A8,
    &D_800A50C0, &D_800A50D8, &D_800A50F0, &D_800A5108,
    &D_800A5120, &D_800A5138, &D_800A5150, &D_800A5168,
    &D_800A5180, &D_800A5198, &D_800A51B0, &D_800A51C8,
    &D_800A51E0, &D_800A51F8, &D_800A5210, &D_800A5228,
    &D_800A5240, &D_800A5258, &D_800A5270, &D_800A5288,
    &D_800A52A0, &D_800A52B8, &D_800A52D0, &D_800A52E8,
    &D_800A5300, &D_800A5318, &D_800A5330, &D_800A5348,
    &D_800A5360, &D_800A5378, NULL,
};
Battle D_800A542C = { 174, 10, 0x60080000 };
Battle D_800A5438 = { 174, 10, 0x60080000 };
Battle D_800A5444 = { 170, 10, 0x60080000 };
Battle D_800A5450 = { 170, 10, 0x60080000 };
Battle D_800A545C = { 170, 10, 0x60080000 };
Battle D_800A5468 = { 170, 10, 0x60080000 };
Battle D_800A5474 = { 170, 10, 0x60080000 };
Battle D_800A5480 = { 170, 10, 0x60080000 };
BattleList D_800A548C = {
    1,
    { &D_800A542C, &D_800A5438, &D_800A5444, &D_800A5450,
      &D_800A545C, &D_800A5468, &D_800A5474, &D_800A5480 },
};
Battle D_800A54B0 = { 0, 0, 0x60040000 };
Battle D_800A54BC = { 0, 0, 0x60040000 };
Battle D_800A54C8 = { 0, 0, 0x60040000 };
Battle D_800A54D4 = { 0, 0, 0x60040000 };
Battle D_800A54E0 = { 0, 0, 0x60040000 };
Battle D_800A54EC = { 0, 0, 0x60040000 };
Battle D_800A54F8 = { 0, 0, 0x60040000 };
Battle D_800A5504 = { 0, 0, 0x60040000 };
BattleList D_800A5510 = {
    0,
    { &D_800A54B0, &D_800A54BC, &D_800A54C8, &D_800A54D4,
      &D_800A54E0, &D_800A54EC, &D_800A54F8, &D_800A5504 },
};
Battle D_800A5534 = { 0, 0, 0x60040000 };
Battle D_800A5540 = { 0, 0, 0x60040000 };
Battle D_800A554C = { 0, 0, 0x60040000 };
Battle D_800A5558 = { 0, 0, 0x60040000 };
Battle D_800A5564 = { 0, 0, 0x60040000 };
Battle D_800A5570 = { 0, 0, 0x60040000 };
Battle D_800A557C = { 0, 0, 0x60040000 };
Battle D_800A5588 = { 0, 0, 0x60040000 };
BattleList D_800A5594 = {
    0,
    { &D_800A5534, &D_800A5540, &D_800A554C, &D_800A5558,
      &D_800A5564, &D_800A5570, &D_800A557C, &D_800A5588 },
};
Battle D_800A55B8 = { 0, 0, 0x60040000 };
Battle D_800A55C4 = { 0, 0, 0x60040000 };
Battle D_800A55D0 = { 0, 0, 0x60040000 };
Battle D_800A55DC = { 0, 0, 0x60040000 };
Battle D_800A55E8 = { 0, 0, 0x60040000 };
Battle D_800A55F4 = { 0, 0, 0x60040000 };
Battle D_800A5600 = { 0, 0, 0x60040000 };
Battle D_800A560C = { 0, 0, 0x60040000 };
BattleList D_800A5618 = {
    0,
    { &D_800A55B8, &D_800A55C4, &D_800A55D0, &D_800A55DC,
      &D_800A55E8, &D_800A55F4, &D_800A5600, &D_800A560C },
};
Battle D_800A563C = { 174, 10, 0x60080000 };
Battle D_800A5648 = { 174, 10, 0x60080000 };
Battle D_800A5654 = { 170, 10, 0x60080000 };
Battle D_800A5660 = { 170, 10, 0x60080000 };
Battle D_800A566C = { 182, 10, 0x60080000 };
Battle D_800A5678 = { 182, 10, 0x60080000 };
Battle D_800A5684 = { 71, 10, 0x60080000 };
Battle D_800A5690 = { 71, 10, 0x60080000 };
BattleList D_800A569C = {
    1,
    { &D_800A563C, &D_800A5648, &D_800A5654, &D_800A5660,
      &D_800A566C, &D_800A5678, &D_800A5684, &D_800A5690 },
};
Battle D_800A56C0 = { 0, 0, 0x60040000 };
Battle D_800A56CC = { 0, 0, 0x60040000 };
Battle D_800A56D8 = { 0, 0, 0x60040000 };
Battle D_800A56E4 = { 0, 0, 0x60040000 };
Battle D_800A56F0 = { 0, 0, 0x60040000 };
Battle D_800A56FC = { 0, 0, 0x60040000 };
Battle D_800A5708 = { 0, 0, 0x60040000 };
Battle D_800A5714 = { 0, 0, 0x60040000 };
BattleList D_800A5720 = {
    0,
    { &D_800A56C0, &D_800A56CC, &D_800A56D8, &D_800A56E4,
      &D_800A56F0, &D_800A56FC, &D_800A5708, &D_800A5714 },
};
Battle D_800A5744 = { 0, 0, 0x60040000 };
Battle D_800A5750 = { 0, 0, 0x60040000 };
Battle D_800A575C = { 0, 0, 0x60040000 };
Battle D_800A5768 = { 0, 0, 0x60040000 };
Battle D_800A5774 = { 0, 0, 0x60040000 };
Battle D_800A5780 = { 0, 0, 0x60040000 };
Battle D_800A578C = { 0, 0, 0x60040000 };
Battle D_800A5798 = { 0, 0, 0x60040000 };
BattleList D_800A57A4 = {
    0,
    { &D_800A5744, &D_800A5750, &D_800A575C, &D_800A5768,
      &D_800A5774, &D_800A5780, &D_800A578C, &D_800A5798 },
};
Battle D_800A57C8 = { 0, 0, 0x60040000 };
Battle D_800A57D4 = { 0, 0, 0x60040000 };
Battle D_800A57E0 = { 0, 0, 0x60040000 };
Battle D_800A57EC = { 0, 0, 0x60040000 };
Battle D_800A57F8 = { 0, 0, 0x60040000 };
Battle D_800A5804 = { 0, 0, 0x60040000 };
Battle D_800A5810 = { 0, 0, 0x60040000 };
Battle D_800A581C = { 0, 0, 0x60040000 };
BattleList D_800A5828 = {
    0,
    { &D_800A57C8, &D_800A57D4, &D_800A57E0, &D_800A57EC,
      &D_800A57F8, &D_800A5804, &D_800A5810, &D_800A581C },
};
Battle D_800A584C = { 110, 10, 0x60080000 };
Battle D_800A5858 = { 110, 10, 0x60080000 };
Battle D_800A5864 = { 110, 10, 0x60080000 };
Battle D_800A5870 = { 110, 10, 0x60080000 };
Battle D_800A587C = { 182, 10, 0x60080000 };
Battle D_800A5888 = { 182, 10, 0x60080000 };
Battle D_800A5894 = { 182, 10, 0x60080000 };
Battle D_800A58A0 = { 182, 10, 0x60080000 };
BattleList D_800A58AC = {
    1,
    { &D_800A584C, &D_800A5858, &D_800A5864, &D_800A5870,
      &D_800A587C, &D_800A5888, &D_800A5894, &D_800A58A0 },
};
Battle D_800A58D0 = { 0, 0, 0x60040000 };
Battle D_800A58DC = { 0, 0, 0x60040000 };
Battle D_800A58E8 = { 0, 0, 0x60040000 };
Battle D_800A58F4 = { 0, 0, 0x60040000 };
Battle D_800A5900 = { 0, 0, 0x60040000 };
Battle D_800A590C = { 0, 0, 0x60040000 };
Battle D_800A5918 = { 0, 0, 0x60040000 };
Battle D_800A5924 = { 0, 0, 0x60040000 };
BattleList D_800A5930 = {
    0,
    { &D_800A58D0, &D_800A58DC, &D_800A58E8, &D_800A58F4,
      &D_800A5900, &D_800A590C, &D_800A5918, &D_800A5924 },
};
Battle D_800A5954 = { 0, 0, 0x60040000 };
Battle D_800A5960 = { 0, 0, 0x60040000 };
Battle D_800A596C = { 0, 0, 0x60040000 };
Battle D_800A5978 = { 0, 0, 0x60040000 };
Battle D_800A5984 = { 0, 0, 0x60040000 };
Battle D_800A5990 = { 0, 0, 0x60040000 };
Battle D_800A599C = { 0, 0, 0x60040000 };
Battle D_800A59A8 = { 0, 0, 0x60040000 };
BattleList D_800A59B4 = {
    0,
    { &D_800A5954, &D_800A5960, &D_800A596C, &D_800A5978,
      &D_800A5984, &D_800A5990, &D_800A599C, &D_800A59A8 },
};
Battle D_800A59D8 = { 0, 0, 0x60040000 };
Battle D_800A59E4 = { 0, 0, 0x60040000 };
Battle D_800A59F0 = { 0, 0, 0x60040000 };
Battle D_800A59FC = { 0, 0, 0x60040000 };
Battle D_800A5A08 = { 0, 0, 0x60040000 };
Battle D_800A5A14 = { 0, 0, 0x60040000 };
Battle D_800A5A20 = { 0, 0, 0x60040000 };
Battle D_800A5A2C = { 0, 0, 0x60040000 };
BattleList D_800A5A38 = {
    0,
    { &D_800A59D8, &D_800A59E4, &D_800A59F0, &D_800A59FC,
      &D_800A5A08, &D_800A5A14, &D_800A5A20, &D_800A5A2C },
};
Battle D_800A5A5C = { 110, 10, 0x60080000 };
Battle D_800A5A68 = { 110, 10, 0x60080000 };
Battle D_800A5A74 = { 110, 10, 0x60080000 };
Battle D_800A5A80 = { 110, 10, 0x60080000 };
Battle D_800A5A8C = { 110, 10, 0x60080000 };
Battle D_800A5A98 = { 110, 10, 0x60080000 };
Battle D_800A5AA4 = { 110, 10, 0x60080000 };
Battle D_800A5AB0 = { 110, 10, 0x60080000 };
BattleList D_800A5ABC = {
    1,
    { &D_800A5A5C, &D_800A5A68, &D_800A5A74, &D_800A5A80,
      &D_800A5A8C, &D_800A5A98, &D_800A5AA4, &D_800A5AB0 },
};
Battle D_800A5AE0 = { 0, 0, 0x60040000 };
Battle D_800A5AEC = { 0, 0, 0x60040000 };
Battle D_800A5AF8 = { 0, 0, 0x60040000 };
Battle D_800A5B04 = { 0, 0, 0x60040000 };
Battle D_800A5B10 = { 0, 0, 0x60040000 };
Battle D_800A5B1C = { 0, 0, 0x60040000 };
Battle D_800A5B28 = { 0, 0, 0x60040000 };
Battle D_800A5B34 = { 0, 0, 0x60040000 };
BattleList D_800A5B40 = {
    0,
    { &D_800A5AE0, &D_800A5AEC, &D_800A5AF8, &D_800A5B04,
      &D_800A5B10, &D_800A5B1C, &D_800A5B28, &D_800A5B34 },
};
Battle D_800A5B64 = { 0, 0, 0x60040000 };
Battle D_800A5B70 = { 0, 0, 0x60040000 };
Battle D_800A5B7C = { 0, 0, 0x60040000 };
Battle D_800A5B88 = { 0, 0, 0x60040000 };
Battle D_800A5B94 = { 0, 0, 0x60040000 };
Battle D_800A5BA0 = { 0, 0, 0x60040000 };
Battle D_800A5BAC = { 0, 0, 0x60040000 };
Battle D_800A5BB8 = { 0, 0, 0x60040000 };
BattleList D_800A5BC4 = {
    0,
    { &D_800A5B64, &D_800A5B70, &D_800A5B7C, &D_800A5B88,
      &D_800A5B94, &D_800A5BA0, &D_800A5BAC, &D_800A5BB8 },
};
Battle D_800A5BE8 = { 0, 0, 0x60040000 };
Battle D_800A5BF4 = { 0, 0, 0x60040000 };
Battle D_800A5C00 = { 0, 0, 0x60040000 };
Battle D_800A5C0C = { 0, 0, 0x60040000 };
Battle D_800A5C18 = { 0, 0, 0x60040000 };
Battle D_800A5C24 = { 0, 0, 0x60040000 };
Battle D_800A5C30 = { 0, 0, 0x60040000 };
Battle D_800A5C3C = { 0, 0, 0x60040000 };
BattleList D_800A5C48 = {
    0,
    { &D_800A5BE8, &D_800A5BF4, &D_800A5C00, &D_800A5C0C,
      &D_800A5C18, &D_800A5C24, &D_800A5C30, &D_800A5C3C },
};
Battle D_800A5C6C = { 182, 10, 0x60080000 };
Battle D_800A5C78 = { 182, 10, 0x60080000 };
Battle D_800A5C84 = { 182, 10, 0x60080000 };
Battle D_800A5C90 = { 182, 10, 0x60080000 };
Battle D_800A5C9C = { 71, 10, 0x60080000 };
Battle D_800A5CA8 = { 71, 10, 0x60080000 };
Battle D_800A5CB4 = { 71, 10, 0x60080000 };
Battle D_800A5CC0 = { 71, 10, 0x60080000 };
BattleList D_800A5CCC = {
    1,
    { &D_800A5C6C, &D_800A5C78, &D_800A5C84, &D_800A5C90,
      &D_800A5C9C, &D_800A5CA8, &D_800A5CB4, &D_800A5CC0 },
};
Battle D_800A5CF0 = { 0, 0, 0x60040000 };
Battle D_800A5CFC = { 0, 0, 0x60040000 };
Battle D_800A5D08 = { 0, 0, 0x60040000 };
Battle D_800A5D14 = { 0, 0, 0x60040000 };
Battle D_800A5D20 = { 0, 0, 0x60040000 };
Battle D_800A5D2C = { 0, 0, 0x60040000 };
Battle D_800A5D38 = { 0, 0, 0x60040000 };
Battle D_800A5D44 = { 0, 0, 0x60040000 };
BattleList D_800A5D50 = {
    0,
    { &D_800A5CF0, &D_800A5CFC, &D_800A5D08, &D_800A5D14,
      &D_800A5D20, &D_800A5D2C, &D_800A5D38, &D_800A5D44 },
};
Battle D_800A5D74 = { 0, 0, 0x60040000 };
Battle D_800A5D80 = { 0, 0, 0x60040000 };
Battle D_800A5D8C = { 0, 0, 0x60040000 };
Battle D_800A5D98 = { 0, 0, 0x60040000 };
Battle D_800A5DA4 = { 0, 0, 0x60040000 };
Battle D_800A5DB0 = { 0, 0, 0x60040000 };
Battle D_800A5DBC = { 0, 0, 0x60040000 };
Battle D_800A5DC8 = { 0, 0, 0x60040000 };
BattleList D_800A5DD4 = {
    0,
    { &D_800A5D74, &D_800A5D80, &D_800A5D8C, &D_800A5D98,
      &D_800A5DA4, &D_800A5DB0, &D_800A5DBC, &D_800A5DC8 },
};
Battle D_800A5DF8 = { 0, 0, 0x60040000 };
Battle D_800A5E04 = { 0, 0, 0x60040000 };
Battle D_800A5E10 = { 0, 0, 0x60040000 };
Battle D_800A5E1C = { 0, 0, 0x60040000 };
Battle D_800A5E28 = { 0, 0, 0x60040000 };
Battle D_800A5E34 = { 0, 0, 0x60040000 };
Battle D_800A5E40 = { 0, 0, 0x60040000 };
Battle D_800A5E4C = { 0, 0, 0x60040000 };
BattleList D_800A5E58 = {
    0,
    { &D_800A5DF8, &D_800A5E04, &D_800A5E10, &D_800A5E1C,
      &D_800A5E28, &D_800A5E34, &D_800A5E40, &D_800A5E4C },
};
Battle D_800A5E7C = { 174, 10, 0x60080000 };
Battle D_800A5E88 = { 174, 10, 0x60080000 };
Battle D_800A5E94 = { 170, 10, 0x60080000 };
Battle D_800A5EA0 = { 170, 10, 0x60080000 };
Battle D_800A5EAC = { 170, 10, 0x60080000 };
Battle D_800A5EB8 = { 170, 10, 0x60080000 };
Battle D_800A5EC4 = { 170, 10, 0x60080000 };
Battle D_800A5ED0 = { 170, 10, 0x60080000 };
BattleList D_800A5EDC = {
    4,
    { &D_800A5E7C, &D_800A5E88, &D_800A5E94, &D_800A5EA0,
      &D_800A5EAC, &D_800A5EB8, &D_800A5EC4, &D_800A5ED0 },
};
Battle D_800A5F00 = { 0, 0, 0x60040000 };
Battle D_800A5F0C = { 0, 0, 0x60040000 };
Battle D_800A5F18 = { 0, 0, 0x60040000 };
Battle D_800A5F24 = { 0, 0, 0x60040000 };
Battle D_800A5F30 = { 0, 0, 0x60040000 };
Battle D_800A5F3C = { 0, 0, 0x60040000 };
Battle D_800A5F48 = { 0, 0, 0x60040000 };
Battle D_800A5F54 = { 0, 0, 0x60040000 };
BattleList D_800A5F60 = {
    0,
    { &D_800A5F00, &D_800A5F0C, &D_800A5F18, &D_800A5F24,
      &D_800A5F30, &D_800A5F3C, &D_800A5F48, &D_800A5F54 },
};
Battle D_800A5F84 = { 0, 0, 0x60040000 };
Battle D_800A5F90 = { 0, 0, 0x60040000 };
Battle D_800A5F9C = { 0, 0, 0x60040000 };
Battle D_800A5FA8 = { 0, 0, 0x60040000 };
Battle D_800A5FB4 = { 0, 0, 0x60040000 };
Battle D_800A5FC0 = { 0, 0, 0x60040000 };
Battle D_800A5FCC = { 0, 0, 0x60040000 };
Battle D_800A5FD8 = { 0, 0, 0x60040000 };
BattleList D_800A5FE4 = {
    0,
    { &D_800A5F84, &D_800A5F90, &D_800A5F9C, &D_800A5FA8,
      &D_800A5FB4, &D_800A5FC0, &D_800A5FCC, &D_800A5FD8 },
};
Battle D_800A6008 = { 0, 0, 0x60040000 };
Battle D_800A6014 = { 0, 0, 0x60040000 };
Battle D_800A6020 = { 0, 0, 0x60040000 };
Battle D_800A602C = { 0, 0, 0x60040000 };
Battle D_800A6038 = { 0, 0, 0x60040000 };
Battle D_800A6044 = { 0, 0, 0x60040000 };
Battle D_800A6050 = { 0, 0, 0x60040000 };
Battle D_800A605C = { 0, 0, 0x60040000 };
BattleList D_800A6068 = {
    0,
    { &D_800A6008, &D_800A6014, &D_800A6020, &D_800A602C,
      &D_800A6038, &D_800A6044, &D_800A6050, &D_800A605C },
};
Battle D_800A608C = { 174, 10, 0x60080000 };
Battle D_800A6098 = { 174, 10, 0x60080000 };
Battle D_800A60A4 = { 170, 10, 0x60080000 };
Battle D_800A60B0 = { 170, 10, 0x60080000 };
Battle D_800A60BC = { 170, 10, 0x60080000 };
Battle D_800A60C8 = { 170, 10, 0x60080000 };
Battle D_800A60D4 = { 170, 10, 0x60080000 };
Battle D_800A60E0 = { 170, 10, 0x60080000 };
BattleList D_800A60EC = {
    5,
    { &D_800A608C, &D_800A6098, &D_800A60A4, &D_800A60B0,
      &D_800A60BC, &D_800A60C8, &D_800A60D4, &D_800A60E0 },
};
Battle D_800A6110 = { 0, 0, 0x60040000 };
Battle D_800A611C = { 0, 0, 0x60040000 };
Battle D_800A6128 = { 0, 0, 0x60040000 };
Battle D_800A6134 = { 0, 0, 0x60040000 };
Battle D_800A6140 = { 0, 0, 0x60040000 };
Battle D_800A614C = { 0, 0, 0x60040000 };
Battle D_800A6158 = { 0, 0, 0x60040000 };
Battle D_800A6164 = { 0, 0, 0x60040000 };
BattleList D_800A6170 = {
    0,
    { &D_800A6110, &D_800A611C, &D_800A6128, &D_800A6134,
      &D_800A6140, &D_800A614C, &D_800A6158, &D_800A6164 },
};
Battle D_800A6194 = { 0, 0, 0x60040000 };
Battle D_800A61A0 = { 0, 0, 0x60040000 };
Battle D_800A61AC = { 0, 0, 0x60040000 };
Battle D_800A61B8 = { 0, 0, 0x60040000 };
Battle D_800A61C4 = { 0, 0, 0x60040000 };
Battle D_800A61D0 = { 0, 0, 0x60040000 };
Battle D_800A61DC = { 0, 0, 0x60040000 };
Battle D_800A61E8 = { 0, 0, 0x60040000 };
BattleList D_800A61F4 = {
    0,
    { &D_800A6194, &D_800A61A0, &D_800A61AC, &D_800A61B8,
      &D_800A61C4, &D_800A61D0, &D_800A61DC, &D_800A61E8 },
};
Battle D_800A6218 = { 0, 0, 0x60040000 };
Battle D_800A6224 = { 0, 0, 0x60040000 };
Battle D_800A6230 = { 0, 0, 0x60040000 };
Battle D_800A623C = { 0, 0, 0x60040000 };
Battle D_800A6248 = { 0, 0, 0x60040000 };
Battle D_800A6254 = { 0, 0, 0x60040000 };
Battle D_800A6260 = { 0, 0, 0x60040000 };
Battle D_800A626C = { 0, 0, 0x60040000 };
BattleList D_800A6278 = {
    0,
    { &D_800A6218, &D_800A6224, &D_800A6230, &D_800A623C,
      &D_800A6248, &D_800A6254, &D_800A6260, &D_800A626C },
};
Battle D_800A629C = { 174, 10, 0x60080000 };
Battle D_800A62A8 = { 174, 10, 0x60080000 };
Battle D_800A62B4 = { 170, 10, 0x60080000 };
Battle D_800A62C0 = { 170, 10, 0x60080000 };
Battle D_800A62CC = { 170, 10, 0x60080000 };
Battle D_800A62D8 = { 170, 10, 0x60080000 };
Battle D_800A62E4 = { 170, 10, 0x60080000 };
Battle D_800A62F0 = { 170, 10, 0x60080000 };
BattleList D_800A62FC = {
    4,
    { &D_800A629C, &D_800A62A8, &D_800A62B4, &D_800A62C0,
      &D_800A62CC, &D_800A62D8, &D_800A62E4, &D_800A62F0 },
};
Battle D_800A6320 = { 0, 0, 0x60040000 };
Battle D_800A632C = { 0, 0, 0x60040000 };
Battle D_800A6338 = { 0, 0, 0x60040000 };
Battle D_800A6344 = { 0, 0, 0x60040000 };
Battle D_800A6350 = { 0, 0, 0x60040000 };
Battle D_800A635C = { 0, 0, 0x60040000 };
Battle D_800A6368 = { 0, 0, 0x60040000 };
Battle D_800A6374 = { 0, 0, 0x60040000 };
BattleList D_800A6380 = {
    0,
    { &D_800A6320, &D_800A632C, &D_800A6338, &D_800A6344,
      &D_800A6350, &D_800A635C, &D_800A6368, &D_800A6374 },
};
Battle D_800A63A4 = { 0, 0, 0x60040000 };
Battle D_800A63B0 = { 0, 0, 0x60040000 };
Battle D_800A63BC = { 0, 0, 0x60040000 };
Battle D_800A63C8 = { 0, 0, 0x60040000 };
Battle D_800A63D4 = { 0, 0, 0x60040000 };
Battle D_800A63E0 = { 0, 0, 0x60040000 };
Battle D_800A63EC = { 0, 0, 0x60040000 };
Battle D_800A63F8 = { 0, 0, 0x60040000 };
BattleList D_800A6404 = {
    0,
    { &D_800A63A4, &D_800A63B0, &D_800A63BC, &D_800A63C8,
      &D_800A63D4, &D_800A63E0, &D_800A63EC, &D_800A63F8 },
};
Battle D_800A6428 = { 0, 0, 0x60040000 };
Battle D_800A6434 = { 0, 0, 0x60040000 };
Battle D_800A6440 = { 0, 0, 0x60040000 };
Battle D_800A644C = { 0, 0, 0x60040000 };
Battle D_800A6458 = { 0, 0, 0x60040000 };
Battle D_800A6464 = { 0, 0, 0x60040000 };
Battle D_800A6470 = { 0, 0, 0x60040000 };
Battle D_800A647C = { 0, 0, 0x60040000 };
BattleList D_800A6488 = {
    0,
    { &D_800A6428, &D_800A6434, &D_800A6440, &D_800A644C,
      &D_800A6458, &D_800A6464, &D_800A6470, &D_800A647C },
};
Battle D_800A64AC = { 174, 10, 0x60080000 };
Battle D_800A64B8 = { 174, 10, 0x60080000 };
Battle D_800A64C4 = { 170, 10, 0x60080000 };
Battle D_800A64D0 = { 170, 10, 0x60080000 };
Battle D_800A64DC = { 170, 10, 0x60080000 };
Battle D_800A64E8 = { 170, 10, 0x60080000 };
Battle D_800A64F4 = { 170, 10, 0x60080000 };
Battle D_800A6500 = { 170, 10, 0x60080000 };
BattleList D_800A650C = {
    5,
    { &D_800A64AC, &D_800A64B8, &D_800A64C4, &D_800A64D0,
      &D_800A64DC, &D_800A64E8, &D_800A64F4, &D_800A6500 },
};
Battle D_800A6530 = { 0, 0, 0x60040000 };
Battle D_800A653C = { 0, 0, 0x60040000 };
Battle D_800A6548 = { 0, 0, 0x60040000 };
Battle D_800A6554 = { 0, 0, 0x60040000 };
Battle D_800A6560 = { 0, 0, 0x60040000 };
Battle D_800A656C = { 0, 0, 0x60040000 };
Battle D_800A6578 = { 0, 0, 0x60040000 };
Battle D_800A6584 = { 0, 0, 0x60040000 };
BattleList D_800A6590 = {
    0,
    { &D_800A6530, &D_800A653C, &D_800A6548, &D_800A6554,
      &D_800A6560, &D_800A656C, &D_800A6578, &D_800A6584 },
};
Battle D_800A65B4 = { 0, 0, 0x60040000 };
Battle D_800A65C0 = { 0, 0, 0x60040000 };
Battle D_800A65CC = { 0, 0, 0x60040000 };
Battle D_800A65D8 = { 0, 0, 0x60040000 };
Battle D_800A65E4 = { 0, 0, 0x60040000 };
Battle D_800A65F0 = { 0, 0, 0x60040000 };
Battle D_800A65FC = { 0, 0, 0x60040000 };
Battle D_800A6608 = { 0, 0, 0x60040000 };
BattleList D_800A6614 = {
    0,
    { &D_800A65B4, &D_800A65C0, &D_800A65CC, &D_800A65D8,
      &D_800A65E4, &D_800A65F0, &D_800A65FC, &D_800A6608 },
};
Battle D_800A6638 = { 0, 0, 0x60040000 };
Battle D_800A6644 = { 0, 0, 0x60040000 };
Battle D_800A6650 = { 0, 0, 0x60040000 };
Battle D_800A665C = { 0, 0, 0x60040000 };
Battle D_800A6668 = { 0, 0, 0x60040000 };
Battle D_800A6674 = { 0, 0, 0x60040000 };
Battle D_800A6680 = { 0, 0, 0x60040000 };
Battle D_800A668C = { 0, 0, 0x60040000 };
BattleList D_800A6698 = {
    0,
    { &D_800A6638, &D_800A6644, &D_800A6650, &D_800A665C,
      &D_800A6668, &D_800A6674, &D_800A6680, &D_800A668C },
};
Battle D_800A66BC = { 182, 10, 0x60080000 };
Battle D_800A66C8 = { 182, 10, 0x60080000 };
Battle D_800A66D4 = { 182, 10, 0x60080000 };
Battle D_800A66E0 = { 182, 10, 0x60080000 };
Battle D_800A66EC = { 71, 10, 0x60080000 };
Battle D_800A66F8 = { 71, 10, 0x60080000 };
Battle D_800A6704 = { 71, 10, 0x60080000 };
Battle D_800A6710 = { 71, 10, 0x60080000 };
BattleList D_800A671C = {
    5,
    { &D_800A66BC, &D_800A66C8, &D_800A66D4, &D_800A66E0,
      &D_800A66EC, &D_800A66F8, &D_800A6704, &D_800A6710 },
};
Battle D_800A6740 = { 0, 0, 0x60040000 };
Battle D_800A674C = { 0, 0, 0x60040000 };
Battle D_800A6758 = { 0, 0, 0x60040000 };
Battle D_800A6764 = { 0, 0, 0x60040000 };
Battle D_800A6770 = { 0, 0, 0x60040000 };
Battle D_800A677C = { 0, 0, 0x60040000 };
Battle D_800A6788 = { 0, 0, 0x60040000 };
Battle D_800A6794 = { 0, 0, 0x60040000 };
BattleList D_800A67A0 = {
    0,
    { &D_800A6740, &D_800A674C, &D_800A6758, &D_800A6764,
      &D_800A6770, &D_800A677C, &D_800A6788, &D_800A6794 },
};
Battle D_800A67C4 = { 0, 0, 0x60040000 };
Battle D_800A67D0 = { 0, 0, 0x60040000 };
Battle D_800A67DC = { 0, 0, 0x60040000 };
Battle D_800A67E8 = { 0, 0, 0x60040000 };
Battle D_800A67F4 = { 0, 0, 0x60040000 };
Battle D_800A6800 = { 0, 0, 0x60040000 };
Battle D_800A680C = { 0, 0, 0x60040000 };
Battle D_800A6818 = { 0, 0, 0x60040000 };
BattleList D_800A6824 = {
    0,
    { &D_800A67C4, &D_800A67D0, &D_800A67DC, &D_800A67E8,
      &D_800A67F4, &D_800A6800, &D_800A680C, &D_800A6818 },
};
Battle D_800A6848 = { 0, 0, 0x60040000 };
Battle D_800A6854 = { 0, 0, 0x60040000 };
Battle D_800A6860 = { 0, 0, 0x60040000 };
Battle D_800A686C = { 0, 0, 0x60040000 };
Battle D_800A6878 = { 0, 0, 0x60040000 };
Battle D_800A6884 = { 0, 0, 0x60040000 };
Battle D_800A6890 = { 0, 0, 0x60040000 };
Battle D_800A689C = { 0, 0, 0x60040000 };
BattleList D_800A68A8 = {
    0,
    { &D_800A6848, &D_800A6854, &D_800A6860, &D_800A686C,
      &D_800A6878, &D_800A6884, &D_800A6890, &D_800A689C },
};
Battle D_800A68CC = { 110, 10, 0x60080000 };
Battle D_800A68D8 = { 110, 10, 0x60080000 };
Battle D_800A68E4 = { 110, 10, 0x60080000 };
Battle D_800A68F0 = { 110, 10, 0x60080000 };
Battle D_800A68FC = { 110, 10, 0x60080000 };
Battle D_800A6908 = { 110, 10, 0x60080000 };
Battle D_800A6914 = { 110, 10, 0x60080000 };
Battle D_800A6920 = { 110, 10, 0x60080000 };
BattleList D_800A692C = {
    1,
    { &D_800A68CC, &D_800A68D8, &D_800A68E4, &D_800A68F0,
      &D_800A68FC, &D_800A6908, &D_800A6914, &D_800A6920 },
};
Battle D_800A6950 = { 0, 0, 0x60040000 };
Battle D_800A695C = { 0, 0, 0x60040000 };
Battle D_800A6968 = { 0, 0, 0x60040000 };
Battle D_800A6974 = { 0, 0, 0x60040000 };
Battle D_800A6980 = { 0, 0, 0x60040000 };
Battle D_800A698C = { 0, 0, 0x60040000 };
Battle D_800A6998 = { 0, 0, 0x60040000 };
Battle D_800A69A4 = { 0, 0, 0x60040000 };
BattleList D_800A69B0 = {
    0,
    { &D_800A6950, &D_800A695C, &D_800A6968, &D_800A6974,
      &D_800A6980, &D_800A698C, &D_800A6998, &D_800A69A4 },
};
Battle D_800A69D4 = { 0, 0, 0x60040000 };
Battle D_800A69E0 = { 0, 0, 0x60040000 };
Battle D_800A69EC = { 0, 0, 0x60040000 };
Battle D_800A69F8 = { 0, 0, 0x60040000 };
Battle D_800A6A04 = { 0, 0, 0x60040000 };
Battle D_800A6A10 = { 0, 0, 0x60040000 };
Battle D_800A6A1C = { 0, 0, 0x60040000 };
Battle D_800A6A28 = { 0, 0, 0x60040000 };
BattleList D_800A6A34 = {
    0,
    { &D_800A69D4, &D_800A69E0, &D_800A69EC, &D_800A69F8,
      &D_800A6A04, &D_800A6A10, &D_800A6A1C, &D_800A6A28 },
};
Battle D_800A6A58 = { 0, 0, 0x60040000 };
Battle D_800A6A64 = { 0, 0, 0x60040000 };
Battle D_800A6A70 = { 0, 0, 0x60040000 };
Battle D_800A6A7C = { 0, 0, 0x60040000 };
Battle D_800A6A88 = { 0, 0, 0x60040000 };
Battle D_800A6A94 = { 0, 0, 0x60040000 };
Battle D_800A6AA0 = { 0, 0, 0x60040000 };
Battle D_800A6AAC = { 0, 0, 0x60040000 };
BattleList D_800A6AB8 = {
    0,
    { &D_800A6A58, &D_800A6A64, &D_800A6A70, &D_800A6A7C,
      &D_800A6A88, &D_800A6A94, &D_800A6AA0, &D_800A6AAC },
};
Battle D_800A6ADC = { 182, 10, 0x60080000 };
Battle D_800A6AE8 = { 182, 10, 0x60080000 };
Battle D_800A6AF4 = { 182, 10, 0x60080000 };
Battle D_800A6B00 = { 182, 10, 0x60080000 };
Battle D_800A6B0C = { 71, 10, 0x60080000 };
Battle D_800A6B18 = { 71, 10, 0x60080000 };
Battle D_800A6B24 = { 71, 10, 0x60080000 };
Battle D_800A6B30 = { 71, 10, 0x60080000 };
BattleList D_800A6B3C = {
    1,
    { &D_800A6ADC, &D_800A6AE8, &D_800A6AF4, &D_800A6B00,
      &D_800A6B0C, &D_800A6B18, &D_800A6B24, &D_800A6B30 },
};
Battle D_800A6B60 = { 0, 0, 0x60040000 };
Battle D_800A6B6C = { 0, 0, 0x60040000 };
Battle D_800A6B78 = { 0, 0, 0x60040000 };
Battle D_800A6B84 = { 0, 0, 0x60040000 };
Battle D_800A6B90 = { 0, 0, 0x60040000 };
Battle D_800A6B9C = { 0, 0, 0x60040000 };
Battle D_800A6BA8 = { 0, 0, 0x60040000 };
Battle D_800A6BB4 = { 0, 0, 0x60040000 };
BattleList D_800A6BC0 = {
    0,
    { &D_800A6B60, &D_800A6B6C, &D_800A6B78, &D_800A6B84,
      &D_800A6B90, &D_800A6B9C, &D_800A6BA8, &D_800A6BB4 },
};
Battle D_800A6BE4 = { 0, 0, 0x60040000 };
Battle D_800A6BF0 = { 0, 0, 0x60040000 };
Battle D_800A6BFC = { 0, 0, 0x60040000 };
Battle D_800A6C08 = { 0, 0, 0x60040000 };
Battle D_800A6C14 = { 0, 0, 0x60040000 };
Battle D_800A6C20 = { 0, 0, 0x60040000 };
Battle D_800A6C2C = { 0, 0, 0x60040000 };
Battle D_800A6C38 = { 0, 0, 0x60040000 };
BattleList D_800A6C44 = {
    0,
    { &D_800A6BE4, &D_800A6BF0, &D_800A6BFC, &D_800A6C08,
      &D_800A6C14, &D_800A6C20, &D_800A6C2C, &D_800A6C38 },
};
Battle D_800A6C68 = { 0, 0, 0x60040000 };
Battle D_800A6C74 = { 0, 0, 0x60040000 };
Battle D_800A6C80 = { 0, 0, 0x60040000 };
Battle D_800A6C8C = { 0, 0, 0x60040000 };
Battle D_800A6C98 = { 0, 0, 0x60040000 };
Battle D_800A6CA4 = { 0, 0, 0x60040000 };
Battle D_800A6CB0 = { 0, 0, 0x60040000 };
Battle D_800A6CBC = { 0, 0, 0x60040000 };
BattleList D_800A6CC8 = {
    0,
    { &D_800A6C68, &D_800A6C74, &D_800A6C80, &D_800A6C8C,
      &D_800A6C98, &D_800A6CA4, &D_800A6CB0, &D_800A6CBC },
};
Battle D_800A6CEC = { 110, 10, 0x60080000 };
Battle D_800A6CF8 = { 110, 10, 0x60080000 };
Battle D_800A6D04 = { 110, 10, 0x60080000 };
Battle D_800A6D10 = { 110, 10, 0x60080000 };
Battle D_800A6D1C = { 110, 10, 0x60080000 };
Battle D_800A6D28 = { 110, 10, 0x60080000 };
Battle D_800A6D34 = { 110, 10, 0x60080000 };
Battle D_800A6D40 = { 110, 10, 0x60080000 };
BattleList D_800A6D4C = {
    3,
    { &D_800A6CEC, &D_800A6CF8, &D_800A6D04, &D_800A6D10,
      &D_800A6D1C, &D_800A6D28, &D_800A6D34, &D_800A6D40 },
};
Battle D_800A6D70 = { 0, 0, 0x60040000 };
Battle D_800A6D7C = { 0, 0, 0x60040000 };
Battle D_800A6D88 = { 0, 0, 0x60040000 };
Battle D_800A6D94 = { 0, 0, 0x60040000 };
Battle D_800A6DA0 = { 0, 0, 0x60040000 };
Battle D_800A6DAC = { 0, 0, 0x60040000 };
Battle D_800A6DB8 = { 0, 0, 0x60040000 };
Battle D_800A6DC4 = { 0, 0, 0x60040000 };
BattleList D_800A6DD0 = {
    0,
    { &D_800A6D70, &D_800A6D7C, &D_800A6D88, &D_800A6D94,
      &D_800A6DA0, &D_800A6DAC, &D_800A6DB8, &D_800A6DC4 },
};
Battle D_800A6DF4 = { 0, 0, 0x60040000 };
Battle D_800A6E00 = { 0, 0, 0x60040000 };
Battle D_800A6E0C = { 0, 0, 0x60040000 };
Battle D_800A6E18 = { 0, 0, 0x60040000 };
Battle D_800A6E24 = { 0, 0, 0x60040000 };
Battle D_800A6E30 = { 0, 0, 0x60040000 };
Battle D_800A6E3C = { 0, 0, 0x60040000 };
Battle D_800A6E48 = { 0, 0, 0x60040000 };
BattleList D_800A6E54 = {
    0,
    { &D_800A6DF4, &D_800A6E00, &D_800A6E0C, &D_800A6E18,
      &D_800A6E24, &D_800A6E30, &D_800A6E3C, &D_800A6E48 },
};
Battle D_800A6E78 = { 0, 0, 0x60040000 };
Battle D_800A6E84 = { 0, 0, 0x60040000 };
Battle D_800A6E90 = { 0, 0, 0x60040000 };
Battle D_800A6E9C = { 0, 0, 0x60040000 };
Battle D_800A6EA8 = { 0, 0, 0x60040000 };
Battle D_800A6EB4 = { 0, 0, 0x60040000 };
Battle D_800A6EC0 = { 0, 0, 0x60040000 };
Battle D_800A6ECC = { 0, 0, 0x60040000 };
BattleList D_800A6ED8 = {
    0,
    { &D_800A6E78, &D_800A6E84, &D_800A6E90, &D_800A6E9C,
      &D_800A6EA8, &D_800A6EB4, &D_800A6EC0, &D_800A6ECC },
};
Battle D_800A6EFC = { 110, 10, 0x60080000 };
Battle D_800A6F08 = { 110, 10, 0x60080000 };
Battle D_800A6F14 = { 110, 10, 0x60080000 };
Battle D_800A6F20 = { 110, 10, 0x60080000 };
Battle D_800A6F2C = { 110, 10, 0x60080000 };
Battle D_800A6F38 = { 110, 10, 0x60080000 };
Battle D_800A6F44 = { 110, 10, 0x60080000 };
Battle D_800A6F50 = { 110, 10, 0x60080000 };
BattleList D_800A6F5C = {
    3,
    { &D_800A6EFC, &D_800A6F08, &D_800A6F14, &D_800A6F20,
      &D_800A6F2C, &D_800A6F38, &D_800A6F44, &D_800A6F50 },
};
Battle D_800A6F80 = { 0, 0, 0x60040000 };
Battle D_800A6F8C = { 0, 0, 0x60040000 };
Battle D_800A6F98 = { 0, 0, 0x60040000 };
Battle D_800A6FA4 = { 0, 0, 0x60040000 };
Battle D_800A6FB0 = { 0, 0, 0x60040000 };
Battle D_800A6FBC = { 0, 0, 0x60040000 };
Battle D_800A6FC8 = { 0, 0, 0x60040000 };
Battle D_800A6FD4 = { 0, 0, 0x60040000 };
BattleList D_800A6FE0 = {
    0,
    { &D_800A6F80, &D_800A6F8C, &D_800A6F98, &D_800A6FA4,
      &D_800A6FB0, &D_800A6FBC, &D_800A6FC8, &D_800A6FD4 },
};
Battle D_800A7004 = { 0, 0, 0x60040000 };
Battle D_800A7010 = { 0, 0, 0x60040000 };
Battle D_800A701C = { 0, 0, 0x60040000 };
Battle D_800A7028 = { 0, 0, 0x60040000 };
Battle D_800A7034 = { 0, 0, 0x60040000 };
Battle D_800A7040 = { 0, 0, 0x60040000 };
Battle D_800A704C = { 0, 0, 0x60040000 };
Battle D_800A7058 = { 0, 0, 0x60040000 };
BattleList D_800A7064 = {
    0,
    { &D_800A7004, &D_800A7010, &D_800A701C, &D_800A7028,
      &D_800A7034, &D_800A7040, &D_800A704C, &D_800A7058 },
};
Battle D_800A7088 = { 0, 0, 0x60040000 };
Battle D_800A7094 = { 0, 0, 0x60040000 };
Battle D_800A70A0 = { 0, 0, 0x60040000 };
Battle D_800A70AC = { 0, 0, 0x60040000 };
Battle D_800A70B8 = { 0, 0, 0x60040000 };
Battle D_800A70C4 = { 0, 0, 0x60040000 };
Battle D_800A70D0 = { 0, 0, 0x60040000 };
Battle D_800A70DC = { 0, 0, 0x60040000 };
BattleList D_800A70E8 = {
    0,
    { &D_800A7088, &D_800A7094, &D_800A70A0, &D_800A70AC,
      &D_800A70B8, &D_800A70C4, &D_800A70D0, &D_800A70DC },
};
Battle D_800A710C = { 182, 10, 0x60080000 };
Battle D_800A7118 = { 182, 10, 0x60080000 };
Battle D_800A7124 = { 182, 10, 0x60080000 };
Battle D_800A7130 = { 182, 10, 0x60080000 };
Battle D_800A713C = { 71, 10, 0x60080000 };
Battle D_800A7148 = { 71, 10, 0x60080000 };
Battle D_800A7154 = { 71, 10, 0x60080000 };
Battle D_800A7160 = { 71, 10, 0x60080000 };
BattleList D_800A716C = {
    2,
    { &D_800A710C, &D_800A7118, &D_800A7124, &D_800A7130,
      &D_800A713C, &D_800A7148, &D_800A7154, &D_800A7160 },
};
Battle D_800A7190 = { 0, 0, 0x60040000 };
Battle D_800A719C = { 0, 0, 0x60040000 };
Battle D_800A71A8 = { 0, 0, 0x60040000 };
Battle D_800A71B4 = { 0, 0, 0x60040000 };
Battle D_800A71C0 = { 0, 0, 0x60040000 };
Battle D_800A71CC = { 0, 0, 0x60040000 };
Battle D_800A71D8 = { 0, 0, 0x60040000 };
Battle D_800A71E4 = { 0, 0, 0x60040000 };
BattleList D_800A71F0 = {
    0,
    { &D_800A7190, &D_800A719C, &D_800A71A8, &D_800A71B4,
      &D_800A71C0, &D_800A71CC, &D_800A71D8, &D_800A71E4 },
};
Battle D_800A7214 = { 0, 0, 0x60040000 };
Battle D_800A7220 = { 0, 0, 0x60040000 };
Battle D_800A722C = { 0, 0, 0x60040000 };
Battle D_800A7238 = { 0, 0, 0x60040000 };
Battle D_800A7244 = { 0, 0, 0x60040000 };
Battle D_800A7250 = { 0, 0, 0x60040000 };
Battle D_800A725C = { 0, 0, 0x60040000 };
Battle D_800A7268 = { 0, 0, 0x60040000 };
BattleList D_800A7274 = {
    0,
    { &D_800A7214, &D_800A7220, &D_800A722C, &D_800A7238,
      &D_800A7244, &D_800A7250, &D_800A725C, &D_800A7268 },
};
Battle D_800A7298 = { 0, 0, 0x60040000 };
Battle D_800A72A4 = { 0, 0, 0x60040000 };
Battle D_800A72B0 = { 0, 0, 0x60040000 };
Battle D_800A72BC = { 0, 0, 0x60040000 };
Battle D_800A72C8 = { 0, 0, 0x60040000 };
Battle D_800A72D4 = { 0, 0, 0x60040000 };
Battle D_800A72E0 = { 0, 0, 0x60040000 };
Battle D_800A72EC = { 0, 0, 0x60040000 };
BattleList D_800A72F8 = {
    0,
    { &D_800A7298, &D_800A72A4, &D_800A72B0, &D_800A72BC,
      &D_800A72C8, &D_800A72D4, &D_800A72E0, &D_800A72EC },
};
Battle D_800A731C = { 182, 10, 0x60080000 };
Battle D_800A7328 = { 182, 10, 0x60080000 };
Battle D_800A7334 = { 182, 10, 0x60080000 };
Battle D_800A7340 = { 182, 10, 0x60080000 };
Battle D_800A734C = { 71, 10, 0x60080000 };
Battle D_800A7358 = { 71, 10, 0x60080000 };
Battle D_800A7364 = { 71, 10, 0x60080000 };
Battle D_800A7370 = { 71, 10, 0x60080000 };
BattleList D_800A737C = {
    5,
    { &D_800A731C, &D_800A7328, &D_800A7334, &D_800A7340,
      &D_800A734C, &D_800A7358, &D_800A7364, &D_800A7370 },
};
Battle D_800A73A0 = { 0, 0, 0x60040000 };
Battle D_800A73AC = { 0, 0, 0x60040000 };
Battle D_800A73B8 = { 0, 0, 0x60040000 };
Battle D_800A73C4 = { 0, 0, 0x60040000 };
Battle D_800A73D0 = { 0, 0, 0x60040000 };
Battle D_800A73DC = { 0, 0, 0x60040000 };
Battle D_800A73E8 = { 0, 0, 0x60040000 };
Battle D_800A73F4 = { 0, 0, 0x60040000 };
BattleList D_800A7400 = {
    0,
    { &D_800A73A0, &D_800A73AC, &D_800A73B8, &D_800A73C4,
      &D_800A73D0, &D_800A73DC, &D_800A73E8, &D_800A73F4 },
};
Battle D_800A7424 = { 0, 0, 0x60040000 };
Battle D_800A7430 = { 0, 0, 0x60040000 };
Battle D_800A743C = { 0, 0, 0x60040000 };
Battle D_800A7448 = { 0, 0, 0x60040000 };
Battle D_800A7454 = { 0, 0, 0x60040000 };
Battle D_800A7460 = { 0, 0, 0x60040000 };
Battle D_800A746C = { 0, 0, 0x60040000 };
Battle D_800A7478 = { 0, 0, 0x60040000 };
BattleList D_800A7484 = {
    0,
    { &D_800A7424, &D_800A7430, &D_800A743C, &D_800A7448,
      &D_800A7454, &D_800A7460, &D_800A746C, &D_800A7478 },
};
Battle D_800A74A8 = { 0, 0, 0x60040000 };
Battle D_800A74B4 = { 0, 0, 0x60040000 };
Battle D_800A74C0 = { 0, 0, 0x60040000 };
Battle D_800A74CC = { 0, 0, 0x60040000 };
Battle D_800A74D8 = { 0, 0, 0x60040000 };
Battle D_800A74E4 = { 0, 0, 0x60040000 };
Battle D_800A74F0 = { 0, 0, 0x60040000 };
Battle D_800A74FC = { 0, 0, 0x60040000 };
BattleList D_800A7508 = {
    0,
    { &D_800A74A8, &D_800A74B4, &D_800A74C0, &D_800A74CC,
      &D_800A74D8, &D_800A74E4, &D_800A74F0, &D_800A74FC },
};
Battle D_800A752C = { 182, 10, 0x60080000 };
Battle D_800A7538 = { 182, 10, 0x60080000 };
Battle D_800A7544 = { 182, 10, 0x60080000 };
Battle D_800A7550 = { 182, 10, 0x60080000 };
Battle D_800A755C = { 71, 10, 0x60080000 };
Battle D_800A7568 = { 71, 10, 0x60080000 };
Battle D_800A7574 = { 71, 10, 0x60080000 };
Battle D_800A7580 = { 71, 10, 0x60080000 };
BattleList D_800A758C = {
    4,
    { &D_800A752C, &D_800A7538, &D_800A7544, &D_800A7550,
      &D_800A755C, &D_800A7568, &D_800A7574, &D_800A7580 },
};
Battle D_800A75B0 = { 0, 0, 0x60040000 };
Battle D_800A75BC = { 0, 0, 0x60040000 };
Battle D_800A75C8 = { 0, 0, 0x60040000 };
Battle D_800A75D4 = { 0, 0, 0x60040000 };
Battle D_800A75E0 = { 0, 0, 0x60040000 };
Battle D_800A75EC = { 0, 0, 0x60040000 };
Battle D_800A75F8 = { 0, 0, 0x60040000 };
Battle D_800A7604 = { 0, 0, 0x60040000 };
BattleList D_800A7610 = {
    0,
    { &D_800A75B0, &D_800A75BC, &D_800A75C8, &D_800A75D4,
      &D_800A75E0, &D_800A75EC, &D_800A75F8, &D_800A7604 },
};
Battle D_800A7634 = { 0, 0, 0x60040000 };
Battle D_800A7640 = { 0, 0, 0x60040000 };
Battle D_800A764C = { 0, 0, 0x60040000 };
Battle D_800A7658 = { 0, 0, 0x60040000 };
Battle D_800A7664 = { 0, 0, 0x60040000 };
Battle D_800A7670 = { 0, 0, 0x60040000 };
Battle D_800A767C = { 0, 0, 0x60040000 };
Battle D_800A7688 = { 0, 0, 0x60040000 };
BattleList D_800A7694 = {
    0,
    { &D_800A7634, &D_800A7640, &D_800A764C, &D_800A7658,
      &D_800A7664, &D_800A7670, &D_800A767C, &D_800A7688 },
};
Battle D_800A76B8 = { 0, 0, 0x60040000 };
Battle D_800A76C4 = { 0, 0, 0x60040000 };
Battle D_800A76D0 = { 0, 0, 0x60040000 };
Battle D_800A76DC = { 0, 0, 0x60040000 };
Battle D_800A76E8 = { 0, 0, 0x60040000 };
Battle D_800A76F4 = { 0, 0, 0x60040000 };
Battle D_800A7700 = { 0, 0, 0x60040000 };
Battle D_800A770C = { 0, 0, 0x60040000 };
BattleList D_800A7718 = {
    0,
    { &D_800A76B8, &D_800A76C4, &D_800A76D0, &D_800A76DC,
      &D_800A76E8, &D_800A76F4, &D_800A7700, &D_800A770C },
};
Battle D_800A773C = { 182, 10, 0x60080000 };
Battle D_800A7748 = { 182, 10, 0x60080000 };
Battle D_800A7754 = { 182, 10, 0x60080000 };
Battle D_800A7760 = { 182, 10, 0x60080000 };
Battle D_800A776C = { 71, 10, 0x60080000 };
Battle D_800A7778 = { 71, 10, 0x60080000 };
Battle D_800A7784 = { 71, 10, 0x60080000 };
Battle D_800A7790 = { 71, 10, 0x60080000 };
BattleList D_800A779C = {
    5,
    { &D_800A773C, &D_800A7748, &D_800A7754, &D_800A7760,
      &D_800A776C, &D_800A7778, &D_800A7784, &D_800A7790 },
};
Battle D_800A77C0 = { 0, 0, 0x60040000 };
Battle D_800A77CC = { 0, 0, 0x60040000 };
Battle D_800A77D8 = { 0, 0, 0x60040000 };
Battle D_800A77E4 = { 0, 0, 0x60040000 };
Battle D_800A77F0 = { 0, 0, 0x60040000 };
Battle D_800A77FC = { 0, 0, 0x60040000 };
Battle D_800A7808 = { 0, 0, 0x60040000 };
Battle D_800A7814 = { 0, 0, 0x60040000 };
BattleList D_800A7820 = {
    0,
    { &D_800A77C0, &D_800A77CC, &D_800A77D8, &D_800A77E4,
      &D_800A77F0, &D_800A77FC, &D_800A7808, &D_800A7814 },
};
Battle D_800A7844 = { 0, 0, 0x60040000 };
Battle D_800A7850 = { 0, 0, 0x60040000 };
Battle D_800A785C = { 0, 0, 0x60040000 };
Battle D_800A7868 = { 0, 0, 0x60040000 };
Battle D_800A7874 = { 0, 0, 0x60040000 };
Battle D_800A7880 = { 0, 0, 0x60040000 };
Battle D_800A788C = { 0, 0, 0x60040000 };
Battle D_800A7898 = { 0, 0, 0x60040000 };
BattleList D_800A78A4 = {
    0,
    { &D_800A7844, &D_800A7850, &D_800A785C, &D_800A7868,
      &D_800A7874, &D_800A7880, &D_800A788C, &D_800A7898 },
};
Battle D_800A78C8 = { 0, 0, 0x60040000 };
Battle D_800A78D4 = { 0, 0, 0x60040000 };
Battle D_800A78E0 = { 0, 0, 0x60040000 };
Battle D_800A78EC = { 0, 0, 0x60040000 };
Battle D_800A78F8 = { 0, 0, 0x60040000 };
Battle D_800A7904 = { 0, 0, 0x60040000 };
Battle D_800A7910 = { 0, 0, 0x60040000 };
Battle D_800A791C = { 0, 0, 0x60040000 };
BattleList D_800A7928 = {
    0,
    { &D_800A78C8, &D_800A78D4, &D_800A78E0, &D_800A78EC,
      &D_800A78F8, &D_800A7904, &D_800A7910, &D_800A791C },
};
Battle D_800A794C = { 174, 10, 0x60080000 };
Battle D_800A7958 = { 174, 10, 0x60080000 };
Battle D_800A7964 = { 170, 10, 0x60080000 };
Battle D_800A7970 = { 170, 10, 0x60080000 };
Battle D_800A797C = { 170, 10, 0x60080000 };
Battle D_800A7988 = { 170, 10, 0x60080000 };
Battle D_800A7994 = { 170, 10, 0x60080000 };
Battle D_800A79A0 = { 170, 10, 0x60080000 };
BattleList D_800A79AC = {
    2,
    { &D_800A794C, &D_800A7958, &D_800A7964, &D_800A7970,
      &D_800A797C, &D_800A7988, &D_800A7994, &D_800A79A0 },
};
Battle D_800A79D0 = { 0, 0, 0x60040000 };
Battle D_800A79DC = { 0, 0, 0x60040000 };
Battle D_800A79E8 = { 0, 0, 0x60040000 };
Battle D_800A79F4 = { 0, 0, 0x60040000 };
Battle D_800A7A00 = { 0, 0, 0x60040000 };
Battle D_800A7A0C = { 0, 0, 0x60040000 };
Battle D_800A7A18 = { 0, 0, 0x60040000 };
Battle D_800A7A24 = { 0, 0, 0x60040000 };
BattleList D_800A7A30 = {
    0,
    { &D_800A79D0, &D_800A79DC, &D_800A79E8, &D_800A79F4,
      &D_800A7A00, &D_800A7A0C, &D_800A7A18, &D_800A7A24 },
};
Battle D_800A7A54 = { 0, 0, 0x60040000 };
Battle D_800A7A60 = { 0, 0, 0x60040000 };
Battle D_800A7A6C = { 0, 0, 0x60040000 };
Battle D_800A7A78 = { 0, 0, 0x60040000 };
Battle D_800A7A84 = { 0, 0, 0x60040000 };
Battle D_800A7A90 = { 0, 0, 0x60040000 };
Battle D_800A7A9C = { 0, 0, 0x60040000 };
Battle D_800A7AA8 = { 0, 0, 0x60040000 };
BattleList D_800A7AB4 = {
    0,
    { &D_800A7A54, &D_800A7A60, &D_800A7A6C, &D_800A7A78,
      &D_800A7A84, &D_800A7A90, &D_800A7A9C, &D_800A7AA8 },
};
Battle D_800A7AD8 = { 0, 0, 0x60040000 };
Battle D_800A7AE4 = { 0, 0, 0x60040000 };
Battle D_800A7AF0 = { 0, 0, 0x60040000 };
Battle D_800A7AFC = { 0, 0, 0x60040000 };
Battle D_800A7B08 = { 0, 0, 0x60040000 };
Battle D_800A7B14 = { 0, 0, 0x60040000 };
Battle D_800A7B20 = { 0, 0, 0x60040000 };
Battle D_800A7B2C = { 0, 0, 0x60040000 };
BattleList D_800A7B38 = {
    0,
    { &D_800A7AD8, &D_800A7AE4, &D_800A7AF0, &D_800A7AFC,
      &D_800A7B08, &D_800A7B14, &D_800A7B20, &D_800A7B2C },
};
Battle D_800A7B5C = { 182, 10, 0x60080000 };
Battle D_800A7B68 = { 182, 10, 0x60080000 };
Battle D_800A7B74 = { 182, 10, 0x60080000 };
Battle D_800A7B80 = { 182, 10, 0x60080000 };
Battle D_800A7B8C = { 71, 10, 0x60080000 };
Battle D_800A7B98 = { 71, 10, 0x60080000 };
Battle D_800A7BA4 = { 71, 10, 0x60080000 };
Battle D_800A7BB0 = { 71, 10, 0x60080000 };
BattleList D_800A7BBC = {
    1,
    { &D_800A7B5C, &D_800A7B68, &D_800A7B74, &D_800A7B80,
      &D_800A7B8C, &D_800A7B98, &D_800A7BA4, &D_800A7BB0 },
};
Battle D_800A7BE0 = { 0, 0, 0x60040000 };
Battle D_800A7BEC = { 0, 0, 0x60040000 };
Battle D_800A7BF8 = { 0, 0, 0x60040000 };
Battle D_800A7C04 = { 0, 0, 0x60040000 };
Battle D_800A7C10 = { 0, 0, 0x60040000 };
Battle D_800A7C1C = { 0, 0, 0x60040000 };
Battle D_800A7C28 = { 0, 0, 0x60040000 };
Battle D_800A7C34 = { 0, 0, 0x60040000 };
BattleList D_800A7C40 = {
    0,
    { &D_800A7BE0, &D_800A7BEC, &D_800A7BF8, &D_800A7C04,
      &D_800A7C10, &D_800A7C1C, &D_800A7C28, &D_800A7C34 },
};
Battle D_800A7C64 = { 0, 0, 0x60040000 };
Battle D_800A7C70 = { 0, 0, 0x60040000 };
Battle D_800A7C7C = { 0, 0, 0x60040000 };
Battle D_800A7C88 = { 0, 0, 0x60040000 };
Battle D_800A7C94 = { 0, 0, 0x60040000 };
Battle D_800A7CA0 = { 0, 0, 0x60040000 };
Battle D_800A7CAC = { 0, 0, 0x60040000 };
Battle D_800A7CB8 = { 0, 0, 0x60040000 };
BattleList D_800A7CC4 = {
    0,
    { &D_800A7C64, &D_800A7C70, &D_800A7C7C, &D_800A7C88,
      &D_800A7C94, &D_800A7CA0, &D_800A7CAC, &D_800A7CB8 },
};
Battle D_800A7CE8 = { 0, 0, 0x60040000 };
Battle D_800A7CF4 = { 0, 0, 0x60040000 };
Battle D_800A7D00 = { 0, 0, 0x60040000 };
Battle D_800A7D0C = { 0, 0, 0x60040000 };
Battle D_800A7D18 = { 0, 0, 0x60040000 };
Battle D_800A7D24 = { 0, 0, 0x60040000 };
Battle D_800A7D30 = { 0, 0, 0x60040000 };
Battle D_800A7D3C = { 0, 0, 0x60040000 };
BattleList D_800A7D48 = {
    0,
    { &D_800A7CE8, &D_800A7CF4, &D_800A7D00, &D_800A7D0C,
      &D_800A7D18, &D_800A7D24, &D_800A7D30, &D_800A7D3C },
};
Battle D_800A7D6C = { 182, 10, 0x60080000 };
Battle D_800A7D78 = { 182, 10, 0x60080000 };
Battle D_800A7D84 = { 182, 10, 0x60080000 };
Battle D_800A7D90 = { 182, 10, 0x60080000 };
Battle D_800A7D9C = { 71, 10, 0x60080000 };
Battle D_800A7DA8 = { 71, 10, 0x60080000 };
Battle D_800A7DB4 = { 71, 10, 0x60080000 };
Battle D_800A7DC0 = { 71, 10, 0x60080000 };
BattleList D_800A7DCC = {
    1,
    { &D_800A7D6C, &D_800A7D78, &D_800A7D84, &D_800A7D90,
      &D_800A7D9C, &D_800A7DA8, &D_800A7DB4, &D_800A7DC0 },
};
Battle D_800A7DF0 = { 0, 0, 0x60040000 };
Battle D_800A7DFC = { 0, 0, 0x60040000 };
Battle D_800A7E08 = { 0, 0, 0x60040000 };
Battle D_800A7E14 = { 0, 0, 0x60040000 };
Battle D_800A7E20 = { 0, 0, 0x60040000 };
Battle D_800A7E2C = { 0, 0, 0x60040000 };
Battle D_800A7E38 = { 0, 0, 0x60040000 };
Battle D_800A7E44 = { 0, 0, 0x60040000 };
BattleList D_800A7E50 = {
    0,
    { &D_800A7DF0, &D_800A7DFC, &D_800A7E08, &D_800A7E14,
      &D_800A7E20, &D_800A7E2C, &D_800A7E38, &D_800A7E44 },
};
Battle D_800A7E74 = { 0, 0, 0x60040000 };
Battle D_800A7E80 = { 0, 0, 0x60040000 };
Battle D_800A7E8C = { 0, 0, 0x60040000 };
Battle D_800A7E98 = { 0, 0, 0x60040000 };
Battle D_800A7EA4 = { 0, 0, 0x60040000 };
Battle D_800A7EB0 = { 0, 0, 0x60040000 };
Battle D_800A7EBC = { 0, 0, 0x60040000 };
Battle D_800A7EC8 = { 0, 0, 0x60040000 };
BattleList D_800A7ED4 = {
    0,
    { &D_800A7E74, &D_800A7E80, &D_800A7E8C, &D_800A7E98,
      &D_800A7EA4, &D_800A7EB0, &D_800A7EBC, &D_800A7EC8 },
};
Battle D_800A7EF8 = { 0, 0, 0x60040000 };
Battle D_800A7F04 = { 0, 0, 0x60040000 };
Battle D_800A7F10 = { 0, 0, 0x60040000 };
Battle D_800A7F1C = { 0, 0, 0x60040000 };
Battle D_800A7F28 = { 0, 0, 0x60040000 };
Battle D_800A7F34 = { 0, 0, 0x60040000 };
Battle D_800A7F40 = { 0, 0, 0x60040000 };
Battle D_800A7F4C = { 0, 0, 0x60040000 };
BattleList D_800A7F58 = {
    0,
    { &D_800A7EF8, &D_800A7F04, &D_800A7F10, &D_800A7F1C,
      &D_800A7F28, &D_800A7F34, &D_800A7F40, &D_800A7F4C },
};
Battle D_800A7F7C = { 174, 10, 0x60080000 };
Battle D_800A7F88 = { 174, 10, 0x60080000 };
Battle D_800A7F94 = { 170, 10, 0x60080000 };
Battle D_800A7FA0 = { 170, 10, 0x60080000 };
Battle D_800A7FAC = { 182, 10, 0x60080000 };
Battle D_800A7FB8 = { 182, 10, 0x60080000 };
Battle D_800A7FC4 = { 71, 10, 0x60080000 };
Battle D_800A7FD0 = { 71, 10, 0x60080000 };
BattleList D_800A7FDC = {
    1,
    { &D_800A7F7C, &D_800A7F88, &D_800A7F94, &D_800A7FA0,
      &D_800A7FAC, &D_800A7FB8, &D_800A7FC4, &D_800A7FD0 },
};
Battle D_800A8000 = { 0, 0, 0x60040000 };
Battle D_800A800C = { 0, 0, 0x60040000 };
Battle D_800A8018 = { 0, 0, 0x60040000 };
Battle D_800A8024 = { 0, 0, 0x60040000 };
Battle D_800A8030 = { 0, 0, 0x60040000 };
Battle D_800A803C = { 0, 0, 0x60040000 };
Battle D_800A8048 = { 0, 0, 0x60040000 };
Battle D_800A8054 = { 0, 0, 0x60040000 };
BattleList D_800A8060 = {
    0,
    { &D_800A8000, &D_800A800C, &D_800A8018, &D_800A8024,
      &D_800A8030, &D_800A803C, &D_800A8048, &D_800A8054 },
};
Battle D_800A8084 = { 0, 0, 0x60040000 };
Battle D_800A8090 = { 0, 0, 0x60040000 };
Battle D_800A809C = { 0, 0, 0x60040000 };
Battle D_800A80A8 = { 0, 0, 0x60040000 };
Battle D_800A80B4 = { 0, 0, 0x60040000 };
Battle D_800A80C0 = { 0, 0, 0x60040000 };
Battle D_800A80CC = { 0, 0, 0x60040000 };
Battle D_800A80D8 = { 0, 0, 0x60040000 };
BattleList D_800A80E4 = {
    0,
    { &D_800A8084, &D_800A8090, &D_800A809C, &D_800A80A8,
      &D_800A80B4, &D_800A80C0, &D_800A80CC, &D_800A80D8 },
};
Battle D_800A8108 = { 0, 0, 0x60040000 };
Battle D_800A8114 = { 0, 0, 0x60040000 };
Battle D_800A8120 = { 0, 0, 0x60040000 };
Battle D_800A812C = { 0, 0, 0x60040000 };
Battle D_800A8138 = { 0, 0, 0x60040000 };
Battle D_800A8144 = { 0, 0, 0x60040000 };
Battle D_800A8150 = { 0, 0, 0x60040000 };
Battle D_800A815C = { 0, 0, 0x60040000 };
BattleList D_800A8168 = {
    0,
    { &D_800A8108, &D_800A8114, &D_800A8120, &D_800A812C,
      &D_800A8138, &D_800A8144, &D_800A8150, &D_800A815C },
};
FieldBattles stageBattles[] = {
    { 232, 1, 0, { &D_800A548C, &D_800A5510, &D_800A5594, &D_800A5618 } },
    { 251, 4, 0, { &D_800A569C, &D_800A5720, &D_800A57A4, &D_800A5828 } },
    { 267, 7, 0, { &D_800A58AC, &D_800A5930, &D_800A59B4, &D_800A5A38 } },
    { 293, 12, 0, { &D_800A5ABC, &D_800A5B40, &D_800A5BC4, &D_800A5C48 } },
    { 301, 13, 0, { &D_800A5CCC, &D_800A5D50, &D_800A5DD4, &D_800A5E58 } },
    { 303, 14, 0, { &D_800A5EDC, &D_800A5F60, &D_800A5FE4, &D_800A6068 } },
    { 306, 15, 0, { &D_800A60EC, &D_800A6170, &D_800A61F4, &D_800A6278 } },
    { 311, 16, 0, { &D_800A62FC, &D_800A6380, &D_800A6404, &D_800A6488 } },
    { 313, 17, 0, { &D_800A650C, &D_800A6590, &D_800A6614, &D_800A6698 } },
    { 316, 18, 0, { &D_800A671C, &D_800A67A0, &D_800A6824, &D_800A68A8 } },
    { 322, 19, 0, { &D_800A692C, &D_800A69B0, &D_800A6A34, &D_800A6AB8 } },
    { 328, 20, 0, { &D_800A6B3C, &D_800A6BC0, &D_800A6C44, &D_800A6CC8 } },
    { 333, 21, 0, { &D_800A6D4C, &D_800A6DD0, &D_800A6E54, &D_800A6ED8 } },
    { 337, 22, 0, { &D_800A6F5C, &D_800A6FE0, &D_800A7064, &D_800A70E8 } },
    { 341, 23, 0, { &D_800A716C, &D_800A71F0, &D_800A7274, &D_800A72F8 } },
    { 344, 24, 0, { &D_800A737C, &D_800A7400, &D_800A7484, &D_800A7508 } },
    { 349, 25, 0, { &D_800A758C, &D_800A7610, &D_800A7694, &D_800A7718 } },
    { 351, 26, 0, { &D_800A779C, &D_800A7820, &D_800A78A4, &D_800A7928 } },
    { 354, 27, 0, { &D_800A79AC, &D_800A7A30, &D_800A7AB4, &D_800A7B38 } },
    { 361, 28, 0, { &D_800A7BBC, &D_800A7C40, &D_800A7CC4, &D_800A7D48 } },
    { 367, 29, 0, { &D_800A7DCC, &D_800A7E50, &D_800A7ED4, &D_800A7F58 } },
    { 373, 30, 0, { &D_800A7FDC, &D_800A8060, &D_800A80E4, &D_800A8168 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14C, 0x140, 0x30, 0x40, 0x140, 0x1FF },
    { 0x140, 0x100, 0x152, 0x140, 0x48, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x158, 0x140, 0x60, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x15E, 0x140, 0x78, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x164, 0x140, 0x90, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x16A, 0x140, 0xA8, 0x40, 0x150, 0x1FE },
    { 0x140, 0x100, 0x170, 0x140, 0xC0, 0x40, 0x160, 0x1FE },
    { 0x140, 0x100, 0x176, 0x140, 0xD8, 0x40, 0x170, 0x1FE },
    { 0x140, 0x100, 0x14C, 0x160, 0x30, 0x60, 0x140, 0x1FD },
    { 0x140, 0x100, 0x152, 0x160, 0x48, 0x60, 0x150, 0x1FD },
    { 0x140, 0x100, 0x158, 0x160, 0x60, 0x60, 0x160, 0x1FD },
    { 0x140, 0x100, 0x15E, 0x160, 0x78, 0x60, 0x170, 0x1FD },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x140, 0x1FC },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x150, 0x1FC },
    { 0x140, 0x100, 0x164, 0x160, 0x90, 0x60, 0x160, 0x1FC },
    { 0x140, 0x100, 0x16A, 0x160, 0xA8, 0x60, 0x170, 0x1FC },
    { 0x140, 0x100, 0x170, 0x160, 0xC0, 0x60, 0x140, 0x1FB },
    { 0x140, 0x100, 0x176, 0x160, 0xD8, 0x60, 0x150, 0x1FB },
    { 0x140, 0x100, 0x140, 0x170, 0, 0x70, 0x160, 0x1FB },
    { 0x140, 0x100, 0x146, 0x170, 0x18, 0x70, 0x170, 0x1FB },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x140, 0x1FA },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x150, 0x1FA },
};
u16 D_800A85B4[] = { 0x22D, 1, 0x822F, 1, 0xFFFF };
u16 D_800A85C0[] = { 0x22E, 1, 0x8230, 1, 0xFFFF };
u16 D_800A85CC[] = { 0x22F, 1, 0x8231, 1, 0xFFFF };
u16 D_800A85D8[] = { 0x230, 1, 0x8232, 1, 0xFFFF };
u16 D_800A85E4[] = { 0x231, 1, 0x8233, 1, 0xFFFF };
u16 D_800A85F0[] = { 0x232, 1, 0x8234, 1, 0xFFFF };
u16 D_800A85FC[] = { 0x233, 1, 0x8235, 1, 0xFFFF };
u16 D_800A8608[] = { 0x234, 1, 0x8237, 1, 0xFFFF };
u16 D_800A8614[] = { 0x235, 1, 0x8238, 1, 0xFFFF };
u16 D_800A8620[] = { 0x236, 1, 0x8239, 1, 0xFFFF };
u16 D_800A862C[] = { 0x237, 1, 0x823A, 1, 0xFFFF };
u16 D_800A8638[] = { 0x256, 1, 0x823B, 1, 0xFFFF };
u16 D_800A8644[] = { 0x257, 1, 0x823C, 1, 0xFFFF };
u16 D_800A8650[] = { 0x258, 1, 0x823D, 1, 0xFFFF };
u16 D_800A865C[] = { 0x259, 1, 0x8470, 1, 0xFFFF };
u16 D_800A8668[] = { 0x25A, 1, 0x8B1B, 1, 0xFFFF };
u16 D_800A8674[] = { 0x25B, 1, 0x8B1C, 1, 0xFFFF };
u16 D_800A8680[] = { 0x25C, 1, 0x8AFF, 1, 0xFFFF };
FieldTalk D_800A868C[] = {
    { NULL, D_800A85B4, 0x38E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A86A4[] = {
    { NULL, D_800A85C0, 0x388 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A86BC[] = {
    { NULL, D_800A85CC, 0x389 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A86D4[] = {
    { NULL, D_800A85D8, 0x38A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A86EC[] = {
    { NULL, D_800A85E4, 0x38B },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8704[] = {
    { NULL, D_800A85F0, 0x38C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A871C[] = {
    { NULL, D_800A85FC, 0x38D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8734[] = {
    { NULL, D_800A8608, 0x38F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A874C[] = {
    { NULL, D_800A8614, 0x390 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8764[] = {
    { NULL, D_800A8620, 0x391 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A877C[] = {
    { NULL, D_800A862C, 0x392 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8794[] = {
    { NULL, D_800A8638, 0x393 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A87AC[] = {
    { NULL, D_800A8644, 0x394 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A87C4[] = {
    { NULL, D_800A8650, 0x395 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A87DC[] = {
    { NULL, D_800A865C, 0x396 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A87F4[] = {
    { NULL, D_800A8668, 0x397 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A880C[] = {
    { NULL, D_800A8674, 0x398 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8824[] = {
    { NULL, D_800A8680, 0x399 },
    { NULL, NULL, 0 },
};
u16 D_800A883C[] = { 0x7E15, 1, 0x7E1E, 1, 0x22D, 0, 0xFFFF };
u16 D_800A884C[] = { 0x7E12, 1, 0x7E21, 1, 0x22E, 0, 0xFFFF };
u16 D_800A885C[] = { 0x7E00, 1, 0x7E1E, 1, 0x22F, 0, 0xFFFF };
u16 D_800A886C[] = { 0x7E18, 1, 0x7E1F, 1, 0x230, 0, 0xFFFF };
u16 D_800A887C[] = { 0x7E0E, 1, 0x7E1E, 1, 0x231, 0, 0xFFFF };
u16 D_800A888C[] = { 0x7E03, 1, 0x7E1E, 1, 0x232, 0, 0xFFFF };
u16 D_800A889C[] = { 0x7E11, 1, 0x7E1E, 1, 0x233, 0, 0xFFFF };
u16 D_800A88AC[] = { 0x7E0F, 1, 0x7E1E, 1, 0x234, 0, 0xFFFF };
u16 D_800A88BC[] = { 0x7E1C, 1, 0x7E1F, 1, 0x235, 0, 0xFFFF };
u16 D_800A88CC[] = { 0x7E0D, 1, 0x7E1E, 1, 0x236, 0, 0xFFFF };
u16 D_800A88DC[] = { 0x7E10, 1, 0x7E1E, 1, 0x237, 0, 0xFFFF };
u16 D_800A88EC[] = { 0x256, 0, 0x7E0C, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A88FC[] = { 0x7E18, 1, 8, 0, 0xFFFF };
u16 D_800A8908[] = { 0x7E1B, 1, 8, 0, 0xFFFF };
u16 D_800A8914[] = { 0x7E06, 1, 0x7E1E, 1, 0x257, 0, 0xFFFF };
u16 D_800A8924[] = { 0x7E13, 1, 0x7E20, 1, 0x258, 0, 0xFFFF };
u16 D_800A8934[] = { 0x7E13, 1, 0x7E23, 1, 0x259, 0, 0xFFFF };
u16 D_800A8944[] = { 0x7E19, 1, 0x7E1E, 1, 0x25A, 0, 0xFFFF };
u16 D_800A8954[] = { 0x7E17, 1, 0x7E1E, 1, 0x25B, 0, 0xFFFF };
u16 D_800A8964[] = { 0x7E1B, 1, 0x7E1F, 1, 0x25C, 0, 0xFFFF };
u16 D_800A8974[] = { 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A8980[] = { 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A898C[] = { 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A8998[] = { 0x7E21, 1, 9, 0, 0xFFFF };
u16 D_800A89A4[] = { 0x7E00, 1, 0xA, 0, 0xFFFF };
u16 D_800A89B0[] = { 0x7E0B, 1, 0xA, 0, 0xFFFF };
u16 D_800A89BC[] = { 0x7E0C, 1, 0xA, 0, 0xFFFF };
u16 D_800A89C8[] = { 0x7E0D, 1, 0xA, 0, 0xFFFF };
u16 D_800A89D4[] = { 0x7E0F, 1, 0xA, 0, 0xFFFF };
u16 D_800A89E0[] = { 0x7E10, 1, 0xA, 0, 0xFFFF };
u16 D_800A89EC[] = { 0x7E12, 1, 0xA, 0, 0xFFFF };
u16 D_800A89F8[] = { 0x7E13, 1, 0xA, 0, 0xFFFF };
u16 D_800A8A04[] = { 0x7E17, 1, 0xA, 0, 0xFFFF };
u16 D_800A8A10[] = { 0x7E18, 1, 0xA, 0, 0xFFFF };
u16 D_800A8A1C[] = { 0x7E1A, 1, 0xA, 0, 0xFFFF };
u16 D_800A8A28[] = { 0x7E1B, 1, 0xA, 0, 0xFFFF };
u16 D_800A8A34[] = { 0x7E1C, 1, 0xA, 0, 0xFFFF };
u16 D_800A8A40[] = { 0x7E1D, 1, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A8A4C = { D_800A883C, D_800A868C, 0x21, 4, 240, 600, 1 };
FieldActorEntry D_800A8A60 = { D_800A884C, D_800A86A4, 0x4D, 5, 240, 600, 1 };
FieldActorEntry D_800A8A74 = { D_800A885C, D_800A86BC, 0x4E, 6, 240, 600, 1 };
FieldActorEntry D_800A8A88 = { D_800A886C, D_800A86D4, 0x4F, 7, 240, 600, 1 };
FieldActorEntry D_800A8A9C = { D_800A887C, D_800A86EC, 0x50, 8, 240, 600, 1 };
FieldActorEntry D_800A8AB0 = { D_800A888C, D_800A8704, 0x51, 9, 260, 600, 1 };
FieldActorEntry D_800A8AC4 = { D_800A889C, D_800A871C, 0x52, 0xA, 240, 600, 1 };
FieldActorEntry D_800A8AD8 = { D_800A88AC, D_800A8734, 0x53, 0xB, 240, 600, 1 };
FieldActorEntry D_800A8AEC = { D_800A88BC, D_800A874C, 0x54, 0xC, 240, 600, 1 };
FieldActorEntry D_800A8B00 = { D_800A88CC, D_800A8764, 0x55, 0xD, 240, 600, 1 };
FieldActorEntry D_800A8B14 = { D_800A88DC, D_800A877C, 0x56, 0xE, 240, 600, 1 };
FieldActorEntry D_800A8B28 = { D_800A88EC, D_800A8794, 0x57, 0xF, 240, 600, 1 };
FieldActorEntry D_800A8B3C = { NULL, NULL, 0x146, 0x10, 0, 0, 0 };
FieldActorEntry D_800A8B50 = { D_800A88FC, NULL, 0x148, 0x11, 336, 312, 1 };
FieldActorEntry D_800A8B64 = { D_800A8908, NULL, 0x148, 0x11, 400, 344, 1 };
FieldActorEntry D_800A8B78 = { D_800A8914, D_800A87AC, 0x154, 0x12, 240, 600, 1 };
FieldActorEntry D_800A8B8C = { D_800A8924, D_800A87C4, 0x155, 0x13, 240, 600, 1 };
FieldActorEntry D_800A8BA0 = { D_800A8934, D_800A87DC, 0x156, 0x14, 240, 600, 1 };
FieldActorEntry D_800A8BB4 = { D_800A8944, D_800A87F4, 0x157, 0x15, 240, 600, 1 };
FieldActorEntry D_800A8BC8 = { D_800A8954, D_800A880C, 0x158, 0x16, 240, 600, 1 };
FieldActorEntry D_800A8BDC = { D_800A8964, D_800A8824, 0x15B, 0x17, 240, 600, 1 };
FieldActorEntry D_800A8BF0 = { D_800A8974, NULL, 0x15F, 0x18, 288, 400, 1 };
FieldActorEntry D_800A8C04 = { D_800A8980, NULL, 0x15F, 0x18, 208, 440, 1 };
FieldActorEntry D_800A8C18 = { D_800A898C, NULL, 0x15F, 0x18, 160, 464, 1 };
FieldActorEntry D_800A8C2C = { D_800A8998, NULL, 0x15F, 0x18, 480, 208, 1 };
FieldActorEntry D_800A8C40 = { D_800A89A4, NULL, 0x160, 0x19, 192, 544, 1 };
FieldActorEntry D_800A8C54 = { D_800A89B0, NULL, 0x160, 0x19, 480, 208, 1 };
FieldActorEntry D_800A8C68 = { D_800A89BC, NULL, 0x160, 0x19, 352, 272, 1 };
FieldActorEntry D_800A8C7C = { D_800A89C8, NULL, 0x160, 0x19, 336, 312, 1 };
FieldActorEntry D_800A8C90 = { D_800A89D4, NULL, 0x160, 0x19, 240, 488, 1 };
FieldActorEntry D_800A8CA4 = { D_800A89E0, NULL, 0x160, 0x19, 336, 376, 1 };
FieldActorEntry D_800A8CB8 = { D_800A89EC, NULL, 0x160, 0x19, 352, 272, 1 };
FieldActorEntry D_800A8CCC = { D_800A89F8, NULL, 0x160, 0x19, 400, 344, 1 };
FieldActorEntry D_800A8CE0 = { D_800A8A04, NULL, 0x160, 0x19, 352, 272, 1 };
FieldActorEntry D_800A8CF4 = { D_800A8A10, NULL, 0x160, 0x19, 192, 544, 1 };
FieldActorEntry D_800A8D08 = { D_800A8A1C, NULL, 0x160, 0x19, 240, 488, 1 };
FieldActorEntry D_800A8D1C = { D_800A8A28, NULL, 0x160, 0x19, 480, 208, 1 };
FieldActorEntry D_800A8D30 = { D_800A8A34, NULL, 0x160, 0x19, 352, 272, 1 };
FieldActorEntry D_800A8D44 = { D_800A8A40, NULL, 0x160, 0x19, 336, 376, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A8A4C,
    &D_800A8A60,
    &D_800A8A74,
    &D_800A8A88,
    &D_800A8A9C,
    &D_800A8AB0,
    &D_800A8AC4,
    &D_800A8AD8,
    &D_800A8AEC,
    &D_800A8B00,
    &D_800A8B14,
    &D_800A8B28,
    &D_800A8B3C,
    &D_800A8B50,
    &D_800A8B64,
    &D_800A8B78,
    &D_800A8B8C,
    &D_800A8BA0,
    &D_800A8BB4,
    &D_800A8BC8,
    &D_800A8BDC,
    &D_800A8BF0,
    &D_800A8C04,
    &D_800A8C18,
    &D_800A8C2C,
    &D_800A8C40,
    &D_800A8C54,
    &D_800A8C68,
    &D_800A8C7C,
    &D_800A8C90,
    &D_800A8CA4,
    &D_800A8CB8,
    &D_800A8CCC,
    &D_800A8CE0,
    &D_800A8CF4,
    &D_800A8D08,
    &D_800A8D1C,
    &D_800A8D30,
    &D_800A8D44,
    NULL,
};
StageTile stageObjects[] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2EB, 0x240, 0xA0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
