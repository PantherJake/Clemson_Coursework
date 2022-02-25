#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

//***********************
// Jacob Vickio         *
// CPSC 2310 Spring 2021*
// jvickio              *
// Dr. Yvon Feaster     *
//***********************

// First meaningful line of the PPM file
typedef struct header {
  char MAGIC_NUMBER[2];
  unsigned int HEIGHT, WIDTH, MAX_COLOR;
} header_t;

typedef struct pixel {
  unsigned char R, G, B;
} pixel_t;

typedef struct image {
  header_t header;
  pixel_t* pixels;
} image_t;

header_t read_header(FILE* image_file);

image_t* read_ppm(FILE* image_file);
image_t* read_p6(FILE* image_file, header_t header);
image_t* copy_image(image_t*);

void write_header(FILE* out_file, header_t header);
void write_p6(FILE* out_file, image_t* image);
#endif
