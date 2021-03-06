#ifndef REGISTERS_H
#define REGISTERS_H

/* port and mode registers */
#define R_P1   0xFF00
#define R_SB   0xFF01
#define R_SC   0xFF02
#define R_DIV  0xFF04
#define R_TIMA 0xFF05
#define R_TMA  0xFF06
#define R_TAC  0xFF07
#define R_KEY1 0xFF4D
#define R_RP   0xFF56

/* bank control registers */
#define R_VBK  0xFF4F
#define R_SVBK 0xFF70

/* interrupt registers */
#define R_IF   0xFF0F
#define R_IE   0xFFFF

/* lcd display registers */
#define R_LCDC 0xFF40
#define R_STAT 0xFF41
#define R_SCY  0xFF42
#define R_SCX  0xFF43
#define R_LY   0xFF44
#define R_LYC  0xFF45
#define R_DMA  0xFF46
#define R_BGP  0xFF47
#define R_OBP0 0xFF48
#define R_OBP1 0xFF49
#define R_WY   0xFF4A
#define R_WX   0xFF4B

#define R_HMDA1 0xFF51
#define R_HMDA2 0xFF52
#define R_HMDA3 0xFF53
#define R_HMDA4 0xFF54
#define R_HMDA5 0xFF55
#define R_BCPS  0xFF68
#define R_BCPD  0xFF69
#define R_OCPS  0xFF6A
#define R_OCPD  0xFF6B

/* sound registers */
#define R_NR10 0xFF10
#define R_NR11 0xFF11
#define R_NR12 0xFF12
#define R_NR13 0xFF13
#define R_NR14 0xFF14

#define R_NR21 0xFF16
#define R_NR22 0xFF17
#define R_NR23 0xFF18
#define R_NR24 0xFF19

#define R_NR30 0xFF1A
#define R_NR31 0xFF1B
#define R_NR32 0xFF1C
#define R_NR33 0xFF1D
#define R_NR34 0xFF1E

#define R_NR41 0xFF20
#define R_NR42 0xFF21
#define R_NR43 0xFF22
#define R_NR44 0xFF23

#define R_NR50 0xFF24
#define R_NR51 0xFF25
#define R_NR52 0xFF26

#endif /* REGISTERS_H */
