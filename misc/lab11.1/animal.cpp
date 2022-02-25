#include "animal.h"
using namespace std;

int Animal:: getAge() {
return age;
}

double Animal:: getWeight() {
return weight;
}

void Animal:: setAge(int a) {
age = a;
}

void Animal:: setWeight(double w) {
weight = w;
}

void Animal:: printInfo() {
cout << "     Age: " << age << endl;
cout << "  Weight: " << weight << endl;
//cout << "    Name: " << name << endl;
//cout << "   Sound: " << soundsLike << "\n\n";
}

