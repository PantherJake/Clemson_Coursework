#include <stdio.h>
#include <stdlib.h>
    
int main() {
    int num;

    FILE *fptr;

    // make sure file exists, give message and exit otherwise
    if ((fptr = fopen("input.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }

    // while we still have items to read
    while( fscanf(fptr,"%d", &num) != EOF){
        printf("n is:  %d\n", num);

    }
    
    fclose(fptr);  // close the file  
       
return 0;
}
