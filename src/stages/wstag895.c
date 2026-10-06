#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x689
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x699
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x13B00, 0x21000};
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

extern StagePoint D_800A4F94;
extern StagePoint D_800A4FA4;
extern StagePoint D_800A4FB4;
extern StagePoint D_800A4FCC;
extern StagePoint D_800A4FDC;
extern StagePoint D_800A4FEC;
extern StagePoint D_800A5004;
extern StagePoint D_800A5014;
extern StagePoint D_800A5024;
extern StagePoint D_800A503C;
extern StagePoint D_800A504C;
extern StagePoint D_800A505C;
extern StagePoint D_800A5074;
extern StagePoint D_800A5084;
extern StagePoint D_800A5094;
extern StagePoint D_800A50AC;
extern StagePoint D_800A50BC;
extern StagePoint D_800A50CC;
extern StagePoint D_800A50E4;
extern StagePoint D_800A50F4;
extern StagePoint D_800A5104;
extern StagePoint D_800A511C;
extern StagePoint D_800A512C;
extern StagePoint D_800A513C;
extern StagePoint D_800A5154;
extern StagePoint D_800A5164;
extern StagePoint D_800A5174;
extern StagePoint D_800A518C;
extern StagePoint D_800A519C;
extern StagePoint D_800A51AC;
extern StagePoint D_800A51C4;
extern StagePoint D_800A51D4;
extern StagePoint D_800A51E4;
extern StagePoint D_800A51FC;
extern StagePoint D_800A520C;
extern StagePoint D_800A521C;
extern StagePoint D_800A5234;
extern StagePoint D_800A5244;
extern StagePoint D_800A5254;
extern StagePoint D_800A526C;
extern StagePoint D_800A527C;
extern StagePoint D_800A528C;
extern StagePoint D_800A52A4;
extern StagePoint D_800A52B4;
extern StagePoint D_800A52C4;
extern StagePoint D_800A52DC;
extern StagePoint D_800A52EC;
extern StagePoint D_800A52FC;
extern StagePoint D_800A5314;
extern StagePoint D_800A5324;
extern StagePoint D_800A5334;
extern StagePoint D_800A534C;
extern StagePoint D_800A535C;
extern StagePoint D_800A536C;
extern StagePoint D_800A5384;
extern StagePoint D_800A5394;
extern StagePoint D_800A53A4;
extern StagePoint D_800A53BC;
extern StagePoint D_800A53CC;
extern StagePoint D_800A53DC;
extern StagePoint D_800A53F4;
extern StagePoint D_800A5404;
extern StagePoint D_800A5414;
extern StagePoint D_800A542C;
extern StagePoint D_800A543C;
extern StagePoint D_800A544C;
extern StagePoint D_800A5464;
extern StagePoint D_800A5474;
extern StagePoint D_800A5484;
extern StagePoint D_800A549C;
extern StagePoint D_800A54AC;
extern StagePoint D_800A54BC;
extern StagePoint D_800A54D4;
extern StagePoint D_800A54E4;
extern StagePoint D_800A54F4;
extern StagePoint D_800A550C;
extern StagePoint D_800A551C;
extern StagePoint D_800A552C;
extern StagePoint D_800A5544;
extern StagePoint D_800A5554;
extern StagePoint D_800A5564;
extern StagePoint D_800A557C;
extern StagePoint D_800A558C;
extern StagePoint D_800A559C;
extern StagePoint D_800A55B4;
extern StagePoint D_800A55C4;
extern StagePoint D_800A55D4;
extern StagePoint D_800A55EC;
extern StagePoint D_800A55FC;
extern StagePoint D_800A560C;
extern StagePoint D_800A5624;
extern StagePoint D_800A5634;
extern StagePoint D_800A5644;
extern StagePoint D_800A565C;
extern StagePoint D_800A566C;
extern StagePoint D_800A567C;
extern StagePoint D_800A5694;
extern StagePoint D_800A56A4;
extern StagePoint D_800A56B4;
extern StagePoint D_800A56CC;
extern StagePoint D_800A56DC;
extern StagePoint D_800A56EC;
extern StagePoint D_800A5704;
extern StagePoint D_800A5714;
extern StagePoint D_800A5724;
extern StagePoint D_800A573C;
extern StagePoint D_800A574C;
extern StagePoint D_800A575C;
extern StagePoint D_800A5774;
extern StagePoint D_800A5784;
extern StagePoint D_800A5794;
extern StagePoint D_800A57AC;
extern StagePoint D_800A57BC;
extern StagePoint D_800A57CC;
extern StagePoint D_800A57E4;
extern StagePoint D_800A57F4;
extern StagePoint D_800A5804;
extern StagePoint D_800A581C;
extern StagePoint D_800A582C;
extern StagePoint D_800A583C;
extern StagePoint D_800A5854;
extern StagePoint D_800A5864;
extern StagePoint D_800A5874;
extern StagePoint D_800A588C;
extern StagePoint D_800A589C;
extern StagePoint D_800A58AC;
extern StagePoints D_800A4FC4;
extern StagePoints D_800A4FFC;
extern StagePoints D_800A5034;
extern StagePoints D_800A506C;
extern StagePoints D_800A50A4;
extern StagePoints D_800A50DC;
extern StagePoints D_800A5114;
extern StagePoints D_800A514C;
extern StagePoints D_800A5184;
extern StagePoints D_800A51BC;
extern StagePoints D_800A51F4;
extern StagePoints D_800A522C;
extern StagePoints D_800A5264;
extern StagePoints D_800A529C;
extern StagePoints D_800A52D4;
extern StagePoints D_800A530C;
extern StagePoints D_800A5344;
extern StagePoints D_800A537C;
extern StagePoints D_800A53B4;
extern StagePoints D_800A53EC;
extern StagePoints D_800A5424;
extern StagePoints D_800A545C;
extern StagePoints D_800A5494;
extern StagePoints D_800A54CC;
extern StagePoints D_800A5504;
extern StagePoints D_800A553C;
extern StagePoints D_800A5574;
extern StagePoints D_800A55AC;
extern StagePoints D_800A55E4;
extern StagePoints D_800A561C;
extern StagePoints D_800A5654;
extern StagePoints D_800A568C;
extern StagePoints D_800A56C4;
extern StagePoints D_800A56FC;
extern StagePoints D_800A5734;
extern StagePoints D_800A576C;
extern StagePoints D_800A57A4;
extern StagePoints D_800A57DC;
extern StagePoints D_800A5814;
extern StagePoints D_800A584C;
extern StagePoints D_800A5884;
extern StagePoints D_800A58BC;
extern Battle D_800A5970;
extern Battle D_800A597C;
extern Battle D_800A5988;
extern Battle D_800A5994;
extern Battle D_800A59A0;
extern Battle D_800A59AC;
extern Battle D_800A59B8;
extern Battle D_800A59C4;
extern Battle D_800A59F4;
extern Battle D_800A5A00;
extern Battle D_800A5A0C;
extern Battle D_800A5A18;
extern Battle D_800A5A24;
extern Battle D_800A5A30;
extern Battle D_800A5A3C;
extern Battle D_800A5A48;
extern Battle D_800A5A78;
extern Battle D_800A5A84;
extern Battle D_800A5A90;
extern Battle D_800A5A9C;
extern Battle D_800A5AA8;
extern Battle D_800A5AB4;
extern Battle D_800A5AC0;
extern Battle D_800A5ACC;
extern Battle D_800A5AFC;
extern Battle D_800A5B08;
extern Battle D_800A5B14;
extern Battle D_800A5B20;
extern Battle D_800A5B2C;
extern Battle D_800A5B38;
extern Battle D_800A5B44;
extern Battle D_800A5B50;
extern Battle D_800A5B80;
extern Battle D_800A5B8C;
extern Battle D_800A5B98;
extern Battle D_800A5BA4;
extern Battle D_800A5BB0;
extern Battle D_800A5BBC;
extern Battle D_800A5BC8;
extern Battle D_800A5BD4;
extern Battle D_800A5C04;
extern Battle D_800A5C10;
extern Battle D_800A5C1C;
extern Battle D_800A5C28;
extern Battle D_800A5C34;
extern Battle D_800A5C40;
extern Battle D_800A5C4C;
extern Battle D_800A5C58;
extern Battle D_800A5C88;
extern Battle D_800A5C94;
extern Battle D_800A5CA0;
extern Battle D_800A5CAC;
extern Battle D_800A5CB8;
extern Battle D_800A5CC4;
extern Battle D_800A5CD0;
extern Battle D_800A5CDC;
extern Battle D_800A5D0C;
extern Battle D_800A5D18;
extern Battle D_800A5D24;
extern Battle D_800A5D30;
extern Battle D_800A5D3C;
extern Battle D_800A5D48;
extern Battle D_800A5D54;
extern Battle D_800A5D60;
extern Battle D_800A5D90;
extern Battle D_800A5D9C;
extern Battle D_800A5DA8;
extern Battle D_800A5DB4;
extern Battle D_800A5DC0;
extern Battle D_800A5DCC;
extern Battle D_800A5DD8;
extern Battle D_800A5DE4;
extern Battle D_800A5E14;
extern Battle D_800A5E20;
extern Battle D_800A5E2C;
extern Battle D_800A5E38;
extern Battle D_800A5E44;
extern Battle D_800A5E50;
extern Battle D_800A5E5C;
extern Battle D_800A5E68;
extern Battle D_800A5E98;
extern Battle D_800A5EA4;
extern Battle D_800A5EB0;
extern Battle D_800A5EBC;
extern Battle D_800A5EC8;
extern Battle D_800A5ED4;
extern Battle D_800A5EE0;
extern Battle D_800A5EEC;
extern Battle D_800A5F1C;
extern Battle D_800A5F28;
extern Battle D_800A5F34;
extern Battle D_800A5F40;
extern Battle D_800A5F4C;
extern Battle D_800A5F58;
extern Battle D_800A5F64;
extern Battle D_800A5F70;
extern Battle D_800A5FA0;
extern Battle D_800A5FAC;
extern Battle D_800A5FB8;
extern Battle D_800A5FC4;
extern Battle D_800A5FD0;
extern Battle D_800A5FDC;
extern Battle D_800A5FE8;
extern Battle D_800A5FF4;
extern Battle D_800A6024;
extern Battle D_800A6030;
extern Battle D_800A603C;
extern Battle D_800A6048;
extern Battle D_800A6054;
extern Battle D_800A6060;
extern Battle D_800A606C;
extern Battle D_800A6078;
extern Battle D_800A60A8;
extern Battle D_800A60B4;
extern Battle D_800A60C0;
extern Battle D_800A60CC;
extern Battle D_800A60D8;
extern Battle D_800A60E4;
extern Battle D_800A60F0;
extern Battle D_800A60FC;
extern Battle D_800A612C;
extern Battle D_800A6138;
extern Battle D_800A6144;
extern Battle D_800A6150;
extern Battle D_800A615C;
extern Battle D_800A6168;
extern Battle D_800A6174;
extern Battle D_800A6180;
extern Battle D_800A61B0;
extern Battle D_800A61BC;
extern Battle D_800A61C8;
extern Battle D_800A61D4;
extern Battle D_800A61E0;
extern Battle D_800A61EC;
extern Battle D_800A61F8;
extern Battle D_800A6204;
extern Battle D_800A6234;
extern Battle D_800A6240;
extern Battle D_800A624C;
extern Battle D_800A6258;
extern Battle D_800A6264;
extern Battle D_800A6270;
extern Battle D_800A627C;
extern Battle D_800A6288;
extern Battle D_800A62B8;
extern Battle D_800A62C4;
extern Battle D_800A62D0;
extern Battle D_800A62DC;
extern Battle D_800A62E8;
extern Battle D_800A62F4;
extern Battle D_800A6300;
extern Battle D_800A630C;
extern Battle D_800A633C;
extern Battle D_800A6348;
extern Battle D_800A6354;
extern Battle D_800A6360;
extern Battle D_800A636C;
extern Battle D_800A6378;
extern Battle D_800A6384;
extern Battle D_800A6390;
extern Battle D_800A63C0;
extern Battle D_800A63CC;
extern Battle D_800A63D8;
extern Battle D_800A63E4;
extern Battle D_800A63F0;
extern Battle D_800A63FC;
extern Battle D_800A6408;
extern Battle D_800A6414;
extern Battle D_800A6444;
extern Battle D_800A6450;
extern Battle D_800A645C;
extern Battle D_800A6468;
extern Battle D_800A6474;
extern Battle D_800A6480;
extern Battle D_800A648C;
extern Battle D_800A6498;
extern Battle D_800A64C8;
extern Battle D_800A64D4;
extern Battle D_800A64E0;
extern Battle D_800A64EC;
extern Battle D_800A64F8;
extern Battle D_800A6504;
extern Battle D_800A6510;
extern Battle D_800A651C;
extern Battle D_800A654C;
extern Battle D_800A6558;
extern Battle D_800A6564;
extern Battle D_800A6570;
extern Battle D_800A657C;
extern Battle D_800A6588;
extern Battle D_800A6594;
extern Battle D_800A65A0;
extern Battle D_800A65D0;
extern Battle D_800A65DC;
extern Battle D_800A65E8;
extern Battle D_800A65F4;
extern Battle D_800A6600;
extern Battle D_800A660C;
extern Battle D_800A6618;
extern Battle D_800A6624;
extern Battle D_800A6654;
extern Battle D_800A6660;
extern Battle D_800A666C;
extern Battle D_800A6678;
extern Battle D_800A6684;
extern Battle D_800A6690;
extern Battle D_800A669C;
extern Battle D_800A66A8;
extern Battle D_800A66D8;
extern Battle D_800A66E4;
extern Battle D_800A66F0;
extern Battle D_800A66FC;
extern Battle D_800A6708;
extern Battle D_800A6714;
extern Battle D_800A6720;
extern Battle D_800A672C;
extern Battle D_800A675C;
extern Battle D_800A6768;
extern Battle D_800A6774;
extern Battle D_800A6780;
extern Battle D_800A678C;
extern Battle D_800A6798;
extern Battle D_800A67A4;
extern Battle D_800A67B0;
extern Battle D_800A67E0;
extern Battle D_800A67EC;
extern Battle D_800A67F8;
extern Battle D_800A6804;
extern Battle D_800A6810;
extern Battle D_800A681C;
extern Battle D_800A6828;
extern Battle D_800A6834;
extern Battle D_800A6864;
extern Battle D_800A6870;
extern Battle D_800A687C;
extern Battle D_800A6888;
extern Battle D_800A6894;
extern Battle D_800A68A0;
extern Battle D_800A68AC;
extern Battle D_800A68B8;
extern Battle D_800A68E8;
extern Battle D_800A68F4;
extern Battle D_800A6900;
extern Battle D_800A690C;
extern Battle D_800A6918;
extern Battle D_800A6924;
extern Battle D_800A6930;
extern Battle D_800A693C;
extern Battle D_800A696C;
extern Battle D_800A6978;
extern Battle D_800A6984;
extern Battle D_800A6990;
extern Battle D_800A699C;
extern Battle D_800A69A8;
extern Battle D_800A69B4;
extern Battle D_800A69C0;
extern Battle D_800A69F0;
extern Battle D_800A69FC;
extern Battle D_800A6A08;
extern Battle D_800A6A14;
extern Battle D_800A6A20;
extern Battle D_800A6A2C;
extern Battle D_800A6A38;
extern Battle D_800A6A44;
extern Battle D_800A6A74;
extern Battle D_800A6A80;
extern Battle D_800A6A8C;
extern Battle D_800A6A98;
extern Battle D_800A6AA4;
extern Battle D_800A6AB0;
extern Battle D_800A6ABC;
extern Battle D_800A6AC8;
extern Battle D_800A6AF8;
extern Battle D_800A6B04;
extern Battle D_800A6B10;
extern Battle D_800A6B1C;
extern Battle D_800A6B28;
extern Battle D_800A6B34;
extern Battle D_800A6B40;
extern Battle D_800A6B4C;
extern Battle D_800A6B7C;
extern Battle D_800A6B88;
extern Battle D_800A6B94;
extern Battle D_800A6BA0;
extern Battle D_800A6BAC;
extern Battle D_800A6BB8;
extern Battle D_800A6BC4;
extern Battle D_800A6BD0;
extern Battle D_800A6C00;
extern Battle D_800A6C0C;
extern Battle D_800A6C18;
extern Battle D_800A6C24;
extern Battle D_800A6C30;
extern Battle D_800A6C3C;
extern Battle D_800A6C48;
extern Battle D_800A6C54;
extern Battle D_800A6C84;
extern Battle D_800A6C90;
extern Battle D_800A6C9C;
extern Battle D_800A6CA8;
extern Battle D_800A6CB4;
extern Battle D_800A6CC0;
extern Battle D_800A6CCC;
extern Battle D_800A6CD8;
extern Battle D_800A6D08;
extern Battle D_800A6D14;
extern Battle D_800A6D20;
extern Battle D_800A6D2C;
extern Battle D_800A6D38;
extern Battle D_800A6D44;
extern Battle D_800A6D50;
extern Battle D_800A6D5C;
extern Battle D_800A6D8C;
extern Battle D_800A6D98;
extern Battle D_800A6DA4;
extern Battle D_800A6DB0;
extern Battle D_800A6DBC;
extern Battle D_800A6DC8;
extern Battle D_800A6DD4;
extern Battle D_800A6DE0;
extern Battle D_800A6E10;
extern Battle D_800A6E1C;
extern Battle D_800A6E28;
extern Battle D_800A6E34;
extern Battle D_800A6E40;
extern Battle D_800A6E4C;
extern Battle D_800A6E58;
extern Battle D_800A6E64;
extern Battle D_800A6E94;
extern Battle D_800A6EA0;
extern Battle D_800A6EAC;
extern Battle D_800A6EB8;
extern Battle D_800A6EC4;
extern Battle D_800A6ED0;
extern Battle D_800A6EDC;
extern Battle D_800A6EE8;
extern Battle D_800A6F18;
extern Battle D_800A6F24;
extern Battle D_800A6F30;
extern Battle D_800A6F3C;
extern Battle D_800A6F48;
extern Battle D_800A6F54;
extern Battle D_800A6F60;
extern Battle D_800A6F6C;
extern Battle D_800A6F9C;
extern Battle D_800A6FA8;
extern Battle D_800A6FB4;
extern Battle D_800A6FC0;
extern Battle D_800A6FCC;
extern Battle D_800A6FD8;
extern Battle D_800A6FE4;
extern Battle D_800A6FF0;
extern Battle D_800A7020;
extern Battle D_800A702C;
extern Battle D_800A7038;
extern Battle D_800A7044;
extern Battle D_800A7050;
extern Battle D_800A705C;
extern Battle D_800A7068;
extern Battle D_800A7074;
extern Battle D_800A70A4;
extern Battle D_800A70B0;
extern Battle D_800A70BC;
extern Battle D_800A70C8;
extern Battle D_800A70D4;
extern Battle D_800A70E0;
extern Battle D_800A70EC;
extern Battle D_800A70F8;
extern Battle D_800A7128;
extern Battle D_800A7134;
extern Battle D_800A7140;
extern Battle D_800A714C;
extern Battle D_800A7158;
extern Battle D_800A7164;
extern Battle D_800A7170;
extern Battle D_800A717C;
extern Battle D_800A71AC;
extern Battle D_800A71B8;
extern Battle D_800A71C4;
extern Battle D_800A71D0;
extern Battle D_800A71DC;
extern Battle D_800A71E8;
extern Battle D_800A71F4;
extern Battle D_800A7200;
extern Battle D_800A7230;
extern Battle D_800A723C;
extern Battle D_800A7248;
extern Battle D_800A7254;
extern Battle D_800A7260;
extern Battle D_800A726C;
extern Battle D_800A7278;
extern Battle D_800A7284;
extern Battle D_800A72B4;
extern Battle D_800A72C0;
extern Battle D_800A72CC;
extern Battle D_800A72D8;
extern Battle D_800A72E4;
extern Battle D_800A72F0;
extern Battle D_800A72FC;
extern Battle D_800A7308;
extern Battle D_800A7338;
extern Battle D_800A7344;
extern Battle D_800A7350;
extern Battle D_800A735C;
extern Battle D_800A7368;
extern Battle D_800A7374;
extern Battle D_800A7380;
extern Battle D_800A738C;
extern Battle D_800A73BC;
extern Battle D_800A73C8;
extern Battle D_800A73D4;
extern Battle D_800A73E0;
extern Battle D_800A73EC;
extern Battle D_800A73F8;
extern Battle D_800A7404;
extern Battle D_800A7410;
extern Battle D_800A7440;
extern Battle D_800A744C;
extern Battle D_800A7458;
extern Battle D_800A7464;
extern Battle D_800A7470;
extern Battle D_800A747C;
extern Battle D_800A7488;
extern Battle D_800A7494;
extern Battle D_800A74C4;
extern Battle D_800A74D0;
extern Battle D_800A74DC;
extern Battle D_800A74E8;
extern Battle D_800A74F4;
extern Battle D_800A7500;
extern Battle D_800A750C;
extern Battle D_800A7518;
extern Battle D_800A7548;
extern Battle D_800A7554;
extern Battle D_800A7560;
extern Battle D_800A756C;
extern Battle D_800A7578;
extern Battle D_800A7584;
extern Battle D_800A7590;
extern Battle D_800A759C;
extern Battle D_800A75CC;
extern Battle D_800A75D8;
extern Battle D_800A75E4;
extern Battle D_800A75F0;
extern Battle D_800A75FC;
extern Battle D_800A7608;
extern Battle D_800A7614;
extern Battle D_800A7620;
extern Battle D_800A7650;
extern Battle D_800A765C;
extern Battle D_800A7668;
extern Battle D_800A7674;
extern Battle D_800A7680;
extern Battle D_800A768C;
extern Battle D_800A7698;
extern Battle D_800A76A4;
extern Battle D_800A76D4;
extern Battle D_800A76E0;
extern Battle D_800A76EC;
extern Battle D_800A76F8;
extern Battle D_800A7704;
extern Battle D_800A7710;
extern Battle D_800A771C;
extern Battle D_800A7728;
extern Battle D_800A7758;
extern Battle D_800A7764;
extern Battle D_800A7770;
extern Battle D_800A777C;
extern Battle D_800A7788;
extern Battle D_800A7794;
extern Battle D_800A77A0;
extern Battle D_800A77AC;
extern Battle D_800A77DC;
extern Battle D_800A77E8;
extern Battle D_800A77F4;
extern Battle D_800A7800;
extern Battle D_800A780C;
extern Battle D_800A7818;
extern Battle D_800A7824;
extern Battle D_800A7830;
extern Battle D_800A7860;
extern Battle D_800A786C;
extern Battle D_800A7878;
extern Battle D_800A7884;
extern Battle D_800A7890;
extern Battle D_800A789C;
extern Battle D_800A78A8;
extern Battle D_800A78B4;
extern Battle D_800A78E4;
extern Battle D_800A78F0;
extern Battle D_800A78FC;
extern Battle D_800A7908;
extern Battle D_800A7914;
extern Battle D_800A7920;
extern Battle D_800A792C;
extern Battle D_800A7938;
extern Battle D_800A7968;
extern Battle D_800A7974;
extern Battle D_800A7980;
extern Battle D_800A798C;
extern Battle D_800A7998;
extern Battle D_800A79A4;
extern Battle D_800A79B0;
extern Battle D_800A79BC;
extern Battle D_800A79EC;
extern Battle D_800A79F8;
extern Battle D_800A7A04;
extern Battle D_800A7A10;
extern Battle D_800A7A1C;
extern Battle D_800A7A28;
extern Battle D_800A7A34;
extern Battle D_800A7A40;
extern Battle D_800A7A70;
extern Battle D_800A7A7C;
extern Battle D_800A7A88;
extern Battle D_800A7A94;
extern Battle D_800A7AA0;
extern Battle D_800A7AAC;
extern Battle D_800A7AB8;
extern Battle D_800A7AC4;
extern Battle D_800A7AF4;
extern Battle D_800A7B00;
extern Battle D_800A7B0C;
extern Battle D_800A7B18;
extern Battle D_800A7B24;
extern Battle D_800A7B30;
extern Battle D_800A7B3C;
extern Battle D_800A7B48;
extern Battle D_800A7B78;
extern Battle D_800A7B84;
extern Battle D_800A7B90;
extern Battle D_800A7B9C;
extern Battle D_800A7BA8;
extern Battle D_800A7BB4;
extern Battle D_800A7BC0;
extern Battle D_800A7BCC;
extern Battle D_800A7BFC;
extern Battle D_800A7C08;
extern Battle D_800A7C14;
extern Battle D_800A7C20;
extern Battle D_800A7C2C;
extern Battle D_800A7C38;
extern Battle D_800A7C44;
extern Battle D_800A7C50;
extern Battle D_800A7C80;
extern Battle D_800A7C8C;
extern Battle D_800A7C98;
extern Battle D_800A7CA4;
extern Battle D_800A7CB0;
extern Battle D_800A7CBC;
extern Battle D_800A7CC8;
extern Battle D_800A7CD4;
extern Battle D_800A7D04;
extern Battle D_800A7D10;
extern Battle D_800A7D1C;
extern Battle D_800A7D28;
extern Battle D_800A7D34;
extern Battle D_800A7D40;
extern Battle D_800A7D4C;
extern Battle D_800A7D58;
extern Battle D_800A7D88;
extern Battle D_800A7D94;
extern Battle D_800A7DA0;
extern Battle D_800A7DAC;
extern Battle D_800A7DB8;
extern Battle D_800A7DC4;
extern Battle D_800A7DD0;
extern Battle D_800A7DDC;
extern Battle D_800A7E0C;
extern Battle D_800A7E18;
extern Battle D_800A7E24;
extern Battle D_800A7E30;
extern Battle D_800A7E3C;
extern Battle D_800A7E48;
extern Battle D_800A7E54;
extern Battle D_800A7E60;
extern Battle D_800A7E90;
extern Battle D_800A7E9C;
extern Battle D_800A7EA8;
extern Battle D_800A7EB4;
extern Battle D_800A7EC0;
extern Battle D_800A7ECC;
extern Battle D_800A7ED8;
extern Battle D_800A7EE4;
extern Battle D_800A7F14;
extern Battle D_800A7F20;
extern Battle D_800A7F2C;
extern Battle D_800A7F38;
extern Battle D_800A7F44;
extern Battle D_800A7F50;
extern Battle D_800A7F5C;
extern Battle D_800A7F68;
extern Battle D_800A7F98;
extern Battle D_800A7FA4;
extern Battle D_800A7FB0;
extern Battle D_800A7FBC;
extern Battle D_800A7FC8;
extern Battle D_800A7FD4;
extern Battle D_800A7FE0;
extern Battle D_800A7FEC;
extern Battle D_800A801C;
extern Battle D_800A8028;
extern Battle D_800A8034;
extern Battle D_800A8040;
extern Battle D_800A804C;
extern Battle D_800A8058;
extern Battle D_800A8064;
extern Battle D_800A8070;
extern Battle D_800A80A0;
extern Battle D_800A80AC;
extern Battle D_800A80B8;
extern Battle D_800A80C4;
extern Battle D_800A80D0;
extern Battle D_800A80DC;
extern Battle D_800A80E8;
extern Battle D_800A80F4;
extern Battle D_800A8124;
extern Battle D_800A8130;
extern Battle D_800A813C;
extern Battle D_800A8148;
extern Battle D_800A8154;
extern Battle D_800A8160;
extern Battle D_800A816C;
extern Battle D_800A8178;
extern Battle D_800A81A8;
extern Battle D_800A81B4;
extern Battle D_800A81C0;
extern Battle D_800A81CC;
extern Battle D_800A81D8;
extern Battle D_800A81E4;
extern Battle D_800A81F0;
extern Battle D_800A81FC;
extern Battle D_800A822C;
extern Battle D_800A8238;
extern Battle D_800A8244;
extern Battle D_800A8250;
extern Battle D_800A825C;
extern Battle D_800A8268;
extern Battle D_800A8274;
extern Battle D_800A8280;
extern Battle D_800A82B0;
extern Battle D_800A82BC;
extern Battle D_800A82C8;
extern Battle D_800A82D4;
extern Battle D_800A82E0;
extern Battle D_800A82EC;
extern Battle D_800A82F8;
extern Battle D_800A8304;
extern Battle D_800A8334;
extern Battle D_800A8340;
extern Battle D_800A834C;
extern Battle D_800A8358;
extern Battle D_800A8364;
extern Battle D_800A8370;
extern Battle D_800A837C;
extern Battle D_800A8388;
extern Battle D_800A83B8;
extern Battle D_800A83C4;
extern Battle D_800A83D0;
extern Battle D_800A83DC;
extern Battle D_800A83E8;
extern Battle D_800A83F4;
extern Battle D_800A8400;
extern Battle D_800A840C;
extern Battle D_800A843C;
extern Battle D_800A8448;
extern Battle D_800A8454;
extern Battle D_800A8460;
extern Battle D_800A846C;
extern Battle D_800A8478;
extern Battle D_800A8484;
extern Battle D_800A8490;
extern Battle D_800A84C0;
extern Battle D_800A84CC;
extern Battle D_800A84D8;
extern Battle D_800A84E4;
extern Battle D_800A84F0;
extern Battle D_800A84FC;
extern Battle D_800A8508;
extern Battle D_800A8514;
extern Battle D_800A8544;
extern Battle D_800A8550;
extern Battle D_800A855C;
extern Battle D_800A8568;
extern Battle D_800A8574;
extern Battle D_800A8580;
extern Battle D_800A858C;
extern Battle D_800A8598;
extern Battle D_800A85C8;
extern Battle D_800A85D4;
extern Battle D_800A85E0;
extern Battle D_800A85EC;
extern Battle D_800A85F8;
extern Battle D_800A8604;
extern Battle D_800A8610;
extern Battle D_800A861C;
extern Battle D_800A864C;
extern Battle D_800A8658;
extern Battle D_800A8664;
extern Battle D_800A8670;
extern Battle D_800A867C;
extern Battle D_800A8688;
extern Battle D_800A8694;
extern Battle D_800A86A0;
extern Battle D_800A86D0;
extern Battle D_800A86DC;
extern Battle D_800A86E8;
extern Battle D_800A86F4;
extern Battle D_800A8700;
extern Battle D_800A870C;
extern Battle D_800A8718;
extern Battle D_800A8724;
extern Battle D_800A8754;
extern Battle D_800A8760;
extern Battle D_800A876C;
extern Battle D_800A8778;
extern Battle D_800A8784;
extern Battle D_800A8790;
extern Battle D_800A879C;
extern Battle D_800A87A8;
extern Battle D_800A87D8;
extern Battle D_800A87E4;
extern Battle D_800A87F0;
extern Battle D_800A87FC;
extern Battle D_800A8808;
extern Battle D_800A8814;
extern Battle D_800A8820;
extern Battle D_800A882C;
extern Battle D_800A885C;
extern Battle D_800A8868;
extern Battle D_800A8874;
extern Battle D_800A8880;
extern Battle D_800A888C;
extern Battle D_800A8898;
extern Battle D_800A88A4;
extern Battle D_800A88B0;
extern BattleList D_800A59D0;
extern BattleList D_800A5A54;
extern BattleList D_800A5AD8;
extern BattleList D_800A5B5C;
extern BattleList D_800A5BE0;
extern BattleList D_800A5C64;
extern BattleList D_800A5CE8;
extern BattleList D_800A5D6C;
extern BattleList D_800A5DF0;
extern BattleList D_800A5E74;
extern BattleList D_800A5EF8;
extern BattleList D_800A5F7C;
extern BattleList D_800A6000;
extern BattleList D_800A6084;
extern BattleList D_800A6108;
extern BattleList D_800A618C;
extern BattleList D_800A6210;
extern BattleList D_800A6294;
extern BattleList D_800A6318;
extern BattleList D_800A639C;
extern BattleList D_800A6420;
extern BattleList D_800A64A4;
extern BattleList D_800A6528;
extern BattleList D_800A65AC;
extern BattleList D_800A6630;
extern BattleList D_800A66B4;
extern BattleList D_800A6738;
extern BattleList D_800A67BC;
extern BattleList D_800A6840;
extern BattleList D_800A68C4;
extern BattleList D_800A6948;
extern BattleList D_800A69CC;
extern BattleList D_800A6A50;
extern BattleList D_800A6AD4;
extern BattleList D_800A6B58;
extern BattleList D_800A6BDC;
extern BattleList D_800A6C60;
extern BattleList D_800A6CE4;
extern BattleList D_800A6D68;
extern BattleList D_800A6DEC;
extern BattleList D_800A6E70;
extern BattleList D_800A6EF4;
extern BattleList D_800A6F78;
extern BattleList D_800A6FFC;
extern BattleList D_800A7080;
extern BattleList D_800A7104;
extern BattleList D_800A7188;
extern BattleList D_800A720C;
extern BattleList D_800A7290;
extern BattleList D_800A7314;
extern BattleList D_800A7398;
extern BattleList D_800A741C;
extern BattleList D_800A74A0;
extern BattleList D_800A7524;
extern BattleList D_800A75A8;
extern BattleList D_800A762C;
extern BattleList D_800A76B0;
extern BattleList D_800A7734;
extern BattleList D_800A77B8;
extern BattleList D_800A783C;
extern BattleList D_800A78C0;
extern BattleList D_800A7944;
extern BattleList D_800A79C8;
extern BattleList D_800A7A4C;
extern BattleList D_800A7AD0;
extern BattleList D_800A7B54;
extern BattleList D_800A7BD8;
extern BattleList D_800A7C5C;
extern BattleList D_800A7CE0;
extern BattleList D_800A7D64;
extern BattleList D_800A7DE8;
extern BattleList D_800A7E6C;
extern BattleList D_800A7EF0;
extern BattleList D_800A7F74;
extern BattleList D_800A7FF8;
extern BattleList D_800A807C;
extern BattleList D_800A8100;
extern BattleList D_800A8184;
extern BattleList D_800A8208;
extern BattleList D_800A828C;
extern BattleList D_800A8310;
extern BattleList D_800A8394;
extern BattleList D_800A8418;
extern BattleList D_800A849C;
extern BattleList D_800A8520;
extern BattleList D_800A85A4;
extern BattleList D_800A8628;
extern BattleList D_800A86AC;
extern BattleList D_800A8730;
extern BattleList D_800A87B4;
extern BattleList D_800A8838;
extern BattleList D_800A88BC;
extern u16 D_800A8E8C[];
extern FieldTalk D_800A8C94[];
extern u16 D_800A8E98[];
extern FieldTalk D_800A8CAC[];
extern u16 D_800A8EA4[];
extern FieldTalk D_800A8CC4[];
extern u16 D_800A8EB0[];
extern FieldTalk D_800A8CDC[];
extern u16 D_800A8EBC[];
extern FieldTalk D_800A8CF4[];
extern u16 D_800A8EC8[];
extern FieldTalk D_800A8D0C[];
extern u16 D_800A8ED4[];
extern FieldTalk D_800A8D24[];
extern u16 D_800A8EE0[];
extern FieldTalk D_800A8D3C[];
extern u16 D_800A8EEC[];
extern FieldTalk D_800A8D54[];
extern u16 D_800A8EF8[];
extern FieldTalk D_800A8D6C[];
extern u16 D_800A8F04[];
extern FieldTalk D_800A8D84[];
extern u16 D_800A8F10[];
extern FieldTalk D_800A8D9C[];
extern u16 D_800A8F1C[];
extern FieldTalk D_800A8DB4[];
extern u16 D_800A8F28[];
extern FieldTalk D_800A8DCC[];
extern u16 D_800A8F34[];
extern FieldTalk D_800A8DE4[];
extern u16 D_800A8F40[];
extern FieldTalk D_800A8DFC[];
extern u16 D_800A8F4C[];
extern FieldTalk D_800A8E14[];
extern u16 D_800A8F58[];
extern FieldTalk D_800A8E2C[];
extern u16 D_800A8F64[];
extern FieldTalk D_800A8E44[];
extern u16 D_800A8F70[];
extern FieldTalk D_800A8E5C[];
extern u16 D_800A8F7C[];
extern FieldTalk D_800A8E74[];
extern u16 D_800A8F88[];
extern u16 D_800A8F94[];
extern u16 D_800A8FA0[];
extern u16 D_800A8FAC[];
extern u16 D_800A8FB8[];
extern u16 D_800A8FC4[];
extern u16 D_800A8FD0[];
extern u16 D_800A8FDC[];
extern u16 D_800A8FE8[];
extern u16 D_800A8FF4[];
extern u16 D_800A9000[];
extern u16 D_800A900C[];
extern u16 D_800A9018[];
extern u16 D_800A9024[];
extern u16 D_800A9030[];
extern u16 D_800A903C[];
extern FieldActorEntry D_800A9048;
extern FieldActorEntry D_800A905C;
extern FieldActorEntry D_800A9070;
extern FieldActorEntry D_800A9084;
extern FieldActorEntry D_800A9098;
extern FieldActorEntry D_800A90AC;
extern FieldActorEntry D_800A90C0;
extern FieldActorEntry D_800A90D4;
extern FieldActorEntry D_800A90E8;
extern FieldActorEntry D_800A90FC;
extern FieldActorEntry D_800A9110;
extern FieldActorEntry D_800A9124;
extern FieldActorEntry D_800A9138;
extern FieldActorEntry D_800A914C;
extern FieldActorEntry D_800A9160;
extern FieldActorEntry D_800A9174;
extern FieldActorEntry D_800A9188;
extern FieldActorEntry D_800A919C;
extern FieldActorEntry D_800A91B0;
extern FieldActorEntry D_800A91C4;
extern FieldActorEntry D_800A91D8;
extern FieldActorEntry D_800A91EC;
extern FieldActorEntry D_800A9200;
extern FieldActorEntry D_800A9214;
extern FieldActorEntry D_800A9228;
extern FieldActorEntry D_800A923C;
extern FieldActorEntry D_800A9250;
extern FieldActorEntry D_800A9264;
extern FieldActorEntry D_800A9278;
extern FieldActorEntry D_800A928C;
extern FieldActorEntry D_800A92A0;
extern FieldActorEntry D_800A92B4;
extern FieldActorEntry D_800A92C8;
extern FieldActorEntry D_800A92DC;
extern FieldActorEntry D_800A92F0;
extern FieldActorEntry D_800A9304;
extern FieldActorEntry D_800A9318;
extern FieldActorEntry D_800A932C;

