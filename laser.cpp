#include "laser.h"

void ShotLaser(double x, double y, int type, int color, double angle, int way, int size, double velocity, double curve, int curveframe, int curveflag, int countt, auto pattern, int id) {
	if (typeid(pattern).name() == "PKc") {
		l.emplace_back({ 
			x, 
			y, 
			cos(angle), 
			-sin(angle), 
			countt, 
			way, 
			angle, 
			angle, 
			curve, 
			curveframe, 
			curveflag, 
			1, 
			0, 
			type, 
			color, 
			'c', 
			0, 
			pattern, 
			size, 
			velocity, 
			0, 
			id 
		});
	}
	if (typeid(pattern).name() == "i") {
		l.emplace_back({ 
			x, 
			y, 
			cos(angle), 
			-sin(angle), 
			countt, 
			way, 
			angle, 
			angle, 
			curve, 
			curveframe, 
			curveflag, 
			1,
			0,
			type,
			color,
			'i',
			pattern,
			"", 
			size,
			velocity,
			0, 
			id 
		});
	}
}
void LaserFunc() {
	for (int i = 0; i < BT; i++) {
		if (l[i].flag == 1) {
			if (l[i].count >= 1) {
				l[i].count--;
				barrage(l[i].x, l[i].y, l[i].type, l[i].color, 3, l[i].angle, l[i].way, l[i].velocity, l[i].curve, l[i].curveframe, 360, l[i].size, l[i].curveflag, 0, l[i].id);
			}
			else {
				l[i].flag = 0;
			}
		}
	}
}