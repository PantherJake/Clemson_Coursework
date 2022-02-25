#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

const int N = 50;

struct Point { double x, y; };

vector<Point> P(N);
vector<int> tour(N);

double best_len = 7813462346;
vector<int> best;

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

int ouch = 0;
void refine_tour(int index) {
  // Base case
  if (index == N) {
    if (tourlen() < best_len) {
      best_len = tourlen();
      best = tour;
    }
    return;
  }

    if(dist(tour[index], tour[ouch]) < dist(tour[ouch], tour[ouch + 1])) {
      swap(tour[index], tour[ouch + 1]);
    }

  refine_tour(index+1);
}

int main() {
  Point temp;
  ifstream inFILE;
  double a, b;
  inFILE.open("tsp_points.txt");

  if(inFILE == NULL) {
    cout << "File Error." << endl;
    return -1;
  }

  int count = 0;
  // Initialize vector
  while(inFILE >> a) {
    temp.x = a;
    inFILE >> b;
    temp.y = b;

    P[count] = temp;
    count++;
  }

  //cout << P[N-1].x << " " << P[N-1].y << endl;

for(int l = 0; l < 1000; ++l) {
  // Randomize tour to start
  for(int i = 1; i < N; ++i) {
    for(int q = 1; q < N; q++) {
      tour[q] = q;
    }
    swap(tour[i], tour[rand()%i]);
    refine_tour(1);
  }
}

  cout << "Best Tour Length: " << best_len << endl;
  return 0;
}

// HW3 STUFF

int total;
int helpful_index;
vector<Candy> temp = C;
int bag_num = 0;
double max = temp[0].ratio;
Bag B[3];

// Bag *B = new Bag[2];
for(int i = 0; i < 3; ++i) {
  B[i].total_tastiness = 0;
  B[i].num_candies = 0;
  B[i].sofar = 0;
}

for(int i = 0; i < N; ++i) {
  for(int j = 0; j < N; ++j) {
    if(temp[j].ratio > max) {
      max = temp[j].ratio;
      helpful_index = temp[j].index;
      //cout << max << " " << helpful_index << endl;
    }
    max = temp[0].ratio;
  }

  if((temp[helpful_index].w + B[bag_num].sofar) > 2000) {
    if(i == N-1 && bag_num < 3) {
      //cout << "Hi" << endl;
      bag_num++;
      i=0;
    }
  }
  else {
    B[bag_num].total_tastiness += temp[helpful_index].t;
    B[bag_num].num_candies++;
    B[bag_num].sofar += temp[helpful_index].w;
    //Erase max in helpful_index
    temp[helpful_index].ratio = 0.0;
  }
}
