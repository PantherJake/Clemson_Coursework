/* 
rockpaperscissors.c
Jacob Vickio
CPSC 1010-200, CPSC 1011-003
Lab 05 - Part 3
09/26/19

This program takes a user input and allows the user to play rock, paper, scissors with the computer. It is done by taking a user input and out putting a random computer response.

Academic Honesty Declaration:
The following code represents my own work and I have neither received nor given assistance that violates the collaboration policy associated with this assignment. I have not copied or modified code from any other source other than the lab assignment, course textbook, or course lecture slides. Any unauthorized collaboration or use of materials not permitted will be subjected to academic integrity policies of Clemson University and CPSC 1010/1011.

I acknowledge that this lab assignment is based upon an assignment created at Clemson University and that any publishing or posting of this code is prohibited unless I receive written permission from Clemson University.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {

int userInput = 0;
int userScore = 0;
int compScore = 0;
int tieScore;
int compInput;
char gameInput;
int i;

printf("Starting the CPSC 1011 Rock, Paper, Scissors Game!\n\n");

printf("Enter the number of matches to play: ");
scanf(" %d", &userInput);

for (i = 1; i < userInput; i = i + 1) {
	printf("\t\t\nMatch %d: Enter R for rock, P for paper, or S for scissors: ", 		i);
	printf("\n");
	scanf(" %c", &gameInput);
	compInput = rand() % 3;

	if ((gameInput == 'R' || gameInput == 'r') && compInput == 0) {
		printf("\tThe computer chose rock. You tied.\n");
		tieScore = tieScore + 1;
	}
	else if ((gameInput == 'R' || gameInput == 'r') && compInput == 1) {
		printf("\tThe computer chose scissors. You win!\n");
		userScore = userScore + 1;
	}
	else if ((gameInput == 'R' || gameInput == 'r') && compInput == 2) {
		printf("\tThe computer chose paper. You lose.\n");
		compScore = compScore + 1;
	}
	else if ((gameInput == 'S' || gameInput == 's') && compInput == 0) {
		printf("\tThe computer chose rock. You lose.\n");
		compScore = compScore + 1;
	}
	else if ((gameInput == 'S' || gameInput == 's') && compInput == 1) {
		printf("\tThe computer chose scissors. You tied.\n");
		tieScore = tieScore + 1;
	}
	else if ((gameInput == 'S' || gameInput == 's') && compInput == 2) {
		printf("\tThe computer chose paper. You win!\n");
		userScore = userScore + 1;
	}
	else if ((gameInput == 'P' || gameInput == 'p') && compInput == 0) {
		printf("\tThe computer chose rock. You win!\n");
		userScore = userScore + 1;
	}
	else if ((gameInput == 'P' || gameInput == 'p') && compInput == 1) {
		printf("\tThe computer chose scissors. You lose.\n");
		compScore = compScore + 1;
	}
	else if ((gameInput == 'P' || gameInput == 'p') && compInput == 2) {
		printf("\tThe computer chose paper. You tied.\n");
		tieScore = tieScore + 1;
	}
	// print out scores
	printf("\n\tScores: ");
	if (userScore > 0) {
		printf("You-%d ", userScore);
	}
	if (compScore > 0) {
		printf("Computer-%d ", compScore);
	}
	if (tieScore > 0) {
		printf("Ties-%d ", tieScore);
	}
	
} 

printf("The game of %d matches is complete. The final scores are:\n", userInput);
printf("You:\t\t%d\n", userScore);
printf("Computer:\t%d\n", compScore);
printf("Ties:\t\t%d\n", tieScore);

return 0;
}
















