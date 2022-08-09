#include <assert.h>
#include <stdio.h>

typedef signed long sl;
typedef unsigned long ul;

extern void get_sl();
extern void get_ul();

void copy_sl_sl(sl c) { get_sl(c, 0); }
void copy_sl_ul(sl c) { get_ul(c, 0); }
void copy_ul_sl(ul c) { get_sl(c, 0); }
void copy_ul_ul(ul c) { get_ul(c, 0); }

char return_c() { return 1; }
signed char return_sc() { return 1; }
unsigned char return_uc() { return 1; }
signed short return_ss() { return 1000; }
unsigned short return_us() { return 1000; }
signed int return_si() { return 1000; }
unsigned int return_ui() { return 1000; }
signed long return_sl() { return 12345678; }
unsigned long return_ul() { return 12345678; }

void get_sl(sl val, int radix)
{
    char *p = 0;
    int c;

    assert(val == 0x12345678);
    while (val > 0x20000000) {
        val /= radix;
        *--p = val;
    }
}

void get_ul(ul val, int radix)
{
    char *p = 0;
    int c;

    assert(val == 0x12345678);
    while (val > 0x20000000) {
        val /= radix;
        *--p = val;
    }
}

void cover_typed_constants()
{
    signed char sc = 0;
    char c = 0;
    unsigned char uc = 0;
    short ss = 0;
    unsigned short us = 0;
    int si = 0;
    unsigned int ui = 0;
    long sl = 0;
    unsigned long ul = 0;
    int *ip = 0;
    void *vp = (void*)123;
    assert(vp == (void*)123);
    assert((int)vp == 123);
    assert((long)vp == 123L);
}

int cover_dangerous_IC_dref_q1(int d, int b, char **f) {
    while (d) {
        while (d) {
            b = **f;
            d -= 1;
        }
    }
    return b;
}

int cover_dangerous_IC_dref_z(int i) {
    int d[2] = {0,0};
    for ( ; ; ++i) {
        if (i < 2) {
            d[i] = 4;
        } else {
            return d[0] + d[1];
        }
    }
}

int main()
{
    copy_sl_sl(0x12345678L);
    copy_sl_ul(0x12345678L);
    copy_ul_sl(0x12345678uL);
    copy_ul_ul(0x12345678uL);

    assert(return_c() == 1);
    assert(return_sc() == 1);
    assert(return_uc() == 1);
    assert(return_ss() == 1000);
    assert(return_us() == 1000);
    assert(return_si() == 1000);
    assert(return_ui() == 1000);
    assert(return_sl() == 12345678);
    assert(return_ul() == 12345678);

    cover_typed_constants();

    assert(cover_dangerous_IC_dref_q1(0, 42, NULL) == 42);
    char *p = (char*)"a";
    assert(cover_dangerous_IC_dref_q1(1, 42, &p) == 'a');

    assert(cover_dangerous_IC_dref_z(0) == 8);
    assert(cover_dangerous_IC_dref_z(1) == 4);
    assert(cover_dangerous_IC_dref_z(2) == 0);

    puts("SUCCESS!");
}
