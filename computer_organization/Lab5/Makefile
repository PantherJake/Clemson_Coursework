# Makefile for lab5
OBJS=driver.o functions.o
CFLAGS=-Wall -g

default: ${OBJS}
	gcc -o $@ -g ${OBJS}

${OBJS}: functions.h Makefile

run:
	./lab5

clean:
	rm -f *.o lab5
