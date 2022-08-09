VBCC=/Users/aodwyer/vbccz/vbcc /Users/aodwyer/vbccz/vbcc/bin/vc +z -c99 -O0 -comment-ic -comment-misc -S reduce.c > out.txt 2>&1
if grep -q "Assertion failed: " out.txt; then
  exit 0
fi
if grep -q ": internal error" out.txt; then
  if ! grep -q "internal error 0 in line 977 of file loop.c" out.txt; then
    exit 0
  fi
fi

VBCC=/Users/aodwyer/vbccz/vbcc /Users/aodwyer/vbccz/vbcc/bin/vc +z -c99 -O1 -comment-ic -comment-misc -S reduce.c > out.txt 2>&1
if grep -q "Assertion failed: " out.txt; then
  exit 0
fi
if grep -q ": internal error" out.txt; then
  if ! grep -q "internal error 0 in line 977 of file loop.c" out.txt; then
    exit 0
  fi
fi

VBCC=/Users/aodwyer/vbccz/vbcc /Users/aodwyer/vbccz/vbcc/bin/vc +z -c99 -O2 -comment-ic -comment-misc -S reduce.c > out.txt 2>&1
if grep -q "Assertion failed: " out.txt; then
  exit 0
fi
if grep -q ": internal error" out.txt; then
  if ! grep -q "internal error 0 in line 977 of file loop.c" out.txt; then
    exit 0
  fi
fi
exit 1
