#ifndef PGM_H
#define PGM_H
#include "grayPixel.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;



class pgm
{
	private:
		string magicNumber;
		int height;
		int width;
		string maxValue;	
	  //vector<string> pgm;
		
	public:
		//vector<char> pgmGrayBoi;
    		vector<string> pgmGray;
		pgm();
		pgm(string m, int h, int w, string mv, vector<string> pgm)
		{
		magicNumber = m;
		height = h;
		width = w;
		maxValue = mv;
		pgmGray = pgm;
		}
		
		/*pgm(string m, int h, int w, string mv, vector<char> pgm)
		{
		magicNumber = m;
		height = h;
		width = w;
		maxValue = mv;
		pgmGrayBoi = pgm;
		}*/
		/*pgm rGrayPixel(ifstream& fp);
		void wGrayPixel(ofstream& fp, pgm a);*/
		string getMagicNum() {return magicNumber;}
		int getHeight() {return height;}
		int getWidth() {return width;}
		string getMax() {return maxValue;}
};

pgm rGrayPixel(ifstream& fp);
void wGrayPixel(ofstream& fp, pgm a);
#endif
