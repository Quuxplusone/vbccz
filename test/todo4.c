void f(int);

void g(int) {
    f(0);
}

void h() {
    g(0);
}
/*
error 158 in line 1665206121 of "todo4.c": internal error 0 in line 1143 of file regs.c !!
*/
