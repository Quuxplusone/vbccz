vbccz:
	cd vbcc ; mkdir -p bin ; yes '' | TARGET=z make

vbccppc:
	cd vbcc ; mkdir -p bin ; yes '' | TARGET=ppc make

clean:
	find vbcc/ '(' -name '*.gcda' -o -name '*.gcno' -o -name '*.o' ')' -delete
	make -C test/ clean
	rm -f vbcc-patch.diff

coverage: clean
	cd vbcc ; mkdir -p bin ; yes '' | TARGET=z CFLAGS='-O0 --coverage' make
	make -C test/ clean all CFLAGS='-O3 -comment-misc'
	make -C test/ clean all CFLAGS='-O2 -trace-all -comment-ic'
	make -C test/ clean all CFLAGS='-O1 -trace-calls'
	make -C test/ clean all CFLAGS='-O0 -comment-ic'
	cd vbcc ; gcov machines/z/machine.c ; mv machine.c.gcov ../coverage-report.txt
	find vbcc/ '(' -name '*.gcda' -o -name '*.gcno' ')' -delete
	@echo `grep -c '^[ ]*[0-9]*:' coverage-report.txt` 'lines covered'
	@echo `grep -c '^[ ]*#####:' coverage-report.txt` 'lines not covered'
	@echo 'Wrote coverage report to ./coverage-report.txt'

diff:
	git diff master -- vbcc/ > vbcc-patch.diff

test: vbccz
	make -C test/ clean
	make -C test/ all

.PHONY: clean coverage diff test
