#include "pgm.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
/*
pgm rGrayPixel(ifstream& fp);
void wGrayPixel(ofstream& fp, pgm a);

void BinaryGray(ifstream& fp);
*/
/*int main() {/*
ifstream input;
input.open("chips.pgm");
BinaryGray(input);

ifstream input;
input.open("potatochips.pgm");
pgm Object = rGrayPixel(input);

ofstream output;
output.open("CopyGray.pgm");
wGrayPixel(output, Object);
}*/

/*Read Gray Pixel in for non-binary copying, read the ppm file out to temporary variables then store them in the constructor */
pgm rGrayPixel(ifstream& fp) {
int numPixels = 0;
int tempWidth = 0;
int tempHeight = 0;
string temp;
string tempMagicNumber;
vector<string> pgmImage;	

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
	
	for(int i = 0; i < numPixels; i++)
	{
	std:: string pixelVal;
	fp >> pixelVal;
	pgmImage.push_back(pixelVal);
	}
	
	/*for(int j = 0; j < 5; j++)
	{
	cout << pgmImage.at(j)<< "\n";
	}	*/
	pgm Obj(tempMagicNumber, tempHeight, tempWidth, tempMaxValue, pgmImage);
	return Obj;
}

/*This function makes a new file and writes it to copy it */
void wGrayPixel(ofstream& fp, pgm a) {
fp << a.getMagicNum() << "\n" << a.getWidth() << " " << a.getHeight() << "\n" << a.getMax() << endl;
for(int i = 0; i < a.pgmGray.size(); ++i) {
	fp << a.pgmGray.at(i) << endl;
}
}

/*Reading binary values into the file directly plus writing the header */
void BinaryGray(ifstream& fp) {
int numPixels = 0;
int tempWidth = 0;
int tempHeight = 0;
string temp;
string tempMagicNumber;
vector<char> pgmImage;	

	getline(fp, tempMagicNumber);
	getline(fp, temp);

	std:: string stringWidth, stringHeight, tempMaxValue;

	fp >> stringWidth >> stringHeight >> tempMaxValue;
	stringstream wdt(stringWidth);
	wdt >> tempWidth;

	stringstream hgt(stringHeight);
	hgt >> tempHeight;
	cout << tempMagicNumber << endl << tempWidth << " " << tempHeight << endl << tempMaxValue << endl;

	numPixels = tempWidth * tempHeight;

/*::std::ifstream in("chips.pgm", ::std::ios::binary);
while(in) {
	char c;
	in.get(c);
	if (in) {
		pgmImage.push_back(c);
	}
}*/
string temp1;
getline(fp, temp1);

pgm Obj(tempMagicNumber, tempHeight, tempWidth, tempMaxValue, pgmImage);

ofstream out;
out.open("BinaryGray.pgm");

wGrayPixel(out, Obj);

::std::ifstream in("chips.pgm", ::std::ios::binary);
while(in) {
	char c;
	in.get(c);
	if (in) {
		out << c << "\n";
	}
}
}

