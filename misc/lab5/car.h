#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using namespace std;

class Car {

private:
string model;
string make;
int year;
double price;

public:
Car(){}
~Car(){}

void setMake(string m) {make = m;}
void setModel(string d) {model = d;}
void setYear(int i) {year = i;}
void setPrice(float f) {price = f;}

string getMake() {return make;}
string getModel() {return model;}
int getYear() {return year;}
double getPrice() {return price;}

void printCarInfo();
bool isClassic();
};

void Car::printCarInfo() {
cout << year << " " << make << " " << model << " " << price << endl;
}

bool Car::isClassic() {
if (year <= 1990) {
return true;
}
else {
return false;
}

}

#endif
