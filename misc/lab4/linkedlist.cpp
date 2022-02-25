#include <stdlib.h>
#include <iostream>
#include "linkedlist.h"

using namespace std;

NodePtr head = NULL;
NodePtr tail = NULL;

bool isEmpty(){
   return (head == NULL);
}

NodePtr makeNewNode(int number) {
   NodePtr newNode = (NodePtr) malloc(sizeof(Node));
   if(newNode != NULL){
      newNode->data = number;
      newNode->next = NULL;
   }
   return newNode;
}

void insertAtFront(const NodePtr newPtr){
    if (isEmpty()){
     head = newPtr;
     tail = newPtr;
   }
   else{ // not empty
     newPtr->next = head;
     head = newPtr;
   }
}

void insertAtEnd(const NodePtr newPtr){
NodePtr temp = head;
if (isEmpty()) {
tail = newPtr;
}
while (temp->next != NULL) {
temp = temp->next;
}
tail->next = newPtr;
newPtr->prev = tail;
tail = newPtr;
}

void insertStrategic(const NodePtr newPtr){
if (isEmpty()) {
head = newPtr;
tail = newPtr;
}

NodePtr temp = head;
NodePtr previous = temp;
while (temp->next != NULL && newPtr->data < temp->data) {
previous = temp;
temp = temp->next;
}

previous->next = newPtr;
}	

void deleteFromFront(){
if (isEmpty()) {
cout << "List is empty. :(\n";
exit(1);
}
/*NodePtr temp = head;
head = temp->next;
temp = NULL;*/
head = head->next;
free(head->prev);
}

void deleteFromEnd(){
if (isEmpty()) {
cout << "List is empty. :(\n";
return;
}
/*NodePtr temp = head;
while (temp->next != tail) {
temp = temp->next;
}   
tail = temp;
temp->next = NULL; */
tail = tail->prev;
free(tail->next);
tail->next = NULL;
}


void printList(){
   if (isEmpty()){
     cout << "List is empty. :(\n" << endl;
     exit(1);
   }
   else {
     NodePtr temp = head;
     while (temp != NULL){
       cout << " The data is: " << temp->data << endl;
       temp = temp->next;
     }
   }
}

