#ifndef H_STDLIB
 #define H_STDLIB

#ifndef NULL
 #define NULL 0
#endif /* NULL */

void exit(int status) = "\t@quit;\n";

inline int abs(int x) { return (x < 0) ? -x : x; }

int atoi(const char *str);

#include <stddef.h>
void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);
void memcpy(void*, void*, size_t);
int memcmp(void*, void*, size_t);

#endif /* H_STDLIB */
