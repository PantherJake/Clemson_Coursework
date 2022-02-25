#include "owner.h"

Owner::Owner(string n, int c) {
name = n;
age = c;
}

string Owner::getName() {
return name;
}

int Owner::getAge() {
return age;
}
