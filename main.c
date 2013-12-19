#include <stdio.h>
#include "gameboy.h"

int main(int argc, char** argv)
{
    gameboy_t gb;

    puts("gbv starting");
    gameboy_init(&gb);



    gameboy_close(&gb);
    puts("gbv done");

    return 0;
}
