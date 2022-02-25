#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;

/* For this I would push all the values back into a vector, sort the vector and
run through the vector and for each time the sort would place a lot of same values
together I would add that number to an array which will be printed in reverse order.
This algorithm would run in O(n^2) time. Another way I could have implemented it
was to insert all the elements into a hash table using chaining and have a counter
for the length of each linked list at each node of the hash table and print out using that
counter. */
const int N = 10;
int count;
int a[N] = {7, 3, 3, 1, 3, 5, 3, 2, 5, 2};
vector<int> counted;
int f[N];

int main() {
  int temp = 0;
  int max = 0;
  int fcount = 0;

  for(int i = 0; i < N; ++i) {
    counted.push_back(a[i]);
  }
  sort(counted.begin(), counted.end());

  for(int i = 0; i < counted.size(); ++i) {
    while(counted[i] == counted[i+1]) {
      temp++;
      i++;
    }
    if(temp > max) {
      f[fcount] = counted[i];
      fcount++;
    }
  }

  for(int i = 0; i < fcount; ++i) {
    cout << f[i] << ", ";
  }

  cout << endl;
  return 0;
}
