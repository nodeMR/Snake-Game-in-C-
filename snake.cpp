#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

class Snake {
  int p1, p2, v1, v2, v3, e1, e2, prev, now, n, colr, dsp, cnt, dly, m;
  int stp, egGen;
  int xr, yr;
  void caught();
  public:
    long scr;
  int strtX, strtY, endX, endY;
  int pos[100][2];
  void show();
  void init();
  void egg();
  void transpose();
  void gnrtCond();
  void gnrtUnCond();
  void check();
  void checkEgg();
  void move();
  void chngDir();
  void sndEt();
  void sndCgt();
  int test();
  void score();
  Snake();
  Snake(Snake * );
  ~Snake();
};
Snake::Snake() {}
Snake::~Snake() {}

void main() {
  Snake snk;
  int gd = DETECT, gm, i, j, k, x, y;
  clrscr();
  initgraph( & gd, & gm, "C:\\Turboc3\\bgi");
  snk.init();
  snk.move();
  closegraph();
  restorecrtmode();
}
