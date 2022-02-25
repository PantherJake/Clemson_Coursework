#include <iostream>
#include <string>
#include "stddev.h"
using namespace std;

int main() {
int n = 0;

/*  User input for size of array for standard deviation */
cout << "Please enter your given number : ";
cin >> n;
n = n + 1;

/* Allocate space in memory for the pointer array */
float* data = new float[n];

/* Initialize array to specified numbers stated in the lab file */
for (int i = 1; i < n; ++i) {
data[i] = 4 * i;
}

/* Call standard deviation calculation function */
stats(data, n);

cout << "Your standard deviation is :  " << data[0] << "\n";

delete []data;

return 0;
}
