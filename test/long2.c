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
