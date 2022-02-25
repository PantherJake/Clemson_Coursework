/* Jake Vickio, Trevor Rizzo */
#include "ppm.h"
#include "pgm.h"
#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
//string inFile(argv[1]);
//string outFile(argv[2]);
int cont = 0;
while(cont == 0)
{
int userChoice = 0;
/*Intro*/
/*cout << argc << endl;
for(int i = 0; i < argc; ++i) {
cout << argv[1] << endl;
}*/

cout << endl << "Welcome to the CPSC 1020 Assignment 2 Image Flipper!" << endl; 
cout << "Select type of image do you want to flip?" << endl << "1) " << ".ppm" << endl << "2) " << ".pgm" << endl;
cin >> userChoice;

/*Take user input to copy file */
if(userChoice < 1 || userChoice > 2)
	{
	cout << "We're sorry, please enter a valid choice!" << endl;
	}
else if(userChoice == 1)
	{
	// Opening files and calling function to read
	ifstream input;
	input.open(argv[1]);
	ppm Object = rColorPixel(input);
	
	// Opening file to write
	ofstream output;
	output.open(argv[2]);
	wColorPixel(output , Object);
	cont = 1;
	}
else if(userChoice == 2)
	{
	ifstream input;
	input.open(argv[1]);
	pgm Obj = rGrayPixel(input);
	
	ofstream output;
	output.open(argv[2]);
	wGrayPixel(output, Obj);
	cont = 1;
	}
}	
cout << endl << "Thank you for using the 1020 Assignment 2 Image Flipper, your new ppm/pgm file is in the directory!" << endl;	
}
