#include <assert.h>
#include <stdio.h>

typedef struct A {
    char a;
    char b;
} A;

A add(A x, A y) { A result = x; result.a += y.a; result.b += y.b; return result; }

int main()
{
    A a = { 1, 2 };
    A b = { 3, 42 };
    A r = add(a, b); assert(r.a == 4 && r.b == 44);
    a.a = 5; assert(a.a == 5 && a.b == 2);
    b.b = 17; assert(b.a == 3 && b.b == 17);
    r = add(a, b); assert(r.a == 8 && r.b == 19);
    r = add(a, r); assert(r.a == 13 && r.b == 21);
    r = add(r, a); assert(r.a == 18 && r.b == 23);

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
    p = sp; assert(p->a == 2 && p->b == -2);
    assert(p == sp && p == &sa && p != &a);

    puts("SUCCESS!");
}
