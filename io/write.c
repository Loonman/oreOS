#include "write.h"
#include "framebuffer.h"
unsigned short cursor = 0;

int write(char * buf, unsigned int len)
{
    unsigned int i  = 0;
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
