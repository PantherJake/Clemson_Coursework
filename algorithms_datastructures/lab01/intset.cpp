#include <iostream>
#include <assert.h>
#include "intset.h"

using namespace std;

//node* head = NULL;

Intset::Intset() {

for (int i = 0; i < 10; ++i) {
node* temp = new node;
temp->data = i;
temp->next = head;
head = temp;
}

}

Intset::~Intset() {
  for (int i = 0; i < 10; ++i) {
  node* q = head;
  head = q->next;
  delete q;
}
}

/* Return true if key is in the set */
bool Intset::find(int key) {
node* finder = head;

if (finder == NULL) {return false;}
while (finder != NULL) {
if (finder->data == key) {return true;}
finder = finder->next;
}
return false;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Intset::insert(int key) {

assert (!find(key));

node* p = new node;
p = head;
//node* q = p->next;
while (key < p->data) {
p = p->next;
//q = q->next;
}
p->data = key;
}

/* Removes a key.  It is an error if key isn't in the set */
void Intset::remove(int key)
{
  assert (find(key));
	
  node* p = head;
  node* q = p->next;

  if (key == p->data) {
  p = q->next;
  delete head;
  delete q;
  }
  else {
  while (key != p->data) {
  q = q->next;
  p = p->next;
  }
  
  p = q->next;
  delete q;
}
}

void Intset::print(void) {
node* ptr = head;

while(ptr != NULL) {
cout << ptr->data << endl;
ptr = ptr->next;
}
}
