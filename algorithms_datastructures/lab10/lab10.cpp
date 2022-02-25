#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef string Node;
map<Node, vector<Node>> neighbors;
vector<int> dist;
vector<Node> all_nodes;

void bfs(int source) {
  int count = 0;
  for(int i = 0; i < all_nodes.size(); ++i) {
    dist[count] = all_nodes.size();
    count++;
  }
  dist[source] = 0;
  cout << dist[5] << endl;

}

vector<Node> differbyone(Node index) {
  vector<Node> V;
  int count = 0;
  Node push;
  ifstream F("words5.txt");

  while(F >> push) {
    for(int i = 0; i < index.length(); ++i) {
      if(index[i] != push[i]) count++;
    }

    if(count == 1) {
      V.push_back(push);
      //cout << "Found differ by one!" << endl;
    }

    count = 0;
  }

  F.close();
  return V;
}

int main(void) {
  int count = 0;
  int f;
  ifstream inFile("words5.txt");
  Node s;
  vector<Node> dif;

  while(inFile >> s) {
    if(s == "graph") {
      f = count;
    }

    all_nodes.push_back(s);
    neighbors.insert(pair<Node, vector<Node>> (s, differbyone(s)));
    count++;
  }

  //Goal 1 Complete

  // Node f;
  // f = neighbors.find("graph")->first;
  bfs(f);

  inFile.close();
  return 0;
}
