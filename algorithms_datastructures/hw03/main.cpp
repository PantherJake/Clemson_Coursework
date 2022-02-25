#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstdbool>
#include <tuple>
using namespace std;

const int N = 16, O = 3;
struct Candy { int w, t, index; double ratio; };
struct Bag {
  int total_tastiness = 0;
  int num_candies = 0;
  int sofar = 0;
};
vector<Candy> C(N);
Bag B[O+1];
int best = 10591;

void insert_new_candy(int candy, int bag_num) {
  B[bag_num].total_tastiness += C[candy].t;
  B[bag_num].num_candies++;
  if(B[bag_num].sofar + C[candy].w > 2000) return;
  else { B[bag_num].sofar += C[candy].w; }
}

void remove_candy(int candy, int bag_num) {
  B[bag_num].total_tastiness -= C[candy].t;
  B[bag_num].num_candies--;
  B[bag_num].sofar -= C[candy].w;
}

void greedy_solution(void) {
  int total;
  int helpful_index;
  vector<Candy> temp = C;
  int bag_num = 0;
  double max = temp[0].ratio;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(temp[j].ratio > max) {
        max = temp[j].ratio;
        helpful_index = j;
        //cout << max << " " << helpful_index << endl;
      }
      //cout << max << " " << helpful_index << endl;
      max = temp[0].ratio;
    }

    temp[helpful_index].ratio = 0.0;

    if((temp[helpful_index].w + B[bag_num].sofar) > 2000) {
      if(i == N-1 && bag_num < 3) {
        //cout << i << endl;
        bag_num++;
        i=0;
      }
    }
    else {
      B[bag_num].total_tastiness += temp[helpful_index].t;
      B[bag_num].num_candies++;
      B[bag_num].sofar += temp[helpful_index].w;
      //Erase max in
    }
  }

  // cout << B[0].total_tastiness << "\n" << B[1].total_tastiness << "\n" << B[2].total_tastiness << endl;
  // cout << B[0].sofar << "\n" << B[1].sofar << "\n" << B[2].sofar << endl;
  // cout << B[0].num_candies << "\n" << B[1].num_candies << "\n" << B[2].num_candies << endl;
  total = B[0].total_tastiness + B[1].total_tastiness + B[2].total_tastiness;

  cout << "Greedy: " << total << endl;
  return;
}

void random_assignment() {
  int index;
  for(int i = 0; i < N; ++i) {
    while(B[i].sofar < 2000) {
      index = C[rand() % 16].index;
      B[i].total_tastiness += C[index].t;
      if(B[i].sofar + C[index].w > 2000) break;
      else {
        B[i].sofar += C[index].w;
      }
    }
  }
  // cout << B[0].total_tastiness << "\n" << B[1].total_tastiness << "\n" << B[2].total_tastiness << endl;
  // cout << B[0].sofar << "\n" << B[1].sofar << "\n" << B[2].sofar << endl;
}

void iterative_solution(void) {
  int best;
  for(int iter = 0; iter < 1000; ++iter) {
    random_shuffle(C.begin(), C.end());
    random_assignment();
    //refine();
  }

  cout << "Iterative: " << best << endl;
  return;
}

int highest_possible(int index) {
  int high_taste = B[0].total_tastiness + B[1].total_tastiness + B[2].total_tastiness;
  int high_weight = B[0].sofar + B[1].sofar + B[2].sofar;
  for(int i = index; i < N; ++i) {
    if(high_weight + C[i].w > 6000) {
      high_taste = high_taste + C[i].t;
      break;
    }
    else {
      high_taste = high_taste += C[i].t;
    }
  }
  return high_taste;
}

int exhaustive(int index, int sym) {
  if(index >= N)
  {
    if(B[0].total_tastiness + B[1].total_tastiness + B[2].total_tastiness > best) {
      best = B[0].total_tastiness + B[1].total_tastiness + B[2].total_tastiness;
    }
    return 0;
  }
  for(int i = 0; i < sym; ++i) {
    if(i != sym -1) {
      if(B[i].sofar + C[index].w <= 2000) {
        if(highest_possible(index) <= best) return 0;
        insert_new_candy(index, i);
        exhaustive(index + 1, 4);
      }
      else exhaustive(index + 1, 4);
    }
  }
  return 0;
}

int main(void) {
  Candy temp;
  ifstream inFILE;
  int weight, taste;
  inFILE.open("candy.txt");

  int count = 0;
  while(inFILE >> weight) {
    temp.w = weight;
    inFILE >> taste;
    temp.t = taste;
    temp.ratio = (double)taste / (double)weight;
    temp.index++;
    C[count] = temp;
    count++;
  }

  // for(int i = 0; i < N; ++i) {
  //   cout << C[i].w << " " << C[i].t << " " << C[i].ratio << endl;
  // }

  inFILE.close();
  greedy_solution();

  for(int i = 0; i < 3; ++i) {
    B[i].total_tastiness = 0;
    B[i].num_candies = 0;
    B[i].sofar = 0;
  }

  iterative_solution();

  for(int i = 0; i < 3; ++i) {
    B[i].total_tastiness = 0;
    B[i].num_candies = 0;
    B[i].sofar = 0;
  }

  int n = exhaustive(0, 4);
  int total = B[0].total_tastiness + B[1].total_tastiness + B[2].total_tastiness;
  cout << "Exhaustive: " << total << endl;
  return 0;
}
