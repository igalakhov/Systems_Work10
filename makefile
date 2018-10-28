all: main.o randgen.o
	gcc -o main.out main.o randgen.o
	rm *.o

main.o: main.c randgen.c
	gcc -c main.c randgen.h

randgen.o: randgen.c randgen.h
	gcc -c randgen.c randgen.h

run:
	./main.out
