#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Owner {
private:
string name;
int age;

public:
Owner() {};
~Owner() {};
Owner(string, int);
string getName();
int getAge();
};


#endif
