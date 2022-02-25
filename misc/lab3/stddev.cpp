#include "stddev.h"
using namespace std;

float calMean(float* data, int n){
    float mean = 0;
    for(int i = 0; i < n; i++)
    {
        mean += data[i];
    }
    return mean/float(n);
}


float calVariance(float* data, int n){
    float mean = 0;
    for(int i = 0; i < n; i++)
    {
        mean+=data[i];
    }
    mean/=float(n);
    float variance = 0;
    for(int i = 0; i < n; i++)
    {
        variance+= pow(data[i] - mean,2.0);
    }
    return variance/n;
	
}


float calStdev(float* data, int n){
    float mean = 0;
    for(int i = 0; i < n; i++)
    {
        mean += data[i];
    }
    mean/=float(n);
    float variance = 0;
    for(int i = 0; i < n; i++)
    {
        variance += pow(data[i] - mean,2.0);
    }
    variance/=float(n);
    return sqrt(variance);
}


// add implementation for function construct below this comment.
float construct(Stats* s1, float* newData, int n, float (*funcPtr1)(float*, int)) {
/* Use the function pointer within the struct and set it equal to funcPtr1 so that the function can point to multiple different functions */
s1->funcPtr = funcPtr1;
s1->stat = s1->funcPtr(newData, n);
}
// return type: float
// incoming parameters: a Struct pointer, a float, an int, and a pointer
// that can point to calMean, calVariance, or calStdev finctions above

// add implementation for function output below this comment.
void output(Stats* s1, Stats* s2, Stats* s3, void (*funPtr)(Stats*, Stats*, Stats*)) {
/* Here just simply execute the funPtr function with included parameters and since it is a function pointer it will be able to execute more than 1 function */
funPtr(s1, s2, s3);
} 
// return type: void
// incoming parameters: three Stats pointers, and a pointer that can point 
// to either min or max functions declared above

void min(Stats* s1, Stats* s2, Stats* s3){
    float min = 10000;
    if(s1->stat>s2->stat)
    {
        min = s2->stat;
    }
    else
    {
        min = s1->stat;
    }

    if(min > s3->stat)
        min = s3->stat;

    cout << "min: " << min << endl;
}


void max(Stats* s1, Stats* s2, Stats* s3){
    float max = -10000;
    if(s1->stat<s2->stat)
    {
        max = s2->stat;
    }
    else
    {
        max = s1->stat;
    }

    if(max < s3->stat)
        max = s3->stat;

    cout << "max: " << max << endl;
}
