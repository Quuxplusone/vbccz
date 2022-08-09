for i in $(seq 100000); do
  echo "csmith --seed $i --quiet --concise --no-builtins --no-float --no-longlong --no-packed-struct --no-safe-math --no-volatiles > reduce.c"
        csmith --seed $i --quiet --concise --no-builtins --no-float --no-longlong --no-packed-struct --no-safe-math --no-volatiles > reduce.c
  VBCC=../vbcc ../vbcc/bin/vc +z -c99 -I../z-machine/include reduce.c -E
  mv reduce.i reduce.c
  if ./interesting.sh; then
    echo "Error detected!"
    creduce ./interesting.sh reduce.c
    mv reduce.c "crash-$i.c"
  fi
done
