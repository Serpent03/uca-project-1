#include <stdio.h>
#include <stdlib.h>
#include "render.h"
// #include <SDL2/SDL.h>

// SDL2 is to be used. let's get it started first,
// then we will start making the orbital simulator or even a matplotlib clone !

int BITMAP[TPIXEL];

int main()
{
    printf("%d\n", TPIXEL);
    SET();
    DISPLAY();
    printf("%d\b", TPIXEL);

}