StagePoint D_800A4F94 = { 0x2E9, 1, 2, 0x240, 240, 1, NULL };
StagePoint D_800A4FA4 = { 0x2ED, 1, 1, 0x350, 0x1F8, 5, &D_800A4F94 };
StagePoint D_800A4FB4 = { 0x2ED, 1, 2, 224, 192, 5, &D_800A4FA4 };
StagePoints D_800A4FC4 = { 1, 1, &D_800A4FB4 };
StagePoint D_800A4FCC = { 0x2ED, 2, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A4FDC = { 0x2EC, 2, 1, 240, 0x1D8, 5, &D_800A4FCC };
StagePoint D_800A4FEC = { 0x2ED, 2, 1, 224, 192, 5, &D_800A4FDC };
StagePoints D_800A4FFC = { 2, 1, &D_800A4FEC };
StagePoint D_800A5004 = { 0x2E9, 2, 3, 0x240, 240, 1, NULL };
StagePoint D_800A5014 = { 0x2EA, 2, 2, 224, 0x200, 5, &D_800A5004 };
StagePoint D_800A5024 = { 0x2ED, 2, 2, 224, 192, 5, &D_800A5014 };
StagePoints D_800A5034 = { 2, 2, &D_800A5024 };
StagePoint D_800A503C = { 0x2ED, 3, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A504C = { 0x2EC, 3, 1, 240, 0x1D8, 5, &D_800A503C };
StagePoint D_800A505C = { 0x2ED, 3, 1, 224, 192, 5, &D_800A504C };
StagePoints D_800A506C = { 3, 1, &D_800A505C };
StagePoint D_800A5074 = { 0x2ED, 3, 3, 0x3A0, 128, 1, NULL };
StagePoint D_800A5084 = { 0x2ED, 3, 1, 0x350, 0x1F8, 5, &D_800A5074 };
StagePoint D_800A5094 = { 0x2E8, 3, 3, 176, 0x168, 5, &D_800A5084 };
StagePoints D_800A50A4 = { 3, 2, &D_800A5094 };
StagePoint D_800A50AC = { 0x2E9, 3, 2, 0x240, 240, 1, NULL };
StagePoint D_800A50BC = { 0x2ED, 3, 2, 0x350, 0x1F8, 5, &D_800A50AC };
StagePoint D_800A50CC = { 0x2ED, 3, 3, 224, 192, 5, &D_800A50BC };
StagePoints D_800A50DC = { 3, 3, &D_800A50CC };
StagePoint D_800A50E4 = { 0x2E9, 3, 3, 0x240, 240, 1, NULL };
StagePoint D_800A50F4 = { 0x2ED, 3, 3, 0x350, 0x1F8, 5, &D_800A50E4 };
StagePoint D_800A5104 = { 0x2ED, 3, 4, 224, 192, 5, &D_800A50F4 };
StagePoints D_800A5114 = { 3, 4, &D_800A5104 };
StagePoint D_800A511C = { 0x2E9, 3, 4, 0x240, 240, 1, NULL };
StagePoint D_800A512C = { 0x2ED, 3, 4, 0x350, 0x1F8, 5, &D_800A511C };
StagePoint D_800A513C = { 0x2E8, 3, 5, 176, 0x168, 5, &D_800A512C };
StagePoints D_800A514C = { 3, 5, &D_800A513C };
StagePoint D_800A5154 = { 0x2ED, 4, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A5164 = { 0x2E8, 4, 1, 176, 0x168, 5, &D_800A5154 };
StagePoint D_800A5174 = { 0x2EA, 4, 1, 224, 0x200, 5, &D_800A5164 };
StagePoints D_800A5184 = { 4, 1, &D_800A5174 };
StagePoint D_800A518C = { 0x2ED, 4, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A519C = { 0x2E8, 4, 2, 176, 0x168, 5, &D_800A518C };
StagePoint D_800A51AC = { 0x2ED, 4, 1, 224, 192, 5, &D_800A519C };
StagePoints D_800A51BC = { 4, 2, &D_800A51AC };
StagePoint D_800A51C4 = { 0x2ED, 5, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A51D4 = { 0x2E8, 5, 1, 176, 0x168, 5, &D_800A51C4 };
StagePoint D_800A51E4 = { 0x2ED, 5, 1, 224, 192, 5, &D_800A51D4 };
StagePoints D_800A51F4 = { 5, 1, &D_800A51E4 };
StagePoint D_800A51FC = { 0x2ED, 5, 3, 0x3A0, 128, 1, NULL };
StagePoint D_800A520C = { 0x2ED, 5, 1, 0x350, 0x1F8, 5, &D_800A51FC };
StagePoint D_800A521C = { 0x2E8, 5, 2, 176, 0x168, 5, &D_800A520C };
StagePoints D_800A522C = { 5, 2, &D_800A521C };
StagePoint D_800A5234 = { 0x2E9, 5, 2, 0x240, 240, 1, NULL };
StagePoint D_800A5244 = { 0x2ED, 5, 2, 0x350, 0x1F8, 5, &D_800A5234 };
StagePoint D_800A5254 = { 0x2ED, 5, 3, 224, 192, 5, &D_800A5244 };
StagePoints D_800A5264 = { 5, 3, &D_800A5254 };
StagePoint D_800A526C = { 0x2E9, 5, 3, 0x240, 240, 1, NULL };
StagePoint D_800A527C = { 0x2ED, 5, 3, 0x350, 0x1F8, 5, &D_800A526C };
StagePoint D_800A528C = { 0x2ED, 5, 4, 224, 192, 5, &D_800A527C };
StagePoints D_800A529C = { 5, 4, &D_800A528C };
StagePoint D_800A52A4 = { 0x2E9, 6, 1, 0x240, 240, 1, NULL };
StagePoint D_800A52B4 = { 0x2EC, 6, 1, 240, 0x1D8, 5, &D_800A52A4 };
StagePoint D_800A52C4 = { 0x2ED, 6, 1, 224, 192, 5, &D_800A52B4 };
StagePoints D_800A52D4 = { 6, 1, &D_800A52C4 };
StagePoint D_800A52DC = { 0x2EE, 6, 3, 0x130, 200, 1, NULL };
StagePoint D_800A52EC = { 0x2ED, 6, 1, 0x350, 0x1F8, 5, &D_800A52DC };
StagePoint D_800A52FC = { 0x2ED, 6, 2, 224, 192, 5, &D_800A52EC };
StagePoints D_800A530C = { 6, 2, &D_800A52FC };
StagePoint D_800A5314 = { 0x2E9, 6, 2, 0x240, 240, 1, NULL };
StagePoint D_800A5324 = { 0x2EE, 6, 2, 224, 0x240, 5, &D_800A5314 };
StagePoint D_800A5334 = { 0x2EC, 6, 2, 240, 0x1D8, 5, &D_800A5324 };
StagePoints D_800A5344 = { 6, 3, &D_800A5334 };
StagePoint D_800A534C = { 0x2EC, 7, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A535C = { 0x2EC, 7, 1, 240, 0x1D8, 5, &D_800A534C };
StagePoint D_800A536C = { 0x2EC, 7, 2, 240, 0x1D8, 5, &D_800A535C };
StagePoints D_800A537C = { 7, 1, &D_800A536C };
StagePoint D_800A5384 = { 0x2EB, 7, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5394 = { 0x2EC, 7, 3, 240, 0x1D8, 5, &D_800A5384 };
StagePoint D_800A53A4 = { 0x2E8, 7, 3, 176, 0x168, 5, &D_800A5394 };
StagePoints D_800A53B4 = { 7, 2, &D_800A53A4 };
StagePoint D_800A53BC = { 0x2E9, 8, 2, 0x240, 240, 1, NULL };
StagePoint D_800A53CC = { 0x2ED, 8, 1, 0x350, 0x1F8, 5, &D_800A53BC };
StagePoint D_800A53DC = { 0x2ED, 8, 2, 224, 192, 5, &D_800A53CC };
StagePoints D_800A53EC = { 8, 1, &D_800A53DC };
StagePoint D_800A53F4 = { 0x2ED, 9, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A5404 = { 0x2EC, 9, 1, 240, 0x1D8, 5, &D_800A53F4 };
StagePoint D_800A5414 = { 0x2ED, 9, 1, 224, 192, 5, &D_800A5404 };
StagePoints D_800A5424 = { 9, 1, &D_800A5414 };
StagePoint D_800A542C = { 0x2E9, 9, 2, 0x240, 240, 1, NULL };
StagePoint D_800A543C = { 0x2EA, 9, 2, 224, 0x200, 5, &D_800A542C };
StagePoint D_800A544C = { 0x2ED, 9, 2, 224, 192, 5, &D_800A543C };
StagePoints D_800A545C = { 9, 2, &D_800A544C };
StagePoint D_800A5464 = { 0x2E9, 10, 1, 0x240, 240, 1, NULL };
StagePoint D_800A5474 = { 0x2EC, 10, 1, 240, 0x1D8, 5, &D_800A5464 };
StagePoint D_800A5484 = { 0x2ED, 10, 1, 224, 192, 5, &D_800A5474 };
StagePoints D_800A5494 = { 10, 1, &D_800A5484 };
StagePoint D_800A549C = { 0x2E9, 11, 1, 0x240, 240, 1, NULL };
StagePoint D_800A54AC = { 0x2EC, 11, 1, 240, 0x1D8, 5, &D_800A549C };
StagePoint D_800A54BC = { 0x2ED, 11, 1, 224, 192, 5, &D_800A54AC };
StagePoints D_800A54CC = { 11, 1, &D_800A54BC };
StagePoint D_800A54D4 = { 0x2EC, 12, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A54E4 = { 0x2ED, 12, 1, 0x350, 0x1F8, 5, &D_800A54D4 };
StagePoint D_800A54F4 = { 0x2ED, 12, 2, 224, 192, 5, &D_800A54E4 };
StagePoints D_800A5504 = { 12, 1, &D_800A54F4 };
StagePoint D_800A550C = { 0x2EC, 12, 5, 0x3B0, 120, 1, NULL };
StagePoint D_800A551C = { 0x2ED, 12, 2, 0x350, 0x1F8, 5, &D_800A550C };
StagePoint D_800A552C = { 0x2EC, 12, 2, 240, 0x1D8, 5, &D_800A551C };
StagePoints D_800A553C = { 12, 2, &D_800A552C };
StagePoint D_800A5544 = { 0x2EC, 13, 5, 0x3B0, 120, 1, NULL };
StagePoint D_800A5554 = { 0x2ED, 13, 1, 0x350, 0x1F8, 5, &D_800A5544 };
StagePoint D_800A5564 = { 0x2ED, 13, 2, 224, 192, 5, &D_800A5554 };
StagePoints D_800A5574 = { 13, 1, &D_800A5564 };
StagePoint D_800A557C = { 0x2EC, 13, 6, 0x3B0, 120, 1, NULL };
StagePoint D_800A558C = { 0x2ED, 13, 2, 0x350, 0x1F8, 5, &D_800A557C };
StagePoint D_800A559C = { 0x2EC, 13, 2, 240, 0x1D8, 5, &D_800A558C };
StagePoints D_800A55AC = { 13, 2, &D_800A559C };
StagePoint D_800A55B4 = { 0x2ED, 16, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A55C4 = { 0x2EA, 16, 1, 224, 0x200, 5, &D_800A55B4 };
StagePoint D_800A55D4 = { 0x2E8, 16, 1, 176, 0x168, 5, &D_800A55C4 };
StagePoints D_800A55E4 = { 16, 1, &D_800A55D4 };
StagePoint D_800A55EC = { 0x2EC, 19, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A55FC = { 0x2EA, 19, 2, 224, 0x200, 5, &D_800A55EC };
StagePoint D_800A560C = { 0x2EC, 19, 1, 240, 0x1D8, 5, &D_800A55FC };
StagePoints D_800A561C = { 19, 1, &D_800A560C };
StagePoint D_800A5624 = { 0x2ED, 19, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A5634 = { 0x2EC, 19, 2, 240, 0x1D8, 5, &D_800A5624 };
StagePoint D_800A5644 = { 0x2EC, 19, 3, 240, 0x1D8, 5, &D_800A5634 };
StagePoints D_800A5654 = { 19, 2, &D_800A5644 };
StagePoint D_800A565C = { 0x2EC, 20, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A566C = { 0x2EA, 20, 1, 224, 0x200, 5, &D_800A565C };
StagePoint D_800A567C = { 0x2E8, 20, 1, 176, 0x168, 5, &D_800A566C };
StagePoints D_800A568C = { 20, 1, &D_800A567C };
StagePoint D_800A5694 = { 0x2ED, 20, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A56A4 = { 0x2EC, 20, 1, 240, 0x1D8, 5, &D_800A5694 };
StagePoint D_800A56B4 = { 0x2EC, 20, 2, 240, 0x1D8, 5, &D_800A56A4 };
StagePoints D_800A56C4 = { 20, 2, &D_800A56B4 };
StagePoint D_800A56CC = { 0x2EB, 21, 1, 0x240, 160, 1, NULL };
StagePoint D_800A56DC = { 0x2EC, 21, 2, 240, 0x1D8, 5, &D_800A56CC };
StagePoint D_800A56EC = { 0x2E8, 21, 1, 176, 0x168, 5, &D_800A56DC };
StagePoints D_800A56FC = { 21, 1, &D_800A56EC };
StagePoint D_800A5704 = { 0x2EC, 22, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A5714 = { 0x2EC, 22, 1, 240, 0x1D8, 5, &D_800A5704 };
StagePoint D_800A5724 = { 0x2EC, 22, 2, 240, 0x1D8, 5, &D_800A5714 };
StagePoints D_800A5734 = { 22, 1, &D_800A5724 };
StagePoint D_800A573C = { 0x2EB, 23, 1, 0x240, 160, 1, NULL };
StagePoint D_800A574C = { 0x2EC, 23, 3, 240, 0x1D8, 5, &D_800A573C };
StagePoint D_800A575C = { 0x2E8, 23, 2, 176, 0x168, 5, &D_800A574C };
StagePoints D_800A576C = { 23, 1, &D_800A575C };
StagePoint D_800A5774 = { 0x2ED, 25, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A5784 = { 0x2E8, 25, 1, 176, 0x168, 5, &D_800A5774 };
StagePoint D_800A5794 = { 0x2EA, 25, 1, 224, 0x200, 5, &D_800A5784 };
StagePoints D_800A57A4 = { 25, 1, &D_800A5794 };
StagePoint D_800A57AC = { 0x2EC, 28, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A57BC = { 0x2ED, 28, 1, 0x350, 0x1F8, 5, &D_800A57AC };
StagePoint D_800A57CC = { 0x2ED, 28, 2, 224, 192, 5, &D_800A57BC };
StagePoints D_800A57DC = { 28, 1, &D_800A57CC };
StagePoint D_800A57E4 = { 0x2EB, 28, 3, 0x240, 160, 1, NULL };
StagePoint D_800A57F4 = { 0x2ED, 28, 2, 0x350, 0x1F8, 5, &D_800A57E4 };
StagePoint D_800A5804 = { 0x2EC, 28, 2, 240, 0x1D8, 5, &D_800A57F4 };
StagePoints D_800A5814 = { 28, 2, &D_800A5804 };
StagePoint D_800A581C = { 0x2ED, 29, 1, 0x3A0, 128, 1, NULL };
StagePoint D_800A582C = { 0x2EC, 29, 1, 240, 0x1D8, 5, &D_800A581C };
StagePoint D_800A583C = { 0x2EC, 29, 2, 240, 0x1D8, 5, &D_800A582C };
StagePoints D_800A584C = { 29, 1, &D_800A583C };
StagePoint D_800A5854 = { 0x2E9, 30, 1, 0x240, 240, 1, NULL };
StagePoint D_800A5864 = { 0x2ED, 30, 1, 0x350, 0x1F8, 5, &D_800A5854 };
StagePoint D_800A5874 = { 0x2ED, 30, 2, 224, 192, 5, &D_800A5864 };
StagePoints D_800A5884 = { 30, 1, &D_800A5874 };
StagePoint D_800A588C = { 0x2EB, 30, 2, 0x240, 160, 1, NULL };
StagePoint D_800A589C = { 0x2ED, 30, 2, 0x350, 0x1F8, 5, &D_800A588C };
StagePoint D_800A58AC = { 0x2EA, 30, 1, 224, 0x200, 5, &D_800A589C };
StagePoints D_800A58BC = { 30, 2, &D_800A58AC };
StagePoints *placePoints[] = {
    &D_800A4FC4, &D_800A4FFC, &D_800A5034, &D_800A506C,
    &D_800A50A4, &D_800A50DC, &D_800A5114, &D_800A514C,
    &D_800A5184, &D_800A51BC, &D_800A51F4, &D_800A522C,
    &D_800A5264, &D_800A529C, &D_800A52D4, &D_800A530C,
    &D_800A5344, &D_800A537C, &D_800A53B4, &D_800A53EC,
    &D_800A5424, &D_800A545C, &D_800A5494, &D_800A54CC,
    &D_800A5504, &D_800A553C, &D_800A5574, &D_800A55AC,
    &D_800A55E4, &D_800A561C, &D_800A5654, &D_800A568C,
    &D_800A56C4, &D_800A56FC, &D_800A5734, &D_800A576C,
    &D_800A57A4, &D_800A57DC, &D_800A5814, &D_800A584C,
    &D_800A5884, &D_800A58BC, NULL,
};
Battle D_800A5970 = { 174, 10, 0x60080000 };
Battle D_800A597C = { 174, 10, 0x60080000 };
Battle D_800A5988 = { 170, 10, 0x60080000 };
Battle D_800A5994 = { 170, 10, 0x60080000 };
Battle D_800A59A0 = { 170, 10, 0x60080000 };
Battle D_800A59AC = { 170, 10, 0x60080000 };
Battle D_800A59B8 = { 170, 10, 0x60080000 };
Battle D_800A59C4 = { 170, 10, 0x60080000 };
BattleList D_800A59D0 = {
    1,
    { &D_800A5970, &D_800A597C, &D_800A5988, &D_800A5994,
      &D_800A59A0, &D_800A59AC, &D_800A59B8, &D_800A59C4 },
};
Battle D_800A59F4 = { 0, 0, 0x60040000 };
Battle D_800A5A00 = { 0, 0, 0x60040000 };
Battle D_800A5A0C = { 0, 0, 0x60040000 };
Battle D_800A5A18 = { 0, 0, 0x60040000 };
Battle D_800A5A24 = { 0, 0, 0x60040000 };
Battle D_800A5A30 = { 0, 0, 0x60040000 };
Battle D_800A5A3C = { 0, 0, 0x60040000 };
Battle D_800A5A48 = { 0, 0, 0x60040000 };
BattleList D_800A5A54 = {
    0,
    { &D_800A59F4, &D_800A5A00, &D_800A5A0C, &D_800A5A18,
      &D_800A5A24, &D_800A5A30, &D_800A5A3C, &D_800A5A48 },
};
Battle D_800A5A78 = { 0, 0, 0x60040000 };
Battle D_800A5A84 = { 0, 0, 0x60040000 };
Battle D_800A5A90 = { 0, 0, 0x60040000 };
Battle D_800A5A9C = { 0, 0, 0x60040000 };
Battle D_800A5AA8 = { 0, 0, 0x60040000 };
Battle D_800A5AB4 = { 0, 0, 0x60040000 };
Battle D_800A5AC0 = { 0, 0, 0x60040000 };
Battle D_800A5ACC = { 0, 0, 0x60040000 };
BattleList D_800A5AD8 = {
    0,
    { &D_800A5A78, &D_800A5A84, &D_800A5A90, &D_800A5A9C,
      &D_800A5AA8, &D_800A5AB4, &D_800A5AC0, &D_800A5ACC },
};
Battle D_800A5AFC = { 0, 0, 0x60040000 };
Battle D_800A5B08 = { 0, 0, 0x60040000 };
Battle D_800A5B14 = { 0, 0, 0x60040000 };
Battle D_800A5B20 = { 0, 0, 0x60040000 };
Battle D_800A5B2C = { 0, 0, 0x60040000 };
Battle D_800A5B38 = { 0, 0, 0x60040000 };
Battle D_800A5B44 = { 0, 0, 0x60040000 };
Battle D_800A5B50 = { 0, 0, 0x60040000 };
BattleList D_800A5B5C = {
    0,
    { &D_800A5AFC, &D_800A5B08, &D_800A5B14, &D_800A5B20,
      &D_800A5B2C, &D_800A5B38, &D_800A5B44, &D_800A5B50 },
};
Battle D_800A5B80 = { 174, 10, 0x60080000 };
Battle D_800A5B8C = { 174, 10, 0x60080000 };
Battle D_800A5B98 = { 170, 10, 0x60080000 };
Battle D_800A5BA4 = { 170, 10, 0x60080000 };
Battle D_800A5BB0 = { 170, 10, 0x60080000 };
Battle D_800A5BBC = { 110, 10, 0x60080000 };
Battle D_800A5BC8 = { 110, 10, 0x60080000 };
Battle D_800A5BD4 = { 110, 10, 0x60080000 };
BattleList D_800A5BE0 = {
    1,
    { &D_800A5B80, &D_800A5B8C, &D_800A5B98, &D_800A5BA4,
      &D_800A5BB0, &D_800A5BBC, &D_800A5BC8, &D_800A5BD4 },
};
Battle D_800A5C04 = { 0, 0, 0x60040000 };
Battle D_800A5C10 = { 0, 0, 0x60040000 };
Battle D_800A5C1C = { 0, 0, 0x60040000 };
Battle D_800A5C28 = { 0, 0, 0x60040000 };
Battle D_800A5C34 = { 0, 0, 0x60040000 };
Battle D_800A5C40 = { 0, 0, 0x60040000 };
Battle D_800A5C4C = { 0, 0, 0x60040000 };
Battle D_800A5C58 = { 0, 0, 0x60040000 };
BattleList D_800A5C64 = {
    0,
    { &D_800A5C04, &D_800A5C10, &D_800A5C1C, &D_800A5C28,
      &D_800A5C34, &D_800A5C40, &D_800A5C4C, &D_800A5C58 },
};
Battle D_800A5C88 = { 0, 0, 0x60040000 };
Battle D_800A5C94 = { 0, 0, 0x60040000 };
Battle D_800A5CA0 = { 0, 0, 0x60040000 };
Battle D_800A5CAC = { 0, 0, 0x60040000 };
Battle D_800A5CB8 = { 0, 0, 0x60040000 };
Battle D_800A5CC4 = { 0, 0, 0x60040000 };
Battle D_800A5CD0 = { 0, 0, 0x60040000 };
Battle D_800A5CDC = { 0, 0, 0x60040000 };
BattleList D_800A5CE8 = {
    0,
    { &D_800A5C88, &D_800A5C94, &D_800A5CA0, &D_800A5CAC,
      &D_800A5CB8, &D_800A5CC4, &D_800A5CD0, &D_800A5CDC },
};
Battle D_800A5D0C = { 0, 0, 0x60040000 };
Battle D_800A5D18 = { 0, 0, 0x60040000 };
Battle D_800A5D24 = { 0, 0, 0x60040000 };
Battle D_800A5D30 = { 0, 0, 0x60040000 };
Battle D_800A5D3C = { 0, 0, 0x60040000 };
Battle D_800A5D48 = { 0, 0, 0x60040000 };
Battle D_800A5D54 = { 0, 0, 0x60040000 };
Battle D_800A5D60 = { 0, 0, 0x60040000 };
BattleList D_800A5D6C = {
    0,
    { &D_800A5D0C, &D_800A5D18, &D_800A5D24, &D_800A5D30,
      &D_800A5D3C, &D_800A5D48, &D_800A5D54, &D_800A5D60 },
};
Battle D_800A5D90 = { 174, 10, 0x60080000 };
Battle D_800A5D9C = { 174, 10, 0x60080000 };
Battle D_800A5DA8 = { 170, 10, 0x60080000 };
Battle D_800A5DB4 = { 170, 10, 0x60080000 };
Battle D_800A5DC0 = { 182, 10, 0x60080000 };
Battle D_800A5DCC = { 182, 10, 0x60080000 };
Battle D_800A5DD8 = { 71, 10, 0x60080000 };
Battle D_800A5DE4 = { 71, 10, 0x60080000 };
BattleList D_800A5DF0 = {
    1,
    { &D_800A5D90, &D_800A5D9C, &D_800A5DA8, &D_800A5DB4,
      &D_800A5DC0, &D_800A5DCC, &D_800A5DD8, &D_800A5DE4 },
};
Battle D_800A5E14 = { 0, 0, 0x60040000 };
Battle D_800A5E20 = { 0, 0, 0x60040000 };
Battle D_800A5E2C = { 0, 0, 0x60040000 };
Battle D_800A5E38 = { 0, 0, 0x60040000 };
Battle D_800A5E44 = { 0, 0, 0x60040000 };
Battle D_800A5E50 = { 0, 0, 0x60040000 };
Battle D_800A5E5C = { 0, 0, 0x60040000 };
Battle D_800A5E68 = { 0, 0, 0x60040000 };
BattleList D_800A5E74 = {
    0,
    { &D_800A5E14, &D_800A5E20, &D_800A5E2C, &D_800A5E38,
      &D_800A5E44, &D_800A5E50, &D_800A5E5C, &D_800A5E68 },
};
Battle D_800A5E98 = { 0, 0, 0x60040000 };
Battle D_800A5EA4 = { 0, 0, 0x60040000 };
Battle D_800A5EB0 = { 0, 0, 0x60040000 };
Battle D_800A5EBC = { 0, 0, 0x60040000 };
Battle D_800A5EC8 = { 0, 0, 0x60040000 };
Battle D_800A5ED4 = { 0, 0, 0x60040000 };
Battle D_800A5EE0 = { 0, 0, 0x60040000 };
Battle D_800A5EEC = { 0, 0, 0x60040000 };
BattleList D_800A5EF8 = {
    0,
    { &D_800A5E98, &D_800A5EA4, &D_800A5EB0, &D_800A5EBC,
      &D_800A5EC8, &D_800A5ED4, &D_800A5EE0, &D_800A5EEC },
};
Battle D_800A5F1C = { 0, 0, 0x60040000 };
Battle D_800A5F28 = { 0, 0, 0x60040000 };
Battle D_800A5F34 = { 0, 0, 0x60040000 };
Battle D_800A5F40 = { 0, 0, 0x60040000 };
Battle D_800A5F4C = { 0, 0, 0x60040000 };
Battle D_800A5F58 = { 0, 0, 0x60040000 };
Battle D_800A5F64 = { 0, 0, 0x60040000 };
Battle D_800A5F70 = { 0, 0, 0x60040000 };
BattleList D_800A5F7C = {
    0,
    { &D_800A5F1C, &D_800A5F28, &D_800A5F34, &D_800A5F40,
      &D_800A5F4C, &D_800A5F58, &D_800A5F64, &D_800A5F70 },
};
Battle D_800A5FA0 = { 174, 10, 0x60080000 };
Battle D_800A5FAC = { 174, 10, 0x60080000 };
Battle D_800A5FB8 = { 170, 10, 0x60080000 };
Battle D_800A5FC4 = { 170, 10, 0x60080000 };
Battle D_800A5FD0 = { 182, 10, 0x60080000 };
Battle D_800A5FDC = { 182, 10, 0x60080000 };
Battle D_800A5FE8 = { 71, 10, 0x60080000 };
Battle D_800A5FF4 = { 71, 10, 0x60080000 };
BattleList D_800A6000 = {
    1,
    { &D_800A5FA0, &D_800A5FAC, &D_800A5FB8, &D_800A5FC4,
      &D_800A5FD0, &D_800A5FDC, &D_800A5FE8, &D_800A5FF4 },
};
Battle D_800A6024 = { 0, 0, 0x60040000 };
Battle D_800A6030 = { 0, 0, 0x60040000 };
Battle D_800A603C = { 0, 0, 0x60040000 };
Battle D_800A6048 = { 0, 0, 0x60040000 };
Battle D_800A6054 = { 0, 0, 0x60040000 };
Battle D_800A6060 = { 0, 0, 0x60040000 };
Battle D_800A606C = { 0, 0, 0x60040000 };
Battle D_800A6078 = { 0, 0, 0x60040000 };
BattleList D_800A6084 = {
    0,
    { &D_800A6024, &D_800A6030, &D_800A603C, &D_800A6048,
      &D_800A6054, &D_800A6060, &D_800A606C, &D_800A6078 },
};
Battle D_800A60A8 = { 0, 0, 0x60040000 };
Battle D_800A60B4 = { 0, 0, 0x60040000 };
Battle D_800A60C0 = { 0, 0, 0x60040000 };
Battle D_800A60CC = { 0, 0, 0x60040000 };
Battle D_800A60D8 = { 0, 0, 0x60040000 };
Battle D_800A60E4 = { 0, 0, 0x60040000 };
Battle D_800A60F0 = { 0, 0, 0x60040000 };
Battle D_800A60FC = { 0, 0, 0x60040000 };
BattleList D_800A6108 = {
    0,
    { &D_800A60A8, &D_800A60B4, &D_800A60C0, &D_800A60CC,
      &D_800A60D8, &D_800A60E4, &D_800A60F0, &D_800A60FC },
};
Battle D_800A612C = { 0, 0, 0x60040000 };
Battle D_800A6138 = { 0, 0, 0x60040000 };
Battle D_800A6144 = { 0, 0, 0x60040000 };
Battle D_800A6150 = { 0, 0, 0x60040000 };
Battle D_800A615C = { 0, 0, 0x60040000 };
Battle D_800A6168 = { 0, 0, 0x60040000 };
Battle D_800A6174 = { 0, 0, 0x60040000 };
Battle D_800A6180 = { 0, 0, 0x60040000 };
BattleList D_800A618C = {
    0,
    { &D_800A612C, &D_800A6138, &D_800A6144, &D_800A6150,
      &D_800A615C, &D_800A6168, &D_800A6174, &D_800A6180 },
};
Battle D_800A61B0 = { 174, 10, 0x60080000 };
Battle D_800A61BC = { 170, 10, 0x60080000 };
Battle D_800A61C8 = { 110, 10, 0x60080000 };
Battle D_800A61D4 = { 110, 10, 0x60080000 };
Battle D_800A61E0 = { 182, 10, 0x60080000 };
Battle D_800A61EC = { 182, 10, 0x60080000 };
Battle D_800A61F8 = { 71, 10, 0x60080000 };
Battle D_800A6204 = { 71, 10, 0x60080000 };
BattleList D_800A6210 = {
    1,
    { &D_800A61B0, &D_800A61BC, &D_800A61C8, &D_800A61D4,
      &D_800A61E0, &D_800A61EC, &D_800A61F8, &D_800A6204 },
};
Battle D_800A6234 = { 0, 0, 0x60040000 };
Battle D_800A6240 = { 0, 0, 0x60040000 };
Battle D_800A624C = { 0, 0, 0x60040000 };
Battle D_800A6258 = { 0, 0, 0x60040000 };
Battle D_800A6264 = { 0, 0, 0x60040000 };
Battle D_800A6270 = { 0, 0, 0x60040000 };
Battle D_800A627C = { 0, 0, 0x60040000 };
Battle D_800A6288 = { 0, 0, 0x60040000 };
BattleList D_800A6294 = {
    0,
    { &D_800A6234, &D_800A6240, &D_800A624C, &D_800A6258,
      &D_800A6264, &D_800A6270, &D_800A627C, &D_800A6288 },
};
Battle D_800A62B8 = { 0, 0, 0x60040000 };
Battle D_800A62C4 = { 0, 0, 0x60040000 };
Battle D_800A62D0 = { 0, 0, 0x60040000 };
Battle D_800A62DC = { 0, 0, 0x60040000 };
Battle D_800A62E8 = { 0, 0, 0x60040000 };
Battle D_800A62F4 = { 0, 0, 0x60040000 };
Battle D_800A6300 = { 0, 0, 0x60040000 };
Battle D_800A630C = { 0, 0, 0x60040000 };
BattleList D_800A6318 = {
    0,
    { &D_800A62B8, &D_800A62C4, &D_800A62D0, &D_800A62DC,
      &D_800A62E8, &D_800A62F4, &D_800A6300, &D_800A630C },
};
Battle D_800A633C = { 0, 0, 0x60040000 };
Battle D_800A6348 = { 0, 0, 0x60040000 };
Battle D_800A6354 = { 0, 0, 0x60040000 };
Battle D_800A6360 = { 0, 0, 0x60040000 };
Battle D_800A636C = { 0, 0, 0x60040000 };
Battle D_800A6378 = { 0, 0, 0x60040000 };
Battle D_800A6384 = { 0, 0, 0x60040000 };
Battle D_800A6390 = { 0, 0, 0x60040000 };
BattleList D_800A639C = {
    0,
    { &D_800A633C, &D_800A6348, &D_800A6354, &D_800A6360,
      &D_800A636C, &D_800A6378, &D_800A6384, &D_800A6390 },
};
Battle D_800A63C0 = { 174, 10, 0x60080000 };
Battle D_800A63CC = { 170, 10, 0x60080000 };
Battle D_800A63D8 = { 110, 10, 0x60080000 };
Battle D_800A63E4 = { 110, 10, 0x60080000 };
Battle D_800A63F0 = { 182, 10, 0x60080000 };
Battle D_800A63FC = { 182, 10, 0x60080000 };
Battle D_800A6408 = { 71, 10, 0x60080000 };
Battle D_800A6414 = { 71, 10, 0x60080000 };
BattleList D_800A6420 = {
    1,
    { &D_800A63C0, &D_800A63CC, &D_800A63D8, &D_800A63E4,
      &D_800A63F0, &D_800A63FC, &D_800A6408, &D_800A6414 },
};
Battle D_800A6444 = { 0, 0, 0x60040000 };
Battle D_800A6450 = { 0, 0, 0x60040000 };
Battle D_800A645C = { 0, 0, 0x60040000 };
Battle D_800A6468 = { 0, 0, 0x60040000 };
Battle D_800A6474 = { 0, 0, 0x60040000 };
Battle D_800A6480 = { 0, 0, 0x60040000 };
Battle D_800A648C = { 0, 0, 0x60040000 };
Battle D_800A6498 = { 0, 0, 0x60040000 };
BattleList D_800A64A4 = {
    0,
    { &D_800A6444, &D_800A6450, &D_800A645C, &D_800A6468,
      &D_800A6474, &D_800A6480, &D_800A648C, &D_800A6498 },
};
Battle D_800A64C8 = { 0, 0, 0x60040000 };
Battle D_800A64D4 = { 0, 0, 0x60040000 };
Battle D_800A64E0 = { 0, 0, 0x60040000 };
Battle D_800A64EC = { 0, 0, 0x60040000 };
Battle D_800A64F8 = { 0, 0, 0x60040000 };
Battle D_800A6504 = { 0, 0, 0x60040000 };
Battle D_800A6510 = { 0, 0, 0x60040000 };
Battle D_800A651C = { 0, 0, 0x60040000 };
BattleList D_800A6528 = {
    0,
    { &D_800A64C8, &D_800A64D4, &D_800A64E0, &D_800A64EC,
      &D_800A64F8, &D_800A6504, &D_800A6510, &D_800A651C },
};
Battle D_800A654C = { 0, 0, 0x60040000 };
Battle D_800A6558 = { 0, 0, 0x60040000 };
Battle D_800A6564 = { 0, 0, 0x60040000 };
Battle D_800A6570 = { 0, 0, 0x60040000 };
Battle D_800A657C = { 0, 0, 0x60040000 };
Battle D_800A6588 = { 0, 0, 0x60040000 };
Battle D_800A6594 = { 0, 0, 0x60040000 };
Battle D_800A65A0 = { 0, 0, 0x60040000 };
BattleList D_800A65AC = {
    0,
    { &D_800A654C, &D_800A6558, &D_800A6564, &D_800A6570,
      &D_800A657C, &D_800A6588, &D_800A6594, &D_800A65A0 },
};
Battle D_800A65D0 = { 110, 10, 0x60080000 };
Battle D_800A65DC = { 110, 10, 0x60080000 };
Battle D_800A65E8 = { 110, 10, 0x60080000 };
Battle D_800A65F4 = { 110, 10, 0x60080000 };
Battle D_800A6600 = { 182, 10, 0x60080000 };
Battle D_800A660C = { 182, 10, 0x60080000 };
Battle D_800A6618 = { 182, 10, 0x60080000 };
Battle D_800A6624 = { 182, 10, 0x60080000 };
BattleList D_800A6630 = {
    1,
    { &D_800A65D0, &D_800A65DC, &D_800A65E8, &D_800A65F4,
      &D_800A6600, &D_800A660C, &D_800A6618, &D_800A6624 },
};
Battle D_800A6654 = { 0, 0, 0x60040000 };
Battle D_800A6660 = { 0, 0, 0x60040000 };
Battle D_800A666C = { 0, 0, 0x60040000 };
Battle D_800A6678 = { 0, 0, 0x60040000 };
Battle D_800A6684 = { 0, 0, 0x60040000 };
Battle D_800A6690 = { 0, 0, 0x60040000 };
Battle D_800A669C = { 0, 0, 0x60040000 };
Battle D_800A66A8 = { 0, 0, 0x60040000 };
BattleList D_800A66B4 = {
    0,
    { &D_800A6654, &D_800A6660, &D_800A666C, &D_800A6678,
      &D_800A6684, &D_800A6690, &D_800A669C, &D_800A66A8 },
};
Battle D_800A66D8 = { 0, 0, 0x60040000 };
Battle D_800A66E4 = { 0, 0, 0x60040000 };
Battle D_800A66F0 = { 0, 0, 0x60040000 };
Battle D_800A66FC = { 0, 0, 0x60040000 };
Battle D_800A6708 = { 0, 0, 0x60040000 };
Battle D_800A6714 = { 0, 0, 0x60040000 };
Battle D_800A6720 = { 0, 0, 0x60040000 };
Battle D_800A672C = { 0, 0, 0x60040000 };
BattleList D_800A6738 = {
    0,
    { &D_800A66D8, &D_800A66E4, &D_800A66F0, &D_800A66FC,
      &D_800A6708, &D_800A6714, &D_800A6720, &D_800A672C },
};
Battle D_800A675C = { 0, 0, 0x60040000 };
Battle D_800A6768 = { 0, 0, 0x60040000 };
Battle D_800A6774 = { 0, 0, 0x60040000 };
Battle D_800A6780 = { 0, 0, 0x60040000 };
Battle D_800A678C = { 0, 0, 0x60040000 };
Battle D_800A6798 = { 0, 0, 0x60040000 };
Battle D_800A67A4 = { 0, 0, 0x60040000 };
Battle D_800A67B0 = { 0, 0, 0x60040000 };
BattleList D_800A67BC = {
    0,
    { &D_800A675C, &D_800A6768, &D_800A6774, &D_800A6780,
      &D_800A678C, &D_800A6798, &D_800A67A4, &D_800A67B0 },
};
Battle D_800A67E0 = { 182, 10, 0x60080000 };
Battle D_800A67EC = { 182, 10, 0x60080000 };
Battle D_800A67F8 = { 182, 10, 0x60080000 };
Battle D_800A6804 = { 182, 10, 0x60080000 };
Battle D_800A6810 = { 71, 10, 0x60080000 };
Battle D_800A681C = { 71, 10, 0x60080000 };
Battle D_800A6828 = { 71, 10, 0x60080000 };
Battle D_800A6834 = { 71, 10, 0x60080000 };
BattleList D_800A6840 = {
    1,
    { &D_800A67E0, &D_800A67EC, &D_800A67F8, &D_800A6804,
      &D_800A6810, &D_800A681C, &D_800A6828, &D_800A6834 },
};
Battle D_800A6864 = { 0, 0, 0x60040000 };
Battle D_800A6870 = { 0, 0, 0x60040000 };
Battle D_800A687C = { 0, 0, 0x60040000 };
Battle D_800A6888 = { 0, 0, 0x60040000 };
Battle D_800A6894 = { 0, 0, 0x60040000 };
Battle D_800A68A0 = { 0, 0, 0x60040000 };
Battle D_800A68AC = { 0, 0, 0x60040000 };
Battle D_800A68B8 = { 0, 0, 0x60040000 };
BattleList D_800A68C4 = {
    0,
    { &D_800A6864, &D_800A6870, &D_800A687C, &D_800A6888,
      &D_800A6894, &D_800A68A0, &D_800A68AC, &D_800A68B8 },
};
Battle D_800A68E8 = { 0, 0, 0x60040000 };
Battle D_800A68F4 = { 0, 0, 0x60040000 };
Battle D_800A6900 = { 0, 0, 0x60040000 };
Battle D_800A690C = { 0, 0, 0x60040000 };
Battle D_800A6918 = { 0, 0, 0x60040000 };
Battle D_800A6924 = { 0, 0, 0x60040000 };
Battle D_800A6930 = { 0, 0, 0x60040000 };
Battle D_800A693C = { 0, 0, 0x60040000 };
BattleList D_800A6948 = {
    0,
    { &D_800A68E8, &D_800A68F4, &D_800A6900, &D_800A690C,
      &D_800A6918, &D_800A6924, &D_800A6930, &D_800A693C },
};
Battle D_800A696C = { 0, 0, 0x60040000 };
Battle D_800A6978 = { 0, 0, 0x60040000 };
Battle D_800A6984 = { 0, 0, 0x60040000 };
Battle D_800A6990 = { 0, 0, 0x60040000 };
Battle D_800A699C = { 0, 0, 0x60040000 };
Battle D_800A69A8 = { 0, 0, 0x60040000 };
Battle D_800A69B4 = { 0, 0, 0x60040000 };
Battle D_800A69C0 = { 0, 0, 0x60040000 };
BattleList D_800A69CC = {
    0,
    { &D_800A696C, &D_800A6978, &D_800A6984, &D_800A6990,
      &D_800A699C, &D_800A69A8, &D_800A69B4, &D_800A69C0 },
};
Battle D_800A69F0 = { 182, 10, 0x60080000 };
Battle D_800A69FC = { 182, 10, 0x60080000 };
Battle D_800A6A08 = { 182, 10, 0x60080000 };
Battle D_800A6A14 = { 182, 10, 0x60080000 };
Battle D_800A6A20 = { 71, 10, 0x60080000 };
Battle D_800A6A2C = { 71, 10, 0x60080000 };
Battle D_800A6A38 = { 71, 10, 0x60080000 };
Battle D_800A6A44 = { 71, 10, 0x60080000 };
BattleList D_800A6A50 = {
    1,
    { &D_800A69F0, &D_800A69FC, &D_800A6A08, &D_800A6A14,
      &D_800A6A20, &D_800A6A2C, &D_800A6A38, &D_800A6A44 },
};
Battle D_800A6A74 = { 0, 0, 0x60040000 };
Battle D_800A6A80 = { 0, 0, 0x60040000 };
Battle D_800A6A8C = { 0, 0, 0x60040000 };
Battle D_800A6A98 = { 0, 0, 0x60040000 };
Battle D_800A6AA4 = { 0, 0, 0x60040000 };
Battle D_800A6AB0 = { 0, 0, 0x60040000 };
Battle D_800A6ABC = { 0, 0, 0x60040000 };
Battle D_800A6AC8 = { 0, 0, 0x60040000 };
BattleList D_800A6AD4 = {
    0,
    { &D_800A6A74, &D_800A6A80, &D_800A6A8C, &D_800A6A98,
      &D_800A6AA4, &D_800A6AB0, &D_800A6ABC, &D_800A6AC8 },
};
Battle D_800A6AF8 = { 0, 0, 0x60040000 };
Battle D_800A6B04 = { 0, 0, 0x60040000 };
Battle D_800A6B10 = { 0, 0, 0x60040000 };
Battle D_800A6B1C = { 0, 0, 0x60040000 };
Battle D_800A6B28 = { 0, 0, 0x60040000 };
Battle D_800A6B34 = { 0, 0, 0x60040000 };
Battle D_800A6B40 = { 0, 0, 0x60040000 };
Battle D_800A6B4C = { 0, 0, 0x60040000 };
BattleList D_800A6B58 = {
    0,
    { &D_800A6AF8, &D_800A6B04, &D_800A6B10, &D_800A6B1C,
      &D_800A6B28, &D_800A6B34, &D_800A6B40, &D_800A6B4C },
};
Battle D_800A6B7C = { 0, 0, 0x60040000 };
Battle D_800A6B88 = { 0, 0, 0x60040000 };
Battle D_800A6B94 = { 0, 0, 0x60040000 };
Battle D_800A6BA0 = { 0, 0, 0x60040000 };
Battle D_800A6BAC = { 0, 0, 0x60040000 };
Battle D_800A6BB8 = { 0, 0, 0x60040000 };
Battle D_800A6BC4 = { 0, 0, 0x60040000 };
Battle D_800A6BD0 = { 0, 0, 0x60040000 };
BattleList D_800A6BDC = {
    0,
    { &D_800A6B7C, &D_800A6B88, &D_800A6B94, &D_800A6BA0,
      &D_800A6BAC, &D_800A6BB8, &D_800A6BC4, &D_800A6BD0 },
};
Battle D_800A6C00 = { 174, 10, 0x60080000 };
Battle D_800A6C0C = { 174, 10, 0x60080000 };
Battle D_800A6C18 = { 170, 10, 0x60080000 };
Battle D_800A6C24 = { 170, 10, 0x60080000 };
Battle D_800A6C30 = { 170, 10, 0x60080000 };
Battle D_800A6C3C = { 110, 10, 0x60080000 };
Battle D_800A6C48 = { 110, 10, 0x60080000 };
Battle D_800A6C54 = { 110, 10, 0x60080000 };
BattleList D_800A6C60 = {
    2,
    { &D_800A6C00, &D_800A6C0C, &D_800A6C18, &D_800A6C24,
      &D_800A6C30, &D_800A6C3C, &D_800A6C48, &D_800A6C54 },
};
Battle D_800A6C84 = { 0, 0, 0x60040000 };
Battle D_800A6C90 = { 0, 0, 0x60040000 };
Battle D_800A6C9C = { 0, 0, 0x60040000 };
Battle D_800A6CA8 = { 0, 0, 0x60040000 };
Battle D_800A6CB4 = { 0, 0, 0x60040000 };
Battle D_800A6CC0 = { 0, 0, 0x60040000 };
Battle D_800A6CCC = { 0, 0, 0x60040000 };
Battle D_800A6CD8 = { 0, 0, 0x60040000 };
BattleList D_800A6CE4 = {
    0,
    { &D_800A6C84, &D_800A6C90, &D_800A6C9C, &D_800A6CA8,
      &D_800A6CB4, &D_800A6CC0, &D_800A6CCC, &D_800A6CD8 },
};
Battle D_800A6D08 = { 0, 0, 0x60040000 };
Battle D_800A6D14 = { 0, 0, 0x60040000 };
Battle D_800A6D20 = { 0, 0, 0x60040000 };
Battle D_800A6D2C = { 0, 0, 0x60040000 };
Battle D_800A6D38 = { 0, 0, 0x60040000 };
Battle D_800A6D44 = { 0, 0, 0x60040000 };
Battle D_800A6D50 = { 0, 0, 0x60040000 };
Battle D_800A6D5C = { 0, 0, 0x60040000 };
BattleList D_800A6D68 = {
    0,
    { &D_800A6D08, &D_800A6D14, &D_800A6D20, &D_800A6D2C,
      &D_800A6D38, &D_800A6D44, &D_800A6D50, &D_800A6D5C },
};
Battle D_800A6D8C = { 0, 0, 0x60040000 };
Battle D_800A6D98 = { 0, 0, 0x60040000 };
Battle D_800A6DA4 = { 0, 0, 0x60040000 };
Battle D_800A6DB0 = { 0, 0, 0x60040000 };
Battle D_800A6DBC = { 0, 0, 0x60040000 };
Battle D_800A6DC8 = { 0, 0, 0x60040000 };
Battle D_800A6DD4 = { 0, 0, 0x60040000 };
Battle D_800A6DE0 = { 0, 0, 0x60040000 };
BattleList D_800A6DEC = {
    0,
    { &D_800A6D8C, &D_800A6D98, &D_800A6DA4, &D_800A6DB0,
      &D_800A6DBC, &D_800A6DC8, &D_800A6DD4, &D_800A6DE0 },
};
Battle D_800A6E10 = { 182, 10, 0x60080000 };
Battle D_800A6E1C = { 182, 10, 0x60080000 };
Battle D_800A6E28 = { 182, 10, 0x60080000 };
Battle D_800A6E34 = { 182, 10, 0x60080000 };
Battle D_800A6E40 = { 71, 10, 0x60080000 };
Battle D_800A6E4C = { 71, 10, 0x60080000 };
Battle D_800A6E58 = { 71, 10, 0x60080000 };
Battle D_800A6E64 = { 71, 10, 0x60080000 };
BattleList D_800A6E70 = {
    2,
    { &D_800A6E10, &D_800A6E1C, &D_800A6E28, &D_800A6E34,
      &D_800A6E40, &D_800A6E4C, &D_800A6E58, &D_800A6E64 },
};
Battle D_800A6E94 = { 0, 0, 0x60040000 };
Battle D_800A6EA0 = { 0, 0, 0x60040000 };
Battle D_800A6EAC = { 0, 0, 0x60040000 };
Battle D_800A6EB8 = { 0, 0, 0x60040000 };
Battle D_800A6EC4 = { 0, 0, 0x60040000 };
Battle D_800A6ED0 = { 0, 0, 0x60040000 };
Battle D_800A6EDC = { 0, 0, 0x60040000 };
Battle D_800A6EE8 = { 0, 0, 0x60040000 };
BattleList D_800A6EF4 = {
    0,
    { &D_800A6E94, &D_800A6EA0, &D_800A6EAC, &D_800A6EB8,
      &D_800A6EC4, &D_800A6ED0, &D_800A6EDC, &D_800A6EE8 },
};
Battle D_800A6F18 = { 0, 0, 0x60040000 };
Battle D_800A6F24 = { 0, 0, 0x60040000 };
Battle D_800A6F30 = { 0, 0, 0x60040000 };
Battle D_800A6F3C = { 0, 0, 0x60040000 };
Battle D_800A6F48 = { 0, 0, 0x60040000 };
Battle D_800A6F54 = { 0, 0, 0x60040000 };
Battle D_800A6F60 = { 0, 0, 0x60040000 };
Battle D_800A6F6C = { 0, 0, 0x60040000 };
BattleList D_800A6F78 = {
    0,
    { &D_800A6F18, &D_800A6F24, &D_800A6F30, &D_800A6F3C,
      &D_800A6F48, &D_800A6F54, &D_800A6F60, &D_800A6F6C },
};
Battle D_800A6F9C = { 0, 0, 0x60040000 };
Battle D_800A6FA8 = { 0, 0, 0x60040000 };
Battle D_800A6FB4 = { 0, 0, 0x60040000 };
Battle D_800A6FC0 = { 0, 0, 0x60040000 };
Battle D_800A6FCC = { 0, 0, 0x60040000 };
Battle D_800A6FD8 = { 0, 0, 0x60040000 };
Battle D_800A6FE4 = { 0, 0, 0x60040000 };
Battle D_800A6FF0 = { 0, 0, 0x60040000 };
BattleList D_800A6FFC = {
    0,
    { &D_800A6F9C, &D_800A6FA8, &D_800A6FB4, &D_800A6FC0,
      &D_800A6FCC, &D_800A6FD8, &D_800A6FE4, &D_800A6FF0 },
};
Battle D_800A7020 = { 110, 10, 0x60080000 };
Battle D_800A702C = { 110, 10, 0x60080000 };
Battle D_800A7038 = { 110, 10, 0x60080000 };
Battle D_800A7044 = { 110, 10, 0x60080000 };
Battle D_800A7050 = { 110, 10, 0x60080000 };
Battle D_800A705C = { 110, 10, 0x60080000 };
Battle D_800A7068 = { 110, 10, 0x60080000 };
Battle D_800A7074 = { 110, 10, 0x60080000 };
BattleList D_800A7080 = {
    1,
    { &D_800A7020, &D_800A702C, &D_800A7038, &D_800A7044,
      &D_800A7050, &D_800A705C, &D_800A7068, &D_800A7074 },
};
Battle D_800A70A4 = { 0, 0, 0x60040000 };
Battle D_800A70B0 = { 0, 0, 0x60040000 };
Battle D_800A70BC = { 0, 0, 0x60040000 };
Battle D_800A70C8 = { 0, 0, 0x60040000 };
Battle D_800A70D4 = { 0, 0, 0x60040000 };
Battle D_800A70E0 = { 0, 0, 0x60040000 };
Battle D_800A70EC = { 0, 0, 0x60040000 };
Battle D_800A70F8 = { 0, 0, 0x60040000 };
BattleList D_800A7104 = {
    0,
    { &D_800A70A4, &D_800A70B0, &D_800A70BC, &D_800A70C8,
      &D_800A70D4, &D_800A70E0, &D_800A70EC, &D_800A70F8 },
};
Battle D_800A7128 = { 0, 0, 0x60040000 };
Battle D_800A7134 = { 0, 0, 0x60040000 };
Battle D_800A7140 = { 0, 0, 0x60040000 };
Battle D_800A714C = { 0, 0, 0x60040000 };
Battle D_800A7158 = { 0, 0, 0x60040000 };
Battle D_800A7164 = { 0, 0, 0x60040000 };
Battle D_800A7170 = { 0, 0, 0x60040000 };
Battle D_800A717C = { 0, 0, 0x60040000 };
BattleList D_800A7188 = {
    0,
    { &D_800A7128, &D_800A7134, &D_800A7140, &D_800A714C,
      &D_800A7158, &D_800A7164, &D_800A7170, &D_800A717C },
};
Battle D_800A71AC = { 0, 0, 0x60040000 };
Battle D_800A71B8 = { 0, 0, 0x60040000 };
Battle D_800A71C4 = { 0, 0, 0x60040000 };
Battle D_800A71D0 = { 0, 0, 0x60040000 };
Battle D_800A71DC = { 0, 0, 0x60040000 };
Battle D_800A71E8 = { 0, 0, 0x60040000 };
Battle D_800A71F4 = { 0, 0, 0x60040000 };
Battle D_800A7200 = { 0, 0, 0x60040000 };
BattleList D_800A720C = {
    0,
    { &D_800A71AC, &D_800A71B8, &D_800A71C4, &D_800A71D0,
      &D_800A71DC, &D_800A71E8, &D_800A71F4, &D_800A7200 },
};
Battle D_800A7230 = { 182, 10, 0x60080000 };
Battle D_800A723C = { 182, 10, 0x60080000 };
Battle D_800A7248 = { 182, 10, 0x60080000 };
Battle D_800A7254 = { 182, 10, 0x60080000 };
Battle D_800A7260 = { 71, 10, 0x60080000 };
Battle D_800A726C = { 71, 10, 0x60080000 };
Battle D_800A7278 = { 71, 10, 0x60080000 };
Battle D_800A7284 = { 71, 10, 0x60080000 };
BattleList D_800A7290 = {
    1,
    { &D_800A7230, &D_800A723C, &D_800A7248, &D_800A7254,
      &D_800A7260, &D_800A726C, &D_800A7278, &D_800A7284 },
};
Battle D_800A72B4 = { 0, 0, 0x60040000 };
Battle D_800A72C0 = { 0, 0, 0x60040000 };
Battle D_800A72CC = { 0, 0, 0x60040000 };
Battle D_800A72D8 = { 0, 0, 0x60040000 };
Battle D_800A72E4 = { 0, 0, 0x60040000 };
Battle D_800A72F0 = { 0, 0, 0x60040000 };
Battle D_800A72FC = { 0, 0, 0x60040000 };
Battle D_800A7308 = { 0, 0, 0x60040000 };
BattleList D_800A7314 = {
    0,
    { &D_800A72B4, &D_800A72C0, &D_800A72CC, &D_800A72D8,
      &D_800A72E4, &D_800A72F0, &D_800A72FC, &D_800A7308 },
};
Battle D_800A7338 = { 0, 0, 0x60040000 };
Battle D_800A7344 = { 0, 0, 0x60040000 };
Battle D_800A7350 = { 0, 0, 0x60040000 };
Battle D_800A735C = { 0, 0, 0x60040000 };
Battle D_800A7368 = { 0, 0, 0x60040000 };
Battle D_800A7374 = { 0, 0, 0x60040000 };
Battle D_800A7380 = { 0, 0, 0x60040000 };
Battle D_800A738C = { 0, 0, 0x60040000 };
BattleList D_800A7398 = {
    0,
    { &D_800A7338, &D_800A7344, &D_800A7350, &D_800A735C,
      &D_800A7368, &D_800A7374, &D_800A7380, &D_800A738C },
};
Battle D_800A73BC = { 0, 0, 0x60040000 };
Battle D_800A73C8 = { 0, 0, 0x60040000 };
Battle D_800A73D4 = { 0, 0, 0x60040000 };
Battle D_800A73E0 = { 0, 0, 0x60040000 };
Battle D_800A73EC = { 0, 0, 0x60040000 };
Battle D_800A73F8 = { 0, 0, 0x60040000 };
Battle D_800A7404 = { 0, 0, 0x60040000 };
Battle D_800A7410 = { 0, 0, 0x60040000 };
BattleList D_800A741C = {
    0,
    { &D_800A73BC, &D_800A73C8, &D_800A73D4, &D_800A73E0,
      &D_800A73EC, &D_800A73F8, &D_800A7404, &D_800A7410 },
};
Battle D_800A7440 = { 174, 10, 0x60080000 };
Battle D_800A744C = { 174, 10, 0x60080000 };
Battle D_800A7458 = { 170, 10, 0x60080000 };
Battle D_800A7464 = { 170, 10, 0x60080000 };
Battle D_800A7470 = { 170, 10, 0x60080000 };
Battle D_800A747C = { 170, 10, 0x60080000 };
Battle D_800A7488 = { 170, 10, 0x60080000 };
Battle D_800A7494 = { 170, 10, 0x60080000 };
BattleList D_800A74A0 = {
    4,
    { &D_800A7440, &D_800A744C, &D_800A7458, &D_800A7464,
      &D_800A7470, &D_800A747C, &D_800A7488, &D_800A7494 },
};
Battle D_800A74C4 = { 0, 0, 0x60040000 };
Battle D_800A74D0 = { 0, 0, 0x60040000 };
Battle D_800A74DC = { 0, 0, 0x60040000 };
Battle D_800A74E8 = { 0, 0, 0x60040000 };
Battle D_800A74F4 = { 0, 0, 0x60040000 };
Battle D_800A7500 = { 0, 0, 0x60040000 };
Battle D_800A750C = { 0, 0, 0x60040000 };
Battle D_800A7518 = { 0, 0, 0x60040000 };
BattleList D_800A7524 = {
    0,
    { &D_800A74C4, &D_800A74D0, &D_800A74DC, &D_800A74E8,
      &D_800A74F4, &D_800A7500, &D_800A750C, &D_800A7518 },
};
Battle D_800A7548 = { 0, 0, 0x60040000 };
Battle D_800A7554 = { 0, 0, 0x60040000 };
Battle D_800A7560 = { 0, 0, 0x60040000 };
Battle D_800A756C = { 0, 0, 0x60040000 };
Battle D_800A7578 = { 0, 0, 0x60040000 };
Battle D_800A7584 = { 0, 0, 0x60040000 };
Battle D_800A7590 = { 0, 0, 0x60040000 };
Battle D_800A759C = { 0, 0, 0x60040000 };
BattleList D_800A75A8 = {
    0,
    { &D_800A7548, &D_800A7554, &D_800A7560, &D_800A756C,
      &D_800A7578, &D_800A7584, &D_800A7590, &D_800A759C },
};
Battle D_800A75CC = { 0, 0, 0x60040000 };
Battle D_800A75D8 = { 0, 0, 0x60040000 };
Battle D_800A75E4 = { 0, 0, 0x60040000 };
Battle D_800A75F0 = { 0, 0, 0x60040000 };
Battle D_800A75FC = { 0, 0, 0x60040000 };
Battle D_800A7608 = { 0, 0, 0x60040000 };
Battle D_800A7614 = { 0, 0, 0x60040000 };
Battle D_800A7620 = { 0, 0, 0x60040000 };
BattleList D_800A762C = {
    0,
    { &D_800A75CC, &D_800A75D8, &D_800A75E4, &D_800A75F0,
      &D_800A75FC, &D_800A7608, &D_800A7614, &D_800A7620 },
};
Battle D_800A7650 = { 110, 10, 0x60080000 };
Battle D_800A765C = { 110, 10, 0x60080000 };
Battle D_800A7668 = { 110, 10, 0x60080000 };
Battle D_800A7674 = { 110, 10, 0x60080000 };
Battle D_800A7680 = { 110, 10, 0x60080000 };
Battle D_800A768C = { 110, 10, 0x60080000 };
Battle D_800A7698 = { 110, 10, 0x60080000 };
Battle D_800A76A4 = { 110, 10, 0x60080000 };
BattleList D_800A76B0 = {
    1,
    { &D_800A7650, &D_800A765C, &D_800A7668, &D_800A7674,
      &D_800A7680, &D_800A768C, &D_800A7698, &D_800A76A4 },
};
Battle D_800A76D4 = { 0, 0, 0x60040000 };
Battle D_800A76E0 = { 0, 0, 0x60040000 };
Battle D_800A76EC = { 0, 0, 0x60040000 };
Battle D_800A76F8 = { 0, 0, 0x60040000 };
Battle D_800A7704 = { 0, 0, 0x60040000 };
Battle D_800A7710 = { 0, 0, 0x60040000 };
Battle D_800A771C = { 0, 0, 0x60040000 };
Battle D_800A7728 = { 0, 0, 0x60040000 };
BattleList D_800A7734 = {
    0,
    { &D_800A76D4, &D_800A76E0, &D_800A76EC, &D_800A76F8,
      &D_800A7704, &D_800A7710, &D_800A771C, &D_800A7728 },
};
Battle D_800A7758 = { 0, 0, 0x60040000 };
Battle D_800A7764 = { 0, 0, 0x60040000 };
Battle D_800A7770 = { 0, 0, 0x60040000 };
Battle D_800A777C = { 0, 0, 0x60040000 };
Battle D_800A7788 = { 0, 0, 0x60040000 };
Battle D_800A7794 = { 0, 0, 0x60040000 };
Battle D_800A77A0 = { 0, 0, 0x60040000 };
Battle D_800A77AC = { 0, 0, 0x60040000 };
BattleList D_800A77B8 = {
    0,
    { &D_800A7758, &D_800A7764, &D_800A7770, &D_800A777C,
      &D_800A7788, &D_800A7794, &D_800A77A0, &D_800A77AC },
};
Battle D_800A77DC = { 0, 0, 0x60040000 };
Battle D_800A77E8 = { 0, 0, 0x60040000 };
Battle D_800A77F4 = { 0, 0, 0x60040000 };
Battle D_800A7800 = { 0, 0, 0x60040000 };
Battle D_800A780C = { 0, 0, 0x60040000 };
Battle D_800A7818 = { 0, 0, 0x60040000 };
Battle D_800A7824 = { 0, 0, 0x60040000 };
Battle D_800A7830 = { 0, 0, 0x60040000 };
BattleList D_800A783C = {
    0,
    { &D_800A77DC, &D_800A77E8, &D_800A77F4, &D_800A7800,
      &D_800A780C, &D_800A7818, &D_800A7824, &D_800A7830 },
};
Battle D_800A7860 = { 182, 10, 0x60080000 };
Battle D_800A786C = { 182, 10, 0x60080000 };
Battle D_800A7878 = { 182, 10, 0x60080000 };
Battle D_800A7884 = { 182, 10, 0x60080000 };
Battle D_800A7890 = { 71, 10, 0x60080000 };
Battle D_800A789C = { 71, 10, 0x60080000 };
Battle D_800A78A8 = { 71, 10, 0x60080000 };
Battle D_800A78B4 = { 71, 10, 0x60080000 };
BattleList D_800A78C0 = {
    1,
    { &D_800A7860, &D_800A786C, &D_800A7878, &D_800A7884,
      &D_800A7890, &D_800A789C, &D_800A78A8, &D_800A78B4 },
};
Battle D_800A78E4 = { 0, 0, 0x60040000 };
Battle D_800A78F0 = { 0, 0, 0x60040000 };
Battle D_800A78FC = { 0, 0, 0x60040000 };
Battle D_800A7908 = { 0, 0, 0x60040000 };
Battle D_800A7914 = { 0, 0, 0x60040000 };
Battle D_800A7920 = { 0, 0, 0x60040000 };
Battle D_800A792C = { 0, 0, 0x60040000 };
Battle D_800A7938 = { 0, 0, 0x60040000 };
BattleList D_800A7944 = {
    0,
    { &D_800A78E4, &D_800A78F0, &D_800A78FC, &D_800A7908,
      &D_800A7914, &D_800A7920, &D_800A792C, &D_800A7938 },
};
Battle D_800A7968 = { 0, 0, 0x60040000 };
Battle D_800A7974 = { 0, 0, 0x60040000 };
Battle D_800A7980 = { 0, 0, 0x60040000 };
Battle D_800A798C = { 0, 0, 0x60040000 };
Battle D_800A7998 = { 0, 0, 0x60040000 };
Battle D_800A79A4 = { 0, 0, 0x60040000 };
Battle D_800A79B0 = { 0, 0, 0x60040000 };
Battle D_800A79BC = { 0, 0, 0x60040000 };
BattleList D_800A79C8 = {
    0,
    { &D_800A7968, &D_800A7974, &D_800A7980, &D_800A798C,
      &D_800A7998, &D_800A79A4, &D_800A79B0, &D_800A79BC },
};
Battle D_800A79EC = { 0, 0, 0x60040000 };
Battle D_800A79F8 = { 0, 0, 0x60040000 };
Battle D_800A7A04 = { 0, 0, 0x60040000 };
Battle D_800A7A10 = { 0, 0, 0x60040000 };
Battle D_800A7A1C = { 0, 0, 0x60040000 };
Battle D_800A7A28 = { 0, 0, 0x60040000 };
Battle D_800A7A34 = { 0, 0, 0x60040000 };
Battle D_800A7A40 = { 0, 0, 0x60040000 };
BattleList D_800A7A4C = {
    0,
    { &D_800A79EC, &D_800A79F8, &D_800A7A04, &D_800A7A10,
      &D_800A7A1C, &D_800A7A28, &D_800A7A34, &D_800A7A40 },
};
Battle D_800A7A70 = { 110, 10, 0x60080000 };
Battle D_800A7A7C = { 110, 10, 0x60080000 };
Battle D_800A7A88 = { 110, 10, 0x60080000 };
Battle D_800A7A94 = { 110, 10, 0x60080000 };
Battle D_800A7AA0 = { 110, 10, 0x60080000 };
Battle D_800A7AAC = { 110, 10, 0x60080000 };
Battle D_800A7AB8 = { 110, 10, 0x60080000 };
Battle D_800A7AC4 = { 110, 10, 0x60080000 };
BattleList D_800A7AD0 = {
    3,
    { &D_800A7A70, &D_800A7A7C, &D_800A7A88, &D_800A7A94,
      &D_800A7AA0, &D_800A7AAC, &D_800A7AB8, &D_800A7AC4 },
};
Battle D_800A7AF4 = { 0, 0, 0x60040000 };
Battle D_800A7B00 = { 0, 0, 0x60040000 };
Battle D_800A7B0C = { 0, 0, 0x60040000 };
Battle D_800A7B18 = { 0, 0, 0x60040000 };
Battle D_800A7B24 = { 0, 0, 0x60040000 };
Battle D_800A7B30 = { 0, 0, 0x60040000 };
Battle D_800A7B3C = { 0, 0, 0x60040000 };
Battle D_800A7B48 = { 0, 0, 0x60040000 };
BattleList D_800A7B54 = {
    0,
    { &D_800A7AF4, &D_800A7B00, &D_800A7B0C, &D_800A7B18,
      &D_800A7B24, &D_800A7B30, &D_800A7B3C, &D_800A7B48 },
};
Battle D_800A7B78 = { 0, 0, 0x60040000 };
Battle D_800A7B84 = { 0, 0, 0x60040000 };
Battle D_800A7B90 = { 0, 0, 0x60040000 };
Battle D_800A7B9C = { 0, 0, 0x60040000 };
Battle D_800A7BA8 = { 0, 0, 0x60040000 };
Battle D_800A7BB4 = { 0, 0, 0x60040000 };
Battle D_800A7BC0 = { 0, 0, 0x60040000 };
Battle D_800A7BCC = { 0, 0, 0x60040000 };
BattleList D_800A7BD8 = {
    0,
    { &D_800A7B78, &D_800A7B84, &D_800A7B90, &D_800A7B9C,
      &D_800A7BA8, &D_800A7BB4, &D_800A7BC0, &D_800A7BCC },
};
Battle D_800A7BFC = { 0, 0, 0x60040000 };
Battle D_800A7C08 = { 0, 0, 0x60040000 };
Battle D_800A7C14 = { 0, 0, 0x60040000 };
Battle D_800A7C20 = { 0, 0, 0x60040000 };
Battle D_800A7C2C = { 0, 0, 0x60040000 };
Battle D_800A7C38 = { 0, 0, 0x60040000 };
Battle D_800A7C44 = { 0, 0, 0x60040000 };
Battle D_800A7C50 = { 0, 0, 0x60040000 };
BattleList D_800A7C5C = {
    0,
    { &D_800A7BFC, &D_800A7C08, &D_800A7C14, &D_800A7C20,
      &D_800A7C2C, &D_800A7C38, &D_800A7C44, &D_800A7C50 },
};
Battle D_800A7C80 = { 110, 10, 0x60080000 };
Battle D_800A7C8C = { 110, 10, 0x60080000 };
Battle D_800A7C98 = { 110, 10, 0x60080000 };
Battle D_800A7CA4 = { 110, 10, 0x60080000 };
Battle D_800A7CB0 = { 110, 10, 0x60080000 };
Battle D_800A7CBC = { 110, 10, 0x60080000 };
Battle D_800A7CC8 = { 110, 10, 0x60080000 };
Battle D_800A7CD4 = { 110, 10, 0x60080000 };
BattleList D_800A7CE0 = {
    3,
    { &D_800A7C80, &D_800A7C8C, &D_800A7C98, &D_800A7CA4,
      &D_800A7CB0, &D_800A7CBC, &D_800A7CC8, &D_800A7CD4 },
};
Battle D_800A7D04 = { 0, 0, 0x60040000 };
Battle D_800A7D10 = { 0, 0, 0x60040000 };
Battle D_800A7D1C = { 0, 0, 0x60040000 };
Battle D_800A7D28 = { 0, 0, 0x60040000 };
Battle D_800A7D34 = { 0, 0, 0x60040000 };
Battle D_800A7D40 = { 0, 0, 0x60040000 };
Battle D_800A7D4C = { 0, 0, 0x60040000 };
Battle D_800A7D58 = { 0, 0, 0x60040000 };
BattleList D_800A7D64 = {
    0,
    { &D_800A7D04, &D_800A7D10, &D_800A7D1C, &D_800A7D28,
      &D_800A7D34, &D_800A7D40, &D_800A7D4C, &D_800A7D58 },
};
Battle D_800A7D88 = { 0, 0, 0x60040000 };
Battle D_800A7D94 = { 0, 0, 0x60040000 };
Battle D_800A7DA0 = { 0, 0, 0x60040000 };
Battle D_800A7DAC = { 0, 0, 0x60040000 };
Battle D_800A7DB8 = { 0, 0, 0x60040000 };
Battle D_800A7DC4 = { 0, 0, 0x60040000 };
Battle D_800A7DD0 = { 0, 0, 0x60040000 };
Battle D_800A7DDC = { 0, 0, 0x60040000 };
BattleList D_800A7DE8 = {
    0,
    { &D_800A7D88, &D_800A7D94, &D_800A7DA0, &D_800A7DAC,
      &D_800A7DB8, &D_800A7DC4, &D_800A7DD0, &D_800A7DDC },
};
Battle D_800A7E0C = { 0, 0, 0x60040000 };
Battle D_800A7E18 = { 0, 0, 0x60040000 };
Battle D_800A7E24 = { 0, 0, 0x60040000 };
Battle D_800A7E30 = { 0, 0, 0x60040000 };
Battle D_800A7E3C = { 0, 0, 0x60040000 };
Battle D_800A7E48 = { 0, 0, 0x60040000 };
Battle D_800A7E54 = { 0, 0, 0x60040000 };
Battle D_800A7E60 = { 0, 0, 0x60040000 };
BattleList D_800A7E6C = {
    0,
    { &D_800A7E0C, &D_800A7E18, &D_800A7E24, &D_800A7E30,
      &D_800A7E3C, &D_800A7E48, &D_800A7E54, &D_800A7E60 },
};
Battle D_800A7E90 = { 182, 10, 0x60080000 };
Battle D_800A7E9C = { 182, 10, 0x60080000 };
Battle D_800A7EA8 = { 182, 10, 0x60080000 };
Battle D_800A7EB4 = { 182, 10, 0x60080000 };
Battle D_800A7EC0 = { 71, 10, 0x60080000 };
Battle D_800A7ECC = { 71, 10, 0x60080000 };
Battle D_800A7ED8 = { 71, 10, 0x60080000 };
Battle D_800A7EE4 = { 71, 10, 0x60080000 };
BattleList D_800A7EF0 = {
    2,
    { &D_800A7E90, &D_800A7E9C, &D_800A7EA8, &D_800A7EB4,
      &D_800A7EC0, &D_800A7ECC, &D_800A7ED8, &D_800A7EE4 },
};
Battle D_800A7F14 = { 0, 0, 0x60040000 };
Battle D_800A7F20 = { 0, 0, 0x60040000 };
Battle D_800A7F2C = { 0, 0, 0x60040000 };
Battle D_800A7F38 = { 0, 0, 0x60040000 };
Battle D_800A7F44 = { 0, 0, 0x60040000 };
Battle D_800A7F50 = { 0, 0, 0x60040000 };
Battle D_800A7F5C = { 0, 0, 0x60040000 };
Battle D_800A7F68 = { 0, 0, 0x60040000 };
BattleList D_800A7F74 = {
    0,
    { &D_800A7F14, &D_800A7F20, &D_800A7F2C, &D_800A7F38,
      &D_800A7F44, &D_800A7F50, &D_800A7F5C, &D_800A7F68 },
};
Battle D_800A7F98 = { 0, 0, 0x60040000 };
Battle D_800A7FA4 = { 0, 0, 0x60040000 };
Battle D_800A7FB0 = { 0, 0, 0x60040000 };
Battle D_800A7FBC = { 0, 0, 0x60040000 };
Battle D_800A7FC8 = { 0, 0, 0x60040000 };
Battle D_800A7FD4 = { 0, 0, 0x60040000 };
Battle D_800A7FE0 = { 0, 0, 0x60040000 };
Battle D_800A7FEC = { 0, 0, 0x60040000 };
BattleList D_800A7FF8 = {
    0,
    { &D_800A7F98, &D_800A7FA4, &D_800A7FB0, &D_800A7FBC,
      &D_800A7FC8, &D_800A7FD4, &D_800A7FE0, &D_800A7FEC },
};
Battle D_800A801C = { 0, 0, 0x60040000 };
Battle D_800A8028 = { 0, 0, 0x60040000 };
Battle D_800A8034 = { 0, 0, 0x60040000 };
Battle D_800A8040 = { 0, 0, 0x60040000 };
Battle D_800A804C = { 0, 0, 0x60040000 };
Battle D_800A8058 = { 0, 0, 0x60040000 };
Battle D_800A8064 = { 0, 0, 0x60040000 };
Battle D_800A8070 = { 0, 0, 0x60040000 };
BattleList D_800A807C = {
    0,
    { &D_800A801C, &D_800A8028, &D_800A8034, &D_800A8040,
      &D_800A804C, &D_800A8058, &D_800A8064, &D_800A8070 },
};
Battle D_800A80A0 = { 182, 10, 0x60080000 };
Battle D_800A80AC = { 182, 10, 0x60080000 };
Battle D_800A80B8 = { 182, 10, 0x60080000 };
Battle D_800A80C4 = { 182, 10, 0x60080000 };
Battle D_800A80D0 = { 71, 10, 0x60080000 };
Battle D_800A80DC = { 71, 10, 0x60080000 };
Battle D_800A80E8 = { 71, 10, 0x60080000 };
Battle D_800A80F4 = { 71, 10, 0x60080000 };
BattleList D_800A8100 = {
    4,
    { &D_800A80A0, &D_800A80AC, &D_800A80B8, &D_800A80C4,
      &D_800A80D0, &D_800A80DC, &D_800A80E8, &D_800A80F4 },
};
Battle D_800A8124 = { 0, 0, 0x60040000 };
Battle D_800A8130 = { 0, 0, 0x60040000 };
Battle D_800A813C = { 0, 0, 0x60040000 };
Battle D_800A8148 = { 0, 0, 0x60040000 };
Battle D_800A8154 = { 0, 0, 0x60040000 };
Battle D_800A8160 = { 0, 0, 0x60040000 };
Battle D_800A816C = { 0, 0, 0x60040000 };
Battle D_800A8178 = { 0, 0, 0x60040000 };
BattleList D_800A8184 = {
    0,
    { &D_800A8124, &D_800A8130, &D_800A813C, &D_800A8148,
      &D_800A8154, &D_800A8160, &D_800A816C, &D_800A8178 },
};
Battle D_800A81A8 = { 0, 0, 0x60040000 };
Battle D_800A81B4 = { 0, 0, 0x60040000 };
Battle D_800A81C0 = { 0, 0, 0x60040000 };
Battle D_800A81CC = { 0, 0, 0x60040000 };
Battle D_800A81D8 = { 0, 0, 0x60040000 };
Battle D_800A81E4 = { 0, 0, 0x60040000 };
Battle D_800A81F0 = { 0, 0, 0x60040000 };
Battle D_800A81FC = { 0, 0, 0x60040000 };
BattleList D_800A8208 = {
    0,
    { &D_800A81A8, &D_800A81B4, &D_800A81C0, &D_800A81CC,
      &D_800A81D8, &D_800A81E4, &D_800A81F0, &D_800A81FC },
};
Battle D_800A822C = { 0, 0, 0x60040000 };
Battle D_800A8238 = { 0, 0, 0x60040000 };
Battle D_800A8244 = { 0, 0, 0x60040000 };
Battle D_800A8250 = { 0, 0, 0x60040000 };
Battle D_800A825C = { 0, 0, 0x60040000 };
Battle D_800A8268 = { 0, 0, 0x60040000 };
Battle D_800A8274 = { 0, 0, 0x60040000 };
Battle D_800A8280 = { 0, 0, 0x60040000 };
BattleList D_800A828C = {
    0,
    { &D_800A822C, &D_800A8238, &D_800A8244, &D_800A8250,
      &D_800A825C, &D_800A8268, &D_800A8274, &D_800A8280 },
};
Battle D_800A82B0 = { 182, 10, 0x60080000 };
Battle D_800A82BC = { 182, 10, 0x60080000 };
Battle D_800A82C8 = { 182, 10, 0x60080000 };
Battle D_800A82D4 = { 182, 10, 0x60080000 };
Battle D_800A82E0 = { 71, 10, 0x60080000 };
Battle D_800A82EC = { 71, 10, 0x60080000 };
Battle D_800A82F8 = { 71, 10, 0x60080000 };
Battle D_800A8304 = { 71, 10, 0x60080000 };
BattleList D_800A8310 = {
    1,
    { &D_800A82B0, &D_800A82BC, &D_800A82C8, &D_800A82D4,
      &D_800A82E0, &D_800A82EC, &D_800A82F8, &D_800A8304 },
};
Battle D_800A8334 = { 0, 0, 0x60040000 };
Battle D_800A8340 = { 0, 0, 0x60040000 };
Battle D_800A834C = { 0, 0, 0x60040000 };
Battle D_800A8358 = { 0, 0, 0x60040000 };
Battle D_800A8364 = { 0, 0, 0x60040000 };
Battle D_800A8370 = { 0, 0, 0x60040000 };
Battle D_800A837C = { 0, 0, 0x60040000 };
Battle D_800A8388 = { 0, 0, 0x60040000 };
BattleList D_800A8394 = {
    0,
    { &D_800A8334, &D_800A8340, &D_800A834C, &D_800A8358,
      &D_800A8364, &D_800A8370, &D_800A837C, &D_800A8388 },
};
Battle D_800A83B8 = { 0, 0, 0x60040000 };
Battle D_800A83C4 = { 0, 0, 0x60040000 };
Battle D_800A83D0 = { 0, 0, 0x60040000 };
Battle D_800A83DC = { 0, 0, 0x60040000 };
Battle D_800A83E8 = { 0, 0, 0x60040000 };
Battle D_800A83F4 = { 0, 0, 0x60040000 };
Battle D_800A8400 = { 0, 0, 0x60040000 };
Battle D_800A840C = { 0, 0, 0x60040000 };
BattleList D_800A8418 = {
    0,
    { &D_800A83B8, &D_800A83C4, &D_800A83D0, &D_800A83DC,
      &D_800A83E8, &D_800A83F4, &D_800A8400, &D_800A840C },
};
Battle D_800A843C = { 0, 0, 0x60040000 };
Battle D_800A8448 = { 0, 0, 0x60040000 };
Battle D_800A8454 = { 0, 0, 0x60040000 };
Battle D_800A8460 = { 0, 0, 0x60040000 };
Battle D_800A846C = { 0, 0, 0x60040000 };
Battle D_800A8478 = { 0, 0, 0x60040000 };
Battle D_800A8484 = { 0, 0, 0x60040000 };
Battle D_800A8490 = { 0, 0, 0x60040000 };
BattleList D_800A849C = {
    0,
    { &D_800A843C, &D_800A8448, &D_800A8454, &D_800A8460,
      &D_800A846C, &D_800A8478, &D_800A8484, &D_800A8490 },
};
Battle D_800A84C0 = { 182, 10, 0x60080000 };
Battle D_800A84CC = { 182, 10, 0x60080000 };
Battle D_800A84D8 = { 182, 10, 0x60080000 };
Battle D_800A84E4 = { 182, 10, 0x60080000 };
Battle D_800A84F0 = { 71, 10, 0x60080000 };
Battle D_800A84FC = { 71, 10, 0x60080000 };
Battle D_800A8508 = { 71, 10, 0x60080000 };
Battle D_800A8514 = { 71, 10, 0x60080000 };
BattleList D_800A8520 = {
    1,
    { &D_800A84C0, &D_800A84CC, &D_800A84D8, &D_800A84E4,
      &D_800A84F0, &D_800A84FC, &D_800A8508, &D_800A8514 },
};
Battle D_800A8544 = { 0, 0, 0x60040000 };
Battle D_800A8550 = { 0, 0, 0x60040000 };
Battle D_800A855C = { 0, 0, 0x60040000 };
Battle D_800A8568 = { 0, 0, 0x60040000 };
Battle D_800A8574 = { 0, 0, 0x60040000 };
Battle D_800A8580 = { 0, 0, 0x60040000 };
Battle D_800A858C = { 0, 0, 0x60040000 };
Battle D_800A8598 = { 0, 0, 0x60040000 };
BattleList D_800A85A4 = {
    0,
    { &D_800A8544, &D_800A8550, &D_800A855C, &D_800A8568,
      &D_800A8574, &D_800A8580, &D_800A858C, &D_800A8598 },
};
Battle D_800A85C8 = { 0, 0, 0x60040000 };
Battle D_800A85D4 = { 0, 0, 0x60040000 };
Battle D_800A85E0 = { 0, 0, 0x60040000 };
Battle D_800A85EC = { 0, 0, 0x60040000 };
Battle D_800A85F8 = { 0, 0, 0x60040000 };
Battle D_800A8604 = { 0, 0, 0x60040000 };
Battle D_800A8610 = { 0, 0, 0x60040000 };
Battle D_800A861C = { 0, 0, 0x60040000 };
BattleList D_800A8628 = {
    0,
    { &D_800A85C8, &D_800A85D4, &D_800A85E0, &D_800A85EC,
      &D_800A85F8, &D_800A8604, &D_800A8610, &D_800A861C },
};
Battle D_800A864C = { 0, 0, 0x60040000 };
Battle D_800A8658 = { 0, 0, 0x60040000 };
Battle D_800A8664 = { 0, 0, 0x60040000 };
Battle D_800A8670 = { 0, 0, 0x60040000 };
Battle D_800A867C = { 0, 0, 0x60040000 };
Battle D_800A8688 = { 0, 0, 0x60040000 };
Battle D_800A8694 = { 0, 0, 0x60040000 };
Battle D_800A86A0 = { 0, 0, 0x60040000 };
BattleList D_800A86AC = {
    0,
    { &D_800A864C, &D_800A8658, &D_800A8664, &D_800A8670,
      &D_800A867C, &D_800A8688, &D_800A8694, &D_800A86A0 },
};
Battle D_800A86D0 = { 174, 10, 0x60080000 };
Battle D_800A86DC = { 174, 10, 0x60080000 };
Battle D_800A86E8 = { 170, 10, 0x60080000 };
Battle D_800A86F4 = { 170, 10, 0x60080000 };
Battle D_800A8700 = { 182, 10, 0x60080000 };
Battle D_800A870C = { 182, 10, 0x60080000 };
Battle D_800A8718 = { 71, 10, 0x60080000 };
Battle D_800A8724 = { 71, 10, 0x60080000 };
BattleList D_800A8730 = {
    1,
    { &D_800A86D0, &D_800A86DC, &D_800A86E8, &D_800A86F4,
      &D_800A8700, &D_800A870C, &D_800A8718, &D_800A8724 },
};
Battle D_800A8754 = { 0, 0, 0x60040000 };
Battle D_800A8760 = { 0, 0, 0x60040000 };
Battle D_800A876C = { 0, 0, 0x60040000 };
Battle D_800A8778 = { 0, 0, 0x60040000 };
Battle D_800A8784 = { 0, 0, 0x60040000 };
Battle D_800A8790 = { 0, 0, 0x60040000 };
Battle D_800A879C = { 0, 0, 0x60040000 };
Battle D_800A87A8 = { 0, 0, 0x60040000 };
BattleList D_800A87B4 = {
    0,
    { &D_800A8754, &D_800A8760, &D_800A876C, &D_800A8778,
      &D_800A8784, &D_800A8790, &D_800A879C, &D_800A87A8 },
};
Battle D_800A87D8 = { 0, 0, 0x60040000 };
Battle D_800A87E4 = { 0, 0, 0x60040000 };
Battle D_800A87F0 = { 0, 0, 0x60040000 };
Battle D_800A87FC = { 0, 0, 0x60040000 };
Battle D_800A8808 = { 0, 0, 0x60040000 };
Battle D_800A8814 = { 0, 0, 0x60040000 };
Battle D_800A8820 = { 0, 0, 0x60040000 };
Battle D_800A882C = { 0, 0, 0x60040000 };
BattleList D_800A8838 = {
    0,
    { &D_800A87D8, &D_800A87E4, &D_800A87F0, &D_800A87FC,
      &D_800A8808, &D_800A8814, &D_800A8820, &D_800A882C },
};
Battle D_800A885C = { 0, 0, 0x60040000 };
Battle D_800A8868 = { 0, 0, 0x60040000 };
Battle D_800A8874 = { 0, 0, 0x60040000 };
Battle D_800A8880 = { 0, 0, 0x60040000 };
Battle D_800A888C = { 0, 0, 0x60040000 };
Battle D_800A8898 = { 0, 0, 0x60040000 };
Battle D_800A88A4 = { 0, 0, 0x60040000 };
Battle D_800A88B0 = { 0, 0, 0x60040000 };
BattleList D_800A88BC = {
    0,
    { &D_800A885C, &D_800A8868, &D_800A8874, &D_800A8880,
      &D_800A888C, &D_800A8898, &D_800A88A4, &D_800A88B0 },
};
FieldBattles stageBattles[] = {
    { 233, 1, 0, { &D_800A59D0, &D_800A5A54, &D_800A5AD8, &D_800A5B5C } },
    { 239, 2, 0, { &D_800A5BE0, &D_800A5C64, &D_800A5CE8, &D_800A5D6C } },
    { 244, 3, 0, { &D_800A5DF0, &D_800A5E74, &D_800A5EF8, &D_800A5F7C } },
    { 248, 4, 0, { &D_800A6000, &D_800A6084, &D_800A6108, &D_800A618C } },
    { 255, 5, 0, { &D_800A6210, &D_800A6294, &D_800A6318, &D_800A639C } },
    { 262, 6, 0, { &D_800A6420, &D_800A64A4, &D_800A6528, &D_800A65AC } },
    { 266, 7, 0, { &D_800A6630, &D_800A66B4, &D_800A6738, &D_800A67BC } },
    { 272, 8, 0, { &D_800A6840, &D_800A68C4, &D_800A6948, &D_800A69CC } },
    { 277, 9, 0, { &D_800A6A50, &D_800A6AD4, &D_800A6B58, &D_800A6BDC } },
    { 282, 10, 0, { &D_800A6C60, &D_800A6CE4, &D_800A6D68, &D_800A6DEC } },
    { 287, 11, 0, { &D_800A6E70, &D_800A6EF4, &D_800A6F78, &D_800A6FFC } },
    { 292, 12, 0, { &D_800A7080, &D_800A7104, &D_800A7188, &D_800A720C } },
    { 299, 13, 0, { &D_800A7290, &D_800A7314, &D_800A7398, &D_800A741C } },
    { 309, 16, 0, { &D_800A74A0, &D_800A7524, &D_800A75A8, &D_800A762C } },
    { 320, 19, 0, { &D_800A76B0, &D_800A7734, &D_800A77B8, &D_800A783C } },
    { 325, 20, 0, { &D_800A78C0, &D_800A7944, &D_800A79C8, &D_800A7A4C } },
    { 332, 21, 0, { &D_800A7AD0, &D_800A7B54, &D_800A7BD8, &D_800A7C5C } },
    { 336, 22, 0, { &D_800A7CE0, &D_800A7D64, &D_800A7DE8, &D_800A7E6C } },
    { 340, 23, 0, { &D_800A7EF0, &D_800A7F74, &D_800A7FF8, &D_800A807C } },
    { 347, 25, 0, { &D_800A8100, &D_800A8184, &D_800A8208, &D_800A828C } },
    { 360, 28, 0, { &D_800A8310, &D_800A8394, &D_800A8418, &D_800A849C } },
    { 365, 29, 0, { &D_800A8520, &D_800A85A4, &D_800A8628, &D_800A86AC } },
    { 372, 30, 0, { &D_800A8730, &D_800A87B4, &D_800A8838, &D_800A88BC } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14C, 0x140, 0x30, 0x40, 0x140, 0x1FF },
    { 0x140, 0x100, 0x154, 0x140, 0x50, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x15C, 0x140, 0x70, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x164, 0x140, 0x90, 0x40, 0x170, 0x1FF },
    { 0x140, 0x100, 0x16C, 0x140, 0xB0, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x174, 0x140, 0xD0, 0x40, 0x150, 0x1FE },
    { 0x140, 0x100, 0x14C, 0x160, 0x30, 0x60, 0x160, 0x1FE },
    { 0x140, 0x100, 0x154, 0x160, 0x50, 0x60, 0x170, 0x1FE },
    { 0x140, 0x100, 0x15C, 0x160, 0x70, 0x60, 0x140, 0x1FD },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x150, 0x1FD },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x160, 0x1FD },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x170, 0x1FD },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x140, 0x1FC },
};
FieldTalk D_800A8C94[] = {
    { NULL, NULL, 0x35E },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8CAC[] = {
    { NULL, NULL, 0x3BD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8CC4[] = {
    { NULL, NULL, 0x3BF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8CDC[] = {
    { NULL, NULL, 0x3C0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8CF4[] = {
    { NULL, NULL, 0x3C7 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D0C[] = {
    { NULL, NULL, 0x361 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D24[] = {
    { NULL, NULL, 0x3C3 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D3C[] = {
    { NULL, NULL, 0x3C4 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D54[] = {
    { NULL, NULL, 0x3C5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D6C[] = {
    { NULL, NULL, 0x3C6 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D84[] = {
    { NULL, NULL, 0x364 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D9C[] = {
    { NULL, NULL, 0x3BE },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8DB4[] = {
    { NULL, NULL, 0x3C1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8DCC[] = {
    { NULL, NULL, 0x3C2 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8DE4[] = {
    { NULL, NULL, 0x3C8 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8DFC[] = {
    { NULL, NULL, 0x35F },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8E14[] = {
    { NULL, NULL, 0x360 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8E2C[] = {
    { NULL, NULL, 0x362 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8E44[] = {
    { NULL, NULL, 0x363 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8E5C[] = {
    { NULL, NULL, 0x365 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8E74[] = {
    { NULL, NULL, 0x366 },
    { NULL, NULL, 0 },
};
u16 D_800A8E8C[] = { 0x7E00, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8E98[] = { 0x7E01, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8EA4[] = { 0x7E02, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8EB0[] = { 0x7E03, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8EBC[] = { 0x7E1B, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8EC8[] = { 0x7E06, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8ED4[] = { 0x7E0B, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8EE0[] = { 0x7E0C, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8EEC[] = { 0x7E12, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8EF8[] = { 0x7E13, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8F04[] = { 0x7E07, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F10[] = { 0x7E02, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F1C[] = { 0x7E03, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8F28[] = { 0x7E08, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F34[] = { 0x7E1C, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F40[] = { 0x7E02, 1, 0x7E20, 1, 0xFFFF };
u16 D_800A8F4C[] = { 0x7E16, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F58[] = { 0x7E09, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F64[] = { 0x7E1D, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F70[] = { 0x7E0A, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F7C[] = { 0x7E15, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8F88[] = { 0x7E03, 1, 8, 0, 0xFFFF };
u16 D_800A8F94[] = { 0x7E05, 1, 8, 0, 0xFFFF };
u16 D_800A8FA0[] = { 0x7E0B, 1, 8, 0, 0xFFFF };
u16 D_800A8FAC[] = { 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A8FB8[] = { 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A8FC4[] = { 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A8FD0[] = { 0x7E02, 1, 0xA, 0, 0xFFFF };
u16 D_800A8FDC[] = { 0x7E03, 1, 0xA, 0, 0xFFFF };
u16 D_800A8FE8[] = { 0x7E04, 1, 0xA, 0, 0xFFFF };
u16 D_800A8FF4[] = { 0x7E05, 1, 0xA, 0, 0xFFFF };
u16 D_800A9000[] = { 0x7E08, 1, 0xA, 0, 0xFFFF };
u16 D_800A900C[] = { 0x7E0B, 1, 0xA, 0, 0xFFFF };
u16 D_800A9018[] = { 0x7E0C, 1, 0xA, 0, 0xFFFF };
u16 D_800A9024[] = { 0x7E12, 1, 0xA, 0, 0xFFFF };
u16 D_800A9030[] = { 0x7E13, 1, 0xA, 0, 0xFFFF };
u16 D_800A903C[] = { 0x7E1D, 1, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A9048 = { D_800A8E8C, D_800A8C94, 0x22, 4, 456, 424, 1 };
FieldActorEntry D_800A905C = { D_800A8E98, D_800A8CAC, 0x22, 4, 168, 256, 5 };
FieldActorEntry D_800A9070 = { D_800A8EA4, D_800A8CC4, 0x22, 4, 840, 520, 1 };
FieldActorEntry D_800A9084 = { D_800A8EB0, D_800A8CDC, 0x22, 4, 168, 256, 5 };
FieldActorEntry D_800A9098 = { D_800A8EBC, D_800A8CF4, 0x22, 4, 456, 424, 1 };
FieldActorEntry D_800A90AC = { D_800A8EC8, D_800A8D0C, 0x40, 5, 456, 424, 1 };
FieldActorEntry D_800A90C0 = { D_800A8ED4, D_800A8D24, 0x40, 5, 456, 424, 1 };
FieldActorEntry D_800A90D4 = { D_800A8EE0, D_800A8D3C, 0x40, 5, 840, 520, 1 };
FieldActorEntry D_800A90E8 = { D_800A8EEC, D_800A8D54, 0x40, 5, 168, 256, 5 };
FieldActorEntry D_800A90FC = { D_800A8EF8, D_800A8D6C, 0x40, 5, 840, 520, 1 };
FieldActorEntry D_800A9110 = { D_800A8F04, D_800A8D84, 0xB4, 6, 456, 424, 1 };
FieldActorEntry D_800A9124 = { D_800A8F10, D_800A8D9C, 0xB4, 6, 840, 520, 1 };
FieldActorEntry D_800A9138 = { D_800A8F1C, D_800A8DB4, 0xB4, 6, 840, 520, 1 };
FieldActorEntry D_800A914C = { D_800A8F28, D_800A8DCC, 0xB4, 6, 168, 256, 5 };
FieldActorEntry D_800A9160 = { D_800A8F34, D_800A8DE4, 0xB4, 6, 168, 256, 5 };
FieldActorEntry D_800A9174 = { D_800A8F40, D_800A8DFC, 0xE2, 7, 456, 424, 1 };
FieldActorEntry D_800A9188 = { D_800A8F4C, D_800A8E14, 0xE3, 8, 456, 424, 1 };
FieldActorEntry D_800A919C = { D_800A8F58, D_800A8E2C, 0xE7, 9, 456, 424, 1 };
FieldActorEntry D_800A91B0 = { D_800A8F64, D_800A8E44, 0xE8, 0xA, 456, 424, 1 };
FieldActorEntry D_800A91C4 = { D_800A8F70, D_800A8E5C, 0xF1, 0xB, 456, 424, 1 };
FieldActorEntry D_800A91D8 = { D_800A8F7C, D_800A8E74, 0xF2, 0xC, 456, 424, 1 };
FieldActorEntry D_800A91EC = { NULL, NULL, 0x146, 0xD, 0, 0, 0 };
FieldActorEntry D_800A9200 = { D_800A8F88, NULL, 0x148, 0xE, 256, 224, 1 };
FieldActorEntry D_800A9214 = { D_800A8F94, NULL, 0x148, 0xE, 448, 528, 1 };
FieldActorEntry D_800A9228 = { D_800A8FA0, NULL, 0x148, 0xE, 704, 416, 1 };
FieldActorEntry D_800A923C = { D_800A8FAC, NULL, 0x15F, 0xF, 624, 304, 1 };
FieldActorEntry D_800A9250 = { D_800A8FB8, NULL, 0x15F, 0xF, 720, 544, 1 };
FieldActorEntry D_800A9264 = { D_800A8FC4, NULL, 0x15F, 0xF, 784, 488, 1 };
FieldActorEntry D_800A9278 = { D_800A8FD0, NULL, 0x160, 0x10, 608, 512, 1 };
FieldActorEntry D_800A928C = { D_800A8FDC, NULL, 0x160, 0x10, 864, 448, 1 };
FieldActorEntry D_800A92A0 = { D_800A8FE8, NULL, 0x160, 0x10, 288, 544, 1 };
FieldActorEntry D_800A92B4 = { D_800A8FF4, NULL, 0x160, 0x10, 440, 324, 1 };
FieldActorEntry D_800A92C8 = { D_800A9000, NULL, 0x160, 0x10, 288, 544, 1 };
FieldActorEntry D_800A92DC = { D_800A900C, NULL, 0x160, 0x10, 280, 300, 1 };
FieldActorEntry D_800A92F0 = { D_800A9018, NULL, 0x160, 0x10, 864, 448, 1 };
FieldActorEntry D_800A9304 = { D_800A9024, NULL, 0x160, 0x10, 608, 512, 1 };
FieldActorEntry D_800A9318 = { D_800A9030, NULL, 0x160, 0x10, 256, 224, 1 };
FieldActorEntry D_800A932C = { D_800A903C, NULL, 0x160, 0x10, 280, 300, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A9048,
    &D_800A905C,
    &D_800A9070,
    &D_800A9084,
    &D_800A9098,
    &D_800A90AC,
    &D_800A90C0,
    &D_800A90D4,
    &D_800A90E8,
    &D_800A90FC,
    &D_800A9110,
    &D_800A9124,
    &D_800A9138,
    &D_800A914C,
    &D_800A9160,
    &D_800A9174,
    &D_800A9188,
    &D_800A919C,
    &D_800A91B0,
    &D_800A91C4,
    &D_800A91D8,
    &D_800A91EC,
    &D_800A9200,
    &D_800A9214,
    &D_800A9228,
    &D_800A923C,
    &D_800A9250,
    &D_800A9264,
    &D_800A9278,
    &D_800A928C,
    &D_800A92A0,
    &D_800A92B4,
    &D_800A92C8,
    &D_800A92DC,
    &D_800A92F0,
    &D_800A9304,
    &D_800A9318,
    &D_800A932C,
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
