#include <assert.h>
#include <stdio.h>

unsigned long array_of_long[1] = {42};
char ga[2][8] = { "one", "seven" };
char seven[] = "seven";
static char *gp[3] = { "one", NULL, seven };
char array_of_one[1] = {'x'};

void test_global_arrays()
{
    assert(array_of_one[0] == 'x');
    assert(array_of_long[0] == 42);
    assert(ga[0][0] == 'o');
    assert(ga[0][3] == '\0');
    assert(ga[1][0] == 's');
    assert(ga[1][5] == '\0');
    assert(gp[0][0] == 'o');
    assert(gp[0][3] == '\0');
    assert(gp[1] == NULL);
    assert(gp[2][0] == 's');
    assert(gp[2][5] == '\0');
}

void test_static_arrays()
{
    static char array_of_one[1] = {'x'};
    static long array_of_long[1];
    static char eight[] = "eight";
    static char *lp[4] = { "one", seven, NULL, eight };
    assert(array_of_one[0] == 'x');
    assert(array_of_long[0] == 0);
    assert(lp[0][0] == 'o');
    assert(lp[0][3] == '\0');
    assert(lp[1][0] == 's');
    assert(lp[1][5] == '\0');
    assert(lp[2] == NULL);
    assert(lp[3][0] == 'e');
    assert(lp[3][5] == '\0');
}

void test_automatic_arrays()
{
    char array_of_one[1] = {'x'};
    long array_of_long[1] = {42};
    static char eight[] = "eight";
    char nine[] = "nine";
    char *ten = NULL;
    char *lp[6] = { "one", seven, eight, NULL, nine, ten };
    assert(array_of_one[0] == 'x');
    assert(array_of_long[0] == 42);
    assert(lp[0][0] == 'o');
    assert(lp[0][3] == '\0');
    assert(lp[1][0] == 's');
    assert(lp[1][5] == '\0');
    assert(lp[2][0] == 'e');
    assert(lp[2][5] == '\0');
    assert(lp[3] == NULL);
    assert(lp[4][0] == 'n');
    assert(lp[4][4] == '\0');
    assert(lp[5] == NULL);
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

void test_pointer_arithmetic(int *a)
{
    static const int * const b = &g[2];
    assert(b - a == 2); assert(a - b == -2);
    assert(a + 2 == b); assert(2 + a == b); assert(b - 2 == a); assert(-2 + b == a + 0);
    assert(a < b); assert(!(a > b)); assert(a <= b); assert(!(a >= b)); assert(a != b);
}

int main()
{
    test_global_arrays();
    test_static_arrays();
    test_automatic_arrays();
    test_uninitialized_char();
    test_offsets();
    test_pointer_arithmetic(g);

    puts("SUCCESS!");
}
