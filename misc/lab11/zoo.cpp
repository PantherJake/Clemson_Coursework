#include "tiger.h"
#include "monkey.h"
using namespace std;

int main() {
vector<Animal*> myAnimals;

Animal* t1 = new Tiger("Mufasa", "Roar!");
t1->setAge(17);
t1->setWeight(69.7);

Animal* t2 = new Tiger("Scar", "Roar!");
t2->setAge(16);
t2->setWeight(42); 

myAnimals.push_back(t1);
myAnimals.push_back(t2);

Animal* m1 = new Monkey("Roberto", "Screeech!!");
m1->setAge(4); 
m1->setWeight(20.4); 

Animal* m2 = new Monkey("Dude", "Screeech!!");
m2->setAge(3); 
m2->setWeight(30.3); 

myAnimals.push_back(m1);
myAnimals.push_back(m2);

int count = 1;
unsigned int size = myAnimals.size();

for (unsigned int i = 0; i < size; ++i) {
//for (const auto &animal: myAnimals) {
cout << "Animal " << count << ":" << endl;
//animal[0]->printInfo();
myAnimals[i]->printInfo();
++count;
}

return 0;
}


