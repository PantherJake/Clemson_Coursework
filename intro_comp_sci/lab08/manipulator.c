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
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function needed to replace characters in the sentence.
void replaceAll(char userstring[]) {
	int count = 0;
	char j;
	char k;
	printf("Enter the character to replace: ");
	scanf(" %c", &j);
	printf("\n");
	
	// Loop to insure that there is a character in the string equal to the 		// character inputted
	for (int i = 0; i < strlen(userstring); ++i) {
		if (userstring[i] == j) {
			++count;
		}
	}
	
	// In case the character is not equal to one in the string the user is 
	// returned to main function.
	if (count == 0) {
		printf("Error, %c is not in the string", k);
		printf("\n");
		return;
	}

	// Scan for new character and execute loop to replace characters with k.
	printf("Enter the new character: ");
	scanf(" %c", &k);
	for(int i = 0; i < strlen(userstring); ++i) {
		if (userstring[i] == j) {
			userstring[i] = k;
		}
	}
	// Print new sentence.
	printf("Your new sentence is %s", userstring);
}

int main() {
	char userIn[12];
	char sentence[25];

	// Scan for string to modify
	printf("Enter a string (up to 25 characters) to be transformed: ");
	fgets(sentence, 25, stdin);

	printf("\n");

// Loop to continue replacing characters until user types "quit"
while (1) {
	// Scan for user input command
	printf("Enter your command (quit, replace all): ");
	fgets(userIn, 12, stdin);

	// Move all letters inputted to upper case to make sure the input is tested 
	// for correctly.
	for (int i = 0; i < strlen(userIn); ++i) {
		userIn[i] = toupper(userIn[i]);
	}

	// Execute replaceAll function if inputted string is replace all.
	if (strcmp(userIn, "REPLACE ALL") == 0) {
		replaceAll(sentence);
		getchar();
	}

	// If user string input is quit then break the loop and end program.
	else if (userIn[0] == 'Q' && userIn[1] == 'U' && userIn[2] == 'I' && userIn[3] == 'T') {
		break;
	}

	// If other than the command is invalid and return to first command in loop.
	else {
		printf("Sorry that command is invalid, Please type one of the options.");
		printf("\n");
	}
}
}


	


		
		
