# vbcc needs this environment variable so it can find its config file.
export VBCC:=../vbcc

VBCCZ = ../vbcc/bin/vc +z -c99 -O1 -I../z-machine/include

all: arrays.z8 calls.z8 fptr.z8 int.z8

clean:
	rm -rf .objs/ *.z8

.objs/%/main.s: %.c
	mkdir -p .objs/$(patsubst %.c,%,$<)
	$(VBCCZ) -c $< -o $@ -module-name=main

%.z8: .objs/%/main.s ../z-machine/cstubs.s
	inform -v8 -ew~S~X~D +include_path=.objs/$(patsubst %.z8,%,$@),../z-machine ../z-machine/Main.inf $@

../z-machine/cstubs.s: ../z-machine/cstubs.c
	$(VBCCZ) -c $< -o $@ -module-name=libc

.PHONY: clean
.PRECIOUS: .objs/%/main.s
