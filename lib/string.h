#ifndef STRING_H
#define STRING_H
#include "stdint.h"
uint8_t *memcpy(uint8_t *dest, const uint8_t *src, uint32_t count);
void *memset(void *dest, uint32_t val, uint32_t count);
uint16_t *memsetw(uint16_t *dest, uint16_t val, uint32_t count);
uint32_t strlen(const uint8_t *str);
#endif //STRING_H
