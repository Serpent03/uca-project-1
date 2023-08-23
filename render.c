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

int iter = 1;

int main()
{
    FLUSH;
    CHG_BUF(); // FRAME 2 UP
    SET();     // just flip buffer 2 to up for now

    while (iter <= 60)
    {
        CHG_BUF(); // FRAME 1 UP
        LOAD_BUF((iter % 4) + 1); // edit 2 here
        RENDER();
        iter++;
        CHG_BUF(); // FRAME 2 UP
        LOAD_BUF((iter % 4) + 1); // edit 1 here
        RENDER();

        iter++;
    }
}
