#include <assert.h>
#include <stdio.h>

volatile int x;
volatile int *p = &x;

int main()
{
    assert(p == &x);
    puts("SUCCESS!");
}
