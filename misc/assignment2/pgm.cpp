#include "pgm.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

pgm rGrayPixel(ifstream& fp);
void wGrayPixel(ofstream& fp, pgm a);

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
	}*/	
	pgm Obj(tempMagicNumber, tempHeight, tempWidth, tempMaxValue, pgmImage);
	return Obj;
}

/*This function makes a new file and writes it to copy it */
void wGrayPixel(ofstream& fp, pgm a) {
fp << a.getMagicNum() << "\n" << a.getWidth() << " " << a.getHeight() << "\n" << a.getMax() << endl;
vector<string> b;
b = a.pgmGray;
//cout << b.at(0) << endl;

/*for(vector<string>::iterator it = b.end(); it != b.begin(); --it) { 
fp << *it << endl;*/
for(unsigned int i = b.size() - 1; i > 0; --i) {
fp << b.at(i) << endl;
}
}
