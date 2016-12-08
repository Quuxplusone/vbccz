#include <assert.h>
#include <stdio.h>

struct S {
    unsigned f : 10;
};

int main()
{
    struct S s; (s.f = 42) + 0; assert(s.f == 42);

    puts("SUCCESS!");
}
