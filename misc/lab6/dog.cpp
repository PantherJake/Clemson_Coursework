#include "dog.h"
using namespace std;

Dog::Dog(string name, int c) {
breed = name;
age = c;

string ownerTag;
int ownerAge;

cout << "Enter in name and age of owner: \n";
cin >> ownerTag;
cin >> ownerAge;

owner = Owner(ownerTag, ownerAge);
}

string Dog::getBreed() {
return breed;
}

int Dog::getAge() {
return age;
}

int Dog::dogCount = 0;

int Dog::getDogCount() {
return dogCount;
}

void Dog::printDogInfo() {
cout << "Before instantiating Dog objects dogCount is: " << dogCount << endl;
dogCount++;
cout << "Dog " << dogCount << ":" << endl;
cout << "Breed: " << breed << endl;
cout << "Age: " << age << endl;
cout << "Owner: " << owner.getName() << ", " << owner.getAge() << " y/o\n";
cout << "After instantiating Dog objects dogCount is: " << dogCount << endl;
}
