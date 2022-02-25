# Makefile for PA1
OBJS=driver.o functions.o
CFLAGS=-Wall -g
file1 = data.txt
file2 = output.txt

default: ${OBJS}
	gcc -o $@ -g ${OBJS}

${OBJS}: functions.h Makefile

run:
	./a.out ${file1} ${file2}

clean:
	rm -f *.o lab6
