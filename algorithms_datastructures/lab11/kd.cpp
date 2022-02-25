#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include "assert.h"
using namespace std;

const int N = 3961, D = 11; // number of points and number of dimensions

struct Point {
  int quality;    // quality of wine, from 1 (worst) .. 9 (best)
  double data[D]; // D attributes of this wine
};
vector<Point> all_points;

struct Node {
  int p; // index, within the all_points vector, of the point represented by this node
  Node *left;
  Node *right;
  Node (int _p) { p = _p; left = right = NULL; }
};

// Insert all_points[p] into kd-tree
Node *insert(Node *root, int p, int dim)
{
  if (root == NULL) return new Node(p);
  if (all_points[p].data[dim] < all_points[root->p].data[dim])
    root->left  = insert(root->left,  p, (dim+1) % D);
  else
    root->right = insert(root->right, p, (dim+1) % D);
  return root;
}

// Distance between all_points[p] and all_points[q]
double get_dist(int p, int q)
{
  double t = 0;
  for (int i=0; i<D; i++) t += pow(all_points[p].data[i] - all_points[q].data[i], 2);
  return sqrt(t);
}

// Determine closest point in the kd-tree to all_points[p]
// Return the index of this point in the "nearest" variable
// Assume "nearest" is initially set to -1
void kd_nearest(Node *root, int p, int dim, int &nearest)
{
  if(root == NULL) return;
  else {
    if(nearest == -1 && p != root->p) nearest = root->p;
    if(p != root->p) {
      if(get_dist(p, root->p) < get_dist(p, nearest)) nearest = root->p;
    }

    kd_nearest(root->right, p, (dim+1) % D, nearest);
    if(all_points[p].data[dim] - all_points[root->p].data[dim] < get_dist(p, nearest))
      kd_nearest(root->left, p, (dim+1) % D, nearest);
    }

    return;
}

int confusion[10][10];

void print_confusion_matrix(void)
{
  printf ("   "); for (int j=1; j<=9; j++) printf (" %4d", j); printf ("\n");
  printf ("   "); for (int j=1; j<=9; j++) printf (" ----");   printf ("\n");
  for (int i=1; i<=9; i++) {
    printf ("%d |", i);
    for (int j=1; j<=9; j++) printf (" %4d", confusion[i][j]);
    printf ("\n");
  }
}

int main(void)
{
  ifstream wine ("wine.txt");
  Point p;
  for (int i=0; i<N; i++) {
    wine >> p.quality;
    for (int j=0; j<D; j++) wine >> p.data[j];
    all_points.push_back(p);
  }

  // Compute "confusion" matrix, the slow way...
  for (int i=0; i<N; i++) {
    int nearest = -1;
    for (int j=0; j<N; j++)
      if (i!=j && (nearest==-1 || get_dist(i,j) < get_dist(i,nearest))) nearest = j;
    confusion[all_points[i].quality][all_points[nearest].quality]++;
  }
  printf ("Confusion matrix (computed the boring slow way):\n");
  print_confusion_matrix();

  // Now do it the fast way, using the kd-tree
  for (int i=1; i<=9; i++)
    for (int j=1; j<=9; j++)
      confusion[i][j] = 0; // clear matrix
  Node *root = NULL;
  for (int i=0; i<N; i++) root = insert(root, i, 0); // Insert points into a kd tree
  for (int i=0; i<N; i++) {
    int nearest = -1;
    kd_nearest(root, i, 0, nearest);
    assert (nearest != -1); // If this fires, your code is returning -1 for nearest!!!
    confusion[all_points[i].quality][all_points[nearest].quality]++;
  }
  printf ("\nConfusion matrix (computed the cool way with a kd-tree):\n");
  print_confusion_matrix();
}
