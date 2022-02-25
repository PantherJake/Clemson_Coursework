/*Jake Vickio, Trevor Rizzo */

#include "ppm.h"
#include "pgm.h"
#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
using namespace std;

ppm rColorPixel(ifstream& fp);
void wColorPixel(ofstream& fp, ppm a);
void BinaryColor(ifstream& fp);
pgm rGrayPixel(ifstream& fp);
void wGrayPixel(ofstream& fp, pgm a);
void BinaryGray(ifstream& fp);

int main()
{
int cont = 0;
while(cont == 0)
{
int userChoice = 0;
cout << "Welcome to the CPSC 1020 Assignment 1 Image Replicator!" << endl;
cout << "Select which image you would like to replicate" << endl << "1) potatochips.ppm" << endl << "2) chips.ppm" << endl << "3) potatochips.pgm" << endl << "4) chips.pgm" << endl;
cin >> userChoice;

if(userChoice < 1 || userChoice > 4)
	{
	cout << "We're sorry, please enter a valid choice!" << endl;
	}
else if(userChoice == 1)
	{
	ifstream input;
	input.open("potatochips.ppm");
	ppm Object = rColorPixel(input);
	
	ofstream output;
	output.open("copyColor.ppm");
	wColorPixel(output , Object);
	cont = 1;
	}
else if(userChoice == 2)
	{
	ifstream input;
	input.open("chips.ppm");
	BinaryColor(input);
	cont = 1;
	}
else if(userChoice == 3)
	{
	ifstream input;
	input.open("potatochips.pgm");
	pgm Obj = rGrayPixel(input);
	
	ofstream output;
	output.open("CopyGray.pgm");
	wGrayPixel(output, Obj);
	cont = 1;
	}
else if(userChoice == 4)
	{
	ifstream input;
	input.open("chips.pgm");
	BinaryGray(input);
	cont = 1;
	}

}	
cout << "Thank you for using the 1020 Assignment 1 Image Replicator, your file is in the directory!" << endl;	
}

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

void wGrayPixel(ofstream& fp, pgm a) {
fp << a.getMagicNum() << "\n" << a.getWidth() << " " << a.getHeight() << "\n" << a.getMax() << endl;
for(int i = 0; i < a.pgmGray.size(); ++i) {
	fp << a.pgmGray.at(i) << endl;
}
}

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
	//cout << tempMagicNumber << endl << tempWidth << " " << tempHeight << endl << tempMaxValue << endl;

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
for(int i = 0; i < a.ppmColor.size(); ++i) {
fp << a.ppmColor.at(i) << endl;
}
}

void BinaryColor(ifstream& fp) {
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

