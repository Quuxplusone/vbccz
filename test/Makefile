# vbcc needs this environment variable so it can find its config file.
export VBCC:=../vbcc

CFLAGS ?= -O3 -comment-ic -comment-misc
VBCCZ = ../vbcc/bin/vc +z -c99 $(CFLAGS) -I../z-machine/include
MAXES = \$$MAX_ZCODE_SIZE=40000

ALL_TESTS = arrays.z8 calls.z8 conversions.z8 coverage.z8 fptr.z8 \
    ice1.z8 ice4.z8 ice5.z8 int.z8 \
    long.z8 printf.z8 \
    struct.z8 uint.z8 ulong.z8 union.z8

all: $(ALL_TESTS)

run-tests: all
	./run-tests.sh $(ALL_TESTS)

clean:
	rm -rf .objs/ *.z8

.objs/%/main.s: %.c
	mkdir -p .objs/$(patsubst %.c,%,$<)
	$(VBCCZ) -c $< -o $@ -module-name=main

%.z8: .objs/%/main.s ../z-machine/cstubs.s
	inform -v8 -ew~S~X~D $(MAXES) +include_path=.objs/$(patsubst %.z8,%,$@),../z-machine ../z-machine/Main.inf $@

../z-machine/cstubs.s: ../z-machine/cstubs.c
	$(VBCCZ) -c $< -o $@ -module-name=libc

.PHONY: clean
.PRECIOUS: .objs/%/main.s
