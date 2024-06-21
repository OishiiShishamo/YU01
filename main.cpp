#include "main.h"

FILE* fp;

int f = 0;

int stage = 0;
int GH[100];
int TGH[100];
int OGH[100];
int EGH[100];
int BOSSGH[5];
int EFGH[100];
int BBGH[100];
int BFGH[100];
int BGGH[10];
int SSH[20];
int BSH[20];
int title_flag = 0;
double slow = 3;
double fast = 7;
int in = 0;
long score = 0;
char scoree[12] = "";
long combo = 0;
int cg = 0;
int playerr = 2;
int bomb = 3;
double tmp = 0;
int count = 0;
double bitangle = 0;
int text_count = 0;
int z_keypush_flag = 0;
int up_keypush_flag = 0;
int down_keypush_flag = 0;
std::string textlist[100];
int boss_flag = 0;
int bgm_num = 0;
int select_num = 0;
unsigned int thread_num = std::thread::hardware_concurrency();

struct Player p;
std::vector<Enemy> e;
std::vector<ToothPick> t;
std::vector<Bullet> b;
std::vector<Laser> l;
struct BackGround bg1;
struct BackGround bg2;
struct TextBox txt;
struct SaveData save;
struct Boss boss;
struct Bomb bo;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow) {
	setlocale(LC_ALL, "Japanese");
	SetOutApplicationLogValidFlag(FALSE);
	SetGraphMode(1280, 960, 32);
	SetUseTransColor(FALSE);
	SetMainWindowClassName("YU01");
	fopen_s(&fp, "score.dat", "rb+");
	if (fp == 0) {
		fopen_s(&fp, "score.dat", "w+");
		fwrite(&save, sizeof(save), 1, fp);
		fclose(fp);
		fopen_s(&fp, "score.dat", "rb+");
	}
	fread(&save, sizeof(save), 1, fp);
	fclose(fp);
	if (save.window_mode == 1) {
		ChangeWindowMode(TRUE);
	}
	else {
		ChangeWindowMode(FALSE);
	}
	SetWindowText("–²Œ»’´Œƒâ");
	if (DxLib_Init() == -1) {
		return -1;
	}

	init();

	while (TRUE) {
		Fps_Update();
		bgm();
		if (CheckHitKey(KEY_INPUT_F11) == 1) {
			if (save.window_mode == 1) {
				save.window_mode = 0;
				ChangeWindowMode(FALSE);
				init();
			}
			else {
				save.window_mode = 1;
				ChangeWindowMode(TRUE);
				init();
			}
		}
		switch (stage) {
		case 0:
			f++;
			switch (title_flag) {
			case 0:
				title();
				break;
			case 1:
				option();
				break;
			}
			function();
			break;
		case 1:
			f++;
			bitangle += ICHIDO * 5;
			if (in > 0)in--;
			ClearDrawScreen();
			background();
			ToothPickFunc();
			PlayerMove(fast, slow);
			PlayerDraw();
			bomber();
			function();
			MoveEnemy();
			MoveBullet();
			DrawEnemy();
			DrawBullet();
			LaserFunc();
			function2();
			comboo();
			ui();
			textbox();
			break;
		}
		if (CheckHitKey(KEY_INPUT_LSHIFT) == 1) {
			DrawRotaGraph(p.x, p.y, 1.0, 0.0, GH[4], TRUE);
		}
		Fps_Draw();
		Fps_Wait();
		ScreenFlip();
		if (ProcessMessage() == -1) {
			fopen_s(&fp, "score.dat", "w+");
			fwrite(&save, sizeof(save), 1, fp);
			fclose(fp);
			break;
		}
		if (CheckHitKey(KEY_INPUT_P) == 1) {
			SaveDrawScreen(0, 0, 1280, 960, "ScreenShot.bmp");
		}
		if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
			if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1)playerr = 2147483647;
		}
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			fopen_s(&fp, "score.dat", "w+");
			fwrite(&save, sizeof(save), 1, fp);
			fclose(fp);
			break;
		}
