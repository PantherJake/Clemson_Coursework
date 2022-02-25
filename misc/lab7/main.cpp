#include "owner.h"
#include "dog.h"

int main() {
string name;
int age;
cout << "Enter in your dog's breed and age. \n";
cin >> name;
cin >> age;

Dog c(name, age);

c.printDogInfo();
}

