/* 
Jacob Vickio
CPSC 1010-200, CPSC 1011-003 
Lab 07 - Part 3
10/11/19

Academic Honesty Declaration
The following code represents my own work and I have neither received nor given assistance that violates the collaboration policy posted with this assignment. I have not copied or modified code from any other source other than the lab assignment, course textbook, or course lecture slides. Any unauthorized collaboration or use of materials not permitted to will be subjected to academic integrity policies of Clemson University and CPSC 1010/1011.

I acknowledge that this lab assignment is based upon a an assignment created by Clemson University and that publishing or posting of this code is prohibited unless I receive written permission from Clemson University.
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
// Initialize variables needed for the program
int binNum[20];
double userInput;
double userInput1;
int realNum;
int remain;
const int num_val = 20;
bool printCon;

printf("Starting the CPSC 1011 Decimal to Binary Converter!\n");
/* While an end of function has not been declared (ctrl + D) continue the conversion of binary numbers */
while (!feof(stdin)) {

	printf("Please enter a positive whole number (or EOF to quit): ");
	scanf("%lf", &userInput);
	userInput1 = userInput;
	printf("\n");
	if (feof(stdin)) {
	break;
	}

	realNum = userInput;
// Use logical statements to determine whether the array values should be 1s or 0s
	if (userInput - (int)userInput == 0 && userInput > 0) {

		for (int i = 0; i < num_val; ++i) {
			remain = ((int)userInput) % 2;
			userInput = userInput / 2;
			binNum[i] = remain;
		}
	}
	
	else { 
		printf("\n");
		printf("\tSorry, that was not a positive whole number.\n");
		continue;
	}
// Use boolean variable to determine whether to start printing or not
	printCon = false;
	printf("\t%d (base-10) is equivalent to ", (int)userInput1);
	for (int i = num_val - 1; i >= 0; i--) {
		if (binNum[i] == 1) {
			printCon = true;
		}
		if (printCon == true) {
		printf("%d", binNum[i]);
		}
	}
	printf(" (base-2)!\n");
}
printf("\n");
printf("Thanks for using the CPSC 1011 Decimal to Binary Generator. Goodbye!");		
}



