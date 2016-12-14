# vbcc needs this environment variable so it can find its config file.
export VBCC:=../vbcc

CFLAGS ?= -O3 -comment-ic -comment-misc
VBCCZ = ../vbcc/bin/vc +z -c99 $(CFLAGS) -I../z-machine/include

all: arrays.z8 calls.z8 conversions.z8 coverage.z8 fptr.z8 int.z8 long.z8 struct.z8 uint.z8 ulong.z8 union.z8

clean:
	rm -rf .objs/ *.z8

.objs/%/main.s: %.c
	mkdir -p .objs/$(patsubst %.c,%,$<)
	$(VBCCZ) -c $< -o $@ -module-name=main

%.z8: .objs/%/main.s ../z-machine/cstubs.s
	inform -v8 -ew~S~X~D \$$MAX_STATIC_DATA=50000 \$$MAX_ARRAYS=10000 +include_path=.objs/$(patsubst %.z8,%,$@),../z-machine ../z-machine/Main.inf $@

../z-machine/cstubs.s: ../z-machine/cstubs.c
	$(VBCCZ) -c $< -o $@ -module-name=libc

.PHONY: clean
.PRECIOUS: .objs/%/main.s
