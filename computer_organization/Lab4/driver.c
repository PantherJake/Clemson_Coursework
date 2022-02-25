/** Lab 54Test program **/
#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

/******************
* Jacob Vickio    *
* CPSC 2130 Lab 4 *
* jvickio         *
* 2               *
******************/

int main() {
  unsigned int x = 0x2468acef;
  int ndx;
  unsigned int result;

  /** nget Tests **/
  printf("TESTING nget() =================================\n");
  printf("Initial Test value: %8.8X\n", x);
  for (ndx=0; ndx<8; ndx++) {
      result = nget(x, ndx);
      printf("  Position %d=%8.8X\n", ndx, result);
  }

  /** nset Tests **/
  printf("TESTING nset() =================================\n");
  x = 0x2468acef;
  printf("Initial Test value: %8.8X\n", x);
  for (ndx=0; ndx<8; ndx++) {
      result = nset(x, ndx, ndx);
      printf("  Setting position %d, result=%8.8X\n", ndx, result);
      x = result;
  }

  /** nlrotate Tests **/
  printf("TESTING nlrotate() =================================\n");
  x = 0x2468acef;
  printf("Initial Test value: %8.8X\n", x);
  for (ndx=0; ndx<8; ndx++) {
      result = nlrotate(x);
      printf("   Rotate %d, result=%8.8X\n", ndx, result);
      x = result;
  }

  return 0;
}
