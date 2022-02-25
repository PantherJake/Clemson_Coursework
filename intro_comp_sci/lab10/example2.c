/* There are multiple bugs in this program.
Jacob Vickio
CPSC 1010-200, CPSC 1011-003 
Lab 07 - Part 3
10/11/19

Academic Honesty Declaration
The following code represents my own work and I have neither received nor given assistance that violates the collaboration policy posted with this assignment. I have not copied or modified code from any other source other than the lab assignment, course textbook, or course lecture slides. Any unauthorized collaboration or use of materials not permitted to will be subjected to academic integrity policies of Clemson University and CPSC 1010/1011.

I acknowledge that this lab assignment is based upon a an assignment created by Clemson University and that publishing or posting of this code is prohibited unless I receive written permission from Clemson University.

Description: This searches for the number 11 in a table of values. The program also takes two arrays and prints the first value from both arrays.
*/

#include <stdio.h>
#include <stdlib.h>

void Find11 ();
void PointersAreFun();

/* Main simply calls both of the other functions in the program. */
int main( void ) {
    Find11();
    PointersAreFun();
    return 0;
}
/* This function searches for the number 11 in a table array of values and if found the program prints stating that the number 11 was found. If not the program prints that 11 was not found */
void Find11 (void){
    int i = 0, count = 0, search = 1, found = 0;
    int number = 5;
    int table[10];
    
    table[0] = number;
/* Change the %i to %d */ 
    printf( "table[%d]: %d\n", count, table[count] );
    
    count = 1;
    while( count < 10 ) {
        table[count] = number++ * 2;
        printf( "table[%d]: %d\n", count, table[count] );
        count++;
    }
    
/* Add another equals sign because it is a comparison between two integers. */
    while( search == 1 ) {
        if( table[i++] == 11 ) {
            search = 0;
            found = i - 1;
        }
        if( count == i ) {
            search = 0;
        }
    }
    
    if( found )
        printf( "The number 11 is in the table at location: %d\n", found );
    else
        printf( "The number 11 is not in the table.\n" );
}

/* This function takes two arrays and prints the first values of both arrays by using pointers to switch the addresses of the values. */
void PointersAreFun(){
    puts("\nDemo on Pointers!\n");

    int myArray [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int anotheArray [10] = {10, 11, 12};
    int * ptrArray = NULL;
    int * ptrAnotherArray = NULL;
    
    ptrArray = myArray;
/* Add another statement setting the two values equal so that the *ptrAnotherArray will print the correct value. Setting address of pointer equal to the array. */
    ptrAnotherArray = anotheArray;
   
    printf("The first value of the array is %d\n", *ptrArray);
    printf("The first value of the second array is %d\n", *ptrAnotherArray);
    
    
}
