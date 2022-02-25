#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"

// Jacob Vickio, jvickio, 2

int main() {
    // Absolute Value Test | |
    assert(absValue(-100) == 100);
    assert(absValue(-45) == 45);
    
    // Binary And Test &
    assert(binaryAnd(6, 5) == 4);
    assert(binaryAnd(12, 4) == 4);
    
    // Binary Not Or Test ~(int | int)
    assert(binaryNotOr(0x6, 0x5) == 0xFFFFFFF8);
    assert(binaryNotOr(0x3, 0x2) == 0xFFFFFFFC);
    
    // Binary Or Test |
    assert(binaryOr(6, 7) == 7);
    assert(binaryOr(8, 10) == 10);
    
    // Binary Exclusive Or Test ^
    assert(binaryXor(4, 5) == 1);
    assert(binaryXor(10, 16) == 26);
    
    // Unsigned Add Test
    assert(unsignedAddOk(3, 1) == 4);
    assert(unsignedAddOk(4, 3) == 7);
    
    // Twos Comp Addition Test
    assert(twosAddOk(2, -3) == -1);
    assert(twosAddOk(47, 50) == 97);
    
    // Twos Comp Subtract Test
    assert(twosSubtractOK(3, 2) == 1);
    assert(twosSubtractOK(4, 5) == -1);
    
    return 0;
}
