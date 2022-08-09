
#include <stdio.h>
#include <string.h>

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int16_t;
typedef unsigned int uint16_t;
typedef signed long int32_t;
typedef unsigned long uint32_t;

#define INT8_MIN               (-128)
#define INT16_MIN              (-32767-1)
#define INT32_MIN              (-2147483647-1)

#define INT8_MAX               (127)
#define INT16_MAX              (32767)
#define INT32_MAX              (2147483647)

#define UINT8_MAX              (255)
#define UINT16_MAX             (65535)
#define UINT32_MAX             (4294967295U)

#define CHAR_BIT 8

#define STATIC static

#define UNDEFINED(__val) (__val)

#define LOG_INDEX

#define LOG_EXEC

#define FUNC_NAME(x) (safe_##x)

// FIXME
#define assert(x)

static inline void platform_main_begin(void) {}

static inline void crc32_gentab(void) {}

#define _CSMITH_BITFIELD(x) ((x>32)?(x%32):x)

uint32_t crc32_context;

static inline void 
transparent_crc(uint32_t val, char* vname, int flag)
{
  crc32_context += val;
}

static void 
transparent_crc_bytes(char *ptr, int nbytes, char* vname, int flag)
{
  int i;
  for (i=0; i<nbytes; i++) {
    crc32_context += ptr[i];
  }
}

static inline void platform_main_end (uint32_t x, int flag) {}
