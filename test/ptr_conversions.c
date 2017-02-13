#include <assert.h>
#include <stdio.h>

typedef signed char sc; typedef unsigned char uc;
typedef signed short ss; typedef unsigned short us;
typedef signed int si; typedef unsigned int ui;
typedef signed long sl; typedef unsigned long ul;
typedef void *vp;
typedef void (*fp)();

#define EXPLICIT_CONV(ft, tt) tt ft##_##tt(ft c) { return (tt)c; }
#define ECONV4(st) EXPLICIT_CONV(st, vp) EXPLICIT_CONV(vp, st) EXPLICIT_CONV(st, fp) EXPLICIT_CONV(fp, st)
#define ECONV8(st) ECONV4(s##st) ECONV4(u##st)

ECONV8(c) ECONV8(s) ECONV8(i) ECONV8(l)

static vp v42 = (void *)42;
static fp f42 = (void (*)())42;

int main()
{
    assert(sc_vp(42) == (void*)42);
    assert(sc_fp(42) == (void(*)())42);
    assert(vp_sc(v42) == 42);
    assert(fp_sc(f42) == 42);

    assert(uc_vp(42) == (void*)42);
    assert(uc_fp(42) == (void(*)())42);
    assert(vp_uc(v42) == 42);
    assert(fp_uc(f42) == 42);

    assert(ss_vp(42) == (void*)42);
    assert(ss_fp(42) == (void(*)())42);
    assert(vp_ss(v42) == 42);
    assert(fp_ss(f42) == 42);

    assert(us_vp(42) == (void*)42);
    assert(us_fp(42) == (void(*)())42);
    assert(vp_us(v42) == 42);
    assert(fp_us(f42) == 42);

    assert(si_vp(42) == (void*)42);
    assert(si_fp(42) == (void(*)())42);
    assert(vp_si(v42) == 42);
    assert(fp_si(f42) == 42);

    assert(ui_vp(-42) == (void*)-42);
    assert(ui_fp(-42) == (void(*)())-42);
    assert(vp_ui(v42) == 42);
    assert(fp_ui(f42) == 42);

    assert(sl_vp(0x12345678L) == (void*)0x5678);
    assert(sl_fp(0x12345678L) == (void(*)())0x5678);
    assert(vp_sl(v42) == 42);
    assert(fp_sl(f42) == 42);

    assert(ul_vp(0x12345678L) == (void*)0x5678);
    assert(ul_fp(0x12345678L) == (void(*)())0x5678);
    assert(vp_ul(v42) == 42);
    assert(fp_ul(f42) == 42);

    // pointers are "unsigned" and thus don't sign-extend
    assert(vp_sl((void*)0x123489ABL) == 0x000089ABL);
    assert(fp_sl((void(*)())0x123489ABL) == 0x000089ABL);
    assert(vp_ul((void*)0x123489ABL) == 0x000089ABL);
    assert(fp_ul((void(*)())0x123489ABL) == 0x000089ABL);

    // pointers compare unsigned as well
    assert((void*)0 < &v42);
    assert((void*)1 < &v42);
    assert((void*)1 < (void*)-1);
    assert(v42 < (void*)0xFFFF);

    puts("SUCCESS!");
}
