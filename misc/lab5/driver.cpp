#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "car.h"
using namespace std;

int main() {
ifstream in_file;
in_file.open ("raw.data");
Car car1, car2, car3, car4, car5;


string make[4], model[4];
int year[4];
float price[4];

for (int i = 0; i < 4; ++i) {
in_file >> year[i] >> make[i] >> model[i] >> price[i];
}
// go up to 4
car1.setMake(make[0]); car1.setModel(model[0]); car1.setYear(year[0]); car1.setPrice(price[0]);
car2.setMake(make[1]); car2.setModel(model[1]); car2.setYear(year[1]); car1.setPrice(price[1]);
car3.setMake(make[2]); car3.setModel(model[2]); car3.setYear(year[2]); car3.setPrice(price[2]);
car4.setMake(make[3]); car4.setModel(model[3]); car4.setYear(year[3]); car4.setPrice(price[3]);
car5.setMake(make[4]); car5.setModel(model[4]); car5.setYear(year[4]); car5.setPrice(price[4]);

in_file.close();

ofstream out_file;
out_file.open("formatted.data");

out_file << setw(10) << "Car 1:\n" << "Make: " << setw(6) << car1.getMake() << endl;
out_file << "Model: \t" << setw(6) << car1.getModel() << endl;
out_file << "Year: \t" << setw(6) << car1.getYear() << endl; 
out_file << "Price: \t" << setw(6) << car1.getPrice() << endl;

out_file << setw(10) << "Car 2:\n" << "Make: " << setw(6) << car2.getMake() << endl;
out_file << "Model: \t" << setw(6) << car2.getModel() << endl;
out_file << "Year: \t" << setw(6) << car2.getYear() << endl; 
out_file << "Price: \t" << setw(6) << car2.getPrice() << endl;

out_file << setw(10) << "Car 3:\n" << "Make: " << setw(6) << car3.getMake() << endl;
out_file << "Model: \t" << setw(6) << car3.getModel() << endl;
out_file << "Year: \t" << setw(6) << car3.getYear() << endl; 
out_file << "Price: \t" << setw(6) << car3.getPrice() << endl;

/*out_file << setw(10) << "Car 4:\n" << "Make: " << setw(6) << car4.getMake() << endl;
out_file << "Model: \t" << setw(6) << car4.getModel() << endl;
out_file << "Year: \t" << setw(6) << car4.getYear() << endl; 
out_file << "Price: \t" << setw(6) << car4.getPrice() << endl;*/

/*out_file << setw(10) << "Car 5:\n" << "Make: " << setw(6) << car5.getMake() << endl;
out_file << "Model: \t" << setw(6) << car5.getModel() << endl;
out_file << "Year: \t" << setw(6) << car5.getYear() << endl; 
out_file << "Price: \t" << setw(6) << car5.getPrice() << endl;*/
//out_file << "Car 2:\n" << car2.getMake() << car2.getModel() << car2.getYear() << car2.getPrice() << endl;

out_file.close();

}


