#include <stdio.h>
#include <stdlib.h>

#define WIDTH 40
#define HEIGHT 15
#define TPIXEL WIDTH * HEIGHT
// #define REFRESH_TIME 15 // in ms
#define BUFFER_CHAR "@"

#ifdef _WIN32
#define FLUSH system("cls")
#define REFRESH_TIME 15
#endif

#ifdef __unix__
#define FLUSH system("clear")
#define REFRESH_TIME 50
#endif

extern char BUFFER1[TPIXEL];
extern char BUFFER2[TPIXEL];
extern char *BITMAP;
extern char *BG_BITMAP;
extern int ISBUFFER2FLAG; // is BUFFER2 selected?
extern FILE* fileP;

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
