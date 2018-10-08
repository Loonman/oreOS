#include "write.h"
#include "framebuffer.h"
uint16_t cursor = 0;

int write(char * buf, size_t len)
{
    uint32_t i  = 0;
    while (i < len)
    {
        fb_write_cell(*buf, FB_BLACK, FB_WHITE, cursor);
        fb_move_cursor(cursor);
        i++;
        cursor += 2;
        buf++;
    }
    return i;
}
