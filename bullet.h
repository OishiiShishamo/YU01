#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "main.h"

void ShotBullet(double x, double y, int type, int color, int pattern, double angle, int size, double velocity, double curve, int curveframe, int curveflag, int id);
void barrage(double x, double y, int type, int color, int pattern, double angle, int way, double velocity, double curve, int curveframe, double rwidth, int size, int curveflag, int pt, int id);
void MoveBullet();
void CustomBulletMove(int bullet_num);
void DrawBullet();

#endif