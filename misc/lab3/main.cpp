#include "stddev.h"
#include <iostream>
using namespace std;

int main()
{
   int n = 0;
   cout << "Please type the size of your array: " << endl;
   cin >> n;

   float* data = new float[n];
   
   for(int i = 0; i < n; i++)
   {
/* This loop initializes the array with numbers so that the operations can be called in future functions */
       data[i] = (i+1)*4;
      // cout << "data: " << data[i] << endl;
   }

   // declare three Stats pointers below named mean, variance, and stdev
/* Allocate the memory of these three so that there is enough memory within the variables that a function pointer can be used to calculate the different operations. */
/* If this were done in C, the correct call would be Stats* mean = (Stats*)malloc(sizeof(Stats)); */
Stats* mean = new (Stats);
Stats* variance = new (Stats);
Stats* stdev = new (Stats);
   // and allocate memory for each of the using malloc, calloc or new
   // calling function construct to calculate the mean
   construct(mean, data, n, calMean);
   
  
   // print the mean below this comment
/* mean->stat is used because that is a member of the mean struct that has been executed with the previous function call */
   cout << "mean: " << mean->stat  << endl;
   
   // calling function construct to calculate the variance
   construct(variance, data, n, calVariance);
   
   
   // print the variance below this comment
   cout << "variance: " << variance->stat << endl;
   // calling function construct to calculate the stdev
   construct(stdev, data, n, calStdev);
   

   // print the variance below this comment
   cout << "stdev: " << stdev->stat << endl;
   
   // calling function output with min and max
/* Output is called both times with min and max which makes it a simple transition in the function definition where you simply have to plug the parameters in and solve for min and max */
   output(mean, variance, stdev, min);
   output(mean, variance, stdev, max);

   // free memory that you have allocated above for the three pointers to Stats here
/* If this were to be done in C, the programmer would have to use the free() call instead of delete */
delete mean;
delete variance;
delete stdev;
}
