#ifndef MONKEY_H
#define MONKEY_H

#include "animal.h"
using namespace std;

class Monkey: public Animal {
private: 
string name;
string soundsLike;

public:
Monkey(string n, string s): Animal(0, 10.0) {
name = n;
soundsLike = s;
}

string getVoice();
string getName();
void setVoice(string s);
void setName(string n);
void printInfo();
};

#endif


