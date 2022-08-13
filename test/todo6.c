struct S { int; };
struct T { struct S m; };
struct T t = ;

#if 0

$ VBCC=../vbcc ../vbcc/bin/vc +z -c99 -S -O2 crash-2459.c 
>struct S { int;
warning 53 in line 1 of "crash-2459.c": struct/union member needs identifier
>EOF
error 158 in line 4 of "crash-2459.c": internal error 0 in line 3371 of file declaration.c !!
aborting...
$VBCC/bin/vbccz -quiet "crash-2459.c" -o="crash-2459.asm" -c99  -O=1023 failed

#endif
