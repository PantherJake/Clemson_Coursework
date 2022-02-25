#include "animal.h"
#include "tiger.h"
using namespace std;

string Tiger:: getVoice() {
return soundsLike;
}

string Tiger:: getName() {
return name;
}

void Tiger:: setVoice(string s) {
soundsLike = s;
}

void Tiger:: setName(string n) {
name = n;
}

void Tiger:: printInfo() {
cout << "     Age: " << getAge() << endl;
cout << "  Weight: " << getWeight() << endl;
cout << "    Name: " << name << endl;
cout << "   Sound: " << soundsLike << "\n\n";
}
