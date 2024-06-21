#pragma once
#ifndef MAIN_H
#define MAIN_H

#define _USE_MATH_DEFINES
#define CENTERX 448
#define CENTERY 480
#define DEFAULTX 448
#define DEFAULTY 800
#define MIGI 832
#define HIDARI 64
#define UE 32
#define SHITA 928
#define TP 500
#define LN 1000
#define EN 1000000
#define BT 1000000
#define BIT 128
#define PI M_PI
#define TAU PI * 2//6.28318530718
#define ICHIDO PI / 180//0.01745329251

//color
#define RED 0
#define ORANGE 1
#define YELLOW 2
#define GREEN 3
#define AQUA 4
#define BLUE 5
#define PURPLE 6
#define PINK 7
#define LIME 8
#define WHITE 9
#define BLACK 10

#include "DxLib.h"
#include <locale.h>
#include <math.h>
#include <iostream>
#include <string>
#include "player.h"
#include "toothpick.h"
#include "enemy.h"
#include "bullet.h"
#include "range.h"
#include "laser.h"
#include "background.h"
#include "fps.h"
#include "title.h"
#include "text.h"
#include "init.h"
#include "bgm.h"
#include "option.h"
#include "boss.h"
#include <thread>
#include <vector>

struct ToothPick {
	int x;
	int y;
};
struct Bullet {
	double x;
	double y;
	double xv;
	double yv;
	double angle;
	double viewangle;
	double curve;
	int curveframe;
	int curveflag;
	int flag;
	int refl;
	int type;
	int color;
	char pattern_type;
	int pattern_int;
	const char* pattern_str;
	int size;
	double velocity;
	double gr;
	double grspeed;
	double grbias;
	int frame;
	int id;
};
struct Enemy {
	double x;
	double y;
	double xv;
	double yv;
	double angle;
	int type;
	int pattern;
	int bullet;
	int frame;
};
struct Laser {
	double x;
	double y;
	double xv;
	double yv;
	int count;
	int way;
	double angle;
	double curve;
	int curveframe;
	int curveflag;
	int flag;
	int refl;
	int type;
	int color;
	char pattern_type;
	int pattern_int;
	const char* pattern_str;
	int size;
	double velocity;
	int frame;
	int id;
};
struct Player {
	double x = DEFAULTX;
	double y = DEFAULTY;
};
struct Bomb {
	int x;
	int y;
	int time;
};
struct Item {
	int x;
	int y;
	int type;
};
struct bit {
	double x[BIT];
	double y[BIT];
	double x_b[BIT];
	double y_b[BIT];
	double xs[BIT];
	double ys[BIT];
	double angle1[BIT];
	double angle2[BIT];
	double angle_b[BIT];
	double viewangle[BIT];
	int size[BIT];
	int type[BIT];
	int type_b[BIT];
	int pattern[BIT];
	int pattern_b[BIT];
	int frame[BIT];
	int way[BIT];
	double curve1[BIT];
	double curve2[BIT];
	double curve_b[BIT];
	int curveframe1[BIT];
	int curveframe2[BIT];
	int curveframe_b[BIT];
	int curveflag1[BIT];
	int curveflag2[BIT];
	int curveflag_b[BIT];
	int changeframe[BIT];
	int flag[BIT];
};
struct TextBox {
	std::string one;
	std::string two;
	std::string three;
	std::string four;
	std::string five;
	std::string six;
	std::string seven;
	std::string eight;
	int color1;
	int color2;
	int color3;
	int color4;
	int color5;
	int color6;
	int color7;
	int color8;
	int flag;
};
struct BackGround {
	int x;
	int y;
	int speed;
};
struct Boss {
	double x;
	double y;
	double xv;
	double yv;
	int flag;
	int hp;
	int face[100];
	int graph;
};
struct SaveData {
	long hiscore = 0;
	int window_mode = 1;
	int bgm_vol = 80;
	int se_vol = 60;
};

extern int GH[100];
extern int TGH[100];
extern int OGH[100];
extern int EGH[100];
extern int BOSSGH[5];
extern int BBGH[100];
extern int BFGH[100];
extern int BGGH[10];
extern int EFGH[100];
extern int SSH[20];
extern int BSH[20];

extern struct Player p;
extern std::vector<Enemy> e;
extern std::vector<ToothPick> t;
extern std::vector<Bullet> b;
extern std::vector<Laser> l;
extern struct BackGround bg1;
extern struct BackGround bg2;
extern struct TextBox txt;
extern struct SaveData save;
extern struct Boss boss;
extern struct Bomb bo;

extern int f;
extern int count;
extern int stage;
extern double tmp;
extern int z_keypush_flag;
extern int up_keypush_flag;
extern int down_keypush_flag;
extern int select_num;
extern int boss_flag;
extern std::string textlist[100];
extern int bgm_num;
extern int title_flag;
extern unsigned int thread_num;

int hitcheck(int x, int y, int size);
void bomber();
void gameover();
void ehit();
void phit();
void comboo();
void bit(double x, double y, int type, int pattern, double angle1, double angle2, int size_bit, double speed1, double speed2, double curve1, double curve2, int curveframe1, int curveframe2, int curveflag1, int curveflag2, int hp, int changeframe, double x_b, double y_b, int type_b, int pattern_b, double angle_b, int wey, double speed_b, double curve_b, int curveframe_b, double rwidth, int size_b, int curveflag_b, int pt);
void ui();
void function();
void function2();

#endif