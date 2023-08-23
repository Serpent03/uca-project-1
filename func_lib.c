#include <stdlib.h>
#include <stdio.h>
#include "render.h"

void printA(int *pArr, int pArrLen)
{
    for (int i = 0; i < pArrLen; i++)
    {
        printf("->%d\n", pArr[i]);
    }
}

int GET_MEMLOC(int x, int y)
{
    int MEMLOC = (((y - 1) * WIDTH) + x) - 1;
    return (0 < MEMLOC < TPIXEL) ? MEMLOC : -1;
}

void DISPLAY()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      int MEMLOC = GET_MEMLOC(j + 1, i + 1);
      (BITMAP[MEMLOC] == 1) ? printf("`") : printf(" ");
    }
    printf("\n");
  }
  printf("\n");
}


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