#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


/*I would use the starter code for lab 10, edit the starter code for build build_graph
and main so that it could use BFS to find the shortest path adding "fital" to the file making it
possible to construct a word ladder from "cruel" to "final". Runs in O(n logn) time.*/

struct Node {
  string s;
  int pred, dist;
  vector<int> nbrs;
  Node (string _s) { s = _s; }
};

vector<Node> W;

// returns farthest distance from s, and the node id with that distance
pair<int,int> bfs(int s) {
  for (int i=0; i<W.size(); i++) W[i].dist = W.size();
  W[s].dist = 0;
  pair<int,int> result;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int x = Q.front(); Q.pop();
    result = make_pair(W[x].dist, x);
    for (int y : W[x].nbrs)
      if (W[y].dist == W.size()) {
	W[y].dist = W[x].dist + 1;
	W[y].pred = x;
	Q.push(y);
      }
  }
  return result;
}

int letters_diff(string s, string t)
{
  int n=0;
  for (int i=0; i<5; i++) if (s[i] != t[i]) n++;
  return n;
}

void build_graph(void)
{
  int num_words = W.size();
  string w = "fital";

  for(int i = 0; i < 1156; ++i) {
    all_nodes.push_back(W.at(i));
  }
  all_nodes.push_back(w);
  for(int j = 1157; j < num_words + 1; j++) {
    all_nodes.push_back(w);
  }


}

void print_path(int x, int y)
{
  if (x != y) print_path(x, W[y].pred);
  cout << W[y].s << "\n";
}

int main(void)
{
  string s;
  int farthest=0;
  vector<pair<int,int>> F;

  ifstream wfile ("words5.txt");
  while (wfile >> s) W.push_back(Node(s));
  build_graph();

  for (int i=0; i<W.size(); i++) {
    F.push_back(bfs(i));
    if (F[i].first > F[farthest].first) farthest = i;
  }

  pair<int,int> result = bfs(farthest);
  cout << "Longest word ladder length: " << result.first << "\n";
  print_path(farthest, result.second);
}
