#include "enemy.h"

void enemyenemy(int size1, int size2, int i) {
	for (int j = 0; j <= t.size(); j++) {
		if (e[i].x - size1 / 2 + 5 <= t[j].x - 20 && e[i].x + size1 / 2 + 5 >= t[j].x + 20 && e[i].y - size1 / 2 + 5 <= p.y + 20 && e[i].y + size1 / 2 + 5 >= t[j].y - 20) {
			t.erase(t.begin() + j);
			ehit();
			e.erase(e.begin() + i);
		}
		if (e[i].x >= MIGI + size1 / 2 || e[i].x <= HIDARI - size1 / 2 || e[i].y >= SHITA + size1 / 2 || e[i].y <= UE - size1 / 2) {
			e.erase(e.begin() + i);
		}
		if (hitcheck(e[i].x, e[i].y, size2)) {
			phit();
		}
	}
}

void MoveEnemy() {
	for (int i = 0; i < e.size(); i++) {
		e[i].frame++;
		switch (e[i].type) {
		case 1:
			switch (e[i].bullet) {
			case 0:
				if (e[i].frame % 5 == 0) {
					barrage(e[i].x, e[i].y, 0, RED, 0, 0.0, 10, 5.0, 0.0, 1, 25.0, 4, 0, 0, 0);
				}
				break;
			case 1:
				if (e[i].frame % 5 == 0) {
					barrage(e[i].x, e[i].y, 0, RED, 1, 0.0, 10, 5.0, 0.0, 1, 25.0, 4, 0, 0, 0);
				}
			}
			switch (e[i].pattern) {
			case 1:
				for (int k = 0; k <= 5; k++) {
					e[i].x--;
					enemyenemy(50, 20, i);
				}
				break;
			case 2:
				for (int k = 0; k <= 5; k++) {
					e[i].x++;
					enemyenemy(50, 20, i);
				}
				break;
			case 3:
				for (int k = 0; k <= 5; k++) {
					e[i].x--;
					enemyenemy(50, 20, i);
				}
				break;
			case 4:
				for (int k = 0; k <= 5; k++) {
					e[i].x++;
					enemyenemy(50, 20, i);
				}
				break;
			case 5:
				for (int k = 0; k <= 5; k++) {
					e[i].x--;
					e[i].yv += 0.01;
					e[i].y = UE + 50 + sin(e[i].yv) * 100;
					enemyenemy(50, 20, i);
				}
				break;
			case 6:
				for (int k = 0; k <= 5; k++) {
					e[i].x++;
					e[i].yv += 0.01;
					e[i].y = UE + 50 + sin(e[i].yv) * 100;
					enemyenemy(50, 20, i);
				}
				break;
			case 7:
				for (int k = 0; k <= 5; k++) {
					e[i].x--;
					e[i].yv += 0.01;
					e[i].y = UE + 300 + sin(e[i].yv) * -100;
					enemyenemy(50, 20, i);
				}
				break;
			case 8:
				for (int k = 0; k <= 5; k++) {
					e[i].x++;
					e[i].yv += 0.01;
					e[i].y = UE + 300 + sin(e[i].yv) * -100;
					enemyenemy(50, 20, i);
				}
				break;
			case 9:
				for (int k = 0; k <= 5; k++) {
					e[i].x += cos(e[i].angle);
					e[i].y += -sin(e[i].angle);
					enemyenemy(50, 20, i);
				}
				break;
			case 10:
				for (int k = 0; k <= 5; k++) {
					e[i].x += cos(e[i].angle);
					e[i].y += -sin(e[i].angle);
					enemyenemy(50, 20, i);
				}
				break;
			case 11:
				for (int k = 0; k <= 5; k++) {
					e[i].x += cos(e[i].angle);
					e[i].y += -sin(e[i].angle);
					enemyenemy(50, 20, i);
				}
				break;
			case 12:
				for (int k = 0; k <= 5; k++) {
					e[i].x += cos(e[i].angle);
					e[i].y += -sin(e[i].angle);
					enemyenemy(50, 20, i);
				}
				break;
			}
			break;
		}
	}
}

void DrawEnemy() {
	for (int i = 0; i < e.size(); i++) {
		switch (e[i].type) {
		case 1:
			DrawRotaGraph(e[i].x, e[i].y, 1.0, 0.0, EGH[0], TRUE);
			break;
		default:
			DrawRotaGraph(e[i].x, e[i].y, 1.0, 0.0, EGH[0], TRUE);
			break;
		}
	}
}

void enemy(double x, double y, double xv, double yv, int type, int pattern, int bullet, int aim) {
	if (aim == 1) {
		e.emplace_back(x, y, xv, yv, atan2(-double(p.y - y), double(p.x - x)), type, pattern, bullet, 0);
	}
	else {
		e.emplace_back(x, y, xv, yv, 0, type, pattern, bullet, 0);
	}
}