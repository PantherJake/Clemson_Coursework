#include "ppm.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ppm rColorPixel(ifstream& fp);
void wColorPixel(ofstream& fp, ppm a);

//void BinaryColor(ifstream& fp);

int main() {
ifstream input;
input.open("potatochips.ppm");
ppm Object = rColorPixel(input);

ofstream output;
output.open("copyPp.ppm");
wColorPixel(output, Object);

/*ifstream input;
input.open("chips.ppm");
BinaryColor(input);*/
}


ppm rColorPixel(ifstream& fp) {
/*declaring temp variables*/
int numOfPixels;
int tempHeight;
int tempWidth;
string tempMagicNumber;
string temp;
vector <string> ppmImage;

getline(fp, tempMagicNumber); 
getline(fp, temp);

std:: string stringHeight, stringWidth, tempMaxValue;
fp >> stringHeight >> stringWidth >> tempMaxValue;

//converting width to int
stringstream wid(stringHeight);
wid >> tempWidth;

//converting height to int
stringstream hit(stringWidth);
hit >> tempHeight;
//stoi(tempWidth);
//stoi(tempHeight);

numOfPixels = tempHeight * tempWidth;
for(int i = 0; i < numOfPixels; i++) {
std:: string redVal, greenVal, blueVal;
getline(fp, redVal);
getline(fp, greenVal);
getline(fp, blueVal);
ppmImage.push_back(redVal);
ppmImage.push_back(greenVal);
ppmImage.push_back(blueVal);
}

//cout << tempMagicNumber << "\n" << tempHeight << " " << tempWidth << "\n" << tempMaxValue << "\n";

/*for(int j = 0; j < 5; j++) {
cout << ppmImage.at(j) << "\n";
}*/

ppm Obj(tempMagicNumber, tempHeight, tempWidth, tempMaxValue, ppmImage);
return Obj;
}

void wColorPixel(ofstream& fp, ppm a) {
fp << a.getMagicNum() << "\n" << a.getWidth() << " " << a.getHeight() << "\n" << a.getMax();
vector<string> b;
b = a.ppmColor;
//for(int i = a.ppmColor.end(); i < a.ppmColor.size(); --i) {
for(vector<string>::iterator it = b.end(); it != b.begin(); --it) { 
fp << *it << endl;
//fp << a.ppmColor.at(i) << endl;
}
}

/*void BinaryColor(ifstream& fp) {
int numPixels = 0;
int tempWidth = 0;
int tempHeight = 0;
string temp;
string tempMagicNumber;
vector<string> ppmImage;	

	getline(fp, tempMagicNumber);
	getline(fp, temp);

	std:: string stringWidth, stringHeight, tempMaxValue;

	fp >> stringWidth >> stringHeight >> tempMaxValue;
	stringstream wdt(stringWidth);
	wdt >> tempWidth;

	stringstream hgt(stringHeight);
	hgt >> tempHeight;
	//cout << tempMagicNumber << endl << tempWidth << " " << tempHeight << endl << tempMaxValue << endl;

	numPixels = tempWidth * tempHeight;
*/
/*::std::ifstream in("chips.pgm", ::std::ios::binary);
while(in) {
	char c;
	in.get(c);
	if (in) {
		pgmImage.push_back(c);
	}
}*/
/*string temp1;
getline(fp, temp1);

ppm Obj(tempMagicNumber, tempHeight, tempWidth, tempMaxValue, ppmImage);

ofstream out;
out.open("ColorBinary.ppm");

wColorPixel(out, Obj);

::std::ifstream in("chips.ppm", ::std::ios::binary);
while(in) {
	char c;
	in.get(c);
	if (in) {
		out << c << "\n";
	}
}
}
*/