//		Sleep(1000 / 60 * 9);
	}
	DxLib_End();
	return 0;
}
int hitcheck(int x, int y, int size) {
	if (range(y, p.y, x, p.x) <= size / 2) {
		return 1;
	}
	else {
		return 0;
	}
}
void bomber() {
	if (CheckHitKey(KEY_INPUT_X) == 1) {
		if (bomb >= 1 && bo.time <= 0) {
			PlaySoundMem(SSH[1], DX_PLAYTYPE_BACK);
			bo.time = 120;
			in = 120;
			bomb--;
		}
	}
	bo.time--;
	if (bo.time >= 1) {
		for (int i = 0; i < b.size(); i++) {
			score += 10;
			if (save.hiscore < score)save.hiscore = score;
			b.erase(b.begin() + i);
		}
		for (int i = 0; i < e.size(); i++) {
			score += 100;
			if (save.hiscore < score)save.hiscore = score;
			e.erase(e.begin() + i);
		}
	}
}
void gameover() {

}
void ehit() {
	combo++;
	cg -= 20;
	if (cg <= 0) {
		cg = 0;
	}
	if (combo % 1000 == 0) {
		playerr++;
	}
	if (combo >= 1000) {
		score += 100;
		if (save.hiscore < score)save.hiscore = score;
	}
	else {
		score += (combo);
		if (save.hiscore < score)save.hiscore = score;
	}
}
void phit() {
	if (in <= 0) {
		PlaySoundMem(SSH[0], DX_PLAYTYPE_BACK);
		in = 160;
		bomb = 3;
		playerr--;
		if (playerr < 0) {
			gameover();
		}
	}
}
void comboo() {
	cg++;
	if (cg >= 60) {
		combo = 0;
	}
}
void bit(double x, double y, int type, int pattern, double angle1, double angle2, int size, double speed1, double speed2, double curve1, double curve2, int curveframe1, int curveframe2, int curveflag1, int curveflag2, int hp, int changeframe) {

}
void ui() {
	DrawGraph(0, 0, GH[2], TRUE);
	if (save.hiscore != 0) {
		DrawFormatString(1100, 60, GetColor(255, 255, 255), "%d0", save.hiscore);
	}
	else {
		DrawFormatString(1100, 60, GetColor(255, 255, 255), "%d", save.hiscore);
	}
	if (score != 0) {
		DrawFormatString(1100,120, GetColor(255, 255, 255), "%d0", score);
	}
	else {
		DrawFormatString(1100, 120, GetColor(255, 255, 255), "%d", score);
	}
	DrawFormatString(1100, 180, GetColor(255, 255, 255), "%d", combo);
	DrawFormatString(1100, 240, GetColor(255, 255, 255), "%d", playerr);
	DrawFormatString(1100, 300, GetColor(255, 255, 255), "%d", bomb);
}
void function() {
	switch (stage) {
	case 0:
		bgm_num = 0;
		break;
	case 1:
		if (boss_flag == 0) {
			if (f >= 60 && f <= 100 && f % 10 == 0)enemy(MIGI, UE + 50, 0, 0, 1, 5, 0, 0);
			if (f >= 130 && f <= 170 && f % 10 == 0)enemy(HIDARI, UE + 50, 0, 0, 1, 6, 0, 0);
			if (f >= 200 && f <= 210 && f % 5 == 0) {
				enemy(MIGI, UE + 50, 0, 0, 1, 9, 0, 1);
				enemy(HIDARI, UE + 50, 0, 0, 1, 10, 0, 1);
			}
			if (f >= 300 && f <= 600 && f % 3 == 0)barrage(CENTERX, CENTERY, 2, YELLOW, 3, ICHIDO * f * 1.5, 30, 3, 0, 0, 360, 4, 0, 0, 0);
			if (f >= 600 && f <= 720 && f % 4 == 0) {
				enemy(MIGI, UE + 300, 0, 0, 1, 11, 0, 1);
				enemy(HIDARI, UE + 300, 0, 0, 1, 12, 0, 1);
			}
			if (f >= 750 && f <= 800) {
				for (int i = 5; i <= 10; i++) {
					barrage(CENTERX, CENTERY, 0, RED, 3, ICHIDO * f / 10, 40, i, 0, 0, 360, 4, 0, 0, 0);
				}
			}
			if (f >= 800 && f <= 850) {
				for (int i = 5; i <= 10; i++) {
					barrage(CENTERX, CENTERY, 0, RED, 3, -ICHIDO * f / 10, 40, i, 0, 0, 360, 4, 0, 0, 0);
				}
			}
			if (f >= 850 && f <= 900) {
				for (int i = 5; i <= 10; i++) {
					barrage(CENTERX, CENTERY, 0, RED, 3, ICHIDO * f / 10, 40, i, 0, 0, 360, 4, 0, 0, 0);
				}
			}
			if (f >= 900 && f <= 950) {
				for (int i = 5; i <= 10; i++) {
					barrage(CENTERX, CENTERY, 0, RED, 3, -ICHIDO * f / 10, 40, i, 0, 0, 360, 4, 0, 0, 0);
				}
			}
			if (f >= 950 && f <= 2750) {
				enemy(MIGI, UE + 50, 0, 0, 1, 9, 0, 1);
				enemy(HIDARI, UE + 50, 0, 0, 1, 10, 0, 1);
			}
			if (f >= 2750 && f <= 3600 && f % 4 == 0) {
				barrage(CENTERX, CENTERY, 0, RED, 3, sin(f * 0.02) * 5, 30, 5.0, 0, 0, 360, 4, 0, 0, 0);
			}
			if (f >= 3600 && f <= 3900 && f % 3 == 0) {
				barrage(CENTERX, CENTERY, 1, BLUE, 3, sin(f * 0.01) * 5, 40, 10.0, -ICHIDO * 30, 30, 360, 4, 0, 0, 0);
				barrage(CENTERX, CENTERY, 1, RED, 3, ICHIDO * f, 4, 10.0, 0.0, 0, 360, 4, 0, 0, 0);
				barrage(CENTERX, CENTERY, 1, RED, 3, -ICHIDO * f, 4, 10.0, 0.0, 0, 360, 4, 0, 0, 0);
			}
			if (f >= 3900 && f <= 5000 && f % 1 == 0) {
				if (f <= 4500) {
					barrage(CENTERX, CENTERY, 0, BLUE, 3, ICHIDO * f * 10, 4, 5, ICHIDO * 2, 2, 360, 4, 1, 0, 0);
				}
				if (f >= 4500) {
					barrage(CENTERX, CENTERY, 0, BLUE, 3, ICHIDO * f * 10, 4, 5, ICHIDO * 2, 2, 360, 4, 1, 0, 0);
					barrage(CENTERX, CENTERY, 0, BLUE, 3, ICHIDO * f * 10, 4, 4, ICHIDO * 2, 2, 360, 4, 1, 0, 0);
					barrage(CENTERX, CENTERY, 0, BLUE, 3, ICHIDO * f * 10, 4, 3, ICHIDO * 2, 2, 360, 4, 1, 0, 0);
				}
				barrage(CENTERX, CENTERY, 0, LIME, 3, ICHIDO * f * 0.1, 16, 3, ICHIDO * 45, 60, 360, 4, 1, 0, 0);
				barrage(CENTERX, CENTERY, 0, LIME, 3, ICHIDO * f * 0.1, 16, 3, -ICHIDO * 45, 60, 360, 4, 1, 0, 0);
			}
			if (f == 5000) {
				for (int i = 0; i < b.size(); i++) {
					b[i].curveflag = 0;
				}
			}
			if (f >= 5000 && f <= 6000) {
				if (f % 10 == 0) {
					barrage(CENTERX, CENTERY, 2, YELLOW, 3, ICHIDO * f * 0.1, 16, 2, 0, 0, 360, 4, 0, 0, 0);
					barrage(CENTERX, CENTERY, 2, YELLOW, 3, -ICHIDO * f * 0.1, 16, 2, 0, 0, 360, 4, 0, 0, 0);
				}
				if (f <= 5500 && f % 60 == 0) {
					barrage(CENTERX, CENTERY, 0, BLUE, 3, ICHIDO * f, 128, 2, ICHIDO * 90, 60, 360, 4, 0, 1, 0);
				}
				if (f >= 5500 && f % 15 == 0) {
					barrage(CENTERX, CENTERY, 0, BLUE, 3, ICHIDO * f, 128, 2, ICHIDO * 90, 60, 360, 4, 0, 1, 0);
				}
			}
			if (f >= 6000 && f <= 7000) {
				if (f % 5 == 0) {
					ShotLaser(CENTERX + sin((double)f / 100) * 150, CENTERY + cos((double)f / 100) * 150, 99, WHITE, sin(f / 50) * TAU, 4, 4, 4, ICHIDO * sin(f / 100) * 0.1, 1, 1, 240, 0);
				}
				if (f <= 6500) {
					if (f % 10 == 0) {
						barrage(CENTERX + sin((double)f / 100) * 150, CENTERY + cos((double)f / 100) * 150, 0, BLUE, 2, 0, 64, 2, ICHIDO * 0.2, 1, 360, 4, 1, 0, 0);
					}
				}
				else {
					if (f % 5 == 0) {
						barrage(CENTERX + sin((double)f / 100) * 150, CENTERY + cos((double)f / 100) * 150, 0, BLUE, 2, 0, 64, 2, ICHIDO * 0.2, 1, 360, 4, 1, 0, 0);
					}
				}
			}
			if (f == 7000) {
				score += 1000000;
				if (save.hiscore < score)save.hiscore = score;
				//PlaySoundMem(BSH[2], DX_PLAYTYPE_LOOP);
			}
			/*		if (f > 7000 && f % 10 == 0) {
						barrage(CENTERX, CENTERY, 0, 3, sin((double)f / 200) * TAU * 5, 10000, 10, 0, 0, 360, 4, 0, 0);
					}*/
			if (f == 7001) txt.flag = 1;
			if (f > 7000) {
				switch (text_count) {
				case 0:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], RED);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 1:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], WHITE);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 2:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], RED);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 3:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], WHITE);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 4:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], RED);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 5:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], WHITE);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 6:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], RED);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 7:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], WHITE);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 8:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], RED);
							text_count++;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 9:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text(textlist[text_count], WHITE);
							text_count++;
							bgm_num = 2;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				case 10:
					if (CheckHitKey(KEY_INPUT_Z) == 1 || CheckHitKey(KEY_INPUT_RETURN) == 1) {
						if (z_keypush_flag == 0) {
							z_keypush_flag = 1;
							text_clear();
							txt.flag = 0;
							boss_flag = 1;
							boss.flag = 1;
							boss.hp = 100000;
							boss.x = CENTERX;
							boss.y = 200;
							f = 0;
						}
					}
					else {
						z_keypush_flag = 0;
					}
					break;
				}
			}
		}
		else {
			if (f < 2000 && f % 5 == 0) {
				barrage(boss.x, boss.y, 2, PURPLE, 2, 0, 64, 5, 0, 0, 360, 4, 0, 0, 0);
				if (f % 120 < 60) {
					for (int i = 0; i < b.size(); i++) {
						b[i].velocity = 1;
						b[i].color = WHITE;
					}
				}
				else {
					for (int i = 0; i < b.size(); i++) {
						b[i].velocity = 5;
						b[i].color = PURPLE;
					}
				}
				if (f % 120 == 0) {
					for (int i = 0; i < b.size(); i++) {
						b[i].angle += ICHIDO * 30;
					}
				}
			}
			if (f > 2000 && f < 4000) {
				if (f % 120 < 45) {
					if (f % 10 == 0) {
						barrage(boss.x, boss.y, 0, BLUE, 2, 0, 64, 5, 0, 0, 360, 4, 0, 0, 1);
					}
					for (int i = 0; i < b.size(); i++) {
						if (b[i].id == 0) {
							b[i].size = -4;
							b[i].color = WHITE;
						}
					}
				}
				else {
					barrage(boss.x, boss.y, 2, PURPLE, 2, 0, 128, 5, 0, 0, 360, 16, 0, 0, 0);
					for (int i = 0; i < b.size(); i++) {
						if (b[i].id == 0) {
							b[i].size = 4;
							b[i].color = PURPLE;
						}
					}
				}
			}
			if (f > 4000 && f < 6000) {
				if (f % 2 == 0) {
					barrage(boss.x, boss.y, 2, PURPLE, 3, f * ICHIDO * 8, 32, 2, 0, 0, 280, 4, 0, 0, 0);
					barrage(boss.x, boss.y, 2, PURPLE, 3, -f * ICHIDO * 8, 32, 2, 0, 0, 280, 4, 0, 0, 0);
				}
			}
			if (f > 6000 && f < 8000) {
				if (f % 4 == 0) {
					barrage(boss.x, boss.y, 2, PURPLE, 3, f * ICHIDO * 8, 8, 2, 0, 0, 280, 4, 0, 1, 0);
					barrage(boss.x, boss.y, 2, PURPLE, 3, -f * ICHIDO * 8, 8, 2, 0, 0, 280, 4, 0, 1, 0);
				}
			}
			if (f > 8000 && f < 10000) {
				if (f % 30 == 0) {
					barrage(boss.x, boss.y, 0, WHITE, 2, 0, 128, 5, 0, 0, 360, 4, 0, 0, 0);
				}
			}
			if (f > 10000) {
				if (f % 15 == 0) {
					barrage(boss.x, boss.y, 0, WHITE, 2, 0, 128, 3, 0, 0, 360, 4, 0, 0, 0);
				}
				if (f % 4 == 0) {
					barrage(boss.x, boss.y, 2, PURPLE, 3, f * ICHIDO * 8, 32, 2, 0, 0, 280, 4, 0, 0, 0);
					barrage(boss.x, boss.y, 2, PURPLE, 3, -f * ICHIDO * 8, 32, 2, 0, 0, 280, 4, 0, 0, 0);
				}
			}
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}
void function2() {
	switch (stage) {
	case 1:
		if (boss_flag == 0) {
			if (f >= 2750 && f <= 6000)DrawRotaGraph(CENTERX, CENTERY, 0.75, bitangle, GH[5], TRUE);
			if (f >= 6000 && f <= 7000)DrawRotaGraph(CENTERX + sin((double)f / 100) * 150, CENTERY + cos((double)f / 100) * 150, 0.75, bitangle, GH[5], TRUE);
		}
		else {

		}
		break;
	}
}