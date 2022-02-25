#ifndef DOG_H
#define DOG_H

#include "owner.h"
using namespace std;

class Dog {
private:
string breed;
int age;
Owner owner;
static int dogCount;

public:
Dog();
Dog(string, int);
string getBreed();
int getAge();
void setBreed(string h);
void setAge(int a);
void printDogInfo();
static int getDogCount();
};

#endif
