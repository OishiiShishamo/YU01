#include "background.h"

void background() {
	switch (stage) {
	case 1:
		for (int i = 0; i < bg1.speed; i++) {
			bg1.y++;
			bg2.y++;
			if (bg1.y >= 990)bg1.y = -990;
			if (bg2.y >= 990)bg2.y = -990;
		}
		DrawRotaGraph(bg1.x + 640, bg1.y + 500, 1, 0, BGGH[2], TRUE);
		DrawRotaGraph(bg2.x + 640, bg2.y + 500, 1, 0, BGGH[2], TRUE);
		break;
	}
}