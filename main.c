#include <stdio.h>
#include <errno.h>
#include "gameboy.h"


int main(int argc, char** argv)
{
    int err;
    gb_t gb;

    if(argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        exit(-EINVAL);
    }

    puts("gbv starting");
    if((err = gb_init(&gb)) != 0) {
        printf("Error: gb_init returned %i\n", err);
        exit(-EINVAL);
    }

    FILE* rf = fopen(argv[1], "r");
    if(!rf) {
        printf("Error opening rom: %s\n", argv[1]);
        exit(-EINVAL);
    }

    fseek(rf, 0, SEEK_END);
    int rom_size = ftell(rf);
    fseek(rf, 0, SEEK_SET);

    uint8_t* rom = malloc(rom_size);
    int len = fread(rom, 1, rom_size, rf);
    fclose(rf);

    if(len < rom_size) {
        printf("Error reading rom: %s\n", argv[1]);
        exit(-EINVAL);
    }

    printf("Loading \"%s\" (%i bytes)\n", argv[1], rom_size);
    if((err = gb_load(&gb, rom, rom_size)) != 0) {
        printf("Error: gb_load returned %i\n", err);
        exit(-EINVAL);
    }

    gb_close(&gb);
    puts("gbv done");

    return 0;
}
