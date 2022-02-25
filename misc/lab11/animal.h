#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
private: 
int age;
double weight;

public:
//Animal();
Animal(int a, double w) {
age = a;
weight = w; }

int getAge();
double getWeight();
void setAge(int a);
void setWeight(double w);
virtual void printInfo();
};

#endif
