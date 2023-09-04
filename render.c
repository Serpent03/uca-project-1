#include <stdio.h>
#include <stdlib.h>
#include "render.h"

char BUFFER1[TPIXEL];
char BUFFER2[TPIXEL];
char *BITMAP = BUFFER1;
char *BG_BITMAP;
int ISBUFFER2FLAG = 0;

// simulate BAD APPLE
// STEPS:
// BUFFER SWITCH MECHANISM ✅
// CREATE A REUPDATING DISPLAY ✅
// EDIT NON-DISPLAYING BUFFER ✅
// READ FROM FILE INTO BITMAP ✅
// READ CORRECT SEQUENCE BUFFER ✅
// RENDER BITMAP AND DISPLAY ✅
// INITIAL VIDEO RENDERING ✅
// CORRECT FRAME SEQUENCE RENDERING ✅
// FFMPEG INTEGRATION
// INDIVIDUAL FRAME SEEK BUFFER LOADING
// SDL RENDERING INITIALIZATION
// SDL SOUND INITIALIZATION 

int iter = 1;

int main(int argc, char **argv)
{
    int maxFrame = atoi(argv[1]);
    FLUSH;
    while (iter < maxFrame)
    {
        CHG_BUF();                // FRAME 1 UP
        LOAD_BUF(iter); // edit 2 here
        RENDER();
        iter++;
        CHG_BUF();                // FRAME 2 UP
        LOAD_BUF(iter); // edit 1 here
        RENDER();
        iter++;
    }
}
