#include <stdio.h>
#include <stdlib.h>
#include "render.h"

int BUFFER1[TPIXEL];
int BUFFER2[TPIXEL];
int *BITMAP = BUFFER1;
int *BG_BITMAP;
int ISBUFFER2FLAG = 0;

int PROCESSING = 1;

// simulate BAD APPLE
// STEPS:
// BUFFER SWITCH MECHANISM ✅
// CREATE A REUPDATING DISPLAY ✅
// EDIT NON-DISPLAYING BUFFER ✅
// READ FROM FILE INTO BITMAP
// RENDER BITMAP AND DISPLAY

int iter = 0;

void RANDOM_BUF()
{
    BG_BITMAP = (ISBUFFER2FLAG) ? BUFFER1 : BUFFER2;
    for (int i = 0; i < TPIXEL; i++)
    {
        BG_BITMAP[i] = (rand() % 2 == 0);
    }
}

int main()
{
    FLUSH;
    CHG_BUF(); // 2
    SET();     // just flip buffer 2 to up for now

    while (iter < 100)
    {
        CHG_BUF(); // 1
        // edit 2 here??
        RANDOM_BUF();
        RENDER();

        CHG_BUF(); // 2
        // edit 1 here??
        RANDOM_BUF();
        RENDER();

        iter++;
    }
}
