#ifndef H_ASSERT
 #define H_ASSERT

#ifdef NDEBUG
#define assert(x)
#else
#include <stdio.h>
#define assert(x) do { if (!(x)) printf("ASSERTION FAILURE (" #x ") at " __FILE__ ":%d\n", __LINE__); } while (0)
#endif

#endif /* H_ASSERT */
