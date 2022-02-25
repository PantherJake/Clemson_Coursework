#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
  int pi;
  int key;
  Node *next;
  Node(int k, Node *n) { key = k; next = n; }
  Node() { key = 0; next = NULL; }
};

int N = 1000000;
int pi = 0;
Node** table;
int sum = 0;

// Guaranteed to output a hash value in the range 0 ... 999,999
unsigned int myhash(int x)
{
  return ((unsigned)x * 123147 + 293871) % 100 + 900000;
}

void insert(int key) {
int h = myhash(key);

if(table[h] != NULL) {
Node* newNode = table[h];
Node* prev;
pi++;

while(newNode != NULL) {
  prev = newNode;
  newNode = newNode->next;
}

Node* temp = new Node;
temp->key = key;
temp->next = NULL;
prev->next = temp;
}
else {
Node* temp = new Node;
temp->key = key;
temp->next = NULL;
table[h] = temp;
}
}

int main() {
  table = new Node *[N];
  int average;

  for(int i = 0; i < N; ++i) {
    insert(1 + (rand() % N));
    //cout << pi << endl;
    sum += pi;
    pi = 0;
  }

average = sum / N;
cout << "Average: " << average << endl;
//cout << "Maximum: " << max << endl;
}
