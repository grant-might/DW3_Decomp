#include "common.h"
#include "stage.h"

#include "common/copy_place_points.inc.c"
#include "common/update_stage_places.inc.c"
#include "common/start_stage.inc.c"

#if VERSION_US
#define STAGE_TEXT 0xE9
#define STAGE_FILE 0x6A4
#elif VERSION_EU
#define STAGE_TEXT (LANGUAGE + 0xE1)
#define STAGE_FILE 0x6B4
#endif
void setupStage(void) {
    D_800990B4.textFile = STAGE_TEXT;
    D_800990B4.mapFile = STAGE_FILE - 1;
    D_800990B4.sheetEntry = STAGE_FILE << 16;
    D_800990B4.objects = stageObjects;
    D_800990B4.slots = stageSlots;
    D_800990B4.imageFile = STAGE_FILE - 2;
    D_800990B4.start = (Vec2){0x17900, 0x17300};
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
extern Battle D_800A5518;
extern Battle D_800A5524;
extern Battle D_800A5530;
extern Battle D_800A553C;
extern Battle D_800A5548;
extern Battle D_800A5554;
extern Battle D_800A5560;
extern Battle D_800A556C;
extern Battle D_800A559C;
extern Battle D_800A55A8;
extern Battle D_800A55B4;
extern Battle D_800A55C0;
extern Battle D_800A55CC;
extern Battle D_800A55D8;
extern Battle D_800A55E4;
extern Battle D_800A55F0;
extern Battle D_800A5620;
extern Battle D_800A562C;
extern Battle D_800A5638;
extern Battle D_800A5644;
extern Battle D_800A5650;
extern Battle D_800A565C;
extern Battle D_800A5668;
extern Battle D_800A5674;
extern Battle D_800A56A4;
extern Battle D_800A56B0;
extern Battle D_800A56BC;
extern Battle D_800A56C8;
extern Battle D_800A56D4;
extern Battle D_800A56E0;
extern Battle D_800A56EC;
extern Battle D_800A56F8;
extern Battle D_800A5728;
extern Battle D_800A5734;
extern Battle D_800A5740;
extern Battle D_800A574C;
extern Battle D_800A5758;
extern Battle D_800A5764;
extern Battle D_800A5770;
extern Battle D_800A577C;
extern Battle D_800A57AC;
extern Battle D_800A57B8;
extern Battle D_800A57C4;
extern Battle D_800A57D0;
extern Battle D_800A57DC;
extern Battle D_800A57E8;
extern Battle D_800A57F4;
extern Battle D_800A5800;
extern Battle D_800A5830;
extern Battle D_800A583C;
extern Battle D_800A5848;
extern Battle D_800A5854;
extern Battle D_800A5860;
extern Battle D_800A586C;
extern Battle D_800A5878;
extern Battle D_800A5884;
extern Battle D_800A58B4;
extern Battle D_800A58C0;
extern Battle D_800A58CC;
extern Battle D_800A58D8;
extern Battle D_800A58E4;
extern Battle D_800A58F0;
extern Battle D_800A58FC;
extern Battle D_800A5908;
extern Battle D_800A5938;
extern Battle D_800A5944;
extern Battle D_800A5950;
extern Battle D_800A595C;
extern Battle D_800A5968;
extern Battle D_800A5974;
extern Battle D_800A5980;
extern Battle D_800A598C;
extern Battle D_800A59BC;
extern Battle D_800A59C8;
extern Battle D_800A59D4;
extern Battle D_800A59E0;
extern Battle D_800A59EC;
extern Battle D_800A59F8;
extern Battle D_800A5A04;
extern Battle D_800A5A10;
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
extern BattleList D_800A5578;
extern BattleList D_800A55FC;
extern BattleList D_800A5680;
extern BattleList D_800A5704;
extern BattleList D_800A5788;
extern BattleList D_800A580C;
extern BattleList D_800A5890;
extern BattleList D_800A5914;
extern BattleList D_800A5998;
extern BattleList D_800A5A1C;
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
extern u16 D_800A76FC[];
extern FieldTalk D_800A766C[];
extern u16 D_800A7708[];
extern FieldTalk D_800A7684[];
extern u16 D_800A7714[];
extern FieldTalk D_800A769C[];
extern u16 D_800A7720[];
extern FieldTalk D_800A76B4[];
extern u16 D_800A772C[];
extern FieldTalk D_800A76CC[];
extern u16 D_800A7738[];
extern FieldTalk D_800A76E4[];
extern u16 D_800A7744[];
extern u16 D_800A7750[];
extern u16 D_800A775C[];
extern u16 D_800A7768[];
extern u16 D_800A7774[];
extern u16 D_800A7780[];
extern u16 D_800A778C[];
extern u16 D_800A7798[];
extern u16 D_800A77A4[];
extern u16 D_800A77B0[];
extern u16 D_800A77BC[];
extern u16 D_800A77C8[];
extern u16 D_800A77D4[];
extern u16 D_800A77E0[];
extern FieldActorEntry D_800A77EC;
extern FieldActorEntry D_800A7800;
extern FieldActorEntry D_800A7814;
extern FieldActorEntry D_800A7828;
extern FieldActorEntry D_800A783C;
extern FieldActorEntry D_800A7850;
extern FieldActorEntry D_800A7864;
extern FieldActorEntry D_800A7878;
extern FieldActorEntry D_800A788C;
extern FieldActorEntry D_800A78A0;
extern FieldActorEntry D_800A78B4;
extern FieldActorEntry D_800A78C8;
extern FieldActorEntry D_800A78DC;
extern FieldActorEntry D_800A78F0;
extern FieldActorEntry D_800A7904;
extern FieldActorEntry D_800A7918;
extern FieldActorEntry D_800A792C;
extern FieldActorEntry D_800A7940;
extern FieldActorEntry D_800A7954;
extern FieldActorEntry D_800A7968;
extern FieldActorEntry D_800A797C;

StagePoint D_800A4F94 = { 0x2ED, 1, 2, 0x350, 0x1F8, 5, NULL };
StagePoint D_800A4FA4 = { 0x229, 0, 0, 0x1F0, 0x360, 0, &D_800A4F94 };
StagePoints D_800A4FB4 = { 1, 1, &D_800A4FA4 };
StagePoint D_800A4FBC = { 0x2EE, 1, 1, 224, 0x240, 5, NULL };
StagePoint D_800A4FCC = { 0x23C, 0, 0, 0x410, 0x2F8, 0, &D_800A4FBC };
StagePoints D_800A4FDC = { 1, 2, &D_800A4FCC };
StagePoint D_800A4FE4 = { 0x2ED, 2, 1, 0x350, 0x1F8, 5, NULL };
StagePoint D_800A4FF4 = { 0x22A, 0, 0, 0x440, 0x2F8, 0, &D_800A4FE4 };
StagePoints D_800A5004 = { 2, 1, &D_800A4FF4 };
StagePoint D_800A500C = { 0x2ED, 2, 2, 0x350, 0x1F8, 5, NULL };
StagePoint D_800A501C = { 0x220, 0, 0, 0x450, 0x226, 0, &D_800A500C };
StagePoints D_800A502C = { 2, 2, &D_800A501C };
StagePoint D_800A5034 = { 0x2EE, 2, 2, 224, 0x240, 5, NULL };
StagePoint D_800A5044 = { 0x24A, 0, 0, 0x2B0, 0x100, 0, &D_800A5034 };
StagePoints D_800A5054 = { 2, 3, &D_800A5044 };
StagePoint D_800A505C = { 0x2EC, 3, 2, 240, 0x1D8, 5, NULL };
StagePoint D_800A506C = { 0x247, 0, 0, 0x3D0, 0x100, 0, &D_800A505C };
StagePoints D_800A507C = { 3, 1, &D_800A506C };
StagePoint D_800A5084 = { 0x2EE, 3, 3, 224, 0x240, 5, NULL };
StagePoint D_800A5094 = { 0x23A, 0, 0, 0x560, 0x188, 0, &D_800A5084 };
StagePoints D_800A50A4 = { 3, 2, &D_800A5094 };
StagePoint D_800A50AC = { 0x2EE, 3, 4, 224, 0x240, 5, NULL };
StagePoint D_800A50BC = { 0x299, 0, 0, 0x2D0, 0x590, 0, &D_800A50AC };
StagePoints D_800A50CC = { 3, 3, &D_800A50BC };
StagePoint D_800A50D4 = { 0x2EE, 3, 5, 224, 0x240, 5, NULL };
StagePoint D_800A50E4 = { 0x22A, 0, 0, 0x2D0, 0x590, 0, &D_800A50D4 };
StagePoints D_800A50F4 = { 3, 4, &D_800A50E4 };
StagePoint D_800A50FC = { 0x2ED, 4, 1, 0x350, 0x1F8, 5, NULL };
StagePoint D_800A510C = { 0x24A, 0, 0, 0x5F0, 0x190, 0, &D_800A50FC };
StagePoints D_800A511C = { 4, 1, &D_800A510C };
StagePoint D_800A5124 = { 0x2ED, 4, 2, 0x350, 0x1F8, 5, NULL };
StagePoint D_800A5134 = { 0x2B4, 0, 0, 0x5F0, 0x190, 0, &D_800A5124 };
StagePoints D_800A5144 = { 4, 2, &D_800A5134 };
StagePoint D_800A514C = { 0x2ED, 5, 2, 224, 192, 5, NULL };
StagePoint D_800A515C = { 0x265, 0, 0, 0x4C0, 200, 0, &D_800A514C };
StagePoints D_800A516C = { 5, 1, &D_800A515C };
StagePoint D_800A5174 = { 0x2EE, 5, 3, 224, 0x240, 5, NULL };
StagePoint D_800A5184 = { 0x261, 0, 0, 0x4B0, 0x13E, 0, &D_800A5174 };
StagePoints D_800A5194 = { 5, 2, &D_800A5184 };
StagePoint D_800A519C = { 0x2EE, 5, 4, 224, 0x240, 5, NULL };
StagePoint D_800A51AC = { 0x264, 0, 0, 192, 0x214, 0, &D_800A519C };
StagePoints D_800A51BC = { 5, 3, &D_800A51AC };
StagePoint D_800A51C4 = { 0x2EC, 5, 1, 240, 0x1D8, 5, NULL };
StagePoint D_800A51D4 = { 0x229, 0, 0, 0x560, 0x238, 0, &D_800A51C4 };
StagePoints D_800A51E4 = { 5, 4, &D_800A51D4 };
StagePoint D_800A51EC = { 0x2EE, 6, 1, 224, 0x240, 5, NULL };
StagePoint D_800A51FC = { 0x2B1, 0, 0, 0x190, 0x1C0, 0, &D_800A51EC };
StagePoints D_800A520C = { 6, 1, &D_800A51FC };
StagePoint D_800A5214 = { 0x2EE, 6, 3, 224, 0x240, 5, NULL };
StagePoint D_800A5224 = { 0x265, 0, 0, 0x1C0, 0x206, 0, &D_800A5214 };
StagePoints D_800A5234 = { 6, 2, &D_800A5224 };
StagePoint D_800A523C = { 0x2ED, 8, 1, 224, 192, 5, NULL };
StagePoint D_800A524C = { 0x24A, 0, 0, 0x3F0, 0x330, 0, &D_800A523C };
StagePoints D_800A525C = { 8, 1, &D_800A524C };
StagePoint D_800A5264 = { 0x2EE, 8, 1, 224, 0x240, 5, NULL };
StagePoint D_800A5274 = { 0x2A9, 0, 0, 0x410, 0x2F8, 0, &D_800A5264 };
StagePoints D_800A5284 = { 8, 2, &D_800A5274 };
StagePoint D_800A528C = { 0x2ED, 8, 2, 0x350, 0x1F8, 5, NULL };
StagePoint D_800A529C = { 0x298, 0, 0, 0x1F0, 0x360, 0, &D_800A528C };
StagePoints D_800A52AC = { 8, 3, &D_800A529C };
StagePoint D_800A52B4 = { 0x2ED, 9, 1, 0x350, 0x1F8, 5, NULL };
StagePoint D_800A52C4 = { 0x299, 0, 0, 0x440, 0x2F8, 0, &D_800A52B4 };
StagePoints D_800A52D4 = { 9, 1, &D_800A52C4 };
StagePoint D_800A52DC = { 0x2EE, 9, 2, 224, 0x240, 5, NULL };
StagePoint D_800A52EC = { 0x2B4, 0, 0, 0x2B0, 0x100, 0, &D_800A52DC };
StagePoints D_800A52FC = { 9, 2, &D_800A52EC };
StagePoint D_800A5304 = { 0x2ED, 9, 2, 0x350, 0x1F8, 5, NULL };
StagePoint D_800A5314 = { 0x28F, 0, 0, 0x450, 0x226, 0, &D_800A5304 };
StagePoints D_800A5324 = { 9, 3, &D_800A5314 };
StagePoint D_800A532C = { 0x2EE, 10, 1, 224, 0x240, 5, NULL };
StagePoint D_800A533C = { 0x247, 0, 0, 0x1B0, 0x2F0, 0, &D_800A532C };
StagePoints D_800A534C = { 10, 1, &D_800A533C };
StagePoint D_800A5354 = { 0x2EC, 10, 2, 240, 0x1D8, 5, NULL };
StagePoint D_800A5364 = { 0x24B, 0, 0, 0x2E0, 216, 0, &D_800A5354 };
StagePoints D_800A5374 = { 10, 2, &D_800A5364 };
StagePoint D_800A537C = { 0x2EE, 11, 1, 224, 0x240, 5, NULL };
StagePoint D_800A538C = { 0x2B1, 0, 0, 0x1B0, 0x2F0, 0, &D_800A537C };
StagePoints D_800A539C = { 11, 1, &D_800A538C };
StagePoint D_800A53A4 = { 0x2EC, 11, 2, 240, 0x1D8, 5, NULL };
StagePoint D_800A53B4 = { 0x2B5, 0, 0, 0x2E0, 216, 0, &D_800A53A4 };
StagePoints D_800A53C4 = { 11, 2, &D_800A53B4 };
StagePoint D_800A53CC = { 0x2EC, 12, 5, 240, 0x1D8, 5, NULL };
StagePoint D_800A53DC = { 0x264, 0, 0, 0x2E0, 196, 0, &D_800A53CC };
StagePoints D_800A53EC = { 12, 1, &D_800A53DC };
StagePoint D_800A53F4 = { 0x2EC, 13, 4, 240, 0x1D8, 5, NULL };
StagePoint D_800A5404 = { 0x2CC, 0, 0, 0x2E0, 196, 0, &D_800A53F4 };
StagePoints D_800A5414 = { 13, 1, &D_800A5404 };
StagePoint D_800A541C = { 0x2ED, 14, 2, 224, 192, 5, NULL };
StagePoint D_800A542C = { 0x23A, 0, 0, 0x1C1, 0x37A, 0, &D_800A541C };
StagePoints D_800A543C = { 14, 1, &D_800A542C };
StagePoint D_800A5444 = { 0x2ED, 27, 2, 224, 192, 5, NULL };
StagePoint D_800A5454 = { 0x248, 0, 0, 0x2A0, 0x138, 0, &D_800A5444 };
StagePoints D_800A5464 = { 27, 1, &D_800A5454 };
StagePoint D_800A546C = { 0x2EE, 30, 1, 224, 0x240, 5, NULL };
StagePoint D_800A547C = { 0x24A, 0, 0, 0x2C0, 0x2A8, 0, &D_800A546C };
StagePoints D_800A548C = { 30, 1, &D_800A547C };
StagePoints *placePoints[] = {
    &D_800A4FB4, &D_800A4FDC, &D_800A5004, &D_800A502C,
    &D_800A5054, &D_800A507C, &D_800A50A4, &D_800A50CC,
    &D_800A50F4, &D_800A511C, &D_800A5144, &D_800A516C,
    &D_800A5194, &D_800A51BC, &D_800A51E4, &D_800A520C,
    &D_800A5234, &D_800A525C, &D_800A5284, &D_800A52AC,
    &D_800A52D4, &D_800A52FC, &D_800A5324, &D_800A534C,
    &D_800A5374, &D_800A539C, &D_800A53C4, &D_800A53EC,
    &D_800A5414, &D_800A543C, &D_800A5464, &D_800A548C,
    NULL,
};
Battle D_800A5518 = { 174, 10, 0x60080000 };
Battle D_800A5524 = { 174, 10, 0x60080000 };
Battle D_800A5530 = { 170, 10, 0x60080000 };
Battle D_800A553C = { 170, 10, 0x60080000 };
Battle D_800A5548 = { 170, 10, 0x60080000 };
Battle D_800A5554 = { 170, 10, 0x60080000 };
Battle D_800A5560 = { 170, 10, 0x60080000 };
Battle D_800A556C = { 170, 10, 0x60080000 };
BattleList D_800A5578 = {
    1,
    { &D_800A5518, &D_800A5524, &D_800A5530, &D_800A553C,
      &D_800A5548, &D_800A5554, &D_800A5560, &D_800A556C },
};
Battle D_800A559C = { 0, 0, 0x60040000 };
Battle D_800A55A8 = { 0, 0, 0x60040000 };
Battle D_800A55B4 = { 0, 0, 0x60040000 };
Battle D_800A55C0 = { 0, 0, 0x60040000 };
Battle D_800A55CC = { 0, 0, 0x60040000 };
Battle D_800A55D8 = { 0, 0, 0x60040000 };
Battle D_800A55E4 = { 0, 0, 0x60040000 };
Battle D_800A55F0 = { 0, 0, 0x60040000 };
BattleList D_800A55FC = {
    0,
    { &D_800A559C, &D_800A55A8, &D_800A55B4, &D_800A55C0,
      &D_800A55CC, &D_800A55D8, &D_800A55E4, &D_800A55F0 },
};
Battle D_800A5620 = { 0, 0, 0x60040000 };
Battle D_800A562C = { 0, 0, 0x60040000 };
Battle D_800A5638 = { 0, 0, 0x60040000 };
Battle D_800A5644 = { 0, 0, 0x60040000 };
Battle D_800A5650 = { 0, 0, 0x60040000 };
Battle D_800A565C = { 0, 0, 0x60040000 };
Battle D_800A5668 = { 0, 0, 0x60040000 };
Battle D_800A5674 = { 0, 0, 0x60040000 };
BattleList D_800A5680 = {
    0,
    { &D_800A5620, &D_800A562C, &D_800A5638, &D_800A5644,
      &D_800A5650, &D_800A565C, &D_800A5668, &D_800A5674 },
};
Battle D_800A56A4 = { 0, 0, 0x60040000 };
Battle D_800A56B0 = { 0, 0, 0x60040000 };
Battle D_800A56BC = { 0, 0, 0x60040000 };
Battle D_800A56C8 = { 0, 0, 0x60040000 };
Battle D_800A56D4 = { 0, 0, 0x60040000 };
Battle D_800A56E0 = { 0, 0, 0x60040000 };
Battle D_800A56EC = { 0, 0, 0x60040000 };
Battle D_800A56F8 = { 0, 0, 0x60040000 };
BattleList D_800A5704 = {
    0,
    { &D_800A56A4, &D_800A56B0, &D_800A56BC, &D_800A56C8,
      &D_800A56D4, &D_800A56E0, &D_800A56EC, &D_800A56F8 },
};
Battle D_800A5728 = { 174, 10, 0x60080000 };
Battle D_800A5734 = { 174, 10, 0x60080000 };
Battle D_800A5740 = { 170, 10, 0x60080000 };
Battle D_800A574C = { 170, 10, 0x60080000 };
Battle D_800A5758 = { 170, 10, 0x60080000 };
Battle D_800A5764 = { 110, 10, 0x60080000 };
Battle D_800A5770 = { 110, 10, 0x60080000 };
Battle D_800A577C = { 110, 10, 0x60080000 };
BattleList D_800A5788 = {
    1,
    { &D_800A5728, &D_800A5734, &D_800A5740, &D_800A574C,
      &D_800A5758, &D_800A5764, &D_800A5770, &D_800A577C },
};
Battle D_800A57AC = { 0, 0, 0x60040000 };
Battle D_800A57B8 = { 0, 0, 0x60040000 };
Battle D_800A57C4 = { 0, 0, 0x60040000 };
Battle D_800A57D0 = { 0, 0, 0x60040000 };
Battle D_800A57DC = { 0, 0, 0x60040000 };
Battle D_800A57E8 = { 0, 0, 0x60040000 };
Battle D_800A57F4 = { 0, 0, 0x60040000 };
Battle D_800A5800 = { 0, 0, 0x60040000 };
BattleList D_800A580C = {
    0,
    { &D_800A57AC, &D_800A57B8, &D_800A57C4, &D_800A57D0,
      &D_800A57DC, &D_800A57E8, &D_800A57F4, &D_800A5800 },
};
Battle D_800A5830 = { 0, 0, 0x60040000 };
Battle D_800A583C = { 0, 0, 0x60040000 };
Battle D_800A5848 = { 0, 0, 0x60040000 };
Battle D_800A5854 = { 0, 0, 0x60040000 };
Battle D_800A5860 = { 0, 0, 0x60040000 };
Battle D_800A586C = { 0, 0, 0x60040000 };
Battle D_800A5878 = { 0, 0, 0x60040000 };
Battle D_800A5884 = { 0, 0, 0x60040000 };
BattleList D_800A5890 = {
    0,
    { &D_800A5830, &D_800A583C, &D_800A5848, &D_800A5854,
      &D_800A5860, &D_800A586C, &D_800A5878, &D_800A5884 },
};
Battle D_800A58B4 = { 0, 0, 0x60040000 };
Battle D_800A58C0 = { 0, 0, 0x60040000 };
Battle D_800A58CC = { 0, 0, 0x60040000 };
Battle D_800A58D8 = { 0, 0, 0x60040000 };
Battle D_800A58E4 = { 0, 0, 0x60040000 };
Battle D_800A58F0 = { 0, 0, 0x60040000 };
Battle D_800A58FC = { 0, 0, 0x60040000 };
Battle D_800A5908 = { 0, 0, 0x60040000 };
BattleList D_800A5914 = {
    0,
    { &D_800A58B4, &D_800A58C0, &D_800A58CC, &D_800A58D8,
      &D_800A58E4, &D_800A58F0, &D_800A58FC, &D_800A5908 },
};
Battle D_800A5938 = { 174, 10, 0x60080000 };
Battle D_800A5944 = { 174, 10, 0x60080000 };
Battle D_800A5950 = { 170, 10, 0x60080000 };
Battle D_800A595C = { 170, 10, 0x60080000 };
Battle D_800A5968 = { 182, 10, 0x60080000 };
Battle D_800A5974 = { 182, 10, 0x60080000 };
Battle D_800A5980 = { 71, 10, 0x60080000 };
Battle D_800A598C = { 71, 10, 0x60080000 };
BattleList D_800A5998 = {
    1,
    { &D_800A5938, &D_800A5944, &D_800A5950, &D_800A595C,
      &D_800A5968, &D_800A5974, &D_800A5980, &D_800A598C },
};
Battle D_800A59BC = { 0, 0, 0x60040000 };
Battle D_800A59C8 = { 0, 0, 0x60040000 };
Battle D_800A59D4 = { 0, 0, 0x60040000 };
Battle D_800A59E0 = { 0, 0, 0x60040000 };
Battle D_800A59EC = { 0, 0, 0x60040000 };
Battle D_800A59F8 = { 0, 0, 0x60040000 };
Battle D_800A5A04 = { 0, 0, 0x60040000 };
Battle D_800A5A10 = { 0, 0, 0x60040000 };
BattleList D_800A5A1C = {
    0,
    { &D_800A59BC, &D_800A59C8, &D_800A59D4, &D_800A59E0,
      &D_800A59EC, &D_800A59F8, &D_800A5A04, &D_800A5A10 },
};
Battle D_800A5A40 = { 0, 0, 0x60040000 };
Battle D_800A5A4C = { 0, 0, 0x60040000 };
Battle D_800A5A58 = { 0, 0, 0x60040000 };
Battle D_800A5A64 = { 0, 0, 0x60040000 };
Battle D_800A5A70 = { 0, 0, 0x60040000 };
Battle D_800A5A7C = { 0, 0, 0x60040000 };
Battle D_800A5A88 = { 0, 0, 0x60040000 };
Battle D_800A5A94 = { 0, 0, 0x60040000 };
BattleList D_800A5AA0 = {
    0,
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
Battle D_800A5B48 = { 174, 10, 0x60080000 };
Battle D_800A5B54 = { 174, 10, 0x60080000 };
Battle D_800A5B60 = { 170, 10, 0x60080000 };
Battle D_800A5B6C = { 170, 10, 0x60080000 };
Battle D_800A5B78 = { 182, 10, 0x60080000 };
Battle D_800A5B84 = { 182, 10, 0x60080000 };
Battle D_800A5B90 = { 71, 10, 0x60080000 };
Battle D_800A5B9C = { 71, 10, 0x60080000 };
BattleList D_800A5BA8 = {
    1,
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
Battle D_800A5C50 = { 0, 0, 0x60040000 };
Battle D_800A5C5C = { 0, 0, 0x60040000 };
Battle D_800A5C68 = { 0, 0, 0x60040000 };
Battle D_800A5C74 = { 0, 0, 0x60040000 };
Battle D_800A5C80 = { 0, 0, 0x60040000 };
Battle D_800A5C8C = { 0, 0, 0x60040000 };
Battle D_800A5C98 = { 0, 0, 0x60040000 };
Battle D_800A5CA4 = { 0, 0, 0x60040000 };
BattleList D_800A5CB0 = {
    0,
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
Battle D_800A5D58 = { 174, 10, 0x60080000 };
Battle D_800A5D64 = { 170, 10, 0x60080000 };
Battle D_800A5D70 = { 110, 10, 0x60080000 };
Battle D_800A5D7C = { 110, 10, 0x60080000 };
Battle D_800A5D88 = { 182, 10, 0x60080000 };
Battle D_800A5D94 = { 182, 10, 0x60080000 };
Battle D_800A5DA0 = { 71, 10, 0x60080000 };
Battle D_800A5DAC = { 71, 10, 0x60080000 };
BattleList D_800A5DB8 = {
    1,
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
Battle D_800A5E60 = { 0, 0, 0x60040000 };
Battle D_800A5E6C = { 0, 0, 0x60040000 };
Battle D_800A5E78 = { 0, 0, 0x60040000 };
Battle D_800A5E84 = { 0, 0, 0x60040000 };
Battle D_800A5E90 = { 0, 0, 0x60040000 };
Battle D_800A5E9C = { 0, 0, 0x60040000 };
Battle D_800A5EA8 = { 0, 0, 0x60040000 };
Battle D_800A5EB4 = { 0, 0, 0x60040000 };
BattleList D_800A5EC0 = {
    0,
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
Battle D_800A5F68 = { 174, 10, 0x60080000 };
Battle D_800A5F74 = { 170, 10, 0x60080000 };
Battle D_800A5F80 = { 110, 10, 0x60080000 };
Battle D_800A5F8C = { 110, 10, 0x60080000 };
Battle D_800A5F98 = { 182, 10, 0x60080000 };
Battle D_800A5FA4 = { 182, 10, 0x60080000 };
Battle D_800A5FB0 = { 71, 10, 0x60080000 };
Battle D_800A5FBC = { 71, 10, 0x60080000 };
BattleList D_800A5FC8 = {
    1,
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
Battle D_800A6070 = { 0, 0, 0x60040000 };
Battle D_800A607C = { 0, 0, 0x60040000 };
Battle D_800A6088 = { 0, 0, 0x60040000 };
Battle D_800A6094 = { 0, 0, 0x60040000 };
Battle D_800A60A0 = { 0, 0, 0x60040000 };
Battle D_800A60AC = { 0, 0, 0x60040000 };
Battle D_800A60B8 = { 0, 0, 0x60040000 };
Battle D_800A60C4 = { 0, 0, 0x60040000 };
BattleList D_800A60D0 = {
    0,
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
Battle D_800A6178 = { 182, 10, 0x60080000 };
Battle D_800A6184 = { 182, 10, 0x60080000 };
Battle D_800A6190 = { 182, 10, 0x60080000 };
Battle D_800A619C = { 182, 10, 0x60080000 };
Battle D_800A61A8 = { 71, 10, 0x60080000 };
Battle D_800A61B4 = { 71, 10, 0x60080000 };
Battle D_800A61C0 = { 71, 10, 0x60080000 };
Battle D_800A61CC = { 71, 10, 0x60080000 };
BattleList D_800A61D8 = {
    1,
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
Battle D_800A6280 = { 0, 0, 0x60040000 };
Battle D_800A628C = { 0, 0, 0x60040000 };
Battle D_800A6298 = { 0, 0, 0x60040000 };
Battle D_800A62A4 = { 0, 0, 0x60040000 };
Battle D_800A62B0 = { 0, 0, 0x60040000 };
Battle D_800A62BC = { 0, 0, 0x60040000 };
Battle D_800A62C8 = { 0, 0, 0x60040000 };
Battle D_800A62D4 = { 0, 0, 0x60040000 };
BattleList D_800A62E0 = {
    0,
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
Battle D_800A6388 = { 182, 10, 0x60080000 };
Battle D_800A6394 = { 182, 10, 0x60080000 };
Battle D_800A63A0 = { 182, 10, 0x60080000 };
Battle D_800A63AC = { 182, 10, 0x60080000 };
Battle D_800A63B8 = { 71, 10, 0x60080000 };
Battle D_800A63C4 = { 71, 10, 0x60080000 };
Battle D_800A63D0 = { 71, 10, 0x60080000 };
Battle D_800A63DC = { 71, 10, 0x60080000 };
BattleList D_800A63E8 = {
    1,
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
Battle D_800A6490 = { 0, 0, 0x60040000 };
Battle D_800A649C = { 0, 0, 0x60040000 };
Battle D_800A64A8 = { 0, 0, 0x60040000 };
Battle D_800A64B4 = { 0, 0, 0x60040000 };
Battle D_800A64C0 = { 0, 0, 0x60040000 };
Battle D_800A64CC = { 0, 0, 0x60040000 };
Battle D_800A64D8 = { 0, 0, 0x60040000 };
Battle D_800A64E4 = { 0, 0, 0x60040000 };
BattleList D_800A64F0 = {
    0,
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
Battle D_800A6598 = { 174, 10, 0x60080000 };
Battle D_800A65A4 = { 174, 10, 0x60080000 };
Battle D_800A65B0 = { 170, 10, 0x60080000 };
Battle D_800A65BC = { 170, 10, 0x60080000 };
Battle D_800A65C8 = { 170, 10, 0x60080000 };
Battle D_800A65D4 = { 110, 10, 0x60080000 };
Battle D_800A65E0 = { 110, 10, 0x60080000 };
Battle D_800A65EC = { 110, 10, 0x60080000 };
BattleList D_800A65F8 = {
    2,
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
Battle D_800A66A0 = { 0, 0, 0x60040000 };
Battle D_800A66AC = { 0, 0, 0x60040000 };
Battle D_800A66B8 = { 0, 0, 0x60040000 };
Battle D_800A66C4 = { 0, 0, 0x60040000 };
Battle D_800A66D0 = { 0, 0, 0x60040000 };
Battle D_800A66DC = { 0, 0, 0x60040000 };
Battle D_800A66E8 = { 0, 0, 0x60040000 };
Battle D_800A66F4 = { 0, 0, 0x60040000 };
BattleList D_800A6700 = {
    0,
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
Battle D_800A67A8 = { 182, 10, 0x60080000 };
Battle D_800A67B4 = { 182, 10, 0x60080000 };
Battle D_800A67C0 = { 182, 10, 0x60080000 };
Battle D_800A67CC = { 182, 10, 0x60080000 };
Battle D_800A67D8 = { 71, 10, 0x60080000 };
Battle D_800A67E4 = { 71, 10, 0x60080000 };
Battle D_800A67F0 = { 71, 10, 0x60080000 };
Battle D_800A67FC = { 71, 10, 0x60080000 };
BattleList D_800A6808 = {
    2,
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
Battle D_800A68B0 = { 0, 0, 0x60040000 };
Battle D_800A68BC = { 0, 0, 0x60040000 };
Battle D_800A68C8 = { 0, 0, 0x60040000 };
Battle D_800A68D4 = { 0, 0, 0x60040000 };
Battle D_800A68E0 = { 0, 0, 0x60040000 };
Battle D_800A68EC = { 0, 0, 0x60040000 };
Battle D_800A68F8 = { 0, 0, 0x60040000 };
Battle D_800A6904 = { 0, 0, 0x60040000 };
BattleList D_800A6910 = {
    0,
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
Battle D_800A69B8 = { 110, 10, 0x60080000 };
Battle D_800A69C4 = { 110, 10, 0x60080000 };
Battle D_800A69D0 = { 110, 10, 0x60080000 };
Battle D_800A69DC = { 110, 10, 0x60080000 };
Battle D_800A69E8 = { 110, 10, 0x60080000 };
Battle D_800A69F4 = { 110, 10, 0x60080000 };
Battle D_800A6A00 = { 110, 10, 0x60080000 };
Battle D_800A6A0C = { 110, 10, 0x60080000 };
BattleList D_800A6A18 = {
    1,
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
Battle D_800A6AC0 = { 0, 0, 0x60040000 };
Battle D_800A6ACC = { 0, 0, 0x60040000 };
Battle D_800A6AD8 = { 0, 0, 0x60040000 };
Battle D_800A6AE4 = { 0, 0, 0x60040000 };
Battle D_800A6AF0 = { 0, 0, 0x60040000 };
Battle D_800A6AFC = { 0, 0, 0x60040000 };
Battle D_800A6B08 = { 0, 0, 0x60040000 };
Battle D_800A6B14 = { 0, 0, 0x60040000 };
BattleList D_800A6B20 = {
    0,
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
Battle D_800A6BC8 = { 182, 10, 0x60080000 };
Battle D_800A6BD4 = { 182, 10, 0x60080000 };
Battle D_800A6BE0 = { 182, 10, 0x60080000 };
Battle D_800A6BEC = { 182, 10, 0x60080000 };
Battle D_800A6BF8 = { 71, 10, 0x60080000 };
Battle D_800A6C04 = { 71, 10, 0x60080000 };
Battle D_800A6C10 = { 71, 10, 0x60080000 };
Battle D_800A6C1C = { 71, 10, 0x60080000 };
BattleList D_800A6C28 = {
    1,
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
Battle D_800A6CD0 = { 0, 0, 0x60040000 };
Battle D_800A6CDC = { 0, 0, 0x60040000 };
Battle D_800A6CE8 = { 0, 0, 0x60040000 };
Battle D_800A6CF4 = { 0, 0, 0x60040000 };
Battle D_800A6D00 = { 0, 0, 0x60040000 };
Battle D_800A6D0C = { 0, 0, 0x60040000 };
Battle D_800A6D18 = { 0, 0, 0x60040000 };
Battle D_800A6D24 = { 0, 0, 0x60040000 };
BattleList D_800A6D30 = {
    0,
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
Battle D_800A6DD8 = { 174, 10, 0x60080000 };
Battle D_800A6DE4 = { 174, 10, 0x60080000 };
Battle D_800A6DF0 = { 170, 10, 0x60080000 };
Battle D_800A6DFC = { 170, 10, 0x60080000 };
Battle D_800A6E08 = { 170, 10, 0x60080000 };
Battle D_800A6E14 = { 170, 10, 0x60080000 };
Battle D_800A6E20 = { 170, 10, 0x60080000 };
Battle D_800A6E2C = { 170, 10, 0x60080000 };
BattleList D_800A6E38 = {
    4,
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
Battle D_800A6EE0 = { 0, 0, 0x60040000 };
Battle D_800A6EEC = { 0, 0, 0x60040000 };
Battle D_800A6EF8 = { 0, 0, 0x60040000 };
Battle D_800A6F04 = { 0, 0, 0x60040000 };
Battle D_800A6F10 = { 0, 0, 0x60040000 };
Battle D_800A6F1C = { 0, 0, 0x60040000 };
Battle D_800A6F28 = { 0, 0, 0x60040000 };
Battle D_800A6F34 = { 0, 0, 0x60040000 };
BattleList D_800A6F40 = {
    0,
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
Battle D_800A6FE8 = { 174, 10, 0x60080000 };
Battle D_800A6FF4 = { 174, 10, 0x60080000 };
Battle D_800A7000 = { 170, 10, 0x60080000 };
Battle D_800A700C = { 170, 10, 0x60080000 };
Battle D_800A7018 = { 170, 10, 0x60080000 };
Battle D_800A7024 = { 170, 10, 0x60080000 };
Battle D_800A7030 = { 170, 10, 0x60080000 };
Battle D_800A703C = { 170, 10, 0x60080000 };
BattleList D_800A7048 = {
    2,
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
Battle D_800A70F0 = { 0, 0, 0x60040000 };
Battle D_800A70FC = { 0, 0, 0x60040000 };
Battle D_800A7108 = { 0, 0, 0x60040000 };
Battle D_800A7114 = { 0, 0, 0x60040000 };
Battle D_800A7120 = { 0, 0, 0x60040000 };
Battle D_800A712C = { 0, 0, 0x60040000 };
Battle D_800A7138 = { 0, 0, 0x60040000 };
Battle D_800A7144 = { 0, 0, 0x60040000 };
BattleList D_800A7150 = {
    0,
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
Battle D_800A71F8 = { 174, 10, 0x60080000 };
Battle D_800A7204 = { 174, 10, 0x60080000 };
Battle D_800A7210 = { 170, 10, 0x60080000 };
Battle D_800A721C = { 170, 10, 0x60080000 };
Battle D_800A7228 = { 182, 10, 0x60080000 };
Battle D_800A7234 = { 182, 10, 0x60080000 };
Battle D_800A7240 = { 71, 10, 0x60080000 };
Battle D_800A724C = { 71, 10, 0x60080000 };
BattleList D_800A7258 = {
    1,
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
Battle D_800A7300 = { 0, 0, 0x60040000 };
Battle D_800A730C = { 0, 0, 0x60040000 };
Battle D_800A7318 = { 0, 0, 0x60040000 };
Battle D_800A7324 = { 0, 0, 0x60040000 };
Battle D_800A7330 = { 0, 0, 0x60040000 };
Battle D_800A733C = { 0, 0, 0x60040000 };
Battle D_800A7348 = { 0, 0, 0x60040000 };
Battle D_800A7354 = { 0, 0, 0x60040000 };
BattleList D_800A7360 = {
    0,
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
FieldBattles stageBattles[] = {
    { 234, 1, 0, { &D_800A5578, &D_800A55FC, &D_800A5680, &D_800A5704 } },
    { 240, 2, 0, { &D_800A5788, &D_800A580C, &D_800A5890, &D_800A5914 } },
    { 245, 3, 0, { &D_800A5998, &D_800A5A1C, &D_800A5AA0, &D_800A5B24 } },
    { 250, 4, 0, { &D_800A5BA8, &D_800A5C2C, &D_800A5CB0, &D_800A5D34 } },
    { 256, 5, 0, { &D_800A5DB8, &D_800A5E3C, &D_800A5EC0, &D_800A5F44 } },
    { 263, 6, 0, { &D_800A5FC8, &D_800A604C, &D_800A60D0, &D_800A6154 } },
    { 271, 8, 0, { &D_800A61D8, &D_800A625C, &D_800A62E0, &D_800A6364 } },
    { 278, 9, 0, { &D_800A63E8, &D_800A646C, &D_800A64F0, &D_800A6574 } },
    { 283, 10, 0, { &D_800A65F8, &D_800A667C, &D_800A6700, &D_800A6784 } },
    { 288, 11, 0, { &D_800A6808, &D_800A688C, &D_800A6910, &D_800A6994 } },
    { 294, 12, 0, { &D_800A6A18, &D_800A6A9C, &D_800A6B20, &D_800A6BA4 } },
    { 300, 13, 0, { &D_800A6C28, &D_800A6CAC, &D_800A6D30, &D_800A6DB4 } },
    { 304, 14, 0, { &D_800A6E38, &D_800A6EBC, &D_800A6F40, &D_800A6FC4 } },
    { 355, 27, 0, { &D_800A7048, &D_800A70CC, &D_800A7150, &D_800A71D4 } },
    { 374, 30, 0, { &D_800A7258, &D_800A72DC, &D_800A7360, &D_800A73E4 } },
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
    { 0x140, 0x100, 0x14C, 0x140, 0x30, 0x40, 0x150, 0x1FE },
    { 0x140, 0x100, 0x14C, 0x100, 0x30, 0, 0x160, 0x1FE },
    { 0x140, 0x100, 0x160, 0x100, 0x80, 0, 0x170, 0x1FE },
};
FieldTalk D_800A766C[] = {
    { NULL, NULL, 0x3AA },
    { NULL, NULL, 0 },
};
FieldTalk D_800A7684[] = {
    { NULL, NULL, 0x3AC },
    { NULL, NULL, 0 },
};
FieldTalk D_800A769C[] = {
    { NULL, NULL, 0x3AF },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76B4[] = {
    { NULL, NULL, 0x3AB },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76CC[] = {
    { NULL, NULL, 0x3AD },
    { NULL, NULL, 0 },
};
FieldTalk D_800A76E4[] = {
    { NULL, NULL, 0x3AE },
    { NULL, NULL, 0 },
};
u16 D_800A76FC[] = { 0x7E00, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A7708[] = { 0x7E01, 1, 0x7E20, 1, 0xFFFF };
u16 D_800A7714[] = { 0x7E08, 1, 0x7E20, 1, 0xFFFF };
u16 D_800A7720[] = { 0x7E01, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A772C[] = { 0x7E02, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A7738[] = { 0x7E07, 1, 0x7E1F, 1, 0xFFFF };
u16 D_800A7744[] = { 0x7E1F, 1, 8, 0, 0xFFFF };
u16 D_800A7750[] = { 0x7E1E, 1, 9, 0, 0xFFFF };
u16 D_800A775C[] = { 0x7E1F, 1, 9, 0, 0xFFFF };
u16 D_800A7768[] = { 0x7E20, 1, 9, 0, 0xFFFF };
u16 D_800A7774[] = { 0x7E01, 1, 0xA, 0, 0xFFFF };
u16 D_800A7780[] = { 0x7E02, 1, 0xA, 0, 0xFFFF };
u16 D_800A778C[] = { 0x7E04, 1, 0xA, 0, 0xFFFF };
u16 D_800A7798[] = { 0x7E05, 1, 0xA, 0, 0xFFFF };
u16 D_800A77A4[] = { 0x7E07, 1, 0xA, 0, 0xFFFF };
u16 D_800A77B0[] = { 0x7E08, 1, 0xA, 0, 0xFFFF };
u16 D_800A77BC[] = { 0x7E0A, 1, 0xA, 0, 0xFFFF };
u16 D_800A77C8[] = { 0x7E0C, 1, 0xA, 0, 0xFFFF };
u16 D_800A77D4[] = { 0x7E1A, 1, 0xA, 0, 0xFFFF };
u16 D_800A77E0[] = { 0x7E1D, 1, 0xA, 0, 0xFFFF };
FieldActorEntry D_800A77EC = { D_800A76FC, D_800A766C, 0x42, 4, 104, 272, 7 };
FieldActorEntry D_800A7800 = { D_800A7708, D_800A7684, 0x42, 4, 104, 272, 7 };
FieldActorEntry D_800A7814 = { D_800A7714, D_800A769C, 0x42, 4, 104, 272, 7 };
FieldActorEntry D_800A7828 = { D_800A7720, D_800A76B4, 0xB6, 5, 104, 272, 7 };
FieldActorEntry D_800A783C = { D_800A772C, D_800A76CC, 0xB6, 5, 104, 272, 7 };
FieldActorEntry D_800A7850 = { D_800A7738, D_800A76E4, 0xB6, 5, 104, 272, 7 };
FieldActorEntry D_800A7864 = { NULL, NULL, 0x146, 6, 0, 0, 0 };
FieldActorEntry D_800A7878 = { D_800A7744, NULL, 0x148, 7, 368, 392, 1 };
FieldActorEntry D_800A788C = { D_800A7750, NULL, 0x15F, 8, 432, 312, 1 };
FieldActorEntry D_800A78A0 = { D_800A775C, NULL, 0x15F, 8, 272, 344, 1 };
FieldActorEntry D_800A78B4 = { D_800A7768, NULL, 0x15F, 8, 376, 340, 1 };
FieldActorEntry D_800A78C8 = { D_800A7774, NULL, 0x160, 9, 528, 264, 1 };
FieldActorEntry D_800A78DC = { D_800A7780, NULL, 0x160, 9, 480, 288, 1 };
FieldActorEntry D_800A78F0 = { D_800A778C, NULL, 0x160, 9, 416, 368, 1 };
FieldActorEntry D_800A7904 = { D_800A7798, NULL, 0x160, 9, 528, 264, 1 };
FieldActorEntry D_800A7918 = { D_800A77A4, NULL, 0x160, 9, 312, 364, 1 };
FieldActorEntry D_800A792C = { D_800A77B0, NULL, 0x160, 9, 224, 320, 1 };
FieldActorEntry D_800A7940 = { D_800A77BC, NULL, 0x160, 9, 312, 364, 1 };
FieldActorEntry D_800A7954 = { D_800A77C8, NULL, 0x160, 9, 376, 340, 1 };
FieldActorEntry D_800A7968 = { D_800A77D4, NULL, 0x160, 9, 528, 264, 1 };
FieldActorEntry D_800A797C = { D_800A77E0, NULL, 0x160, 9, 224, 320, 1 };
FieldActorEntry *stageActors[] = {
    &D_800A77EC,
    &D_800A7800,
    &D_800A7814,
    &D_800A7828,
    &D_800A783C,
    &D_800A7850,
    &D_800A7864,
    &D_800A7878,
    &D_800A788C,
    &D_800A78A0,
    &D_800A78B4,
    &D_800A78C8,
    &D_800A78DC,
    &D_800A78F0,
    &D_800A7904,
    &D_800A7918,
    &D_800A792C,
    &D_800A7940,
    &D_800A7954,
    &D_800A7968,
    &D_800A797C,
    NULL,
};
StageTile stageObjects[] = {
    { 1, 0, 0xFF, 4, 0x32, 2, 0, 7, 0x14, 0, 152, 140, 253, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
StageSlot stageSlots[] = {
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E9, 0xB0, 0xF8, 4, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 1, 0x2E9, 0x240, 0xF0, 5, 0, 0, 0 },
    { { { 0xFFFF, 0 }, { 0xFFFF, 0 } }, 0, 0, 0, 0, 0, 0, 0, 0 },
};
void (*stageFuncs[])(void) = {
    setupStage,
};
