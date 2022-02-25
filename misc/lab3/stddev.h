#include <iostream>
#include <cmath>

using std::pow;

// create a struct Stats below this comment
typedef struct Stats {
float stat;
float (*funcPtr)(float*, int);
}Stats;
// struct members are a float variable and a pointer that can point to  
// calMean, calVariance, or calStdev finctions below

float calMean(float* data, int n);
float calVariance(float* data, int n);
float calStdev(float* data, int n);

void max(Stats* s1, Stats* s2 , Stats* s3);
void min(Stats* s1, Stats* s2 , Stats* s3);


// add the prototype for function "construct" under this comment
float construct(Stats* s1, float* newData, int n, float (*funcPtr)(float*, int));
// return type: float
// incoming parameters: a Struct pointer, a float, an int, and a pointer
// that can point to calMean, calVariance, or calStdev finctions above





// add the prototype for function "output" under this comment
void output(Stats* ns1, Stats* ns2, Stats* ns3, void (*funPtr)(Stats* s1, Stats* s2, Stats* s3)); 
// return type: void
// incoming parameters: three Stats pointers, and a pointer that can point 
// to either min or max functions declared above






