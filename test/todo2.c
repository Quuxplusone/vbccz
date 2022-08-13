struct S {
  int indvar;
  int not_indvar;
};
void g(int);

void f(struct S s) {
  for (s.indvar = 0; s.indvar < 10; ++s.indvar) {
    g(s.not_indvar << 1);
  }
}

#if 0

$ ../vbcc/bin/vbccz -quiet crash-193.c -o="/var/tmp/tmp.0.ljqQjs.asm" -c99 -O=1023 
>EOF
error 158 in line 12 of "crash-193.c": internal error 0 in line 977 of file loop.c !!
aborting...
unexpected end of file
1 error found!

#endif
