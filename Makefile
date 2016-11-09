vbccz:
	cd vbcc ; mkdir -p bin ; yes '' | TARGET=z make

clean:
	find vbcc/ -name '*.o' -delete
	make -C test/ clean
	rm -f vbcc-patch.diff

diff:
	git diff master -- vbcc/ > vbcc-patch.diff

test: vbccz
	make -C test/ clean
	make -C test/ all

.PHONY: clean diff test
