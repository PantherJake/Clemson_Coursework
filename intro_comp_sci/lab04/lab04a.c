/*
lab04a.c
Jacob Vickio
CPSC 1010-200, CPSC 1011-003
Lab 4 - Part 3
09/19/19

This program takes numbers that the user inputs and places them in a square. Based on row, column, and diagnol lines across the square, the program calculates if the numbers add up to 15. If all add up to 15, the square is magic, if not the program prints that the square is not magic.

Academic Honesty Declaration:
The following code represents my own work and I have neither received nor given assistance that violates the collaboration policy posted with this assignment. I have not copied or modified code from any other source other than the lab assignment, course textbook, or course lecture slides. Any unauthorized collaboration or use of materials not permitted will be subjected to academic integrity policies of Clemson University and CPSC 1010/1011.

I acknowledge that this lab assignment is based upon an assignment created at Clemson University and that any publishing of this code is prohibited unless I receive written permission from Clemson University.
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

// Initialize variables for the rest of the program
int userInput1;
int userInput2;
int userInput3;
int userInput4;
int userInput5;
int userInput6;
int userInput7;
int userInput8;
int userInput9;
bool isMagic1 = false;
bool isMagic2 = false;
bool isMagic3 = false;
int diagLeft;
int diagRight;

// Scan the values of the integers for the first row
printf("Enter the values: ");
scanf("%d", &userInput1);
scanf("%d", &userInput2);
scanf("%d", &userInput3);
int row1 = userInput1 + userInput2 + userInput3;

// Scan the values of the integers for the second row
scanf("%d", &userInput4);
scanf("%d", &userInput5);
scanf("%d", &userInput6);
int row2 = userInput4 + userInput5 + userInput6;

// Scan the values of the integers for the third row
scanf("%d", &userInput7);
scanf("%d", &userInput8);
scanf("%d", &userInput9);
int row3 = userInput7 + userInput8 + userInput9;

// Set up column variables 
int column1 = userInput1 + userInput4 + userInput7;
int column2 = userInput2 + userInput5 + userInput8;
int column3 = userInput3 + userInput6 + userInput9;

// Print the square
printf("You entered:\n");
printf("%d %d %d\n", userInput1, userInput2, userInput3);
printf("%d %d %d\n", userInput4, userInput5, userInput6);
printf("%d %d %d\n\n", userInput7, userInput8, userInput9);

diagLeft = userInput1 + userInput5 + userInput9;
diagRight = userInput3 + userInput5 + userInput7;

printf("Analyzing...\n\n");

//Use logic in order to determine whether this square is logical or not
if((row1 == 15) && (row2 == 15) && (row3 == 15)) {
isMagic1 = true;
}
if((column1 == 15) && (column2 == 15) && (column3 == 15)) {
isMagic2 = true;
}
if((diagLeft == 15) && (diagRight == 15)) {
isMagic3 = true;
}

if((isMagic1 == true) && (isMagic2 == true) && (isMagic3 == true)) {
printf("This is a magic square!\n");
}
else {
printf("This square is not magic! :(\n");
}

return 0;
}




