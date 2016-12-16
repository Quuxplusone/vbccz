#include <assert.h>
#include <stdio.h>

typedef struct {
   int f;
} S;

S u = {2}, *p = &u;

void f(S x, S y)
{
    assert(x.f == 2);
    assert(y.f == 2);
}

int main()
{
    f(*p, *p);

    puts("SUCCESS!");
}
