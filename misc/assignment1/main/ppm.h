#ifndef PPM_H
#define PPM_H
#include "colorPixel.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;



class ppm
{
	private:
		string magicNumber;
		int height;
		int width;
		string maxValue;
		//vector <string> ppmColor;
	
	public: 
		vector <string> ppmColor;
		ppm();
		ppm(string m, int h, int w, string mv, vector <string> ppm)
		{
		magicNumber = m;
		height = h;
		width = w;
		maxValue = mv;
		ppmColor = ppm;
		}
		//~ppm();
		void wColorPixel(ofstream& fp);
		ppm rColorPixel(ifstream& fp);
		
		string getMagicNum() {return magicNumber;}
		int getHeight() {return height;}
		int getWidth() {return width;}
		string getMax() {return maxValue;}
};
ppm rColorPixel(ifstream& fp);
void wColorPixel(ofstream& fp, ppm a);

void BinaryColor(ifstream& fp);

#endif
