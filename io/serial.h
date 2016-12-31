#ifndef SERIAL_H
#define SERIAL_H

/** serial_configure_baud_rate:
*  Sets the speed of the data being sent. The default speed of a serial
*  port is 115200 bits/s. The argument is a divisor of that number, hence
*  the resulting speed becomes (115200 / divisor) bits/s.
*
*  @param com      The COM port to configure
*  @param divisor  The divisor
*/
void serial_configure_baud_rate(unsigned short com, unsigned short divisor);

/** serial_configure_line:
*  Configures the line of the given serial port. The port is set to have a
*  data length of 8 bits, no parity bits, one stop bit and break control
*  disabled.
*
*  @param com  The serial port to configure
*/
void serial_configure_line(unsigned short com);

int serial_write(char * buf, unsigned int len);

#endif /* SERIAL_H */