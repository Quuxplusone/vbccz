#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct A_ {
    char a;
    char b;
} A_;
typedef union { struct A_ _; } A;

typedef struct B_ {
    int a;
    char b;
    int c;
} B_;
typedef union { struct B_ _; } B;

A adda(A x, A y) { A result = x; result._.a += y._.a; result._.b += y._.b; return result; }
B addb(B x, B y) { B result = x; result._.a += y._.a; result._.b += y._.b; return result; }

int vara(A a, ...) {
    va_list ap; va_start(ap, x);
    int i = va_arg(ap, int); va_end(ap);
    return a._.a + a._.b + i;
}

int varb(B b, ...) {
    va_list ap; va_start(ap, b);
    int i = va_arg(ap, int); va_end(ap);
    return b._.a + b._.b + b._.c + i;
}

void test_small_struct()
{
    A a = { ._ = { 1, 2 } };
    A b = { ._ = { 3, 42 } };
    A r = adda(a, b); assert(r._.a == 4 && r._.b == 44);
    a._.a = 5; assert(a._.a == 5 && a._.b == 2);
    b._.b = 17; assert(b._.a == 3 && b._.b == 17);
    r = adda(a, b); assert(r._.a == 8 && r._.b == 19);
    r = adda(a, r); assert(r._.a == 13 && r._.b == 21);
    r = adda(r, a); assert(r._.a == 18 && r._.b == 23);

    static A sa = { ._ = { -1, -2 } };
    A *p = &a;
    static A *sp = &sa;

    assert(p == &a);
    assert(p != NULL);
    assert(sp == &sa);
    assert(sp != NULL);
    assert(p && sp);
    assert(p || sp);
    p->_.a = sp->_.a; assert(p->_.a == -1 && p->_.b == 2);
    sp->_.a = p->_.b; assert(sp->_.a == 2 && sp->_.b == -2);
    r = adda(*p, *sp); assert(r._.a == 1 && r._.b == 0);
    p = sp; assert(p->_.a == 2 && p->_.b == -2);
    assert(p == sp && p == &sa && p != &a);
}

void test_large_struct()
{
    B a = { ._ = { 1, 2 } };
    B b = { ._ = { 3, 42 } };
    B r = addb(a, b); assert(r._.a == 4 && r._.b == 44);
    a._.a = 5; assert(a._.a == 5 && a._.b == 2);
    b._.b = 17; assert(b._.a == 3 && b._.b == 17);
    r = addb(a, b); assert(r._.a == 8 && r._.b == 19);
    r = addb(a, r); assert(r._.a == 13 && r._.b == 21);
    r = addb(r, a); assert(r._.a == 18 && r._.b == 23);

    static B sa = { ._ = { -1, -2 } };
    B *p = &a;
    static B *sp = &sa;

    assert(p == &a);
    assert(p != NULL);
    assert(sp == &sa);
    assert(sp != NULL);
    assert(p && sp);
    assert(p || sp);
    p->_.a = sp->_.a; assert(p->_.a == -1 && p->_.b == 2);
    sp->_.a = p->_.b; assert(sp->_.a == 2 && sp->_.b == -2);
    r = addb(*p, *sp); assert(r._.a == 1 && r._.b == 0);
    p = sp; assert(p->_.a == 2 && p->_.b == -2);
    assert(p == sp && p == &sa && p != &a);
}

void test_variadics()
{
    A a = { ._ = { 1,2 }};
    B b = { ._ = { 1,2,3 }};
    assert(vara(a, 42) == 45);
    assert(varb(b, 42) == 48);
}

int main()
{
    test_small_struct();
    test_large_struct();
    test_variadics();

    puts("SUCCESS!");
}
