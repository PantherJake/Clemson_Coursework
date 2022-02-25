#include <iostream>
using namespace std;

struct Node {
  int val;
  int size;
  Node *left, *right;
  Node (int v, Node *l, Node *r) { val = v; left = l; right = r; size = 1; }
  Node (int v) { val = v; left = right = NULL; size = 1; }
  Node () { val = 0; left = right = NULL; size = 1; }
};

void fix_size(Node *T)
{
  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;
}

// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{
  if (T == NULL) return new Node(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  return T;
}

// prints out the inorder traversal of T (i.e., the contents of T in sorted order)
void print_inorder(Node *T)
{
  if (T == NULL) return;
  print_inorder(T->left);
  cout << T->key << "\n";
  print_inorder(T->right);
}

// Return a balanced BST containing the even elements of the input BST
// (which you can assume is balanced).  Odd elements should be de-allocated,
// so only one copy of each even element should reside in memory at the
// end of this function's execution
Node *filter_evens(Node *root)
{
  if(root == NULL) return NULL;
  filter_evens(root->left);
  if((root->val % 2) != 0) remove(root);
  filter_evens(root->right);
  // else if((root->left->val % 2) != 0) filter_evens(root->left);
  // else if((root->right->val % 2) != 0) filter_evens(root->right);
  return root;
}

// return a pointer to the node with key k in tree T, or NULL if it doesn't exist
Node *find(Node *T, int k)
{
  if (T == NULL) return NULL;
  if (k == T->key) return T;
  if (k < T->key) return find(T->left, k);
  else return find(T->right, k);
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r)
{
  assert(T!=NULL && r>=0 && r<T->size);

  int rank_of_root = T->left ? T->left->size : 0;
  if (r == rank_of_root) return T;
  if (r < rank_of_root) return select(T->left, r);
  else return select(T->right, r - rank_of_root - 1);
}

// Join trees L and R (with L containing keys all <= the keys in R)
// Return a pointer to the joined tree.
Node *join(Node *L, Node *R)
{
  // choose either the root of L or the root of R to be the root of the joined tree
  // (where we choose with probabilities proportional to the sizes of L and R)
  if (L == NULL) return R;
  if (R == NULL) return L;
  int random = rand() % (L->size + R->size);
  if (random < L->size) {
    // L stays root
    L->right = join(L->right, R);
    fix_size(L);
    return L;
  } else {
    // R stays root
    R->left = join(L, R->left);
    fix_size(R);
    return R;
  }
}

// remove key k from T, returning a pointer to the resulting tree.
// it is required that k be present in T
Node *remove(Node *T, int k)
{
  assert(T != NULL);
  if (k == T->key) {
    Node *to_delete = T;
    T = join(T->left, T->right);
    delete to_delete;
    return T;
  }
  if (k < T->key) T->left = remove(T->left, k);
  else T->right = remove(T->right, k);
  fix_size(T);
  return T;
}

// Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k)
void split(Node *T, int k, Node **L, Node **R)
{
  if (T == NULL) {
    *L = NULL;
    *R = NULL;
    return;
  }
  if (k < T->key) {
    // recursively split left subtree
    split(T->left, k, L, &T->left);
    *R = T;
  } else {
    split(T->right, k, &T->right, R);
    *L = T;
  }
  fix_size(T);
}

// insert key k into the tree T, returning a pointer to the resulting tree
Node *insert_random(Node *T, int k)
{
  // If k is the Nth node inserted into T, then:
  // with probability 1/N, insert k at the root of T
  // otherwise, insert_random k recursively left or right of the root of T
  if (T == NULL) return new Node(k);
  if (rand() % (T->size + 1) == 0) {
    // insert at root
    Node *new_root = new Node(k);
    split(T, k, &new_root->left, &new_root->right);
    fix_size(new_root);
    return new_root;
  }
  if (k < T->key) T->left = insert_random(T->left, k);
  else T->right = insert_random(T->right, k);
  fix_size(T);
  return T;
}

int main(void)
{
  return 0;
}
