#include <assert.h>
#include <stdio.h>

int g = 0;

void fv() { g = 10; return; }
int fi() { return 42; }
int fii(int x) { return x + 1; }

void (*gpfv)() = fv;
int (*gpfi)() = fi;
int (*gpfii)() = fii;

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
    puts("SUCCESS!");
}
