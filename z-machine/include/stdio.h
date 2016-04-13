#ifndef H_STDIO
 #define H_STDIO

#include <stdarg.h>
#include <stddef.h>

#define EOF (-1)

typedef struct _Neverdefined FILE;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

void printf(const char *fmt, ...);
void puts(const char *);
void putc(int, FILE *);
char *fgets(char *buffer, int len, FILE *in);

void fprintf(FILE *, const char *fmt, ...);
void vprintf(const char *fmt, va_list ap);

void sprintf(char *buf, const char *fmt, ...);

void fflush(FILE *) = "";
void clearerr(FILE *) = "";

void fprintf(FILE *, const char *fmt, ...);

#endif /* H_STDIO */
