#include <stdio.h>
#include <stdlib.h>
// #include <graphics.h>
// #include <SDL2/SDL.h>

// SDL2 is to be used. let's get it started first,
// then we will start making the orbital simulator or even a matplotlib clone !

#define WIDTH 80
#define HEIGHT 40
#define T_PIXEL WIDTH * HEIGHT
int BITMAP[T_PIXEL];

void RESET()
{
    for (int i = 0; i < T_PIXEL; i++)
    {
        BITMAP[i] = 0;
    }
}

void printA(int* pArr, int pArrLen)
{
    for (int i = 0; i < pArrLen; i++)
    {
        printf("->%d\n", pArr[i]);
    }
}

int main()
{
    printf("%d", T_PIXEL);
    printA(BITMAP, T_PIXEL);
}


