#include <assert.h>
#include <stdio.h>

char ga[2][8] = { "one", "seven" };
char seven[] = "seven";
static char *gp[2] = { "one", seven };

void test_global_arrays()
{
    assert(ga[0][0] == 'o');
    assert(ga[0][3] == '\0');
    assert(ga[1][0] == 's');
    assert(ga[1][5] == '\0');
    assert(gp[0][0] == 'o');
    assert(gp[0][3] == '\0');
    assert(gp[1][0] == 's');
    assert(gp[1][5] == '\0');
}

void test_static_arrays()
{
    static char eight[] = "eight";
    static char *lp[3] = { "one", seven, eight };
    assert(lp[0][0] == 'o');
    assert(lp[0][3] == '\0');
    assert(lp[1][0] == 's');
    assert(lp[1][5] == '\0');
    assert(lp[2][0] == 'e');
    assert(lp[2][5] == '\0');
}

void test_automatic_arrays()
{
    static char eight[] = "eight";
    char nine[] = "nine";
    char *lp[4] = { "one", seven, eight, nine };
    assert(lp[0][0] == 'o');
    assert(lp[0][3] == '\0');
    assert(lp[1][0] == 's');
    assert(lp[1][5] == '\0');
    assert(lp[2][0] == 'e');
    assert(lp[2][5] == '\0');
    assert(lp[3][0] == 'n');
    assert(lp[3][4] == '\0');
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
    test_static_arrays();
    test_automatic_arrays();
    test_uninitialized_char();

    puts("SUCCESS!");
}
