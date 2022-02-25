#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/**************************
 *Jacob Vickio
 *CPSC2310 Spring 2021            
 *UserName: jvickio                               
 *Instructor:  Dr. Yvon Feaster  
*************************/

int printReturn(int a, int b, int action) {
    return action == 1 ? a == b 
            : action == 2 ? a < b 
            : action == 3 ? a > b
            : -50000;
}

