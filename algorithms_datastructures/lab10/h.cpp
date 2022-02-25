#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

unordered_map <string, vector<string> > Neighbors;
unordered_map <string, int> dists;
vector <pair<int, string> > E;

int bfs (string s) {
  int ec;
  queue <string> q;
  dists[s] = 0;
  q.push(s);
  while (!q.empty()) {
    string v = q.front();
    ec = dists[v];
    q.pop();
    for (auto &n : Neighbors[v]) {
      if (dists[n] == 49) {
        q.push(n);
        dists[n] = dists[v] + 1;
      }
    }
  }
  return ec;
}

int main (void) {
  string a, b;
  while (cin >> a >> b) {
    Neighbors[a].push_back(b);
    Neighbors[b].push_back(a);
  }

  for (unordered_map <string, vector<string> >::iterator it = Neighbors.begin(); it!=Neighbors.end(); it++) {
    for (unordered_map <string, vector<string> >::iterator it = Neighbors.begin(); it!=Neighbors.end(); it++) {
      dists[it->first] = 49;
    }
    int hld = 0;
    hld = bfs(it->first);
    E.push_back(make_pair(hld, it->first));
  }

  sort(E.begin(), E.end());

  for (int i=0; i < E.size(); i++) {
    cout << E[i].second << " " << E[i].first << endl;
  }

  return 0;
}
