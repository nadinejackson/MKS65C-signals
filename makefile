all: signal.o
	gcc signal.o
signal.o: signal.c
	gcc -c signal.c
run: a.out
	./a.out
again: signal.c
	emacs signal.c
