global gdt_load
KERNEL_CS equ 0x08 ;Kernel code segment
KERNEL_DS equ 0x10 ;Kernel data segment

section .text

gdt_load:
    mov eax, [esp+4]     ;Get the gdt struct from the stack
    lgdt[eax]           ;Load the global descriptor table
    ;To set the cs we need to do a far jump, including the segment and offset
    jmp KERNEL_CS:.gdt_flush

.gdt_flush:
    mov ax, KERNEL_DS
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov gs, ax
    mov fs, ax
    ret
