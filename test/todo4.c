void f(int);

void g(int) {
    f(0);
}

void h() {
    g(0);
}

#if 0

$ VBCC=../vbcc ../vbcc/bin/vc +z -c99 -O3 -comment-ic -comment-misc -I../z-machine/include -c todo4.c 
>EOF
error 158 in line 0 of "todo4.c": internal error 0 in line 1216 of file regs.c !!
aborting...
1 error found!
$VBCC/bin/vbccz -quiet "todo4.c" -o="/var/tmp/tmp.0.A1DSPz.asm" -c99 -comment-ic -comment-misc -I../z-machine/include  -O=-1 failed

#endif
