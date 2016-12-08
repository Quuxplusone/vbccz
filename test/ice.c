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

void ice2(int x)
{
    if (0) {
        if (0) { L1:; } else {}
    }
    if (0) {
        if (x) { L2:; } else {}
    }
    if (0) {
        if (1) { L3:; } else {}
    }
}

int main()
{
    struct S s; (s.f = 42) + 0; assert(s.f == 42);
    ice1(0);
    ice2(0);
    ice2(1);
    puts("SUCCESS!");
}
