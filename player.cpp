#include "player.h"

void PlayerMove(double fast, double slow) {
	int r = 0;
	if (CheckHitKey(KEY_INPUT_UP) == 1)r = 1;
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)r = 2;
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)r = 3;
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)r = 4;
	if (CheckHitKey(KEY_INPUT_UP) == 1 && CheckHitKey(KEY_INPUT_RIGHT) == 1)r = 5;
	if (CheckHitKey(KEY_INPUT_UP) == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1)r = 6;
	if (CheckHitKey(KEY_INPUT_DOWN) == 1 && CheckHitKey(KEY_INPUT_RIGHT) == 1)r = 7;
	if (CheckHitKey(KEY_INPUT_DOWN) == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1)r = 8;
	if (CheckHitKey(KEY_INPUT_LSHIFT) == 1) {
		switch (r) {
		case 1:
			p.y -= slow;
			break;
		case 2:
			p.y += slow;
			break;
		case 3:
			p.x += slow;
			break;
		case 4:
			p.x -= slow;
			break;
		case 5:
			p.x += slow / 1.41;
			p.y -= slow / 1.41;
			break;
		case 6:
			p.x -= slow / 1.41;
			p.y -= slow / 1.41;
			break;
		case 7:
			p.x += slow / 1.41;
			p.y += slow / 1.41;
			break;
		case 8:
			p.x -= slow / 1.41;
			p.y += slow / 1.41;
			break;
		}
	}
	else {
		switch (r) {
		case 1:
			p.y -= fast;
			break;
		case 2:
			p.y += fast;
			break;
		case 3:
			p.x += fast;
			break;
		case 4:
			p.x -= fast;
			break;
		case 5:
			p.x += fast / 1.41;
			p.y -= fast / 1.41;
			break;
		case 6:
			p.x -= fast / 1.41;
			p.y -= fast / 1.41;
			break;
		case 7:
			p.x += fast / 1.41;
			p.y += fast / 1.41;
			break;
		case 8:
			p.x -= fast / 1.41;
			p.y += fast / 1.41;
			break;
		}
	}
	if (p.x >= MIGI - 15)p.x = MIGI - 15;
	if (p.x <= HIDARI + 14)p.x = HIDARI + 14;
	if (p.y >= SHITA - 20)p.y = SHITA - 20;
	if (p.y <= UE + 60)p.y = UE + 60;
}
void PlayerDraw() {
	DrawRotaGraph(p.x, p.y + 10, 1.0, 0.0, GH[0], TRUE);
}