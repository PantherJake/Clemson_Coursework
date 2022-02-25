#include <iostream>
//#include <stdlib>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;

class HashTable {
private:
  static const int num_groups = 10;

  struct Node {
    int key;
    string username;
    string password;
    Node* next;
  };

  Node* head;
public:
  int hashFunc(int key);
  bool insert(string username, string password, int key);
  bool isEmpty();
};

int HashTable::hashFunc(int key) {
  return key % num_groups;
}

bool HashTable::isEmpty() {
  int sum;
  if(head == NULL) return true;
  return false;
}

bool HashTable::insert(string username, string password, int key) {
  int hash = hashFunc(key);
  bool keyExists = false;

  for(Node* i = head; head != NULL; i = i->next) {
    if(i->key == hash) {
      keyExists = true;
      cout << "Cannot use password. Already used previously." << endl;
      return false;
    }
  }

  if(!keyExists) {
    Node* n = new Node;
    n->next = head;
    n->username = username;
    n->password = password;
    head = n;
  }
return true;
}

int main() {
HashTable HT;
string s;
string username;
string password;
int elems;
int N;

if(HT.isEmpty()) cout << "Nice." << endl;
else cout << "Noooo!" << endl;

FILE* fp = fopen("password_changes.txt", "r'");
if(fp == NULL) {
cout << "cannot open." << endl;
return -1;
}

fp >> elems;

while(fp >> s) {
  N++
  username = s;
  fp >> s;
  password = s;
  HP.insert(username, password, N);
  cout << username << "\n" << password << "\n\n";
}
