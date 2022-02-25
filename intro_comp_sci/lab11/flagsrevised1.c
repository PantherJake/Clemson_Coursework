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

/* Define structs that will be used to hold the data used to create the flags. Values here will depend on what country code the user inputs. */
typedef struct pixel_struct {
int r;
int g;
int b;
} pixel;

typedef struct image_struct {
int width;
int height;
int country_code;
} image;

/* This function figures out what color to print based on the value of country code and the values in respect to width and height of the flag. */
pixel get_color (int column, int row, image g) {
pixel picture;
/* Switch statement in order to change colors printed based on value of country code */
switch (g.country_code) {
	case 1:
	if (column <= (0.5 * g.height)) {
		picture.r = 255;
		picture.g = 255;
		picture.b = 255;
	}
	else {
		picture.r = 255;
		picture.g = 0;
		picture.b = 0;
	}
	break;
	case 2:
	if (column <= (.33333 * g.height)) {
		picture.r = 255;
		picture.g = 0;
		picture.b = 0;
	}
	else if  ((column > (.33333 * g.height)) && (column <= (0.66666 * g.height))) {
		picture.r = 255;
		picture.g = 255;
		picture.b = 255;
	}
	else {
		picture.r = 0;
		picture.g = 0;
		picture.b = 255;
	}
	break;
	case 3:
	if (row <= (g.width * 0.33333)) {
		picture.r = 0;
		picture.g = 255;
		picture.b = 0;
	}
	else if ((row > (g.width * 0.33333)) && (row <= (g.width * 0.66666))) {
		picture.r = 255;
		picture.g = 255;
		picture.b = 255;
	}
	else {
		picture.r = 255;
		picture.g = 0;
		picture.b = 0;
	}
	break;
	case 4:
	if ((row >= (g.width * 0.40)) && (column < (g.height * 0.50))) {
		picture.r = 255;
		picture.g = 255;
		picture.b = 0;
	}
	else if ((row >= (g.width * 0.40)) && (column >= (g.height * 0.50))) {
		picture.r = 255;
		picture.g = 0;
		picture.b = 0;
	}
	else {
		picture.r = 0;
		picture.g = 170;
		picture.b = 0;
	}
	break;
	default:
	break;
}
/* Return the value of the pixel struct because that is the struct that deals with color */
return picture;
}

/* Calculate height with this function with respect to the inputted country code. The image struct values (width/height) will vary based on the value of country code, because not all the dimensions of the flag values are the same */
image calculate_height (int width, int country_code) {
/* Declares the image struct so that the values can be altered */
image k;
/* This switch statement changes the values of the image struct with respect to the value of country_code */
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

/* Sets the struct values equal to the parameter values that were inputted from the make ppm image function */
k.width = width;
k.country_code = country_code;
/* Return the image struct because that comes w the values that were deciphered with the function */
return k;
}

/* This function makes the header for the flag so that the ppm image has a canvas that it can print on */
void make_ppm_header (image var) {
fprintf(stdout, "P6\n");
fprintf(stdout, "%d %d %d\n", var.width, var.height, 255);
}

/* This function actually prints out the flag with respect to the color values altered within the get_color function */
void make_pixel (pixel colors) {
fprintf(stdout, "%c%c%c", colors.r, colors.g, colors.b);
}

/* This function is the bread and butter of the program. This function calls the other functions in the program and sets the proper struct values to the correct value. It also makes the header and prints out the flag. */
void make_ppm_image (int width, int country_code) {
pixel color;
image flag = calculate_height(width, country_code);
make_ppm_header(flag);

/* Needs a loop to continute testing whether the color needs to change within the get_color function */
for (int i = 0; i < flag.height; ++i) {
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
fprintf(stderr, "\nWhat country's flag do you want to create? (must be between and including 1(Poland), 2(Netherlands), 3(Italy), and 4(Benin) for corresponding flag: ");

/* This scan statement initializes the value of country code to the flag that the user wants to create. */
fscanf(stdin, "%d", &country_code);

if ((country_code <= 0) && (country_code >= 4)) {
printf("\nInvalid country code value.");
return 0;
}

fprintf(stderr, "\nWhat width in pixels do you want it to be? ");

/* This initializes the width that the user wants the flag to be in pixels */
fscanf(stdin, "%d", &width);
fprintf(stderr, "\n");

if (width <= 0) {
printf("\nInvalid width value.");
return 0;
}

fprintf(stderr, "\nMaking country %d's flag with width %d pixels... \n", country_code, width);
/* Calls the bread and butter function that prints out the flag */
make_ppm_image(width, country_code);
fprintf(stderr, "Done!\n");
}







