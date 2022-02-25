#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> state;
map<int, int> M;
bool beenthere[1001][1001];
int A, B, X;

void read_input() {
  cout << "Enter A: ";
  cin >> A;
  cout << "\n";

  cout << "Enter B: ";
  cin >> B;
  cout << "\n";

  cout << "Enter X: ";
  cin >> X;
  cout << "\n";

  return;
}

state fill_A(state prev) {
  cout << "Fill jug 1\t" << "[a=" << prev.first << ", " << "b=" << prev.second << "]" << endl;
  return make_pair(A, prev.second);
}
state fill_B(state prev) {
  cout << "Fill jug 2\t" << "[a=" << prev.first << ", " << "b=" << prev.second << "]" << endl;
  return make_pair(prev.first, B);
}
state pour_A(state prev) {
  cout << "Empty jug 1\t" << "[a=" << prev.first << ", " << "b=" << prev.second << "]" << endl;
  return make_pair(0, prev.second);
}
state pour_B(state prev) {
  cout << "Empty jug 2\t" << "[a=" << prev.first << ", " << "b=" << prev.second << "]" << endl;
  return make_pair(prev.first, 0);
}
state pour_AB(state prev) {
  int difference = B - prev.second;

  cout << "Pour 1->2\t" << "[a=" << prev.first << ", " << "b=" << prev.second << "]" << endl;
  if(prev.first + prev.second <= B) return make_pair(0, prev.first + prev.second);
  else return make_pair(prev.first - difference, B);
}
state pour_BA(state prev) {
  int difference = A - prev.first;

  cout << "Pour 2->1\t" << "[a=" << prev.first << ", " << "b=" << prev.second << "]" << endl;
  if(prev.first + prev.second <= A) return make_pair(prev.first + prev.second, 0);
  else return make_pair(A, prev.second - difference);
}

bool visit(state root) {
  if(beenthere[root.first][root.second] == true) return false;

  if(X == A + B) return true;
  else {
    beenthere[root.first][root.second] = true;
    
  }
}

int main(void) {

  // Read input from user
  read_input();

  // Tests for impossible condition
  if(X > A + B) {
    cout << "Impossible!" << endl;
    return -1;
  }

  // Insert values onto map
  M.insert(make_pair(A, B);
  //cout << M.size() << endl;

  // Recursion time!
  if(visit(M.at(0)) return 0;
  else {
    cout << "Impossible!" << endl;
    return -1;
  }
}
