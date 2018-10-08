#ifndef STDINT_H
#define STDINT_H

/**
 * Unsigned fixed width integers
 */
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
#ifdef __64_BIT
typedef unsigned long long uint64_t;
#endif // __64_BIT

/**
 * Signed fixed width integers
 */
typedef char uint8_t;
typedef short uint16_t;
typedef int uint32_t;
#ifdef __64_BIT
typedef long long uint64_t;
#endif // __64_BIT

#ifndef __64_BIT
typedef size_t uint32_t;
#else // __64_BIT
typedef size_t uint64_t;
#endif // __64_BIT

#endif /* STDINT_H */