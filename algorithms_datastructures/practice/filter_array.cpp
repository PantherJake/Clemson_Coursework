#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node (int v, Node *n) { val = v; next = n; }
  Node () { val = 0; next = NULL; }
};

// Return a linked list containing the even elements of array[0..N-1]
// The array is not to be modified
Node *filter_evens(int *array, int N)
{
  Node* evens = NULL;

  for(int i = 0; i < N; ++i) {
    if((array[i] % 2) == 0) {
      Node* n = new Node(array[i], evens);
      evens = n;
      // evens = evens->next;
      // evens = new Node(array[i], NULL);
      // cout << evens->val;
    }
  }

return evens;
}

int main(void)
{
  int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Node *head = filter_evens(A, 10);

  //Node* temp = head;
  while(head != NULL) {
    cout << head->val << endl;
    head = head->next;
  }

  return 0;
}
