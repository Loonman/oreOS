#include "color.h"
#include "../lib/stdint.h"

struct frame {
    uint16_t background_color : 4;
    uint16_t foreground_color : 4;
    char letter;
} __attribute__((packed));

typedef struct frame frame;

/**
 * Writes a character from frame to the framebuffer at position i
 * @param frame - the frame to Writes
 * @param pos - the position in the framebuffer
 */
void fb_write_cell(char c, uint8_t fg, uint8_t bg, uint32_t pos);

void fb_move_cursor(uint16_t pos);

int write(uint8_t * buf, uint32_t len);