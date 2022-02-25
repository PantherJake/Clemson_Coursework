// This is a sketch you can use for your "bad1" .. "bad3" programs...

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
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
  int hash = 6661;
  int max = 0;
  
  for(int i = 0; i < N; i++) {
    cout << hash << endl;
    hash += 10000;
  }

  return 0;
}
