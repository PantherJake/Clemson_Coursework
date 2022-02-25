#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algo.h"

int main() {
/* Initialize file pointer that will be used to read from to scan for the array. (Random numbers) Also initialize the variables/arrays that are needed for functionality of the program */
  FILE* inFP;
  int userin;
  double timeVals[3];
  clock_t start, end;
  int array[10000];
  int bubbleArray[10000];
  int quickArray[10000];
  int insertArray[10000];

/* Menu to give user options */
  printf("Welcome the CPSC 1011 sorting simulator.\n");
  printf("Which data file would you like to sort?\n");
  printf(" [1] Small file (10 items)\n");
  printf(" [2] Medium file (100 items)\n");
  printf(" [3] Large file (1,000 items)\n");
  printf(" [4] Jumbo file (10,000 items)\n\n");

  printf("Enter your choice: ");
  scanf("%d", &userin);

/* Switch statement that opens and reads from a different sized file based on userin */
/* Similar incremental steps are taken for each switch possibility only accounting for different sizes of the file */
switch(userin) {
//Small
    case 1:
/* Open the file to be read from */
    inFP = fopen("lab13_random.small.input", "r");
    if (inFP == NULL) {
	printf("Error!");
	return -1;
    }
/* Scan the number values from the file to the array */
    for (int i = 0; i < 10; ++i) {
	fscanf(inFP, "%d, ", &array[i]);
    } 
    fclose(inFP); 
/* Need different arrays because they all need to be sorted individually so that time will be recorded correctly. */
    for (int i = 0; i < 10; ++i) {
	insertArray[i] = array[i];
	bubbleArray[i] = array[i];
	quickArray[i] = array[i];
    }

/* Begin clock that will run for duration of the selection sort function */
    start = clock();
    selectionSort(array, 10);
/* End clock because the selection sort function has been completed at this point */
    end = clock() - start;
/* Calculate the amount of time the function took in milliseconds (This value will be multiplied by 1000) */
    timeVals[0] = ((double)(end) / CLOCKS_PER_SEC);

    start = clock();
    insertionSort(insertArray, 10);
    end = clock() - start;
    timeVals[1] = ((double)(end) / CLOCKS_PER_SEC);
    
    start = clock();
    bubbleSort(bubbleArray, 10);
    end = clock() - start;
    timeVals[2] = ((double)(end) / CLOCKS_PER_SEC);

    start = clock();
    quickSort(0, 10, quickArray);
    end = clock() - start;
    timeVals[3] = ((double)(end) / CLOCKS_PER_SEC);

    writeArrayToFile(array, 10);
    break;
//Medium
    case 2:
    inFP = fopen("lab13_random.medium.input", "r");
    if (inFP == NULL) {
	printf("Error!");
	return -1;
    }
    for (int i = 0; i < 100; ++i) {
	fscanf(inFP, "%d, ", &array[i]);
    } 
    fclose(inFP); 
    for (int i = 0; i < 100; ++i) {
	insertArray[i] = array[i];
	bubbleArray[i] = array[i];
	quickArray[i] = array[i];
    }

    start = clock();
    selectionSort(array, 100);
    end = clock() - start;
    timeVals[0] = ((double)(end) / CLOCKS_PER_SEC);

    start = clock();
    insertionSort(insertArray, 100);
    end = clock() - start;
    timeVals[1] = ((double)(end) / CLOCKS_PER_SEC);
    
    start = clock();
    bubbleSort(bubbleArray, 100);
    end = clock() - start;
    timeVals[2] = ((double)(end) / CLOCKS_PER_SEC);

    start = clock();
    quickSort(0, 100, quickArray);
    end = clock() - start;
    timeVals[3] = ((double)(end) / CLOCKS_PER_SEC);

    writeArrayToFile(array, 100);
    break;
//Large
    case 3:
    inFP = fopen("lab13_random.large.input", "r");
    if (inFP == NULL) {
	printf("Error!");
	return -1;
    }
    for (int i = 0; i < 1000; ++i) {
	fscanf(inFP, "%d, ", &array[i]);
    } 
    fclose(inFP); 
    for (int i = 0; i < 1000; ++i) {
	insertArray[i] = array[i];
	bubbleArray[i] = array[i];
	quickArray[i] = array[i];
    }

    start = clock();
    selectionSort(array, 1000);
    end = clock() - start;
    timeVals[0] = ((double)(end) / CLOCKS_PER_SEC);

    start = clock();
    insertionSort(insertArray, 1000);
    end = clock() - start;
    timeVals[1] = ((double)(end) / CLOCKS_PER_SEC);
    
    start = clock();
    bubbleSort(bubbleArray, 1000);
    end = clock() - start;
    timeVals[2] = ((double)(end) / CLOCKS_PER_SEC);

    start = clock();
    quickSort(0, 1000, quickArray);
    end = clock() - start;
    timeVals[3] = ((double)(end) / CLOCKS_PER_SEC);

    writeArrayToFile(array, 1000);
    break;
//JUMBO
    case 4:
    inFP = fopen("lab13_random.jumbo.input", "r");
    if (inFP == NULL) {
	printf("Error!");
	return -1;
    }
    for (int i = 0; i < 10000; ++i) {
	fscanf(inFP, "%d, ", &array[i]);
    } 
    fclose(inFP);
    for (int i = 0; i < 10000; ++i) {
	insertArray[i] = array[i];
	quickArray[i] = array[i];
	bubbleArray[i] = array[i];
    }

    start = clock();
    selectionSort(array, 10000);
    end = clock() - start;
    timeVals[0] = ((double)(end) / CLOCKS_PER_SEC);

    start = clock();
    insertionSort(insertArray, 10000);
    end = clock() - start;
    timeVals[1] = ((double)(end) / CLOCKS_PER_SEC);
    
    start = clock();
    bubbleSort(bubbleArray, 10000);
    end = clock() - start;
    timeVals[2] = ((double)(end) / CLOCKS_PER_SEC);

    start = clock();
    quickSort(0, 10000, quickArray);
    end = clock() - start;
    timeVals[3] = ((double)(end) / CLOCKS_PER_SEC);

    writeArrayToFile(array, 10000);
    break;
  }

/* This loop multiplies all the time values by 1000 so that the number printed is in milliseconds rather than seconds. */
for (int i = 0; i < 4; ++i) {
	timeVals[i] = timeVals[i] * 1000;
}

/* Print statement comparing all the different values of time based on different sorting algorithms */
  printf("Sorting with selection sort... done after %lf ms.\n", timeVals[0]);
  printf("Sorting with insertion sort... done after %lf ms.\n", timeVals[1]);
  printf("Sorting with bubble sort... done (after %lf ms.)\n", timeVals[2]);
  printf("Sorting with quick sort... (after %lf ms.)\n\n", timeVals[3]);

  printf("Finishing the program...\n");
  return 0;
}
