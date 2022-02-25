#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

int count = 0;
int N;
int **board;

bool check_board(int C);
bool isValid(int r, int c);

int main(int argc, char *argv[]) {
  char* a = argv[1];
  N = atoi(a);
  //int solution = 0;
  board = new int *[N];
  for(int i = 0; i < N; ++i) {
    board[i] = new int[N];
  }
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      board[i][j] = 0;
    }
  }

  if(check_board(0) == 0) {cout << "No sol." << endl; return -1;}
  cout << "Number of possible solutions: " << count << endl;

  return 0;
}

bool check_board(int C) {
  if(C == N) {count++; return true;}

  bool std = false;
  for(int i = 0; i < N; ++i) {
    if(isValid(i, C)) {
      board[i][C] = 1;
      std = check_board(C + 1) || std;

      board[i][C] = 0;
    }
  }
  return std;
}

bool isValid(int r, int c) {
  int i, j;
  for (i = 0; i < c; i++)
      if (board[r][i])
          return false;

  for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
      if (board[i][j])
          return false;

  for (i = r, j = c; j >= 0 && i < N; i++, j--)
      if (board[i][j])
          return false;

  return true;
}
