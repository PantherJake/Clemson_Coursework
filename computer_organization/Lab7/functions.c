#include "functions.h"

/**************************
 *Jacob Vickio                                
 *CPSC2310 Lab7                         
 *UserName: jvickio                                
 *Lab Section: 002                               
/************************/

/*You are going to write a function that returns 1 when ran on a machine that uses
 arithmetic right shifts for data type int and yields 0 otherwise.
 FYI – I tested the solution on the SoC servers on a joey machine so you can assume
 that these machines use arithmetic right shifts. This will be useful when testing
 your algorithm.
You are to implement the  isArithmetic() function.  You are not allowed to
 change the prototype of the function. You will receive a 0 for this task if you
 change the prototype.
 */

int isArithmetic() {
    int a = (-1 >> 1) < 0;
    return a;
}

/*For this problem you must follow the Bit-Level Rules listed in the document.
 If you violate any of these Rules you will receive a 0 on this task.
You are going to write a function that returns 1 if any of the odd bits
 in an unsigned int equal one. As an example, the bit pattern 0100 0000
 has a one in the 2nd bit position so this would return 0.
 However, bit pattern 1000 0000 has a 1 in bit position 1 therefore it
 will return 1.
You are to implement the isOddOne function.  You are not allowed to
 change the prototype of the function. You will receive a 0 for this
 task if you change the prototype.
 */

int isOddOne(unsigned int x) {
    // AA = 1010 1010 for odd positioning 
    int a = !!(x & 0xAA);
    return a;
}

