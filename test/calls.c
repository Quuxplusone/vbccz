#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

static int a() { return 1; }
int b(int x) { return x; }
int c() { return 3; }

void regular_function(int a, int b, int c)
{
    assert(a == 1);
    assert(b == 2);
    assert(c == 3);
}

void rf4(int a, int b, int c, int d) { assert(a==1 && b==2 && c==3 && d==4); }
void rf5(int a, int b, int c, int d, int e) { assert(a==1 && b==2 && c==3 && d==4 && e==5); }
void rf6(int a, int b, int c, int d, int e, int f) { assert(a==1 && b==2 && c==3 && d==4 && e==5 && f==6); }
void rf7(int a, int b, int c, int d, int e, int f, int g) { assert(a==1 && b==2 && c==3 && d==4 && e==5 && f==6 && g==7); }
void rf8(int a, int b, int c, int d, int e, int f, int g, int h) { assert(a==1 && b==2 && c==3 && d==4 && e==5 && f==6 && g==7 && h==8); }

void rfl4(int a, int b, int c, long d) { assert(a==1 && b==2 && c==3 && d==4); }
void rfl5(int a, int b, int c, long d, int e) { assert(a==1 && b==2 && c==3 && d==4 && e==5); }
void rfl6(int a, int b, int c, long d, int e, int f) { assert(a==1 && b==2 && c==3 && d==4 && e==5 && f==6); }
void rfl7(int a, int b, int c, long d, int e, int f, int g) { assert(a==1 && b==2 && c==3 && d==4 && e==5 && f==6 && g==7); }
void rfl8(int a, int b, int c, long d, int e, int f, int g, int h) { assert(a==1 && b==2 && c==3 && d==4 && e==5 && f==6 && g==7 && h==8); }

void variadic_int(int a, ...)
{
    va_list ap;
    va_start(ap, a);
    int b = va_arg(ap, int);
    int c = va_arg(ap, int);
    va_end(ap);
    assert(a == 1);
    assert(b == 2);
    assert(c == 3);
}

void variadic_long(long a, ...)
{
    va_list ap;
    va_start(ap, a);
    long b = va_arg(ap, long);
    long c = va_arg(ap, long);
    va_end(ap);
    assert(a == 1);
    assert(b == 2);
    assert(c == 3);
}

void vfl8(int a, int b, int c, long d, int e, int f, int g, int h, ...)
{
    va_list ap;
    va_start(ap, h);
    long i = va_arg(ap, int);
    long j = va_arg(ap, long);
    long k = va_arg(ap, int);
    assert(a==1 && b==2 && c==3 && d==4 && e==5 && f==6 && g==7 && h==8);
    assert(i==9 && j==10 && k==11);
}

void test_dangerous_ops(int *a, int n, int k, int *p)
{
    for (int i=0; i < n; ++i) {
        a[6*i+0] = (k ? 1 / k : i);
        a[6*i+1] = (k ? 1 % k : i);
        a[6*i+2] = (k ? *p : i);
        a[6*i+3] = (k ? 1 / 0 : i);
        a[6*i+4] = (k ? 1 % 0 : i);
        a[6*i+5] = (k ? *(int *)0 : i);
    }
}

int three = 3;
long lthree = 3;

int main()
{
    int local = 3;
    regular_function(a(), b(2), c());
    variadic_int(a(), b(2), c());
    variadic_int(a(), 2, three);
    variadic_int(local / local, local-1, local);
    variadic_long((long)a(), (long)b(2), (long)c());
    variadic_long((long)a(), 2L, lthree);
    variadic_long((long)(local / local), local - 1L, (long)local);
    rf4(1,2,3,4);
    rf5(1,2,3,4,5);
    rf6(1,2,3,4,5,6);
    rf7(1,2,3,4,5,6,7);
    rf8(1,2,3,4,5,6,7,8);
    rfl4(1,2,3,4);
    rfl5(1,2,3,4,5);
    rfl6(1,2,3,4,5,6);
    rfl7(1,2,3,4,5,6,7);
    rfl8(1,2,3,4,5,6,7,8);
    vfl8(1,2,3,4,5,6,7,8,9,10L,11);
    {
        int arr[12];
        test_dangerous_ops(arr, 2, 0, NULL);
        for (int i=0; i < 12; ++i) {
            assert(arr[i] == i/6);
        }
    }
    puts("SUCCESS!");
}
