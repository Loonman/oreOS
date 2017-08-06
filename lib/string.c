#include "string.h"
#include "stdint.h"
uint8_t *memcpy(uint8_t *dest, const uint8_t *src, uint32_t count)
{
    uint32_t i;
    for(i = 0; i < count; i++)
    {
        //Memory safety never bothered me anyway~
        dest[i] = src[i];
    }
    return dest;
}

void *memset(void *dest, uint32_t val, uint32_t count)
{
    uint32_t i;
    for(i = 0; i < count; i++)
    {
        //Memory safety never bothered me anyway~
        ((uint32_t*)dest)[i] = val;
    }
    return dest;
}

uint32_t strlen(const uint8_t *str)
{
    uint32_t len = 0;
    //All strings end with a null terminator right... right?
    while(*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}
