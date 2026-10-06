#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x6A0
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6B0
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0xF900, 0x14000};
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
extern StagePoint D_800A4FB8;
extern StagePoint D_800A4FC8;
extern StagePoint D_800A4FE0;
extern StagePoint D_800A4FF0;
extern StagePoint D_800A5008;
extern StagePoint D_800A5018;
extern StagePoint D_800A5030;
extern StagePoint D_800A5040;
extern StagePoint D_800A5058;
extern StagePoint D_800A5068;
extern StagePoint D_800A5080;
extern StagePoint D_800A5090;
extern StagePoint D_800A50A8;
extern StagePoint D_800A50B8;
extern StagePoint D_800A50D0;
extern StagePoint D_800A50E0;
extern StagePoint D_800A50F8;
extern StagePoint D_800A5108;
extern StagePoint D_800A5120;
extern StagePoint D_800A5130;
extern StagePoint D_800A5148;
extern StagePoint D_800A5158;
extern StagePoint D_800A5170;
extern StagePoint D_800A5180;
extern StagePoint D_800A5198;
extern StagePoint D_800A51A8;
extern StagePoint D_800A51C0;
extern StagePoint D_800A51D0;
extern StagePoint D_800A51E8;
extern StagePoint D_800A51F8;
extern StagePoint D_800A5210;
extern StagePoint D_800A5220;
extern StagePoint D_800A5238;
extern StagePoint D_800A5248;
extern StagePoint D_800A5260;
extern StagePoint D_800A5270;
extern StagePoint D_800A5288;
extern StagePoint D_800A5298;
extern StagePoint D_800A52B0;
extern StagePoint D_800A52C0;
extern StagePoint D_800A52D8;
extern StagePoint D_800A52E8;
extern StagePoint D_800A5300;
extern StagePoint D_800A5310;
extern StagePoint D_800A5328;
extern StagePoint D_800A5338;
extern StagePoint D_800A5350;
extern StagePoint D_800A5360;
extern StagePoint D_800A5378;
extern StagePoint D_800A5388;
extern StagePoint D_800A53A0;
extern StagePoint D_800A53B0;
extern StagePoint D_800A53C8;
extern StagePoint D_800A53D8;
extern StagePoint D_800A53F0;
extern StagePoint D_800A5400;
extern StagePoint D_800A5418;
extern StagePoint D_800A5428;
extern StagePoint D_800A5440;
extern StagePoint D_800A5450;
extern StagePoint D_800A5468;
extern StagePoint D_800A5478;
extern StagePoint D_800A5490;
extern StagePoint D_800A54A0;
extern StagePoint D_800A54B8;
extern StagePoint D_800A54C8;
extern StagePoint D_800A54E0;
extern StagePoint D_800A54F0;
extern StagePoint D_800A5508;
extern StagePoint D_800A5518;
extern StagePoint D_800A5530;
extern StagePoint D_800A5540;
extern StagePoint D_800A5558;
extern StagePoint D_800A5568;
extern StagePoint D_800A5580;
extern StagePoint D_800A5590;
extern StagePoint D_800A55A8;
extern StagePoint D_800A55B8;
extern StagePoint D_800A55D0;
extern StagePoint D_800A55E0;
extern StagePoint D_800A55F8;
extern StagePoint D_800A5608;
extern StagePoint D_800A5620;
extern StagePoint D_800A5630;
extern StagePoint D_800A5648;
extern StagePoint D_800A5658;
extern StagePoints D_800A4FB0;
extern StagePoints D_800A4FD8;
extern StagePoints D_800A5000;
extern StagePoints D_800A5028;
extern StagePoints D_800A5050;
extern StagePoints D_800A5078;
extern StagePoints D_800A50A0;
extern StagePoints D_800A50C8;
extern StagePoints D_800A50F0;
extern StagePoints D_800A5118;
extern StagePoints D_800A5140;
extern StagePoints D_800A5168;
extern StagePoints D_800A5190;
extern StagePoints D_800A51B8;
extern StagePoints D_800A51E0;
extern StagePoints D_800A5208;
extern StagePoints D_800A5230;
extern StagePoints D_800A5258;
extern StagePoints D_800A5280;
extern StagePoints D_800A52A8;
extern StagePoints D_800A52D0;
extern StagePoints D_800A52F8;
extern StagePoints D_800A5320;
extern StagePoints D_800A5348;
extern StagePoints D_800A5370;
extern StagePoints D_800A5398;
extern StagePoints D_800A53C0;
extern StagePoints D_800A53E8;
extern StagePoints D_800A5410;
extern StagePoints D_800A5438;
extern StagePoints D_800A5460;
extern StagePoints D_800A5488;
extern StagePoints D_800A54B0;
extern StagePoints D_800A54D8;
extern StagePoints D_800A5500;
extern StagePoints D_800A5528;
extern StagePoints D_800A5550;
extern StagePoints D_800A5578;
extern StagePoints D_800A55A0;
extern StagePoints D_800A55C8;
extern StagePoints D_800A55F0;
extern StagePoints D_800A5618;
extern StagePoints D_800A5640;
extern StagePoints D_800A5668;
extern Battle D_800A5724;
extern Battle D_800A5730;
extern Battle D_800A573C;
extern Battle D_800A5748;
extern Battle D_800A5754;
extern Battle D_800A5760;
extern Battle D_800A576C;
extern Battle D_800A5778;
extern Battle D_800A57A8;
extern Battle D_800A57B4;
extern Battle D_800A57C0;
extern Battle D_800A57CC;
extern Battle D_800A57D8;
extern Battle D_800A57E4;
extern Battle D_800A57F0;
extern Battle D_800A57FC;
extern Battle D_800A582C;
extern Battle D_800A5838;
extern Battle D_800A5844;
extern Battle D_800A5850;
extern Battle D_800A585C;
extern Battle D_800A5868;
extern Battle D_800A5874;
extern Battle D_800A5880;
extern Battle D_800A58B0;
extern Battle D_800A58BC;
extern Battle D_800A58C8;
extern Battle D_800A58D4;
extern Battle D_800A58E0;
extern Battle D_800A58EC;
extern Battle D_800A58F8;
extern Battle D_800A5904;
extern Battle D_800A5934;
extern Battle D_800A5940;
extern Battle D_800A594C;
extern Battle D_800A5958;
extern Battle D_800A5964;
extern Battle D_800A5970;
extern Battle D_800A597C;
extern Battle D_800A5988;
extern Battle D_800A59B8;
extern Battle D_800A59C4;
extern Battle D_800A59D0;
extern Battle D_800A59DC;
extern Battle D_800A59E8;
extern Battle D_800A59F4;
extern Battle D_800A5A00;
extern Battle D_800A5A0C;
extern Battle D_800A5A3C;
extern Battle D_800A5A48;
extern Battle D_800A5A54;
extern Battle D_800A5A60;
extern Battle D_800A5A6C;
extern Battle D_800A5A78;
extern Battle D_800A5A84;
extern Battle D_800A5A90;
extern Battle D_800A5AC0;
extern Battle D_800A5ACC;
extern Battle D_800A5AD8;
extern Battle D_800A5AE4;
extern Battle D_800A5AF0;
extern Battle D_800A5AFC;
extern Battle D_800A5B08;
extern Battle D_800A5B14;
extern Battle D_800A5B44;
extern Battle D_800A5B50;
extern Battle D_800A5B5C;
extern Battle D_800A5B68;
extern Battle D_800A5B74;
extern Battle D_800A5B80;
extern Battle D_800A5B8C;
extern Battle D_800A5B98;
extern Battle D_800A5BC8;
extern Battle D_800A5BD4;
extern Battle D_800A5BE0;
extern Battle D_800A5BEC;
extern Battle D_800A5BF8;
extern Battle D_800A5C04;
extern Battle D_800A5C10;
extern Battle D_800A5C1C;
extern Battle D_800A5C4C;
extern Battle D_800A5C58;
extern Battle D_800A5C64;
extern Battle D_800A5C70;
extern Battle D_800A5C7C;
extern Battle D_800A5C88;
extern Battle D_800A5C94;
extern Battle D_800A5CA0;
extern Battle D_800A5CD0;
extern Battle D_800A5CDC;
extern Battle D_800A5CE8;
extern Battle D_800A5CF4;
extern Battle D_800A5D00;
extern Battle D_800A5D0C;
extern Battle D_800A5D18;
extern Battle D_800A5D24;
extern Battle D_800A5D54;
extern Battle D_800A5D60;
extern Battle D_800A5D6C;
extern Battle D_800A5D78;
extern Battle D_800A5D84;
extern Battle D_800A5D90;
extern Battle D_800A5D9C;
extern Battle D_800A5DA8;
extern Battle D_800A5DD8;
extern Battle D_800A5DE4;
extern Battle D_800A5DF0;
extern Battle D_800A5DFC;
extern Battle D_800A5E08;
extern Battle D_800A5E14;
extern Battle D_800A5E20;
extern Battle D_800A5E2C;
extern Battle D_800A5E5C;
extern Battle D_800A5E68;
extern Battle D_800A5E74;
extern Battle D_800A5E80;
extern Battle D_800A5E8C;
extern Battle D_800A5E98;
extern Battle D_800A5EA4;
extern Battle D_800A5EB0;
extern Battle D_800A5EE0;
extern Battle D_800A5EEC;
extern Battle D_800A5EF8;
extern Battle D_800A5F04;
extern Battle D_800A5F10;
extern Battle D_800A5F1C;
extern Battle D_800A5F28;
extern Battle D_800A5F34;
extern Battle D_800A5F64;
extern Battle D_800A5F70;
extern Battle D_800A5F7C;
extern Battle D_800A5F88;
extern Battle D_800A5F94;
extern Battle D_800A5FA0;
extern Battle D_800A5FAC;
extern Battle D_800A5FB8;
extern Battle D_800A5FE8;
extern Battle D_800A5FF4;
extern Battle D_800A6000;
extern Battle D_800A600C;
extern Battle D_800A6018;
extern Battle D_800A6024;
extern Battle D_800A6030;
extern Battle D_800A603C;
extern Battle D_800A606C;
extern Battle D_800A6078;
extern Battle D_800A6084;
extern Battle D_800A6090;
extern Battle D_800A609C;
extern Battle D_800A60A8;
extern Battle D_800A60B4;
extern Battle D_800A60C0;
extern Battle D_800A60F0;
extern Battle D_800A60FC;
extern Battle D_800A6108;
extern Battle D_800A6114;
extern Battle D_800A6120;
extern Battle D_800A612C;
extern Battle D_800A6138;
extern Battle D_800A6144;
extern Battle D_800A6174;
extern Battle D_800A6180;
extern Battle D_800A618C;
extern Battle D_800A6198;
extern Battle D_800A61A4;
extern Battle D_800A61B0;
extern Battle D_800A61BC;
extern Battle D_800A61C8;
extern Battle D_800A61F8;
extern Battle D_800A6204;
extern Battle D_800A6210;
extern Battle D_800A621C;
extern Battle D_800A6228;
extern Battle D_800A6234;
extern Battle D_800A6240;
extern Battle D_800A624C;
extern Battle D_800A627C;
extern Battle D_800A6288;
extern Battle D_800A6294;
extern Battle D_800A62A0;
extern Battle D_800A62AC;
extern Battle D_800A62B8;
extern Battle D_800A62C4;
extern Battle D_800A62D0;
extern Battle D_800A6300;
extern Battle D_800A630C;
extern Battle D_800A6318;
extern Battle D_800A6324;
extern Battle D_800A6330;
extern Battle D_800A633C;
extern Battle D_800A6348;
extern Battle D_800A6354;
extern Battle D_800A6384;
extern Battle D_800A6390;
extern Battle D_800A639C;
extern Battle D_800A63A8;
extern Battle D_800A63B4;
extern Battle D_800A63C0;
extern Battle D_800A63CC;
extern Battle D_800A63D8;
extern Battle D_800A6408;
extern Battle D_800A6414;
extern Battle D_800A6420;
extern Battle D_800A642C;
extern Battle D_800A6438;
extern Battle D_800A6444;
extern Battle D_800A6450;
extern Battle D_800A645C;
extern Battle D_800A648C;
extern Battle D_800A6498;
extern Battle D_800A64A4;
extern Battle D_800A64B0;
extern Battle D_800A64BC;
extern Battle D_800A64C8;
extern Battle D_800A64D4;
extern Battle D_800A64E0;
extern Battle D_800A6510;
extern Battle D_800A651C;
extern Battle D_800A6528;
extern Battle D_800A6534;
extern Battle D_800A6540;
extern Battle D_800A654C;
extern Battle D_800A6558;
extern Battle D_800A6564;
extern Battle D_800A6594;
extern Battle D_800A65A0;
extern Battle D_800A65AC;
extern Battle D_800A65B8;
extern Battle D_800A65C4;
extern Battle D_800A65D0;
extern Battle D_800A65DC;
extern Battle D_800A65E8;
extern Battle D_800A6618;
extern Battle D_800A6624;
extern Battle D_800A6630;
extern Battle D_800A663C;
extern Battle D_800A6648;
extern Battle D_800A6654;
extern Battle D_800A6660;
extern Battle D_800A666C;
extern Battle D_800A669C;
extern Battle D_800A66A8;
extern Battle D_800A66B4;
extern Battle D_800A66C0;
extern Battle D_800A66CC;
extern Battle D_800A66D8;
extern Battle D_800A66E4;
extern Battle D_800A66F0;
extern Battle D_800A6720;
extern Battle D_800A672C;
extern Battle D_800A6738;
extern Battle D_800A6744;
extern Battle D_800A6750;
extern Battle D_800A675C;
extern Battle D_800A6768;
extern Battle D_800A6774;
extern Battle D_800A67A4;
extern Battle D_800A67B0;
extern Battle D_800A67BC;
extern Battle D_800A67C8;
extern Battle D_800A67D4;
extern Battle D_800A67E0;
extern Battle D_800A67EC;
extern Battle D_800A67F8;
extern Battle D_800A6828;
extern Battle D_800A6834;
extern Battle D_800A6840;
extern Battle D_800A684C;
extern Battle D_800A6858;
extern Battle D_800A6864;
extern Battle D_800A6870;
extern Battle D_800A687C;
extern Battle D_800A68AC;
extern Battle D_800A68B8;
extern Battle D_800A68C4;
extern Battle D_800A68D0;
extern Battle D_800A68DC;
extern Battle D_800A68E8;
extern Battle D_800A68F4;
extern Battle D_800A6900;
extern Battle D_800A6930;
extern Battle D_800A693C;
extern Battle D_800A6948;
extern Battle D_800A6954;
extern Battle D_800A6960;
extern Battle D_800A696C;
extern Battle D_800A6978;
extern Battle D_800A6984;
extern Battle D_800A69B4;
extern Battle D_800A69C0;
extern Battle D_800A69CC;
extern Battle D_800A69D8;
extern Battle D_800A69E4;
extern Battle D_800A69F0;
extern Battle D_800A69FC;
extern Battle D_800A6A08;
extern Battle D_800A6A38;
extern Battle D_800A6A44;
extern Battle D_800A6A50;
extern Battle D_800A6A5C;
extern Battle D_800A6A68;
extern Battle D_800A6A74;
extern Battle D_800A6A80;
extern Battle D_800A6A8C;
extern Battle D_800A6ABC;
extern Battle D_800A6AC8;
extern Battle D_800A6AD4;
extern Battle D_800A6AE0;
extern Battle D_800A6AEC;
extern Battle D_800A6AF8;
extern Battle D_800A6B04;
extern Battle D_800A6B10;
extern Battle D_800A6B40;
extern Battle D_800A6B4C;
extern Battle D_800A6B58;
extern Battle D_800A6B64;
extern Battle D_800A6B70;
extern Battle D_800A6B7C;
extern Battle D_800A6B88;
extern Battle D_800A6B94;
extern Battle D_800A6BC4;
extern Battle D_800A6BD0;
extern Battle D_800A6BDC;
extern Battle D_800A6BE8;
extern Battle D_800A6BF4;
extern Battle D_800A6C00;
extern Battle D_800A6C0C;
extern Battle D_800A6C18;
extern Battle D_800A6C48;
extern Battle D_800A6C54;
extern Battle D_800A6C60;
extern Battle D_800A6C6C;
extern Battle D_800A6C78;
extern Battle D_800A6C84;
extern Battle D_800A6C90;
extern Battle D_800A6C9C;
extern Battle D_800A6CCC;
extern Battle D_800A6CD8;
extern Battle D_800A6CE4;
extern Battle D_800A6CF0;
extern Battle D_800A6CFC;
extern Battle D_800A6D08;
extern Battle D_800A6D14;
extern Battle D_800A6D20;
extern Battle D_800A6D50;
extern Battle D_800A6D5C;
extern Battle D_800A6D68;
extern Battle D_800A6D74;
extern Battle D_800A6D80;
extern Battle D_800A6D8C;
extern Battle D_800A6D98;
extern Battle D_800A6DA4;
extern Battle D_800A6DD4;
extern Battle D_800A6DE0;
extern Battle D_800A6DEC;
extern Battle D_800A6DF8;
extern Battle D_800A6E04;
extern Battle D_800A6E10;
extern Battle D_800A6E1C;
extern Battle D_800A6E28;
extern Battle D_800A6E58;
extern Battle D_800A6E64;
extern Battle D_800A6E70;
extern Battle D_800A6E7C;
extern Battle D_800A6E88;
extern Battle D_800A6E94;
extern Battle D_800A6EA0;
extern Battle D_800A6EAC;
extern Battle D_800A6EDC;
extern Battle D_800A6EE8;
extern Battle D_800A6EF4;
extern Battle D_800A6F00;
extern Battle D_800A6F0C;
extern Battle D_800A6F18;
extern Battle D_800A6F24;
extern Battle D_800A6F30;
extern Battle D_800A6F60;
extern Battle D_800A6F6C;
extern Battle D_800A6F78;
extern Battle D_800A6F84;
extern Battle D_800A6F90;
extern Battle D_800A6F9C;
extern Battle D_800A6FA8;
extern Battle D_800A6FB4;
extern Battle D_800A6FE4;
extern Battle D_800A6FF0;
extern Battle D_800A6FFC;
extern Battle D_800A7008;
extern Battle D_800A7014;
extern Battle D_800A7020;
extern Battle D_800A702C;
extern Battle D_800A7038;
extern Battle D_800A7068;
extern Battle D_800A7074;
extern Battle D_800A7080;
extern Battle D_800A708C;
extern Battle D_800A7098;
extern Battle D_800A70A4;
extern Battle D_800A70B0;
extern Battle D_800A70BC;
extern Battle D_800A70EC;
extern Battle D_800A70F8;
extern Battle D_800A7104;
extern Battle D_800A7110;
extern Battle D_800A711C;
extern Battle D_800A7128;
extern Battle D_800A7134;
extern Battle D_800A7140;
extern Battle D_800A7170;
extern Battle D_800A717C;
extern Battle D_800A7188;
extern Battle D_800A7194;
extern Battle D_800A71A0;
extern Battle D_800A71AC;
extern Battle D_800A71B8;
extern Battle D_800A71C4;
extern Battle D_800A71F4;
extern Battle D_800A7200;
extern Battle D_800A720C;
extern Battle D_800A7218;
extern Battle D_800A7224;
extern Battle D_800A7230;
extern Battle D_800A723C;
extern Battle D_800A7248;
extern Battle D_800A7278;
extern Battle D_800A7284;
extern Battle D_800A7290;
extern Battle D_800A729C;
extern Battle D_800A72A8;
extern Battle D_800A72B4;
extern Battle D_800A72C0;
extern Battle D_800A72CC;
extern Battle D_800A72FC;
extern Battle D_800A7308;
extern Battle D_800A7314;
extern Battle D_800A7320;
extern Battle D_800A732C;
extern Battle D_800A7338;
extern Battle D_800A7344;
extern Battle D_800A7350;
extern Battle D_800A7380;
extern Battle D_800A738C;
extern Battle D_800A7398;
extern Battle D_800A73A4;
extern Battle D_800A73B0;
extern Battle D_800A73BC;
extern Battle D_800A73C8;
extern Battle D_800A73D4;
extern Battle D_800A7404;
extern Battle D_800A7410;
extern Battle D_800A741C;
extern Battle D_800A7428;
extern Battle D_800A7434;
extern Battle D_800A7440;
extern Battle D_800A744C;
extern Battle D_800A7458;
extern Battle D_800A7488;
extern Battle D_800A7494;
extern Battle D_800A74A0;
extern Battle D_800A74AC;
extern Battle D_800A74B8;
extern Battle D_800A74C4;
extern Battle D_800A74D0;
extern Battle D_800A74DC;
extern Battle D_800A750C;
extern Battle D_800A7518;
extern Battle D_800A7524;
extern Battle D_800A7530;
extern Battle D_800A753C;
extern Battle D_800A7548;
extern Battle D_800A7554;
extern Battle D_800A7560;
extern Battle D_800A7590;
extern Battle D_800A759C;
extern Battle D_800A75A8;
extern Battle D_800A75B4;
extern Battle D_800A75C0;
extern Battle D_800A75CC;
extern Battle D_800A75D8;
extern Battle D_800A75E4;
extern Battle D_800A7614;
extern Battle D_800A7620;
extern Battle D_800A762C;
extern Battle D_800A7638;
extern Battle D_800A7644;
extern Battle D_800A7650;
extern Battle D_800A765C;
extern Battle D_800A7668;
extern Battle D_800A7698;
extern Battle D_800A76A4;
extern Battle D_800A76B0;
extern Battle D_800A76BC;
extern Battle D_800A76C8;
extern Battle D_800A76D4;
extern Battle D_800A76E0;
extern Battle D_800A76EC;
extern Battle D_800A771C;
extern Battle D_800A7728;
extern Battle D_800A7734;
extern Battle D_800A7740;
extern Battle D_800A774C;
extern Battle D_800A7758;
extern Battle D_800A7764;
extern Battle D_800A7770;
extern Battle D_800A77A0;
extern Battle D_800A77AC;
extern Battle D_800A77B8;
extern Battle D_800A77C4;
extern Battle D_800A77D0;
extern Battle D_800A77DC;
extern Battle D_800A77E8;
extern Battle D_800A77F4;
extern Battle D_800A7824;
extern Battle D_800A7830;
extern Battle D_800A783C;
extern Battle D_800A7848;
extern Battle D_800A7854;
extern Battle D_800A7860;
extern Battle D_800A786C;
extern Battle D_800A7878;
extern Battle D_800A78A8;
extern Battle D_800A78B4;
extern Battle D_800A78C0;
extern Battle D_800A78CC;
extern Battle D_800A78D8;
extern Battle D_800A78E4;
extern Battle D_800A78F0;
extern Battle D_800A78FC;
extern Battle D_800A792C;
extern Battle D_800A7938;
extern Battle D_800A7944;
extern Battle D_800A7950;
extern Battle D_800A795C;
extern Battle D_800A7968;
extern Battle D_800A7974;
extern Battle D_800A7980;
extern Battle D_800A79B0;
extern Battle D_800A79BC;
extern Battle D_800A79C8;
extern Battle D_800A79D4;
extern Battle D_800A79E0;
extern Battle D_800A79EC;
extern Battle D_800A79F8;
extern Battle D_800A7A04;
extern Battle D_800A7A34;
extern Battle D_800A7A40;
extern Battle D_800A7A4C;
extern Battle D_800A7A58;
extern Battle D_800A7A64;
extern Battle D_800A7A70;
extern Battle D_800A7A7C;
extern Battle D_800A7A88;
extern Battle D_800A7AB8;
extern Battle D_800A7AC4;
extern Battle D_800A7AD0;
extern Battle D_800A7ADC;
extern Battle D_800A7AE8;
extern Battle D_800A7AF4;
extern Battle D_800A7B00;
extern Battle D_800A7B0C;
extern Battle D_800A7B3C;
extern Battle D_800A7B48;
extern Battle D_800A7B54;
extern Battle D_800A7B60;
extern Battle D_800A7B6C;
extern Battle D_800A7B78;
extern Battle D_800A7B84;
extern Battle D_800A7B90;
extern Battle D_800A7BC0;
extern Battle D_800A7BCC;
extern Battle D_800A7BD8;
extern Battle D_800A7BE4;
extern Battle D_800A7BF0;
extern Battle D_800A7BFC;
extern Battle D_800A7C08;
extern Battle D_800A7C14;
extern Battle D_800A7C44;
extern Battle D_800A7C50;
extern Battle D_800A7C5C;
extern Battle D_800A7C68;
extern Battle D_800A7C74;
extern Battle D_800A7C80;
extern Battle D_800A7C8C;
extern Battle D_800A7C98;
extern Battle D_800A7CC8;
extern Battle D_800A7CD4;
extern Battle D_800A7CE0;
extern Battle D_800A7CEC;
extern Battle D_800A7CF8;
extern Battle D_800A7D04;
extern Battle D_800A7D10;
extern Battle D_800A7D1C;
extern Battle D_800A7D4C;
extern Battle D_800A7D58;
extern Battle D_800A7D64;
extern Battle D_800A7D70;
extern Battle D_800A7D7C;
extern Battle D_800A7D88;
extern Battle D_800A7D94;
extern Battle D_800A7DA0;
extern Battle D_800A7DD0;
extern Battle D_800A7DDC;
extern Battle D_800A7DE8;
extern Battle D_800A7DF4;
extern Battle D_800A7E00;
extern Battle D_800A7E0C;
extern Battle D_800A7E18;
extern Battle D_800A7E24;
extern Battle D_800A7E54;
extern Battle D_800A7E60;
extern Battle D_800A7E6C;
extern Battle D_800A7E78;
extern Battle D_800A7E84;
extern Battle D_800A7E90;
extern Battle D_800A7E9C;
extern Battle D_800A7EA8;
extern Battle D_800A7ED8;
extern Battle D_800A7EE4;
extern Battle D_800A7EF0;
extern Battle D_800A7EFC;
extern Battle D_800A7F08;
extern Battle D_800A7F14;
extern Battle D_800A7F20;
extern Battle D_800A7F2C;
extern Battle D_800A7F5C;
extern Battle D_800A7F68;
extern Battle D_800A7F74;
extern Battle D_800A7F80;
extern Battle D_800A7F8C;
extern Battle D_800A7F98;
extern Battle D_800A7FA4;
extern Battle D_800A7FB0;
extern Battle D_800A7FE0;
extern Battle D_800A7FEC;
extern Battle D_800A7FF8;
extern Battle D_800A8004;
extern Battle D_800A8010;
extern Battle D_800A801C;
extern Battle D_800A8028;
extern Battle D_800A8034;
extern Battle D_800A8064;
extern Battle D_800A8070;
extern Battle D_800A807C;
extern Battle D_800A8088;
extern Battle D_800A8094;
extern Battle D_800A80A0;
extern Battle D_800A80AC;
extern Battle D_800A80B8;
extern Battle D_800A80E8;
extern Battle D_800A80F4;
extern Battle D_800A8100;
extern Battle D_800A810C;
extern Battle D_800A8118;
extern Battle D_800A8124;
extern Battle D_800A8130;
extern Battle D_800A813C;
extern Battle D_800A816C;
extern Battle D_800A8178;
extern Battle D_800A8184;
extern Battle D_800A8190;
extern Battle D_800A819C;
extern Battle D_800A81A8;
extern Battle D_800A81B4;
extern Battle D_800A81C0;
extern Battle D_800A81F0;
extern Battle D_800A81FC;
extern Battle D_800A8208;
extern Battle D_800A8214;
extern Battle D_800A8220;
extern Battle D_800A822C;
extern Battle D_800A8238;
extern Battle D_800A8244;
extern Battle D_800A8274;
extern Battle D_800A8280;
extern Battle D_800A828C;
extern Battle D_800A8298;
extern Battle D_800A82A4;
extern Battle D_800A82B0;
extern Battle D_800A82BC;
extern Battle D_800A82C8;
extern Battle D_800A82F8;
extern Battle D_800A8304;
extern Battle D_800A8310;
extern Battle D_800A831C;
extern Battle D_800A8328;
extern Battle D_800A8334;
extern Battle D_800A8340;
extern Battle D_800A834C;
extern Battle D_800A837C;
extern Battle D_800A8388;
extern Battle D_800A8394;
extern Battle D_800A83A0;
extern Battle D_800A83AC;
extern Battle D_800A83B8;
extern Battle D_800A83C4;
extern Battle D_800A83D0;
extern Battle D_800A8400;
extern Battle D_800A840C;
extern Battle D_800A8418;
extern Battle D_800A8424;
extern Battle D_800A8430;
extern Battle D_800A843C;
extern Battle D_800A8448;
extern Battle D_800A8454;
extern Battle D_800A8484;
extern Battle D_800A8490;
extern Battle D_800A849C;
extern Battle D_800A84A8;
extern Battle D_800A84B4;
extern Battle D_800A84C0;
extern Battle D_800A84CC;
extern Battle D_800A84D8;
extern Battle D_800A8508;
extern Battle D_800A8514;
extern Battle D_800A8520;
extern Battle D_800A852C;
extern Battle D_800A8538;
extern Battle D_800A8544;
extern Battle D_800A8550;
extern Battle D_800A855C;
extern Battle D_800A858C;
extern Battle D_800A8598;
extern Battle D_800A85A4;
extern Battle D_800A85B0;
extern Battle D_800A85BC;
extern Battle D_800A85C8;
extern Battle D_800A85D4;
extern Battle D_800A85E0;
extern Battle D_800A8610;
extern Battle D_800A861C;
extern Battle D_800A8628;
extern Battle D_800A8634;
extern Battle D_800A8640;
extern Battle D_800A864C;
extern Battle D_800A8658;
extern Battle D_800A8664;
extern Battle D_800A8694;
extern Battle D_800A86A0;
extern Battle D_800A86AC;
extern Battle D_800A86B8;
extern Battle D_800A86C4;
extern Battle D_800A86D0;
extern Battle D_800A86DC;
extern Battle D_800A86E8;
extern Battle D_800A8718;
extern Battle D_800A8724;
extern Battle D_800A8730;
extern Battle D_800A873C;
extern Battle D_800A8748;
extern Battle D_800A8754;
extern Battle D_800A8760;
extern Battle D_800A876C;
extern Battle D_800A879C;
extern Battle D_800A87A8;
extern Battle D_800A87B4;
extern Battle D_800A87C0;
extern Battle D_800A87CC;
extern Battle D_800A87D8;
extern Battle D_800A87E4;
extern Battle D_800A87F0;
extern Battle D_800A8820;
extern Battle D_800A882C;
extern Battle D_800A8838;
extern Battle D_800A8844;
extern Battle D_800A8850;
extern Battle D_800A885C;
extern Battle D_800A8868;
extern Battle D_800A8874;
extern Battle D_800A88A4;
extern Battle D_800A88B0;
extern Battle D_800A88BC;
extern Battle D_800A88C8;
extern Battle D_800A88D4;
extern Battle D_800A88E0;
extern Battle D_800A88EC;
extern Battle D_800A88F8;
extern Battle D_800A8928;
extern Battle D_800A8934;
extern Battle D_800A8940;
extern Battle D_800A894C;
extern Battle D_800A8958;
extern Battle D_800A8964;
extern Battle D_800A8970;
extern Battle D_800A897C;
extern Battle D_800A89AC;
extern Battle D_800A89B8;
extern Battle D_800A89C4;
extern Battle D_800A89D0;
extern Battle D_800A89DC;
extern Battle D_800A89E8;
extern Battle D_800A89F4;
extern Battle D_800A8A00;
extern Battle D_800A8A30;
extern Battle D_800A8A3C;
extern Battle D_800A8A48;
extern Battle D_800A8A54;
extern Battle D_800A8A60;
extern Battle D_800A8A6C;
extern Battle D_800A8A78;
extern Battle D_800A8A84;
extern Battle D_800A8AB4;
extern Battle D_800A8AC0;
extern Battle D_800A8ACC;
extern Battle D_800A8AD8;
extern Battle D_800A8AE4;
extern Battle D_800A8AF0;
extern Battle D_800A8AFC;
extern Battle D_800A8B08;
extern Battle D_800A8B38;
extern Battle D_800A8B44;
extern Battle D_800A8B50;
extern Battle D_800A8B5C;
extern Battle D_800A8B68;
extern Battle D_800A8B74;
extern Battle D_800A8B80;
extern Battle D_800A8B8C;
extern Battle D_800A8BBC;
extern Battle D_800A8BC8;
extern Battle D_800A8BD4;
extern Battle D_800A8BE0;
extern Battle D_800A8BEC;
extern Battle D_800A8BF8;
extern Battle D_800A8C04;
extern Battle D_800A8C10;
extern Battle D_800A8C40;
extern Battle D_800A8C4C;
extern Battle D_800A8C58;
extern Battle D_800A8C64;
extern Battle D_800A8C70;
extern Battle D_800A8C7C;
extern Battle D_800A8C88;
extern Battle D_800A8C94;
extern Battle D_800A8CC4;
extern Battle D_800A8CD0;
extern Battle D_800A8CDC;
extern Battle D_800A8CE8;
extern Battle D_800A8CF4;
extern Battle D_800A8D00;
extern Battle D_800A8D0C;
extern Battle D_800A8D18;
extern Battle D_800A8D48;
extern Battle D_800A8D54;
extern Battle D_800A8D60;
extern Battle D_800A8D6C;
extern Battle D_800A8D78;
extern Battle D_800A8D84;
extern Battle D_800A8D90;
extern Battle D_800A8D9C;
extern Battle D_800A8DCC;
extern Battle D_800A8DD8;
extern Battle D_800A8DE4;
extern Battle D_800A8DF0;
extern Battle D_800A8DFC;
extern Battle D_800A8E08;
extern Battle D_800A8E14;
extern Battle D_800A8E20;
extern Battle D_800A8E50;
extern Battle D_800A8E5C;
extern Battle D_800A8E68;
extern Battle D_800A8E74;
extern Battle D_800A8E80;
extern Battle D_800A8E8C;
extern Battle D_800A8E98;
extern Battle D_800A8EA4;
extern Battle D_800A8ED4;
extern Battle D_800A8EE0;
extern Battle D_800A8EEC;
extern Battle D_800A8EF8;
extern Battle D_800A8F04;
extern Battle D_800A8F10;
extern Battle D_800A8F1C;
extern Battle D_800A8F28;
extern Battle D_800A8F58;
extern Battle D_800A8F64;
extern Battle D_800A8F70;
extern Battle D_800A8F7C;
extern Battle D_800A8F88;
extern Battle D_800A8F94;
extern Battle D_800A8FA0;
extern Battle D_800A8FAC;
extern Battle D_800A8FDC;
extern Battle D_800A8FE8;
extern Battle D_800A8FF4;
extern Battle D_800A9000;
extern Battle D_800A900C;
extern Battle D_800A9018;
extern Battle D_800A9024;
extern Battle D_800A9030;
extern Battle D_800A9060;
extern Battle D_800A906C;
extern Battle D_800A9078;
extern Battle D_800A9084;
extern Battle D_800A9090;
extern Battle D_800A909C;
extern Battle D_800A90A8;
extern Battle D_800A90B4;
extern BattleList D_800A5784;
extern BattleList D_800A5808;
extern BattleList D_800A588C;
extern BattleList D_800A5910;
extern BattleList D_800A5994;
extern BattleList D_800A5A18;
extern BattleList D_800A5A9C;
extern BattleList D_800A5B20;
extern BattleList D_800A5BA4;
extern BattleList D_800A5C28;
extern BattleList D_800A5CAC;
extern BattleList D_800A5D30;
extern BattleList D_800A5DB4;
extern BattleList D_800A5E38;
extern BattleList D_800A5EBC;
extern BattleList D_800A5F40;
extern BattleList D_800A5FC4;
extern BattleList D_800A6048;
extern BattleList D_800A60CC;
extern BattleList D_800A6150;
extern BattleList D_800A61D4;
extern BattleList D_800A6258;
extern BattleList D_800A62DC;
extern BattleList D_800A6360;
extern BattleList D_800A63E4;
extern BattleList D_800A6468;
extern BattleList D_800A64EC;
extern BattleList D_800A6570;
extern BattleList D_800A65F4;
extern BattleList D_800A6678;
extern BattleList D_800A66FC;
extern BattleList D_800A6780;
extern BattleList D_800A6804;
extern BattleList D_800A6888;
extern BattleList D_800A690C;
extern BattleList D_800A6990;
extern BattleList D_800A6A14;
extern BattleList D_800A6A98;
extern BattleList D_800A6B1C;
extern BattleList D_800A6BA0;
extern BattleList D_800A6C24;
extern BattleList D_800A6CA8;
extern BattleList D_800A6D2C;
extern BattleList D_800A6DB0;
extern BattleList D_800A6E34;
extern BattleList D_800A6EB8;
extern BattleList D_800A6F3C;
extern BattleList D_800A6FC0;
extern BattleList D_800A7044;
extern BattleList D_800A70C8;
extern BattleList D_800A714C;
extern BattleList D_800A71D0;
extern BattleList D_800A7254;
extern BattleList D_800A72D8;
extern BattleList D_800A735C;
extern BattleList D_800A73E0;
extern BattleList D_800A7464;
extern BattleList D_800A74E8;
extern BattleList D_800A756C;
extern BattleList D_800A75F0;
extern BattleList D_800A7674;
extern BattleList D_800A76F8;
extern BattleList D_800A777C;
extern BattleList D_800A7800;
extern BattleList D_800A7884;
extern BattleList D_800A7908;
extern BattleList D_800A798C;
extern BattleList D_800A7A10;
extern BattleList D_800A7A94;
extern BattleList D_800A7B18;
extern BattleList D_800A7B9C;
extern BattleList D_800A7C20;
extern BattleList D_800A7CA4;
extern BattleList D_800A7D28;
extern BattleList D_800A7DAC;
extern BattleList D_800A7E30;
extern BattleList D_800A7EB4;
extern BattleList D_800A7F38;
extern BattleList D_800A7FBC;
extern BattleList D_800A8040;
extern BattleList D_800A80C4;
extern BattleList D_800A8148;
extern BattleList D_800A81CC;
extern BattleList D_800A8250;
extern BattleList D_800A82D4;
extern BattleList D_800A8358;
extern BattleList D_800A83DC;
extern BattleList D_800A8460;
extern BattleList D_800A84E4;
extern BattleList D_800A8568;
extern BattleList D_800A85EC;
extern BattleList D_800A8670;
extern BattleList D_800A86F4;
extern BattleList D_800A8778;
extern BattleList D_800A87FC;
extern BattleList D_800A8880;
extern BattleList D_800A8904;
extern BattleList D_800A8988;
extern BattleList D_800A8A0C;
extern BattleList D_800A8A90;
extern BattleList D_800A8B14;
extern BattleList D_800A8B98;
extern BattleList D_800A8C1C;
extern BattleList D_800A8CA0;
extern BattleList D_800A8D24;
extern BattleList D_800A8DA8;
extern BattleList D_800A8E2C;
extern BattleList D_800A8EB0;
extern BattleList D_800A8F34;
extern BattleList D_800A8FB8;
extern BattleList D_800A903C;
extern BattleList D_800A90C0;
extern u16 D_800A951C[];
extern FieldTalk D_800A94A4[];
extern u16 D_800A9528[];
extern FieldTalk D_800A94BC[];
extern u16 D_800A9534[];
extern FieldTalk D_800A94D4[];
extern u16 D_800A9540[];
extern FieldTalk D_800A94EC[];
extern u16 D_800A954C[];
extern FieldTalk D_800A9504[];
extern u16 D_800A9558[];
extern u16 D_800A9564[];
extern u16 D_800A9570[];
extern u16 D_800A957C[];
extern u16 D_800A9588[];
extern u16 D_800A9594[];
extern u16 D_800A95A0[];
extern u16 D_800A95AC[];
extern u16 D_800A95B8[];
extern u16 D_800A95C4[];
extern FieldActorEntry D_800A95D0;
extern FieldActorEntry D_800A95E4;
extern FieldActorEntry D_800A95F8;
extern FieldActorEntry D_800A960C;
extern FieldActorEntry D_800A9620;
extern FieldActorEntry D_800A9634;
extern FieldActorEntry D_800A9648;
extern FieldActorEntry D_800A965C;
extern FieldActorEntry D_800A9670;
extern FieldActorEntry D_800A9684;
extern FieldActorEntry D_800A9698;
extern FieldActorEntry D_800A96AC;
extern FieldActorEntry D_800A96C0;
extern FieldActorEntry D_800A96D4;
extern FieldActorEntry D_800A96E8;
extern FieldActorEntry D_800A96FC;

