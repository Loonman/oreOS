#ifndef IDT_H
#define IDT_H
#include "../lib/stdint.h"

/**
* High 32 Bits
* Bit:     | 31              16 | 15 | 14 13 | 12 | 11 | 10 9 8 | 7 6 5 | 4 3 2 1 0 |
* Content: | offset high        | P  | DPL   | 0  | D  | 1  1 0 | 0 0 0 | reserved  |
* Low 32 Bits
* Bit:     | 31              16 | 15              0 |
* Content: | segment selector   | offset low        |
* P   - Handler in memory
* DPL - Privilege level (0,1,2,3)
* D   - Size of Gate 1 = 32b 0 = 16b
**/
struct idt_entry 
{
    uint16_t offset_low;
    uint16_t seg_selection;
    uint8_t reserved0;
    uint8_t flags;
    uint16_t offset_high;
} __attribute__((packed));

struct idt_ptr
{
    uint16_t size;
    uint32_t address;
} __attribute__((packed));

struct idt_entry idt[256];
struct idt_ptr _idtp;

extern void idt_load();
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idt_init();
#endif