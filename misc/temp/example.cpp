#include <iostream>
#include <stdio.h>

int main() {

int nums[] = {4, 7, 11, 13, 15, 17, 19, 21, 71};
int *numptr = nums;
for (int i = 0; i < 3; i++) {  
          numptr++;
}

printf("%d", *numptr);
return 0;
}
