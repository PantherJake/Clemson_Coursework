#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
//#include "fig.h"
using namespace std;

const int N = 15;

struct Point { double x, y; };

vector<Point> P(N);
vector<int> tour(N);

double dist(int a, int b)
{
  double dx = P[a].x - P[b].x, dy = P[a].y - P[b].y;
  return sqrt(dx*dx + dy*dy);
}

double tourlen(void)
{
  double total = 0.0;
  for (int i=0; i<N; i++) {
    int a = tour[i];
    int b = tour[(i+1)%N];
    total += dist(a,b);
  }
  return total;
}

double best_len = 7813462346;
vector<int> best;

// Investigate all possible cities to go in tour[index]
void solve(int index)
{
  // Base case
  if (index == N) {
    if (tourlen() < best_len) {
      best_len = tourlen();
      best = tour;
    }
  }

  // Prune search
  double sofar = 0.0;
  for (int i=0; i<index-1; i++) {
    int a = tour[i];
    int b = tour[(i+1)%N];
    sofar += dist(a,b);
  }
  double to_complete = dist(tour[index-1], tour[0]);
  if (sofar + to_complete > best_len) return;

  vector<bool> visited(N);
  for (int i=0; i<index; i++) visited[tour[i]] = true;

  for (int i=0; i<N; i++)
    if (!visited[i]) {
      tour[index] = i;
      solve(index+1);
    }
}

int main(void)
{
  for (int i=0; i<N; i++) {
    P[i].x = drand48() * 1000;
    P[i].y = drand48() * 1000;
  }
  tour[0] = 0;
  solve(1);
  header();
  tour = best;
  for (int i=0; i<N; i++) {
    circle(P[i].x, P[i].y);
    int a = tour[i];
    int b = tour[(i+1)%N];
    line (P[a].x, P[a].y, P[b].x, P[b].y);
  }
}
