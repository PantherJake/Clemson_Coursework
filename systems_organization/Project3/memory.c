//============================================================================
// Name        : memory.c
// Author      : Saavedra-Barrera [1992] copied from textbook Computer Architecture
// 		 A Quantitative Approach by Hennessy and Patterson
// Version     :
// Copyright   : Your copyright notice
// Description : measure cache 
// Compile     : gcc -o memory memory.c
// Usage       : ./memory
//============================================================================
#include <stdio.h>
#include <sys/times.h>
#include <sys/types.h>
#include <time.h>
#define CACHE_MIN (1024)	/* smallest cache. Change it for your experiments */
#define CACHE_MAX (1024*1024*16) 	/* largest cache. Change it for your experiments */
#define SAMPLE 10 		/* to get a larger time sample */
#ifndef CLK_TCK
#define CLK_TCK 60 		/* number clock ticks per second */
#endif

int x[CACHE_MAX]; /* array going to stride through */
double get_seconds(){		/*routine to read time */
	struct tms rusage;
	times(&rusage);		/* UNIX utility: time in clock ticks */
	return (double)(rusage.tms_utime)/CLK_TCK;
}

void main(){
	int register i, index, stride, limit, temp;
	int steps, tsteps, csize;
	double sec0, sec; 	/*timing variables */
	for (csize = CACHE_MIN; csize <= CACHE_MAX; csize = csize*2){
		for (stride  = 1; stride <= csize/2; stride = stride*2){
			sec = 0; 	/*initialize timer*/
			limit = csize - stride + 1;		/*cache size this loop */
			steps = 0;
			do {
				sec0 = get_seconds();		/*start timer*/
				for (i = SAMPLE * stride; i != 0; i = i-1)	/*larger sample */
					for (index = 0; index < limit; index = index+stride)
						x[index] = x[index] + 1;		/*cache access*/

				steps = steps + 1;
				sec = sec + ( get_seconds() - sec0 );
			}while (sec < 1.0);

			/*Repeat empty loop to subtract loop overhead */

			tsteps = 0;
			do {
				sec0 = get_seconds();
				for ( i = SAMPLE*stride; i !=0; i = i-1)
					for (index = 0; index < limit; index = index + stride)
						temp = temp + index;
				tsteps = tsteps + 1;
				sec = sec - (get_seconds() - sec0);
			}while (tsteps < steps );

			printf("Size : %7ld Stride : %7ld read+write: %14.1f ns\n", csize*sizeof(int), stride*sizeof(int), (double)sec*1e9/(steps*SAMPLE*stride*((limit-1)/stride+1)));
		}
	}

}




