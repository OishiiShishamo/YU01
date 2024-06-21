#include "fps.h"
static int mStartTime;
static int mCount;
static float mFps;
static const int N = 60;
static const int FPS = 60;
void Fps_Initialize() {
    mStartTime = GetNowCount();
    mCount = 0;
    mFps = 0;
}
bool Fps_Update() {
    if (mCount == 0) {
        mStartTime = GetNowCount();
    }
    if (mCount == N) {
        int t = GetNowCount();
        mFps = 1000.f / ((t - mStartTime) / (float)N);
        mCount = 0;
        mStartTime = t;
    }
    mCount++;
    return true;
}
void Fps_Draw() {
    SetFontSize(30);
    DrawFormatString(1150, 920, GetColor(0, 0, 0), "%.2ffps", mFps);
    SetFontSize(30);
}
void Fps_Wait() {
    int tookTime = GetNowCount() - mStartTime;
    int waitTime = mCount * 1000 / FPS - tookTime;
    if (waitTime > 0) {
        Sleep(waitTime);
    }
}