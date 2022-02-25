# Makefile for lab4
OBJS=driver.o functions.o
CFLAGS=-Wall -g

lab4: ${OBJS}
	gcc -o $@ -g ${OBJS}

${OBJS}: functions.h Makefile

test:
	./lab4

clean:
	rm -f *.o lab6
