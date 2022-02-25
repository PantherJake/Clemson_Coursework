#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*****************************
Jacob Vickio
CPSC 2310 Spring 21 
Username: jvickio
Instructor: Dr. Yvon Feaster
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Bday {
    int day;
    int month; 
    int year;
} bday_t;

typedef struct Node {
    bday_t B;
    char firstName[25];
    char lastName[25];
    char favSong[50];
    struct Node *next;
} node_t;

/*
Parameters: FILE* to read into linked list, node_t** is the head of the linked list used to store file info
Return: The head of the created linked list of file information is returned
Description: This function takes the head of the linked list, calls readNodeInfo to store each node and add 
it to the list and then the head is returned
*/
node_t* createList(FILE*, node_t**);

/*
Parameters: node_t** is the head of the linked list used to delete the information stored inside the list
Return: void
Descripton: This function takes the head of the linked list, loops through and frees each node back to
memory and sets the head equal to NULL.
*/
void deleteList(node_t**);

/* 
Parameters: node_t** node is the node with stored information for one student or TA that will be added, 
node_t** head is the head of the current linked list that will be added onto by node
Return: void
Description: This function takes the node the user wants to add and loops from the head to the end of the
linked list and sets the next node equal to node.
*/
void add(node_t **node, node_t **head);

/* 
Parameters: FILE* is the file passed to read from and store into the node that will be returned
Return: node_t* is returned which is the node that will be added to the list inside of the createList 
function
Description: This function takes the input file and scans information from it into the node's data 
so that it can be stored into the linked list
*/
node_t* readNodeInfo(FILE* input);

/*
Parameters: bday_t is passed to check for if the birthday is valid
Return: returns true if the birthday is valid and false if the birthday is not valid.
Description: This function takes a single student or TA's birthday and checks to make sure that it 
has a year between 1900 and 2000, months between 1 and 12, and days between 1 and the number of days 
in that month.
*/
bool checkDate(bday_t);

/* 
Parameters: int is passed in to check to see if the year passed is a leap year.
Return: returns true if the year passed is a leap year and false if the year passed is not a leap year
Description: This function takes a single year of a birthday from a student or TA and mods it by 4 to
check for the remainders value. If mod 4 of the year is equal to 0 then it is a leap year since leap
years are multiples of 4
*/
bool isLeapYear(int);

/*
Parameters: FILE* is passed in as the output file where names will be written, node_t* is the head of
the linked list storing the names that will be printed
Return: void
Description: This function takes the output file and head of the full linked list and prints the first
and last name, stored in the node, into the file 
*/
void PrintName(FILE*, node_t*);

/*
Parameters: FILE* is passed in as the output file where data will be written, node_t* is the head of
the linked list storing the information that will be printed
Return: void
Description: This function takes the output file and head of the full linked list and prints all data 
stored in the node, into the file 
*/
void PrintList(FILE*, node_t*);

/*
Parameters: FILE* is passed in as the output file where birthdays will be written, node_t* is the head of
the linked list storing the bdays that will be printed
Return: void
Description: This function takes the output file and head of the full linked list and prints the birth date,
month and year into the output file stored in a struct in the list
*/
void PrintBDay(FILE*, node_t*);

/*
Parameters: FILE* is passed in as the output file where fav songs will be written, node_t* is the head of
the linked list storing the songs that will be printed
Return: void
Description: This function takes the output file and head of the full linked list and prints the songs 
,stored in each node, into the file 
*/
void Song(FILE*, node_t*);

/*
Parameters: FILE* is passed in as the output file where the border will be printed.
Return: void
Description: This function prints a border of 80 asterisks to the output file
*/
void PrintBorder(FILE*);

/*
Parameters: void (*fp)(FILE*, node_t*) is the type of the print the user wants to perform, FILE* is 
the file pointer pointing at the output to be written, node_t* is the head of the linked list of information
Return: void
Description: This function pointer points to a specific print function and prints that functions method into 
the file
*/
void print(void (*fp)(FILE*, node_t*),FILE*,node_t*);

/*
Parameters: int is the number of arguments passed at command line
Return: void
Description: This function takes the number of command line args and makes sure that the number is only 3
for ./a.out data.txt output.txt
*/
void checkArgs(int);

/*
Parameters: FILE* is passed in to make sure it does not equal NULL
Return: void
Description: This function ensures that the file for input and output opened correctly so that it does not
point to NULL
*/
void checkFile(FILE*);

#endif
