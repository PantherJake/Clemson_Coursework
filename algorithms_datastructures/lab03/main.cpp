#include "points.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
Points P;
double close;
double x, y;
int count = 0;


ifstream coord;
coord.open ("points.txt");
while (coord >> x >> y) {
	P.insert(x, y);
	count++;
}
cout << "Points have been inserted." << endl;
cout << count << endl;


return 0;
}


