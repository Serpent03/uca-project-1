#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 30
#define TPIXEL WIDTH * HEIGHT
#define REFRESH_TIME 10 // in ms
#define BUFFER_CHAR "@"

#ifdef _WIN32
#define FLUSH system("cls")
#endif

#ifdef __unix__
#define FLUSH system("clear")
#endif

extern char BUFFER1[TPIXEL];
extern char BUFFER2[TPIXEL];
extern char *BITMAP;
extern char *BG_BITMAP;
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
