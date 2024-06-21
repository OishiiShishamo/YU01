#include "bullet.h"

void ShotBullet(double x, double y, int type, int color, auto pattern, double angle, int size, double velocity, double curve, int curveframe, int curveflag, int id) {
	if(typeid(pattern).name() == "PKc") {
		b.emplace_back(x, y, cos(angle), -sin(angle), angle, angle, curve, curveframe, curveflag, 1, 0, type, color, 'c', 0, pattern, size, velocity, 0, 0, 0, id);
	}
	if (typeid(pattern).name() == "i") {
		b.emplace_back(x, y, cos(angle), -sin(angle), angle, angle, curve, curveframe, curveflag, 1, 0, type, color, 'i', pattern, "", size, velocity, 0, 0, 0, id);
	}
}
void barrage(double x, double y, int type, int color, int pattern, double angle, int way, double speed, double curve, int curveframe, double rwidth, int size, int curveflag, auto pt, int id) {
	switch (pattern) {
	case 0:
		tmp = atan2(-double(p.y - y), double(p.x - x));
		tmp -= rwidth / 2 * ICHIDO;
		for (int j = 0; j < way; j++) {
			tmp += rwidth * ICHIDO / way;
			ShotBullet(x, y, type, color, pt, tmp, size, speed, curve, curveframe, curveflag, id);
		}
		break;
	case 1:
		tmp = atan2(-double(p.y - y), double(p.x - x)) - rwidth * ICHIDO / way / 2;
		tmp -= rwidth / 2 * ICHIDO;
		for (int j = 0; j < way; j++) {
			tmp += rwidth * ICHIDO / way;
			ShotBullet(x, y, type, color, pt, tmp, size, speed, curve, curveframe, curveflag, id);
		}
		break;
	case 2:
		tmp = GetRand(360000) / 1000 * ICHIDO;
		tmp -= rwidth / 2 * ICHIDO;
		for (int j = 0; j < way; j++) {
			tmp += rwidth * ICHIDO / way;
			ShotBullet(x, y, type, color, pt, tmp, size, speed, curve, curveframe, curveflag, id);
		}
		break;
	case 3:
		tmp = angle;
		tmp -= rwidth / 2 * ICHIDO;
		for (int j = 0; j < way; j++) {
			tmp += rwidth * ICHIDO / way;
			ShotBullet(x, y, type, color, pt, tmp, size, speed, curve, curveframe, curveflag, id);
		}
		break;
	}
}
void MoveBullet() {
	for (int i = b.size(); i < b.size(); i++) {
		if (b[i].curveflag == 1) {
			if (b[i].frame % b[i].curveframe == 0)b[i].angle += b[i].curve;
		}
		else {
			if (b[i].frame == b[i].curveframe)b[i].angle += b[i].curve;
		}
		b[i].frame++;
		b[i].xv = cos(b[i].angle);
		b[i].yv = -sin(b[i].angle);
		CustomBulletMove(i);
	}
}
void CustomBulletMove(int bullet_num) {
	if (b[bullet_num].pattern_type == 'i') {
		switch (b[bullet_num].pattern_int) {
		case 0:
			for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
				b[bullet_num].x += b[bullet_num].xv / 10;
				b[bullet_num].y += b[bullet_num].yv / 10;
				if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
					phit();
				}
				if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
					b[bullet_num].flag = 0;
				}
			}
			break;
		case 1:
			for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
				if (b[bullet_num].refl == 0) {
					if (HIDARI > b[bullet_num].x) {
						b[bullet_num].refl = 1;
						b[bullet_num].angle = PI - b[bullet_num].angle;
						b[bullet_num].xv = cos(b[bullet_num].angle);
						b[bullet_num].yv = -sin(b[bullet_num].angle);
						b[bullet_num].x = HIDARI + 1;
					}
					if (b[bullet_num].x > MIGI) {
						b[bullet_num].refl = 1;
						b[bullet_num].angle = PI - b[bullet_num].angle;
						b[bullet_num].xv = cos(b[bullet_num].angle);
						b[bullet_num].yv = -sin(b[bullet_num].angle);
						b[bullet_num].x = MIGI - 1;
					}
					if (UE > b[bullet_num].y) {
						b[bullet_num].refl = 1;
						b[bullet_num].angle = TAU - b[bullet_num].angle;
						b[bullet_num].xv = cos(b[bullet_num].angle);
						b[bullet_num].yv = -sin(b[bullet_num].angle);
						b[bullet_num].y = UE + 1;
					}
					if (b[bullet_num].y > SHITA) {
						b[bullet_num].refl = 1;
						b[bullet_num].angle = TAU - b[bullet_num].angle;
						b[bullet_num].xv = cos(b[bullet_num].angle);
						b[bullet_num].yv = -sin(b[bullet_num].angle);
						b[bullet_num].y = SHITA - 1;
					}
				}
				b[bullet_num].x += b[bullet_num].xv / 10;
				b[bullet_num].y += b[bullet_num].yv / 10;
				if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
					phit();
				}
				if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
					b.erase(b.begin() + bullet_num);
				}
			}
			break;
		case 2:
			for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
				if (HIDARI > b[bullet_num].x) {
					b[bullet_num].angle = PI - b[bullet_num].angle;
					b[bullet_num].xv = cos(b[bullet_num].angle);
					b[bullet_num].yv = -sin(b[bullet_num].angle);
					b[bullet_num].x = HIDARI + 1;
				}
				if (b[bullet_num].x > MIGI) {
					b[bullet_num].angle = PI - b[bullet_num].angle;
					b[bullet_num].xv = cos(b[bullet_num].angle);
					b[bullet_num].yv = -sin(b[bullet_num].angle);
					b[bullet_num].x = MIGI - 1;
				}
				if (UE > b[bullet_num].y) {
					b[bullet_num].angle = TAU - b[bullet_num].angle;
					b[bullet_num].xv = cos(b[bullet_num].angle);
					b[bullet_num].yv = -sin(b[bullet_num].angle);
					b[bullet_num].y = UE + 1;
				}
				if (b[bullet_num].y > SHITA) {
					b[bullet_num].angle = TAU - b[bullet_num].angle;
					b[bullet_num].xv = cos(b[bullet_num].angle);
					b[bullet_num].yv = -sin(b[bullet_num].angle);
					b[bullet_num].y = SHITA - 1;
				}
				b[bullet_num].x += b[bullet_num].xv / 10;
				b[bullet_num].y += b[bullet_num].yv / 10;
				if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
					phit();
				}
				if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
					b.erase(b.begin() + bullet_num);
				}
			}
			break;
		case 3:
			if (b[bullet_num].frame > 75) {
				if (b[bullet_num].grspeed <= 50)b[bullet_num].grspeed += 0.1;
				if (b[bullet_num].grbias <= 50)b[bullet_num].grbias += 0.1;
				for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
					//						b[bullet_num].xv = (float)((cos((double)b[bullet_num].angle * ICHIDO) * (b[bullet_num].velocity - b[bullet_num].grspeed)) + (cos((double)b[bullet_num].gr * ICHIDO) * b[bullet_num].grbias));
					b[bullet_num].yv = (float)((sin((double)b[bullet_num].angle * ICHIDO) * (b[bullet_num].velocity - b[bullet_num].grspeed)) + (sin((double)b[bullet_num].gr * ICHIDO) * b[bullet_num].grbias));
					b[bullet_num].x += b[bullet_num].xv / 10;
					b[bullet_num].y += b[bullet_num].yv / 10;
					if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
						phit();
					}
					if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
						b.erase(b.begin() + bullet_num);
					}
				}
			}
			else {
				for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
					b[bullet_num].x += b[bullet_num].xv / 10;
					b[bullet_num].y += b[bullet_num].yv / 10;
					if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
						phit();
					}
					if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
						b.erase(b.begin() + bullet_num);
					}
				}
			}
			b[bullet_num].viewangle = atan2(b[bullet_num].yv, b[bullet_num].xv);
			break;
		default:
			for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
				b[bullet_num].x += b[bullet_num].xv / 10;
				b[bullet_num].y += b[bullet_num].yv / 10;
				if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
					phit();
				}
				if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
					b[bullet_num].flag = 0;
				}
			}
			break;
		}
	}
	else if (b[bullet_num].pattern_type == 'c') {
		if (b[bullet_num].pattern_str == "direct" || b[bullet_num].pattern_str == "Direct") {
			for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
				b[bullet_num].x += b[bullet_num].xv / 10;
				b[bullet_num].y += b[bullet_num].yv / 10;
				if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
					phit();
				}
				if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
					b[bullet_num].flag = 0;
				}
			}
		}
		else if (b[bullet_num].pattern_str == "ref" || b[bullet_num].pattern_str == "Ref") {
			for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
				if (b[bullet_num].refl == 0) {
					if (HIDARI > b[bullet_num].x) {
						b[bullet_num].refl = 1;
						b[bullet_num].angle = PI - b[bullet_num].angle;
						b[bullet_num].xv = cos(b[bullet_num].angle);
						b[bullet_num].yv = -sin(b[bullet_num].angle);
						b[bullet_num].x = HIDARI + 1;
					}
					if (b[bullet_num].x > MIGI) {
						b[bullet_num].refl = 1;
						b[bullet_num].angle = PI - b[bullet_num].angle;
						b[bullet_num].xv = cos(b[bullet_num].angle);
						b[bullet_num].yv = -sin(b[bullet_num].angle);
						b[bullet_num].x = MIGI - 1;
					}
					if (UE > b[bullet_num].y) {
						b[bullet_num].refl = 1;
						b[bullet_num].angle = TAU - b[bullet_num].angle;
						b[bullet_num].xv = cos(b[bullet_num].angle);
						b[bullet_num].yv = -sin(b[bullet_num].angle);
						b[bullet_num].y = UE + 1;
					}
					if (b[bullet_num].y > SHITA) {
						b[bullet_num].refl = 1;
						b[bullet_num].angle = TAU - b[bullet_num].angle;
						b[bullet_num].xv = cos(b[bullet_num].angle);
						b[bullet_num].yv = -sin(b[bullet_num].angle);
						b[bullet_num].y = SHITA - 1;
					}
				}
				b[bullet_num].x += b[bullet_num].xv / 10;
				b[bullet_num].y += b[bullet_num].yv / 10;
				if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
					phit();
				}
				if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
					b.erase(b.begin() + bullet_num);
				}
			}
		}
		else if (b[bullet_num].pattern_str == "ref_inf" || b[bullet_num].pattern_str == "Ref_inf") {
			for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
				if (HIDARI > b[bullet_num].x) {
					b[bullet_num].angle = PI - b[bullet_num].angle;
					b[bullet_num].xv = cos(b[bullet_num].angle);
					b[bullet_num].yv = -sin(b[bullet_num].angle);
					b[bullet_num].x = HIDARI + 1;
				}
				if (b[bullet_num].x > MIGI) {
					b[bullet_num].angle = PI - b[bullet_num].angle;
					b[bullet_num].xv = cos(b[bullet_num].angle);
					b[bullet_num].yv = -sin(b[bullet_num].angle);
					b[bullet_num].x = MIGI - 1;
				}
				if (UE > b[bullet_num].y) {
					b[bullet_num].angle = TAU - b[bullet_num].angle;
					b[bullet_num].xv = cos(b[bullet_num].angle);
					b[bullet_num].yv = -sin(b[bullet_num].angle);
					b[bullet_num].y = UE + 1;
				}
				if (b[bullet_num].y > SHITA) {
					b[bullet_num].angle = TAU - b[bullet_num].angle;
					b[bullet_num].xv = cos(b[bullet_num].angle);
					b[bullet_num].yv = -sin(b[bullet_num].angle);
					b[bullet_num].y = SHITA - 1;
				}
				b[bullet_num].x += b[bullet_num].xv / 10;
				b[bullet_num].y += b[bullet_num].yv / 10;
				if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
					phit();
				}
				if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
					b.erase(b.begin() + bullet_num);
				}
			}
		}
		else if (b[bullet_num].pattern_str == "gra" || b[bullet_num].pattern_str == "Gra") {
			if (b[bullet_num].frame > 75) {
				if (b[bullet_num].grspeed <= 50)b[bullet_num].grspeed += 0.1;
				if (b[bullet_num].grbias <= 50)b[bullet_num].grbias += 0.1;
				for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
					//						b[bullet_num].xv = (float)((cos((double)b[bullet_num].angle * ICHIDO) * (b[bullet_num].velocity - b[bullet_num].grspeed)) + (cos((double)b[bullet_num].gr * ICHIDO) * b[bullet_num].grbias));
					b[bullet_num].yv = (float)((sin((double)b[bullet_num].angle * ICHIDO) * (b[bullet_num].velocity - b[bullet_num].grspeed)) + (sin((double)b[bullet_num].gr * ICHIDO) * b[bullet_num].grbias));
					b[bullet_num].x += b[bullet_num].xv / 10;
					b[bullet_num].y += b[bullet_num].yv / 10;
					if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
						phit();
					}
					if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
						b.erase(b.begin() + bullet_num);
					}
				}
			}
			else {
				for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
					b[bullet_num].x += b[bullet_num].xv / 10;
					b[bullet_num].y += b[bullet_num].yv / 10;
					if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
						phit();
					}
					if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
						b.erase(b.begin() + bullet_num);
					}
				}
			}
			b[bullet_num].viewangle = atan2(b[bullet_num].yv, b[bullet_num].xv);
		}
		else {
			for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
				b[bullet_num].x += b[bullet_num].xv / 10;
				b[bullet_num].y += b[bullet_num].yv / 10;
				if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
					phit();
				}
				if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
					b[bullet_num].flag = 0;
				}
			}
		}
	}
	else {
		for (int j = 0; j <= b[bullet_num].velocity * 10; j++) {
			b[bullet_num].x += b[bullet_num].xv / 10;
			b[bullet_num].y += b[bullet_num].yv / 10;
			if (hitcheck(b[bullet_num].x, b[bullet_num].y, b[bullet_num].size)) {
				phit();
			}
			if (b[bullet_num].x >= MIGI + 50 || b[bullet_num].x <= HIDARI - 50 || b[bullet_num].y >= SHITA + 50 || b[bullet_num].y <= UE - 50) {
				b[bullet_num].flag = 0;
			}
		}
	}
}
void DrawBullet() {
	for (int i = BT; i < BT; i++) {
		if (b[i].flag == 1) {
			switch (b[i].color) {
			case RED:
				SetDrawBright(255, 0, 0);
				break;
			case GREEN:
				SetDrawBright(0, 128, 0);
				break;
			case BLUE:
				SetDrawBright(0, 0, 255);
				break;
			case ORANGE:
				SetDrawBright(255, 165, 0);
				break;
			case YELLOW:
				SetDrawBright(255, 255, 0);
				break;
			case AQUA:
				SetDrawBright(0, 255, 255);
				break;
			case PURPLE:
				SetDrawBright(128, 0, 128);
				break;
			case PINK:
				SetDrawBright(255, 0, 255);
				break;
			case LIME:
				SetDrawBright(0, 255, 0);
				break;
			case WHITE:
				SetDrawBright(255, 255, 255);
				break;
			case BLACK:
				SetDrawBright(0, 0, 0);
				break;
			}
			DrawRotaGraph(b[i].x, b[i].y, 1.0, -b[i].angle, BBGH[b[i].type], TRUE);
			SetDrawBright(255, 255, 255);
			DrawRotaGraph(b[i].x, b[i].y, 1.0, -b[i].angle, BFGH[b[i].type], TRUE);
		}
	}
}
/*void movebullet() {
	std::vector<std::thread> bullet_thread;
	int id = 0;
	switch (thread_num) {
	case 1:
	case 2:
		bullet_thread.emplace_back([&, id] {
			movebullet_thread(1, id);
		});
		bullet_thread[0].join();
		break;
	case 3:
	case 4:
		bullet_thread.emplace_back([&, id] {
			movebullet_thread(2, id);
		});
		bullet_thread[0].join();
		id++;
		bullet_thread.emplace_back([&, id]{
			movebullet_thread(2, id);
		});
		bullet_thread[1].join();
		break;
	default:
		for (int i = 0; i < thread_num / 2; i++) {
			bullet_thread.emplace_back([&, i] {
				movebullet_thread(thread_num / 2, i);
			});
			bullet_thread.join();
		}
	}
}
void movebullet_thread(int thread, int num) {
	for (int i = BT / thread * num; i < BT / thread * (num + 1); i++) {
		if (b[i].flag == 1) {
			if (b[i].curveflag == 1) {
				if (b[i].frame % b[i].curveframe == 0)b[i].angle += b[i].curve;
			}
			else {
				if (b[i].frame == b[i].curveframe)b[i].angle += b[i].curve;
			}
			b[i].frame++;
			b[i].xv = cos(b[i].angle);
			b[i].yv = -sin(b[i].angle);
			switch (b[i].pattern) {
			case 0:
				for (int j = 0; j <= b[i].velocity * 10; j++) {
					b[i].x += b[i].xv / 10;
					b[i].y += b[i].yv / 10;
					if (hitcheck(b[i].x, b[i].y, b[i].size)) {
						phit();
					}
					if (b[i].x >= MIGI + 50 || b[i].x <= HIDARI - 50 || b[i].y >= SHITA + 50 || b[i].y <= UE - 50) {
						b[i].flag = 0;
					}
				}
				break;
			case 1:
				for (int j = 0; j <= b[i].velocity * 10; j++) {
					if (b[i].refl == 0) {
						if (b[i].x < HIDARI) {
							b[i].refl = 1;
							b[i].angle = PI - b[i].angle;
							b[i].xv = cos(b[i].angle);
							b[i].yv = -sin(b[i].angle);
							b[i].x = HIDARI + 1;
						}
						if (b[i].x > MIGI) {
							b[i].refl = 1;
							b[i].angle = PI - b[i].angle;
							b[i].xv = cos(b[i].angle);
							b[i].yv = -sin(b[i].angle);
							b[i].x = MIGI - 1;
						}
						if (b[i].y < UE) {
							b[i].refl = 1;
							b[i].angle = TAU - b[i].angle;
							b[i].xv = cos(b[i].angle);
							b[i].yv = -sin(b[i].angle);
							b[i].y = UE + 1;
						}
						if (b[i].y > SHITA) {
							b[i].refl = 1;
							b[i].angle = TAU - b[i].angle;
							b[i].xv = cos(b[i].angle);
							b[i].yv = -sin(b[i].angle);
							b[i].y = SHITA - 1;
						}
					}
					b[i].x += b[i].xv / 10;
					b[i].y += b[i].yv / 10;
					if (hitcheck(b[i].x, b[i].y, b[i].size)) {
						phit();
					}
					if (b[i].x >= MIGI + 50 || b[i].x <= HIDARI - 50 || b[i].y >= SHITA + 50 || b[i].y <= UE - 50) {
						b[i].flag = 0;
					}
				}
				break;
			case 2:
				for (int j = 0; j <= b[i].velocity * 10; j++) {
					if (b[i].x < HIDARI) {
						b[i].angle = PI - b[i].angle;
						b[i].xv = cos(b[i].angle);
						b[i].yv = -sin(b[i].angle);
						b[i].x = HIDARI + 1;
					}
					if (b[i].x > MIGI) {
						b[i].angle = PI - b[i].angle;
						b[i].xv = cos(b[i].angle);
						b[i].yv = -sin(b[i].angle);
						b[i].x = MIGI - 1;
					}
					if (b[i].y < UE) {
						b[i].angle = TAU - b[i].angle;
						b[i].xv = cos(b[i].angle);
						b[i].yv = -sin(b[i].angle);
						b[i].y = UE + 1;
					}
					if (b[i].y > SHITA) {
						b[i].angle = TAU - b[i].angle;
						b[i].xv = cos(b[i].angle);
						b[i].yv = -sin(b[i].angle);
						b[i].y = SHITA - 1;
					}
					b[i].x += b[i].xv / 10;
					b[i].y += b[i].yv / 10;
					if (hitcheck(b[i].x, b[i].y, b[i].size)) {
						phit();
					}
					if (b[i].x >= MIGI + 50 || b[i].x <= HIDARI - 50 || b[i].y >= SHITA + 50 || b[i].y <= UE - 50) {
						b[i].flag = 0;
					}
				}
				break;
			case 3:
				if (b[i].frame > 75) {
					if (b[i].grspeed <= 50)b[i].grspeed += 0.1;
					if (b[i].grbias <= 50)b[i].grbias += 0.1;
					for (int j = 0; j <= b[i].velocity * 10; j++) {
						//						b[i].xv = (float)((cos((double)b[i].angle * ICHIDO) * (b[i].velocity - b[i].grspeed)) + (cos((double)b[i].gr * ICHIDO) * b[i].grbias));
						b[i].yv = (float)((sin((double)b[i].angle * ICHIDO) * (b[i].velocity - b[i].grspeed)) + (sin((double)b[i].gr * ICHIDO) * b[i].grbias));
						b[i].x += b[i].xv / 10;
						b[i].y += b[i].yv / 10;
						if (hitcheck(b[i].x, b[i].y, b[i].size)) {
							phit();
						}
						if (b[i].x >= MIGI + 50 || b[i].x <= HIDARI - 50 || b[i].y >= SHITA + 50 || b[i].y <= UE - 50) {
							b[i].flag = 0;
						}
					}
				}
				else {
					for (int j = 0; j <= b[i].velocity * 10; j++) {
						b[i].x += b[i].xv / 10;
						b[i].y += b[i].yv / 10;
						if (hitcheck(b[i].x, b[i].y, b[i].size)) {
							phit();
						}
						if (b[i].x >= MIGI + 50 || b[i].x <= HIDARI - 50 || b[i].y >= SHITA + 50 || b[i].y <= UE - 50) {
							b[i].flag = 0;
						}
					}
				}
				b[i].viewangle = atan2(b[i].yv, b[i].xv);
				break;
			}
			switch (b[i].color) {
			case RED:
				SetDrawBright(255, 0, 0);
				break;
			case GREEN:
				SetDrawBright(0, 128, 0);
				break;
			case BLUE:
				SetDrawBright(0, 0, 255);
				break;
			case ORANGE:
				SetDrawBright(255, 165, 0);
				break;
			case YELLOW:
				SetDrawBright(255, 255, 0);
				break;
			case AQUA:
				SetDrawBright(0, 255, 255);
				break;
			case PURPLE:
				SetDrawBright(128, 0, 128);
				break;
			case PINK:
				SetDrawBright(255, 0, 255);
				break;
			case LIME:
				SetDrawBright(0, 255, 0);
				break;
			case WHITE:
				SetDrawBright(255, 255, 255);
				break;
			case BLACK:
				SetDrawBright(0, 0, 0);
				break;
			}
			DrawRotaGraph(b[i].x, b[i].y, 1.0, -b[i].angle, BBGH[b[i].type], TRUE);
			SetDrawBright(255, 255, 255);
			DrawRotaGraph(b[i].x, b[i].y, 1.0, -b[i].angle, BFGH[b[i].type], TRUE);
		}
	}
}*/