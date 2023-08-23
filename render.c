#include <stdio.h>
#include <stdlib.h>
#include "render.h"

int BUFFER1[TPIXEL];
int BUFFER2[TPIXEL];
int *BITMAP = BUFFER1;
int ISBUFFER2FLAG = 0;

int PROCESSING = 1;

// simulate BAD APPLE
// STEPS:
// BUFFER SWITCH MECHANISM ✅
// CREATE A REUPDATING DISPLAY ✅
// READ FROM FILE INTO BITMAP 
// RENDER BITMAP AND DISPLAY

int iter = 0;

int main()
{
    FLUSH;
    CHG_BUF();
    SET(); // just flip buffer 2 to up for now

    while (iter < 100)
    {

        CHG_BUF();
        DISPLAY();

        WAIT(100);

        CHG_BUF();
        DISPLAY();

        WAIT(100);

        iter++;
    }
}
