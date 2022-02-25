#ifndef TIGER_H
#define TIGER_H

#include "animal.h"
using namespace std;

class Tiger: public Animal {
private: 
string name;
string soundsLike;

public:
Tiger(string n, string s): Animal(0, 10.0) {
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
