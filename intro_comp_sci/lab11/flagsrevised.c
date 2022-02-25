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

pixel get_color (int column, int row, image k) {
if (l.country_code == 1) {
color.r = 255;
color.g = 0;
color.b = 0;

void make_ppm_header (image temp) {
fprintf(stdout, "P6\n");
fprintf(stdout, "%d %d %d\n", temp.width, temp.height, 255);
}

void make_pixel (pixel temp) {
fprintf(stdout, "%c%c%c", temp.r, temp.g, temp.b);
}

// Function that actually creates the image once called in main()
void make_ppm_image (image k) {
/*Switch statement used to determine which flag will be created since country_code is a user inputted value */
switch(country_code) {
	case 1:
	//Poland
	k.height = 0.625 * (double) k.width;
	make_ppm_header(k.width, k.height);
	for (int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if (i < (0.5 * height)) {
				make_pixel(255, 255, 255);
			}
			else {
				make_pixel(255, 0, 0);
			}
		}
	}
	break;
	case 2:
	// Netherlands
	height = (double) width * (2.0 / 3.0);
	make_ppm_header(width, height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i < (height * (1.0 / 3.0))) {
				make_pixel(255, 0, 0);
			}
			else if (i > (height * (1.0 / 3.0)) && i < (height * (2.0 / 				3.0))) {
				make_pixel(255, 255, 255);
			}
			else {
				make_pixel(0, 0, 255);
			}
		}
	}
	break;
	case 3:
	// Italy 
	height = (double) width * (2.0 / 3.0);
	make_ppm_header(width, height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (j < (width * (1.0 / 3.0))) {
				make_pixel(0, 255, 0);
			}
			else if (j < 2 * (width * (1.0 / 3.0))) {
				make_pixel(255, 255, 255);
			}
			else {
				make_pixel(255, 0, 0);
			}
		}
	}
	break;
	case 4:
	// Benin
}
}

/*Initialize main function in order to collect user input and initiate the flag creaiton.*/
int main() {

image p;
fprintf(stderr, "\nWhat country's flag do you want to create? (must be between and including 1(Poland), 2(Netherlands) and 3(Italy): ");

fscanf(stdin, "%d", &p.country_code);

fprintf(stderr, "\nWhat width in pixels do you want it to be? ");

fscanf(stdin, "%d", &p.width);
fprintf(stderr, "\n");

fprintf(stderr, "\nMaking country %d's flag with width %d pixels... \n", p.country_code, p.width);
make_ppm_image(p);
fprintf(stderr, "Done!\n");

}
	






