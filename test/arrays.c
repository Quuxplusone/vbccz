#include <assert.h>
#include <stdio.h>

char gx[2][8] = { "one", "seven" };

void test_global_arrays()
{
    assert(gx[0][0] == 'o');
    assert(gx[0][3] == '\0');
    assert(gx[1][0] == 's');
    assert(gx[1][5] == '\0');
}

char uc;
void test_uninitialized_char()
{
    static char sc;
    assert(sc == 0); sc = 42; assert(sc == 42);
    assert(uc == 0); uc = 42; assert(uc == 42);
}

int main()
{
    test_global_arrays();
    test_uninitialized_char();

    puts("SUCCESS!");
}
