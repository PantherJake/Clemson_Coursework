#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
  int key;
  Node *left, *right;
  Node (int k) { key = k; left = right = NULL; }
};

Node *insert(Node *root, int x)
{
  if (root == NULL) return new Node(x);
  if (x < root->key) root->left = insert(root->left, x);
  else               root->right = insert(root->right, x);
  return root;
}

// Global variables containing the pre-order traversal of our tree
// and its length.  So A[0] ... A[N-1] is the pre-order traversal.
int *A, N;

void preorder(Node *root)
{
  if (root == NULL) return;
  A[N++] = root->key;
  //cout << root->key;
  preorder(root->left);
  preorder(root->right);
}

// Return the rth largest element, based on the global pre-order array A
// and its length N.  You can write and call helper functions if you need to.
int select(int r)
{
  sort(A);
  return A[A[N] - r];
}

int main(void)
{
  int B = 10;

  // Build random B-node tree and compute its pre-order traversal
  Node *root = NULL;
  for (int i=0; i<B; i++)
    root = insert(root, rand());
  A = new int[B];
  preorder(root);  // Now N = B

  // // New test out select...
  // cout << "\n";
  // for (int r=0; r<N; r++)
  //   cout << "select(" << r << ") gives " << select(r) << "\n";
  //
  // // These results should match what we get when we print out the
  // // sorted ordering of A...
  // sort(A,A+N); cout << "\n";
  // for (int r=0; r<N; r++)
  //   cout << "select(" << r << ") should have given " << A[r] << "\n";
  // cout << "\n";

  return 0;
}
