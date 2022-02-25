/*  program 17.4, page 398  */
/*  from Kochran's C Programming textbook */
/* 
Jacob Vickio
CPSC 1010-200, CPSC 1011-003 
Lab 07 - Part 3
10/11/19

Academic Honesty Declaration
The following code represents my own work and I have neither received nor given assistance that violates the collaboration policy posted with this assignment. I have not copied or modified code from any other source other than the lab assignment, course textbook, or course lecture slides. Any unauthorized collaboration or use of materials not permitted to will be subjected to academic integrity policies of Clemson University and CPSC 1010/1011.

I acknowledge that this lab assignment is based upon a an assignment created by Clemson University and that publishing or posting of this code is prohibited unless I receive written permission from Clemson University.

Description: This program takes the values from the array and sums them up then prints the sum.
*/

#include <stdio.h>

int main (void) {
	
	const int data[5] = {1, 2, 3, 4, 5};
	int i, sum = 0;

/* Change the value that i is being compared to in the loop to i < 5, rather than i >= 0 */
	for (i = 0; i < 5; i++) {
		sum += data[i];
	}

	printf ("sum = %d\n", sum);

	return 0;
}
