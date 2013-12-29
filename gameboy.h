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
    uint8_t  ram_enabled;     /* Is the ram enabled currently?    */
    uint16_t cur_rom_bank;    /* The currently mapped rom bank    */
    uint8_t  cur_ram_bank;    /* The currently mapped ram bank    */
} gb_t;

int8_t gb_init(gb_t* gb);
int8_t gb_close(gb_t* gb);
int8_t gb_reset(gb_t* gb);
int8_t gb_load(gb_t* gb, uint8_t* rom, size_t len);
int8_t gb_step(gb_t* gb);

int8_t gb_mem_read(gb_t* gb, uint16_t addr, uint8_t* val);
int8_t gb_mem_write(gb_t* gb, uint16_t addr, uint8_t val);

#endif /* GAMEBOY_H */
