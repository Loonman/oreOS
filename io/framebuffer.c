#include "framebuffer.h"
#include "io.h"

uint8_t * fb = (uint8_t *) 0x000B8010;

void fb_write_cell(uint8_t c, uint8_t fg, uint8_t bg, uint32_t pos)
{
    fb[pos] = c;
    fb[pos + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

/** fb_move_cursor:
*  Moves the cursor of the framebuffer to the given position
*
*  @param pos The new position of the cursor
*/
void fb_move_cursor(uint16_t pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

