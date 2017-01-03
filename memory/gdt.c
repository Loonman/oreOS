#include "gdt.h"

/* Our GDT, with 3 entries, and our special GDT pointer */
struct gdt_entry gdt[GDT_ENTRIES];

/* Setup a descriptor in the Global Descriptor Table */
void gdt_set_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
    /* Setup the descriptor base address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_mid = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}


void gdt_init()
{
    struct gdt_ptr gp;
    gp.size = sizeof(struct gdt_entry) * GDT_ENTRIES;
    gp.address = (uint32_t)&gdt;

    /* Our NULL descriptor */
    gdt_set_gate(0, 0, 0, 0, 0);

    /* The second entry is our Code Segment. The base address
    *  is 0, the limit is 4GBytes, it uses 4KByte granularity,
    *  uses 32-bit opcodes, and is a Code Segment descriptor.
    *  Please check the table above in the tutorial in order
    *  to see exactly what each value means */
    gdt_set_gate(1, SEGMENT_BASE, SEGMENT_LIMIT, 0x9A, 0xCF);

    /* The third entry is our Data Segment. It's EXACTLY the
    *  same as our code segment, but the descriptor type in
    *  this entry's access byte says it's a Data Segment */
    gdt_set_gate(2, SEGMENT_BASE, SEGMENT_LIMIT, 0x92, 0xCF);

    /* Flush out the old GDT and install the new changes! */
    gdt_load((uint32_t)&gp);
}