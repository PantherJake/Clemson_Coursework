/*
  This program reads tf.txt and answers.txt to reveal how many questions
  you got right for part 1 of the final.  Feel welcome to borrow bits of
  it as part of your ultimate solution if this is convenient.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

const int N = 1000;
bool ans[N+1];
map<int, string> M;

int main(void)
{
  ifstream tf_file("tf.txt");
  ifstream answer_file("answers.txt");

  int num, correct=0;;
  string TF, qnum, the, answer, to, question, is, s;
  for (int i=1; i<=N; i++) { answer_file >> s; ans[i] = s=="T"; }
  for (int i=1; i<=N; i++) {
    tf_file >> qnum >> TF >> the >> answer >> to >> question >> num >> is >> s;
    if (s == "T") correct += ans[i]==ans[num];
    else          correct += ans[i]!=ans[num];
  }
  cout << "Num correct: " << correct << "\n";
}
