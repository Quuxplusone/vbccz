int x()
  int y()
{}

#if 0

$ ../vbcc/bin/vbccz -quiet "todo1.c" -o=x.s -c99  -O=16384
>{
error 37 in line 3 of "todo1.c": <y> is no parameter
>{
warning 54 in line 3 of "todo1.c": ; expected
warning 173 in function "x": function <x> has no return statement
>EOF
error 158 in line 20 of "todo1.c": internal error 0 in line 3012 of file declaration.c !!
aborting...
unexpected end of file
2 errors found!

#endif
