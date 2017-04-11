#ifndef H_STDLIB
 #define H_STDLIB

#include <stddef.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void exit(int status) = "\t@quit;\n";

int abs(int x);
int atoi(const char *str);

void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);
void qsort(void *, size_t, size_t, int (*)(const void *, const void *));

#endif /* H_STDLIB */
