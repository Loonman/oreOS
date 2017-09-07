 /* The C function */
#include "io/log.h"
#include "io/serial.h"
#include "memory/gdt.h"
#include "memory/idt.h"
#include "io/write.h"
void kernel_main()
{
    serial_configure_baud_rate(SERIAL_COM1_BASE, 12);
    serial_configure_line(SERIAL_COM1_BASE);
    //Install the new gdt
    char gdt[10] = "init gdt\r\n";
    char  gdtDone[5] = "done\r";
    LOG_INFO(gdt, 10);
    gdt_init();
    LOG_INFO(gdtDone, 5);

    char idt[9] = "init idt\r";
    char  idtDone[5] = "done\r";
    LOG_INFO(idt, 9);
    idt_init();
    LOG_INFO(idtDone, 5);
    //durdle around a bit
        char b[5] = "hell\r";
    LOG_INFO(b, 5);
    LOG_DEBUG(b, 5);
    LOG_ERROR(b, 5);
    LOG_FATAL(b, 5);
}