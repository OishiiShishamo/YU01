#include "title.h"

void title() {
	if (CheckHitKey(KEY_INPUT_UP) == 1) {
		if (up_keypush_flag == 0) {
			up_keypush_flag = 1;
			select_num--;
			PlaySoundMem(SSH[2], DX_PLAYTYPE_BACK);
			if (select_num == -1)select_num = 4;
		}
	}
	else {
		up_keypush_flag = 0;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
		if (down_keypush_flag == 0) {
			down_keypush_flag = 1;
			select_num++;
			PlaySoundMem(SSH[2], DX_PLAYTYPE_BACK);
			if (select_num == 5)select_num = 0;
		}
	}
	else {
		down_keypush_flag = 0;
	}
	if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
		if (z_keypush_flag == 0) {
			z_keypush_flag = 1;
			switch (select_num) {
			case 0:
				stage = 1;
				boss_flag = 0;
				bgm_num = 1;
				PlaySoundMem(SSH[2], DX_PLAYTYPE_BACK);
				f = 0;
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				select_num = 0;
				title_flag = 1;
				break;
			case 4:
				DxLib_End();
				break;
			}
		}
	}
	else {
		z_keypush_flag = 0;
	}
	DrawGraph(0, 0, GH[6], TRUE);
	DrawGraph(0, 0, TGH[select_num], TRUE);
	/*switch (select_num) {
	case 0:
		DrawRotaGraph(925, 600, 1.0, 0.0, GH[8], TRUE);
		break;
	case 1:
		DrawRotaGraph(925, 680, 1.0, 0.0, GH[8], TRUE);
		break;
	case 2:
		DrawRotaGraph(925, 760, 1.0, 0.0, GH[8], TRUE);
		break;
	case 3:
		DrawRotaGraph(925, 830, 1.0, 0.0, GH[8], TRUE);
		break;
	case 4:
		DrawRotaGraph(925, 910, 1.0, 0.0, GH[8], TRUE);
		break;
	}*/
}