volatile int x;
volatile int *p = &x;

/*
>volatile int *p = &x;
error 46 in line 2 of "todo2.c": initializer not a constant
1 error found!
*/