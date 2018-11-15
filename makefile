all: arg.o
	gcc -o test arg.o

signals.o: arg.c
	gcc -c arg.c

run:
	./test

clean:
	rm *.o
