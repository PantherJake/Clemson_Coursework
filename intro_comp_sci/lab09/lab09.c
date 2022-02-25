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
#include <string.h>
#include <stdbool.h>

const int MAX_SIZE = 20;

/* Declare romanNumeral struct to hold values that will be called later in the program. */
typedef struct romanNumeral_struct {
	int romanNumeraltoConvert;
	char numeral[20];
} romanNumeral;

/* Declare functions that will be used throughout the main to derive a decimal value from a roman numeral. */
bool Prompt(char romanNumeral[], int maxSize);

bool ProperRoman(const char romanNumeral[]);

romanNumeral ConvertRoman(romanNumeral romanNumeralToConvert);

void PrintRoman(romanNumeral romanNumeralToConvert);

/* Main is called, the struct is initiated and the loop for creating roman numerals is set. */
int main(void) {
	romanNumeral myRoman;

	while (Prompt(myRoman.numeral, MAX_SIZE)) {
		myRoman = ConvertRoman(myRoman);
		PrintRoman(myRoman);
	}

	printf("Thank you for using the Roman Numeral to Decimal calculator.\nGoodbye!\n");
}

/* Prompt scans for the user input for the character of the roman numerals. */
bool Prompt(char numeral[], int maxSize) {
	printf("Please input a value in roman numerals or EXIT to quit: ");
	scanf(" %s", numeral);
/* This calls the proper roman function to ensure the user's input is legal. */
	while (!ProperRoman(numeral)) {

/* If the user types EXIT the program ends. */
	if (numeral[0] == 'E' && numeral[1] == 'X' && numeral[2] == 'I' && numeral[3] == 'T') {
		return false;
	}
	printf("Please input a value in roman numerals or EXIT to quit: ");
	scanf(" %s", numeral);
	}
	return true;
}

/* Proper roman takes the user input for 'numeral' in the romanNumber struct and tests it to make sure the string is a roman numeral. */
bool ProperRoman(const char numeral[]) {
	bool isRoman = false;
	if (strlen(numeral) > 20) {
		printf("Error! Too many characters!! Roman Numbers must be less than 21 characters long!.\n");
		return false;
	}
	for (int i = 0; i < strlen(numeral); ++i) {
		switch (numeral[i]) {
			case 'M':
			isRoman = true;
			break;
			case 'L':
			isRoman = true;
			break;
			case 'X':
			isRoman = true;
			break;
			case 'I':
			isRoman = true;
			break;
			case 'V':
			isRoman = true;
			break;
			case 'C':
			isRoman = true;
			break;
			case 'D':
			isRoman = true;
			break;
			default:
			if (numeral[0] != 'E') {
			printf("Illegal Characters.\n\n");
			}
			return false;
			break;
		}
	}
	if (isRoman == true) {
	return true;
	}
}

/* Convert roman is a function that is type of the struct and calculates the decimal value of the roman number based on what is inputted */

romanNumeral ConvertRoman(romanNumeral temp) {
	int addedArray[50];
	int total = 0;
	int added = 0;
	for (int i = 0; i < strlen(temp.numeral); ++i) {
		switch(temp.numeral[i]) {
		case 'L':
		addedArray[i] = 50;
		total++;

		break;
		case 'C':
		addedArray[i] = 100;
		total++;
		break;

		case 'M':
		addedArray[i] = 1000;
		total++;			
			
		break;
		case 'V':
		addedArray[i] = 5;
		total++;

		break;
		case 'I':
		addedArray[i] = 1;
		total++;

		break;
		case 'X':
		addedArray[i] = 10;
		total++;

		break;
		case 'D':
		addedArray[i] = 500;
		total++;
		
		break;
		default:
		printf("Error.");
		break;
		}
	}

/* For loop used to test the position of where the roman numerals fall and makes them negative if they are behind a bigger number */
for (int i = 0; i < total; ++i) {
	if (i < total - 1) {
		if (addedArray[i] < addedArray[i + 1]) {
			addedArray[i] = -(addedArray[i]);
		}
	}
	added += addedArray[i];
}
temp.romanNumeraltoConvert = added;
return temp;
}
/* Prints the numeral character string and the converted decimal */
void PrintRoman(romanNumeral k) {
	printf("%s = %d\n\n", k.numeral, k.romanNumeraltoConvert);
}


			
		
	
	
		


		
