#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x683
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x693
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x37200, 0x1CE00};
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
extern StagePoint D_800A4FBC;
extern StagePoint D_800A4FCC;
extern StagePoint D_800A4FE4;
extern StagePoint D_800A4FF4;
extern StagePoint D_800A500C;
extern StagePoint D_800A501C;
extern StagePoint D_800A5034;
extern StagePoint D_800A5044;
extern StagePoint D_800A505C;
extern StagePoint D_800A506C;
extern StagePoint D_800A5084;
extern StagePoint D_800A5094;
extern StagePoint D_800A50AC;
extern StagePoint D_800A50BC;
extern StagePoint D_800A50D4;
extern StagePoint D_800A50E4;
extern StagePoint D_800A50FC;
extern StagePoint D_800A510C;
extern StagePoint D_800A5124;
extern StagePoint D_800A5134;
extern StagePoint D_800A514C;
extern StagePoint D_800A515C;
extern StagePoint D_800A5174;
extern StagePoint D_800A5184;
extern StagePoint D_800A519C;
extern StagePoint D_800A51AC;
extern StagePoint D_800A51C4;
extern StagePoint D_800A51D4;
extern StagePoint D_800A51EC;
extern StagePoint D_800A51FC;
extern StagePoint D_800A5214;
extern StagePoint D_800A5224;
extern StagePoint D_800A523C;
extern StagePoint D_800A524C;
extern StagePoint D_800A5264;
extern StagePoint D_800A5274;
extern StagePoint D_800A528C;
extern StagePoint D_800A529C;
extern StagePoint D_800A52B4;
extern StagePoint D_800A52C4;
extern StagePoint D_800A52DC;
extern StagePoint D_800A52EC;
extern StagePoint D_800A5304;
extern StagePoint D_800A5314;
extern StagePoint D_800A532C;
extern StagePoint D_800A533C;
extern StagePoint D_800A5354;
extern StagePoint D_800A5364;
extern StagePoint D_800A537C;
extern StagePoint D_800A538C;
extern StagePoint D_800A53A4;
extern StagePoint D_800A53B4;
extern StagePoint D_800A53CC;
extern StagePoint D_800A53DC;
extern StagePoint D_800A53F4;
extern StagePoint D_800A5404;
extern StagePoint D_800A541C;
extern StagePoint D_800A542C;
extern StagePoint D_800A5444;
extern StagePoint D_800A5454;
extern StagePoint D_800A546C;
extern StagePoint D_800A547C;
extern StagePoint D_800A5494;
extern StagePoint D_800A54A4;
extern StagePoint D_800A54BC;
extern StagePoint D_800A54CC;
extern StagePoint D_800A54E4;
extern StagePoint D_800A54F4;
extern StagePoint D_800A550C;
extern StagePoint D_800A551C;
extern StagePoint D_800A5534;
extern StagePoint D_800A5544;
extern StagePoint D_800A555C;
extern StagePoint D_800A556C;
extern StagePoint D_800A5584;
extern StagePoint D_800A5594;
extern StagePoint D_800A55AC;
extern StagePoint D_800A55BC;
extern StagePoint D_800A55D4;
extern StagePoint D_800A55E4;
extern StagePoint D_800A55FC;
extern StagePoint D_800A560C;
extern StagePoint D_800A5624;
extern StagePoint D_800A5634;
extern StagePoint D_800A564C;
extern StagePoint D_800A565C;
extern StagePoint D_800A5674;
extern StagePoint D_800A5684;
extern StagePoint D_800A569C;
extern StagePoint D_800A56AC;
extern StagePoint D_800A56C4;
extern StagePoint D_800A56D4;
extern StagePoint D_800A56EC;
extern StagePoint D_800A56FC;
extern StagePoint D_800A5714;
extern StagePoint D_800A5724;
extern StagePoint D_800A573C;
extern StagePoint D_800A574C;
extern StagePoint D_800A5764;
extern StagePoint D_800A5774;
extern StagePoint D_800A578C;
extern StagePoint D_800A579C;
extern StagePoint D_800A57B4;
extern StagePoint D_800A57C4;
extern StagePoint D_800A57DC;
extern StagePoint D_800A57EC;
extern StagePoint D_800A5804;
extern StagePoint D_800A5814;
extern StagePoint D_800A582C;
extern StagePoint D_800A583C;
extern StagePoint D_800A5854;
extern StagePoint D_800A5864;
extern StagePoint D_800A587C;
extern StagePoint D_800A588C;
extern StagePoint D_800A58A4;
extern StagePoint D_800A58B4;
extern StagePoint D_800A58CC;
extern StagePoint D_800A58DC;
extern StagePoint D_800A58F4;
extern StagePoint D_800A5904;
extern StagePoint D_800A591C;
extern StagePoint D_800A592C;
extern StagePoints D_800A4FB4;
extern StagePoints D_800A4FDC;
extern StagePoints D_800A5004;
extern StagePoints D_800A502C;
extern StagePoints D_800A5054;
extern StagePoints D_800A507C;
extern StagePoints D_800A50A4;
extern StagePoints D_800A50CC;
extern StagePoints D_800A50F4;
extern StagePoints D_800A511C;
extern StagePoints D_800A5144;
extern StagePoints D_800A516C;
extern StagePoints D_800A5194;
extern StagePoints D_800A51BC;
extern StagePoints D_800A51E4;
extern StagePoints D_800A520C;
extern StagePoints D_800A5234;
extern StagePoints D_800A525C;
extern StagePoints D_800A5284;
extern StagePoints D_800A52AC;
extern StagePoints D_800A52D4;
extern StagePoints D_800A52FC;
extern StagePoints D_800A5324;
extern StagePoints D_800A534C;
extern StagePoints D_800A5374;
extern StagePoints D_800A539C;
extern StagePoints D_800A53C4;
extern StagePoints D_800A53EC;
extern StagePoints D_800A5414;
extern StagePoints D_800A543C;
extern StagePoints D_800A5464;
extern StagePoints D_800A548C;
extern StagePoints D_800A54B4;
extern StagePoints D_800A54DC;
extern StagePoints D_800A5504;
extern StagePoints D_800A552C;
extern StagePoints D_800A5554;
extern StagePoints D_800A557C;
extern StagePoints D_800A55A4;
extern StagePoints D_800A55CC;
extern StagePoints D_800A55F4;
extern StagePoints D_800A561C;
extern StagePoints D_800A5644;
extern StagePoints D_800A566C;
extern StagePoints D_800A5694;
extern StagePoints D_800A56BC;
extern StagePoints D_800A56E4;
extern StagePoints D_800A570C;
extern StagePoints D_800A5734;
extern StagePoints D_800A575C;
extern StagePoints D_800A5784;
extern StagePoints D_800A57AC;
extern StagePoints D_800A57D4;
extern StagePoints D_800A57FC;
extern StagePoints D_800A5824;
extern StagePoints D_800A584C;
extern StagePoints D_800A5874;
extern StagePoints D_800A589C;
extern StagePoints D_800A58C4;
extern StagePoints D_800A58EC;
extern StagePoints D_800A5914;
extern StagePoints D_800A593C;
extern Battle D_800A5A40;
extern Battle D_800A5A4C;
extern Battle D_800A5A58;
extern Battle D_800A5A64;
extern Battle D_800A5A70;
extern Battle D_800A5A7C;
extern Battle D_800A5A88;
extern Battle D_800A5A94;
extern Battle D_800A5AC4;
extern Battle D_800A5AD0;
extern Battle D_800A5ADC;
extern Battle D_800A5AE8;
extern Battle D_800A5AF4;
extern Battle D_800A5B00;
extern Battle D_800A5B0C;
extern Battle D_800A5B18;
extern Battle D_800A5B48;
extern Battle D_800A5B54;
extern Battle D_800A5B60;
extern Battle D_800A5B6C;
extern Battle D_800A5B78;
extern Battle D_800A5B84;
extern Battle D_800A5B90;
extern Battle D_800A5B9C;
extern Battle D_800A5BCC;
extern Battle D_800A5BD8;
extern Battle D_800A5BE4;
extern Battle D_800A5BF0;
extern Battle D_800A5BFC;
extern Battle D_800A5C08;
extern Battle D_800A5C14;
extern Battle D_800A5C20;
extern Battle D_800A5C50;
extern Battle D_800A5C5C;
extern Battle D_800A5C68;
extern Battle D_800A5C74;
extern Battle D_800A5C80;
extern Battle D_800A5C8C;
extern Battle D_800A5C98;
extern Battle D_800A5CA4;
extern Battle D_800A5CD4;
extern Battle D_800A5CE0;
extern Battle D_800A5CEC;
extern Battle D_800A5CF8;
extern Battle D_800A5D04;
extern Battle D_800A5D10;
extern Battle D_800A5D1C;
extern Battle D_800A5D28;
extern Battle D_800A5D58;
extern Battle D_800A5D64;
extern Battle D_800A5D70;
extern Battle D_800A5D7C;
extern Battle D_800A5D88;
extern Battle D_800A5D94;
extern Battle D_800A5DA0;
extern Battle D_800A5DAC;
extern Battle D_800A5DDC;
extern Battle D_800A5DE8;
extern Battle D_800A5DF4;
extern Battle D_800A5E00;
extern Battle D_800A5E0C;
extern Battle D_800A5E18;
extern Battle D_800A5E24;
extern Battle D_800A5E30;
extern Battle D_800A5E60;
extern Battle D_800A5E6C;
extern Battle D_800A5E78;
extern Battle D_800A5E84;
extern Battle D_800A5E90;
extern Battle D_800A5E9C;
extern Battle D_800A5EA8;
extern Battle D_800A5EB4;
extern Battle D_800A5EE4;
extern Battle D_800A5EF0;
extern Battle D_800A5EFC;
extern Battle D_800A5F08;
extern Battle D_800A5F14;
extern Battle D_800A5F20;
extern Battle D_800A5F2C;
extern Battle D_800A5F38;
extern Battle D_800A5F68;
extern Battle D_800A5F74;
extern Battle D_800A5F80;
extern Battle D_800A5F8C;
extern Battle D_800A5F98;
extern Battle D_800A5FA4;
extern Battle D_800A5FB0;
extern Battle D_800A5FBC;
extern Battle D_800A5FEC;
extern Battle D_800A5FF8;
extern Battle D_800A6004;
extern Battle D_800A6010;
extern Battle D_800A601C;
extern Battle D_800A6028;
extern Battle D_800A6034;
extern Battle D_800A6040;
extern Battle D_800A6070;
extern Battle D_800A607C;
extern Battle D_800A6088;
extern Battle D_800A6094;
extern Battle D_800A60A0;
extern Battle D_800A60AC;
extern Battle D_800A60B8;
extern Battle D_800A60C4;
extern Battle D_800A60F4;
extern Battle D_800A6100;
extern Battle D_800A610C;
extern Battle D_800A6118;
extern Battle D_800A6124;
extern Battle D_800A6130;
extern Battle D_800A613C;
extern Battle D_800A6148;
extern Battle D_800A6178;
extern Battle D_800A6184;
extern Battle D_800A6190;
extern Battle D_800A619C;
extern Battle D_800A61A8;
extern Battle D_800A61B4;
extern Battle D_800A61C0;
extern Battle D_800A61CC;
extern Battle D_800A61FC;
extern Battle D_800A6208;
extern Battle D_800A6214;
extern Battle D_800A6220;
extern Battle D_800A622C;
extern Battle D_800A6238;
extern Battle D_800A6244;
extern Battle D_800A6250;
extern Battle D_800A6280;
extern Battle D_800A628C;
extern Battle D_800A6298;
extern Battle D_800A62A4;
extern Battle D_800A62B0;
extern Battle D_800A62BC;
extern Battle D_800A62C8;
extern Battle D_800A62D4;
extern Battle D_800A6304;
extern Battle D_800A6310;
extern Battle D_800A631C;
extern Battle D_800A6328;
extern Battle D_800A6334;
extern Battle D_800A6340;
extern Battle D_800A634C;
extern Battle D_800A6358;
extern Battle D_800A6388;
extern Battle D_800A6394;
extern Battle D_800A63A0;
extern Battle D_800A63AC;
extern Battle D_800A63B8;
extern Battle D_800A63C4;
extern Battle D_800A63D0;
extern Battle D_800A63DC;
extern Battle D_800A640C;
extern Battle D_800A6418;
extern Battle D_800A6424;
extern Battle D_800A6430;
extern Battle D_800A643C;
extern Battle D_800A6448;
extern Battle D_800A6454;
extern Battle D_800A6460;
extern Battle D_800A6490;
extern Battle D_800A649C;
extern Battle D_800A64A8;
extern Battle D_800A64B4;
extern Battle D_800A64C0;
extern Battle D_800A64CC;
extern Battle D_800A64D8;
extern Battle D_800A64E4;
extern Battle D_800A6514;
extern Battle D_800A6520;
extern Battle D_800A652C;
extern Battle D_800A6538;
extern Battle D_800A6544;
extern Battle D_800A6550;
extern Battle D_800A655C;
extern Battle D_800A6568;
extern Battle D_800A6598;
extern Battle D_800A65A4;
extern Battle D_800A65B0;
extern Battle D_800A65BC;
extern Battle D_800A65C8;
extern Battle D_800A65D4;
extern Battle D_800A65E0;
extern Battle D_800A65EC;
extern Battle D_800A661C;
extern Battle D_800A6628;
extern Battle D_800A6634;
extern Battle D_800A6640;
extern Battle D_800A664C;
extern Battle D_800A6658;
extern Battle D_800A6664;
extern Battle D_800A6670;
extern Battle D_800A66A0;
extern Battle D_800A66AC;
extern Battle D_800A66B8;
extern Battle D_800A66C4;
extern Battle D_800A66D0;
extern Battle D_800A66DC;
extern Battle D_800A66E8;
extern Battle D_800A66F4;
extern Battle D_800A6724;
extern Battle D_800A6730;
extern Battle D_800A673C;
extern Battle D_800A6748;
extern Battle D_800A6754;
extern Battle D_800A6760;
extern Battle D_800A676C;
extern Battle D_800A6778;
extern Battle D_800A67A8;
extern Battle D_800A67B4;
extern Battle D_800A67C0;
extern Battle D_800A67CC;
extern Battle D_800A67D8;
extern Battle D_800A67E4;
extern Battle D_800A67F0;
extern Battle D_800A67FC;
extern Battle D_800A682C;
extern Battle D_800A6838;
extern Battle D_800A6844;
extern Battle D_800A6850;
extern Battle D_800A685C;
extern Battle D_800A6868;
extern Battle D_800A6874;
extern Battle D_800A6880;
extern Battle D_800A68B0;
extern Battle D_800A68BC;
extern Battle D_800A68C8;
extern Battle D_800A68D4;
extern Battle D_800A68E0;
extern Battle D_800A68EC;
extern Battle D_800A68F8;
extern Battle D_800A6904;
extern Battle D_800A6934;
extern Battle D_800A6940;
extern Battle D_800A694C;
extern Battle D_800A6958;
extern Battle D_800A6964;
extern Battle D_800A6970;
extern Battle D_800A697C;
extern Battle D_800A6988;
extern Battle D_800A69B8;
extern Battle D_800A69C4;
extern Battle D_800A69D0;
extern Battle D_800A69DC;
extern Battle D_800A69E8;
extern Battle D_800A69F4;
extern Battle D_800A6A00;
extern Battle D_800A6A0C;
extern Battle D_800A6A3C;
extern Battle D_800A6A48;
extern Battle D_800A6A54;
extern Battle D_800A6A60;
extern Battle D_800A6A6C;
extern Battle D_800A6A78;
extern Battle D_800A6A84;
extern Battle D_800A6A90;
extern Battle D_800A6AC0;
extern Battle D_800A6ACC;
extern Battle D_800A6AD8;
extern Battle D_800A6AE4;
extern Battle D_800A6AF0;
extern Battle D_800A6AFC;
extern Battle D_800A6B08;
extern Battle D_800A6B14;
extern Battle D_800A6B44;
extern Battle D_800A6B50;
extern Battle D_800A6B5C;
extern Battle D_800A6B68;
extern Battle D_800A6B74;
extern Battle D_800A6B80;
extern Battle D_800A6B8C;
extern Battle D_800A6B98;
extern Battle D_800A6BC8;
extern Battle D_800A6BD4;
extern Battle D_800A6BE0;
extern Battle D_800A6BEC;
extern Battle D_800A6BF8;
extern Battle D_800A6C04;
extern Battle D_800A6C10;
extern Battle D_800A6C1C;
extern Battle D_800A6C4C;
extern Battle D_800A6C58;
extern Battle D_800A6C64;
extern Battle D_800A6C70;
extern Battle D_800A6C7C;
extern Battle D_800A6C88;
extern Battle D_800A6C94;
extern Battle D_800A6CA0;
extern Battle D_800A6CD0;
extern Battle D_800A6CDC;
extern Battle D_800A6CE8;
extern Battle D_800A6CF4;
extern Battle D_800A6D00;
extern Battle D_800A6D0C;
extern Battle D_800A6D18;
extern Battle D_800A6D24;
extern Battle D_800A6D54;
extern Battle D_800A6D60;
extern Battle D_800A6D6C;
extern Battle D_800A6D78;
extern Battle D_800A6D84;
extern Battle D_800A6D90;
extern Battle D_800A6D9C;
extern Battle D_800A6DA8;
extern Battle D_800A6DD8;
extern Battle D_800A6DE4;
extern Battle D_800A6DF0;
extern Battle D_800A6DFC;
extern Battle D_800A6E08;
extern Battle D_800A6E14;
extern Battle D_800A6E20;
extern Battle D_800A6E2C;
extern Battle D_800A6E5C;
extern Battle D_800A6E68;
extern Battle D_800A6E74;
extern Battle D_800A6E80;
extern Battle D_800A6E8C;
extern Battle D_800A6E98;
extern Battle D_800A6EA4;
extern Battle D_800A6EB0;
extern Battle D_800A6EE0;
extern Battle D_800A6EEC;
extern Battle D_800A6EF8;
extern Battle D_800A6F04;
extern Battle D_800A6F10;
extern Battle D_800A6F1C;
extern Battle D_800A6F28;
extern Battle D_800A6F34;
extern Battle D_800A6F64;
extern Battle D_800A6F70;
extern Battle D_800A6F7C;
extern Battle D_800A6F88;
extern Battle D_800A6F94;
extern Battle D_800A6FA0;
extern Battle D_800A6FAC;
extern Battle D_800A6FB8;
extern Battle D_800A6FE8;
extern Battle D_800A6FF4;
extern Battle D_800A7000;
extern Battle D_800A700C;
extern Battle D_800A7018;
extern Battle D_800A7024;
extern Battle D_800A7030;
extern Battle D_800A703C;
extern Battle D_800A706C;
extern Battle D_800A7078;
extern Battle D_800A7084;
extern Battle D_800A7090;
extern Battle D_800A709C;
extern Battle D_800A70A8;
extern Battle D_800A70B4;
extern Battle D_800A70C0;
extern Battle D_800A70F0;
extern Battle D_800A70FC;
extern Battle D_800A7108;
extern Battle D_800A7114;
extern Battle D_800A7120;
extern Battle D_800A712C;
extern Battle D_800A7138;
extern Battle D_800A7144;
extern Battle D_800A7174;
extern Battle D_800A7180;
extern Battle D_800A718C;
extern Battle D_800A7198;
extern Battle D_800A71A4;
extern Battle D_800A71B0;
extern Battle D_800A71BC;
extern Battle D_800A71C8;
extern Battle D_800A71F8;
extern Battle D_800A7204;
extern Battle D_800A7210;
extern Battle D_800A721C;
extern Battle D_800A7228;
extern Battle D_800A7234;
extern Battle D_800A7240;
extern Battle D_800A724C;
extern Battle D_800A727C;
extern Battle D_800A7288;
extern Battle D_800A7294;
extern Battle D_800A72A0;
extern Battle D_800A72AC;
extern Battle D_800A72B8;
extern Battle D_800A72C4;
extern Battle D_800A72D0;
extern Battle D_800A7300;
extern Battle D_800A730C;
extern Battle D_800A7318;
extern Battle D_800A7324;
extern Battle D_800A7330;
extern Battle D_800A733C;
extern Battle D_800A7348;
extern Battle D_800A7354;
extern Battle D_800A7384;
extern Battle D_800A7390;
extern Battle D_800A739C;
extern Battle D_800A73A8;
extern Battle D_800A73B4;
extern Battle D_800A73C0;
extern Battle D_800A73CC;
extern Battle D_800A73D8;
extern Battle D_800A7408;
extern Battle D_800A7414;
extern Battle D_800A7420;
extern Battle D_800A742C;
extern Battle D_800A7438;
extern Battle D_800A7444;
extern Battle D_800A7450;
extern Battle D_800A745C;
extern Battle D_800A748C;
extern Battle D_800A7498;
extern Battle D_800A74A4;
extern Battle D_800A74B0;
extern Battle D_800A74BC;
extern Battle D_800A74C8;
extern Battle D_800A74D4;
extern Battle D_800A74E0;
extern Battle D_800A7510;
extern Battle D_800A751C;
extern Battle D_800A7528;
extern Battle D_800A7534;
extern Battle D_800A7540;
extern Battle D_800A754C;
extern Battle D_800A7558;
extern Battle D_800A7564;
extern Battle D_800A7594;
extern Battle D_800A75A0;
extern Battle D_800A75AC;
extern Battle D_800A75B8;
extern Battle D_800A75C4;
extern Battle D_800A75D0;
extern Battle D_800A75DC;
extern Battle D_800A75E8;
extern Battle D_800A7618;
extern Battle D_800A7624;
extern Battle D_800A7630;
extern Battle D_800A763C;
extern Battle D_800A7648;
extern Battle D_800A7654;
extern Battle D_800A7660;
extern Battle D_800A766C;
extern Battle D_800A769C;
extern Battle D_800A76A8;
extern Battle D_800A76B4;
extern Battle D_800A76C0;
extern Battle D_800A76CC;
extern Battle D_800A76D8;
extern Battle D_800A76E4;
extern Battle D_800A76F0;
extern Battle D_800A7720;
extern Battle D_800A772C;
extern Battle D_800A7738;
extern Battle D_800A7744;
extern Battle D_800A7750;
extern Battle D_800A775C;
extern Battle D_800A7768;
extern Battle D_800A7774;
extern Battle D_800A77A4;
extern Battle D_800A77B0;
extern Battle D_800A77BC;
extern Battle D_800A77C8;
extern Battle D_800A77D4;
extern Battle D_800A77E0;
extern Battle D_800A77EC;
extern Battle D_800A77F8;
extern Battle D_800A7828;
extern Battle D_800A7834;
extern Battle D_800A7840;
extern Battle D_800A784C;
extern Battle D_800A7858;
extern Battle D_800A7864;
extern Battle D_800A7870;
extern Battle D_800A787C;
extern Battle D_800A78AC;
extern Battle D_800A78B8;
extern Battle D_800A78C4;
extern Battle D_800A78D0;
extern Battle D_800A78DC;
extern Battle D_800A78E8;
extern Battle D_800A78F4;
extern Battle D_800A7900;
extern Battle D_800A7930;
extern Battle D_800A793C;
extern Battle D_800A7948;
extern Battle D_800A7954;
extern Battle D_800A7960;
extern Battle D_800A796C;
extern Battle D_800A7978;
extern Battle D_800A7984;
extern Battle D_800A79B4;
extern Battle D_800A79C0;
extern Battle D_800A79CC;
extern Battle D_800A79D8;
extern Battle D_800A79E4;
extern Battle D_800A79F0;
extern Battle D_800A79FC;
extern Battle D_800A7A08;
extern Battle D_800A7A38;
extern Battle D_800A7A44;
extern Battle D_800A7A50;
extern Battle D_800A7A5C;
extern Battle D_800A7A68;
extern Battle D_800A7A74;
extern Battle D_800A7A80;
extern Battle D_800A7A8C;
extern Battle D_800A7ABC;
extern Battle D_800A7AC8;
extern Battle D_800A7AD4;
extern Battle D_800A7AE0;
extern Battle D_800A7AEC;
extern Battle D_800A7AF8;
extern Battle D_800A7B04;
extern Battle D_800A7B10;
extern Battle D_800A7B40;
extern Battle D_800A7B4C;
extern Battle D_800A7B58;
extern Battle D_800A7B64;
extern Battle D_800A7B70;
extern Battle D_800A7B7C;
extern Battle D_800A7B88;
extern Battle D_800A7B94;
extern Battle D_800A7BC4;
extern Battle D_800A7BD0;
extern Battle D_800A7BDC;
extern Battle D_800A7BE8;
extern Battle D_800A7BF4;
extern Battle D_800A7C00;
extern Battle D_800A7C0C;
extern Battle D_800A7C18;
extern Battle D_800A7C48;
extern Battle D_800A7C54;
extern Battle D_800A7C60;
extern Battle D_800A7C6C;
extern Battle D_800A7C78;
extern Battle D_800A7C84;
extern Battle D_800A7C90;
extern Battle D_800A7C9C;
extern Battle D_800A7CCC;
extern Battle D_800A7CD8;
extern Battle D_800A7CE4;
extern Battle D_800A7CF0;
extern Battle D_800A7CFC;
extern Battle D_800A7D08;
extern Battle D_800A7D14;
extern Battle D_800A7D20;
extern Battle D_800A7D50;
extern Battle D_800A7D5C;
extern Battle D_800A7D68;
extern Battle D_800A7D74;
extern Battle D_800A7D80;
extern Battle D_800A7D8C;
extern Battle D_800A7D98;
extern Battle D_800A7DA4;
extern Battle D_800A7DD4;
extern Battle D_800A7DE0;
extern Battle D_800A7DEC;
extern Battle D_800A7DF8;
extern Battle D_800A7E04;
extern Battle D_800A7E10;
extern Battle D_800A7E1C;
extern Battle D_800A7E28;
extern Battle D_800A7E58;
extern Battle D_800A7E64;
extern Battle D_800A7E70;
extern Battle D_800A7E7C;
extern Battle D_800A7E88;
extern Battle D_800A7E94;
extern Battle D_800A7EA0;
extern Battle D_800A7EAC;
extern Battle D_800A7EDC;
extern Battle D_800A7EE8;
extern Battle D_800A7EF4;
extern Battle D_800A7F00;
extern Battle D_800A7F0C;
extern Battle D_800A7F18;
extern Battle D_800A7F24;
extern Battle D_800A7F30;
extern Battle D_800A7F60;
extern Battle D_800A7F6C;
extern Battle D_800A7F78;
extern Battle D_800A7F84;
extern Battle D_800A7F90;
extern Battle D_800A7F9C;
extern Battle D_800A7FA8;
extern Battle D_800A7FB4;
extern Battle D_800A7FE4;
extern Battle D_800A7FF0;
extern Battle D_800A7FFC;
extern Battle D_800A8008;
extern Battle D_800A8014;
extern Battle D_800A8020;
extern Battle D_800A802C;
extern Battle D_800A8038;
extern Battle D_800A8068;
extern Battle D_800A8074;
extern Battle D_800A8080;
extern Battle D_800A808C;
extern Battle D_800A8098;
extern Battle D_800A80A4;
extern Battle D_800A80B0;
extern Battle D_800A80BC;
extern Battle D_800A80EC;
extern Battle D_800A80F8;
extern Battle D_800A8104;
extern Battle D_800A8110;
extern Battle D_800A811C;
extern Battle D_800A8128;
extern Battle D_800A8134;
extern Battle D_800A8140;
extern Battle D_800A8170;
extern Battle D_800A817C;
extern Battle D_800A8188;
extern Battle D_800A8194;
extern Battle D_800A81A0;
extern Battle D_800A81AC;
extern Battle D_800A81B8;
extern Battle D_800A81C4;
extern Battle D_800A81F4;
extern Battle D_800A8200;
extern Battle D_800A820C;
extern Battle D_800A8218;
extern Battle D_800A8224;
extern Battle D_800A8230;
extern Battle D_800A823C;
extern Battle D_800A8248;
extern Battle D_800A8278;
extern Battle D_800A8284;
extern Battle D_800A8290;
extern Battle D_800A829C;
extern Battle D_800A82A8;
extern Battle D_800A82B4;
extern Battle D_800A82C0;
extern Battle D_800A82CC;
extern Battle D_800A82FC;
extern Battle D_800A8308;
extern Battle D_800A8314;
extern Battle D_800A8320;
extern Battle D_800A832C;
extern Battle D_800A8338;
extern Battle D_800A8344;
extern Battle D_800A8350;
extern Battle D_800A8380;
extern Battle D_800A838C;
extern Battle D_800A8398;
extern Battle D_800A83A4;
extern Battle D_800A83B0;
extern Battle D_800A83BC;
extern Battle D_800A83C8;
extern Battle D_800A83D4;
extern Battle D_800A8404;
extern Battle D_800A8410;
extern Battle D_800A841C;
extern Battle D_800A8428;
extern Battle D_800A8434;
extern Battle D_800A8440;
extern Battle D_800A844C;
extern Battle D_800A8458;
extern Battle D_800A8488;
extern Battle D_800A8494;
extern Battle D_800A84A0;
extern Battle D_800A84AC;
extern Battle D_800A84B8;
extern Battle D_800A84C4;
extern Battle D_800A84D0;
extern Battle D_800A84DC;
extern Battle D_800A850C;
extern Battle D_800A8518;
extern Battle D_800A8524;
extern Battle D_800A8530;
extern Battle D_800A853C;
extern Battle D_800A8548;
extern Battle D_800A8554;
extern Battle D_800A8560;
extern Battle D_800A8590;
extern Battle D_800A859C;
extern Battle D_800A85A8;
extern Battle D_800A85B4;
extern Battle D_800A85C0;
extern Battle D_800A85CC;
extern Battle D_800A85D8;
extern Battle D_800A85E4;
extern Battle D_800A8614;
extern Battle D_800A8620;
extern Battle D_800A862C;
extern Battle D_800A8638;
extern Battle D_800A8644;
extern Battle D_800A8650;
extern Battle D_800A865C;
extern Battle D_800A8668;
extern Battle D_800A8698;
extern Battle D_800A86A4;
extern Battle D_800A86B0;
extern Battle D_800A86BC;
extern Battle D_800A86C8;
extern Battle D_800A86D4;
extern Battle D_800A86E0;
extern Battle D_800A86EC;
extern Battle D_800A871C;
extern Battle D_800A8728;
extern Battle D_800A8734;
extern Battle D_800A8740;
extern Battle D_800A874C;
extern Battle D_800A8758;
extern Battle D_800A8764;
extern Battle D_800A8770;
extern BattleList D_800A5AA0;
extern BattleList D_800A5B24;
extern BattleList D_800A5BA8;
extern BattleList D_800A5C2C;
extern BattleList D_800A5CB0;
extern BattleList D_800A5D34;
extern BattleList D_800A5DB8;
extern BattleList D_800A5E3C;
extern BattleList D_800A5EC0;
extern BattleList D_800A5F44;
extern BattleList D_800A5FC8;
extern BattleList D_800A604C;
extern BattleList D_800A60D0;
extern BattleList D_800A6154;
extern BattleList D_800A61D8;
extern BattleList D_800A625C;
extern BattleList D_800A62E0;
extern BattleList D_800A6364;
extern BattleList D_800A63E8;
extern BattleList D_800A646C;
extern BattleList D_800A64F0;
extern BattleList D_800A6574;
extern BattleList D_800A65F8;
extern BattleList D_800A667C;
extern BattleList D_800A6700;
extern BattleList D_800A6784;
extern BattleList D_800A6808;
extern BattleList D_800A688C;
extern BattleList D_800A6910;
extern BattleList D_800A6994;
extern BattleList D_800A6A18;
extern BattleList D_800A6A9C;
extern BattleList D_800A6B20;
extern BattleList D_800A6BA4;
extern BattleList D_800A6C28;
extern BattleList D_800A6CAC;
extern BattleList D_800A6D30;
extern BattleList D_800A6DB4;
extern BattleList D_800A6E38;
extern BattleList D_800A6EBC;
extern BattleList D_800A6F40;
extern BattleList D_800A6FC4;
extern BattleList D_800A7048;
extern BattleList D_800A70CC;
extern BattleList D_800A7150;
extern BattleList D_800A71D4;
extern BattleList D_800A7258;
extern BattleList D_800A72DC;
extern BattleList D_800A7360;
extern BattleList D_800A73E4;
extern BattleList D_800A7468;
extern BattleList D_800A74EC;
extern BattleList D_800A7570;
extern BattleList D_800A75F4;
extern BattleList D_800A7678;
extern BattleList D_800A76FC;
extern BattleList D_800A7780;
extern BattleList D_800A7804;
extern BattleList D_800A7888;
extern BattleList D_800A790C;
extern BattleList D_800A7990;
extern BattleList D_800A7A14;
extern BattleList D_800A7A98;
extern BattleList D_800A7B1C;
extern BattleList D_800A7BA0;
extern BattleList D_800A7C24;
extern BattleList D_800A7CA8;
extern BattleList D_800A7D2C;
extern BattleList D_800A7DB0;
extern BattleList D_800A7E34;
extern BattleList D_800A7EB8;
extern BattleList D_800A7F3C;
extern BattleList D_800A7FC0;
extern BattleList D_800A8044;
extern BattleList D_800A80C8;
extern BattleList D_800A814C;
extern BattleList D_800A81D0;
extern BattleList D_800A8254;
extern BattleList D_800A82D8;
extern BattleList D_800A835C;
extern BattleList D_800A83E0;
extern BattleList D_800A8464;
extern BattleList D_800A84E8;
extern BattleList D_800A856C;
extern BattleList D_800A85F0;
extern BattleList D_800A8674;
extern BattleList D_800A86F8;
extern BattleList D_800A877C;
extern u16 D_800A8B08[];
extern u16 D_800A8B14[];
extern u16 D_800A8B1C[];
extern u16 D_800A8B28[];
extern u16 D_800A8B34[];
extern u16 D_800A8B3C[];
extern u16 D_800A8B48[];
extern u16 D_800A8B58[];
extern u16 D_800A8B64[];
extern u16 D_800A8B6C[];
extern u16 D_800A8B78[];
extern u16 D_800A8B84[];
extern u16 D_800A8B8C[];
extern u16 D_800A8B98[];
extern u16 D_800A8BA8[];
extern u16 D_800A8BB4[];
extern u16 D_800A8BBC[];
extern u16 D_800A8BC8[];
extern u16 D_800A8BD4[];
extern u16 D_800A8BDC[];
extern u16 D_800A8BE8[];
extern u16 D_800A8BF8[];
extern u16 D_800A8C04[];
extern u16 D_800A8C0C[];
extern u16 D_800A8C18[];
extern u16 D_800A8C24[];
extern u16 D_800A8C2C[];
extern u16 D_800A8C38[];
extern u16 D_800A8D98[];
extern FieldTalk D_800A8C48[];
extern u16 D_800A8DA4[];
extern FieldTalk D_800A8C60[];
extern u16 D_800A8DB0[];
extern FieldTalk D_800A8C78[];
extern u16 D_800A8DBC[];
extern FieldTalk D_800A8C90[];
extern u16 D_800A8DC8[];
extern u16 D_800A8DD4[];
extern FieldTalk D_800A8CA8[];
extern u16 D_800A8DE8[];
extern FieldTalk D_800A8CE4[];
extern u16 D_800A8DFC[];
extern FieldTalk D_800A8D20[];
extern u16 D_800A8E10[];
extern FieldTalk D_800A8D5C[];
extern u16 D_800A8E24[];
extern u16 D_800A8E30[];
extern u16 D_800A8E3C[];
extern u16 D_800A8E48[];
extern u16 D_800A8E54[];
extern u16 D_800A8E60[];
extern u16 D_800A8E6C[];
extern u16 D_800A8E78[];
extern u16 D_800A8E84[];
extern u16 D_800A8E90[];
extern u16 D_800A8E9C[];
extern u16 D_800A8EA8[];
extern u16 D_800A8EB4[];
extern u16 D_800A8EC0[];
extern FieldActorEntry D_800A8ECC;
extern FieldActorEntry D_800A8EE0;
extern FieldActorEntry D_800A8EF4;
extern FieldActorEntry D_800A8F08;
extern FieldActorEntry D_800A8F1C;
extern FieldActorEntry D_800A8F30;
extern FieldActorEntry D_800A8F44;
extern FieldActorEntry D_800A8F58;
extern FieldActorEntry D_800A8F6C;
extern FieldActorEntry D_800A8F80;
extern FieldActorEntry D_800A8F94;
extern FieldActorEntry D_800A8FA8;
extern FieldActorEntry D_800A8FBC;
extern FieldActorEntry D_800A8FD0;
extern FieldActorEntry D_800A8FE4;
extern FieldActorEntry D_800A8FF8;
extern FieldActorEntry D_800A900C;
extern FieldActorEntry D_800A9020;
extern FieldActorEntry D_800A9034;
extern FieldActorEntry D_800A9048;
extern FieldActorEntry D_800A905C;
extern FieldActorEntry D_800A9070;
extern FieldActorEntry D_800A9084;
extern FieldActorEntry D_800A9098;

