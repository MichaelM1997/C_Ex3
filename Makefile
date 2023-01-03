
all: txtfind isort

txtfind: txtfind.c
	gcc -Wall txtfind.c -o txtfind


isort: isort.c
	gcc -Wall isort.c -o isort


.PHONY: clean all

clean:
	rm -f txtfind & rm -f isort
