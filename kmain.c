 /* The C function */
#include "io/log.h"
#include "io/serial.h"
void kernel_main()
{
    //durdle around a bit
    serial_configure_baud_rate(SERIAL_COM1_BASE, 12);
    serial_configure_line(SERIAL_COM1_BASE);
    char b[5] = "hell\r";
    LOG_INFO(b, 5);
    LOG_DEBUG(b, 5);
    LOG_ERROR(b, 5);
    LOG_FATAL(b, 5);
}