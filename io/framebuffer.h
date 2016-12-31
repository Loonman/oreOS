#include "color.h"
struct frame {
    unsigned short background_color : 4;
    unsigned short foreground_color : 4;
    char letter;
} __attribute__((packed));

typedef struct frame frame;

/**
 * Writes a character from frame to the framebuffer at position i
 * @param frame - the frame to Writes
 * @param pos - the position in the framebuffer
 */
void fb_write_cell(char c, unsigned char fg, unsigned char bg, unsigned int pos);

void fb_move_cursor(unsigned short pos);

int write(char * buf, unsigned int len);