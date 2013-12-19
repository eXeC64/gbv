#ifndef GAMEBOY_H
#define GAMEBOY_H

#include <stdint.h>

typedef struct {
    uint8_t* mem;
} gameboy_t;

int8_t gameboy_init(gameboy_t* gb);
int8_t gameboy_close(gameboy_t* gb);
int8_t gameboy_reset(gameboy_t* gb);
int8_t gameboy_load(gameboy_t* gb, uint8_t* rom);
int8_t gameboy_step(gameboy_t* gb);

#endif /* GAMEBOY_H */
