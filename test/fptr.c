#include <assert.h>
#include <stdio.h>

int g = 0;

void fv() { g = 10; return; }
int fi() { return 42; }
int fii(int x) { return x + 1; }

void (*gpfv)() = fv;
int (*gpfi)() = fi;
int (*gpfii)() = fii;

int (*test_fptr_as_return())(int)
{
    return fii;
}

void f1() { g = 11; }
void f2() { g = 12; }
void f3() { g = 13; }
void f4() { g = 14; }

void test_fptr_tables(int i)
{
    static void (*gtable[])() = { f1, f2 };
    void (*ltable[])() = { f3, f4 };
    g = 0; gtable[i](); assert(g == 11);
    g = 0; gtable[1+i](); assert(g == 12);
    g = 0; ltable[i](); assert(g == 13);
    g = 0; ltable[1+i](); assert(g == 14);
}

int main()
{
    void (*pfv)() = fv;
    int (*pfi)() = fi;
    int (*pfii)() = fii;
    g = 0; pfv(); assert(g == 10);
    g = 0; gpfv(); assert(g == 10);
    assert(pfi() == 42);
    assert(gpfi() == 42);
    assert(pfii(43) == 44);
    assert(gpfii(43) == 44);

    assert(test_fptr_as_return() == fii);
    assert(test_fptr_as_return()(42) == 43);

    test_fptr_tables(0);

    puts("SUCCESS!");
}
