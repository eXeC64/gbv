#ifndef GAMEBOY_H
#define GAMEBOY_H

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint16_t af;  /* A and F registers */
    uint16_t bc;  /* B and C registers */
    uint16_t de;  /* D and E registers */
    uint16_t hl;  /* H and L registers */
    uint16_t sp;  /* Stack pointer     */
    uint16_t pc;  /* Program counter   */

    uint8_t  mbc;             /* Memory Bank Controller version   */
    uint8_t  has_timer;       /* Does the cartridge have a timer? */
    uint8_t* rom_bank[0x100]; /* Array of rom bank pointers       */
    uint8_t* ram_bank[0x4];   /* Array of ram bank pointers.      */
    uint16_t num_rom_banks;   /* The quantity of rom banks to use */
    uint8_t  num_ram_banks;   /* The quantity of ram banks to use */
    uint16_t ram_size;        /* How much ram there is in total   */
} gameboy_t;

int8_t gameboy_init(gameboy_t* gb);
int8_t gameboy_close(gameboy_t* gb);
int8_t gameboy_reset(gameboy_t* gb);
int8_t gameboy_load(gameboy_t* gb, uint8_t* rom, size_t len);
int8_t gameboy_step(gameboy_t* gb);

#endif /* GAMEBOY_H */
