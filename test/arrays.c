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

int g[2];
void f(int *g) { *g = 15; }
struct { int x; int y; } s;
void test_offsets()
{
    g[0] = 1; g[1] = 2; f(g); assert(g[0] == 15); assert(g[1] == 2);
    g[0] = 3; g[1] = 4; f(g+0); assert(g[0] == 15); assert(g[1] == 4);
    g[0] = 5; g[1] = 6; f(g+1); assert(g[0] == 5); assert(g[1] == 15);
    g[0] = 3; g[1] = 4; f(&g[0]); assert(g[0] == 15); assert(g[1] == 4);
    g[0] = 5; g[1] = 6; f(&g[1]); assert(g[0] == 5); assert(g[1] == 15);
    s.x = 1; s.y = 2; f(&s.x); assert(s.x == 15); assert(s.y == 2);
    s.x = 1; s.y = 2; f(&s.y); assert(s.x == 1); assert(s.y == 15);
}

int main()
{
    test_global_arrays();
    test_static_arrays();
    test_automatic_arrays();
    test_uninitialized_char();
    test_offsets();

    puts("SUCCESS!");
}