StagePoint D_800A4F94 = { 0x2ED, 1, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A4FA4 = { 0x2E8, 1, 1, 176, 0x168, 5, &D_800A4F94 };
StagePoints D_800A4FB4 = { 1, 1, &D_800A4FA4 };
StagePoint D_800A4FBC = { 0x2EE, 2, 1, 0x130, 200, 1, NULL };
StagePoint D_800A4FCC = { 0x2E8, 2, 1, 176, 0x168, 5, &D_800A4FBC };
StagePoints D_800A4FDC = { 2, 1, &D_800A4FCC };
StagePoint D_800A4FE4 = { 0x2EE, 3, 1, 0x130, 200, 1, NULL };
StagePoint D_800A4FF4 = { 0x2E8, 3, 1, 176, 0x168, 5, &D_800A4FE4 };
StagePoints D_800A5004 = { 3, 1, &D_800A4FF4 };
StagePoint D_800A500C = { 0x2E9, 3, 1, 0x240, 240, 1, NULL };
StagePoint D_800A501C = { 0x2ED, 3, 2, 224, 192, 5, &D_800A500C };
StagePoints D_800A502C = { 3, 2, &D_800A501C };
StagePoint D_800A5034 = { 0x2E9, 5, 4, 0x240, 240, 1, NULL };
StagePoint D_800A5044 = { 0x2ED, 5, 4, 0x350, 0x1F8, 5, &D_800A5034 };
StagePoints D_800A5054 = { 5, 1, &D_800A5044 };
StagePoint D_800A505C = { 0x2EE, 6, 1, 0x130, 200, 1, NULL };
StagePoint D_800A506C = { 0x2EA, 6, 1, 224, 0x200, 5, &D_800A505C };
StagePoints D_800A507C = { 6, 1, &D_800A506C };
StagePoint D_800A5084 = { 0x2EE, 6, 3, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5094 = { 0x2ED, 6, 2, 0x350, 0x1F8, 5, &D_800A5084 };
StagePoints D_800A50A4 = { 6, 2, &D_800A5094 };
StagePoint D_800A50AC = { 0x2EE, 7, 1, 0x130, 200, 1, NULL };
StagePoint D_800A50BC = { 0x2E8, 7, 1, 176, 0x168, 5, &D_800A50AC };
StagePoints D_800A50CC = { 7, 1, &D_800A50BC };
StagePoint D_800A50D4 = { 0x2EE, 7, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A50E4 = { 0x2E8, 7, 2, 176, 0x168, 5, &D_800A50D4 };
StagePoints D_800A50F4 = { 7, 2, &D_800A50E4 };
StagePoint D_800A50FC = { 0x2EE, 7, 2, 0x130, 200, 1, NULL };
StagePoint D_800A510C = { 0x2EE, 7, 1, 224, 0x240, 5, &D_800A50FC };
StagePoints D_800A511C = { 7, 3, &D_800A510C };
StagePoint D_800A5124 = { 0x2ED, 8, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A5134 = { 0x2E8, 8, 2, 176, 0x168, 5, &D_800A5124 };
StagePoints D_800A5144 = { 8, 1, &D_800A5134 };
StagePoint D_800A514C = { 0x2EE, 9, 1, 0x130, 200, 1, NULL };
StagePoint D_800A515C = { 0x2E8, 9, 1, 176, 0x168, 5, &D_800A514C };
StagePoints D_800A516C = { 9, 1, &D_800A515C };
StagePoint D_800A5174 = { 0x2EE, 10, 1, 0x130, 200, 1, NULL };
StagePoint D_800A5184 = { 0x2E8, 10, 1, 176, 0x168, 5, &D_800A5174 };
StagePoints D_800A5194 = { 10, 1, &D_800A5184 };
StagePoint D_800A519C = { 0x2E9, 10, 2, 0x240, 240, 1, NULL };
StagePoint D_800A51AC = { 0x2ED, 10, 1, 0x350, 0x1F8, 5, &D_800A519C };
StagePoints D_800A51BC = { 10, 2, &D_800A51AC };
StagePoint D_800A51C4 = { 0x2EE, 11, 1, 0x130, 200, 1, NULL };
StagePoint D_800A51D4 = { 0x2E8, 11, 1, 176, 0x168, 5, &D_800A51C4 };
StagePoints D_800A51E4 = { 11, 1, &D_800A51D4 };
StagePoint D_800A51EC = { 0x2E9, 11, 2, 0x240, 240, 1, NULL };
StagePoint D_800A51FC = { 0x2ED, 11, 1, 0x350, 0x1F8, 5, &D_800A51EC };
StagePoints D_800A520C = { 11, 2, &D_800A51FC };
StagePoint D_800A5214 = { 0x2ED, 12, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A5224 = { 0x2EA, 12, 1, 224, 0x200, 5, &D_800A5214 };
StagePoints D_800A5234 = { 12, 1, &D_800A5224 };
StagePoint D_800A523C = { 0x2EE, 12, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A524C = { 0x2EA, 12, 2, 224, 0x200, 5, &D_800A523C };
StagePoints D_800A525C = { 12, 2, &D_800A524C };
StagePoint D_800A5264 = { 0x2EB, 12, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5274 = { 0x2ED, 12, 1, 224, 192, 5, &D_800A5264 };
StagePoints D_800A5284 = { 12, 3, &D_800A5274 };
StagePoint D_800A528C = { 0x2EB, 12, 2, 0x240, 160, 1, NULL };
StagePoint D_800A529C = { 0x2EE, 12, 1, 224, 0x240, 5, &D_800A528C };
StagePoints D_800A52AC = { 12, 4, &D_800A529C };
StagePoint D_800A52B4 = { 0x2E9, 12, 1, 0x240, 240, 1, NULL };
StagePoint D_800A52C4 = { 0x2EE, 12, 2, 224, 0x240, 5, &D_800A52B4 };
StagePoints D_800A52D4 = { 12, 5, &D_800A52C4 };
StagePoint D_800A52DC = { 0x2ED, 13, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A52EC = { 0x2EA, 13, 1, 224, 0x200, 5, &D_800A52DC };
StagePoints D_800A52FC = { 13, 1, &D_800A52EC };
StagePoint D_800A5304 = { 0x2EE, 13, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5314 = { 0x2E8, 13, 1, 176, 0x168, 5, &D_800A5304 };
StagePoints D_800A5324 = { 13, 2, &D_800A5314 };
StagePoint D_800A532C = { 0x2EC, 13, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A533C = { 0x2ED, 13, 1, 224, 192, 5, &D_800A532C };
StagePoints D_800A534C = { 13, 3, &D_800A533C };
StagePoint D_800A5354 = { 0x2E9, 13, 1, 0x240, 240, 1, NULL };
StagePoint D_800A5364 = { 0x2EC, 13, 3, 240, 0x1D8, 5, &D_800A5354 };
StagePoints D_800A5374 = { 13, 4, &D_800A5364 };
StagePoint D_800A537C = { 0x2EB, 13, 1, 0x240, 160, 1, NULL };
StagePoint D_800A538C = { 0x2EE, 13, 1, 224, 0x240, 5, &D_800A537C };
StagePoints D_800A539C = { 13, 5, &D_800A538C };
StagePoint D_800A53A4 = { 0x2EB, 13, 2, 0x240, 160, 1, NULL };
StagePoint D_800A53B4 = { 0x2EE, 13, 2, 224, 0x240, 5, &D_800A53A4 };
StagePoints D_800A53C4 = { 13, 6, &D_800A53B4 };
StagePoint D_800A53CC = { 0x2EB, 18, 1, 0x240, 160, 1, NULL };
StagePoint D_800A53DC = { 0x2E8, 18, 1, 176, 0x168, 5, &D_800A53CC };
StagePoints D_800A53EC = { 18, 1, &D_800A53DC };
StagePoint D_800A53F4 = { 0x2EE, 19, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5404 = { 0x2EA, 19, 1, 224, 0x200, 5, &D_800A53F4 };
StagePoints D_800A5414 = { 19, 1, &D_800A5404 };
StagePoint D_800A541C = { 0x2EE, 19, 2, 0x130, 200, 1, NULL };
StagePoint D_800A542C = { 0x2E8, 19, 1, 176, 0x168, 5, &D_800A541C };
StagePoints D_800A543C = { 19, 2, &D_800A542C };
StagePoint D_800A5444 = { 0x2EE, 19, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5454 = { 0x2EE, 19, 1, 224, 0x240, 5, &D_800A5444 };
StagePoints D_800A5464 = { 19, 3, &D_800A5454 };
StagePoint D_800A546C = { 0x2ED, 19, 3, 0x3A0, 128, 1, NULL };
StagePoint D_800A547C = { 0x2ED, 19, 1, 224, 192, 5, &D_800A546C };
StagePoints D_800A548C = { 19, 4, &D_800A547C };
StagePoint D_800A5494 = { 0x2EB, 19, 4, 0x240, 160, 1, NULL };
StagePoint D_800A54A4 = { 0x2ED, 19, 3, 0x350, 0x1F8, 5, &D_800A5494 };
StagePoints D_800A54B4 = { 19, 5, &D_800A54A4 };
StagePoint D_800A54BC = { 0x2EE, 20, 2, 0x130, 200, 1, NULL };
StagePoint D_800A54CC = { 0x2EA, 20, 2, 224, 0x200, 5, &D_800A54BC };
StagePoints D_800A54DC = { 20, 1, &D_800A54CC };
StagePoint D_800A54E4 = { 0x2EE, 20, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A54F4 = { 0x2EE, 20, 1, 224, 0x240, 5, &D_800A54E4 };
StagePoints D_800A5504 = { 20, 2, &D_800A54F4 };
StagePoint D_800A550C = { 0x2ED, 20, 3, 0x3A0, 128, 1, NULL };
StagePoint D_800A551C = { 0x2ED, 20, 1, 224, 192, 5, &D_800A550C };
StagePoints D_800A552C = { 20, 3, &D_800A551C };
StagePoint D_800A5534 = { 0x2ED, 20, 4, 0x3A0, 128, 1, NULL };
StagePoint D_800A5544 = { 0x2ED, 20, 2, 0x350, 0x1F8, 5, &D_800A5534 };
StagePoints D_800A5554 = { 20, 4, &D_800A5544 };
StagePoint D_800A555C = { 0x2ED, 20, 5, 0x3A0, 128, 1, NULL };
StagePoint D_800A556C = { 0x2ED, 20, 3, 0x350, 0x1F8, 5, &D_800A555C };
StagePoints D_800A557C = { 20, 5, &D_800A556C };
StagePoint D_800A5584 = { 0x2EB, 20, 4, 0x240, 160, 1, NULL };
StagePoint D_800A5594 = { 0x2ED, 20, 4, 0x350, 0x1F8, 5, &D_800A5584 };
StagePoints D_800A55A4 = { 20, 6, &D_800A5594 };
StagePoint D_800A55AC = { 0x2ED, 20, 6, 0x3A0, 128, 1, NULL };
StagePoint D_800A55BC = { 0x2ED, 20, 5, 224, 192, 5, &D_800A55AC };
StagePoints D_800A55CC = { 20, 7, &D_800A55BC };
StagePoint D_800A55D4 = { 0x2EB, 20, 5, 0x240, 160, 1, NULL };
StagePoint D_800A55E4 = { 0x2ED, 20, 5, 0x350, 0x1F8, 5, &D_800A55D4 };
StagePoints D_800A55F4 = { 20, 8, &D_800A55E4 };
StagePoint D_800A55FC = { 0x2EB, 20, 6, 0x240, 160, 1, NULL };
StagePoint D_800A560C = { 0x2ED, 20, 6, 224, 192, 5, &D_800A55FC };
StagePoints D_800A561C = { 20, 9, &D_800A560C };
StagePoint D_800A5624 = { 0x2EC, 21, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A5634 = { 0x2EA, 21, 1, 224, 0x200, 5, &D_800A5624 };
StagePoints D_800A5644 = { 21, 1, &D_800A5634 };
StagePoint D_800A564C = { 0x2EE, 21, 1, 0x130, 200, 1, NULL };
StagePoint D_800A565C = { 0x2EC, 21, 1, 240, 0x1D8, 5, &D_800A564C };
StagePoints D_800A566C = { 21, 2, &D_800A565C };
StagePoint D_800A5674 = { 0x2EE, 22, 1, 0x130, 200, 1, NULL };
StagePoint D_800A5684 = { 0x2E8, 22, 1, 176, 0x168, 5, &D_800A5674 };
StagePoints D_800A5694 = { 22, 1, &D_800A5684 };
StagePoint D_800A569C = { 0x2EE, 22, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A56AC = { 0x2E8, 22, 2, 176, 0x168, 5, &D_800A569C };
StagePoints D_800A56BC = { 22, 2, &D_800A56AC };
StagePoint D_800A56C4 = { 0x2EB, 22, 1, 0x240, 160, 1, NULL };
StagePoint D_800A56D4 = { 0x2EE, 22, 1, 224, 0x240, 5, &D_800A56C4 };
StagePoints D_800A56E4 = { 22, 3, &D_800A56D4 };
StagePoint D_800A56EC = { 0x2EC, 23, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A56FC = { 0x2E8, 23, 1, 176, 0x168, 5, &D_800A56EC };
StagePoints D_800A570C = { 23, 1, &D_800A56FC };
StagePoint D_800A5714 = { 0x2EC, 23, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A5724 = { 0x2EC, 23, 1, 240, 0x1D8, 5, &D_800A5714 };
StagePoints D_800A5734 = { 23, 2, &D_800A5724 };
StagePoint D_800A573C = { 0x2EE, 23, 1, 0x130, 200, 1, NULL };
StagePoint D_800A574C = { 0x2EC, 23, 2, 240, 0x1D8, 5, &D_800A573C };
StagePoints D_800A575C = { 23, 3, &D_800A574C };
StagePoint D_800A5764 = { 0x2EC, 24, 2, 0x3B0, 120, 1, NULL };
StagePoint D_800A5774 = { 0x2E8, 24, 1, 176, 0x168, 5, &D_800A5764 };
StagePoints D_800A5784 = { 24, 1, &D_800A5774 };
StagePoint D_800A578C = { 0x2EC, 24, 3, 0x3B0, 120, 1, NULL };
StagePoint D_800A579C = { 0x2EC, 24, 1, 240, 0x1D8, 5, &D_800A578C };
StagePoints D_800A57AC = { 24, 2, &D_800A579C };
StagePoint D_800A57B4 = { 0x2EC, 24, 4, 0x3B0, 120, 1, NULL };
StagePoint D_800A57C4 = { 0x2EC, 24, 2, 240, 0x1D8, 5, &D_800A57B4 };
StagePoints D_800A57D4 = { 24, 3, &D_800A57C4 };
StagePoint D_800A57DC = { 0x2EC, 24, 5, 0x3B0, 120, 1, NULL };
StagePoint D_800A57EC = { 0x2EC, 24, 3, 240, 0x1D8, 5, &D_800A57DC };
StagePoints D_800A57FC = { 24, 4, &D_800A57EC };
StagePoint D_800A5804 = { 0x2EB, 24, 1, 0x240, 160, 1, NULL };
StagePoint D_800A5814 = { 0x2EC, 24, 4, 240, 0x1D8, 5, &D_800A5804 };
StagePoints D_800A5824 = { 24, 5, &D_800A5814 };
StagePoint D_800A582C = { 0x2ED, 28, 2, 0x3A0, 128, 1, NULL };
StagePoint D_800A583C = { 0x2EA, 28, 1, 224, 0x200, 5, &D_800A582C };
StagePoints D_800A584C = { 28, 1, &D_800A583C };
StagePoint D_800A5854 = { 0x2EE, 28, 2, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5864 = { 0x2EA, 28, 2, 224, 0x200, 5, &D_800A5854 };
StagePoints D_800A5874 = { 28, 2, &D_800A5864 };
StagePoint D_800A587C = { 0x2EB, 28, 1, 0x240, 160, 1, NULL };
StagePoint D_800A588C = { 0x2ED, 28, 1, 224, 192, 5, &D_800A587C };
StagePoints D_800A589C = { 28, 3, &D_800A588C };
StagePoint D_800A58A4 = { 0x2EB, 28, 2, 0x240, 160, 1, NULL };
StagePoint D_800A58B4 = { 0x2EE, 28, 1, 224, 0x240, 5, &D_800A58A4 };
StagePoints D_800A58C4 = { 28, 4, &D_800A58B4 };
StagePoint D_800A58CC = { 0x2EE, 29, 1, 0x130, 200, 1, NULL };
StagePoint D_800A58DC = { 0x2E8, 29, 1, 176, 0x168, 5, &D_800A58CC };
StagePoints D_800A58EC = { 29, 1, &D_800A58DC };
StagePoint D_800A58F4 = { 0x2EE, 29, 1, 0x3A0, 0x1A0, 1, NULL };
StagePoint D_800A5904 = { 0x2EA, 29, 1, 224, 0x200, 5, &D_800A58F4 };
StagePoints D_800A5914 = { 29, 2, &D_800A5904 };
StagePoint D_800A591C = { 0x2EB, 30, 1, 0x240, 160, 1, NULL };
StagePoint D_800A592C = { 0x2ED, 30, 1, 224, 192, 5, &D_800A591C };
StagePoints D_800A593C = { 30, 1, &D_800A592C };
StagePoints *placePoints[] = {
    &D_800A4FB4, &D_800A4FDC, &D_800A5004, &D_800A502C,
    &D_800A5054, &D_800A507C, &D_800A50A4, &D_800A50CC,
    &D_800A50F4, &D_800A511C, &D_800A5144, &D_800A516C,
    &D_800A5194, &D_800A51BC, &D_800A51E4, &D_800A520C,
    &D_800A5234, &D_800A525C, &D_800A5284, &D_800A52AC,
    &D_800A52D4, &D_800A52FC, &D_800A5324, &D_800A534C,
    &D_800A5374, &D_800A539C, &D_800A53C4, &D_800A53EC,
    &D_800A5414, &D_800A543C, &D_800A5464, &D_800A548C,
    &D_800A54B4, &D_800A54DC, &D_800A5504, &D_800A552C,
    &D_800A5554, &D_800A557C, &D_800A55A4, &D_800A55CC,
    &D_800A55F4, &D_800A561C, &D_800A5644, &D_800A566C,
    &D_800A5694, &D_800A56BC, &D_800A56E4, &D_800A570C,
    &D_800A5734, &D_800A575C, &D_800A5784, &D_800A57AC,
    &D_800A57D4, &D_800A57FC, &D_800A5824, &D_800A584C,
    &D_800A5874, &D_800A589C, &D_800A58C4, &D_800A58EC,
    &D_800A5914, &D_800A593C, NULL,
};
Battle D_800A5A40 = { 174, 10, 0x60080000 };
Battle D_800A5A4C = { 174, 10, 0x60080000 };
Battle D_800A5A58 = { 170, 10, 0x60080000 };
Battle D_800A5A64 = { 170, 10, 0x60080000 };
Battle D_800A5A70 = { 170, 10, 0x60080000 };
Battle D_800A5A7C = { 170, 10, 0x60080000 };
Battle D_800A5A88 = { 170, 10, 0x60080000 };
Battle D_800A5A94 = { 170, 10, 0x60080000 };
BattleList D_800A5AA0 = {
    1,
    { &D_800A5A40, &D_800A5A4C, &D_800A5A58, &D_800A5A64,
      &D_800A5A70, &D_800A5A7C, &D_800A5A88, &D_800A5A94 },
};
Battle D_800A5AC4 = { 0, 0, 0x60040000 };
Battle D_800A5AD0 = { 0, 0, 0x60040000 };
Battle D_800A5ADC = { 0, 0, 0x60040000 };
Battle D_800A5AE8 = { 0, 0, 0x60040000 };
Battle D_800A5AF4 = { 0, 0, 0x60040000 };
Battle D_800A5B00 = { 0, 0, 0x60040000 };
Battle D_800A5B0C = { 0, 0, 0x60040000 };
Battle D_800A5B18 = { 0, 0, 0x60040000 };
BattleList D_800A5B24 = {
    0,
    { &D_800A5AC4, &D_800A5AD0, &D_800A5ADC, &D_800A5AE8,
      &D_800A5AF4, &D_800A5B00, &D_800A5B0C, &D_800A5B18 },
};
Battle D_800A5B48 = { 0, 0, 0x60040000 };
Battle D_800A5B54 = { 0, 0, 0x60040000 };
Battle D_800A5B60 = { 0, 0, 0x60040000 };
Battle D_800A5B6C = { 0, 0, 0x60040000 };
Battle D_800A5B78 = { 0, 0, 0x60040000 };
Battle D_800A5B84 = { 0, 0, 0x60040000 };
Battle D_800A5B90 = { 0, 0, 0x60040000 };
Battle D_800A5B9C = { 0, 0, 0x60040000 };
BattleList D_800A5BA8 = {
    0,
    { &D_800A5B48, &D_800A5B54, &D_800A5B60, &D_800A5B6C,
      &D_800A5B78, &D_800A5B84, &D_800A5B90, &D_800A5B9C },
};
Battle D_800A5BCC = { 0, 0, 0x60040000 };
Battle D_800A5BD8 = { 0, 0, 0x60040000 };
Battle D_800A5BE4 = { 0, 0, 0x60040000 };
Battle D_800A5BF0 = { 0, 0, 0x60040000 };
Battle D_800A5BFC = { 0, 0, 0x60040000 };
Battle D_800A5C08 = { 0, 0, 0x60040000 };
Battle D_800A5C14 = { 0, 0, 0x60040000 };
Battle D_800A5C20 = { 0, 0, 0x60040000 };
BattleList D_800A5C2C = {
    0,
    { &D_800A5BCC, &D_800A5BD8, &D_800A5BE4, &D_800A5BF0,
      &D_800A5BFC, &D_800A5C08, &D_800A5C14, &D_800A5C20 },
};
Battle D_800A5C50 = { 174, 10, 0x60080000 };
Battle D_800A5C5C = { 174, 10, 0x60080000 };
Battle D_800A5C68 = { 170, 10, 0x60080000 };
Battle D_800A5C74 = { 170, 10, 0x60080000 };
Battle D_800A5C80 = { 170, 10, 0x60080000 };
Battle D_800A5C8C = { 110, 10, 0x60080000 };
Battle D_800A5C98 = { 110, 10, 0x60080000 };
Battle D_800A5CA4 = { 110, 10, 0x60080000 };
BattleList D_800A5CB0 = {
    1,
    { &D_800A5C50, &D_800A5C5C, &D_800A5C68, &D_800A5C74,
      &D_800A5C80, &D_800A5C8C, &D_800A5C98, &D_800A5CA4 },
};
Battle D_800A5CD4 = { 0, 0, 0x60040000 };
Battle D_800A5CE0 = { 0, 0, 0x60040000 };
Battle D_800A5CEC = { 0, 0, 0x60040000 };
Battle D_800A5CF8 = { 0, 0, 0x60040000 };
Battle D_800A5D04 = { 0, 0, 0x60040000 };
Battle D_800A5D10 = { 0, 0, 0x60040000 };
Battle D_800A5D1C = { 0, 0, 0x60040000 };
Battle D_800A5D28 = { 0, 0, 0x60040000 };
BattleList D_800A5D34 = {
    0,
    { &D_800A5CD4, &D_800A5CE0, &D_800A5CEC, &D_800A5CF8,
      &D_800A5D04, &D_800A5D10, &D_800A5D1C, &D_800A5D28 },
};
Battle D_800A5D58 = { 0, 0, 0x60040000 };
Battle D_800A5D64 = { 0, 0, 0x60040000 };
Battle D_800A5D70 = { 0, 0, 0x60040000 };
Battle D_800A5D7C = { 0, 0, 0x60040000 };
Battle D_800A5D88 = { 0, 0, 0x60040000 };
Battle D_800A5D94 = { 0, 0, 0x60040000 };
Battle D_800A5DA0 = { 0, 0, 0x60040000 };
Battle D_800A5DAC = { 0, 0, 0x60040000 };
BattleList D_800A5DB8 = {
    0,
    { &D_800A5D58, &D_800A5D64, &D_800A5D70, &D_800A5D7C,
      &D_800A5D88, &D_800A5D94, &D_800A5DA0, &D_800A5DAC },
};
Battle D_800A5DDC = { 0, 0, 0x60040000 };
Battle D_800A5DE8 = { 0, 0, 0x60040000 };
Battle D_800A5DF4 = { 0, 0, 0x60040000 };
Battle D_800A5E00 = { 0, 0, 0x60040000 };
Battle D_800A5E0C = { 0, 0, 0x60040000 };
Battle D_800A5E18 = { 0, 0, 0x60040000 };
Battle D_800A5E24 = { 0, 0, 0x60040000 };
Battle D_800A5E30 = { 0, 0, 0x60040000 };
BattleList D_800A5E3C = {
    0,
    { &D_800A5DDC, &D_800A5DE8, &D_800A5DF4, &D_800A5E00,
      &D_800A5E0C, &D_800A5E18, &D_800A5E24, &D_800A5E30 },
};
Battle D_800A5E60 = { 174, 10, 0x60080000 };
Battle D_800A5E6C = { 174, 10, 0x60080000 };
Battle D_800A5E78 = { 170, 10, 0x60080000 };
Battle D_800A5E84 = { 170, 10, 0x60080000 };
Battle D_800A5E90 = { 182, 10, 0x60080000 };
Battle D_800A5E9C = { 182, 10, 0x60080000 };
Battle D_800A5EA8 = { 71, 10, 0x60080000 };
Battle D_800A5EB4 = { 71, 10, 0x60080000 };
BattleList D_800A5EC0 = {
    1,
    { &D_800A5E60, &D_800A5E6C, &D_800A5E78, &D_800A5E84,
      &D_800A5E90, &D_800A5E9C, &D_800A5EA8, &D_800A5EB4 },
};
Battle D_800A5EE4 = { 0, 0, 0x60040000 };
Battle D_800A5EF0 = { 0, 0, 0x60040000 };
Battle D_800A5EFC = { 0, 0, 0x60040000 };
Battle D_800A5F08 = { 0, 0, 0x60040000 };
Battle D_800A5F14 = { 0, 0, 0x60040000 };
Battle D_800A5F20 = { 0, 0, 0x60040000 };
Battle D_800A5F2C = { 0, 0, 0x60040000 };
Battle D_800A5F38 = { 0, 0, 0x60040000 };
BattleList D_800A5F44 = {
    0,
    { &D_800A5EE4, &D_800A5EF0, &D_800A5EFC, &D_800A5F08,
      &D_800A5F14, &D_800A5F20, &D_800A5F2C, &D_800A5F38 },
};
Battle D_800A5F68 = { 0, 0, 0x60040000 };
Battle D_800A5F74 = { 0, 0, 0x60040000 };
Battle D_800A5F80 = { 0, 0, 0x60040000 };
Battle D_800A5F8C = { 0, 0, 0x60040000 };
Battle D_800A5F98 = { 0, 0, 0x60040000 };
Battle D_800A5FA4 = { 0, 0, 0x60040000 };
Battle D_800A5FB0 = { 0, 0, 0x60040000 };
Battle D_800A5FBC = { 0, 0, 0x60040000 };
BattleList D_800A5FC8 = {
    0,
    { &D_800A5F68, &D_800A5F74, &D_800A5F80, &D_800A5F8C,
      &D_800A5F98, &D_800A5FA4, &D_800A5FB0, &D_800A5FBC },
};
Battle D_800A5FEC = { 0, 0, 0x60040000 };
Battle D_800A5FF8 = { 0, 0, 0x60040000 };
Battle D_800A6004 = { 0, 0, 0x60040000 };
Battle D_800A6010 = { 0, 0, 0x60040000 };
Battle D_800A601C = { 0, 0, 0x60040000 };
Battle D_800A6028 = { 0, 0, 0x60040000 };
Battle D_800A6034 = { 0, 0, 0x60040000 };
Battle D_800A6040 = { 0, 0, 0x60040000 };
BattleList D_800A604C = {
    0,
    { &D_800A5FEC, &D_800A5FF8, &D_800A6004, &D_800A6010,
      &D_800A601C, &D_800A6028, &D_800A6034, &D_800A6040 },
};
Battle D_800A6070 = { 174, 10, 0x60080000 };
Battle D_800A607C = { 170, 10, 0x60080000 };
Battle D_800A6088 = { 110, 10, 0x60080000 };
Battle D_800A6094 = { 110, 10, 0x60080000 };
Battle D_800A60A0 = { 182, 10, 0x60080000 };
Battle D_800A60AC = { 182, 10, 0x60080000 };
Battle D_800A60B8 = { 71, 10, 0x60080000 };
Battle D_800A60C4 = { 71, 10, 0x60080000 };
BattleList D_800A60D0 = {
    1,
    { &D_800A6070, &D_800A607C, &D_800A6088, &D_800A6094,
      &D_800A60A0, &D_800A60AC, &D_800A60B8, &D_800A60C4 },
};
Battle D_800A60F4 = { 0, 0, 0x60040000 };
Battle D_800A6100 = { 0, 0, 0x60040000 };
Battle D_800A610C = { 0, 0, 0x60040000 };
Battle D_800A6118 = { 0, 0, 0x60040000 };
Battle D_800A6124 = { 0, 0, 0x60040000 };
Battle D_800A6130 = { 0, 0, 0x60040000 };
Battle D_800A613C = { 0, 0, 0x60040000 };
Battle D_800A6148 = { 0, 0, 0x60040000 };
BattleList D_800A6154 = {
    0,
    { &D_800A60F4, &D_800A6100, &D_800A610C, &D_800A6118,
      &D_800A6124, &D_800A6130, &D_800A613C, &D_800A6148 },
};
Battle D_800A6178 = { 0, 0, 0x60040000 };
Battle D_800A6184 = { 0, 0, 0x60040000 };
Battle D_800A6190 = { 0, 0, 0x60040000 };
Battle D_800A619C = { 0, 0, 0x60040000 };
Battle D_800A61A8 = { 0, 0, 0x60040000 };
Battle D_800A61B4 = { 0, 0, 0x60040000 };
Battle D_800A61C0 = { 0, 0, 0x60040000 };
Battle D_800A61CC = { 0, 0, 0x60040000 };
BattleList D_800A61D8 = {
    0,
    { &D_800A6178, &D_800A6184, &D_800A6190, &D_800A619C,
      &D_800A61A8, &D_800A61B4, &D_800A61C0, &D_800A61CC },
};
Battle D_800A61FC = { 0, 0, 0x60040000 };
Battle D_800A6208 = { 0, 0, 0x60040000 };
Battle D_800A6214 = { 0, 0, 0x60040000 };
Battle D_800A6220 = { 0, 0, 0x60040000 };
Battle D_800A622C = { 0, 0, 0x60040000 };
Battle D_800A6238 = { 0, 0, 0x60040000 };
Battle D_800A6244 = { 0, 0, 0x60040000 };
Battle D_800A6250 = { 0, 0, 0x60040000 };
BattleList D_800A625C = {
    0,
    { &D_800A61FC, &D_800A6208, &D_800A6214, &D_800A6220,
      &D_800A622C, &D_800A6238, &D_800A6244, &D_800A6250 },
};
Battle D_800A6280 = { 174, 10, 0x60080000 };
Battle D_800A628C = { 170, 10, 0x60080000 };
Battle D_800A6298 = { 110, 10, 0x60080000 };
Battle D_800A62A4 = { 110, 10, 0x60080000 };
Battle D_800A62B0 = { 182, 10, 0x60080000 };
Battle D_800A62BC = { 182, 10, 0x60080000 };
Battle D_800A62C8 = { 71, 10, 0x60080000 };
Battle D_800A62D4 = { 71, 10, 0x60080000 };
BattleList D_800A62E0 = {
    1,
    { &D_800A6280, &D_800A628C, &D_800A6298, &D_800A62A4,
      &D_800A62B0, &D_800A62BC, &D_800A62C8, &D_800A62D4 },
};
Battle D_800A6304 = { 0, 0, 0x60040000 };
Battle D_800A6310 = { 0, 0, 0x60040000 };
Battle D_800A631C = { 0, 0, 0x60040000 };
Battle D_800A6328 = { 0, 0, 0x60040000 };
Battle D_800A6334 = { 0, 0, 0x60040000 };
Battle D_800A6340 = { 0, 0, 0x60040000 };
Battle D_800A634C = { 0, 0, 0x60040000 };
Battle D_800A6358 = { 0, 0, 0x60040000 };
BattleList D_800A6364 = {
    0,
    { &D_800A6304, &D_800A6310, &D_800A631C, &D_800A6328,
      &D_800A6334, &D_800A6340, &D_800A634C, &D_800A6358 },
};
Battle D_800A6388 = { 0, 0, 0x60040000 };
Battle D_800A6394 = { 0, 0, 0x60040000 };
Battle D_800A63A0 = { 0, 0, 0x60040000 };
Battle D_800A63AC = { 0, 0, 0x60040000 };
Battle D_800A63B8 = { 0, 0, 0x60040000 };
Battle D_800A63C4 = { 0, 0, 0x60040000 };
Battle D_800A63D0 = { 0, 0, 0x60040000 };
Battle D_800A63DC = { 0, 0, 0x60040000 };
BattleList D_800A63E8 = {
    0,
    { &D_800A6388, &D_800A6394, &D_800A63A0, &D_800A63AC,
      &D_800A63B8, &D_800A63C4, &D_800A63D0, &D_800A63DC },
};
Battle D_800A640C = { 0, 0, 0x60040000 };
Battle D_800A6418 = { 0, 0, 0x60040000 };
Battle D_800A6424 = { 0, 0, 0x60040000 };
Battle D_800A6430 = { 0, 0, 0x60040000 };
Battle D_800A643C = { 0, 0, 0x60040000 };
Battle D_800A6448 = { 0, 0, 0x60040000 };
Battle D_800A6454 = { 0, 0, 0x60040000 };
Battle D_800A6460 = { 0, 0, 0x60040000 };
BattleList D_800A646C = {
    0,
    { &D_800A640C, &D_800A6418, &D_800A6424, &D_800A6430,
      &D_800A643C, &D_800A6448, &D_800A6454, &D_800A6460 },
};
Battle D_800A6490 = { 110, 10, 0x60080000 };
Battle D_800A649C = { 110, 10, 0x60080000 };
Battle D_800A64A8 = { 110, 10, 0x60080000 };
Battle D_800A64B4 = { 110, 10, 0x60080000 };
Battle D_800A64C0 = { 182, 10, 0x60080000 };
Battle D_800A64CC = { 182, 10, 0x60080000 };
Battle D_800A64D8 = { 182, 10, 0x60080000 };
Battle D_800A64E4 = { 182, 10, 0x60080000 };
BattleList D_800A64F0 = {
    1,
    { &D_800A6490, &D_800A649C, &D_800A64A8, &D_800A64B4,
      &D_800A64C0, &D_800A64CC, &D_800A64D8, &D_800A64E4 },
};
Battle D_800A6514 = { 0, 0, 0x60040000 };
Battle D_800A6520 = { 0, 0, 0x60040000 };
Battle D_800A652C = { 0, 0, 0x60040000 };
Battle D_800A6538 = { 0, 0, 0x60040000 };
Battle D_800A6544 = { 0, 0, 0x60040000 };
Battle D_800A6550 = { 0, 0, 0x60040000 };
Battle D_800A655C = { 0, 0, 0x60040000 };
Battle D_800A6568 = { 0, 0, 0x60040000 };
BattleList D_800A6574 = {
    0,
    { &D_800A6514, &D_800A6520, &D_800A652C, &D_800A6538,
      &D_800A6544, &D_800A6550, &D_800A655C, &D_800A6568 },
};
Battle D_800A6598 = { 0, 0, 0x60040000 };
Battle D_800A65A4 = { 0, 0, 0x60040000 };
Battle D_800A65B0 = { 0, 0, 0x60040000 };
Battle D_800A65BC = { 0, 0, 0x60040000 };
Battle D_800A65C8 = { 0, 0, 0x60040000 };
Battle D_800A65D4 = { 0, 0, 0x60040000 };
Battle D_800A65E0 = { 0, 0, 0x60040000 };
Battle D_800A65EC = { 0, 0, 0x60040000 };
BattleList D_800A65F8 = {
    0,
    { &D_800A6598, &D_800A65A4, &D_800A65B0, &D_800A65BC,
      &D_800A65C8, &D_800A65D4, &D_800A65E0, &D_800A65EC },
};
Battle D_800A661C = { 0, 0, 0x60040000 };
Battle D_800A6628 = { 0, 0, 0x60040000 };
Battle D_800A6634 = { 0, 0, 0x60040000 };
Battle D_800A6640 = { 0, 0, 0x60040000 };
Battle D_800A664C = { 0, 0, 0x60040000 };
Battle D_800A6658 = { 0, 0, 0x60040000 };
Battle D_800A6664 = { 0, 0, 0x60040000 };
Battle D_800A6670 = { 0, 0, 0x60040000 };
BattleList D_800A667C = {
    0,
    { &D_800A661C, &D_800A6628, &D_800A6634, &D_800A6640,
      &D_800A664C, &D_800A6658, &D_800A6664, &D_800A6670 },
};
Battle D_800A66A0 = { 182, 10, 0x60080000 };
Battle D_800A66AC = { 182, 10, 0x60080000 };
Battle D_800A66B8 = { 182, 10, 0x60080000 };
Battle D_800A66C4 = { 182, 10, 0x60080000 };
Battle D_800A66D0 = { 71, 10, 0x60080000 };
Battle D_800A66DC = { 71, 10, 0x60080000 };
Battle D_800A66E8 = { 71, 10, 0x60080000 };
Battle D_800A66F4 = { 71, 10, 0x60080000 };
BattleList D_800A6700 = {
    1,
    { &D_800A66A0, &D_800A66AC, &D_800A66B8, &D_800A66C4,
      &D_800A66D0, &D_800A66DC, &D_800A66E8, &D_800A66F4 },
};
Battle D_800A6724 = { 0, 0, 0x60040000 };
Battle D_800A6730 = { 0, 0, 0x60040000 };
Battle D_800A673C = { 0, 0, 0x60040000 };
Battle D_800A6748 = { 0, 0, 0x60040000 };
Battle D_800A6754 = { 0, 0, 0x60040000 };
Battle D_800A6760 = { 0, 0, 0x60040000 };
Battle D_800A676C = { 0, 0, 0x60040000 };
Battle D_800A6778 = { 0, 0, 0x60040000 };
BattleList D_800A6784 = {
    0,
    { &D_800A6724, &D_800A6730, &D_800A673C, &D_800A6748,
      &D_800A6754, &D_800A6760, &D_800A676C, &D_800A6778 },
};
Battle D_800A67A8 = { 0, 0, 0x60040000 };
Battle D_800A67B4 = { 0, 0, 0x60040000 };
Battle D_800A67C0 = { 0, 0, 0x60040000 };
Battle D_800A67CC = { 0, 0, 0x60040000 };
Battle D_800A67D8 = { 0, 0, 0x60040000 };
Battle D_800A67E4 = { 0, 0, 0x60040000 };
Battle D_800A67F0 = { 0, 0, 0x60040000 };
Battle D_800A67FC = { 0, 0, 0x60040000 };
BattleList D_800A6808 = {
    0,
    { &D_800A67A8, &D_800A67B4, &D_800A67C0, &D_800A67CC,
      &D_800A67D8, &D_800A67E4, &D_800A67F0, &D_800A67FC },
};
Battle D_800A682C = { 0, 0, 0x60040000 };
Battle D_800A6838 = { 0, 0, 0x60040000 };
Battle D_800A6844 = { 0, 0, 0x60040000 };
Battle D_800A6850 = { 0, 0, 0x60040000 };
Battle D_800A685C = { 0, 0, 0x60040000 };
Battle D_800A6868 = { 0, 0, 0x60040000 };
Battle D_800A6874 = { 0, 0, 0x60040000 };
Battle D_800A6880 = { 0, 0, 0x60040000 };
BattleList D_800A688C = {
    0,
    { &D_800A682C, &D_800A6838, &D_800A6844, &D_800A6850,
      &D_800A685C, &D_800A6868, &D_800A6874, &D_800A6880 },
};
Battle D_800A68B0 = { 182, 10, 0x60080000 };
Battle D_800A68BC = { 182, 10, 0x60080000 };
Battle D_800A68C8 = { 182, 10, 0x60080000 };
Battle D_800A68D4 = { 182, 10, 0x60080000 };
Battle D_800A68E0 = { 71, 10, 0x60080000 };
Battle D_800A68EC = { 71, 10, 0x60080000 };
Battle D_800A68F8 = { 71, 10, 0x60080000 };
Battle D_800A6904 = { 71, 10, 0x60080000 };
BattleList D_800A6910 = {
    1,
    { &D_800A68B0, &D_800A68BC, &D_800A68C8, &D_800A68D4,
      &D_800A68E0, &D_800A68EC, &D_800A68F8, &D_800A6904 },
};
Battle D_800A6934 = { 0, 0, 0x60040000 };
Battle D_800A6940 = { 0, 0, 0x60040000 };
Battle D_800A694C = { 0, 0, 0x60040000 };
Battle D_800A6958 = { 0, 0, 0x60040000 };
Battle D_800A6964 = { 0, 0, 0x60040000 };
Battle D_800A6970 = { 0, 0, 0x60040000 };
Battle D_800A697C = { 0, 0, 0x60040000 };
Battle D_800A6988 = { 0, 0, 0x60040000 };
BattleList D_800A6994 = {
    0,
    { &D_800A6934, &D_800A6940, &D_800A694C, &D_800A6958,
      &D_800A6964, &D_800A6970, &D_800A697C, &D_800A6988 },
};
Battle D_800A69B8 = { 0, 0, 0x60040000 };
Battle D_800A69C4 = { 0, 0, 0x60040000 };
Battle D_800A69D0 = { 0, 0, 0x60040000 };
Battle D_800A69DC = { 0, 0, 0x60040000 };
Battle D_800A69E8 = { 0, 0, 0x60040000 };
Battle D_800A69F4 = { 0, 0, 0x60040000 };
Battle D_800A6A00 = { 0, 0, 0x60040000 };
Battle D_800A6A0C = { 0, 0, 0x60040000 };
BattleList D_800A6A18 = {
    0,
    { &D_800A69B8, &D_800A69C4, &D_800A69D0, &D_800A69DC,
      &D_800A69E8, &D_800A69F4, &D_800A6A00, &D_800A6A0C },
};
Battle D_800A6A3C = { 0, 0, 0x60040000 };
Battle D_800A6A48 = { 0, 0, 0x60040000 };
Battle D_800A6A54 = { 0, 0, 0x60040000 };
Battle D_800A6A60 = { 0, 0, 0x60040000 };
Battle D_800A6A6C = { 0, 0, 0x60040000 };
Battle D_800A6A78 = { 0, 0, 0x60040000 };
Battle D_800A6A84 = { 0, 0, 0x60040000 };
Battle D_800A6A90 = { 0, 0, 0x60040000 };
BattleList D_800A6A9C = {
    0,
    { &D_800A6A3C, &D_800A6A48, &D_800A6A54, &D_800A6A60,
      &D_800A6A6C, &D_800A6A78, &D_800A6A84, &D_800A6A90 },
};
Battle D_800A6AC0 = { 174, 10, 0x60080000 };
Battle D_800A6ACC = { 174, 10, 0x60080000 };
Battle D_800A6AD8 = { 170, 10, 0x60080000 };
Battle D_800A6AE4 = { 170, 10, 0x60080000 };
Battle D_800A6AF0 = { 170, 10, 0x60080000 };
Battle D_800A6AFC = { 110, 10, 0x60080000 };
Battle D_800A6B08 = { 110, 10, 0x60080000 };
Battle D_800A6B14 = { 110, 10, 0x60080000 };
BattleList D_800A6B20 = {
    2,
    { &D_800A6AC0, &D_800A6ACC, &D_800A6AD8, &D_800A6AE4,
      &D_800A6AF0, &D_800A6AFC, &D_800A6B08, &D_800A6B14 },
};
Battle D_800A6B44 = { 0, 0, 0x60040000 };
Battle D_800A6B50 = { 0, 0, 0x60040000 };
Battle D_800A6B5C = { 0, 0, 0x60040000 };
Battle D_800A6B68 = { 0, 0, 0x60040000 };
Battle D_800A6B74 = { 0, 0, 0x60040000 };
Battle D_800A6B80 = { 0, 0, 0x60040000 };
Battle D_800A6B8C = { 0, 0, 0x60040000 };
Battle D_800A6B98 = { 0, 0, 0x60040000 };
BattleList D_800A6BA4 = {
    0,
    { &D_800A6B44, &D_800A6B50, &D_800A6B5C, &D_800A6B68,
      &D_800A6B74, &D_800A6B80, &D_800A6B8C, &D_800A6B98 },
};
Battle D_800A6BC8 = { 0, 0, 0x60040000 };
Battle D_800A6BD4 = { 0, 0, 0x60040000 };
Battle D_800A6BE0 = { 0, 0, 0x60040000 };
Battle D_800A6BEC = { 0, 0, 0x60040000 };
Battle D_800A6BF8 = { 0, 0, 0x60040000 };
Battle D_800A6C04 = { 0, 0, 0x60040000 };
Battle D_800A6C10 = { 0, 0, 0x60040000 };
Battle D_800A6C1C = { 0, 0, 0x60040000 };
BattleList D_800A6C28 = {
    0,
    { &D_800A6BC8, &D_800A6BD4, &D_800A6BE0, &D_800A6BEC,
      &D_800A6BF8, &D_800A6C04, &D_800A6C10, &D_800A6C1C },
};
Battle D_800A6C4C = { 0, 0, 0x60040000 };
Battle D_800A6C58 = { 0, 0, 0x60040000 };
Battle D_800A6C64 = { 0, 0, 0x60040000 };
Battle D_800A6C70 = { 0, 0, 0x60040000 };
Battle D_800A6C7C = { 0, 0, 0x60040000 };
Battle D_800A6C88 = { 0, 0, 0x60040000 };
Battle D_800A6C94 = { 0, 0, 0x60040000 };
Battle D_800A6CA0 = { 0, 0, 0x60040000 };
BattleList D_800A6CAC = {
    0,
    { &D_800A6C4C, &D_800A6C58, &D_800A6C64, &D_800A6C70,
      &D_800A6C7C, &D_800A6C88, &D_800A6C94, &D_800A6CA0 },
};
Battle D_800A6CD0 = { 182, 10, 0x60080000 };
Battle D_800A6CDC = { 182, 10, 0x60080000 };
Battle D_800A6CE8 = { 182, 10, 0x60080000 };
Battle D_800A6CF4 = { 182, 10, 0x60080000 };
Battle D_800A6D00 = { 71, 10, 0x60080000 };
Battle D_800A6D0C = { 71, 10, 0x60080000 };
Battle D_800A6D18 = { 71, 10, 0x60080000 };
Battle D_800A6D24 = { 71, 10, 0x60080000 };
BattleList D_800A6D30 = {
    2,
    { &D_800A6CD0, &D_800A6CDC, &D_800A6CE8, &D_800A6CF4,
      &D_800A6D00, &D_800A6D0C, &D_800A6D18, &D_800A6D24 },
};
Battle D_800A6D54 = { 0, 0, 0x60040000 };
Battle D_800A6D60 = { 0, 0, 0x60040000 };
Battle D_800A6D6C = { 0, 0, 0x60040000 };
Battle D_800A6D78 = { 0, 0, 0x60040000 };
Battle D_800A6D84 = { 0, 0, 0x60040000 };
Battle D_800A6D90 = { 0, 0, 0x60040000 };
Battle D_800A6D9C = { 0, 0, 0x60040000 };
Battle D_800A6DA8 = { 0, 0, 0x60040000 };
BattleList D_800A6DB4 = {
    0,
    { &D_800A6D54, &D_800A6D60, &D_800A6D6C, &D_800A6D78,
      &D_800A6D84, &D_800A6D90, &D_800A6D9C, &D_800A6DA8 },
};
Battle D_800A6DD8 = { 0, 0, 0x60040000 };
Battle D_800A6DE4 = { 0, 0, 0x60040000 };
Battle D_800A6DF0 = { 0, 0, 0x60040000 };
Battle D_800A6DFC = { 0, 0, 0x60040000 };
Battle D_800A6E08 = { 0, 0, 0x60040000 };
Battle D_800A6E14 = { 0, 0, 0x60040000 };
Battle D_800A6E20 = { 0, 0, 0x60040000 };
Battle D_800A6E2C = { 0, 0, 0x60040000 };
BattleList D_800A6E38 = {
    0,
    { &D_800A6DD8, &D_800A6DE4, &D_800A6DF0, &D_800A6DFC,
      &D_800A6E08, &D_800A6E14, &D_800A6E20, &D_800A6E2C },
};
Battle D_800A6E5C = { 0, 0, 0x60040000 };
Battle D_800A6E68 = { 0, 0, 0x60040000 };
Battle D_800A6E74 = { 0, 0, 0x60040000 };
Battle D_800A6E80 = { 0, 0, 0x60040000 };
Battle D_800A6E8C = { 0, 0, 0x60040000 };
Battle D_800A6E98 = { 0, 0, 0x60040000 };
Battle D_800A6EA4 = { 0, 0, 0x60040000 };
Battle D_800A6EB0 = { 0, 0, 0x60040000 };
BattleList D_800A6EBC = {
    0,
    { &D_800A6E5C, &D_800A6E68, &D_800A6E74, &D_800A6E80,
      &D_800A6E8C, &D_800A6E98, &D_800A6EA4, &D_800A6EB0 },
};
Battle D_800A6EE0 = { 110, 10, 0x60080000 };
Battle D_800A6EEC = { 110, 10, 0x60080000 };
Battle D_800A6EF8 = { 110, 10, 0x60080000 };
Battle D_800A6F04 = { 110, 10, 0x60080000 };
Battle D_800A6F10 = { 110, 10, 0x60080000 };
Battle D_800A6F1C = { 110, 10, 0x60080000 };
Battle D_800A6F28 = { 110, 10, 0x60080000 };
Battle D_800A6F34 = { 110, 10, 0x60080000 };
BattleList D_800A6F40 = {
    1,
    { &D_800A6EE0, &D_800A6EEC, &D_800A6EF8, &D_800A6F04,
      &D_800A6F10, &D_800A6F1C, &D_800A6F28, &D_800A6F34 },
};
Battle D_800A6F64 = { 0, 0, 0x60040000 };
Battle D_800A6F70 = { 0, 0, 0x60040000 };
Battle D_800A6F7C = { 0, 0, 0x60040000 };
Battle D_800A6F88 = { 0, 0, 0x60040000 };
Battle D_800A6F94 = { 0, 0, 0x60040000 };
Battle D_800A6FA0 = { 0, 0, 0x60040000 };
Battle D_800A6FAC = { 0, 0, 0x60040000 };
Battle D_800A6FB8 = { 0, 0, 0x60040000 };
BattleList D_800A6FC4 = {
    0,
    { &D_800A6F64, &D_800A6F70, &D_800A6F7C, &D_800A6F88,
      &D_800A6F94, &D_800A6FA0, &D_800A6FAC, &D_800A6FB8 },
};
Battle D_800A6FE8 = { 0, 0, 0x60040000 };
Battle D_800A6FF4 = { 0, 0, 0x60040000 };
Battle D_800A7000 = { 0, 0, 0x60040000 };
Battle D_800A700C = { 0, 0, 0x60040000 };
Battle D_800A7018 = { 0, 0, 0x60040000 };
Battle D_800A7024 = { 0, 0, 0x60040000 };
Battle D_800A7030 = { 0, 0, 0x60040000 };
Battle D_800A703C = { 0, 0, 0x60040000 };
BattleList D_800A7048 = {
    0,
    { &D_800A6FE8, &D_800A6FF4, &D_800A7000, &D_800A700C,
      &D_800A7018, &D_800A7024, &D_800A7030, &D_800A703C },
};
Battle D_800A706C = { 0, 0, 0x60040000 };
Battle D_800A7078 = { 0, 0, 0x60040000 };
Battle D_800A7084 = { 0, 0, 0x60040000 };
Battle D_800A7090 = { 0, 0, 0x60040000 };
Battle D_800A709C = { 0, 0, 0x60040000 };
Battle D_800A70A8 = { 0, 0, 0x60040000 };
Battle D_800A70B4 = { 0, 0, 0x60040000 };
Battle D_800A70C0 = { 0, 0, 0x60040000 };
BattleList D_800A70CC = {
    0,
    { &D_800A706C, &D_800A7078, &D_800A7084, &D_800A7090,
      &D_800A709C, &D_800A70A8, &D_800A70B4, &D_800A70C0 },
};
Battle D_800A70F0 = { 182, 10, 0x60080000 };
Battle D_800A70FC = { 182, 10, 0x60080000 };
Battle D_800A7108 = { 182, 10, 0x60080000 };
Battle D_800A7114 = { 182, 10, 0x60080000 };
Battle D_800A7120 = { 71, 10, 0x60080000 };
Battle D_800A712C = { 71, 10, 0x60080000 };
Battle D_800A7138 = { 71, 10, 0x60080000 };
Battle D_800A7144 = { 71, 10, 0x60080000 };
BattleList D_800A7150 = {
    1,
    { &D_800A70F0, &D_800A70FC, &D_800A7108, &D_800A7114,
      &D_800A7120, &D_800A712C, &D_800A7138, &D_800A7144 },
};
Battle D_800A7174 = { 0, 0, 0x60040000 };
Battle D_800A7180 = { 0, 0, 0x60040000 };
Battle D_800A718C = { 0, 0, 0x60040000 };
Battle D_800A7198 = { 0, 0, 0x60040000 };
Battle D_800A71A4 = { 0, 0, 0x60040000 };
Battle D_800A71B0 = { 0, 0, 0x60040000 };
Battle D_800A71BC = { 0, 0, 0x60040000 };
Battle D_800A71C8 = { 0, 0, 0x60040000 };
BattleList D_800A71D4 = {
    0,
    { &D_800A7174, &D_800A7180, &D_800A718C, &D_800A7198,
      &D_800A71A4, &D_800A71B0, &D_800A71BC, &D_800A71C8 },
};
Battle D_800A71F8 = { 0, 0, 0x60040000 };
Battle D_800A7204 = { 0, 0, 0x60040000 };
Battle D_800A7210 = { 0, 0, 0x60040000 };
Battle D_800A721C = { 0, 0, 0x60040000 };
Battle D_800A7228 = { 0, 0, 0x60040000 };
Battle D_800A7234 = { 0, 0, 0x60040000 };
Battle D_800A7240 = { 0, 0, 0x60040000 };
Battle D_800A724C = { 0, 0, 0x60040000 };
BattleList D_800A7258 = {
    0,
    { &D_800A71F8, &D_800A7204, &D_800A7210, &D_800A721C,
      &D_800A7228, &D_800A7234, &D_800A7240, &D_800A724C },
};
Battle D_800A727C = { 0, 0, 0x60040000 };
Battle D_800A7288 = { 0, 0, 0x60040000 };
Battle D_800A7294 = { 0, 0, 0x60040000 };
Battle D_800A72A0 = { 0, 0, 0x60040000 };
Battle D_800A72AC = { 0, 0, 0x60040000 };
Battle D_800A72B8 = { 0, 0, 0x60040000 };
Battle D_800A72C4 = { 0, 0, 0x60040000 };
Battle D_800A72D0 = { 0, 0, 0x60040000 };
BattleList D_800A72DC = {
    0,
    { &D_800A727C, &D_800A7288, &D_800A7294, &D_800A72A0,
      &D_800A72AC, &D_800A72B8, &D_800A72C4, &D_800A72D0 },
};
Battle D_800A7300 = { 182, 10, 0x60080000 };
Battle D_800A730C = { 182, 10, 0x60080000 };
Battle D_800A7318 = { 182, 10, 0x60080000 };
Battle D_800A7324 = { 182, 10, 0x60080000 };
Battle D_800A7330 = { 71, 10, 0x60080000 };
Battle D_800A733C = { 71, 10, 0x60080000 };
Battle D_800A7348 = { 71, 10, 0x60080000 };
Battle D_800A7354 = { 71, 10, 0x60080000 };
BattleList D_800A7360 = {
    5,
    { &D_800A7300, &D_800A730C, &D_800A7318, &D_800A7324,
      &D_800A7330, &D_800A733C, &D_800A7348, &D_800A7354 },
};
Battle D_800A7384 = { 0, 0, 0x60040000 };
Battle D_800A7390 = { 0, 0, 0x60040000 };
Battle D_800A739C = { 0, 0, 0x60040000 };
Battle D_800A73A8 = { 0, 0, 0x60040000 };
Battle D_800A73B4 = { 0, 0, 0x60040000 };
Battle D_800A73C0 = { 0, 0, 0x60040000 };
Battle D_800A73CC = { 0, 0, 0x60040000 };
Battle D_800A73D8 = { 0, 0, 0x60040000 };
BattleList D_800A73E4 = {
    0,
    { &D_800A7384, &D_800A7390, &D_800A739C, &D_800A73A8,
      &D_800A73B4, &D_800A73C0, &D_800A73CC, &D_800A73D8 },
};
Battle D_800A7408 = { 0, 0, 0x60040000 };
Battle D_800A7414 = { 0, 0, 0x60040000 };
Battle D_800A7420 = { 0, 0, 0x60040000 };
Battle D_800A742C = { 0, 0, 0x60040000 };
Battle D_800A7438 = { 0, 0, 0x60040000 };
Battle D_800A7444 = { 0, 0, 0x60040000 };
Battle D_800A7450 = { 0, 0, 0x60040000 };
Battle D_800A745C = { 0, 0, 0x60040000 };
BattleList D_800A7468 = {
    0,
    { &D_800A7408, &D_800A7414, &D_800A7420, &D_800A742C,
      &D_800A7438, &D_800A7444, &D_800A7450, &D_800A745C },
};
Battle D_800A748C = { 0, 0, 0x60040000 };
Battle D_800A7498 = { 0, 0, 0x60040000 };
Battle D_800A74A4 = { 0, 0, 0x60040000 };
Battle D_800A74B0 = { 0, 0, 0x60040000 };
Battle D_800A74BC = { 0, 0, 0x60040000 };
Battle D_800A74C8 = { 0, 0, 0x60040000 };
Battle D_800A74D4 = { 0, 0, 0x60040000 };
Battle D_800A74E0 = { 0, 0, 0x60040000 };
BattleList D_800A74EC = {
    0,
    { &D_800A748C, &D_800A7498, &D_800A74A4, &D_800A74B0,
      &D_800A74BC, &D_800A74C8, &D_800A74D4, &D_800A74E0 },
};
Battle D_800A7510 = { 110, 10, 0x60080000 };
Battle D_800A751C = { 110, 10, 0x60080000 };
Battle D_800A7528 = { 110, 10, 0x60080000 };
Battle D_800A7534 = { 110, 10, 0x60080000 };
Battle D_800A7540 = { 110, 10, 0x60080000 };
Battle D_800A754C = { 110, 10, 0x60080000 };
Battle D_800A7558 = { 110, 10, 0x60080000 };
Battle D_800A7564 = { 110, 10, 0x60080000 };
BattleList D_800A7570 = {
    1,
    { &D_800A7510, &D_800A751C, &D_800A7528, &D_800A7534,
      &D_800A7540, &D_800A754C, &D_800A7558, &D_800A7564 },
};
Battle D_800A7594 = { 0, 0, 0x60040000 };
Battle D_800A75A0 = { 0, 0, 0x60040000 };
Battle D_800A75AC = { 0, 0, 0x60040000 };
Battle D_800A75B8 = { 0, 0, 0x60040000 };
Battle D_800A75C4 = { 0, 0, 0x60040000 };
Battle D_800A75D0 = { 0, 0, 0x60040000 };
Battle D_800A75DC = { 0, 0, 0x60040000 };
Battle D_800A75E8 = { 0, 0, 0x60040000 };
BattleList D_800A75F4 = {
    0,
    { &D_800A7594, &D_800A75A0, &D_800A75AC, &D_800A75B8,
      &D_800A75C4, &D_800A75D0, &D_800A75DC, &D_800A75E8 },
};
Battle D_800A7618 = { 0, 0, 0x60040000 };
Battle D_800A7624 = { 0, 0, 0x60040000 };
Battle D_800A7630 = { 0, 0, 0x60040000 };
Battle D_800A763C = { 0, 0, 0x60040000 };
Battle D_800A7648 = { 0, 0, 0x60040000 };
Battle D_800A7654 = { 0, 0, 0x60040000 };
Battle D_800A7660 = { 0, 0, 0x60040000 };
Battle D_800A766C = { 0, 0, 0x60040000 };
BattleList D_800A7678 = {
    0,
    { &D_800A7618, &D_800A7624, &D_800A7630, &D_800A763C,
      &D_800A7648, &D_800A7654, &D_800A7660, &D_800A766C },
};
Battle D_800A769C = { 0, 0, 0x60040000 };
Battle D_800A76A8 = { 0, 0, 0x60040000 };
Battle D_800A76B4 = { 0, 0, 0x60040000 };
Battle D_800A76C0 = { 0, 0, 0x60040000 };
Battle D_800A76CC = { 0, 0, 0x60040000 };
Battle D_800A76D8 = { 0, 0, 0x60040000 };
Battle D_800A76E4 = { 0, 0, 0x60040000 };
Battle D_800A76F0 = { 0, 0, 0x60040000 };
BattleList D_800A76FC = {
    0,
    { &D_800A769C, &D_800A76A8, &D_800A76B4, &D_800A76C0,
      &D_800A76CC, &D_800A76D8, &D_800A76E4, &D_800A76F0 },
};
Battle D_800A7720 = { 182, 10, 0x60080000 };
Battle D_800A772C = { 182, 10, 0x60080000 };
Battle D_800A7738 = { 182, 10, 0x60080000 };
Battle D_800A7744 = { 182, 10, 0x60080000 };
Battle D_800A7750 = { 71, 10, 0x60080000 };
Battle D_800A775C = { 71, 10, 0x60080000 };
Battle D_800A7768 = { 71, 10, 0x60080000 };
Battle D_800A7774 = { 71, 10, 0x60080000 };
BattleList D_800A7780 = {
    1,
    { &D_800A7720, &D_800A772C, &D_800A7738, &D_800A7744,
      &D_800A7750, &D_800A775C, &D_800A7768, &D_800A7774 },
};
Battle D_800A77A4 = { 0, 0, 0x60040000 };
Battle D_800A77B0 = { 0, 0, 0x60040000 };
Battle D_800A77BC = { 0, 0, 0x60040000 };
Battle D_800A77C8 = { 0, 0, 0x60040000 };
Battle D_800A77D4 = { 0, 0, 0x60040000 };
Battle D_800A77E0 = { 0, 0, 0x60040000 };
Battle D_800A77EC = { 0, 0, 0x60040000 };
Battle D_800A77F8 = { 0, 0, 0x60040000 };
BattleList D_800A7804 = {
    0,
    { &D_800A77A4, &D_800A77B0, &D_800A77BC, &D_800A77C8,
      &D_800A77D4, &D_800A77E0, &D_800A77EC, &D_800A77F8 },
};
Battle D_800A7828 = { 0, 0, 0x60040000 };
Battle D_800A7834 = { 0, 0, 0x60040000 };
Battle D_800A7840 = { 0, 0, 0x60040000 };
Battle D_800A784C = { 0, 0, 0x60040000 };
Battle D_800A7858 = { 0, 0, 0x60040000 };
Battle D_800A7864 = { 0, 0, 0x60040000 };
Battle D_800A7870 = { 0, 0, 0x60040000 };
Battle D_800A787C = { 0, 0, 0x60040000 };
BattleList D_800A7888 = {
    0,
    { &D_800A7828, &D_800A7834, &D_800A7840, &D_800A784C,
      &D_800A7858, &D_800A7864, &D_800A7870, &D_800A787C },
};
Battle D_800A78AC = { 0, 0, 0x60040000 };
Battle D_800A78B8 = { 0, 0, 0x60040000 };
Battle D_800A78C4 = { 0, 0, 0x60040000 };
Battle D_800A78D0 = { 0, 0, 0x60040000 };
Battle D_800A78DC = { 0, 0, 0x60040000 };
Battle D_800A78E8 = { 0, 0, 0x60040000 };
Battle D_800A78F4 = { 0, 0, 0x60040000 };
Battle D_800A7900 = { 0, 0, 0x60040000 };
BattleList D_800A790C = {
    0,
    { &D_800A78AC, &D_800A78B8, &D_800A78C4, &D_800A78D0,
      &D_800A78DC, &D_800A78E8, &D_800A78F4, &D_800A7900 },
};
Battle D_800A7930 = { 110, 10, 0x60080000 };
Battle D_800A793C = { 110, 10, 0x60080000 };
Battle D_800A7948 = { 110, 10, 0x60080000 };
Battle D_800A7954 = { 110, 10, 0x60080000 };
Battle D_800A7960 = { 110, 10, 0x60080000 };
Battle D_800A796C = { 110, 10, 0x60080000 };
Battle D_800A7978 = { 110, 10, 0x60080000 };
Battle D_800A7984 = { 110, 10, 0x60080000 };
BattleList D_800A7990 = {
    3,
    { &D_800A7930, &D_800A793C, &D_800A7948, &D_800A7954,
      &D_800A7960, &D_800A796C, &D_800A7978, &D_800A7984 },
};
Battle D_800A79B4 = { 0, 0, 0x60040000 };
Battle D_800A79C0 = { 0, 0, 0x60040000 };
Battle D_800A79CC = { 0, 0, 0x60040000 };
Battle D_800A79D8 = { 0, 0, 0x60040000 };
Battle D_800A79E4 = { 0, 0, 0x60040000 };
Battle D_800A79F0 = { 0, 0, 0x60040000 };
Battle D_800A79FC = { 0, 0, 0x60040000 };
Battle D_800A7A08 = { 0, 0, 0x60040000 };
BattleList D_800A7A14 = {
    0,
    { &D_800A79B4, &D_800A79C0, &D_800A79CC, &D_800A79D8,
      &D_800A79E4, &D_800A79F0, &D_800A79FC, &D_800A7A08 },
};
Battle D_800A7A38 = { 0, 0, 0x60040000 };
Battle D_800A7A44 = { 0, 0, 0x60040000 };
Battle D_800A7A50 = { 0, 0, 0x60040000 };
Battle D_800A7A5C = { 0, 0, 0x60040000 };
Battle D_800A7A68 = { 0, 0, 0x60040000 };
Battle D_800A7A74 = { 0, 0, 0x60040000 };
Battle D_800A7A80 = { 0, 0, 0x60040000 };
Battle D_800A7A8C = { 0, 0, 0x60040000 };
BattleList D_800A7A98 = {
    0,
    { &D_800A7A38, &D_800A7A44, &D_800A7A50, &D_800A7A5C,
      &D_800A7A68, &D_800A7A74, &D_800A7A80, &D_800A7A8C },
};
Battle D_800A7ABC = { 0, 0, 0x60040000 };
Battle D_800A7AC8 = { 0, 0, 0x60040000 };
Battle D_800A7AD4 = { 0, 0, 0x60040000 };
Battle D_800A7AE0 = { 0, 0, 0x60040000 };
Battle D_800A7AEC = { 0, 0, 0x60040000 };
Battle D_800A7AF8 = { 0, 0, 0x60040000 };
Battle D_800A7B04 = { 0, 0, 0x60040000 };
Battle D_800A7B10 = { 0, 0, 0x60040000 };
BattleList D_800A7B1C = {
    0,
    { &D_800A7ABC, &D_800A7AC8, &D_800A7AD4, &D_800A7AE0,
      &D_800A7AEC, &D_800A7AF8, &D_800A7B04, &D_800A7B10 },
};
Battle D_800A7B40 = { 110, 10, 0x60080000 };
Battle D_800A7B4C = { 110, 10, 0x60080000 };
Battle D_800A7B58 = { 110, 10, 0x60080000 };
Battle D_800A7B64 = { 110, 10, 0x60080000 };
Battle D_800A7B70 = { 110, 10, 0x60080000 };
Battle D_800A7B7C = { 110, 10, 0x60080000 };
Battle D_800A7B88 = { 110, 10, 0x60080000 };
Battle D_800A7B94 = { 110, 10, 0x60080000 };
BattleList D_800A7BA0 = {
    3,
    { &D_800A7B40, &D_800A7B4C, &D_800A7B58, &D_800A7B64,
      &D_800A7B70, &D_800A7B7C, &D_800A7B88, &D_800A7B94 },
};
Battle D_800A7BC4 = { 0, 0, 0x60040000 };
Battle D_800A7BD0 = { 0, 0, 0x60040000 };
Battle D_800A7BDC = { 0, 0, 0x60040000 };
Battle D_800A7BE8 = { 0, 0, 0x60040000 };
Battle D_800A7BF4 = { 0, 0, 0x60040000 };
Battle D_800A7C00 = { 0, 0, 0x60040000 };
Battle D_800A7C0C = { 0, 0, 0x60040000 };
Battle D_800A7C18 = { 0, 0, 0x60040000 };
BattleList D_800A7C24 = {
    0,
    { &D_800A7BC4, &D_800A7BD0, &D_800A7BDC, &D_800A7BE8,
      &D_800A7BF4, &D_800A7C00, &D_800A7C0C, &D_800A7C18 },
};
Battle D_800A7C48 = { 0, 0, 0x60040000 };
Battle D_800A7C54 = { 0, 0, 0x60040000 };
Battle D_800A7C60 = { 0, 0, 0x60040000 };
Battle D_800A7C6C = { 0, 0, 0x60040000 };
Battle D_800A7C78 = { 0, 0, 0x60040000 };
Battle D_800A7C84 = { 0, 0, 0x60040000 };
Battle D_800A7C90 = { 0, 0, 0x60040000 };
Battle D_800A7C9C = { 0, 0, 0x60040000 };
BattleList D_800A7CA8 = {
    0,
    { &D_800A7C48, &D_800A7C54, &D_800A7C60, &D_800A7C6C,
      &D_800A7C78, &D_800A7C84, &D_800A7C90, &D_800A7C9C },
};
Battle D_800A7CCC = { 0, 0, 0x60040000 };
Battle D_800A7CD8 = { 0, 0, 0x60040000 };
Battle D_800A7CE4 = { 0, 0, 0x60040000 };
Battle D_800A7CF0 = { 0, 0, 0x60040000 };
Battle D_800A7CFC = { 0, 0, 0x60040000 };
Battle D_800A7D08 = { 0, 0, 0x60040000 };
Battle D_800A7D14 = { 0, 0, 0x60040000 };
Battle D_800A7D20 = { 0, 0, 0x60040000 };
BattleList D_800A7D2C = {
    0,
    { &D_800A7CCC, &D_800A7CD8, &D_800A7CE4, &D_800A7CF0,
      &D_800A7CFC, &D_800A7D08, &D_800A7D14, &D_800A7D20 },
};
Battle D_800A7D50 = { 182, 10, 0x60080000 };
Battle D_800A7D5C = { 182, 10, 0x60080000 };
Battle D_800A7D68 = { 182, 10, 0x60080000 };
Battle D_800A7D74 = { 182, 10, 0x60080000 };
Battle D_800A7D80 = { 71, 10, 0x60080000 };
Battle D_800A7D8C = { 71, 10, 0x60080000 };
Battle D_800A7D98 = { 71, 10, 0x60080000 };
Battle D_800A7DA4 = { 71, 10, 0x60080000 };
BattleList D_800A7DB0 = {
    2,
    { &D_800A7D50, &D_800A7D5C, &D_800A7D68, &D_800A7D74,
      &D_800A7D80, &D_800A7D8C, &D_800A7D98, &D_800A7DA4 },
};
Battle D_800A7DD4 = { 0, 0, 0x60040000 };
Battle D_800A7DE0 = { 0, 0, 0x60040000 };
Battle D_800A7DEC = { 0, 0, 0x60040000 };
Battle D_800A7DF8 = { 0, 0, 0x60040000 };
Battle D_800A7E04 = { 0, 0, 0x60040000 };
Battle D_800A7E10 = { 0, 0, 0x60040000 };
Battle D_800A7E1C = { 0, 0, 0x60040000 };
Battle D_800A7E28 = { 0, 0, 0x60040000 };
BattleList D_800A7E34 = {
    0,
    { &D_800A7DD4, &D_800A7DE0, &D_800A7DEC, &D_800A7DF8,
      &D_800A7E04, &D_800A7E10, &D_800A7E1C, &D_800A7E28 },
};
Battle D_800A7E58 = { 0, 0, 0x60040000 };
Battle D_800A7E64 = { 0, 0, 0x60040000 };
Battle D_800A7E70 = { 0, 0, 0x60040000 };
Battle D_800A7E7C = { 0, 0, 0x60040000 };
Battle D_800A7E88 = { 0, 0, 0x60040000 };
Battle D_800A7E94 = { 0, 0, 0x60040000 };
Battle D_800A7EA0 = { 0, 0, 0x60040000 };
Battle D_800A7EAC = { 0, 0, 0x60040000 };
BattleList D_800A7EB8 = {
    0,
    { &D_800A7E58, &D_800A7E64, &D_800A7E70, &D_800A7E7C,
      &D_800A7E88, &D_800A7E94, &D_800A7EA0, &D_800A7EAC },
};
Battle D_800A7EDC = { 0, 0, 0x60040000 };
Battle D_800A7EE8 = { 0, 0, 0x60040000 };
Battle D_800A7EF4 = { 0, 0, 0x60040000 };
Battle D_800A7F00 = { 0, 0, 0x60040000 };
Battle D_800A7F0C = { 0, 0, 0x60040000 };
Battle D_800A7F18 = { 0, 0, 0x60040000 };
Battle D_800A7F24 = { 0, 0, 0x60040000 };
Battle D_800A7F30 = { 0, 0, 0x60040000 };
BattleList D_800A7F3C = {
    0,
    { &D_800A7EDC, &D_800A7EE8, &D_800A7EF4, &D_800A7F00,
      &D_800A7F0C, &D_800A7F18, &D_800A7F24, &D_800A7F30 },
};
Battle D_800A7F60 = { 182, 10, 0x60080000 };
Battle D_800A7F6C = { 182, 10, 0x60080000 };
Battle D_800A7F78 = { 182, 10, 0x60080000 };
Battle D_800A7F84 = { 182, 10, 0x60080000 };
Battle D_800A7F90 = { 71, 10, 0x60080000 };
Battle D_800A7F9C = { 71, 10, 0x60080000 };
Battle D_800A7FA8 = { 71, 10, 0x60080000 };
Battle D_800A7FB4 = { 71, 10, 0x60080000 };
BattleList D_800A7FC0 = {
    5,
    { &D_800A7F60, &D_800A7F6C, &D_800A7F78, &D_800A7F84,
      &D_800A7F90, &D_800A7F9C, &D_800A7FA8, &D_800A7FB4 },
};
Battle D_800A7FE4 = { 0, 0, 0x60040000 };
Battle D_800A7FF0 = { 0, 0, 0x60040000 };
Battle D_800A7FFC = { 0, 0, 0x60040000 };
Battle D_800A8008 = { 0, 0, 0x60040000 };
Battle D_800A8014 = { 0, 0, 0x60040000 };
Battle D_800A8020 = { 0, 0, 0x60040000 };
Battle D_800A802C = { 0, 0, 0x60040000 };
Battle D_800A8038 = { 0, 0, 0x60040000 };
BattleList D_800A8044 = {
    0,
    { &D_800A7FE4, &D_800A7FF0, &D_800A7FFC, &D_800A8008,
      &D_800A8014, &D_800A8020, &D_800A802C, &D_800A8038 },
};
Battle D_800A8068 = { 0, 0, 0x60040000 };
Battle D_800A8074 = { 0, 0, 0x60040000 };
Battle D_800A8080 = { 0, 0, 0x60040000 };
Battle D_800A808C = { 0, 0, 0x60040000 };
Battle D_800A8098 = { 0, 0, 0x60040000 };
Battle D_800A80A4 = { 0, 0, 0x60040000 };
Battle D_800A80B0 = { 0, 0, 0x60040000 };
Battle D_800A80BC = { 0, 0, 0x60040000 };
BattleList D_800A80C8 = {
    0,
    { &D_800A8068, &D_800A8074, &D_800A8080, &D_800A808C,
      &D_800A8098, &D_800A80A4, &D_800A80B0, &D_800A80BC },
};
Battle D_800A80EC = { 0, 0, 0x60040000 };
Battle D_800A80F8 = { 0, 0, 0x60040000 };
Battle D_800A8104 = { 0, 0, 0x60040000 };
Battle D_800A8110 = { 0, 0, 0x60040000 };
Battle D_800A811C = { 0, 0, 0x60040000 };
Battle D_800A8128 = { 0, 0, 0x60040000 };
Battle D_800A8134 = { 0, 0, 0x60040000 };
Battle D_800A8140 = { 0, 0, 0x60040000 };
BattleList D_800A814C = {
    0,
    { &D_800A80EC, &D_800A80F8, &D_800A8104, &D_800A8110,
      &D_800A811C, &D_800A8128, &D_800A8134, &D_800A8140 },
};
Battle D_800A8170 = { 182, 10, 0x60080000 };
Battle D_800A817C = { 182, 10, 0x60080000 };
Battle D_800A8188 = { 182, 10, 0x60080000 };
Battle D_800A8194 = { 182, 10, 0x60080000 };
Battle D_800A81A0 = { 71, 10, 0x60080000 };
Battle D_800A81AC = { 71, 10, 0x60080000 };
Battle D_800A81B8 = { 71, 10, 0x60080000 };
Battle D_800A81C4 = { 71, 10, 0x60080000 };
BattleList D_800A81D0 = {
    1,
    { &D_800A8170, &D_800A817C, &D_800A8188, &D_800A8194,
      &D_800A81A0, &D_800A81AC, &D_800A81B8, &D_800A81C4 },
};
Battle D_800A81F4 = { 0, 0, 0x60040000 };
Battle D_800A8200 = { 0, 0, 0x60040000 };
Battle D_800A820C = { 0, 0, 0x60040000 };
Battle D_800A8218 = { 0, 0, 0x60040000 };
Battle D_800A8224 = { 0, 0, 0x60040000 };
Battle D_800A8230 = { 0, 0, 0x60040000 };
Battle D_800A823C = { 0, 0, 0x60040000 };
Battle D_800A8248 = { 0, 0, 0x60040000 };
BattleList D_800A8254 = {
    0,
    { &D_800A81F4, &D_800A8200, &D_800A820C, &D_800A8218,
      &D_800A8224, &D_800A8230, &D_800A823C, &D_800A8248 },
};
Battle D_800A8278 = { 0, 0, 0x60040000 };
Battle D_800A8284 = { 0, 0, 0x60040000 };
Battle D_800A8290 = { 0, 0, 0x60040000 };
Battle D_800A829C = { 0, 0, 0x60040000 };
Battle D_800A82A8 = { 0, 0, 0x60040000 };
Battle D_800A82B4 = { 0, 0, 0x60040000 };
Battle D_800A82C0 = { 0, 0, 0x60040000 };
Battle D_800A82CC = { 0, 0, 0x60040000 };
BattleList D_800A82D8 = {
    0,
    { &D_800A8278, &D_800A8284, &D_800A8290, &D_800A829C,
      &D_800A82A8, &D_800A82B4, &D_800A82C0, &D_800A82CC },
};
Battle D_800A82FC = { 0, 0, 0x60040000 };
Battle D_800A8308 = { 0, 0, 0x60040000 };
Battle D_800A8314 = { 0, 0, 0x60040000 };
Battle D_800A8320 = { 0, 0, 0x60040000 };
Battle D_800A832C = { 0, 0, 0x60040000 };
Battle D_800A8338 = { 0, 0, 0x60040000 };
Battle D_800A8344 = { 0, 0, 0x60040000 };
Battle D_800A8350 = { 0, 0, 0x60040000 };
BattleList D_800A835C = {
    0,
    { &D_800A82FC, &D_800A8308, &D_800A8314, &D_800A8320,
      &D_800A832C, &D_800A8338, &D_800A8344, &D_800A8350 },
};
Battle D_800A8380 = { 182, 10, 0x60080000 };
Battle D_800A838C = { 182, 10, 0x60080000 };
Battle D_800A8398 = { 182, 10, 0x60080000 };
Battle D_800A83A4 = { 182, 10, 0x60080000 };
Battle D_800A83B0 = { 71, 10, 0x60080000 };
Battle D_800A83BC = { 71, 10, 0x60080000 };
Battle D_800A83C8 = { 71, 10, 0x60080000 };
Battle D_800A83D4 = { 71, 10, 0x60080000 };
BattleList D_800A83E0 = {
    1,
    { &D_800A8380, &D_800A838C, &D_800A8398, &D_800A83A4,
      &D_800A83B0, &D_800A83BC, &D_800A83C8, &D_800A83D4 },
};
Battle D_800A8404 = { 0, 0, 0x60040000 };
Battle D_800A8410 = { 0, 0, 0x60040000 };
Battle D_800A841C = { 0, 0, 0x60040000 };
Battle D_800A8428 = { 0, 0, 0x60040000 };
Battle D_800A8434 = { 0, 0, 0x60040000 };
Battle D_800A8440 = { 0, 0, 0x60040000 };
Battle D_800A844C = { 0, 0, 0x60040000 };
Battle D_800A8458 = { 0, 0, 0x60040000 };
BattleList D_800A8464 = {
    0,
    { &D_800A8404, &D_800A8410, &D_800A841C, &D_800A8428,
      &D_800A8434, &D_800A8440, &D_800A844C, &D_800A8458 },
};
Battle D_800A8488 = { 0, 0, 0x60040000 };
Battle D_800A8494 = { 0, 0, 0x60040000 };
Battle D_800A84A0 = { 0, 0, 0x60040000 };
Battle D_800A84AC = { 0, 0, 0x60040000 };
Battle D_800A84B8 = { 0, 0, 0x60040000 };
Battle D_800A84C4 = { 0, 0, 0x60040000 };
Battle D_800A84D0 = { 0, 0, 0x60040000 };
Battle D_800A84DC = { 0, 0, 0x60040000 };
BattleList D_800A84E8 = {
    0,
    { &D_800A8488, &D_800A8494, &D_800A84A0, &D_800A84AC,
      &D_800A84B8, &D_800A84C4, &D_800A84D0, &D_800A84DC },
};
Battle D_800A850C = { 0, 0, 0x60040000 };
Battle D_800A8518 = { 0, 0, 0x60040000 };
Battle D_800A8524 = { 0, 0, 0x60040000 };
Battle D_800A8530 = { 0, 0, 0x60040000 };
Battle D_800A853C = { 0, 0, 0x60040000 };
Battle D_800A8548 = { 0, 0, 0x60040000 };
Battle D_800A8554 = { 0, 0, 0x60040000 };
Battle D_800A8560 = { 0, 0, 0x60040000 };
BattleList D_800A856C = {
    0,
    { &D_800A850C, &D_800A8518, &D_800A8524, &D_800A8530,
      &D_800A853C, &D_800A8548, &D_800A8554, &D_800A8560 },
};
Battle D_800A8590 = { 174, 10, 0x60080000 };
Battle D_800A859C = { 174, 10, 0x60080000 };
Battle D_800A85A8 = { 170, 10, 0x60080000 };
Battle D_800A85B4 = { 170, 10, 0x60080000 };
Battle D_800A85C0 = { 182, 10, 0x60080000 };
Battle D_800A85CC = { 182, 10, 0x60080000 };
Battle D_800A85D8 = { 71, 10, 0x60080000 };
Battle D_800A85E4 = { 71, 10, 0x60080000 };
BattleList D_800A85F0 = {
    1,
    { &D_800A8590, &D_800A859C, &D_800A85A8, &D_800A85B4,
      &D_800A85C0, &D_800A85CC, &D_800A85D8, &D_800A85E4 },
};
Battle D_800A8614 = { 0, 0, 0x60040000 };
Battle D_800A8620 = { 0, 0, 0x60040000 };
Battle D_800A862C = { 0, 0, 0x60040000 };
Battle D_800A8638 = { 0, 0, 0x60040000 };
Battle D_800A8644 = { 0, 0, 0x60040000 };
Battle D_800A8650 = { 0, 0, 0x60040000 };
Battle D_800A865C = { 0, 0, 0x60040000 };
Battle D_800A8668 = { 0, 0, 0x60040000 };
BattleList D_800A8674 = {
    0,
    { &D_800A8614, &D_800A8620, &D_800A862C, &D_800A8638,
      &D_800A8644, &D_800A8650, &D_800A865C, &D_800A8668 },
};
Battle D_800A8698 = { 0, 0, 0x60040000 };
Battle D_800A86A4 = { 0, 0, 0x60040000 };
Battle D_800A86B0 = { 0, 0, 0x60040000 };
Battle D_800A86BC = { 0, 0, 0x60040000 };
Battle D_800A86C8 = { 0, 0, 0x60040000 };
Battle D_800A86D4 = { 0, 0, 0x60040000 };
Battle D_800A86E0 = { 0, 0, 0x60040000 };
Battle D_800A86EC = { 0, 0, 0x60040000 };
BattleList D_800A86F8 = {
    0,
    { &D_800A8698, &D_800A86A4, &D_800A86B0, &D_800A86BC,
      &D_800A86C8, &D_800A86D4, &D_800A86E0, &D_800A86EC },
};
Battle D_800A871C = { 0, 0, 0x60040000 };
Battle D_800A8728 = { 0, 0, 0x60040000 };
Battle D_800A8734 = { 0, 0, 0x60040000 };
Battle D_800A8740 = { 0, 0, 0x60040000 };
Battle D_800A874C = { 0, 0, 0x60040000 };
Battle D_800A8758 = { 0, 0, 0x60040000 };
Battle D_800A8764 = { 0, 0, 0x60040000 };
Battle D_800A8770 = { 0, 0, 0x60040000 };
BattleList D_800A877C = {
    0,
    { &D_800A871C, &D_800A8728, &D_800A8734, &D_800A8740,
      &D_800A874C, &D_800A8758, &D_800A8764, &D_800A8770 },
};
FieldBattles stageBattles[] = {
    { 230, 1, 0, { &D_800A5AA0, &D_800A5B24, &D_800A5BA8, &D_800A5C2C } },
    { 237, 2, 0, { &D_800A5CB0, &D_800A5D34, &D_800A5DB8, &D_800A5E3C } },
    { 242, 3, 0, { &D_800A5EC0, &D_800A5F44, &D_800A5FC8, &D_800A604C } },
    { 257, 5, 0, { &D_800A60D0, &D_800A6154, &D_800A61D8, &D_800A625C } },
    { 260, 6, 0, { &D_800A62E0, &D_800A6364, &D_800A63E8, &D_800A646C } },
    { 265, 7, 0, { &D_800A64F0, &D_800A6574, &D_800A65F8, &D_800A667C } },
    { 269, 8, 0, { &D_800A6700, &D_800A6784, &D_800A6808, &D_800A688C } },
    { 275, 9, 0, { &D_800A6910, &D_800A6994, &D_800A6A18, &D_800A6A9C } },
    { 280, 10, 0, { &D_800A6B20, &D_800A6BA4, &D_800A6C28, &D_800A6CAC } },
    { 285, 11, 0, { &D_800A6D30, &D_800A6DB4, &D_800A6E38, &D_800A6EBC } },
    { 290, 12, 0, { &D_800A6F40, &D_800A6FC4, &D_800A7048, &D_800A70CC } },
    { 296, 13, 0, { &D_800A7150, &D_800A71D4, &D_800A7258, &D_800A72DC } },
    { 315, 18, 0, { &D_800A7360, &D_800A73E4, &D_800A7468, &D_800A74EC } },
    { 318, 19, 0, { &D_800A7570, &D_800A75F4, &D_800A7678, &D_800A76FC } },
    { 326, 20, 0, { &D_800A7780, &D_800A7804, &D_800A7888, &D_800A790C } },
    { 330, 21, 0, { &D_800A7990, &D_800A7A14, &D_800A7A98, &D_800A7B1C } },
    { 335, 22, 0, { &D_800A7BA0, &D_800A7C24, &D_800A7CA8, &D_800A7D2C } },
    { 339, 23, 0, { &D_800A7DB0, &D_800A7E34, &D_800A7EB8, &D_800A7F3C } },
    { 343, 24, 0, { &D_800A7FC0, &D_800A8044, &D_800A80C8, &D_800A814C } },
    { 358, 28, 0, { &D_800A81D0, &D_800A8254, &D_800A82D8, &D_800A835C } },
    { 364, 29, 0, { &D_800A83E0, &D_800A8464, &D_800A84E8, &D_800A856C } },
    { 371, 30, 0, { &D_800A85F0, &D_800A8674, &D_800A86F8, &D_800A877C } },
};
ActorImage stageImages[] = {
    { 0x200, 0x100, 0x21C, 0x1A6, 0x70, 0xA6, 0x230, 0x1FE },
    { 0x200, 0x100, 0x200, 0x100, 0, 0, 0x220, 0x1FE },
    { 0x200, 0x100, 0x216, 0x138, 0x58, 0x38, 0x200, 0x1FD },
    { 0x200, 0x100, 0x208, 0x1BC, 0x20, 0xBC, 0x210, 0x1FD },
    { 0x200, 0x100, 0x210, 0x1BC, 0x40, 0xBC, 0x220, 0x1FD },
    { 0x200, 0x100, 0x200, 0x1BC, 0, 0xBC, 0x230, 0x1FD },
    { 0x140, 0x100, 0x14C, 0x140, 0x30, 0x40, 0x140, 0x1FF },
    { 0x140, 0x100, 0x174, 0x140, 0xD0, 0x40, 0x150, 0x1FF },
    { 0x140, 0x100, 0x140, 0x140, 0, 0x40, 0x160, 0x1FF },
    { 0x140, 0x100, 0x168, 0x100, 0xA0, 0, 0x170, 0x1FF },
    { 0x140, 0x100, 0x154, 0x140, 0x50, 0x40, 0x140, 0x1FE },
    { 0x140, 0x100, 0x15C, 0x140, 0x70, 0x40, 0x150, 0x1FE },
    { 0x140, 0x100, 0x164, 0x140, 0x90, 0x40, 0x160, 0x1FE },
    { 0x140, 0x100, 0x16C, 0x140, 0xB0, 0x40, 0x170, 0x1FE },
    { 0x140, 0x100, 0x140, 0x100, 0, 0, 0x140, 0x1FD },
    { 0x140, 0x100, 0x154, 0x100, 0x50, 0, 0x150, 0x1FD },
};
u16 D_800A8B08[] = { 0x11, 0, 0x9223, 0, 0xFFFF };
u16 D_800A8B14[] = { 0x7649, 1, 0xFFFF };
u16 D_800A8B1C[] = { 0x11, 0, 0x9223, 1, 0xFFFF };
u16 D_800A8B28[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A8B34[] = { 0x11, 0, 0xFFFF };
u16 D_800A8B3C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A8B48[] = { 0x11, 0, 0x10, 0, 0x9223, 1, 0xFFFF };
u16 D_800A8B58[] = { 0x11, 0, 0x9221, 0, 0xFFFF };
u16 D_800A8B64[] = { 0x764A, 1, 0xFFFF };
u16 D_800A8B6C[] = { 0x11, 0, 0x9221, 1, 0xFFFF };
u16 D_800A8B78[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A8B84[] = { 0x11, 0, 0xFFFF };
u16 D_800A8B8C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A8B98[] = { 0x11, 0, 0x10, 0, 0x9221, 1, 0xFFFF };
u16 D_800A8BA8[] = { 0x11, 0, 0x92C6, 0, 0xFFFF };
u16 D_800A8BB4[] = { 0x764C, 1, 0xFFFF };
u16 D_800A8BBC[] = { 0x11, 0, 0x92C6, 1, 0xFFFF };
u16 D_800A8BC8[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A8BD4[] = { 0x11, 0, 0xFFFF };
u16 D_800A8BDC[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A8BE8[] = { 0x11, 0, 0x10, 0, 0x92C6, 1, 0xFFFF };
u16 D_800A8BF8[] = { 0x929B, 0, 0x11, 0, 0xFFFF };
u16 D_800A8C04[] = { 0x764D, 1, 0xFFFF };
u16 D_800A8C0C[] = { 0x11, 0, 0x929B, 1, 0xFFFF };
u16 D_800A8C18[] = { 0x11, 1, 0x10, 0, 0xFFFF };
u16 D_800A8C24[] = { 0x11, 0, 0xFFFF };
u16 D_800A8C2C[] = { 0x11, 1, 0x10, 1, 0xFFFF };
u16 D_800A8C38[] = { 0x11, 0, 0x10, 0, 0x929B, 1, 0xFFFF };
FieldTalk D_800A8C48[] = {
    { NULL, NULL, 0x354 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8C60[] = {
    { NULL, NULL, 0x3B0 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8C78[] = {
    { NULL, NULL, 0x3B1 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8C90[] = {
    { NULL, NULL, 0x3B5 },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8CA8[] = {
    { D_800A8B08, D_800A8B14, 0x367 },
    { D_800A8B1C, NULL, 0x368 },
    { D_800A8B28, D_800A8B34, 0x369 },
    { D_800A8B3C, D_800A8B48, 0x36C },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8CE4[] = {
    { D_800A8B58, D_800A8B64, 0x367 },
    { D_800A8B6C, NULL, 0x368 },
    { D_800A8B78, D_800A8B84, 0x369 },
    { D_800A8B8C, D_800A8B98, 0x36D },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D20[] = {
    { D_800A8BA8, D_800A8BB4, 0x377 },
    { D_800A8BBC, NULL, 0x378 },
    { D_800A8BC8, D_800A8BD4, 0x379 },
    { D_800A8BDC, D_800A8BE8, 0x37A },
    { NULL, NULL, 0 },
};
FieldTalk D_800A8D5C[] = {
    { D_800A8BF8, D_800A8C04, 0x377 },
    { D_800A8C0C, NULL, 0x378 },
    { D_800A8C18, D_800A8C24, 0x379 },
    { D_800A8C2C, D_800A8C38, 0x37B },
    { NULL, NULL, 0 },
};
u16 D_800A8D98[] = { 0x7E17, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A8DA4[] = { 0x7E00, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8DB0[] = { 0x7E07, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8DBC[] = { 0x7E08, 1, 0x7E1E, 1, 0xFFFF };
u16 D_800A8DC8[] = { 0x7E13, 1, 8, 0, 0xFFFF };
u16 D_800A8DD4[] = { 0x9223, 0, 0x7E0B, 1, 0x7E1E, 1, 0x8014, 1, 0xFFFF };
u16 D_800A8DE8[] = { 0x7E0C, 1, 0x7E1E, 1, 0x8014, 1, 0x9221, 0, 0xFFFF };
u16 D_800A8DFC[] = { 0x7E17, 1, 0x7E20, 1, 0x8014, 1, 0x92C6, 0, 0xFFFF };
u16 D_800A8E10[] = { 0x7E16, 1, 0x7E1F, 1, 0x8014, 1, 0x929B, 0, 0xFFFF };
u16 D_800A8E24[] = { 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A8E30[] = { 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A8E3C[] = { 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A8E48[] = { 0x7E05, 1, 0xA, 0, 0xFFFF };
u16 D_800A8E54[] = { 0x7E06, 1, 0xA, 0, 0xFFFF };
u16 D_800A8E60[] = { 0x7E0B, 1, 0xA, 0, 0xFFFF };
u16 D_800A8E6C[] = { 0x7E0C, 1, 0xA, 0, 0xFFFF };
u16 D_800A8E78[] = { 0x7E12, 1, 0xA, 0, 0xFFFF };
u16 D_800A8E84[] = { 0x7E13, 1, 0xA, 0, 0xFFFF };
u16 D_800A8E90[] = { 0x7E15, 1, 0xA, 0, 0xFFFF };
u16 D_800A8E9C[] = { 0x7E16, 1, 0xA, 0, 0xFFFF };
u16 D_800A8EA8[] = { 0x7E17, 1, 0xA, 0, 0xFFFF };
u16 D_800A8EB4[] = { 0x7E1B, 1, 0xA, 0, 0xFFFF };
u16 D_800A8EC0[] = { 0x7E1C, 1, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A8ECC = { D_800A8D98, D_800A8C48, 0x23, 4, 800, 344, 1 };
FieldActorEntry D_800A8EE0 = { D_800A8DA4, D_800A8C60, 0x23, 4, 616, 272, 7 };
FieldActorEntry D_800A8EF4 = { D_800A8DB0, D_800A8C78, 0x23, 4, 800, 344, 1 };
FieldActorEntry D_800A8F08 = { D_800A8DBC, D_800A8C90, 0x41, 5, 616, 272, 7 };
FieldActorEntry D_800A8F1C = { NULL, NULL, 0x146, 6, 0, 0, 0 };
FieldActorEntry D_800A8F30 = { D_800A8DC8, NULL, 0x148, 7, 400, 248, 1 };
FieldActorEntry D_800A8F44 = { D_800A8DD4, D_800A8CA8, 0x151, 8, 800, 344, 1 };
FieldActorEntry D_800A8F58 = { D_800A8DE8, D_800A8CE4, 0x152, 9, 888, 460, 1 };
FieldActorEntry D_800A8F6C = { D_800A8DFC, D_800A8D20, 0x159, 0xA, 448, 200, 1 };
FieldActorEntry D_800A8F80 = { D_800A8E10, D_800A8D5C, 0x15A, 0xB, 888, 460, 1 };
FieldActorEntry D_800A8F94 = { D_800A8E24, NULL, 0x15F, 0xC, 464, 424, 1 };
FieldActorEntry D_800A8FA8 = { D_800A8E30, NULL, 0x15F, 0xC, 704, 352, 1 };
FieldActorEntry D_800A8FBC = { D_800A8E3C, NULL, 0x15F, 0xC, 736, 272, 1 };
FieldActorEntry D_800A8FD0 = { D_800A8E48, NULL, 0x160, 0xD, 880, 152, 1 };
FieldActorEntry D_800A8FE4 = { D_800A8E54, NULL, 0x160, 0xD, 304, 440, 1 };
FieldActorEntry D_800A8FF8 = { D_800A8E60, NULL, 0x160, 0xD, 736, 416, 1 };
FieldActorEntry D_800A900C = { D_800A8E6C, NULL, 0x160, 0xD, 400, 248, 1 };
FieldActorEntry D_800A9020 = { D_800A8E78, NULL, 0x160, 0xD, 592, 440, 1 };
FieldActorEntry D_800A9034 = { D_800A8E84, NULL, 0x160, 0xD, 800, 448, 1 };
FieldActorEntry D_800A9048 = { D_800A8E90, NULL, 0x160, 0xD, 784, 200, 1 };
FieldActorEntry D_800A905C = { D_800A8E9C, NULL, 0x160, 0xD, 320, 288, 1 };
FieldActorEntry D_800A9070 = { D_800A8EA8, NULL, 0x160, 0xD, 800, 448, 1 };
FieldActorEntry D_800A9084 = { D_800A8EB4, NULL, 0x160, 0xD, 880, 152, 1 };
FieldActorEntry D_800A9098 = { D_800A8EC0, NULL, 0x160, 0xD, 736, 416, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A8ECC,
    &D_800A8EE0,
    &D_800A8EF4,
    &D_800A8F08,
    &D_800A8F1C,
    &D_800A8F30,
    &D_800A8F44,
    &D_800A8F58,
    &D_800A8F6C,
    &D_800A8F80,
    &D_800A8F94,
    &D_800A8FA8,
    &D_800A8FBC,
    &D_800A8FD0,
    &D_800A8FE4,
    &D_800A8FF8,
    &D_800A900C,
    &D_800A9020,
    &D_800A9034,
    &D_800A9048,
    &D_800A905C,
    &D_800A9070,
    &D_800A9084,
    &D_800A9098,
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
