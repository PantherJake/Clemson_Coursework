#include "ppm.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ppm rColorPixel(ifstream& fp);
void wColorPixel(ofstream& fp, ppm a);

/*Function reads ppm file to proper variables, creates ppm object and returns it. */
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
ppmImage.push_back(blueVal);
ppmImage.push_back(greenVal);
}

//cout << tempMagicNumber << "\n" << tempHeight << " " << tempWidth << "\n" << tempMaxValue << "\n";

/*for(int j = 0; j < 5; j++) {
cout << ppmImage.at(j) << "\n";
}*/

ppm Obj(tempMagicNumber, tempHeight, tempWidth, tempMaxValue, ppmImage);
return Obj;
}

/*Function writes ppm data to a new file with an inputted name */
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
