#include <iostream>
#include <math.h>
#include "stddev.h"
using namespace std;

void stats(float* data, int n) {
	float average = 0;
	float variance = 0;
	float sum = 0;
	/* This for loop takes the average of all the numbers in the array */
	for (int i = 1; i < n; ++i) {
		sum = sum + data[i];
	}
	average = sum / (n - 1);
	
	/* This for loop squares the numbers inside the array when subtracted by	n */
	for (int i = 1; i < n; ++i) {
		variance += pow((data[i] - average), 2.0);
	}
	
	/* This averages the numbers that were found from using the mathematical 	method above to find variance. Now square root to find the standard devi	ation */ 
	variance = variance / (n - 1);
	data[0] = sqrt(variance);
}
