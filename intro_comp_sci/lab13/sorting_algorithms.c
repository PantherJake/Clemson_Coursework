#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Sorts by finding the minimum element from an unsorted portion of the array and placing it at the beginning. */
void selectionSort(int numberArray[], int num) {
    int i = 0;
    int j = 0;
    int temp = 0;
    int index_smallest = 0;

    for (i = 0; i < num; i++){
        index_smallest = i;
        for (j = i + 1; j < num; j++){
            if (numberArray[j] < numberArray[index_smallest]) {
                index_smallest = j;
	    }
        }
        temp = numberArray[i];
        numberArray[i] = numberArray[index_smallest];
        numberArray[index_smallest] = temp;
    }
}

/* Similar to using playing cards, looking from left to right the sorter places lower values in the front and keeps values greater than the others in the same spot until a value smaller comes up afterwards. */
void insertionSort(int numberArray[], int num) {
    int temp = 0; int i = 0; int j = 0;

    for (i = 1; i < num; i++){
        temp = numberArray[i];
        j = i - 1;
        while (temp < numberArray[j] && j >= 0) {
            numberArray[j + 1] = numberArray[j];
            j--;
        }
        numberArray[j + 1] = temp;
    }
}

/* Pairs the values together and sees which is greater and sorts it based on that. Repeatedly swaps adjacent values based on which is greater over, and over until the values are completely paired */
void bubbleSort(int numberArray[], int num) {
    int i = 0; int j = 0; int temp = 0;

    for (i = 0; i < num; i++){

        for (int j = 0; j < (num - i - 1); j++){
            if (numberArray[j]> numberArray[j+1]){
                temp = numberArray[j];
                numberArray[j] = numberArray[j+1];
                numberArray[j+1] = temp;
            }
        }
    }
}

/* Quick sort picks certain spots in the array to evaluate from. The beginning, median, and end of the array are common values from which quick sort begins. It quickly puts all elements smaller than the numbers picked in front of it, and the numbers larger behind it. */
void quickSort(int low, int high, int numberArray[]) {
    int pivot = 0;
    int i = 0;
    int j = 0;
    int temp = 0;

    if (low < high){
        pivot = low;
        i = low;
        j = high;

        while (i < j){
            while (numberArray[i] <= numberArray[pivot] && i <= high){
                i++;
            }
            while (numberArray[j] > numberArray[pivot] && j >=low){
                j--;
            }

            if (i < j) {
                temp = numberArray[i];
                numberArray[i] = numberArray[j];
                numberArray[j] = temp;
            }

        }
        temp = numberArray[j];
        numberArray[j] = numberArray[pivot];
        numberArray[pivot] = temp;
        quickSort(low, j-1, numberArray);
        quickSort(j+1, high, numberArray);
    }
  }

// Write Integer Array to Output File
// Write Integer Array to Output File
/* Write array to file creates a file of sorted integers after the sorting algorithms have gone through. It creates a different file based on the user input from the main. In the file it prints the values of the sorted digits that come from the array after they have been sorted  */
void writeArrayToFile(int array[], int num) {
  FILE * pFile;
  switch(num) {//based off the file size create a new file with size name
    case 10:
		pFile = fopen("sorted.algorithm.small.output", "w+");
		break;
    case 100:
		pFile = fopen("sorted.algorithm.medium.output", "w+");
		break;
    case 1000:
		pFile = fopen("sorted.algorithm.large.output", "w+");
		break;
    case 10000:
		pFile = fopen("sorted.algorithm.jumbo.output", "w+");
		break;
	default:
		pFile = fopen("rand" , "w+");
 		break;
  }

  if (pFile == NULL) {
	  perror ("Error opening file");
  }
  else
  {
    int i;
    for(i = 0; i < num; i++) {
      fprintf(pFile, "%d, ", array[i]);
    }
    fclose (pFile);
  }
  return;
}
