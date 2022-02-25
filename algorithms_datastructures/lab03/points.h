#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <assert.h>
#include <math.h>
using namespace std;

class Points {
private:
struct Node {
double x;
double y;
Node* next;
Node (double x, double y, Node *n) {double a = x; double b = y; next = n;}
Node() {x = 0; y = 0; next = NULL;}
};

Node ***A;
int b;

public:
Points();
~Points();
void insert(double x, double y);
double dist();
};

#endif

