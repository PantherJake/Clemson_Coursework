# Makefile for lab5
OBJS=driver.o functions.o
CFLAGS=-Wall -g

default: ${OBJS}
	gcc -o $@ -g ${OBJS}

${OBJS}: functions.h Makefile

run:
	./a.out

clean:
	rm -f *.o lab6
