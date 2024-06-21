#include "option.h"

int right_keypush_flag = 0;
int left_keypush_flag = 0;

void option() {
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
			case 2:
				break;
			case 3:
				save.bgm_vol = 80;
				save.se_vol = 60;
				break;
			case 4:
				select_num = 0;
				title_flag = 0;
				break;
			}
		}
	}
	else {
		z_keypush_flag = 0;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
		if (right_keypush_flag == 0) {
			right_keypush_flag = 1;
			switch (select_num) {
			case 0:
				if (save.bgm_vol < 100) {
					save.bgm_vol += 5;
					sound_init();
				}
				break;
			case 1:
				if (save.se_vol < 100) {
					save.se_vol += 5;
					sound_init();
					PlaySoundMem(SSH[0], DX_PLAYTYPE_BACK);
				}
				break;
			}
		}
	}
	else {
		right_keypush_flag = 0;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
		if (left_keypush_flag == 0) {
			left_keypush_flag = 1;
			switch (select_num) {
			case 0:
				if (save.bgm_vol > 0) {
					save.bgm_vol -= 5;
					sound_init();
				}
				break;
			case 1:
				if (save.se_vol > 0) {
					save.se_vol -= 5;
					sound_init();
					PlaySoundMem(SSH[0], DX_PLAYTYPE_BACK);
				}
				break;
			}
		}
	}
	else {
		left_keypush_flag = 0;
	}
	DrawGraph(0, 0, GH[6], TRUE);
	DrawGraph(0, 0, OGH[select_num], TRUE);
	SetFontSize(60);
	DrawFormatString((1280 - GetDrawStringWidth(std::to_string(save.bgm_vol).c_str(), strlen(std::to_string(save.bgm_vol).c_str()))) / 2, 250, GetColor(128, 128, 128), "%d", save.bgm_vol);
	DrawFormatString((1280 - GetDrawStringWidth(std::to_string(save.se_vol).c_str(), strlen(std::to_string(save.se_vol).c_str()))) / 2, 450, GetColor(128, 128, 128), "%d", save.se_vol);
}