#include <stdio.h>
#include <stdlib.h>
#define SDL_MAIN_HANDLED
#include "SDL/include/SDL2/SDL.h"

#define WIDTH 160
#define HEIGHT 120
#define TPIXEL WIDTH * HEIGHT
#define FPS 20
#define REFRESH_TIME 1000 / FPS // in ms
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
extern FILE* fileP;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

// DISPLAY
void RESET();
void SET();
void DISPLAY();
void RENDER();
void WAIT();

// MEMORY & BUFFER
int GET_MEMLOC(int x, int y);
void CHK_BUF();
void CHG_BUF();
void LOAD_BUF(int frame);

// MISC
void printA(int *pArr, int pArrLen);
