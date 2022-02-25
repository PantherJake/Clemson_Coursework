/*
Jacob Vickio
C29552702
CPSC 1010-200 and CPSC 1011-003
Lab 2 - Exercise 1
*/

/* No . to seperate stdio.h */
#include <stdio.h>
/* User did not initiate with a { mark */
int main (void){
/* Program must be opted to support floating point numbers. This is done by changing the variables to double instead of int, and %d to %lf. */
double kilometers;
double miles;

// Read input from the user
/* There was not an ending quotation mark for the \n command*/
printf("\n");
printf("Please enter the distance in miles: ");
/* There was not a quotation mark before %d, which would result in a syntax error */
/* There was a colon instead of a semicolon at the end of the line of code, which would result in a syntax error. */
scanf("%lf", &miles);
/* The programmer forgot to put printf, and instead just used print (syntax error) */
printf("\n");

// Calculate distance in kilometers from miles
kilometers = 1.61 * miles;

// Print the distances
/* The user accidentally placed another & sign next to the words (syntax error) */
printf("%.2lf miles is equal to ", miles);
/* When using printf, you do not need to use the & sign when summoning the var */
/* The programmer did not put a colon at the end of the printf line of code below (syntax error). */
printf("%.2lf kilometers", kilometers);
printf("\n");

return 0;
}
