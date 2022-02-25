#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************
Jacob Vickio
CPSC 2310 Spring 21 
Username: jvickio
Instructor: Dr. Yvon Feaster
*****************************/

int main(int argc, char *argv[]) {
    void (*print[])(FILE*, node_t*) = {PrintList, PrintName, PrintBDay, Song};
    int choice;
    // Head of linked list that will store all the data
    node_t* head = (node_t*)malloc(sizeof(node_t));
    
    // Checks command line args for accuracy
    checkArgs(argc);
    FILE* input = fopen(argv[1], "r");
    // Checks that file opened correctly
    checkFile(input);
    
    // The list is created and loaded with necessary info from data.txt
    head = createList(input, &head);
    fclose(input);
    
    FILE* output;
    
    // Menu
    printf("Hello user, what would you like to print?\n");
    
    while(1) {
        printf("1. Print the entire list information\n");
        printf("2. Print the names on the list\n");
        printf("3. Print the birthdays on the list\n");
        printf("4. Print the favorite songs on the list\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        
        // If user selects to quit or out of bounds we don't want to overwrite file, otherwise we do
        if(choice < 5 && choice > 0) {
            output = fopen(argv[2], "w+");
            checkFile(output);
        }
        	
        // Prints different items to output.txt depending on user choice
        switch(choice) {
            case 1: 
            (*print[0])(output, head);
            fclose(output);
            break;
            case 2:
            (*print[1])(output, head);
            fclose(output);
            break;
            case 3:
            (*print[2])(output, head);
            fclose(output);
            break;
            case 4:
            (*print[3])(output, head);
            fclose(output);
            break;
            case 5:
            deleteList(&head);
            return 0;
            break;
            default:
            printf("Please enter valid input :)\n");
            break;
        }
        
    }
    
    return 0;
}
