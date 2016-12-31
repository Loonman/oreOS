#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/** outb:
*  Sends the given data to the given I/O port. Defined in io.s
*
*  @param port The I/O port to send the data to
*  @param data The data to send to the I/O port
*/
void outb(unsigned short port, unsigned char data);


/** inb:
*  Read a byte from an I/O port.
*
*  @param  port The address of the I/O port
*  @return      The read byte
*/
unsigned char inb(unsigned short port);

#endif /* INCLUDE_IO_H */