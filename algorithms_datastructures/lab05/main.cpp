#include <iostream>
#include <cstdlib>
#include <fstream>
#include <tuple>
#include <vector>
using namespace std;

typedef int keytype; // type of data stored in key fields in tree

struct Node {
  keytype key;
  int size;
  Node *left, *right;
  Node (keytype k) { key = k; size = 1; left = right = NULL; }
};

int get_size(Node *n) { return n == NULL ? 0 : n->size; }
void update_size(Node *n) { n->size = 1 + get_size(n->left) + get_size(n->right); }

Node *insert(Node *root, keytype k)
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

Node *find(Node *root, keytype k)
{
  if (root == NULL || k == root->key) return root;
  return find(k < root->key ? root->left : root->right, k);
}

Node *predfind(Node *root, keytype k)
{
  if (root == NULL || k == root->key) return root;
  if (k < root->key) return predfind(root->left, k);
  Node *right_result = predfind(root->right, k);
  return right_result == NULL ? root : right_result;
}

pair<Node *, Node *> split(Node *root, keytype k)
{
  pair <Node *, Node *> result = make_pair (root, root);
  if (root == NULL) return result;
  if (k < root->key) tie (result.first, root->left)   = split (root->left, k);
  else               tie (root->right, result.second) = split (root->right, k);
  update_size (root);
  return result;
}

Node *insert_keep_balanced(Node *root, keytype k)
{
  if (root == NULL) return new Node(k);
  if (rand() % (1 + root->size) == 0) {
    Node *new_root = new Node(k);
    tie (new_root->left, new_root->right) = split (root, k);
    update_size (new_root);
    return new_root;
  }
  if (k < root->key) root->left  = insert_keep_balanced(root->left,  k);
  else               root->right = insert_keep_balanced(root->right, k);
  update_size (root);
  return root;
}

Node *join(Node *L, Node *R)
{
  if (L == NULL) return R;
  if (R == NULL) return L;
  Node *root = (rand() % (L->size + R->size) < L->size) ? L : R;
  if (root == L) L->right = join(L->right, R);
  else           R->left  = join(L, R->left);
  update_size (root);
  return root;
}

Node *remove(Node *root, keytype k)
{
  if (root == NULL) return NULL;
  if (k == root->key) {
    Node *result = join(root->left, root->right);
    delete root;
    return result;
  }
  if (k < root->key) root->left  = remove (root->left, k);
  else               root->right = remove (root->right, k);
  update_size (root);
  return root;
}

int get_rank(Node *root, keytype x) {
  int rank = 0;
  if(root == NULL) return 0;

  if(root->key < x)  {
    rank = get_rank(root->right, x);
    if(root->left != NULL) rank += 1 + root->left->size;
    else if(root->left == NULL) rank += 1;
    return rank;
  }

  if(root->key >= x) return get_rank(root->left, x);
}

struct points {
  double x, y;
};

vector<pair <double, double>> set;

int main(void) {

// Find how many edges start but do not end inside an edge and
// if edges end but do not start inside a point.
  pair <double, double> N;
  int P = 0;
  int E = 0;
  int total;

  fstream woo;
  woo.open("cuts.txt");

  while(woo >> N.first >> N.second) {
    set.push_back(N);
    E++;
  }

  for(int i = 0; i < E; ++i) {
    for(int j = 0; i < E; ++i) {
      if(set[i].first < set[j].first && set[i].second > set[j].first) P++;
      else if(set[i].first < set[j].second && set[i].second > set[j].second) P++;
    }
  }

  cout << E << endl;
  cout << P << endl;

  total = P + E + 1;
  cout << "Number of intersections: " << total << endl;

  return 0;
}
