#include <assert.h>
#include <stdio.h>

int sc_si(signed char c) { return c; }
unsigned int sc_ui(signed char c) { return c; }
int uc_si(unsigned char c) { return c; }
unsigned int uc_ui(unsigned char c) { return c; }
//long sc_sl(signed char c) { return c; }
//unsigned long sc_ul(signed char c) { return c; }
//long uc_sl(unsigned char c) { return c; }
//unsigned long uc_ul(unsigned char c) { return c; }

int main()
{
    assert(sc_si(42) == 42);
    assert(sc_ui(42) == 42u);
    assert(uc_si(42) == 42);
    assert(uc_ui(42) == 42u);
    //assert(sc_sl(42) == 42L);
    //assert(sc_ul(42) == 42uL);
    //assert(uc_sl(42) == 42L);
    //assert(uc_ul(42) == 42uL);

    assert(sc_si(-42) == -42);
    assert(sc_ui(-42) == 0u - 42u);
    assert(uc_si(-42) == 256 - 42);
    assert(uc_ui(-42) == 256 - 42);
    //assert(sc_sl(-42) == -42L);
    //assert(sc_ul(-42) == 0uL - 42uL);
    //assert(uc_sl(-42) == 256 - 42);
    //assert(uc_ul(-42) == 256 - 42);

    puts("SUCCESS!");
}
