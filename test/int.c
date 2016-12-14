#include <assert.h>
#include <stdio.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }
int mod(int x, int y) { return x % y; }
int lsh(int x, int y) { return x << y; }
int rsh(int x, int y) { return x >> y; }
int and_(int x, int y) { return x & y; }
int or_(int x, int y) { return x | y; }
int xor_(int x, int y) { return x ^ y; }
int andand(int x, int y) { return x && y; }
int oror(int x, int y) { return x || y; }
int bang(int x) { return !x; }
int not_(int x) { return ~x; }
int neg(int x) { return -x; }
int preinc(int *x) { return ++*x; }
int postinc(int *x) { return (*x)++; }
int predec(int *x) { return --*x; }
int postdec(int *x) { return (*x)--; }

void test_initialization(int x, int y)
{
    static int x2 = 0x80;
    static int y2 = 0x8000;
    assert(x == x2); assert(x2 > 0);
    assert(y == y2); assert(y2 < 0);
    ++x2; ++y2;
}

int main()
{
    assert(add(5,4) == 9);
    assert(sub(5,4) == 1);
    assert(mul(5,4) == 20);
    assert(div(20,6) == 3);
    assert(mod(20,6) == 2);
    assert(mod(20,20) == 0);
    assert(lsh(20,2) == 80);
    assert(rsh(25,2) == 6);
    assert(lsh(-20,2) == -80);
    assert(rsh(-25,2) == -7);
    assert(and_(0x8765, 0x1234) == 0x0224);
    assert(or_(0x8765, 0x1234) == 0x9775);
    assert(xor_(0x8765, 0x1234) == 0x9551);
    assert(andand(30,10) == 1);
    assert(andand(0,10) == 0);
    assert(oror(30,10) == 1);
    assert(oror(-10,0) == 1);
    assert(oror(0,0) == 0);
    assert(bang(0) == 1);
    assert(bang(256) == 0);
    assert(not_(0) == -1);
    assert(not_(256) == -257);
    assert(neg(42) == -42);
    assert(neg(-256) == 256);

    int x;
    x = 42; assert(preinc(&x) == 43); assert(x == 43);
    x = 42; assert(postinc(&x) == 42); assert(x == 43);
    x = 42; assert(predec(&x) == 41); assert(x == 41);
    x = 42; assert(postdec(&x) == 42); assert(x == 41);

    test_initialization(0x80, 0x8000);

    puts("SUCCESS!");
}
