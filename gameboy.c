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
    if(!gb) {
        return -EINVAL;
    }

    /* Zero out all working memory */
    memset(gb->mem, 0x00, 0x10000);

    gb->af = 0xB011;
    gb->bc = 0x0013;
    gb->de = 0x00D8;
    gb->hl = 0x014D;
    gb->sp = 0xFFFE;
    gb->pc = 0x0100;

    /* Initial values taken from Game Boy CPU Manual */
    /* Version 1.01 - Section 2.7.1 - Page 18 */
    gb->mem[R_NR10] = 0x80;
    gb->mem[R_NR11] = 0xBF;
    gb->mem[R_NR12] = 0xF3;
    gb->mem[R_NR14] = 0xBF;

    gb->mem[R_NR21] = 0x3F;
    gb->mem[R_NR24] = 0xBF;

    gb->mem[R_NR30] = 0x7F;
    gb->mem[R_NR31] = 0xFF;
    gb->mem[R_NR32] = 0x9F;
    gb->mem[R_NR33] = 0xBF;

    gb->mem[R_NR41] = 0xFF;
    gb->mem[R_NR44] = 0xBF;

    gb->mem[R_NR50] = 0xFF;
    gb->mem[R_NR50] = 0xFF;
    gb->mem[R_NR51] = 0xF3;
    gb->mem[R_NR52] = 0xF1;

    gb->mem[R_LCDC] = 0x90;
    gb->mem[R_BGP]  = 0xFC;
    gb->mem[R_OBP0] = 0xFF;
    gb->mem[R_OBP1] = 0xFF;

    return 0;
}

int8_t gameboy_load(gameboy_t* gb, uint8_t* rom)
{
    return -ENOSYS;
}
