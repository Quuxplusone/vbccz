#include <assert.h>
#include <stdio.h>

short sc_ss(signed char c) { return c; }
unsigned short sc_us(signed char c) { return c; }
short uc_ss(unsigned char c) { return c; }
unsigned short uc_us(unsigned char c) { return c; }

int sc_si(signed char c) { return c; }
unsigned int sc_ui(signed char c) { return c; }
int uc_si(unsigned char c) { return c; }
unsigned int uc_ui(unsigned char c) { return c; }

long sc_sl(signed char c) { return c; }
unsigned long sc_ul(signed char c) { return c; }
long uc_sl(unsigned char c) { return c; }
unsigned long uc_ul(unsigned char c) { return c; }

int ss_si(signed short c) { return c; }
unsigned int ss_ui(signed short c) { return c; }
int us_si(unsigned short c) { return c; }
unsigned int us_ui(unsigned short c) { return c; }

long ss_sl(signed short c) { return c; }
unsigned long ss_ul(signed short c) { return c; }
long us_sl(unsigned short c) { return c; }
unsigned long us_ul(unsigned short c) { return c; }

long si_sl(signed int c) { return c; }
unsigned long si_ul(signed int c) { return c; }
long ui_sl(unsigned int c) { return c; }
unsigned long ui_ul(unsigned int c) { return c; }

unsigned long gul;
void inc_ll_ul(long c) { gul = (unsigned long)(c + 1); }

int main()
{
    assert(sc_ss(42) == 42);
    assert(sc_us(42) == 42);
    assert(uc_ss(42) == 42);
    assert(uc_us(42) == 42);
    assert(sc_si(42) == 42);
    assert(sc_ui(42) == 42u);
    assert(uc_si(42) == 42);
    assert(uc_ui(42) == 42u);
    assert(sc_sl(42) == 42L);
    assert(sc_ul(42) == 42uL);
    assert(uc_sl(42) == 42L);
    assert(uc_ul(42) == 42uL);
    assert(ss_si(42) == 42);
    assert(ss_ui(42) == 42u);
    assert(us_si(42) == 42);
    assert(us_ui(42) == 42u);
    assert(ss_sl(42) == 42L);
    assert(ss_ul(42) == 42uL);
    assert(us_sl(42) == 42L);
    assert(us_ul(42) == 42uL);
    assert(si_sl(42) == 42L);
    assert(si_ul(42) == 42uL);
    assert(ui_sl(42) == 42L);
    assert(ui_ul(42) == 42uL);

    assert(sc_ss(-42) == -42);
    assert(sc_us(-42) == 0u - 42u);
    assert(uc_ss(-42) == 256 - 42);
    assert(uc_us(-42) == 256 - 42);
    assert(sc_si(-42) == -42);
    assert(sc_ui(-42) == 0u - 42u);
    assert(uc_si(-42) == 256 - 42);
    assert(uc_ui(-42) == 256 - 42);
    assert(sc_sl(-42) == -42L);
    assert(sc_ul(-42) == 0uL - 42uL);
    assert(uc_sl(-42) == 256 - 42);
    assert(uc_ul(-42) == 256 - 42);
    assert(ss_si(-42) == -42);
    assert(ss_ui(-42) == 0u - 42u);
    assert(us_si(-42) == -42);
    assert(us_ui(-42) == 0u - 42u);
    assert(ss_sl(-42) == -42L);
    assert(ss_ul(-42) == 0uL - 42uL);
    assert(us_sl(-42) == 65536L - 42L);
    assert(us_ul(-42) == 65536uL - 42uL);
    assert(si_sl(-42) == -42L);
    assert(si_ul(-42) == 0uL - 42uL);
    assert(ui_sl(-42) == 65536L - 42L);
    assert(ui_ul(-42) == 65536uL - 42uL);

    inc_ll_ul(42); assert(gul == 43);

    puts("SUCCESS!");
}
