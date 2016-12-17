#include <assert.h>
#include <stdio.h>
#include <limits.h>

long g = 1234;
long *pg = &g;

long add(long x, long y) { return x + y; }
void varargs(int x, int y, ...) { assert(x == 0 && y == 3); }

int main()
{
    *pg = add(1,2);
    varargs(0, g);
    return 0;
}
/*
When compiled at -O3:
    ASSERTION FAILURE (x == 0 && y == 3) at todo3.c:9
When compiled at -O0, no problem.
*/
