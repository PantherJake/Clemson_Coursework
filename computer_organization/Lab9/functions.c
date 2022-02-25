#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "functions.h"

// Jacob Vickio, jvickio, 2

int absValue(int x) { 
    return ((x >> 31) + x) ^ (x >> 31); 
}

int binaryAnd(int x, int y) { 
    return ~(~x | ~y);
}

int binaryNotOr(int x, int y) { 
    return ~x & ~y;
}

int binaryOr(int x, int y) { 
    return ~(~x & ~y); 
}

int binaryXor(int x, int y) { 
    return ~(~x & ~y) & ~(x & y); 
}

int unsignedAddOk(unsigned x, unsigned y) { 
    unsigned int sum = x + y;
    return ((sum > x) || (sum > y)) ? sum : -1;
}

int twosAddOk(int x, int y) {
    int sum = x + y;
    return ((sum > x) || (sum > y)) ? sum : 2147483648;
}

int twosSubtractOK(int x, int y) {
    int difference = x - y;
    return ((difference < x) || (difference < y)) ? difference : 2147483648;
}

