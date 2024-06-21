#include "init.h"

void init() {
	InitGraph();

	GH[0] = LoadGraph("res/img/player.png");
	GH[1] = LoadGraph("res/img/tp.png");
	GH[2] = LoadGraph("res/img/ui/game/flame.png");
	GH[3] = LoadGraph("res/img/tp.png");
	GH[4] = LoadGraph("res/img/hitpoint.png");
	GH[5] = LoadGraph("res/img/bit.png");
	GH[6] = LoadGraph("res/img/title.png");
	GH[8] = LoadGraph("res/img/cursor.png");
	GH[9] = LoadGraph("res/img/textbox.png");

	TGH[0] = LoadGraph("res/img/ui/title/start_str.png");
	TGH[1] = LoadGraph("res/img/ui/title/practice_str.png");
	TGH[2] = LoadGraph("res/img/ui/title/hiscore_str.png");
	TGH[3] = LoadGraph("res/img/ui/title/option_str.png");
	TGH[4] = LoadGraph("res/img/ui/title/exit_str.png");

	OGH[0] = LoadGraph("res/img/ui/option/bgm_str.png");
	OGH[1] = LoadGraph("res/img/ui/option/se_str.png");
	OGH[2] = LoadGraph("res/img/ui/option/keyconfig_str.png");
	OGH[3] = LoadGraph("res/img/ui/option/default_str.png");
	OGH[4] = LoadGraph("res/img/ui/option/exit_str.png");

	EGH[0] = LoadGraph("res/img/enemy/a.png");

	BOSSGH[0] = LoadGraph("res/img/enemy/a.png");

	BBGH[0] = LoadGraph("res/img/bullet/a_back.png");
	BFGH[0] = LoadGraph("res/img/bullet/a_front.png");
	BBGH[1] = LoadGraph("res/img/bullet/b_back.png");
	BFGH[1] = LoadGraph("res/img/bullet/b_front.png");
	BBGH[2] = LoadGraph("res/img/bullet/c_back.png");
	BFGH[2] = LoadGraph("res/img/bullet/c_front.png");
	BBGH[99] = LoadGraph("res/img/bullet/laser.png");

	BGGH[2] = LoadGraph("res/img/bg/2.png");

	EFGH[0] = LoadGraph("res/img/effect/maru.png");
	EFGH[1] = LoadGraph("res/img/effect/line.png");

	sound_init();

	textlist[0] = "�N�Ȃ̂ł�������Ȓ���������";
	textlist[1] = "����";
	textlist[2] = "����N����Ȃ̂ł�";
	textlist[3] = "����������񂾂�`";
	textlist[4] = "����m��˂���Ȃ̂ł�";
	textlist[5] = "��芸���������ǂ��H";
	textlist[6] = "�����͖�����Ȃ̂ł���B";
	textlist[7] = "����ǂ�����";
	textlist[8] = "�Ȃ񂩂������������悤�ȉ�b�������悤�ȋC��...";
	textlist[9] = "��芸�������ʂ��悢�B";

	bg1.x = 0;
	bg1.y = 0;
	bg1.speed = 5;
	bg2.x = 0;
	bg2.y = -990;
	bg2.speed = 5;

	txt.flag = 0;

	Fps_Initialize();

	SetFontSize(30);
	SetDrawScreen(DX_SCREEN_BACK);
}

void sound_init() {
	InitSoundMem();

	SSH[0] = LoadSoundMem("res/snd/se/Death.wav");
	SSH[1] = LoadSoundMem("res/snd/se/Bomb.wav");
	SSH[2] = LoadSoundMem("res/snd/se/Select.wav");
	ChangeVolumeSoundMem(255 * save.se_vol / 100, SSH[0]);
	ChangeVolumeSoundMem(255 * save.se_vol / 100, SSH[1]);
	ChangeVolumeSoundMem(255 * save.se_vol / 100, SSH[2]);

	BSH[0] = LoadSoundMem("res/snd/bgm/00.wav");
	SetLoopPosSoundMem(4000, BSH[0]);
	ChangeVolumeSoundMem(255 * save.bgm_vol / 100, BSH[0]);
	BSH[1] = LoadSoundMem("res/snd/bgm/01.wav");
	SetLoopPosSoundMem(19200, BSH[1]);
	ChangeVolumeSoundMem(255 * save.bgm_vol / 100, BSH[1]);
	BSH[2] = LoadSoundMem("res/snd/bgm/02.wav");
	SetLoopPosSoundMem(24000, BSH[2]);
	ChangeVolumeSoundMem(255 * save.bgm_vol / 100, BSH[2]);
}