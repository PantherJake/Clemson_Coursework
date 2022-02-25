#include "animal.h"
#include "monkey.h"
using namespace std;

string Monkey:: getVoice() {
return soundsLike;
}

string Monkey:: getName() {
return name;
}

void Monkey:: setVoice(string s) {
soundsLike = s;
}

void Monkey:: setName(string n) {
name = n;
}

void Monkey:: printInfo() {
cout << "     Age: " << getAge() << endl;
cout << "  Weight: " << getWeight() << endl;
cout << "    Name: " << name << endl;
cout << "   Sound: " << soundsLike << "\n\n";
}
