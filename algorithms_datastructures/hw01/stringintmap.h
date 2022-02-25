#ifndef STRINGINTMAP_H /* Prevent multiple inclusion... */
#define STRINGINTMAP_H

#include <string>
#include <vector>
using namespace std;

class StringIntMap {

 private:

  struct Node {
    string key;
    int val;
    Node *next;
    Node(string k, int v, Node *n) { key = k; val = v; next = n; }
  };

  Node **table;  // array of pointers to linked lists
  int size;      // size of table, as currently allocated
  int num_elems; // number of elements stored in the table
  Node **allocate_table(int size);  // private helper function

 public:
  StringIntMap();
  ~StringIntMap();
  int &operator[](string key);
  bool find(string key);
  void insert(string key, int val);
  void remove(string key);
  void print(void);
  int get_num_elems(void);
  string *get_keys(void);
};

struct Word {
  string text;
  int num_pages;
  vector <int> pages;

  Word() {
    text = num_pages;
  }
};

struct Webpage {
  string url;
  int num_links;
  int num_words;
  vector <int> links;
  vector <string> words;
  double weight;
  double new_weight;

  Webpage() {
    url = "NONE";
    num_links = 0;
    num_words = 0;
    weight = 1;
  }
};

#endif
