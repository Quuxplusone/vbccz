#include <assert.h>
#include <stdio.h>

struct S {
    unsigned f : 10;
};

void ice1(int x)
{
    static int a[1][1];
    int i;
    x = (0 * (a[0][0] + (i=2))) >> x; assert(i == 2); assert(x == 0);
    x = (0 / (a[0][0] + (i=3))) >> x; assert(i == 3); assert(x == 0);
}

int main()
{
    struct S s; (s.f = 42) + 0; assert(s.f == 42);
    ice1(0);
    puts("SUCCESS!");
}
