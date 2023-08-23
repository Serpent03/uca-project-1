#include <stdio.h>
#include <stdlib.h>

#define WIDTH 60
#define HEIGHT 25
#define TPIXEL WIDTH * HEIGHT
#define REFRESH_TIME 100 // in ms

#ifdef _WIN32
#define FLUSH system("cls")
#endif

#ifdef __unix__
#define FLUSH system("clear")
#endif

extern int BUFFER1[TPIXEL];
extern int BUFFER2[TPIXEL];
extern int *BITMAP;
extern int *BG_BITMAP;
extern int PROCESSING;
extern int ISBUFFER2FLAG; // is BUFFER2 selected?

// DISPLAY
void RESET();
void SET();
void DISPLAY();
void RENDER();
void WAIT(int wT);

// MEMORY & BUFFER
int GET_MEMLOC(int x, int y);
void CHK_BUF();
void CHG_BUF();
void LOAD_BUF(int frame);

// MISC
void printA(int *pArr, int pArrLen);
