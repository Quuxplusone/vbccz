#include <assert.h>
#include <stdio.h>

long add(long x, long y) { return x + y; }
long sub(long x, long y) { return x - y; }
long mul(long x, long y) { return x * y; }
long div(long x, long y) { return x / y; }
long mod(long x, long y) { return x % y; }
long lsh(long x, long y) { return x << y; }
long rsh(long x, long y) { return x >> y; }
long and_(long x, long y) { return x & y; }
long or_(long x, long y) { return x | y; }
long xor_(long x, long y) { return x ^ y; }
long andand(long x, long y) { return x && y; }
long oror(long x, long y) { return x || y; }
long bang(long x) { return !x; }
long not_(long x) { return ~x; }
long neg(long x) { return -x; }
long preinc(long *x) { return ++*x; }
long postinc(long *x) { return (*x)++; }
long predec(long *x) { return --*x; }
long postdec(long *x) { return (*x)--; }

void test_initialization(long x, long y, long z)
{
    static long x2 = 0x80;
    static long y2 = 0x8000;
    static long z2 = 0x80000000;
    assert(x == x2); assert(x2 > 0);
    assert(y == y2); assert(y2 > 0);
    assert(z == z2); assert(z2 < 0);
    ++x2; ++y2; ++z2;
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
    assert(neg(0x00010000) == 0xFFFF0000);
    assert(neg(0xFFFF0000) == 0x00010000);

    assert(add(0x1234567L,0x89abcdeL) == 0x9be0245L);
    assert(sub(0x1234567L, 0xabc4568L) == -0x9990001L);
    assert(mul(257, 258) == 66306L);
    assert(div(66306L, 257) == 258);
    assert(div(66306L, 66300L) == 1);
    assert(mod(66306L, 257) == 0);
    assert(mod(66306L, 66300L) == 6);
    assert(mod(66306L, 66306L) == 0);
    assert(lsh(20, 18) == 5242880L);
    assert(rsh(5267778L, 18) == 20);
    assert(and_(0x87654321uL, 0x12345432L) == 0x2244020L);
    assert(or_(0x87654321uL, 0x12345432L) == 0x97755733uL);
    assert(xor_(0x87654321uL, 0x12345432L) == 0x95511713);

    long x;
    x = 0x0100FFFF; assert(preinc(&x) == 0x01010000); assert(x == 0x01010000);
    x = 0x0100FFFF; assert(postinc(&x) == 0x0100FFFF); assert(x == 0x01010000);
    x = 0x01010000; assert(predec(&x) == 0x0100FFFF); assert(x == 0x0100FFFF);
    x = 0x01010000; assert(postdec(&x) == 0x01010000); assert(x == 0x0100FFFF);

    test_initialization(0x80, 0x8000, 0x80000000);

    puts("SUCCESS!");
}
