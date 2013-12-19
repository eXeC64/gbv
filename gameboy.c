#include "gameboy.h"

#include <stdint.h>
#include <stdlib.h>
#include <errno.h>


int8_t gameboy_init(gameboy_t* gb)
{
    if(!gb) {
        return -EINVAL;
    }

    gb->mem = calloc(0x10000, 0x1);
    return 0;
}

int8_t gameboy_close(gameboy_t* gb)
{
    if(!gb) {
        return -EINVAL;
    }

    free(gb->mem);
    return 0;
}

int8_t gameboy_reset(gameboy_t* gb)
{
    return -ENOSYS;
}

int8_t gameboy_load(gameboy_t* gb, uint8_t* rom)
{
    return -ENOSYS;
}
