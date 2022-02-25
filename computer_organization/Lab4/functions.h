/** Include file for nibble routines */

/******************
* Jacob Vickio    *
* CPSC 2130 Lab 4 *
* jvickio         *
* 2               *
******************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

unsigned int nget(unsigned int val, int position);
unsigned int nset(unsigned int val, unsigned int nVal, int position);
unsigned int nlrotate(unsigned int val);

#endif
