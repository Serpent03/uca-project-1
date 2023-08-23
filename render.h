#include <stdio.h>
#include <stdlib.h>

#define WIDTH 40
#define HEIGHT 20
#define TPIXEL WIDTH * HEIGHT

extern int BITMAP[TPIXEL];

int GET_MEMLOC(int x, int y);
void RESET();
void SET();
void DISPLAY();

// MISC
void printA(int* pArr, int pArrLen);
