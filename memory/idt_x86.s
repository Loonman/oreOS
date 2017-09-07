global idt_load
extern _idtp
idt_load:
    lidt[_idtp]
    ret
