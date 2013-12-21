#include "gameboy.h"
#include "registers.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int8_t gameboy_init(gameboy_t* gb)
{
    if(!gb) {
        return -EINVAL;
    }

    memset(gb->rom_bank, 0x00, 0x100 * sizeof(uint8_t*));
    memset(gb->ram_bank, 0x00, 0x004 * sizeof(uint8_t*));
    gb->mbc = 0;
    gb->num_rom_banks = 0;
    gb->has_timer = 0;

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

int8_t gameboy_load(gameboy_t* gb, uint8_t* rom, size_t len)
{
    /* Check we can fill the first rom bank */
    if(len < 0x4000) {
        return -EINVAL;
    }

    /* Load the first bank */
    uint8_t* b0 = malloc(0x4000);
    memcpy(b0, rom, 0x4000);
    gb->rom_bank[0] = b0;

    /* Print the title */
    char title[0x10];
    snprintf(title, 0x10, "%s", gb->rom_bank[0] + 0x134);
    printf("title: %s\n", title);

    /* Determine the cartridge type */
    int type = gb->rom_bank[0][0x147];
    printf("type: %#x\n", type);

    gb->mbc = 0;
    if(type >= 0x1 && type <= 0x3) {
        gb->mbc = 1;
    } else if(type == 0x5 || type == 0x6) {
        gb->mbc = 2;
    } else if(type >= 0x0F && type <= 0x13) {
        gb->mbc = 3;
    } else if(type >= 0x15 && type <= 0x17) {
        gb->mbc = 4;
    } else if(type >= 0x19 && type <= 0x1E) {
        gb->mbc = 5;
    }

    int rom_size = gb->rom_bank[0][0x148];
    if(rom_size == 0) {
        gb->num_rom_banks = 2;
    } else if(rom_size == 1) {
        gb->num_rom_banks = 4;
    } else if(rom_size == 2) {
        gb->num_rom_banks = 8;
    } else if(rom_size == 3) {
        gb->num_rom_banks = 16;
    } else if(rom_size == 4) {
        gb->num_rom_banks = 32;
    } else if(rom_size == 5) {
        gb->num_rom_banks = 64;
    } else if(rom_size == 6) {
        gb->num_rom_banks = 128;
    } else if(rom_size == 7) {
        gb->num_rom_banks = 256;
    } else if(rom_size == 0x52) {
        gb->num_rom_banks = 72;
    } else if(rom_size == 0x53) {
        gb->num_rom_banks = 80;
    } else if(rom_size == 0x54) {
        gb->num_rom_banks = 96;
    }
    printf("rom size: %#x (%i bytes across %i banks)\n",
            gb->num_rom_banks * 8192,
            gb->num_rom_banks * 8192,
            gb->num_rom_banks);

    int ram_size;
    if(gb->rom_bank[0][0x149] == 0) {
        ram_size = 0;  /* none!? */
    } else if(gb->rom_bank[0][0x149] == 1) {
        ram_size = 0x800;  /*  2KB */
    } else if(gb->rom_bank[0][0x149] == 2) {
        ram_size = 0x2000; /*  8KB */
    } else if(gb->rom_bank[0][0x149] == 3) {
        ram_size = 0x8000; /* 16KB */
    } else {
        fprintf(stderr, "invalid ram_size %i in header\n", gb->rom_bank[0][0x149]);
        return -EINVAL;
    }
    printf("ram size: %#x (%i bytes)\n", ram_size, ram_size);

    puts("loading rom banks");
    /* Create and fill the other rom banks */
    for(int i = 1; i < gb->num_rom_banks; ++i) {
        if(i*0x4000 >= len) {
            fprintf(stderr, "rom image smaller than expected. Aborting.\n");
            return -EINVAL;
        }
        uint8_t* b = malloc(0x4000);
        memcpy(b, rom + (i * 0x4000), 0x4000);
        gb->rom_bank[i] = b;
    }

    puts("rom banks loaded");

    /* Create the ram banks */

    return 0;
}

int8_t gameboy_step(gameboy_t* gb)
{
    return -ENOSYS;
}
