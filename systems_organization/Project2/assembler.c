#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void registerException(int lineNum);

int main(int argc, char* argv[]) {
  FILE* inFile = fopen(argv[1], "r");
  FILE* outFile = fopen(argv[2], "wb");
  if(inFile == NULL) {
    printf("Error on line 8: Failed opening input file");
    return -1;
  }


  char ALUop
  int count;

}

void registerException(int lineNum) {
  printf("Error on line %d: Register value must be between 0 and 32 inclusive\n", lineNum);
  exit(0);
}
