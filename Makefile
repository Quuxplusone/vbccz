vbccz:
	cd vbcc ; mkdir -p bin ; yes '' | TARGET=z make

diff:
	git diff master -- vbcc/ > vbcc-patch.diff

.PHONY: diff
