#ifndef INTSET_H /* Prevent multiple inclusion... */
#define INTSET_H


class Intset {

 private: 
  struct node {
	int data;
	node* next;
  };
  node* head = NULL;

 public:
  Intset();
  ~Intset();
  bool find(int key);
  void insert(int key);
  void remove(int key);
  void print(void);
};

#endif
