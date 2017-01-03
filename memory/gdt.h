#ifndef GDT_H
#define GDT_H
#include "../lib/stdint.h"

#define SEGMENT_BASE    0
#define SEGMENT_LIMIT   0xFFFFFFFF

#define CODE_RX_TYPE    0xA
#define DATA_RW_TYPE    0x2
#define PL0 0x0
#define PL3 0x3

#define GDT_ENTRIES 3

struct gdt_entry 
{
    uint16_t limit_low;     // The lower 16 bits of the limit
    uint16_t base_low;      // The lower 16 bits of the base
    uint8_t  base_mid;      // The next 8 bits of the base
    uint8_t  access;        // Contains access flags
    uint8_t  granularity;   // Granularity, and 4 bits of limit
    uint8_t  base_high;     // The last 8 bits of the base;
} __attribute__((packed));  

struct gdt_ptr 
{
    uint16_t size;
    uint32_t address;
} __attribute__((packed));


void gdt_load(uint32_t gdt_ptr);

void gdt_set_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

void gdt_init();

#endif // GDT_H
