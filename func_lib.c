#include <stdlib.h>
#include <stdio.h>
#include "render.h"
#include <time.h>
#define SDL_MAIN_HANDLED
#include "SDL/include/SDL2/SDL.h"

FILE* fileP;

void RESET()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void SET()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void DISPLAY()
{
    if (ISBUFFER2FLAG)
    {
        printf("Current buffer: 2\n");
    }
    else
    {
        printf("Current buffer: 1\n");
    }
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int MEMLOC = GET_MEMLOC(j + 1, i + 1);
            int fill = (BITMAP[MEMLOC] == '1') ? 255 : 0;
            SDL_SetRenderDrawColor(renderer, fill, fill, fill, 255);
            SDL_RenderDrawPoint(renderer, (j+1), (i+1));
        }
    }
    // some whitespace
}

void RENDER()
{
    clock_t cStart = clock();
    FLUSH;
    DISPLAY();
    SDL_RenderPresent(renderer);
    // RESET();
    WAIT();
    clock_t cEnd = clock();
    printf("END: %f", (double) (cEnd - cStart) / CLOCKS_PER_SEC);
}

void WAIT()
{
    SDL_Delay(REFRESH_TIME);
    // #ifdef _WIN32
    //     int waitTime = wT;
    //     clock_t cStart = clock();
    //     while (clock() < cStart + waitTime)
    //     {
    //         ;
    //     }
    // #else
    //     struct timespec ts;
    //     ts.tv_sec = wT / 1000;
    //     ts.tv_nsec = (wT % 1000) * 1000000;
    //     nanosleep(&ts, NULL);
    // #endif
}

int GET_MEMLOC(int x, int y)
{
    int MEMLOC = (((y - 1) * WIDTH) + x) - 1;
    return (0 < MEMLOC < TPIXEL) ? MEMLOC : -1;
}

void CHK_BUF()
{
    ISBUFFER2FLAG = (BITMAP == BUFFER2);
}

void CHG_BUF()
{
    BITMAP = (ISBUFFER2FLAG) ? BUFFER1 : BUFFER2;
    ISBUFFER2FLAG = !ISBUFFER2FLAG;
}

void LOAD_BUF(int frame)
{
    // get the frame from the FFMPEG 'API'
    BG_BITMAP = (ISBUFFER2FLAG) ? BUFFER1 : BUFFER2;
    char filename[200];
    sprintf(filename, "./out/%d.txt", frame);
    fileP = fopen(filename, "r");
    fgets(BG_BITMAP, TPIXEL+1, fileP);
    fclose(fileP);
    fileP = NULL;
}

void printA(int *pArr, int pArrLen)
{
    for (int i = 0; i < pArrLen; i++)
    {
        printf("->%d\n", pArr[i]);
    }
}