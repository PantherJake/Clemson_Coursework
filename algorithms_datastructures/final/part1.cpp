#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

const int N = 1000;
map<int, string> M;

int main() {
  ofstream answer_file("answer.txt");
  ifstream tf_file("tf.txt");
  string TF, qnum, the, answer, to, question, is, s;
  int num;

  // Initialize map
for(int i = 1; i <= N; ++i) {
  tf_file >> qnum >> TF >> the >> answer >> to >> question >> num >> is >> s;
  M[num] = s;
}

  for(int i = 1; i <= N; ++i) {
    if(M[i].length() > 0) {
    answer_file << "#" << i << ") " << M[i] << endl;
  }
  }
}
