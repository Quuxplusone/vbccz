void a() {
    int b[10];
    b &= 42;
}

#if 0

$ VBCC=../vbcc ../vbcc/bin/vc +z -c99 -S -O2 crash-1722.c 
>    b &= 42;
error 90 in line 3 of "crash-1722.c": bitwise operations need integer operands
>    b &= 42;
error 158 in line 3 of "crash-1722.c": internal error 0 in line 421 of file supp.c !!
aborting...
unexpected end of file
2 errors found!
$VBCC/bin/vbccz -quiet "crash-1722.c" -o="crash-1722.asm" -c99  -O=1023 failed

#endif
