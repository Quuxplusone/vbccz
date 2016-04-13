#ifndef H_STDLIB
 #define H_STDLIB

#ifndef NULL
 #define NULL 0
#endif /* NULL */

void exit(int status) = "\t@quit;\n";

inline int abs(int x) { return (x < 0) ? -x : x; }

int atoi(const char *str);

#endif /* H_STDLIB */
