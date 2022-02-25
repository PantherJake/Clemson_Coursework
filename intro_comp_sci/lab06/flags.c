/*
Jacob Vickio
CPSC 1010-200, CPSC 1011-003
10/01/19
Lab 06 - Part 3

Purpose: This program takes a user inputted number of 1-3 (depending on country) and makes a file containing the country's flag.

Academic Honesty Declaration: 
The following code represents my own work and I have neither given nor received that violates the collaboration policy posted with this assignment. I have not copied or modified code from any other source other than the lab assignment, course textbook, or course lecture slides. Any unauthorized collaboration or use of materials not permitted will be subjected to academic integrity policies of Clemson University and CPSC 1010/1011.

I acknowledge that this lab assignment is based upon an assignment created at Clemson University and that any posting or publishing of this code is prohibited unless I receive written permission from Clemson University.
*/

#include <stdio.h>

// Use functions to make the ppm files header and pixel coloring.



image calculate_height (int width, int country_code) {
image k;
switch(country_code) {
	case 1:
	k.height = (3.0 * width) / 8.0;
	break;
	case 2:
	k.height = (2.0 * width) / 3.0;
	break;
	case 3:
	k.height = (2.0 * width) / 3.0;
	break;
	case 4:
	k.height = (2.0 * width) / 3.0;
	break;
	default:
	break;
}

k.width = width;
k.country_code = country_code;
return k;
}

void make_ppm_header (image var) {
fprintf(stdout, "P6\n");
fprintf(stdout, "%d %d %d\n", var.width, var.height, 255);
}

void make_pixel (pixel colors) {
fprintf(stdout, "%c%c%c", colors.r, colors.g, colors.b);
}

// Function that actually creates the image once called in main()
void make_ppm_image (int width, int country_code) {
pixel color;
image flag = calculate_height(width, country_code);
make_ppm_header(flag);

for (int i = 0; i < flag.height; ++J) {
	for (int j = 0; j < flag.width; ++j) {
		color = get_color(i, j, flag);
		make_pixel(color);
	}
}
}

/*Initialize main function in order to collect user input and initiate the flag creaiton.*/
int main() {

int height;
int width;
int country_code;
fprintf(stderr, "\nWhat country's flag do you want to create? (must be between and including 1(Poland), 2(Netherlands) and 3(Italy): ");

fscanf(stdin, "%d", &country_code);

if ((country_code <= 0) && (country_code >= 4) {
printf("\nInvalid country code value.");
return 0;
}

fprintf(stderr, "\nWhat width in pixels do you want it to be? ");

fscanf(stdin, "%d", &width);
fprintf(stderr, "\n");

if (width <= 0) {
printf("\nInvalid width value.");
return 0;
}

fprintf(stderr, "\nMaking country %d's flag with width %d pixels... \n", country_code, width);
make_ppm_image(width, country_code);
fprintf(stderr, "Done!\n");

}
	






