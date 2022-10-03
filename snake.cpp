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
void Snake::checkEgg() {
  if ((e1 == p1) && (e2 == p2)) {
    sndEt();
    egg();
    dly--;
    score();
    n++;
  }
}

void Snake::move() {
  int st = 0;
  do {
    if (!kbhit()) {
      checkEgg();
      if (!st)
        show();
      else
        st = 0;
      delay(dly / 4);
      transpose();
      delay(dly / 4);
      gnrtUnCond();
      delay(dly / 4);
      check();
      delay(dly / 4);
    } else if (stp) {
      chngDir();
      gnrtCond();
      check();
      show();
      st = 1;
    }
  } while (stp);
}

void Snake::init() {
  time_t tm;
  srand(time( & tm));
  dsp = 20;
  n = 5;
  prev = 4;
  for (int i = 4; i >= 0; i--) {
    pos[i][0] = 201 + (n - i - 1) * dsp;
    pos[i][1] = 301;
  }
  strtX = 21;
  strtY = 21;
  endX = 481;
  endY = 361;
  colr = 14;
  now = prev;
  dsp = 20;
  stp = 111;
  cnt = -1;
  scr = 0;
  dly = 150;
  xr = 3;
  yr = 9;
  egg();
  egGen = 1;
  score();
  int x = getcolor();
  setlinestyle(0, 1, 3);
  setcolor(15);
  rectangle(strtX - 15, strtY - 15, endX + 15, endY + 15);
  rectangle(endX + 25, strtY - 15, getmaxx() - 15, endY + 15);
  rectangle(strtX - 15, endY + 25, getmaxx() - 15, getmaxy() - 5);
  line(endX + 25, strtY + 75, getmaxx() - 15, strtY + 75);
  line(endX + 25, strtY + 200, getmaxx() - 15, strtY + 200);
  line(endX + 25, strtY + 275, getmaxx() - 15, strtY + 275);
  setlinestyle(0, 1, 1);
  settextstyle(8, 0, 1);
  setcolor(11);
  outtextxy(514, 40, "SCORE");
  setcolor(14);
  settextstyle(11, 0, 5);
  outtextxy(524, 110, " CONTROLS ");
  outtextxy(522, 135, "p = PAUSE");
  outtextxy(522, 155, "g = RESUME");
  outtextxy(522, 175, "e = EXIT");
  outtextxy(513, 195, "ARROWS");
  outtextxy(512, 205, "    -MOVEMENT");
  setcolor(14);
  settextstyle(4, 0, 9);
  outtextxy(getmaxx() - 500, getmaxy() - 110, "SNAKE");
  settextstyle(8, 0, 1);
  setcolor(x);
}

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
