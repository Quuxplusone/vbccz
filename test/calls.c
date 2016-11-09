#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

static int a() { return 1; }
int b(int x) { return x; }
int c() { return 3; }

void regular_function(int a, int b, int c)
{
    assert(a == 1);
    assert(b == 2);
    assert(c == 3);
}

void variadic_function(int a, ...)
{
    va_list ap;
    va_start(ap, a);
    int b = va_arg(ap, int);
    int c = va_arg(ap, int);
    va_end(ap);
    assert(a == 1);
    assert(b == 2);
    assert(c == 3);
}

int main()
{
    regular_function(a(), b(2), c());
    variadic_function(a(), b(2), c());
    puts("SUCCESS!");
}
