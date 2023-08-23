#include <stdlib.h>
#include <stdio.h>
#include "render.h"
#include <time.h>

void RESET()
{
    for (int i = 0; i < TPIXEL; i++)
    {
        BITMAP[i] = 0;
    }
}

void SET()
{
    for (int i = 0; i < TPIXEL; i++)
    {
        BITMAP[i] = 1;
    }
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
            (BITMAP[MEMLOC] == 1) ? printf(".") : printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < 4; i++)
    {
        printf("\n");
    }
}

void RENDER()
{
    FLUSH;
    DISPLAY();
    WAIT(REFRESH_TIME);
}

void WAIT(int wT)
{
#ifdef _WIN32
    sleep(wT / 1000);
#else
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#endif
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
    BG_BITMAP = (ISBUFFER2FLAG) ? BUFFER1 : BUFFER2;
    char filename[20];
    sprintf(filename, "./out/%d.txt", frame);
    printf("%s\n", filename);
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < TPIXEL; i++)
    {
        fscanf(file, "%d,", &BG_BITMAP[i]);
    }
    fclose(file);
}

void printA(int *pArr, int pArrLen)
{
    for (int i = 0; i < pArrLen; i++)
    {
        printf("->%d\n", pArr[i]);
    }
}