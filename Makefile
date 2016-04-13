vbccz:
	cd vbcc ; mkdir -p bin ; yes '' | TARGET=z make

vbccppc:
	cd vbcc ; mkdir -p bin ; yes '' | TARGET=ppc make

clean:
	rm -rf vbcc/objects/
	make -C test/ clean
	rm -f vbcc-patch.diff

coverage: clean
	mkdir -p vbcc/bin
	yes '' | TARGET=z CFLAGS='-O0 -g --coverage' make -C vbcc/
	make -C test/ clean all CFLAGS='-O3 -comment-misc'
	make -C test/ clean all CFLAGS='-O2 -trace-all -comment-ic'
	make -C test/ clean all CFLAGS='-O1 -trace-calls'
	make -C test/ clean all CFLAGS='-O0 -comment-ic'
	cd vbcc ; gcov --object-file=objects/z/machine.gcno machines/z/machine.c
	mv vbcc/machine.c.gcov ./coverage-report.txt
	find vbcc/ '(' -name '*.gcda' -o -name '*.gcno' ')' -delete
	@echo `grep -c '^[ ]*[0-9]*:' coverage-report.txt` 'lines covered'
	@echo `grep -c '^[ ]*#####:' coverage-report.txt` 'lines not covered'
	@echo 'Wrote coverage report to ./coverage-report.txt'

diff:
	git diff master -- vbcc/ > vbcc-patch.diff

compile-tests: vbccz
	make -C test/ clean
	make -C test/ all

run-tests: vbccz
	make -C test/ clean
	make -C test/ run-tests
	make -C test/ clean
	make -C test/ run-tests CFLAGS=-O0

test: run-tests

.PHONY: clean coverage diff test