StagePoint D_800A4F90 = { 0x2EC, 1, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A4FA0 = { 0x21D, 0, 0, 0x410, 0x400, 0, &D_800A4F90 };
StagePoints D_800A4FB0 = { 1, 1, &D_800A4FA0 };
StagePoint D_800A4FB8 = { 0x2ED, 1, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A4FC8 = { 0x248, 0, 0, 0x320, 0x518, 0, &D_800A4FB8 };
StagePoints D_800A4FD8 = { 1, 2, &D_800A4FC8 };
StagePoint D_800A4FE0 = { 0x2EC, 2, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A4FF0 = { 0x261, 0, 0, 176, 0x2EE, 0, &D_800A4FE0 };
StagePoints D_800A5000 = { 2, 1, &D_800A4FF0 };
StagePoint D_800A5008 = { 0x2EC, 3, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5018 = { 0x2CD, 0, 0, 0x1C0, 0x206, 0, &D_800A5008 };
StagePoints D_800A5028 = { 3, 1, &D_800A5018 };
StagePoint D_800A5030 = { 0x2ED, 3, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A5040 = { 0x2A7, 0, 0, 0x560, 0x188, 0, &D_800A5030 };
StagePoints D_800A5050 = { 3, 2, &D_800A5040 };
StagePoint D_800A5058 = { 0x2EE, 3, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5068 = { 0x21D, 0, 0, 0x110, 0x290, 0, &D_800A5058 };
StagePoints D_800A5078 = { 3, 3, &D_800A5068 };
StagePoint D_800A5080 = { 0x2ED, 3, 4, 0x3A0, 128, 1, NULL };
StagePoint D_800A5090 = { 0x28C, 0, 0, 0x110, 0x290, 0, &D_800A5080 };
StagePoints D_800A50A0 = { 3, 4, &D_800A5090 };
StagePoint D_800A50A8 = { 0x2EE, 3, 5, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A50B8 = { 0x2B1, 0, 0, 0x3D0, 0x100, 0, &D_800A50A8 };
StagePoints D_800A50C8 = { 3, 5, &D_800A50B8 };
StagePoint D_800A50D0 = { 0x2EE, 4, 1, 0x130, 200, 1, NULL };
StagePoint D_800A50E0 = { 0x23C, 0, 0, 192, 224, 0, &D_800A50D0 };
StagePoints D_800A50F0 = { 4, 1, &D_800A50E0 };
StagePoint D_800A50F8 = { 0x2EE, 4, 2, 0x130, 200, 1, NULL };
StagePoint D_800A5108 = { 0x2A9, 0, 0, 192, 224, 0, &D_800A50F8 };
StagePoints D_800A5118 = { 4, 2, &D_800A5108 };
StagePoint D_800A5120 = { 0x2EE, 5, 1, 0x130, 200, 1, NULL };
StagePoint D_800A5130 = { 0x2CD, 0, 0, 0x4C0, 200, 0, &D_800A5120 };
StagePoints D_800A5140 = { 5, 1, &D_800A5130 };
StagePoint D_800A5148 = { 0x2EE, 5, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5158 = { 0x2C9, 0, 0, 0x4B0, 0x13E, 0, &D_800A5148 };
StagePoints D_800A5168 = { 5, 2, &D_800A5158 };
StagePoint D_800A5170 = { 0x2ED, 5, 4, 0x3A0, 128, 1, NULL };
StagePoint D_800A5180 = { 0x2CC, 0, 0, 192, 0x214, 0, &D_800A5170 };
StagePoints D_800A5190 = { 5, 3, &D_800A5180 };
StagePoint D_800A5198 = { 0x2ED, 6, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A51A8 = { 0x247, 0, 0, 0x190, 0x1C0, 0, &D_800A5198 };
StagePoints D_800A51B8 = { 6, 1, &D_800A51A8 };
StagePoint D_800A51C0 = { 0x2EC, 7, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A51D0 = { 0x2CA, 0, 0, 0x3BE, 0x2EE, 0, &D_800A51C0 };
StagePoints D_800A51E0 = { 7, 1, &D_800A51D0 };
StagePoint D_800A51E8 = { 0x2EC, 7, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A51F8 = { 0x262, 0, 0, 0x3BE, 0x2EE, 0, &D_800A51E8 };
StagePoints D_800A5208 = { 7, 2, &D_800A51F8 };
StagePoint D_800A5210 = { 0x2EE, 7, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5220 = { 0x298, 0, 0, 0x560, 0x238, 0, &D_800A5210 };
StagePoints D_800A5230 = { 7, 3, &D_800A5220 };
StagePoint D_800A5238 = { 0x2ED, 8, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A5248 = { 0x2B2, 0, 0, 0x320, 0x518, 0, &D_800A5238 };
StagePoints D_800A5258 = { 8, 1, &D_800A5248 };
StagePoint D_800A5260 = { 0x2EC, 8, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5270 = { 0x28C, 0, 0, 0x410, 0x400, 0, &D_800A5260 };
StagePoints D_800A5280 = { 8, 2, &D_800A5270 };
StagePoint D_800A5288 = { 0x2EC, 9, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5298 = { 0x2C9, 0, 0, 176, 0x2EE, 0, &D_800A5288 };
StagePoints D_800A52A8 = { 9, 1, &D_800A5298 };
StagePoint D_800A52B0 = { 0x2EC, 10, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A52C0 = { 0x265, 0, 0, 0x4AE, 0x1EF, 0, &D_800A52B0 };
StagePoints D_800A52D0 = { 10, 1, &D_800A52C0 };
StagePoint D_800A52D8 = { 0x2ED, 10, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A52E8 = { 0x264, 0, 0, 0x100, 0x2A4, 0, &D_800A52D8 };
StagePoints D_800A52F8 = { 10, 2, &D_800A52E8 };
StagePoint D_800A5300 = { 0x2EC, 11, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5310 = { 0x2CD, 0, 0, 0x4AE, 0x1EF, 0, &D_800A5300 };
StagePoints D_800A5320 = { 11, 1, &D_800A5310 };
StagePoint D_800A5328 = { 0x2ED, 11, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A5338 = { 0x2CC, 0, 0, 0x100, 0x2A4, 0, &D_800A5328 };
StagePoints D_800A5348 = { 11, 2, &D_800A5338 };
StagePoint D_800A5350 = { 0x2ED, 12, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A5360 = { 0x261, 0, 0, 0x2F0, 0x30E, 0, &D_800A5350 };
StagePoints D_800A5370 = { 12, 1, &D_800A5360 };
StagePoint D_800A5378 = { 0x2EC, 13, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A5388 = { 0x2C9, 0, 0, 0x2F0, 0x30E, 0, &D_800A5378 };
StagePoints D_800A5398 = { 13, 1, &D_800A5388 };
StagePoint D_800A53A0 = { 0x2EB, 15, 1, 0x240, 160, 1, NULL };
StagePoint D_800A53B0 = { 0x220, 0, 0, 0x398, 0x270, 0, &D_800A53A0 };
StagePoints D_800A53C0 = { 15, 1, &D_800A53B0 };
StagePoint D_800A53C8 = { 0x2EE, 16, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A53D8 = { 0x24C, 0, 0, 0x200, 0x178, 0, &D_800A53C8 };
StagePoints D_800A53E8 = { 16, 1, &D_800A53D8 };
StagePoint D_800A53F0 = { 0x2EB, 17, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5400 = { 0x21D, 0, 0, 0x290, 0x200, 0, &D_800A53F0 };
StagePoints D_800A5410 = { 17, 1, &D_800A5400 };
StagePoint D_800A5418 = { 0x2EC, 18, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5428 = { 0x2B4, 0, 0, 0x3F0, 0x330, 0, &D_800A5418 };
StagePoints D_800A5438 = { 18, 1, &D_800A5428 };
StagePoint D_800A5440 = { 0x2EC, 19, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A5450 = { 0x262, 0, 0, 190, 166, 0, &D_800A5440 };
StagePoints D_800A5460 = { 19, 1, &D_800A5450 };
StagePoint D_800A5468 = { 0x2EE, 20, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5478 = { 0x2CA, 0, 0, 190, 166, 0, &D_800A5468 };
StagePoints D_800A5488 = { 20, 1, &D_800A5478 };
StagePoint D_800A5490 = { 0x2EE, 21, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A54A0 = { 0x264, 0, 0, 0x3A0, 180, 0, &D_800A5490 };
StagePoints D_800A54B0 = { 21, 1, &D_800A54A0 };
StagePoint D_800A54B8 = { 0x2EC, 22, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A54C8 = { 0x265, 0, 0, 0x23F, 0x317, 0, &D_800A54B8 };
StagePoints D_800A54D8 = { 22, 1, &D_800A54C8 };
StagePoint D_800A54E0 = { 0x2EC, 22, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A54F0 = { 0x261, 0, 0, 0x1A0, 0x166, 0, &D_800A54E0 };
StagePoints D_800A5500 = { 22, 2, &D_800A54F0 };
StagePoint D_800A5508 = { 0x2EC, 23, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5518 = { 0x2CD, 0, 0, 0x23F, 0x317, 0, &D_800A5508 };
StagePoints D_800A5528 = { 23, 1, &D_800A5518 };
StagePoint D_800A5530 = { 0x2EE, 23, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5540 = { 0x2C9, 0, 0, 0x1A0, 0x166, 0, &D_800A5530 };
StagePoints D_800A5550 = { 23, 2, &D_800A5540 };
StagePoint D_800A5558 = { 0x2EC, 24, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5568 = { 0x2CC, 0, 0, 0x3A0, 180, 0, &D_800A5558 };
StagePoints D_800A5578 = { 24, 1, &D_800A5568 };
StagePoint D_800A5580 = { 0x2EE, 25, 1, 0x130, 200, 1, NULL };
StagePoint D_800A5590 = { 0x2B6, 0, 0, 0x200, 0x178, 0, &D_800A5580 };
StagePoints D_800A55A0 = { 25, 1, &D_800A5590 };
StagePoint D_800A55A8 = { 0x2EB, 26, 1, 0x240, 160, 1, NULL };
StagePoint D_800A55B8 = { 0x2A7, 0, 0, 0x1C1, 0x37A, 0, &D_800A55A8 };
StagePoints D_800A55C8 = { 26, 1, &D_800A55B8 };
StagePoint D_800A55D0 = { 0x2ED, 28, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A55E0 = { 0x28C, 0, 0, 0x290, 0x200, 0, &D_800A55D0 };
StagePoints D_800A55F0 = { 28, 1, &D_800A55E0 };
StagePoint D_800A55F8 = { 0x2EC, 29, 1, 0x3B0, 120, 1, NULL };
StagePoint D_800A5608 = { 0x28F, 0, 0, 0x398, 0x270, 0, &D_800A55F8 };
StagePoints D_800A5618 = { 29, 1, &D_800A5608 };
StagePoint D_800A5620 = { 0x2ED, 30, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A5630 = { 0x2B4, 0, 0, 0x2C0, 0x2A8, 0, &D_800A5620 };
StagePoints D_800A5640 = { 30, 1, &D_800A5630 };
StagePoint D_800A5648 = { 0x2ED, 30, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A5658 = { 0x2B2, 0, 0, 0x2A0, 0x138, 0, &D_800A5648 };
StagePoints D_800A5668 = { 30, 2, &D_800A5658 };
StagePoints *placePoints[] = {
    &D_800A4FB0, &D_800A4FD8, &D_800A5000, &D_800A5028,
    &D_800A5050, &D_800A5078, &D_800A50A0, &D_800A50C8,
    &D_800A50F0, &D_800A5118, &D_800A5140, &D_800A5168,
    &D_800A5190, &D_800A51B8, &D_800A51E0, &D_800A5208,
    &D_800A5230, &D_800A5258, &D_800A5280, &D_800A52A8,
    &D_800A52D0, &D_800A52F8, &D_800A5320, &D_800A5348,
    &D_800A5370, &D_800A5398, &D_800A53C0, &D_800A53E8,
    &D_800A5410, &D_800A5438, &D_800A5460, &D_800A5488,
    &D_800A54B0, &D_800A54D8, &D_800A5500, &D_800A5528,
    &D_800A5550, &D_800A5578, &D_800A55A0, &D_800A55C8,
    &D_800A55F0, &D_800A5618, &D_800A5640, &D_800A5668,
    NULL,
};
Battle D_800A5724 = { 174, 10, 0x60080000 };
Battle D_800A5730 = { 174, 10, 0x60080000 };
Battle D_800A573C = { 170, 10, 0x60080000 };
Battle D_800A5748 = { 170, 10, 0x60080000 };
Battle D_800A5754 = { 170, 10, 0x60080000 };
Battle D_800A5760 = { 170, 10, 0x60080000 };
Battle D_800A576C = { 170, 10, 0x60080000 };
Battle D_800A5778 = { 170, 10, 0x60080000 };
BattleList D_800A5784 = {
    1,
    { &D_800A5724, &D_800A5730, &D_800A573C, &D_800A5748,
      &D_800A5754, &D_800A5760, &D_800A576C, &D_800A5778 },
};
Battle D_800A57A8 = { 0, 0, 0x60040000 };
Battle D_800A57B4 = { 0, 0, 0x60040000 };
Battle D_800A57C0 = { 0, 0, 0x60040000 };
Battle D_800A57CC = { 0, 0, 0x60040000 };
Battle D_800A57D8 = { 0, 0, 0x60040000 };
Battle D_800A57E4 = { 0, 0, 0x60040000 };
Battle D_800A57F0 = { 0, 0, 0x60040000 };
Battle D_800A57FC = { 0, 0, 0x60040000 };
BattleList D_800A5808 = {
    0,
    { &D_800A57A8, &D_800A57B4, &D_800A57C0, &D_800A57CC,
      &D_800A57D8, &D_800A57E4, &D_800A57F0, &D_800A57FC },
};
Battle D_800A582C = { 0, 0, 0x60040000 };
Battle D_800A5838 = { 0, 0, 0x60040000 };
Battle D_800A5844 = { 0, 0, 0x60040000 };
Battle D_800A5850 = { 0, 0, 0x60040000 };
Battle D_800A585C = { 0, 0, 0x60040000 };
Battle D_800A5868 = { 0, 0, 0x60040000 };
Battle D_800A5874 = { 0, 0, 0x60040000 };
Battle D_800A5880 = { 0, 0, 0x60040000 };
BattleList D_800A588C = {
    0,
    { &D_800A582C, &D_800A5838, &D_800A5844, &D_800A5850,
      &D_800A585C, &D_800A5868, &D_800A5874, &D_800A5880 },
};
Battle D_800A58B0 = { 0, 0, 0x60040000 };
Battle D_800A58BC = { 0, 0, 0x60040000 };
Battle D_800A58C8 = { 0, 0, 0x60040000 };
Battle D_800A58D4 = { 0, 0, 0x60040000 };
Battle D_800A58E0 = { 0, 0, 0x60040000 };
Battle D_800A58EC = { 0, 0, 0x60040000 };
Battle D_800A58F8 = { 0, 0, 0x60040000 };
Battle D_800A5904 = { 0, 0, 0x60040000 };
BattleList D_800A5910 = {
    0,
    { &D_800A58B0, &D_800A58BC, &D_800A58C8, &D_800A58D4,
      &D_800A58E0, &D_800A58EC, &D_800A58F8, &D_800A5904 },
};
Battle D_800A5934 = { 174, 10, 0x60080000 };
Battle D_800A5940 = { 174, 10, 0x60080000 };
Battle D_800A594C = { 170, 10, 0x60080000 };
Battle D_800A5958 = { 170, 10, 0x60080000 };
Battle D_800A5964 = { 170, 10, 0x60080000 };
Battle D_800A5970 = { 110, 10, 0x60080000 };
Battle D_800A597C = { 110, 10, 0x60080000 };
Battle D_800A5988 = { 110, 10, 0x60080000 };
BattleList D_800A5994 = {
    1,
    { &D_800A5934, &D_800A5940, &D_800A594C, &D_800A5958,
      &D_800A5964, &D_800A5970, &D_800A597C, &D_800A5988 },
};
Battle D_800A59B8 = { 0, 0, 0x60040000 };
Battle D_800A59C4 = { 0, 0, 0x60040000 };
Battle D_800A59D0 = { 0, 0, 0x60040000 };
Battle D_800A59DC = { 0, 0, 0x60040000 };
Battle D_800A59E8 = { 0, 0, 0x60040000 };
Battle D_800A59F4 = { 0, 0, 0x60040000 };
Battle D_800A5A00 = { 0, 0, 0x60040000 };
Battle D_800A5A0C = { 0, 0, 0x60040000 };
BattleList D_800A5A18 = {
    0,
    { &D_800A59B8, &D_800A59C4, &D_800A59D0, &D_800A59DC,
      &D_800A59E8, &D_800A59F4, &D_800A5A00, &D_800A5A0C },
};
Battle D_800A5A3C = { 0, 0, 0x60040000 };
Battle D_800A5A48 = { 0, 0, 0x60040000 };
Battle D_800A5A54 = { 0, 0, 0x60040000 };
Battle D_800A5A60 = { 0, 0, 0x60040000 };
Battle D_800A5A6C = { 0, 0, 0x60040000 };
Battle D_800A5A78 = { 0, 0, 0x60040000 };
Battle D_800A5A84 = { 0, 0, 0x60040000 };
Battle D_800A5A90 = { 0, 0, 0x60040000 };
BattleList D_800A5A9C = {
    0,
    { &D_800A5A3C, &D_800A5A48, &D_800A5A54, &D_800A5A60,
      &D_800A5A6C, &D_800A5A78, &D_800A5A84, &D_800A5A90 },
};
Battle D_800A5AC0 = { 0, 0, 0x60040000 };
Battle D_800A5ACC = { 0, 0, 0x60040000 };
Battle D_800A5AD8 = { 0, 0, 0x60040000 };
Battle D_800A5AE4 = { 0, 0, 0x60040000 };
Battle D_800A5AF0 = { 0, 0, 0x60040000 };
Battle D_800A5AFC = { 0, 0, 0x60040000 };
Battle D_800A5B08 = { 0, 0, 0x60040000 };
Battle D_800A5B14 = { 0, 0, 0x60040000 };
BattleList D_800A5B20 = {
    0,
    { &D_800A5AC0, &D_800A5ACC, &D_800A5AD8, &D_800A5AE4,
      &D_800A5AF0, &D_800A5AFC, &D_800A5B08, &D_800A5B14 },
};
Battle D_800A5B44 = { 174, 10, 0x60080000 };
Battle D_800A5B50 = { 174, 10, 0x60080000 };
Battle D_800A5B5C = { 170, 10, 0x60080000 };
Battle D_800A5B68 = { 170, 10, 0x60080000 };
Battle D_800A5B74 = { 182, 10, 0x60080000 };
Battle D_800A5B80 = { 182, 10, 0x60080000 };
Battle D_800A5B8C = { 71, 10, 0x60080000 };
Battle D_800A5B98 = { 71, 10, 0x60080000 };
BattleList D_800A5BA4 = {
    1,
    { &D_800A5B44, &D_800A5B50, &D_800A5B5C, &D_800A5B68,
      &D_800A5B74, &D_800A5B80, &D_800A5B8C, &D_800A5B98 },
};
Battle D_800A5BC8 = { 0, 0, 0x60040000 };
Battle D_800A5BD4 = { 0, 0, 0x60040000 };
Battle D_800A5BE0 = { 0, 0, 0x60040000 };
Battle D_800A5BEC = { 0, 0, 0x60040000 };
Battle D_800A5BF8 = { 0, 0, 0x60040000 };
Battle D_800A5C04 = { 0, 0, 0x60040000 };
Battle D_800A5C10 = { 0, 0, 0x60040000 };
Battle D_800A5C1C = { 0, 0, 0x60040000 };
BattleList D_800A5C28 = {
    0,
    { &D_800A5BC8, &D_800A5BD4, &D_800A5BE0, &D_800A5BEC,
      &D_800A5BF8, &D_800A5C04, &D_800A5C10, &D_800A5C1C },
};
Battle D_800A5C4C = { 0, 0, 0x60040000 };
Battle D_800A5C58 = { 0, 0, 0x60040000 };
Battle D_800A5C64 = { 0, 0, 0x60040000 };
Battle D_800A5C70 = { 0, 0, 0x60040000 };
Battle D_800A5C7C = { 0, 0, 0x60040000 };
Battle D_800A5C88 = { 0, 0, 0x60040000 };
Battle D_800A5C94 = { 0, 0, 0x60040000 };
Battle D_800A5CA0 = { 0, 0, 0x60040000 };
BattleList D_800A5CAC = {
    0,
    { &D_800A5C4C, &D_800A5C58, &D_800A5C64, &D_800A5C70,
      &D_800A5C7C, &D_800A5C88, &D_800A5C94, &D_800A5CA0 },
};
Battle D_800A5CD0 = { 0, 0, 0x60040000 };
Battle D_800A5CDC = { 0, 0, 0x60040000 };
Battle D_800A5CE8 = { 0, 0, 0x60040000 };
Battle D_800A5CF4 = { 0, 0, 0x60040000 };
Battle D_800A5D00 = { 0, 0, 0x60040000 };
Battle D_800A5D0C = { 0, 0, 0x60040000 };
Battle D_800A5D18 = { 0, 0, 0x60040000 };
Battle D_800A5D24 = { 0, 0, 0x60040000 };
BattleList D_800A5D30 = {
    0,
    { &D_800A5CD0, &D_800A5CDC, &D_800A5CE8, &D_800A5CF4,
      &D_800A5D00, &D_800A5D0C, &D_800A5D18, &D_800A5D24 },
};
Battle D_800A5D54 = { 174, 10, 0x60080000 };
Battle D_800A5D60 = { 174, 10, 0x60080000 };
Battle D_800A5D6C = { 170, 10, 0x60080000 };
Battle D_800A5D78 = { 170, 10, 0x60080000 };
Battle D_800A5D84 = { 182, 10, 0x60080000 };
Battle D_800A5D90 = { 182, 10, 0x60080000 };
Battle D_800A5D9C = { 71, 10, 0x60080000 };
Battle D_800A5DA8 = { 71, 10, 0x60080000 };
BattleList D_800A5DB4 = {
    1,
    { &D_800A5D54, &D_800A5D60, &D_800A5D6C, &D_800A5D78,
      &D_800A5D84, &D_800A5D90, &D_800A5D9C, &D_800A5DA8 },
};
Battle D_800A5DD8 = { 0, 0, 0x60040000 };
Battle D_800A5DE4 = { 0, 0, 0x60040000 };
Battle D_800A5DF0 = { 0, 0, 0x60040000 };
Battle D_800A5DFC = { 0, 0, 0x60040000 };
Battle D_800A5E08 = { 0, 0, 0x60040000 };
Battle D_800A5E14 = { 0, 0, 0x60040000 };
Battle D_800A5E20 = { 0, 0, 0x60040000 };
Battle D_800A5E2C = { 0, 0, 0x60040000 };
BattleList D_800A5E38 = {
    0,
    { &D_800A5DD8, &D_800A5DE4, &D_800A5DF0, &D_800A5DFC,
      &D_800A5E08, &D_800A5E14, &D_800A5E20, &D_800A5E2C },
};
Battle D_800A5E5C = { 0, 0, 0x60040000 };
Battle D_800A5E68 = { 0, 0, 0x60040000 };
Battle D_800A5E74 = { 0, 0, 0x60040000 };
Battle D_800A5E80 = { 0, 0, 0x60040000 };
Battle D_800A5E8C = { 0, 0, 0x60040000 };
Battle D_800A5E98 = { 0, 0, 0x60040000 };
Battle D_800A5EA4 = { 0, 0, 0x60040000 };
Battle D_800A5EB0 = { 0, 0, 0x60040000 };
BattleList D_800A5EBC = {
    0,
    { &D_800A5E5C, &D_800A5E68, &D_800A5E74, &D_800A5E80,
      &D_800A5E8C, &D_800A5E98, &D_800A5EA4, &D_800A5EB0 },
};
Battle D_800A5EE0 = { 0, 0, 0x60040000 };
Battle D_800A5EEC = { 0, 0, 0x60040000 };
Battle D_800A5EF8 = { 0, 0, 0x60040000 };
Battle D_800A5F04 = { 0, 0, 0x60040000 };
Battle D_800A5F10 = { 0, 0, 0x60040000 };
Battle D_800A5F1C = { 0, 0, 0x60040000 };
Battle D_800A5F28 = { 0, 0, 0x60040000 };
Battle D_800A5F34 = { 0, 0, 0x60040000 };
BattleList D_800A5F40 = {
    0,
    { &D_800A5EE0, &D_800A5EEC, &D_800A5EF8, &D_800A5F04,
      &D_800A5F10, &D_800A5F1C, &D_800A5F28, &D_800A5F34 },
};
Battle D_800A5F64 = { 174, 10, 0x60080000 };
Battle D_800A5F70 = { 170, 10, 0x60080000 };
Battle D_800A5F7C = { 110, 10, 0x60080000 };
Battle D_800A5F88 = { 110, 10, 0x60080000 };
Battle D_800A5F94 = { 182, 10, 0x60080000 };
Battle D_800A5FA0 = { 182, 10, 0x60080000 };
Battle D_800A5FAC = { 71, 10, 0x60080000 };
Battle D_800A5FB8 = { 71, 10, 0x60080000 };
BattleList D_800A5FC4 = {
    1,
    { &D_800A5F64, &D_800A5F70, &D_800A5F7C, &D_800A5F88,
      &D_800A5F94, &D_800A5FA0, &D_800A5FAC, &D_800A5FB8 },
};
Battle D_800A5FE8 = { 0, 0, 0x60040000 };
Battle D_800A5FF4 = { 0, 0, 0x60040000 };
Battle D_800A6000 = { 0, 0, 0x60040000 };
Battle D_800A600C = { 0, 0, 0x60040000 };
Battle D_800A6018 = { 0, 0, 0x60040000 };
Battle D_800A6024 = { 0, 0, 0x60040000 };
Battle D_800A6030 = { 0, 0, 0x60040000 };
Battle D_800A603C = { 0, 0, 0x60040000 };
BattleList D_800A6048 = {
    0,
    { &D_800A5FE8, &D_800A5FF4, &D_800A6000, &D_800A600C,
      &D_800A6018, &D_800A6024, &D_800A6030, &D_800A603C },
};
Battle D_800A606C = { 0, 0, 0x60040000 };
Battle D_800A6078 = { 0, 0, 0x60040000 };
Battle D_800A6084 = { 0, 0, 0x60040000 };
Battle D_800A6090 = { 0, 0, 0x60040000 };
Battle D_800A609C = { 0, 0, 0x60040000 };
Battle D_800A60A8 = { 0, 0, 0x60040000 };
Battle D_800A60B4 = { 0, 0, 0x60040000 };
Battle D_800A60C0 = { 0, 0, 0x60040000 };
BattleList D_800A60CC = {
    0,
    { &D_800A606C, &D_800A6078, &D_800A6084, &D_800A6090,
      &D_800A609C, &D_800A60A8, &D_800A60B4, &D_800A60C0 },
};
Battle D_800A60F0 = { 0, 0, 0x60040000 };
Battle D_800A60FC = { 0, 0, 0x60040000 };
Battle D_800A6108 = { 0, 0, 0x60040000 };
Battle D_800A6114 = { 0, 0, 0x60040000 };
Battle D_800A6120 = { 0, 0, 0x60040000 };
Battle D_800A612C = { 0, 0, 0x60040000 };
Battle D_800A6138 = { 0, 0, 0x60040000 };
Battle D_800A6144 = { 0, 0, 0x60040000 };
BattleList D_800A6150 = {
    0,
    { &D_800A60F0, &D_800A60FC, &D_800A6108, &D_800A6114,
      &D_800A6120, &D_800A612C, &D_800A6138, &D_800A6144 },
};
Battle D_800A6174 = { 174, 10, 0x60080000 };
Battle D_800A6180 = { 170, 10, 0x60080000 };
Battle D_800A618C = { 110, 10, 0x60080000 };
Battle D_800A6198 = { 110, 10, 0x60080000 };
Battle D_800A61A4 = { 182, 10, 0x60080000 };
Battle D_800A61B0 = { 182, 10, 0x60080000 };
Battle D_800A61BC = { 71, 10, 0x60080000 };
Battle D_800A61C8 = { 71, 10, 0x60080000 };
BattleList D_800A61D4 = {
    1,
    { &D_800A6174, &D_800A6180, &D_800A618C, &D_800A6198,
      &D_800A61A4, &D_800A61B0, &D_800A61BC, &D_800A61C8 },
};
Battle D_800A61F8 = { 0, 0, 0x60040000 };
Battle D_800A6204 = { 0, 0, 0x60040000 };
Battle D_800A6210 = { 0, 0, 0x60040000 };
Battle D_800A621C = { 0, 0, 0x60040000 };
Battle D_800A6228 = { 0, 0, 0x60040000 };
Battle D_800A6234 = { 0, 0, 0x60040000 };
Battle D_800A6240 = { 0, 0, 0x60040000 };
Battle D_800A624C = { 0, 0, 0x60040000 };
BattleList D_800A6258 = {
    0,
    { &D_800A61F8, &D_800A6204, &D_800A6210, &D_800A621C,
      &D_800A6228, &D_800A6234, &D_800A6240, &D_800A624C },
};
Battle D_800A627C = { 0, 0, 0x60040000 };
Battle D_800A6288 = { 0, 0, 0x60040000 };
Battle D_800A6294 = { 0, 0, 0x60040000 };
Battle D_800A62A0 = { 0, 0, 0x60040000 };
Battle D_800A62AC = { 0, 0, 0x60040000 };
Battle D_800A62B8 = { 0, 0, 0x60040000 };
Battle D_800A62C4 = { 0, 0, 0x60040000 };
Battle D_800A62D0 = { 0, 0, 0x60040000 };
BattleList D_800A62DC = {
    0,
    { &D_800A627C, &D_800A6288, &D_800A6294, &D_800A62A0,
      &D_800A62AC, &D_800A62B8, &D_800A62C4, &D_800A62D0 },
};
Battle D_800A6300 = { 0, 0, 0x60040000 };
Battle D_800A630C = { 0, 0, 0x60040000 };
Battle D_800A6318 = { 0, 0, 0x60040000 };
Battle D_800A6324 = { 0, 0, 0x60040000 };
Battle D_800A6330 = { 0, 0, 0x60040000 };
Battle D_800A633C = { 0, 0, 0x60040000 };
Battle D_800A6348 = { 0, 0, 0x60040000 };
Battle D_800A6354 = { 0, 0, 0x60040000 };
BattleList D_800A6360 = {
    0,
    { &D_800A6300, &D_800A630C, &D_800A6318, &D_800A6324,
      &D_800A6330, &D_800A633C, &D_800A6348, &D_800A6354 },
};
Battle D_800A6384 = { 110, 10, 0x60080000 };
Battle D_800A6390 = { 110, 10, 0x60080000 };
Battle D_800A639C = { 110, 10, 0x60080000 };
Battle D_800A63A8 = { 110, 10, 0x60080000 };
Battle D_800A63B4 = { 182, 10, 0x60080000 };
Battle D_800A63C0 = { 182, 10, 0x60080000 };
Battle D_800A63CC = { 182, 10, 0x60080000 };
Battle D_800A63D8 = { 182, 10, 0x60080000 };
BattleList D_800A63E4 = {
    1,
    { &D_800A6384, &D_800A6390, &D_800A639C, &D_800A63A8,
      &D_800A63B4, &D_800A63C0, &D_800A63CC, &D_800A63D8 },
};
Battle D_800A6408 = { 0, 0, 0x60040000 };
Battle D_800A6414 = { 0, 0, 0x60040000 };
Battle D_800A6420 = { 0, 0, 0x60040000 };
Battle D_800A642C = { 0, 0, 0x60040000 };
Battle D_800A6438 = { 0, 0, 0x60040000 };
Battle D_800A6444 = { 0, 0, 0x60040000 };
Battle D_800A6450 = { 0, 0, 0x60040000 };
Battle D_800A645C = { 0, 0, 0x60040000 };
BattleList D_800A6468 = {
    0,
    { &D_800A6408, &D_800A6414, &D_800A6420, &D_800A642C,
      &D_800A6438, &D_800A6444, &D_800A6450, &D_800A645C },
};
Battle D_800A648C = { 0, 0, 0x60040000 };
Battle D_800A6498 = { 0, 0, 0x60040000 };
Battle D_800A64A4 = { 0, 0, 0x60040000 };
Battle D_800A64B0 = { 0, 0, 0x60040000 };
Battle D_800A64BC = { 0, 0, 0x60040000 };
Battle D_800A64C8 = { 0, 0, 0x60040000 };
Battle D_800A64D4 = { 0, 0, 0x60040000 };
Battle D_800A64E0 = { 0, 0, 0x60040000 };
BattleList D_800A64EC = {
    0,
    { &D_800A648C, &D_800A6498, &D_800A64A4, &D_800A64B0,
      &D_800A64BC, &D_800A64C8, &D_800A64D4, &D_800A64E0 },
};
Battle D_800A6510 = { 0, 0, 0x60040000 };
Battle D_800A651C = { 0, 0, 0x60040000 };
Battle D_800A6528 = { 0, 0, 0x60040000 };
Battle D_800A6534 = { 0, 0, 0x60040000 };
Battle D_800A6540 = { 0, 0, 0x60040000 };
Battle D_800A654C = { 0, 0, 0x60040000 };
Battle D_800A6558 = { 0, 0, 0x60040000 };
Battle D_800A6564 = { 0, 0, 0x60040000 };
BattleList D_800A6570 = {
    0,
    { &D_800A6510, &D_800A651C, &D_800A6528, &D_800A6534,
      &D_800A6540, &D_800A654C, &D_800A6558, &D_800A6564 },
};
Battle D_800A6594 = { 182, 10, 0x60080000 };
Battle D_800A65A0 = { 182, 10, 0x60080000 };
Battle D_800A65AC = { 182, 10, 0x60080000 };
Battle D_800A65B8 = { 182, 10, 0x60080000 };
Battle D_800A65C4 = { 71, 10, 0x60080000 };
Battle D_800A65D0 = { 71, 10, 0x60080000 };
Battle D_800A65DC = { 71, 10, 0x60080000 };
Battle D_800A65E8 = { 71, 10, 0x60080000 };
BattleList D_800A65F4 = {
    1,
    { &D_800A6594, &D_800A65A0, &D_800A65AC, &D_800A65B8,
      &D_800A65C4, &D_800A65D0, &D_800A65DC, &D_800A65E8 },
};
Battle D_800A6618 = { 0, 0, 0x60040000 };
Battle D_800A6624 = { 0, 0, 0x60040000 };
Battle D_800A6630 = { 0, 0, 0x60040000 };
Battle D_800A663C = { 0, 0, 0x60040000 };
Battle D_800A6648 = { 0, 0, 0x60040000 };
Battle D_800A6654 = { 0, 0, 0x60040000 };
Battle D_800A6660 = { 0, 0, 0x60040000 };
Battle D_800A666C = { 0, 0, 0x60040000 };
BattleList D_800A6678 = {
    0,
    { &D_800A6618, &D_800A6624, &D_800A6630, &D_800A663C,
      &D_800A6648, &D_800A6654, &D_800A6660, &D_800A666C },
};
Battle D_800A669C = { 0, 0, 0x60040000 };
Battle D_800A66A8 = { 0, 0, 0x60040000 };
Battle D_800A66B4 = { 0, 0, 0x60040000 };
Battle D_800A66C0 = { 0, 0, 0x60040000 };
Battle D_800A66CC = { 0, 0, 0x60040000 };
Battle D_800A66D8 = { 0, 0, 0x60040000 };
Battle D_800A66E4 = { 0, 0, 0x60040000 };
Battle D_800A66F0 = { 0, 0, 0x60040000 };
BattleList D_800A66FC = {
    0,
    { &D_800A669C, &D_800A66A8, &D_800A66B4, &D_800A66C0,
      &D_800A66CC, &D_800A66D8, &D_800A66E4, &D_800A66F0 },
};
Battle D_800A6720 = { 0, 0, 0x60040000 };
Battle D_800A672C = { 0, 0, 0x60040000 };
Battle D_800A6738 = { 0, 0, 0x60040000 };
Battle D_800A6744 = { 0, 0, 0x60040000 };
Battle D_800A6750 = { 0, 0, 0x60040000 };
Battle D_800A675C = { 0, 0, 0x60040000 };
Battle D_800A6768 = { 0, 0, 0x60040000 };
Battle D_800A6774 = { 0, 0, 0x60040000 };
BattleList D_800A6780 = {
    0,
    { &D_800A6720, &D_800A672C, &D_800A6738, &D_800A6744,
      &D_800A6750, &D_800A675C, &D_800A6768, &D_800A6774 },
};
Battle D_800A67A4 = { 182, 10, 0x60080000 };
Battle D_800A67B0 = { 182, 10, 0x60080000 };
Battle D_800A67BC = { 182, 10, 0x60080000 };
Battle D_800A67C8 = { 182, 10, 0x60080000 };
Battle D_800A67D4 = { 71, 10, 0x60080000 };
Battle D_800A67E0 = { 71, 10, 0x60080000 };
Battle D_800A67EC = { 71, 10, 0x60080000 };
Battle D_800A67F8 = { 71, 10, 0x60080000 };
BattleList D_800A6804 = {
    1,
    { &D_800A67A4, &D_800A67B0, &D_800A67BC, &D_800A67C8,
      &D_800A67D4, &D_800A67E0, &D_800A67EC, &D_800A67F8 },
};
Battle D_800A6828 = { 0, 0, 0x60040000 };
Battle D_800A6834 = { 0, 0, 0x60040000 };
Battle D_800A6840 = { 0, 0, 0x60040000 };
Battle D_800A684C = { 0, 0, 0x60040000 };
Battle D_800A6858 = { 0, 0, 0x60040000 };
Battle D_800A6864 = { 0, 0, 0x60040000 };
Battle D_800A6870 = { 0, 0, 0x60040000 };
Battle D_800A687C = { 0, 0, 0x60040000 };
BattleList D_800A6888 = {
    0,
    { &D_800A6828, &D_800A6834, &D_800A6840, &D_800A684C,
      &D_800A6858, &D_800A6864, &D_800A6870, &D_800A687C },
};
Battle D_800A68AC = { 0, 0, 0x60040000 };
Battle D_800A68B8 = { 0, 0, 0x60040000 };
Battle D_800A68C4 = { 0, 0, 0x60040000 };
Battle D_800A68D0 = { 0, 0, 0x60040000 };
Battle D_800A68DC = { 0, 0, 0x60040000 };
Battle D_800A68E8 = { 0, 0, 0x60040000 };
Battle D_800A68F4 = { 0, 0, 0x60040000 };
Battle D_800A6900 = { 0, 0, 0x60040000 };
BattleList D_800A690C = {
    0,
    { &D_800A68AC, &D_800A68B8, &D_800A68C4, &D_800A68D0,
      &D_800A68DC, &D_800A68E8, &D_800A68F4, &D_800A6900 },
};
Battle D_800A6930 = { 0, 0, 0x60040000 };
Battle D_800A693C = { 0, 0, 0x60040000 };
Battle D_800A6948 = { 0, 0, 0x60040000 };
Battle D_800A6954 = { 0, 0, 0x60040000 };
Battle D_800A6960 = { 0, 0, 0x60040000 };
Battle D_800A696C = { 0, 0, 0x60040000 };
Battle D_800A6978 = { 0, 0, 0x60040000 };
Battle D_800A6984 = { 0, 0, 0x60040000 };
BattleList D_800A6990 = {
    0,
    { &D_800A6930, &D_800A693C, &D_800A6948, &D_800A6954,
      &D_800A6960, &D_800A696C, &D_800A6978, &D_800A6984 },
};
Battle D_800A69B4 = { 174, 10, 0x60080000 };
Battle D_800A69C0 = { 174, 10, 0x60080000 };
Battle D_800A69CC = { 170, 10, 0x60080000 };
Battle D_800A69D8 = { 170, 10, 0x60080000 };
Battle D_800A69E4 = { 170, 10, 0x60080000 };
Battle D_800A69F0 = { 110, 10, 0x60080000 };
Battle D_800A69FC = { 110, 10, 0x60080000 };
Battle D_800A6A08 = { 110, 10, 0x60080000 };
BattleList D_800A6A14 = {
    2,
    { &D_800A69B4, &D_800A69C0, &D_800A69CC, &D_800A69D8,
      &D_800A69E4, &D_800A69F0, &D_800A69FC, &D_800A6A08 },
};
Battle D_800A6A38 = { 0, 0, 0x60040000 };
Battle D_800A6A44 = { 0, 0, 0x60040000 };
Battle D_800A6A50 = { 0, 0, 0x60040000 };
Battle D_800A6A5C = { 0, 0, 0x60040000 };
Battle D_800A6A68 = { 0, 0, 0x60040000 };
Battle D_800A6A74 = { 0, 0, 0x60040000 };
Battle D_800A6A80 = { 0, 0, 0x60040000 };
Battle D_800A6A8C = { 0, 0, 0x60040000 };
BattleList D_800A6A98 = {
    0,
    { &D_800A6A38, &D_800A6A44, &D_800A6A50, &D_800A6A5C,
      &D_800A6A68, &D_800A6A74, &D_800A6A80, &D_800A6A8C },
};
Battle D_800A6ABC = { 0, 0, 0x60040000 };
Battle D_800A6AC8 = { 0, 0, 0x60040000 };
Battle D_800A6AD4 = { 0, 0, 0x60040000 };
Battle D_800A6AE0 = { 0, 0, 0x60040000 };
Battle D_800A6AEC = { 0, 0, 0x60040000 };
Battle D_800A6AF8 = { 0, 0, 0x60040000 };
Battle D_800A6B04 = { 0, 0, 0x60040000 };
Battle D_800A6B10 = { 0, 0, 0x60040000 };
BattleList D_800A6B1C = {
    0,
    { &D_800A6ABC, &D_800A6AC8, &D_800A6AD4, &D_800A6AE0,
      &D_800A6AEC, &D_800A6AF8, &D_800A6B04, &D_800A6B10 },
};
Battle D_800A6B40 = { 0, 0, 0x60040000 };
Battle D_800A6B4C = { 0, 0, 0x60040000 };
Battle D_800A6B58 = { 0, 0, 0x60040000 };
Battle D_800A6B64 = { 0, 0, 0x60040000 };
Battle D_800A6B70 = { 0, 0, 0x60040000 };
Battle D_800A6B7C = { 0, 0, 0x60040000 };
Battle D_800A6B88 = { 0, 0, 0x60040000 };
Battle D_800A6B94 = { 0, 0, 0x60040000 };
BattleList D_800A6BA0 = {
    0,
    { &D_800A6B40, &D_800A6B4C, &D_800A6B58, &D_800A6B64,
      &D_800A6B70, &D_800A6B7C, &D_800A6B88, &D_800A6B94 },
};
Battle D_800A6BC4 = { 182, 10, 0x60080000 };
Battle D_800A6BD0 = { 182, 10, 0x60080000 };
Battle D_800A6BDC = { 182, 10, 0x60080000 };
Battle D_800A6BE8 = { 182, 10, 0x60080000 };
Battle D_800A6BF4 = { 71, 10, 0x60080000 };
Battle D_800A6C00 = { 71, 10, 0x60080000 };
Battle D_800A6C0C = { 71, 10, 0x60080000 };
Battle D_800A6C18 = { 71, 10, 0x60080000 };
BattleList D_800A6C24 = {
    2,
    { &D_800A6BC4, &D_800A6BD0, &D_800A6BDC, &D_800A6BE8,
      &D_800A6BF4, &D_800A6C00, &D_800A6C0C, &D_800A6C18 },
};
Battle D_800A6C48 = { 0, 0, 0x60040000 };
Battle D_800A6C54 = { 0, 0, 0x60040000 };
Battle D_800A6C60 = { 0, 0, 0x60040000 };
Battle D_800A6C6C = { 0, 0, 0x60040000 };
Battle D_800A6C78 = { 0, 0, 0x60040000 };
Battle D_800A6C84 = { 0, 0, 0x60040000 };
Battle D_800A6C90 = { 0, 0, 0x60040000 };
Battle D_800A6C9C = { 0, 0, 0x60040000 };
BattleList D_800A6CA8 = {
    0,
    { &D_800A6C48, &D_800A6C54, &D_800A6C60, &D_800A6C6C,
      &D_800A6C78, &D_800A6C84, &D_800A6C90, &D_800A6C9C },
};
Battle D_800A6CCC = { 0, 0, 0x60040000 };
Battle D_800A6CD8 = { 0, 0, 0x60040000 };
Battle D_800A6CE4 = { 0, 0, 0x60040000 };
Battle D_800A6CF0 = { 0, 0, 0x60040000 };
Battle D_800A6CFC = { 0, 0, 0x60040000 };
Battle D_800A6D08 = { 0, 0, 0x60040000 };
Battle D_800A6D14 = { 0, 0, 0x60040000 };
Battle D_800A6D20 = { 0, 0, 0x60040000 };
BattleList D_800A6D2C = {
    0,
    { &D_800A6CCC, &D_800A6CD8, &D_800A6CE4, &D_800A6CF0,
      &D_800A6CFC, &D_800A6D08, &D_800A6D14, &D_800A6D20 },
};
Battle D_800A6D50 = { 0, 0, 0x60040000 };
Battle D_800A6D5C = { 0, 0, 0x60040000 };
Battle D_800A6D68 = { 0, 0, 0x60040000 };
Battle D_800A6D74 = { 0, 0, 0x60040000 };
Battle D_800A6D80 = { 0, 0, 0x60040000 };
Battle D_800A6D8C = { 0, 0, 0x60040000 };
Battle D_800A6D98 = { 0, 0, 0x60040000 };
Battle D_800A6DA4 = { 0, 0, 0x60040000 };
BattleList D_800A6DB0 = {
    0,
    { &D_800A6D50, &D_800A6D5C, &D_800A6D68, &D_800A6D74,
      &D_800A6D80, &D_800A6D8C, &D_800A6D98, &D_800A6DA4 },
};
Battle D_800A6DD4 = { 110, 10, 0x60080000 };
Battle D_800A6DE0 = { 110, 10, 0x60080000 };
Battle D_800A6DEC = { 110, 10, 0x60080000 };
Battle D_800A6DF8 = { 110, 10, 0x60080000 };
Battle D_800A6E04 = { 110, 10, 0x60080000 };
Battle D_800A6E10 = { 110, 10, 0x60080000 };
Battle D_800A6E1C = { 110, 10, 0x60080000 };
Battle D_800A6E28 = { 110, 10, 0x60080000 };
BattleList D_800A6E34 = {
    1,
    { &D_800A6DD4, &D_800A6DE0, &D_800A6DEC, &D_800A6DF8,
      &D_800A6E04, &D_800A6E10, &D_800A6E1C, &D_800A6E28 },
};
Battle D_800A6E58 = { 0, 0, 0x60040000 };
Battle D_800A6E64 = { 0, 0, 0x60040000 };
Battle D_800A6E70 = { 0, 0, 0x60040000 };
Battle D_800A6E7C = { 0, 0, 0x60040000 };
Battle D_800A6E88 = { 0, 0, 0x60040000 };
Battle D_800A6E94 = { 0, 0, 0x60040000 };
Battle D_800A6EA0 = { 0, 0, 0x60040000 };
Battle D_800A6EAC = { 0, 0, 0x60040000 };
BattleList D_800A6EB8 = {
    0,
    { &D_800A6E58, &D_800A6E64, &D_800A6E70, &D_800A6E7C,
      &D_800A6E88, &D_800A6E94, &D_800A6EA0, &D_800A6EAC },
};
Battle D_800A6EDC = { 0, 0, 0x60040000 };
Battle D_800A6EE8 = { 0, 0, 0x60040000 };
Battle D_800A6EF4 = { 0, 0, 0x60040000 };
Battle D_800A6F00 = { 0, 0, 0x60040000 };
Battle D_800A6F0C = { 0, 0, 0x60040000 };
Battle D_800A6F18 = { 0, 0, 0x60040000 };
Battle D_800A6F24 = { 0, 0, 0x60040000 };
Battle D_800A6F30 = { 0, 0, 0x60040000 };
BattleList D_800A6F3C = {
    0,
    { &D_800A6EDC, &D_800A6EE8, &D_800A6EF4, &D_800A6F00,
      &D_800A6F0C, &D_800A6F18, &D_800A6F24, &D_800A6F30 },
};
Battle D_800A6F60 = { 0, 0, 0x60040000 };
Battle D_800A6F6C = { 0, 0, 0x60040000 };
Battle D_800A6F78 = { 0, 0, 0x60040000 };
Battle D_800A6F84 = { 0, 0, 0x60040000 };
Battle D_800A6F90 = { 0, 0, 0x60040000 };
Battle D_800A6F9C = { 0, 0, 0x60040000 };
Battle D_800A6FA8 = { 0, 0, 0x60040000 };
Battle D_800A6FB4 = { 0, 0, 0x60040000 };
BattleList D_800A6FC0 = {
    0,
    { &D_800A6F60, &D_800A6F6C, &D_800A6F78, &D_800A6F84,
      &D_800A6F90, &D_800A6F9C, &D_800A6FA8, &D_800A6FB4 },
};
Battle D_800A6FE4 = { 182, 10, 0x60080000 };
Battle D_800A6FF0 = { 182, 10, 0x60080000 };
Battle D_800A6FFC = { 182, 10, 0x60080000 };
Battle D_800A7008 = { 182, 10, 0x60080000 };
Battle D_800A7014 = { 71, 10, 0x60080000 };
Battle D_800A7020 = { 71, 10, 0x60080000 };
Battle D_800A702C = { 71, 10, 0x60080000 };
Battle D_800A7038 = { 71, 10, 0x60080000 };
BattleList D_800A7044 = {
    1,
    { &D_800A6FE4, &D_800A6FF0, &D_800A6FFC, &D_800A7008,
      &D_800A7014, &D_800A7020, &D_800A702C, &D_800A7038 },
};
Battle D_800A7068 = { 0, 0, 0x60040000 };
Battle D_800A7074 = { 0, 0, 0x60040000 };
Battle D_800A7080 = { 0, 0, 0x60040000 };
Battle D_800A708C = { 0, 0, 0x60040000 };
Battle D_800A7098 = { 0, 0, 0x60040000 };
Battle D_800A70A4 = { 0, 0, 0x60040000 };
Battle D_800A70B0 = { 0, 0, 0x60040000 };
Battle D_800A70BC = { 0, 0, 0x60040000 };
BattleList D_800A70C8 = {
    0,
    { &D_800A7068, &D_800A7074, &D_800A7080, &D_800A708C,
      &D_800A7098, &D_800A70A4, &D_800A70B0, &D_800A70BC },
};
Battle D_800A70EC = { 0, 0, 0x60040000 };
Battle D_800A70F8 = { 0, 0, 0x60040000 };
Battle D_800A7104 = { 0, 0, 0x60040000 };
Battle D_800A7110 = { 0, 0, 0x60040000 };
Battle D_800A711C = { 0, 0, 0x60040000 };
Battle D_800A7128 = { 0, 0, 0x60040000 };
Battle D_800A7134 = { 0, 0, 0x60040000 };
Battle D_800A7140 = { 0, 0, 0x60040000 };
BattleList D_800A714C = {
    0,
    { &D_800A70EC, &D_800A70F8, &D_800A7104, &D_800A7110,
      &D_800A711C, &D_800A7128, &D_800A7134, &D_800A7140 },
};
Battle D_800A7170 = { 0, 0, 0x60040000 };
Battle D_800A717C = { 0, 0, 0x60040000 };
Battle D_800A7188 = { 0, 0, 0x60040000 };
Battle D_800A7194 = { 0, 0, 0x60040000 };
Battle D_800A71A0 = { 0, 0, 0x60040000 };
Battle D_800A71AC = { 0, 0, 0x60040000 };
Battle D_800A71B8 = { 0, 0, 0x60040000 };
Battle D_800A71C4 = { 0, 0, 0x60040000 };
BattleList D_800A71D0 = {
    0,
    { &D_800A7170, &D_800A717C, &D_800A7188, &D_800A7194,
      &D_800A71A0, &D_800A71AC, &D_800A71B8, &D_800A71C4 },
};
Battle D_800A71F4 = { 174, 10, 0x60080000 };
Battle D_800A7200 = { 174, 10, 0x60080000 };
Battle D_800A720C = { 170, 10, 0x60080000 };
Battle D_800A7218 = { 170, 10, 0x60080000 };
Battle D_800A7224 = { 170, 10, 0x60080000 };
Battle D_800A7230 = { 170, 10, 0x60080000 };
Battle D_800A723C = { 170, 10, 0x60080000 };
Battle D_800A7248 = { 170, 10, 0x60080000 };
BattleList D_800A7254 = {
    5,
    { &D_800A71F4, &D_800A7200, &D_800A720C, &D_800A7218,
      &D_800A7224, &D_800A7230, &D_800A723C, &D_800A7248 },
};
Battle D_800A7278 = { 0, 0, 0x60040000 };
Battle D_800A7284 = { 0, 0, 0x60040000 };
Battle D_800A7290 = { 0, 0, 0x60040000 };
Battle D_800A729C = { 0, 0, 0x60040000 };
Battle D_800A72A8 = { 0, 0, 0x60040000 };
Battle D_800A72B4 = { 0, 0, 0x60040000 };
Battle D_800A72C0 = { 0, 0, 0x60040000 };
Battle D_800A72CC = { 0, 0, 0x60040000 };
BattleList D_800A72D8 = {
    0,
    { &D_800A7278, &D_800A7284, &D_800A7290, &D_800A729C,
      &D_800A72A8, &D_800A72B4, &D_800A72C0, &D_800A72CC },
};
Battle D_800A72FC = { 0, 0, 0x60040000 };
Battle D_800A7308 = { 0, 0, 0x60040000 };
Battle D_800A7314 = { 0, 0, 0x60040000 };
Battle D_800A7320 = { 0, 0, 0x60040000 };
Battle D_800A732C = { 0, 0, 0x60040000 };
Battle D_800A7338 = { 0, 0, 0x60040000 };
Battle D_800A7344 = { 0, 0, 0x60040000 };
Battle D_800A7350 = { 0, 0, 0x60040000 };
BattleList D_800A735C = {
    0,
    { &D_800A72FC, &D_800A7308, &D_800A7314, &D_800A7320,
      &D_800A732C, &D_800A7338, &D_800A7344, &D_800A7350 },
};
Battle D_800A7380 = { 0, 0, 0x60040000 };
Battle D_800A738C = { 0, 0, 0x60040000 };
Battle D_800A7398 = { 0, 0, 0x60040000 };
Battle D_800A73A4 = { 0, 0, 0x60040000 };
Battle D_800A73B0 = { 0, 0, 0x60040000 };
Battle D_800A73BC = { 0, 0, 0x60040000 };
Battle D_800A73C8 = { 0, 0, 0x60040000 };
Battle D_800A73D4 = { 0, 0, 0x60040000 };
BattleList D_800A73E0 = {
    0,
    { &D_800A7380, &D_800A738C, &D_800A7398, &D_800A73A4,
      &D_800A73B0, &D_800A73BC, &D_800A73C8, &D_800A73D4 },
};
Battle D_800A7404 = { 174, 10, 0x60080000 };
Battle D_800A7410 = { 174, 10, 0x60080000 };
Battle D_800A741C = { 170, 10, 0x60080000 };
Battle D_800A7428 = { 170, 10, 0x60080000 };
Battle D_800A7434 = { 170, 10, 0x60080000 };
Battle D_800A7440 = { 170, 10, 0x60080000 };
Battle D_800A744C = { 170, 10, 0x60080000 };
Battle D_800A7458 = { 170, 10, 0x60080000 };
BattleList D_800A7464 = {
    4,
    { &D_800A7404, &D_800A7410, &D_800A741C, &D_800A7428,
      &D_800A7434, &D_800A7440, &D_800A744C, &D_800A7458 },
};
Battle D_800A7488 = { 0, 0, 0x60040000 };
Battle D_800A7494 = { 0, 0, 0x60040000 };
Battle D_800A74A0 = { 0, 0, 0x60040000 };
Battle D_800A74AC = { 0, 0, 0x60040000 };
Battle D_800A74B8 = { 0, 0, 0x60040000 };
Battle D_800A74C4 = { 0, 0, 0x60040000 };
Battle D_800A74D0 = { 0, 0, 0x60040000 };
Battle D_800A74DC = { 0, 0, 0x60040000 };
BattleList D_800A74E8 = {
    0,
    { &D_800A7488, &D_800A7494, &D_800A74A0, &D_800A74AC,
      &D_800A74B8, &D_800A74C4, &D_800A74D0, &D_800A74DC },
};
Battle D_800A750C = { 0, 0, 0x60040000 };
Battle D_800A7518 = { 0, 0, 0x60040000 };
Battle D_800A7524 = { 0, 0, 0x60040000 };
Battle D_800A7530 = { 0, 0, 0x60040000 };
Battle D_800A753C = { 0, 0, 0x60040000 };
Battle D_800A7548 = { 0, 0, 0x60040000 };
Battle D_800A7554 = { 0, 0, 0x60040000 };
Battle D_800A7560 = { 0, 0, 0x60040000 };
BattleList D_800A756C = {
    0,
    { &D_800A750C, &D_800A7518, &D_800A7524, &D_800A7530,
      &D_800A753C, &D_800A7548, &D_800A7554, &D_800A7560 },
};
Battle D_800A7590 = { 0, 0, 0x60040000 };
Battle D_800A759C = { 0, 0, 0x60040000 };
Battle D_800A75A8 = { 0, 0, 0x60040000 };
Battle D_800A75B4 = { 0, 0, 0x60040000 };
Battle D_800A75C0 = { 0, 0, 0x60040000 };
Battle D_800A75CC = { 0, 0, 0x60040000 };
Battle D_800A75D8 = { 0, 0, 0x60040000 };
Battle D_800A75E4 = { 0, 0, 0x60040000 };
BattleList D_800A75F0 = {
    0,
    { &D_800A7590, &D_800A759C, &D_800A75A8, &D_800A75B4,
      &D_800A75C0, &D_800A75CC, &D_800A75D8, &D_800A75E4 },
};
Battle D_800A7614 = { 174, 10, 0x60080000 };
Battle D_800A7620 = { 174, 10, 0x60080000 };
Battle D_800A762C = { 170, 10, 0x60080000 };
Battle D_800A7638 = { 170, 10, 0x60080000 };
Battle D_800A7644 = { 170, 10, 0x60080000 };
Battle D_800A7650 = { 170, 10, 0x60080000 };
Battle D_800A765C = { 170, 10, 0x60080000 };
Battle D_800A7668 = { 170, 10, 0x60080000 };
BattleList D_800A7674 = {
    5,
    { &D_800A7614, &D_800A7620, &D_800A762C, &D_800A7638,
      &D_800A7644, &D_800A7650, &D_800A765C, &D_800A7668 },
};
Battle D_800A7698 = { 0, 0, 0x60040000 };
Battle D_800A76A4 = { 0, 0, 0x60040000 };
Battle D_800A76B0 = { 0, 0, 0x60040000 };
Battle D_800A76BC = { 0, 0, 0x60040000 };
Battle D_800A76C8 = { 0, 0, 0x60040000 };
Battle D_800A76D4 = { 0, 0, 0x60040000 };
Battle D_800A76E0 = { 0, 0, 0x60040000 };
Battle D_800A76EC = { 0, 0, 0x60040000 };
BattleList D_800A76F8 = {
    0,
    { &D_800A7698, &D_800A76A4, &D_800A76B0, &D_800A76BC,
      &D_800A76C8, &D_800A76D4, &D_800A76E0, &D_800A76EC },
};
Battle D_800A771C = { 0, 0, 0x60040000 };
Battle D_800A7728 = { 0, 0, 0x60040000 };
Battle D_800A7734 = { 0, 0, 0x60040000 };
Battle D_800A7740 = { 0, 0, 0x60040000 };
Battle D_800A774C = { 0, 0, 0x60040000 };
Battle D_800A7758 = { 0, 0, 0x60040000 };
Battle D_800A7764 = { 0, 0, 0x60040000 };
Battle D_800A7770 = { 0, 0, 0x60040000 };
BattleList D_800A777C = {
    0,
    { &D_800A771C, &D_800A7728, &D_800A7734, &D_800A7740,
      &D_800A774C, &D_800A7758, &D_800A7764, &D_800A7770 },
};
Battle D_800A77A0 = { 0, 0, 0x60040000 };
Battle D_800A77AC = { 0, 0, 0x60040000 };
Battle D_800A77B8 = { 0, 0, 0x60040000 };
Battle D_800A77C4 = { 0, 0, 0x60040000 };
Battle D_800A77D0 = { 0, 0, 0x60040000 };
Battle D_800A77DC = { 0, 0, 0x60040000 };
Battle D_800A77E8 = { 0, 0, 0x60040000 };
Battle D_800A77F4 = { 0, 0, 0x60040000 };
BattleList D_800A7800 = {
    0,
    { &D_800A77A0, &D_800A77AC, &D_800A77B8, &D_800A77C4,
      &D_800A77D0, &D_800A77DC, &D_800A77E8, &D_800A77F4 },
};
Battle D_800A7824 = { 182, 10, 0x60080000 };
Battle D_800A7830 = { 182, 10, 0x60080000 };
Battle D_800A783C = { 182, 10, 0x60080000 };
Battle D_800A7848 = { 182, 10, 0x60080000 };
Battle D_800A7854 = { 71, 10, 0x60080000 };
Battle D_800A7860 = { 71, 10, 0x60080000 };
Battle D_800A786C = { 71, 10, 0x60080000 };
Battle D_800A7878 = { 71, 10, 0x60080000 };
BattleList D_800A7884 = {
    5,
    { &D_800A7824, &D_800A7830, &D_800A783C, &D_800A7848,
      &D_800A7854, &D_800A7860, &D_800A786C, &D_800A7878 },
};
Battle D_800A78A8 = { 0, 0, 0x60040000 };
Battle D_800A78B4 = { 0, 0, 0x60040000 };
Battle D_800A78C0 = { 0, 0, 0x60040000 };
Battle D_800A78CC = { 0, 0, 0x60040000 };
Battle D_800A78D8 = { 0, 0, 0x60040000 };
Battle D_800A78E4 = { 0, 0, 0x60040000 };
Battle D_800A78F0 = { 0, 0, 0x60040000 };
Battle D_800A78FC = { 0, 0, 0x60040000 };
BattleList D_800A7908 = {
    0,
    { &D_800A78A8, &D_800A78B4, &D_800A78C0, &D_800A78CC,
      &D_800A78D8, &D_800A78E4, &D_800A78F0, &D_800A78FC },
};
Battle D_800A792C = { 0, 0, 0x60040000 };
Battle D_800A7938 = { 0, 0, 0x60040000 };
Battle D_800A7944 = { 0, 0, 0x60040000 };
Battle D_800A7950 = { 0, 0, 0x60040000 };
Battle D_800A795C = { 0, 0, 0x60040000 };
Battle D_800A7968 = { 0, 0, 0x60040000 };
Battle D_800A7974 = { 0, 0, 0x60040000 };
Battle D_800A7980 = { 0, 0, 0x60040000 };
BattleList D_800A798C = {
    0,
    { &D_800A792C, &D_800A7938, &D_800A7944, &D_800A7950,
      &D_800A795C, &D_800A7968, &D_800A7974, &D_800A7980 },
};
Battle D_800A79B0 = { 0, 0, 0x60040000 };
Battle D_800A79BC = { 0, 0, 0x60040000 };
Battle D_800A79C8 = { 0, 0, 0x60040000 };
Battle D_800A79D4 = { 0, 0, 0x60040000 };
Battle D_800A79E0 = { 0, 0, 0x60040000 };
Battle D_800A79EC = { 0, 0, 0x60040000 };
Battle D_800A79F8 = { 0, 0, 0x60040000 };
Battle D_800A7A04 = { 0, 0, 0x60040000 };
BattleList D_800A7A10 = {
    0,
    { &D_800A79B0, &D_800A79BC, &D_800A79C8, &D_800A79D4,
      &D_800A79E0, &D_800A79EC, &D_800A79F8, &D_800A7A04 },
};
Battle D_800A7A34 = { 110, 10, 0x60080000 };
Battle D_800A7A40 = { 110, 10, 0x60080000 };
Battle D_800A7A4C = { 110, 10, 0x60080000 };
Battle D_800A7A58 = { 110, 10, 0x60080000 };
Battle D_800A7A64 = { 110, 10, 0x60080000 };
Battle D_800A7A70 = { 110, 10, 0x60080000 };
Battle D_800A7A7C = { 110, 10, 0x60080000 };
Battle D_800A7A88 = { 110, 10, 0x60080000 };
BattleList D_800A7A94 = {
    1,
    { &D_800A7A34, &D_800A7A40, &D_800A7A4C, &D_800A7A58,
      &D_800A7A64, &D_800A7A70, &D_800A7A7C, &D_800A7A88 },
};
Battle D_800A7AB8 = { 0, 0, 0x60040000 };
Battle D_800A7AC4 = { 0, 0, 0x60040000 };
Battle D_800A7AD0 = { 0, 0, 0x60040000 };
Battle D_800A7ADC = { 0, 0, 0x60040000 };
Battle D_800A7AE8 = { 0, 0, 0x60040000 };
Battle D_800A7AF4 = { 0, 0, 0x60040000 };
Battle D_800A7B00 = { 0, 0, 0x60040000 };
Battle D_800A7B0C = { 0, 0, 0x60040000 };
BattleList D_800A7B18 = {
    0,
    { &D_800A7AB8, &D_800A7AC4, &D_800A7AD0, &D_800A7ADC,
      &D_800A7AE8, &D_800A7AF4, &D_800A7B00, &D_800A7B0C },
};
Battle D_800A7B3C = { 0, 0, 0x60040000 };
Battle D_800A7B48 = { 0, 0, 0x60040000 };
Battle D_800A7B54 = { 0, 0, 0x60040000 };
Battle D_800A7B60 = { 0, 0, 0x60040000 };
Battle D_800A7B6C = { 0, 0, 0x60040000 };
Battle D_800A7B78 = { 0, 0, 0x60040000 };
Battle D_800A7B84 = { 0, 0, 0x60040000 };
Battle D_800A7B90 = { 0, 0, 0x60040000 };
BattleList D_800A7B9C = {
    0,
    { &D_800A7B3C, &D_800A7B48, &D_800A7B54, &D_800A7B60,
      &D_800A7B6C, &D_800A7B78, &D_800A7B84, &D_800A7B90 },
};
Battle D_800A7BC0 = { 0, 0, 0x60040000 };
Battle D_800A7BCC = { 0, 0, 0x60040000 };
Battle D_800A7BD8 = { 0, 0, 0x60040000 };
Battle D_800A7BE4 = { 0, 0, 0x60040000 };
Battle D_800A7BF0 = { 0, 0, 0x60040000 };
Battle D_800A7BFC = { 0, 0, 0x60040000 };
Battle D_800A7C08 = { 0, 0, 0x60040000 };
Battle D_800A7C14 = { 0, 0, 0x60040000 };
BattleList D_800A7C20 = {
    0,
    { &D_800A7BC0, &D_800A7BCC, &D_800A7BD8, &D_800A7BE4,
      &D_800A7BF0, &D_800A7BFC, &D_800A7C08, &D_800A7C14 },
};
Battle D_800A7C44 = { 182, 10, 0x60080000 };
Battle D_800A7C50 = { 182, 10, 0x60080000 };
Battle D_800A7C5C = { 182, 10, 0x60080000 };
Battle D_800A7C68 = { 182, 10, 0x60080000 };
Battle D_800A7C74 = { 71, 10, 0x60080000 };
Battle D_800A7C80 = { 71, 10, 0x60080000 };
Battle D_800A7C8C = { 71, 10, 0x60080000 };
Battle D_800A7C98 = { 71, 10, 0x60080000 };
BattleList D_800A7CA4 = {
    1,
    { &D_800A7C44, &D_800A7C50, &D_800A7C5C, &D_800A7C68,
      &D_800A7C74, &D_800A7C80, &D_800A7C8C, &D_800A7C98 },
};
Battle D_800A7CC8 = { 0, 0, 0x60040000 };
Battle D_800A7CD4 = { 0, 0, 0x60040000 };
Battle D_800A7CE0 = { 0, 0, 0x60040000 };
Battle D_800A7CEC = { 0, 0, 0x60040000 };
Battle D_800A7CF8 = { 0, 0, 0x60040000 };
Battle D_800A7D04 = { 0, 0, 0x60040000 };
Battle D_800A7D10 = { 0, 0, 0x60040000 };
Battle D_800A7D1C = { 0, 0, 0x60040000 };
BattleList D_800A7D28 = {
    0,
    { &D_800A7CC8, &D_800A7CD4, &D_800A7CE0, &D_800A7CEC,
      &D_800A7CF8, &D_800A7D04, &D_800A7D10, &D_800A7D1C },
};
Battle D_800A7D4C = { 0, 0, 0x60040000 };
Battle D_800A7D58 = { 0, 0, 0x60040000 };
Battle D_800A7D64 = { 0, 0, 0x60040000 };
Battle D_800A7D70 = { 0, 0, 0x60040000 };
Battle D_800A7D7C = { 0, 0, 0x60040000 };
Battle D_800A7D88 = { 0, 0, 0x60040000 };
Battle D_800A7D94 = { 0, 0, 0x60040000 };
Battle D_800A7DA0 = { 0, 0, 0x60040000 };
BattleList D_800A7DAC = {
    0,
    { &D_800A7D4C, &D_800A7D58, &D_800A7D64, &D_800A7D70,
      &D_800A7D7C, &D_800A7D88, &D_800A7D94, &D_800A7DA0 },
};
Battle D_800A7DD0 = { 0, 0, 0x60040000 };
Battle D_800A7DDC = { 0, 0, 0x60040000 };
Battle D_800A7DE8 = { 0, 0, 0x60040000 };
Battle D_800A7DF4 = { 0, 0, 0x60040000 };
Battle D_800A7E00 = { 0, 0, 0x60040000 };
Battle D_800A7E0C = { 0, 0, 0x60040000 };
Battle D_800A7E18 = { 0, 0, 0x60040000 };
Battle D_800A7E24 = { 0, 0, 0x60040000 };
BattleList D_800A7E30 = {
    0,
    { &D_800A7DD0, &D_800A7DDC, &D_800A7DE8, &D_800A7DF4,
      &D_800A7E00, &D_800A7E0C, &D_800A7E18, &D_800A7E24 },
};
Battle D_800A7E54 = { 110, 10, 0x60080000 };
Battle D_800A7E60 = { 110, 10, 0x60080000 };
Battle D_800A7E6C = { 110, 10, 0x60080000 };
Battle D_800A7E78 = { 110, 10, 0x60080000 };
Battle D_800A7E84 = { 110, 10, 0x60080000 };
Battle D_800A7E90 = { 110, 10, 0x60080000 };
Battle D_800A7E9C = { 110, 10, 0x60080000 };
Battle D_800A7EA8 = { 110, 10, 0x60080000 };
BattleList D_800A7EB4 = {
    3,
    { &D_800A7E54, &D_800A7E60, &D_800A7E6C, &D_800A7E78,
      &D_800A7E84, &D_800A7E90, &D_800A7E9C, &D_800A7EA8 },
};
Battle D_800A7ED8 = { 0, 0, 0x60040000 };
Battle D_800A7EE4 = { 0, 0, 0x60040000 };
Battle D_800A7EF0 = { 0, 0, 0x60040000 };
Battle D_800A7EFC = { 0, 0, 0x60040000 };
Battle D_800A7F08 = { 0, 0, 0x60040000 };
Battle D_800A7F14 = { 0, 0, 0x60040000 };
Battle D_800A7F20 = { 0, 0, 0x60040000 };
Battle D_800A7F2C = { 0, 0, 0x60040000 };
BattleList D_800A7F38 = {
    0,
    { &D_800A7ED8, &D_800A7EE4, &D_800A7EF0, &D_800A7EFC,
      &D_800A7F08, &D_800A7F14, &D_800A7F20, &D_800A7F2C },
};
Battle D_800A7F5C = { 0, 0, 0x60040000 };
Battle D_800A7F68 = { 0, 0, 0x60040000 };
Battle D_800A7F74 = { 0, 0, 0x60040000 };
Battle D_800A7F80 = { 0, 0, 0x60040000 };
Battle D_800A7F8C = { 0, 0, 0x60040000 };
Battle D_800A7F98 = { 0, 0, 0x60040000 };
Battle D_800A7FA4 = { 0, 0, 0x60040000 };
Battle D_800A7FB0 = { 0, 0, 0x60040000 };
BattleList D_800A7FBC = {
    0,
    { &D_800A7F5C, &D_800A7F68, &D_800A7F74, &D_800A7F80,
      &D_800A7F8C, &D_800A7F98, &D_800A7FA4, &D_800A7FB0 },
};
Battle D_800A7FE0 = { 0, 0, 0x60040000 };
Battle D_800A7FEC = { 0, 0, 0x60040000 };
Battle D_800A7FF8 = { 0, 0, 0x60040000 };
Battle D_800A8004 = { 0, 0, 0x60040000 };
Battle D_800A8010 = { 0, 0, 0x60040000 };
Battle D_800A801C = { 0, 0, 0x60040000 };
Battle D_800A8028 = { 0, 0, 0x60040000 };
Battle D_800A8034 = { 0, 0, 0x60040000 };
BattleList D_800A8040 = {
    0,
    { &D_800A7FE0, &D_800A7FEC, &D_800A7FF8, &D_800A8004,
      &D_800A8010, &D_800A801C, &D_800A8028, &D_800A8034 },
};
Battle D_800A8064 = { 110, 10, 0x60080000 };
Battle D_800A8070 = { 110, 10, 0x60080000 };
Battle D_800A807C = { 110, 10, 0x60080000 };
Battle D_800A8088 = { 110, 10, 0x60080000 };
Battle D_800A8094 = { 110, 10, 0x60080000 };
Battle D_800A80A0 = { 110, 10, 0x60080000 };
Battle D_800A80AC = { 110, 10, 0x60080000 };
Battle D_800A80B8 = { 110, 10, 0x60080000 };
BattleList D_800A80C4 = {
    3,
    { &D_800A8064, &D_800A8070, &D_800A807C, &D_800A8088,
      &D_800A8094, &D_800A80A0, &D_800A80AC, &D_800A80B8 },
};
Battle D_800A80E8 = { 0, 0, 0x60040000 };
Battle D_800A80F4 = { 0, 0, 0x60040000 };
Battle D_800A8100 = { 0, 0, 0x60040000 };
Battle D_800A810C = { 0, 0, 0x60040000 };
Battle D_800A8118 = { 0, 0, 0x60040000 };
Battle D_800A8124 = { 0, 0, 0x60040000 };
Battle D_800A8130 = { 0, 0, 0x60040000 };
Battle D_800A813C = { 0, 0, 0x60040000 };
BattleList D_800A8148 = {
    0,
    { &D_800A80E8, &D_800A80F4, &D_800A8100, &D_800A810C,
      &D_800A8118, &D_800A8124, &D_800A8130, &D_800A813C },
};
Battle D_800A816C = { 0, 0, 0x60040000 };
Battle D_800A8178 = { 0, 0, 0x60040000 };
Battle D_800A8184 = { 0, 0, 0x60040000 };
Battle D_800A8190 = { 0, 0, 0x60040000 };
Battle D_800A819C = { 0, 0, 0x60040000 };
Battle D_800A81A8 = { 0, 0, 0x60040000 };
Battle D_800A81B4 = { 0, 0, 0x60040000 };
Battle D_800A81C0 = { 0, 0, 0x60040000 };
BattleList D_800A81CC = {
    0,
    { &D_800A816C, &D_800A8178, &D_800A8184, &D_800A8190,
      &D_800A819C, &D_800A81A8, &D_800A81B4, &D_800A81C0 },
};
Battle D_800A81F0 = { 0, 0, 0x60040000 };
Battle D_800A81FC = { 0, 0, 0x60040000 };
Battle D_800A8208 = { 0, 0, 0x60040000 };
Battle D_800A8214 = { 0, 0, 0x60040000 };
Battle D_800A8220 = { 0, 0, 0x60040000 };
Battle D_800A822C = { 0, 0, 0x60040000 };
Battle D_800A8238 = { 0, 0, 0x60040000 };
Battle D_800A8244 = { 0, 0, 0x60040000 };
BattleList D_800A8250 = {
    0,
    { &D_800A81F0, &D_800A81FC, &D_800A8208, &D_800A8214,
      &D_800A8220, &D_800A822C, &D_800A8238, &D_800A8244 },
};
Battle D_800A8274 = { 182, 10, 0x60080000 };
Battle D_800A8280 = { 182, 10, 0x60080000 };
Battle D_800A828C = { 182, 10, 0x60080000 };
Battle D_800A8298 = { 182, 10, 0x60080000 };
Battle D_800A82A4 = { 71, 10, 0x60080000 };
Battle D_800A82B0 = { 71, 10, 0x60080000 };
Battle D_800A82BC = { 71, 10, 0x60080000 };
Battle D_800A82C8 = { 71, 10, 0x60080000 };
BattleList D_800A82D4 = {
    2,
    { &D_800A8274, &D_800A8280, &D_800A828C, &D_800A8298,
      &D_800A82A4, &D_800A82B0, &D_800A82BC, &D_800A82C8 },
};
Battle D_800A82F8 = { 0, 0, 0x60040000 };
Battle D_800A8304 = { 0, 0, 0x60040000 };
Battle D_800A8310 = { 0, 0, 0x60040000 };
Battle D_800A831C = { 0, 0, 0x60040000 };
Battle D_800A8328 = { 0, 0, 0x60040000 };
Battle D_800A8334 = { 0, 0, 0x60040000 };
Battle D_800A8340 = { 0, 0, 0x60040000 };
Battle D_800A834C = { 0, 0, 0x60040000 };
BattleList D_800A8358 = {
    0,
    { &D_800A82F8, &D_800A8304, &D_800A8310, &D_800A831C,
      &D_800A8328, &D_800A8334, &D_800A8340, &D_800A834C },
};
Battle D_800A837C = { 0, 0, 0x60040000 };
Battle D_800A8388 = { 0, 0, 0x60040000 };
Battle D_800A8394 = { 0, 0, 0x60040000 };
Battle D_800A83A0 = { 0, 0, 0x60040000 };
Battle D_800A83AC = { 0, 0, 0x60040000 };
Battle D_800A83B8 = { 0, 0, 0x60040000 };
Battle D_800A83C4 = { 0, 0, 0x60040000 };
Battle D_800A83D0 = { 0, 0, 0x60040000 };
BattleList D_800A83DC = {
    0,
    { &D_800A837C, &D_800A8388, &D_800A8394, &D_800A83A0,
      &D_800A83AC, &D_800A83B8, &D_800A83C4, &D_800A83D0 },
};
Battle D_800A8400 = { 0, 0, 0x60040000 };
Battle D_800A840C = { 0, 0, 0x60040000 };
Battle D_800A8418 = { 0, 0, 0x60040000 };
Battle D_800A8424 = { 0, 0, 0x60040000 };
Battle D_800A8430 = { 0, 0, 0x60040000 };
Battle D_800A843C = { 0, 0, 0x60040000 };
Battle D_800A8448 = { 0, 0, 0x60040000 };
Battle D_800A8454 = { 0, 0, 0x60040000 };
BattleList D_800A8460 = {
    0,
    { &D_800A8400, &D_800A840C, &D_800A8418, &D_800A8424,
      &D_800A8430, &D_800A843C, &D_800A8448, &D_800A8454 },
};
Battle D_800A8484 = { 182, 10, 0x60080000 };
Battle D_800A8490 = { 182, 10, 0x60080000 };
Battle D_800A849C = { 182, 10, 0x60080000 };
Battle D_800A84A8 = { 182, 10, 0x60080000 };
Battle D_800A84B4 = { 71, 10, 0x60080000 };
Battle D_800A84C0 = { 71, 10, 0x60080000 };
Battle D_800A84CC = { 71, 10, 0x60080000 };
Battle D_800A84D8 = { 71, 10, 0x60080000 };
BattleList D_800A84E4 = {
    5,
    { &D_800A8484, &D_800A8490, &D_800A849C, &D_800A84A8,
      &D_800A84B4, &D_800A84C0, &D_800A84CC, &D_800A84D8 },
};
Battle D_800A8508 = { 0, 0, 0x60040000 };
Battle D_800A8514 = { 0, 0, 0x60040000 };
Battle D_800A8520 = { 0, 0, 0x60040000 };
Battle D_800A852C = { 0, 0, 0x60040000 };
Battle D_800A8538 = { 0, 0, 0x60040000 };
Battle D_800A8544 = { 0, 0, 0x60040000 };
Battle D_800A8550 = { 0, 0, 0x60040000 };
Battle D_800A855C = { 0, 0, 0x60040000 };
BattleList D_800A8568 = {
    0,
    { &D_800A8508, &D_800A8514, &D_800A8520, &D_800A852C,
      &D_800A8538, &D_800A8544, &D_800A8550, &D_800A855C },
};
Battle D_800A858C = { 0, 0, 0x60040000 };
Battle D_800A8598 = { 0, 0, 0x60040000 };
Battle D_800A85A4 = { 0, 0, 0x60040000 };
Battle D_800A85B0 = { 0, 0, 0x60040000 };
Battle D_800A85BC = { 0, 0, 0x60040000 };
Battle D_800A85C8 = { 0, 0, 0x60040000 };
Battle D_800A85D4 = { 0, 0, 0x60040000 };
Battle D_800A85E0 = { 0, 0, 0x60040000 };
BattleList D_800A85EC = {
    0,
    { &D_800A858C, &D_800A8598, &D_800A85A4, &D_800A85B0,
      &D_800A85BC, &D_800A85C8, &D_800A85D4, &D_800A85E0 },
};
Battle D_800A8610 = { 0, 0, 0x60040000 };
Battle D_800A861C = { 0, 0, 0x60040000 };
Battle D_800A8628 = { 0, 0, 0x60040000 };
Battle D_800A8634 = { 0, 0, 0x60040000 };
Battle D_800A8640 = { 0, 0, 0x60040000 };
Battle D_800A864C = { 0, 0, 0x60040000 };
Battle D_800A8658 = { 0, 0, 0x60040000 };
Battle D_800A8664 = { 0, 0, 0x60040000 };
BattleList D_800A8670 = {
    0,
    { &D_800A8610, &D_800A861C, &D_800A8628, &D_800A8634,
      &D_800A8640, &D_800A864C, &D_800A8658, &D_800A8664 },
};
Battle D_800A8694 = { 182, 10, 0x60080000 };
Battle D_800A86A0 = { 182, 10, 0x60080000 };
Battle D_800A86AC = { 182, 10, 0x60080000 };
Battle D_800A86B8 = { 182, 10, 0x60080000 };
Battle D_800A86C4 = { 71, 10, 0x60080000 };
Battle D_800A86D0 = { 71, 10, 0x60080000 };
Battle D_800A86DC = { 71, 10, 0x60080000 };
Battle D_800A86E8 = { 71, 10, 0x60080000 };
BattleList D_800A86F4 = {
    4,
    { &D_800A8694, &D_800A86A0, &D_800A86AC, &D_800A86B8,
      &D_800A86C4, &D_800A86D0, &D_800A86DC, &D_800A86E8 },
};
Battle D_800A8718 = { 0, 0, 0x60040000 };
Battle D_800A8724 = { 0, 0, 0x60040000 };
Battle D_800A8730 = { 0, 0, 0x60040000 };
Battle D_800A873C = { 0, 0, 0x60040000 };
Battle D_800A8748 = { 0, 0, 0x60040000 };
Battle D_800A8754 = { 0, 0, 0x60040000 };
Battle D_800A8760 = { 0, 0, 0x60040000 };
Battle D_800A876C = { 0, 0, 0x60040000 };
BattleList D_800A8778 = {
    0,
    { &D_800A8718, &D_800A8724, &D_800A8730, &D_800A873C,
      &D_800A8748, &D_800A8754, &D_800A8760, &D_800A876C },
};
Battle D_800A879C = { 0, 0, 0x60040000 };
Battle D_800A87A8 = { 0, 0, 0x60040000 };
Battle D_800A87B4 = { 0, 0, 0x60040000 };
Battle D_800A87C0 = { 0, 0, 0x60040000 };
Battle D_800A87CC = { 0, 0, 0x60040000 };
Battle D_800A87D8 = { 0, 0, 0x60040000 };
Battle D_800A87E4 = { 0, 0, 0x60040000 };
Battle D_800A87F0 = { 0, 0, 0x60040000 };
BattleList D_800A87FC = {
    0,
    { &D_800A879C, &D_800A87A8, &D_800A87B4, &D_800A87C0,
      &D_800A87CC, &D_800A87D8, &D_800A87E4, &D_800A87F0 },
};
Battle D_800A8820 = { 0, 0, 0x60040000 };
Battle D_800A882C = { 0, 0, 0x60040000 };
Battle D_800A8838 = { 0, 0, 0x60040000 };
Battle D_800A8844 = { 0, 0, 0x60040000 };
Battle D_800A8850 = { 0, 0, 0x60040000 };
Battle D_800A885C = { 0, 0, 0x60040000 };
Battle D_800A8868 = { 0, 0, 0x60040000 };
Battle D_800A8874 = { 0, 0, 0x60040000 };
BattleList D_800A8880 = {
    0,
    { &D_800A8820, &D_800A882C, &D_800A8838, &D_800A8844,
      &D_800A8850, &D_800A885C, &D_800A8868, &D_800A8874 },
};
Battle D_800A88A4 = { 182, 10, 0x60080000 };
Battle D_800A88B0 = { 182, 10, 0x60080000 };
Battle D_800A88BC = { 182, 10, 0x60080000 };
Battle D_800A88C8 = { 182, 10, 0x60080000 };
Battle D_800A88D4 = { 71, 10, 0x60080000 };
Battle D_800A88E0 = { 71, 10, 0x60080000 };
Battle D_800A88EC = { 71, 10, 0x60080000 };
Battle D_800A88F8 = { 71, 10, 0x60080000 };
BattleList D_800A8904 = {
    5,
    { &D_800A88A4, &D_800A88B0, &D_800A88BC, &D_800A88C8,
      &D_800A88D4, &D_800A88E0, &D_800A88EC, &D_800A88F8 },
};
Battle D_800A8928 = { 0, 0, 0x60040000 };
Battle D_800A8934 = { 0, 0, 0x60040000 };
Battle D_800A8940 = { 0, 0, 0x60040000 };
Battle D_800A894C = { 0, 0, 0x60040000 };
Battle D_800A8958 = { 0, 0, 0x60040000 };
Battle D_800A8964 = { 0, 0, 0x60040000 };
Battle D_800A8970 = { 0, 0, 0x60040000 };
Battle D_800A897C = { 0, 0, 0x60040000 };
BattleList D_800A8988 = {
    0,
    { &D_800A8928, &D_800A8934, &D_800A8940, &D_800A894C,
      &D_800A8958, &D_800A8964, &D_800A8970, &D_800A897C },
};
Battle D_800A89AC = { 0, 0, 0x60040000 };
Battle D_800A89B8 = { 0, 0, 0x60040000 };
Battle D_800A89C4 = { 0, 0, 0x60040000 };
Battle D_800A89D0 = { 0, 0, 0x60040000 };
Battle D_800A89DC = { 0, 0, 0x60040000 };
Battle D_800A89E8 = { 0, 0, 0x60040000 };
Battle D_800A89F4 = { 0, 0, 0x60040000 };
Battle D_800A8A00 = { 0, 0, 0x60040000 };
BattleList D_800A8A0C = {
    0,
    { &D_800A89AC, &D_800A89B8, &D_800A89C4, &D_800A89D0,
      &D_800A89DC, &D_800A89E8, &D_800A89F4, &D_800A8A00 },
};
Battle D_800A8A30 = { 0, 0, 0x60040000 };
Battle D_800A8A3C = { 0, 0, 0x60040000 };
Battle D_800A8A48 = { 0, 0, 0x60040000 };
Battle D_800A8A54 = { 0, 0, 0x60040000 };
Battle D_800A8A60 = { 0, 0, 0x60040000 };
Battle D_800A8A6C = { 0, 0, 0x60040000 };
Battle D_800A8A78 = { 0, 0, 0x60040000 };
Battle D_800A8A84 = { 0, 0, 0x60040000 };
BattleList D_800A8A90 = {
    0,
    { &D_800A8A30, &D_800A8A3C, &D_800A8A48, &D_800A8A54,
      &D_800A8A60, &D_800A8A6C, &D_800A8A78, &D_800A8A84 },
};
Battle D_800A8AB4 = { 182, 10, 0x60080000 };
Battle D_800A8AC0 = { 182, 10, 0x60080000 };
Battle D_800A8ACC = { 182, 10, 0x60080000 };
Battle D_800A8AD8 = { 182, 10, 0x60080000 };
Battle D_800A8AE4 = { 71, 10, 0x60080000 };
Battle D_800A8AF0 = { 71, 10, 0x60080000 };
Battle D_800A8AFC = { 71, 10, 0x60080000 };
Battle D_800A8B08 = { 71, 10, 0x60080000 };
BattleList D_800A8B14 = {
    1,
    { &D_800A8AB4, &D_800A8AC0, &D_800A8ACC, &D_800A8AD8,
      &D_800A8AE4, &D_800A8AF0, &D_800A8AFC, &D_800A8B08 },
};
Battle D_800A8B38 = { 0, 0, 0x60040000 };
Battle D_800A8B44 = { 0, 0, 0x60040000 };
Battle D_800A8B50 = { 0, 0, 0x60040000 };
Battle D_800A8B5C = { 0, 0, 0x60040000 };
Battle D_800A8B68 = { 0, 0, 0x60040000 };
Battle D_800A8B74 = { 0, 0, 0x60040000 };
Battle D_800A8B80 = { 0, 0, 0x60040000 };
Battle D_800A8B8C = { 0, 0, 0x60040000 };
BattleList D_800A8B98 = {
    0,
    { &D_800A8B38, &D_800A8B44, &D_800A8B50, &D_800A8B5C,
      &D_800A8B68, &D_800A8B74, &D_800A8B80, &D_800A8B8C },
};
Battle D_800A8BBC = { 0, 0, 0x60040000 };
Battle D_800A8BC8 = { 0, 0, 0x60040000 };
Battle D_800A8BD4 = { 0, 0, 0x60040000 };
Battle D_800A8BE0 = { 0, 0, 0x60040000 };
Battle D_800A8BEC = { 0, 0, 0x60040000 };
Battle D_800A8BF8 = { 0, 0, 0x60040000 };
Battle D_800A8C04 = { 0, 0, 0x60040000 };
Battle D_800A8C10 = { 0, 0, 0x60040000 };
BattleList D_800A8C1C = {
    0,
    { &D_800A8BBC, &D_800A8BC8, &D_800A8BD4, &D_800A8BE0,
      &D_800A8BEC, &D_800A8BF8, &D_800A8C04, &D_800A8C10 },
};
Battle D_800A8C40 = { 0, 0, 0x60040000 };
Battle D_800A8C4C = { 0, 0, 0x60040000 };
Battle D_800A8C58 = { 0, 0, 0x60040000 };
Battle D_800A8C64 = { 0, 0, 0x60040000 };
Battle D_800A8C70 = { 0, 0, 0x60040000 };
Battle D_800A8C7C = { 0, 0, 0x60040000 };
Battle D_800A8C88 = { 0, 0, 0x60040000 };
Battle D_800A8C94 = { 0, 0, 0x60040000 };
BattleList D_800A8CA0 = {
    0,
    { &D_800A8C40, &D_800A8C4C, &D_800A8C58, &D_800A8C64,
      &D_800A8C70, &D_800A8C7C, &D_800A8C88, &D_800A8C94 },
};
Battle D_800A8CC4 = { 182, 10, 0x60080000 };
Battle D_800A8CD0 = { 182, 10, 0x60080000 };
Battle D_800A8CDC = { 182, 10, 0x60080000 };
Battle D_800A8CE8 = { 182, 10, 0x60080000 };
Battle D_800A8CF4 = { 71, 10, 0x60080000 };
Battle D_800A8D00 = { 71, 10, 0x60080000 };
Battle D_800A8D0C = { 71, 10, 0x60080000 };
Battle D_800A8D18 = { 71, 10, 0x60080000 };
BattleList D_800A8D24 = {
    1,
    { &D_800A8CC4, &D_800A8CD0, &D_800A8CDC, &D_800A8CE8,
      &D_800A8CF4, &D_800A8D00, &D_800A8D0C, &D_800A8D18 },
};
Battle D_800A8D48 = { 0, 0, 0x60040000 };
Battle D_800A8D54 = { 0, 0, 0x60040000 };
Battle D_800A8D60 = { 0, 0, 0x60040000 };
Battle D_800A8D6C = { 0, 0, 0x60040000 };
Battle D_800A8D78 = { 0, 0, 0x60040000 };
Battle D_800A8D84 = { 0, 0, 0x60040000 };
Battle D_800A8D90 = { 0, 0, 0x60040000 };
Battle D_800A8D9C = { 0, 0, 0x60040000 };
BattleList D_800A8DA8 = {
    0,
    { &D_800A8D48, &D_800A8D54, &D_800A8D60, &D_800A8D6C,
      &D_800A8D78, &D_800A8D84, &D_800A8D90, &D_800A8D9C },
};
Battle D_800A8DCC = { 0, 0, 0x60040000 };
Battle D_800A8DD8 = { 0, 0, 0x60040000 };
Battle D_800A8DE4 = { 0, 0, 0x60040000 };
Battle D_800A8DF0 = { 0, 0, 0x60040000 };
Battle D_800A8DFC = { 0, 0, 0x60040000 };
Battle D_800A8E08 = { 0, 0, 0x60040000 };
Battle D_800A8E14 = { 0, 0, 0x60040000 };
Battle D_800A8E20 = { 0, 0, 0x60040000 };
BattleList D_800A8E2C = {
    0,
    { &D_800A8DCC, &D_800A8DD8, &D_800A8DE4, &D_800A8DF0,
      &D_800A8DFC, &D_800A8E08, &D_800A8E14, &D_800A8E20 },
};
Battle D_800A8E50 = { 0, 0, 0x60040000 };
Battle D_800A8E5C = { 0, 0, 0x60040000 };
Battle D_800A8E68 = { 0, 0, 0x60040000 };
Battle D_800A8E74 = { 0, 0, 0x60040000 };
Battle D_800A8E80 = { 0, 0, 0x60040000 };
Battle D_800A8E8C = { 0, 0, 0x60040000 };
Battle D_800A8E98 = { 0, 0, 0x60040000 };
Battle D_800A8EA4 = { 0, 0, 0x60040000 };
BattleList D_800A8EB0 = {
    0,
    { &D_800A8E50, &D_800A8E5C, &D_800A8E68, &D_800A8E74,
      &D_800A8E80, &D_800A8E8C, &D_800A8E98, &D_800A8EA4 },
};
Battle D_800A8ED4 = { 174, 10, 0x60080000 };
Battle D_800A8EE0 = { 174, 10, 0x60080000 };
Battle D_800A8EEC = { 170, 10, 0x60080000 };
Battle D_800A8EF8 = { 170, 10, 0x60080000 };
Battle D_800A8F04 = { 182, 10, 0x60080000 };
Battle D_800A8F10 = { 182, 10, 0x60080000 };
Battle D_800A8F1C = { 71, 10, 0x60080000 };
Battle D_800A8F28 = { 71, 10, 0x60080000 };
BattleList D_800A8F34 = {
    1,
    { &D_800A8ED4, &D_800A8EE0, &D_800A8EEC, &D_800A8EF8,
      &D_800A8F04, &D_800A8F10, &D_800A8F1C, &D_800A8F28 },
};
Battle D_800A8F58 = { 0, 0, 0x60040000 };
Battle D_800A8F64 = { 0, 0, 0x60040000 };
Battle D_800A8F70 = { 0, 0, 0x60040000 };
Battle D_800A8F7C = { 0, 0, 0x60040000 };
Battle D_800A8F88 = { 0, 0, 0x60040000 };
Battle D_800A8F94 = { 0, 0, 0x60040000 };
Battle D_800A8FA0 = { 0, 0, 0x60040000 };
Battle D_800A8FAC = { 0, 0, 0x60040000 };
BattleList D_800A8FB8 = {
    0,
    { &D_800A8F58, &D_800A8F64, &D_800A8F70, &D_800A8F7C,
      &D_800A8F88, &D_800A8F94, &D_800A8FA0, &D_800A8FAC },
};
Battle D_800A8FDC = { 0, 0, 0x60040000 };
Battle D_800A8FE8 = { 0, 0, 0x60040000 };
Battle D_800A8FF4 = { 0, 0, 0x60040000 };
Battle D_800A9000 = { 0, 0, 0x60040000 };
Battle D_800A900C = { 0, 0, 0x60040000 };
Battle D_800A9018 = { 0, 0, 0x60040000 };
Battle D_800A9024 = { 0, 0, 0x60040000 };
Battle D_800A9030 = { 0, 0, 0x60040000 };
BattleList D_800A903C = {
    0,
    { &D_800A8FDC, &D_800A8FE8, &D_800A8FF4, &D_800A9000,
      &D_800A900C, &D_800A9018, &D_800A9024, &D_800A9030 },
};
Battle D_800A9060 = { 0, 0, 0x60040000 };
Battle D_800A906C = { 0, 0, 0x60040000 };
Battle D_800A9078 = { 0, 0, 0x60040000 };
Battle D_800A9084 = { 0, 0, 0x60040000 };
Battle D_800A9090 = { 0, 0, 0x60040000 };
Battle D_800A909C = { 0, 0, 0x60040000 };
Battle D_800A90A8 = { 0, 0, 0x60040000 };
Battle D_800A90B4 = { 0, 0, 0x60040000 };
BattleList D_800A90C0 = {
    0,
    { &D_800A9060, &D_800A906C, &D_800A9078, &D_800A9084,
      &D_800A9090, &D_800A909C, &D_800A90A8, &D_800A90B4 },
};
FieldBattles stageBattles[] = {
    { 229, 1, 0, { &D_800A5784, &D_800A5808, &D_800A588C, &D_800A5910 } },
    { 235, 2, 0, { &D_800A5994, &D_800A5A18, &D_800A5A9C, &D_800A5B20 } },
    { 241, 3, 0, { &D_800A5BA4, &D_800A5C28, &D_800A5CAC, &D_800A5D30 } },
    { 246, 4, 0, { &D_800A5DB4, &D_800A5E38, &D_800A5EBC, &D_800A5F40 } },
    { 253, 5, 0, { &D_800A5FC4, &D_800A6048, &D_800A60CC, &D_800A6150 } },
    { 259, 6, 0, { &D_800A61D4, &D_800A6258, &D_800A62DC, &D_800A6360 } },
    { 264, 7, 0, { &D_800A63E4, &D_800A6468, &D_800A64EC, &D_800A6570 } },
    { 268, 8, 0, { &D_800A65F4, &D_800A6678, &D_800A66FC, &D_800A6780 } },
    { 273, 9, 0, { &D_800A6804, &D_800A6888, &D_800A690C, &D_800A6990 } },
    { 279, 10, 0, { &D_800A6A14, &D_800A6A98, &D_800A6B1C, &D_800A6BA0 } },
    { 284, 11, 0, { &D_800A6C24, &D_800A6CA8, &D_800A6D2C, &D_800A6DB0 } },
    { 289, 12, 0, { &D_800A6E34, &D_800A6EB8, &D_800A6F3C, &D_800A6FC0 } },
    { 297, 13, 0, { &D_800A7044, &D_800A70C8, &D_800A714C, &D_800A71D0 } },
    { 305, 15, 0, { &D_800A7254, &D_800A72D8, &D_800A735C, &D_800A73E0 } },
    { 308, 16, 0, { &D_800A7464, &D_800A74E8, &D_800A756C, &D_800A75F0 } },
    { 312, 17, 0, { &D_800A7674, &D_800A76F8, &D_800A777C, &D_800A7800 } },
    { 314, 18, 0, { &D_800A7884, &D_800A7908, &D_800A798C, &D_800A7A10 } },
    { 319, 19, 0, { &D_800A7A94, &D_800A7B18, &D_800A7B9C, &D_800A7C20 } },
    { 324, 20, 0, { &D_800A7CA4, &D_800A7D28, &D_800A7DAC, &D_800A7E30 } },
    { 331, 21, 0, { &D_800A7EB4, &D_800A7F38, &D_800A7FBC, &D_800A8040 } },
    { 334, 22, 0, { &D_800A80C4, &D_800A8148, &D_800A81CC, &D_800A8250 } },
    { 338, 23, 0, { &D_800A82D4, &D_800A8358, &D_800A83DC, &D_800A8460 } },
    { 342, 24, 0, { &D_800A84E4, &D_800A8568, &D_800A85EC, &D_800A8670 } },
    { 345, 25, 0, { &D_800A86F4, &D_800A8778, &D_800A87FC, &D_800A8880 } },
    { 350, 26, 0, { &D_800A8904, &D_800A8988, &D_800A8A0C, &D_800A8A90 } },
    { 357, 28, 0, { &D_800A8B14, &D_800A8B98, &D_800A8C1C, &D_800A8CA0 } },
    { 362, 29, 0, { &D_800A8D24, &D_800A8DA8, &D_800A8E2C, &D_800A8EB0 } },
    { 368, 30, 0, { &D_800A8F34, &D_800A8FB8, &D_800A903C, &D_800A90C0 } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x174, 0x100, 0xD0, 0, 0x150, 0x1FF },
    { 0x140, 0x100, 0x174, 0x120, 0xD0, 0x20, 0x160, 0x1FF },
    { 0x140, 0x100, 0x160, 0x140, 0x80, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x14C, 0x140, 0x30, 0x40, 0x170, 0x1FE },
};
FieldTalk D_800A94A4[] = {
    { NULL, NULL, 0x3A6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A94BC[] = {
    { NULL, NULL, 0x3A8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A94D4[] = {
    { NULL, NULL, 0x3A5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A94EC[] = {
    { NULL, NULL, 0x3A7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A9504[] = {
    { NULL, NULL, 0x3A9 },
    { NULL, NULL, 0 },
};
u16 D_800A951C[] = { 0x7E03, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A9528[] = { 0x7E07, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A9534[] = { 0x7E02, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A9540[] = { 0x7E03, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A954C[] = { 0x7E19, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A9558[] = { 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A9564[] = { 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A9570[] = { 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A957C[] = { 0x7E00, 1, 0xA, 0, 0xFFFF };
u16 D_800A9588[] = { 0x7E02, 1, 0xA, 0, 0xFFFF };
u16 D_800A9594[] = { 0x7E04, 1, 0xA, 0, 0xFFFF };
u16 D_800A95A0[] = { 0x7E07, 1, 0xA, 0, 0xFFFF };
u16 D_800A95AC[] = { 0x7E09, 1, 0xA, 0, 0xFFFF };
u16 D_800A95B8[] = { 0x7E0A, 1, 0xA, 0, 0xFFFF };
u16 D_800A95C4[] = { 0x7E15, 1, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A95D0 = { D_800A951C, D_800A94A4, 0x42, 4, 648, 232, 1 };
FieldActorEntry D_800A95E4 = { D_800A9528, D_800A94BC, 0x42, 4, 648, 232, 1 };
FieldActorEntry D_800A95F8 = { D_800A9534, D_800A94D4, 0xB6, 5, 648, 232, 1 };
FieldActorEntry D_800A960C = { D_800A9540, D_800A94EC, 0xB6, 5, 648, 232, 1 };
FieldActorEntry D_800A9620 = { D_800A954C, D_800A9504, 0xB6, 5, 648, 232, 1 };
FieldActorEntry D_800A9634 = { NULL, NULL, 0x146, 6, 0, 0, 0 };
FieldActorEntry D_800A9648 = { D_800A9558, NULL, 0x15F, 7, 224, 336, 1 };
FieldActorEntry D_800A965C = { D_800A9564, NULL, 0x15F, 7, 320, 320, 1 };
FieldActorEntry D_800A9670 = { D_800A9570, NULL, 0x15F, 7, 480, 304, 1 };
FieldActorEntry D_800A9684 = { D_800A957C, NULL, 0x160, 8, 432, 328, 1 };
FieldActorEntry D_800A9698 = { D_800A9588, NULL, 0x160, 8, 368, 344, 1 };
FieldActorEntry D_800A96AC = { D_800A9594, NULL, 0x160, 8, 528, 280, 1 };
FieldActorEntry D_800A96C0 = { D_800A95A0, NULL, 0x160, 8, 528, 280, 1 };
FieldActorEntry D_800A96D4 = { D_800A95AC, NULL, 0x160, 8, 368, 344, 1 };
FieldActorEntry D_800A96E8 = { D_800A95B8, NULL, 0x160, 8, 272, 312, 1 };
FieldActorEntry D_800A96FC = { D_800A95C4, NULL, 0x160, 8, 368, 344, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A95D0,
    &D_800A95E4,
    &D_800A95F8,
    &D_800A960C,
    &D_800A9620,
    &D_800A9634,
    &D_800A9648,
    &D_800A965C,
    &D_800A9670,
    &D_800A9684,
    &D_800A9698,
    &D_800A96AC,
    &D_800A96C0,
    &D_800A96D4,
    &D_800A96E8,
    &D_800A96FC,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x14, 0, 552, 100, 213, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E8, 0x240, 0xD0, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E8, 0xB0, 0x168, 1, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
