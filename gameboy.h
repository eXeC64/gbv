#ifndef GAMEBOY_H
#define GAMEBOY_H

#include <stdint.h>

typedef struct {
    uint16_t af;  /* A and F registers */
    uint16_t bc;  /* B and C registers */
    uint16_t de;  /* D and E registers */
    uint16_t hl;  /* H and L registers */
    uint16_t sp;  /* Stack pointer     */
    uint16_t pc;  /* Program counter   */

    uint8_t header[0x50];     /* Cartridge header 0x100-0x14F */
    uint8_t* rom_bank[0x100]; /* Array of rom bank pointers   */
    uint8_t* ram_bank[0x4];   /* Array of ram bank pointers.  */
} gameboy_t;

int8_t gameboy_init(gameboy_t* gb);
int8_t gameboy_close(gameboy_t* gb);
int8_t gameboy_reset(gameboy_t* gb);
int8_t gameboy_load(gameboy_t* gb, uint8_t* rom);
int8_t gameboy_step(gameboy_t* gb);

#endif /* GAMEBOY_H */
