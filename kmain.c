 /* The C function */
#include "io/serial.h"
#include "io/io.h"
#include "io/framebuffer.h"
void kernel_main()
{
    //durdle around a bit
    serial_configure_baud_rate(SERIAL_COM1_BASE, 12);
    serial_configure_line(SERIAL_COM1_BASE);
    while(!serial_is_transmit_fifo_empty(SERIAL_COM1_BASE))
    {
        
    }
    outb(SERIAL_COM1_BASE, 100);
    fb_write_cell(100, FB_BLACK, FB_WHITE, 0);
 
    //serial_write("Test post please ignore", 24, 0);
}