#include "benri.h"

int DrawRotaGraph4(int x, int y, double rate, double anglex, double angley, double anglez, int handle, int tranflag, int x_turn_flag, int y_turn_flag) {
	int sx = 0, sy = 0;
	MATRIX m;
	VECTOR v;

	GetGraphSize(handle, &sx, &sy);
	//	m = MMult(MMult(MGetRotX(anglex), MGetRotY(angley)), MGetRotZ(anglez));
	m = MMult(MGetRotZ(anglez), MGetRotX(anglex));
	m.m[0][0] *= rate; m.m[0][1] *= rate; m.m[0][2] *= rate;
	m.m[1][0] *= rate; m.m[1][1] *= rate; m.m[1][2] *= rate;
	int lux, luy, rux, ruy, rdx, rdy, ldx, ldy;
	if (x_turn_flag == FALSE) {
		if (y_turn_flag == FALSE) {
			v.x = sx / 2; v.y = -sy / 2;  v.z = 0.0;
			v = VTransform(v, m);
			rux = x + v.x, ruy = y + v.y;
			ldx = x - v.x, ldy = y - v.y;

			v.x = -sx / 2; v.y = -sy / 2;  v.z = 0.0;
			v = VTransform(v, m);
			lux = x + v.x, luy = y + v.y;
			rdx = x - v.x, rdy = y - v.y;
		}
		else {
			v.x = sx / 2; v.y = sy / 2;  v.z = 0.0;
			v = VTransform(v, m);
			rux = x + v.x, ruy = y + v.y;
			ldx = x - v.x, ldy = y - v.y;

			v.x = -sx / 2; v.y = sy / 2;  v.z = 0.0;
			v = VTransform(v, m);
			lux = x + v.x, luy = y + v.y;
			rdx = x - v.x, rdy = y - v.y;
		}
	}
	else {
		if (y_turn_flag == FALSE) {
			v.x = -sx / 2; v.y = -sy / 2;  v.z = 0.0;
			v = VTransform(v, m);
			rux = x + v.x, ruy = y + v.y;
			ldx = x - v.x, ldy = y - v.y;

			v.x = sx / 2; v.y = -sy / 2;  v.z = 0.0;
			v = VTransform(v, m);
			lux = x + v.x, luy = y + v.y;
			rdx = x - v.x, rdy = y - v.y;
		}
		else {
			v.x = -sx / 2; v.y = sy / 2;  v.z = 0.0;
			v = VTransform(v, m);
			rux = x + v.x, ruy = y + v.y;
			ldx = x - v.x, ldy = y - v.y;

			v.x = sx / 2; v.y = sy / 2;  v.z = 0.0;
			v = VTransform(v, m);
			lux = x + v.x, luy = y + v.y;
			rdx = x - v.x, rdy = y - v.y;
		}
	}
	DrawModiGraph(lux, luy, rux, ruy, rdx, rdy, ldx, ldy, handle, tranflag);
	return 1;
}

int second(int sec) {
	return sec * 60;
}