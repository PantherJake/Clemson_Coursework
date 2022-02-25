
#ifndef COLORPIXEL_H
#define COLORPIXEL_H
#include <string>
using namespace std;

class ColorPixel
{
	private: 
		string red;
		string green;
		string blue;
	
	public: 
		ColorPixel();
		ColorPixel(string r, string g, string b)
		{
		red = r;
		green = g;
		blue = b;
		}
		string getRed() {return red;}
		string getGreen() {return green;}
		string getBlue() {return blue;}
		void setR(string red) {this->red = red;}
		void setG(string green) {this->green = green;}
		void setB(string blue) {this->blue = blue;}
		~ColorPixel();
};

#endif
