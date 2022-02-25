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

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
enum Month { January = 1, February, March, April, May, June, July, August, September, October, November, December };

const char *enum_str[] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void checkArgs(int a) {
    // ./a.out data.txt output.txt
    if(a > 3 || a < 3) {
        fprintf(stderr, "%s", "Error: Incorrect number of command line arguments\n");
        exit(0);
    }
}

void checkFile(FILE* input) {
    if(input == NULL) {
        fprintf(stderr, "%s", "Error: File did not open correctly\n");
        exit(0);
    }
}

node_t* createList(FILE* input, node_t** h) {
    // node that will be added to list
    node_t* node;
    
    // Loop until nothing left to scan in file, assigning data to node with readNodeInfo and then adding it to linked list
    while(!feof(input)) {
        node = readNodeInfo(input);
        if(node == NULL) continue;
        add(&node, h);
    }   
    
    // Returns pointer to head of list
    return *h;
}

node_t* readNodeInfo(FILE* input) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    bday_t B;
    char comma;
    
    // Scan through data.txt file to set up the returned nodes data
    fscanf(input, "%[^,]%c%[^,]%c%d%c%d%c%d%c%[^\n]\n", node->lastName, &comma, node->firstName, &comma, &B.month, &comma, &B.day, &comma, &B.year, &comma, node->favSong);
    
    // Returns NULL if Bday is out of bounds because we dont want to add that to list
    if(!checkDate(B)) return NULL;
    node->B = B;
    
    return node;
}

void add(node_t **node, node_t **h) {
    if((*h) == NULL) (*h) = *node;
    
    node_t* temp = *h;
    while(temp->next != NULL) temp = temp->next;
    temp->next = *node;
}

void deleteList(node_t** h) {
    node_t* curr = *h;
    node_t* next = NULL;
    
    while(curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    
    *h = NULL;
}

void PrintList(FILE* out, node_t* h) {
    PrintBorder(out);
    
    if(h == NULL) {
        fprintf(stderr, "%s", "Error: List is empty\n");
        exit(0);
    }
    
    // Loop through each node in the list and print all the information to output.txt
    node_t* temp = h;
    temp = temp->next;
    while(temp != NULL) {
        enum Month m = temp->B.month;
        fprintf(out, "%s, %s, %s %d, %d, %s\n", temp->lastName, temp->firstName, enum_str[m], temp->B.day, temp->B.year, temp->favSong);
        temp = temp->next;
    }
    
    PrintBorder(out);
}

void PrintName(FILE* out, node_t* h) {
    PrintBorder(out);
    
    if(h == NULL) {
        fprintf(stderr, "%s", "Error: List is empty\n");
        exit(0);
    }
    
    // Loop through each node in the list and print the names assigned to each node to output.txt
    node_t* temp = h;
    temp = temp->next;
    while(temp != NULL) {
        fprintf(out, "%s, %s\n", temp->lastName, temp->firstName);
        temp = temp->next;
    }
    
    PrintBorder(out);
}

void PrintBDay(FILE* out, node_t* h) {
    PrintBorder(out);
    
    if(h == NULL) {
        fprintf(stderr, "%s", "Error: List is empty\n");
        exit(0);
    }
    
    // Loop through each node in the list and print the birthdays assigned to each node to output.txt
    node_t* temp = h;
    temp = temp->next;
    while(temp != NULL) {
        enum Month m = temp->B.month;
        fprintf(out, "%s %s's date of birth is %s %d, %d\n", temp->firstName, temp->lastName, enum_str[m], temp->B.day, temp->B.year);
        temp = temp->next;
    }
    
    PrintBorder(out);
}

void Song(FILE* out, node_t* h) {
    PrintBorder(out);
    
    if(h == NULL) {
        fprintf(stderr, "%s", "Error: List is empty\n");
        exit(0);
    }
    
    // Loop through each node in the list and print the favorite songs assigned to each node to output.txt
    node_t* temp = h;
    temp = temp->next;
    while(temp != NULL) {
        fprintf(out, "%s %s's favorite song is %s\n", temp->firstName, temp->lastName, temp->favSong);
        temp = temp->next;
    }
    
    PrintBorder(out);
}

void PrintBorder(FILE* out) {
    fprintf(out, "%s", "******************************************************************************\n");
}

bool checkDate(bday_t B) {
    // Checks for year accuracy
    if(B.year > 2020 || B.year < 1900) {
        fprintf(stderr, "%s", "Error: Birth year out of bounds\n");
        return false;
    }
    
    // Checks for month accuracy
    if(B.month > 12 || B.month < 1) {
        fprintf(stderr, "%s", "Error: Birth month out of bounds\n");
        return false;
    }
    
    // Checks for day accuracy. If month is February and is a leap year, then return true
    if(B.day > days[B.month] || B.day < 1) {
        if(B.month == 2) {
            if((isLeapYear(B.year)) && (B.day == 29)) return true;
        }
        fprintf(stderr, "%s", "Error: Birth date out of bounds\n");
        return false;
    }
    
    return true;
}

bool isLeapYear(int year) {
    // Leap years happen to be multiples of four, so if the remainder of 4 and year is 0, then it's a leap year
    if((year % 4) == 0) return true;
    else return false;
}

