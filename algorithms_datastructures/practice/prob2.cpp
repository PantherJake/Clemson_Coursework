#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>
using namespace std;

// class BST {
// private:
//
//   struct Node {
//     int data;
//     Node* left;
//     Node* right;
//   };
//
// public:
//   void printLevel(Node* root, int level);
//   void printLevelOrder(Node* root);
//   int height(Node* p);
// };

struct Node {
    int data;
    Node* left;
    Node* right;
};

void printLevel(Node* root, int level);
void printLevelOrder(Node* root);
int height(Node* p);
Node* newNode(int data);

void printLevelOrder(Node* root) {
  int h = height(root);
  for(int i = 0; i <= h; ++i) {
    printLevel(root, i);
  }
}

void printLevel(Node* root, int level) {
  if(root == NULL) return;
  if(level == 1) cout << root->data << endl;

  else if(level > 1) {
    printLevel(root->left, level-1);
    printLevel(root->right, level-1);
  }
}

int height(Node* p) {
  if(p == NULL) return 0;
  else {
    int left = height(p->left);
    int right = height(p->right);

    if(left > right) return(left + 1);
    else return(right + 1);
  }
}

Node* newNode(int data) {
  Node* p = new Node;
  p->data = data;
  p->left = NULL;
  p->right = NULL;
  return p;
}

int main() {
  Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->right->right = newNode(1);
  printLevelOrder(root);
}
