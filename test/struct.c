#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct A {
    char a;
    char b;
} A;

typedef struct B {
    int a;
    char b;
    int c;
} B;

A adda(A x, A y) { A result = x; result.a += y.a; result.b += y.b; return result; }
B addb(B x, B y) { B result = x; result.a += y.a; result.b += y.b; return result; }

int vara(A a, ...) {
    va_list ap; va_start(ap, x);
    int i = va_arg(ap, int); va_end(ap);
    return a.a + a.b + i;
}

int varb(B b, ...) {
    va_list ap; va_start(ap, b);
    int i = va_arg(ap, int); va_end(ap);
    return b.a + b.b + b.c + i;
}

void test_small_struct()
{
    A a = { 1, 2 };
    A b = { 3, 42 };
    A r = adda(a, b); assert(r.a == 4 && r.b == 44);
    a.a = 5; assert(a.a == 5 && a.b == 2);
    b.b = 17; assert(b.a == 3 && b.b == 17);
    r = adda(a, b); assert(r.a == 8 && r.b == 19);
    r = adda(a, r); assert(r.a == 13 && r.b == 21);
    r = adda(r, a); assert(r.a == 18 && r.b == 23);

    static A sa = { -1, -2 };
    A *p = &a;
    static A *sp = &sa;

    assert(p == &a);
    assert(p != NULL);
    assert(sp == &sa);
    assert(sp != NULL);
    assert(p && sp);
    assert(p || sp);
    p->a = sp->a; assert(p->a == -1 && p->b == 2);
    sp->a = p->b; assert(sp->a == 2 && sp->b == -2);
    r = adda(*p, *sp); assert(r.a == 1 && r.b == 0);
    p = sp; assert(p->a == 2 && p->b == -2);
    assert(p == sp && p == &sa && p != &a);
}

void test_large_struct()
{
    B a = { 1, 2 };
    B b = { 3, 42 };
    B r = addb(a, b); assert(r.a == 4 && r.b == 44);
    a.a = 5; assert(a.a == 5 && a.b == 2);
    b.b = 17; assert(b.a == 3 && b.b == 17);
    r = addb(a, b); assert(r.a == 8 && r.b == 19);
    r = addb(a, r); assert(r.a == 13 && r.b == 21);
    r = addb(r, a); assert(r.a == 18 && r.b == 23);

    static B sa = { -1, -2 };
    B *p = &a;
    static B *sp = &sa;

    assert(p == &a);
    assert(p != NULL);
    assert(sp == &sa);
    assert(sp != NULL);
    assert(p && sp);
    assert(p || sp);
    p->a = sp->a; assert(p->a == -1 && p->b == 2);
    sp->a = p->b; assert(sp->a == 2 && sp->b == -2);
    r = addb(*p, *sp); assert(r.a == 1 && r.b == 0);
    p = sp; assert(p->a == 2 && p->b == -2);
    assert(p == sp && p == &sa && p != &a);
}

void test_variadics()
{
    A a = {1,2};
    B b = {1,2,3};
    assert(vara(a, 42) == 45);
    assert(varb(b, 42) == 48);
}

struct SC { char m; };
struct SS { short m; };
struct SI { int m; };
struct SL { long m; };
int add_c_sc(char a, struct SC s) { return a + s.m; }
int add_c_ss(char a, struct SS s) { return a + s.m; }
int add_c_si(char a, struct SI s) { return a + s.m; }
long add_c_sl(char a, struct SL s) { return a + s.m; }
int add_s_sc(short a, struct SC s) { return a + s.m; }
int add_s_ss(short a, struct SS s) { return a + s.m; }
int add_s_si(short a, struct SI s) { return a + s.m; }
long add_s_sl(short a, struct SL s) { return a + s.m; }
int add_i_sc(int a, struct SC s) { return a + s.m; }
int add_i_ss(int a, struct SS s) { return a + s.m; }
int add_i_si(int a, struct SI s) { return a + s.m; }
long add_i_sl(int a, struct SL s) { return a + s.m; }
long add_l_sc(long a, struct SC s) { return a + s.m; }
long add_l_ss(long a, struct SS s) { return a + s.m; }
long add_l_si(long a, struct SI s) { return a + s.m; }
long add_l_sl(long a, struct SL s) { return a + s.m; }

void test_different_types()
{
    struct SC sc = { 0x01 };
    struct SS ss = { 0x0102 };
    struct SI si = { 0x0102 };
    struct SL sl = { 0x01020304 };
    assert(add_c_sc(0x10, sc) == 0x11);
    assert(add_c_ss(0x10, ss) == 0x0112);
    assert(add_c_si(0x10, si) == 0x0112);
    assert(add_c_sl(0x10, sl) == 0x01020314);
    assert(add_s_sc(0x1020, sc) == 0x1021);
    assert(add_s_ss(0x1020, ss) == 0x1122);
    assert(add_s_si(0x1020, si) == 0x1122);
    assert(add_s_sl(0x1020, sl) == 0x01021324);
    assert(add_i_sc(0x1020, sc) == 0x1021);
    assert(add_i_ss(0x1020, ss) == 0x1122);
    assert(add_i_si(0x1020, si) == 0x1122);
    assert(add_i_sl(0x1020, sl) == 0x01021324);
    assert(add_l_sc(0x10203040, sc) == 0x10203041);
    assert(add_l_ss(0x10203040, ss) == 0x10203142);
    assert(add_l_si(0x10203040, si) == 0x10203142);
    assert(add_l_sl(0x10203040, sl) == 0x11223344);
}

int main()
{
    test_small_struct();
    test_large_struct();
    test_variadics();
    test_different_types();

    puts("SUCCESS!");
}
