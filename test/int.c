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
    assert(and_(0x8765, 0x1234) == 0x0224);
    assert(or_(0x8765, 0x1234) == 0x9775);
    assert(xor_(0x8765, 0x1234) == 0x9551);
    assert(andand(30,10) == 1);
    assert(andand(0,10) == 0);
    assert(oror(30,10) == 1);
    assert(oror(-10,0) == 1);
    assert(oror(0,0) == 0);
    puts("SUCCESS!");
}
