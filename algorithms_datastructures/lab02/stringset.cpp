#include <iostream>
#include <string.h>
#include <assert.h>
#include "stringset.h"

using namespace std;

/* Return a hash for the string s in the range 0..table_size-1 */
int myhash(string s, int table_size) {

unsigned int i, h = 0;
for (i=0; i<s.length(); i++)
h = (h * 2917 + (unsigned int)s[i]) % table_size;
return h;

}

Stringset::Stringset() {
size = 4; // initial size of table    
table = new Node *[size]; // allocate table, initialize head ptrs all to NULL

for (int i=0; i<size; i++) 
table[i] = NULL;
num_elems = 0; 

}

Stringset::~Stringset() {
for (int i=0; i<size; i++) {
	while (table[i] != NULL) {
	Node *temp = table[i];
	table[i] = table[i]->next;
	delete temp;
	}
}
delete[] table;
}

/* Return true if key is in the set */
bool Stringset::find(string key) {
int h = myhash(key, size);
Node *n = table[h];
while (n != NULL) {
	if (n->key == key) return true;
    	n = n->next;
}
return false;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Stringset::insert(string key) {
assert (!find(key));
num_elems++;

if (num_elems == size) {
size = size*2;
Node** bigTable = new Node*[size];

for (int i = 0; i < size/2; ++i) {

	for (Node* c = table[i]; c != NULL; c = c->next) {
	int h = myhash(c->key, size);
		if (bigTable[h] != NULL) {
		Node* newNode = bigTable[h];
		Node* prev;
			while (newNode != NULL) {
			prev = newNode;
			newNode = newNode->next;
			}
		Node* temp = new Node(c->key, NULL);
		prev->next = temp;
		}
		else {
		Node* temp = new Node(c->key, NULL); 
		bigTable[h] = temp;
		}
	}
}

delete table;
table = new Node*[size];
table = bigTable;
}
/*TBD Add new element*/
int p = myhash(key, size);
if (table[p] != NULL) {
Node* newNode = table[p];
Node* prev;

	while(newNode != NULL) {
	prev = newNode;
	newNode = newNode->next;
	}

Node* temp = new Node(key, NULL);
prev->next = temp;
}
else {
Node* temp = new Node(key, NULL);
table[p] = temp;
}
}

/* Removes a key.  It is an error if key isn't in the set */
void Stringset::remove(string key) {
assert (find(key));
num_elems--;
int h = myhash(key, size);


// Tests to see if the string inside the head is the string wanted to remove
if (table[h]->key == key) {

	if (table[h]->next == NULL) {
	table[h] = NULL;
	}
	else {
	Node* current = table[h]->next;
	table[h] = NULL;
	table[h] = current;
	}

}
// Scans through linked list until desired removal is appropriate
else {
Node* temp = table[h];
Node* prev;

	while (temp->key != key) {
	prev = temp;
	temp = temp->next;
	}

	if (temp->next == NULL) {
	temp = NULL;
	}
	else {
	prev->next = temp->next;
	delete temp;
	}
}

/*Node* prev = table[h];
Node* current = table[h]->next;

while(current != NULL) {
	if (current->key == key) {
	break;
	}
	else {
	prev = current;
	current = current->next;
	}
}

prev->next = current->next;
delete current;*/

}

void Stringset::print(void) {

for(int i = 0; i < size; ++i) {
	for (Node* n = table[i]; n != NULL; n = n->next) {
		cout << n->key << "\n";
	}
}
}
