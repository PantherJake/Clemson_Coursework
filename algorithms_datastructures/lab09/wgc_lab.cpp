#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> DaMap;
int A, B, X;

DaMap prevstate[1001][1001];
bool beenthere[1001][1001];
DaMap nextstate[1001][1001];
vector<string> p;

void read_input() {
  cout << "Enter A: ";
  cin >> A;

  cout << "Enter B: ";
  cin >> B;

  cout << "Enter X: ";
  cin >> X;

  return;
}

void fill_A(DaMap &I) { I.first = A; }
void fill_B(DaMap &I) { I.second = B; }
void pour_A(DaMap &I) { I.first = 0; }
void pour_B(DaMap &I) { I.second = 0; }
void pour_BA(DaMap &I) {
  I.first = I.first + I.second;
  I.second = 0;

  if(I.first > A) {
    I.second = I.second + (I.first - B);
    I.first = I.first - (I.first - B);
  }
}
void pour_AB(DaMap &I) {
  I.second = I.second + I.first;
  I.first = 0;

  if(I.second > B) {
    I.first = I.first + (I.second - B);
    I.second = I.second - (I.second - B);
  }
}

bool visit(DaMap &I) {
  DaMap M = I;
  bool solution;

  // Base
  if(I.first + I.second == X) solution = true;

  if(beenthere[I.first][I.second] == false) {
    beenthere[I.first][I.second] = true;

// fill jug 1
    if(solution == false) {
      p.push_back("Fill jug 1");
      fill_A(M);
      nextstate[I.first][I.second] = M;
      prevstate[M.first][M.second] = I;
      solution = visit(M);
    }

// fill jug 2
    if(solution == false) {
      M = I;
      p.push_back("Fill jug 2");
      fill_B(M);
      nextstate[I.first][I.second] = M;
      prevstate[M.first][M.second] = I;
      solution = visit(M);
    }

// empty jug 1
    if(solution == false) {
      M = I;
      p.push_back("Empty jug 1");
      pour_A(M);
      nextstate[I.first][I.second] = M;
      prevstate[M.first][M.second] = I;
      solution = visit(M);
    }

// empty jug 2
    if(solution == false) {
      M = I;
      p.push_back("Empty jug 2");
      pour_B(M);
      nextstate[I.first][I.second] = M;
      prevstate[M.first][M.second] = I;
      solution = visit(M);
    }

// move from jug 2 to 1
    if(solution == false) {
      M = I;
      p.push_back("2->1\t");
      pour_BA(M);
      nextstate[I.first][I.second] = M;
      prevstate[M.first][M.second] = I;
      solution = visit(M);
    }

// move from jug 1 to 2
    if(solution == false) {
      M = I;
      p.push_back("1->2\t");
      pour_AB(M);
      nextstate[I.first][I.second] = M;
      prevstate[M.first][M.second] = I;
      solution = visit(M);
    }
  }

  if(solution == false) p.pop_back();
  return solution;
}

int main(void) {
  read_input();
  DaMap I;
  DaMap J;

  bool finale = visit(I);

  if(finale == false) cout << "Impossible!" << endl;
  else {
    for(unsigned int i = 0; i < p.size(); ++i) {
      cout << p[i] << "\t[a=" << nextstate[J.first][J.second].first <<
              ", b=" << nextstate[J.first][J.second].second << "]" << endl;
      J = nextstate[J.first][J.second];
    }
  }

  return 0;
}
