#ifndef H_ASSERT
 #define H_ASSERT

#ifdef NDEBUG
#define assert(x)
#else
#include <stdio.h>
#define assert(x) do { if (!(x)) puts("ASSERTION FAILURE (" #x ")"); } while (0)
#endif

#endif /* H_ASSERT */
