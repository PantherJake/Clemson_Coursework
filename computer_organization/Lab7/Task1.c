#include<stdio.h>
#include<limits.h>

/**************************
 *Jacob Vickio                                
 *CPSC2310 Lab7                         
 *UserName: jvickio                                
 *Lab Section: 002                               
/************************/


int main() {
    /*Fill in a C expression that evaluates to 1 when the follow conditions are
     *true and to 0 when they are false.  Assume the value is of type int. 
     *Your code MUST follow the Rules described in the lab document. With the
     *additional restriction that you may not use equality (==) or inequality
     *(!=) test. */
    
    //Part A:  
    printf("1.\n");
    int a = -1;
    printf("prints 1 when any bit of a number equals 1 %d\n", (a && 1));
    a = 0;
    printf("prints 1 when any bit of a number equals 1 %d\n", (a && 1));

    //Part B:
    printf("\n2.\n");
    int b = 16;
    printf("prints 1 when any bit of a number equals 0 %d\n", ((~b) && 1));
    b = -1;
    printf("prints 1 when any bit of a number equals 0 %d\n", ((~b) && 1));

    //Part C:
    printf("\n3.\n");
    int c = 1;
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n", ((c & 0x000000FF) && 1));
    c = 1024;
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n", ((c & 0x000000FF) && 1)); 

    //Part D;
    printf("\n4.\n");
    int d = 1024;
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", ((~d) & 0xFF000000) && 1);
    d = -1;
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", ((~d) & 0xFF000000) && 1);

    return 0;
}

