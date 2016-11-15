#include <assert.h>
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

int main()
{
    test_small_struct();
    test_large_struct();

    puts("SUCCESS!");
}
