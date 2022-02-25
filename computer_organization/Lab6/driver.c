#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/**************************
 *Jacob Vickio
 *CPSC2310 Spring 2021            
 *UserName: jvickio                               
 *Instructor:  Dr. Yvon Feaster  
*************************/

#define MAX(X, Y) (X) > (Y) ? (X) : (Y)
#define MIN(X, Y) (X) < (Y) ? (X) : (Y)
#define ABS(X) -(X) > 0 ? -(X) : (X)
#define LARGEST(X, Y, Z) (MAX(X, Y)) > (MAX(X, Z)) ? MAX(X, Y) : MAX(X, Z)
#define SMALLEST(X, Y, Z) (MIN(X, Y)) < (MIN(X, Z)) ? MIN(X, Y) : MIN(X, Z)
#define DEBUG_FPRINT() printf("In File %s line %d", __FILE__, __LINE__)
#define ISEVEN_ODD(X) (X % 2) == 0 ? "Even" : "Odd"
#define MALLOC(X, t) (t *)malloc(sizeof(t))

#define ADD_TO_SUM(sum_number, value) sum ## sum_number += value

int main() {
    int sum1 = 1;
    int* num = NULL;
    
    // Print Return 
    printf("%d\n", printReturn(1, 2, 1));
    printf("%d\n", printReturn(100, 0, 2));
    printf("%d\n", printReturn(100, 50, 3));
    printf("%d\n\n", printReturn(4, 4, 4));
    
    // Maximum
    printf("5, 4\t\tMax: %d\n", MAX(5, 4));
    printf("10.5, 11.9\tMax: %.1f\n", MAX(10.5, 11.9));
    printf("'a', 'b'\tMax: %c\n\n", MAX('a', 'b'));
    
    // Minimum 
    printf("5, 4\t\tMin: %d\n", MIN(5, 4));
    printf("10.5, 11.9\tMin: %.1f\n", MIN(10.5, 11.9));
    printf("'a', 'b'\tMin: %c\n\n", MIN('a', 'b'));
    
    // Absolute Value
    printf("-3\t\tABS: %d\n", ABS(-3));
    printf("3\t\tABS: %d\n", ABS(3));
    printf("0\t\tABS: %d\n\n", ABS(0));
    
    // Largest 
    printf("1, 2, 3\t\tLARGEST: %d\n", LARGEST(1, 2, 3));
    printf("'a', 'b', 'c'\tLARGEST: %c\n", LARGEST('a', 'b', 'c'));
    printf("'c', 'b', 'a'\tLARGEST: %c\n\n", LARGEST('c', 'b', 'a'));
    
    // Smallest
    printf("1, 2, 3\t\tSMALLEST: %d\n", SMALLEST(1, 2, 3));
    printf("'a', 'b', 'c'\tSMALLEST: %c\n", SMALLEST('a', 'b', 'c'));
    printf("'c', 'b', 'a'\tSMALLEST: %c\n\n", SMALLEST('c', 'b', 'a'));
    
    // DEBUG FPRINT 
    DEBUG_FPRINT();
    printf("\n\n");
    
    // Even or Odd
    printf("4 is %s\n", ISEVEN_ODD(4));
    printf("1 is %s\n\n", ISEVEN_ODD(1));
    
    // Memory Allocation
    num = MALLOC(5, int);
    printf("The address of num is: %p\n", num);
    
    // Add to Sum 
    printf("Add_to_Sum: %d\n", ADD_TO_SUM(1, 15));
    
    return 0;
}
