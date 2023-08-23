#include <stdio.h>
#include <stdlib.h>

#define WIDTH 40
#define HEIGHT 20
#define TPIXEL WIDTH * HEIGHT
#define FLUSH system("cls")

extern int BUFFER1[TPIXEL];
extern int BUFFER2[TPIXEL];
extern int* BITMAP;
extern int PROCESSING;
extern int ISBUFFER2FLAG; // is BUFFER2 selected?

// DISPLAY
void RESET();
void SET();
void DISPLAY();
void WAIT(int wT);

// MEMORY & BUFFER
int GET_MEMLOC(int x, int y);
void CHK_BUF();
void CHG_BUF();

// MISC
void printA(int* pArr, int pArrLen);
