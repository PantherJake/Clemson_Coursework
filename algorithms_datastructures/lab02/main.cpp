#include <string>
#include <fstream>
#include <iostream>
#include "stringset.h"

using namespace std;

void spellcheck(void)
{
Stringset S;
string word;

ifstream wordfile("words.txt");

while (wordfile >> word)
S.insert(word);
wordfile.close();

cout << "Dictionary loaded.  Please enter words to spell check.\n";

while (cin >> word) {
cout << "Possible alternatives for word '" << word << "':\n";

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string saved = word;

for (int i = 0; i < word.length(); ++i) {
	for (int j = 0; j < 25; ++j) {
//Testing for every letter in the alphabet in each position of the string 'word'
	word[i] = alphabet[j];
// If statement tests to find word and make sure a duplicate is not printed
		if (S.find(word) && word != saved) {
		cout << word << endl;
		}
	}
	word = saved;
}		


    // TBD: print out all words that differ by exactly one character...
  }
}

void test(void)
{
  Stringset S;
  string key, command;

  while(cin >> command) {
    
    if (command == "insert") {
      
      cin >> key;
      if (S.find(key))
	cout << "Error!  Key " << key << " already in structure!\n";
      else
	S.insert(key);

    } else if (command == "remove") {
      
      cin >> key;
      if (!S.find(key)) 
	cout << "Error!  Key " << key << " not in structure!\n";
      else
	S.remove(key);

    } else if (command == "find") {

      cin >> key;
      if (S.find(key))
	cout << "Key " << key << " present.\n";
      else
	cout << "Key " << key << " absent.\n";

    } else if (command == "print") {

      cout << "Contents of structure:\n";
      S.print();

    } else if (command == "quit") {

      break;

    } else {

      cout << "Error!  Unknown command '" << command << "'!\n";

    }
  }
}

int main(void)
{
  //test();
  spellcheck();
  return 0;
}
