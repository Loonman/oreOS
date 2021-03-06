#include "io.h"
#include "serial.h"
/* The I/O ports */


/** serial_configure_baud_rate:
    *  Sets the speed of the data being sent. The default speed of a serial
    *  port is 115200 bits/s. The argument is a divisor of that number, hence
    *  the resulting speed becomes (115200 / divisor) bits/s.
    *
    *  @param com      The COM port to configure
    *  @param divisor  The divisor
    */
void serial_configure_baud_rate(uint16_t com, uint16_t divisor)
{
    outb(SERIAL_LINE_COMMAND_PORT(com),SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com),(divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

/** serial_configure_line:
*  Configures the line of the given serial port. The port is set to have a
*  data length of 8 bits, no parity bits, one stop bit and break control
*  disabled.
*
*  @param com  The serial port to configure
*/
void serial_configure_line(uint16_t com)
{
    /* Bit:     | 7 | 6 | 5 4 3 | 2 | 1 0 |
     * Content: | d | b | prty  | s | dl  |
     * Value:   | 0 | 0 | 0 0 0 | 0 | 1 1 | = 0x03
     */
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

uint32_t serial_is_transmit_fifo_empty(uint32_t com)
{
    /* 0x20 = 0010 0000 */
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

uint32_t serial_write(char * buf, uint32_t len, uint16_t com)
{
    uint32_t i = 0;
    while (i < len)
    {
        if (serial_is_transmit_fifo_empty(com))
        {
            outb(SERIAL_DATA_PORT(com), *buf);
            buf++;
            i++;
        }
    }
    return i;
}