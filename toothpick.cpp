#include "toothpick.h"

void ToothPickFunc() {
	if (CheckHitKey(KEY_INPUT_Z) == 1) {
		for (int i = 0; i < 6; i++) {
			t.emplace_back(
				p.x - 15 + i * 5,
				p.y - 25
			);
		}
	}
	for (int i = 0; i <= t.size(); i++) {
		t[i].y -= 30;
		if (t[i].y <= UE - 25) {
			t.erase(t.begin() + i);
		}
		DrawRotaGraph(t[i].x, t[i].y, 1.0, 0.0, GH[1], TRUE);
	}
}