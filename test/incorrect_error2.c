#include <assert.h>
#include <stdio.h>

char ch = 42;
long ll = 42;

int main()
{
    int *p = (int*)0 + ch;
    assert(p == &((int*)0)[ch]);
    assert(sizeof(0 + ch) == sizeof(int));
    assert(sizeof(ch + 0) == sizeof(int));
    assert(sizeof(0 | ch) == sizeof(int));
    assert(sizeof(ch | 0) == sizeof(int));
    assert(sizeof(0 ^ ch) == sizeof(int));
    assert(sizeof(ch ^ 0) == sizeof(int));
    assert(sizeof(0 << ch) == sizeof(int));
    assert(sizeof(ch << 0) == sizeof(int));
    assert(sizeof(0 >> ch) == sizeof(int));
    assert(sizeof(ch >> 0) == sizeof(int));
    assert(sizeof(ch / 1) == sizeof(int));
    assert(sizeof(ch % 1) == sizeof(int));
    assert(sizeof(ll * 0) == sizeof(long));
    assert(sizeof(0 * ll) == sizeof(long));
    assert(sizeof(ch / -1) == sizeof(int));
    assert(sizeof(-ch) == sizeof(int));
    assert(sizeof(ll / -1) == sizeof(long));
    assert(sizeof(-ll) == sizeof(long));
    puts("SUCCESS!");
}
