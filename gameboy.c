#include "gameboy.h"
#include "registers.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int8_t gameboy_init(gameboy_t* gb)
{
    if(!gb) {
        return -EINVAL;
    }

    memset(gb->header, 0x00, 0x50);
    memset(gb->rom_bank, 0x00, 0x100 * sizeof(uint8_t*));
    memset(gb->ram_bank, 0x00, 0x004 * sizeof(uint8_t*));
    return 0;
}

int8_t gameboy_close(gameboy_t* gb)
{
    if(!gb) {
        return -EINVAL;
    }

    for(int i = 0; i < 0x100; ++i) {
        if(gb->rom_bank[i]) {
            free(gb->rom_bank[i]);
        }
    }
    for(int i = 0; i < 0x4; ++i) {
        if(gb->ram_bank[i]) {
            free(gb->ram_bank[i]);
        }
    }
    return 0;
}

int8_t gameboy_reset(gameboy_t* gb)
{
    if(!gb) {
        return -EINVAL;
    }

    gb->af = 0xB011;
    gb->bc = 0x0013;
    gb->de = 0x00D8;
    gb->hl = 0x014D;
    gb->sp = 0xFFFE;
    gb->pc = 0x0100;

    return 0;
}

int8_t gameboy_load(gameboy_t* gb, uint8_t* rom)
{
    return -ENOSYS;
}
