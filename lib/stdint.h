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
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
#ifdef __64_BIT
typedef long long int64_t;
#endif // __64_BIT

#ifndef __64_BIT
typedef uint32_t size_t;
#else // __64_BIT
typedef uint64_t size_t;
#endif // __64_BIT

#endif /* STDINT_H */