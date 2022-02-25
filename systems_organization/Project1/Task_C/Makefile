all: dgmake

dgmake: dgemm.c
	gcc dgemm.c -O3 -Wall -Wextra -o dgmake -fopenmp

clean:
	rm -f dgmake

