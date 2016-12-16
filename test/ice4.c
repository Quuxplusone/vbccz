#include <stdio.h>

struct S {
   int f;
};

void unroll_reverse()
{
    struct S s;
    for (s.f = 0; s.f <= 10; s.f += 1);
}

int main()
{
    unroll_reverse();
    puts("SUCCESS!");
}
