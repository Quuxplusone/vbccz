#include <assert.h>
#include <stdio.h>

typedef signed char sc; typedef unsigned char uc;
typedef signed short ss; typedef unsigned short us;
typedef signed int si; typedef unsigned int ui;
typedef signed long sl; typedef unsigned long ul;

#define CONV(ft, tt) tt ft##_##tt(ft c) { return c; }
#define CONV4(ft, tt) CONV(s##ft, s##tt) CONV(s##ft, u##tt) CONV(u##ft, s##tt) CONV(u##ft, u##tt)

CONV4(c,c) CONV4(c,s) CONV4(c,i) CONV4(c,l)
CONV4(s,c) CONV4(s,s) CONV4(s,i) CONV4(s,l)
CONV4(i,c) CONV4(i,s) CONV4(i,i) CONV4(i,l)
CONV4(l,c) CONV4(l,s) CONV4(l,i) CONV4(l,l)

unsigned long gul;
void inc_ll_ul(long c) { gul = (unsigned long)(c + 1); }

int main()
{
    assert(sc_sc(42) == 42);
    assert(sc_uc(42) == 42);
    assert(uc_sc(42) == 42);
    assert(uc_uc(42) == 42);
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

    assert(ss_sc(42) == 42);
    //assert(ss_uc(554) == 42);
    assert(us_sc(42) == 42);
    //assert(us_uc(554) == 42);
    assert(ss_ss(42) == 42);
    assert(ss_us(42) == 42);
    assert(us_ss(42) == 42);
    assert(us_us(42) == 42);
    assert(ss_si(42) == 42);
    assert(ss_ui(42) == 42u);
    assert(us_si(42) == 42);
    assert(us_ui(42) == 42u);
    assert(ss_sl(42) == 42L);
    assert(ss_ul(42) == 42uL);
    assert(us_sl(42) == 42L);
    assert(us_ul(42) == 42uL);

    assert(si_sc(42) == 42);
    //assert(si_uc(554) == 42);
    assert(ui_sc(42) == 42);
    //assert(ui_uc(554) == 42);
    assert(si_ss(42) == 42);
    assert(si_us(42) == 42);
    assert(ui_ss(42) == 42);
    assert(ui_us(42) == 42);
    assert(si_si(42) == 42);
    assert(si_ui(42) == 42u);
    assert(ui_si(42) == 42);
    assert(ui_ui(42) == 42u);
    assert(si_sl(42) == 42L);
    assert(si_ul(42) == 42uL);
    assert(ui_sl(42) == 42L);
    assert(ui_ul(42) == 42uL);

    assert(sl_sc(0x12345678L) == 0x78);
    assert(sl_uc(0x12345678L) == 0x78);
    assert(ul_sc(0x12345678uL) == 0x78);
    assert(ul_uc(0x12345678uL) == 0x78);
    assert(sl_ss(0x12345678L) == 0x5678);
    assert(sl_us(0x12345678L) == 0x5678u);
    assert(ul_ss(0x12345678uL) == 0x5678);
    assert(ul_us(0x12345678uL) == 0x5678u);
    assert(sl_si(0x12345678L) == 0x5678);
    assert(sl_ui(0x12345678L) == 0x5678u);
    assert(ul_si(0x12345678uL) == 0x5678);
    assert(ul_ui(0x12345678uL) == 0x5678u);
    //assert(sl_sl(0x12345678L) == 0x12345678L);
    //assert(sl_ul(0x12345678L) == 0x12345678uL);
    //assert(ul_sl(0x12345678uL) == 0x12345678L);
    //assert(ul_ul(0x12345678uL) == 0x12345678uL);

    assert(sc_sc(-42) == -42);
    //assert(sc_uc(-42) == 256 - 42);
    assert(uc_sc(-42) == -42);
    //assert(uc_uc(-42) == 256 - 42);
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

    assert(ss_sc(-554) == -42);
    //assert(ss_uc(-554) == 256 - 42);
    assert(us_sc(-554) == -42);
    //assert(us_uc(-554) == 256 - 42);
    assert(ss_ss(-554) == -554);
    assert(ss_us(-554) == 64982);
    assert(us_ss(-554) == -554);
    assert(us_us(-554) == 64982);
    assert(ss_si(-42) == -42);
    assert(ss_ui(-42) == 0u - 42u);
    assert(us_si(-42) == -42);
    assert(us_ui(-42) == 0u - 42u);
    assert(ss_sl(-42) == -42L);
    assert(ss_ul(-42) == 0uL - 42uL);
    assert(us_sl(-42) == 65536L - 42L);
    assert(us_ul(-42) == 65536uL - 42uL);

    assert(si_sc(0x12A4) == 0xFFA4);
    //assert(si_uc(0x12A4) == 0xA4);
    assert(ui_sc(0x12A4) == 0xFFA4);
    //assert(ui_uc(0x12A4) == 0xA4);
    assert(si_ss(-42) == -42);
    assert(si_us(-554) == 64982);
    assert(ui_ss(-42) == -42);
    assert(ui_us(-554) == 64982);
    assert(si_si(-42) == -42);
    assert(si_ui(-554) == 64982);
    assert(ui_si(-42) == -42);
    assert(ui_ui(-554) == 64982);
    assert(si_sl(-42) == -42L);
    assert(si_ul(-42) == 0uL - 42uL);
    assert(ui_sl(-42) == 65536L - 42L);
    assert(ui_ul(-42) == 65536uL - 42uL);

    assert(sl_sc(0x123456A8L) == -88);
    assert(sl_uc(0x123456A8L) == 168);
    assert(ul_sc(0x123456A8uL) == -88);
    assert(ul_uc(0x123456A8uL) == 168);
    assert(sl_ss(0x1234A678L) == 0xFFFFA678L);
    assert(sl_us(0x1234A678L) == 0xA678L);
    assert(ul_ss(0x1234A678uL) == 0xFFFFA678L);
    assert(ul_us(0x1234A678uL) == 0xA678L);
    assert(sl_si(0x1234A678L) == 0xFFFFA678L);
    assert(sl_ui(0x1234A678L) == 0xA678L);
    assert(ul_si(0x1234A678uL) == 0xFFFFA678L);
    assert(ul_ui(0x1234A678uL) == 0xA678L);
    //assert(sl_sl(0xA2345678L) == 0xA2345678L);
    //assert(sl_ul(0xA2345678L) == 0xA2345678uL);
    //assert(ul_sl(0xA2345678uL) == 0xA2345678L);
    //assert(ul_ul(0xA2345678uL) == 0xA2345678uL);

    inc_ll_ul(42); assert(gul == 43);

    puts("SUCCESS!");
}
