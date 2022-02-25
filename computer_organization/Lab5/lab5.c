#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//***********************
// Jacob Vickio         *
// CPSC 2310 Spring 2021*
// jvickio              *
// Dr. Yvon Feaster     *
//***********************

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf("USAGE: ./a.out <ppm-image> <out-image1>\n");
    return 1;
  }

  FILE* in_file = fopen(argv[1], "r");
  FILE* out_file1 = fopen(argv[2], "w");


  if (!in_file || !out_file1 ) {
    printf("ERROR: File(s) could not be opened.\n");
    return 1;
  }

  image_t* image = read_ppm(in_file);

  write_p6(out_file1, image);

  free(image->pixels);
  free(image);

  fclose(in_file);
  fclose(out_file1);

  return 0;
}
