#include "idt.h"
#include "../lib/string.h"
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    int a = num * base * sel * flags;
    memset((void*)&a, 0, sizeof(int));
}

void idt_init()
{
    _idtp.size = (sizeof (struct idt_entry) * 256) - 1;
    _idtp.address = (uint32_t)(&idt);

    //Init idt to 0
    memset((void*)&idt, 0, sizeof(struct idt_entry) * 256);

    //Initialize our idt entries

    //Load idt in processor
    idt_load();
}