#include <assert.h>
#include <stdio.h>

typedef unsigned int uint;

uint add(uint x, uint y) { return x + y; }
uint sub(uint x, uint y) { return x - y; }
uint mul(uint x, uint y) { return x * y; }
uint div(uint x, uint y) { return x / y; }
uint mod(uint x, uint y) { return x % y; }
uint lsh(uint x, uint y) { return x << y; }
uint rsh(uint x, uint y) { return x >> y; }
uint and_(uint x, uint y) { return x & y; }
uint or_(uint x, uint y) { return x | y; }
uint xor_(uint x, uint y) { return x ^ y; }
uint andand(uint x, uint y) { return x && y; }
uint oror(uint x, uint y) { return x || y; }
uint bang(uint x) { return !x; }
uint not_(uint x) { return ~x; }
uint neg(uint x) { return -x; }
uint preinc(uint *x) { return ++*x; }
uint postinc(uint *x) { return (*x)++; }
uint predec(uint *x) { return --*x; }
uint postdec(uint *x) { return (*x)--; }

void test_initialization(uint x, uint y)
{
    static uint x2 = 0x80;
    static uint y2 = 0x8000;
    assert(x == x2); assert(x2 > 0);
    assert(y == y2); assert(y2 > 0);
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
    assert(lsh(-20,2) == 65456u);
    assert(rsh(-25,2) == 16377u);
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

    uint x;
    x = 42; assert(preinc(&x) == 43); assert(x == 43);
    x = 42; assert(postinc(&x) == 42); assert(x == 43);
    x = 42; assert(predec(&x) == 41); assert(x == 41);
    x = 42; assert(postdec(&x) == 42); assert(x == 41);

    x = 0xFFFF; assert(preinc(&x) == 0); assert(x == 0x0000);
    x = 0xFFFF; assert(postinc(&x) == -1); assert(x == 0x0000);
    x = 0x0000; assert(predec(&x) == -1); assert(x == 0xFFFF);
    x = 0x0000; assert(postdec(&x) == 0); assert(x == 0xFFFF);

    test_initialization(0x80, 0x8000);

    puts("SUCCESS!");
}
