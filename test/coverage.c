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

int main()
{
    copy_sl_sl(0x12345678L);
    copy_sl_ul(0x12345678L);
    copy_ul_sl(0x12345678uL);
    copy_ul_ul(0x12345678uL);

    cover_typed_constants();

    puts("SUCCESS!");
}
