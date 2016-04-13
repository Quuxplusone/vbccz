#ifndef H_STDINT
 #define H_STDINT

typedef signed char int8_t;
typedef unsigned char uint8_t;
#define INT8_MIN (-128)
#define INT8_MAX 127
#define UINT8_MAX 255

typedef signed int int16_t;
typedef unsigned int uint16_t;
#define INT16_MIN (-32767 - 1)
#define INT16_MAX 32767
#define UINT16_MAX 65535U

typedef signed int intptr_t;
typedef unsigned int uintptr_t;
#define INTPTR_MIN (-32767 - 1)
#define INTPTR_MAX 32767
#define UINTPTR_MAX 65535U

typedef signed long int32_t;
typedef unsigned long uint32_t;
#define INT32_MIN (-2147483647L - 1)
#define INT32_MAX (2147483647L)
#define UINT32_MAX (4294967295UL)

typedef signed long intmax_t;
typedef unsigned long uintmax_t;
#define INTMAX_MIN (-2147483647L - 1)
#define INTMAX_MAX (2147483647L)
#define UINTMAX_MAX (4294967295UL)

#endif /* H_STDINT */
