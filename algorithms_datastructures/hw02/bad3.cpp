// This is a sketch you can use for your "bad1" .. "bad3" programs...

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
  int key;
  int size;
  Node *left, *right;
  Node (int k) { key = k; size = 1; left = right = NULL; }
};

int get_size(Node *n) { return n == NULL ? 0 : n->size; }
void update_size(Node *n) { n->size = 1 + get_size(n->left) + get_size(n->right); }

Node *insert(Node *root, int k /*,int rank*/)
{
  if (root == NULL) return new Node(k);
  if (k < root->key) root->left  = insert(root->left,  k);
  else               root->right = insert(root->right, k);
  update_size (root);
  return root;
}

void print_inorder(Node *root)
{
  if (root == NULL) return;
  print_inorder(root->left);
  cout << root->key << "\n";
  print_inorder(root->right);
}

int main(int argc, char *argv[])
{
  Node* n;
  if (argc != 2) {
    cout << "Usage: bad1 <input size>\n";
    return 0;
  }

  int N = atoi(argv[1]);  // get first command-line argument
  if (N<1 || N>100000) {
    cout << "Invalid input size!\n";
    return 0;
  }

  // Generate and print bad input ``of size N for prog2
  // (currently just generates an input of N random numbers)
  cout << N << "\n";
  for(int i = 0; i < N; ++i) {
    insert(n, i);
  }
  print_inorder(n);

  return 0;
}
