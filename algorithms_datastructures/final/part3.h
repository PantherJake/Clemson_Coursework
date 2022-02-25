#ifndef PART3_H /* Prevent multiple inclusion... */
#define PART3_H

#include <string>
using namespace std;

struct Node {
  int key;
  Node *next;
  Node(int k, Node *n) { key = k; next = n;}
  Node() { key = 0; next = NULL; }
};

class Stringset {

 public:

   Node **table;  // array of pointers to linked lists
   int size;      // size of table, as currently allocated
   int num_elems; // number of elements stored in the table

  Stringset();
  ~Stringset();
  bool find(int key);
  void insert(int key);
  void remove(int key);
  void print(void);
};

#endif
