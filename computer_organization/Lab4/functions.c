/** CPSC 2310 Lab 4

    Nibble routines

    Nibbles are 4-bit parts of a 32 bit unsigned integer variable.  
    Nibbles are numbered 0-7 from left to right.

**/

/******************
* Jacob Vickio    *
* CPSC 2130 Lab 4 *
* jvickio         *
* 2               *
******************/

#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

/*
Return: 
unsigned int return is the nibble of the value at the position
Parameters:
val is the value that the binary number will be based on. Where 
position is the place of the nibble that will be being extracted.
Description:
This function takes the input val variable and extracts the nibble 
at the location 'position' in the val integer.
*/
unsigned int nget(unsigned int val, int position) {
   /** STUBBED **/
   val = val >> (28 - (position * 4));
   val = val & 0xF;
   
   return(val);
}

/*
Return:
unsigned int return is the value of the new nibble after it has
been set to nVal. 
Parameters:
int val is the value of the passed in number that will be altered.
int nVal is the value of the hexadecimal number that will be taking
place of the previous val nibble.
int position is the index of the nibble that will be getting set to
nVal.
Description:
This function takes the input val variable, masks it, and proceeds to
set the nibble at index position equal to nVal.
*/
unsigned int nset(unsigned int val, unsigned int nVal, int position) {
   /** STUBBED **/
   unsigned int mask = ~(0xF << (28 - (position * 4)));
   unsigned int s = (nVal << (28 - (position * 4)));

   val = val & mask;
   val = val | s;

   return(val);
}

/*
Return:
unsigned int return is val after it has been shifted 4 bits.
Parameters:
unsigined int val is the value whose nibbles will shift 4 bits,
making sure to have the nibble leaving on the left return to the right.
Description:
This function moves each nibble 1 index to the left for the unsigned
integer val.
*/
unsigned int nlrotate(unsigned int val) {
   /** STUBBED **/
   unsigned int s = val >> 28;
   s = s & 0xF;

   val = val << 4;
   val = val | s;

   return(val);
}
