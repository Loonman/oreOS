#include "log.h"
#include "serial.h"

void LOG_INFO(char * buf, size_t len)
{
    char info[6] = "INFO: ";
    LOG_BASE(buf, len, info, 6);
}

void LOG_DEBUG(char * buf, size_t len)
{
    char debug[7] = "DEBUG: ";
    LOG_BASE(buf, len, debug, 7);
}

void LOG_ERROR(char * buf, size_t len)
{
    char error[7] = "ERROR: ";
    LOG_BASE(buf, len, error, 7);
}

void LOG_FATAL(char * buf, size_t len)
{
    char fatal[7] = "FATAL: ";
    LOG_BASE(buf, len, fatal, 7);
}

void LOG_BASE(char * buf, size_t len, char * prompt, size_t prompt_len)
{
    char new_buf[len + prompt_len];
    size_t i = 0;
    while ( i < prompt_len )
    {
        new_buf[i] = prompt[i];
        i++;
    }
    size_t j = 0;
    while ( j < len )
    {
        new_buf[i++] = buf[j++];
    }
    serial_write(new_buf, len + prompt_len, SERIAL_COM1_BASE);
}
