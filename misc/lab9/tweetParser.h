#ifndef TWEETPARSER_H 
#define TWEETPARSER_H

#include <sstream>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class tweetParser {
	private:
 
	public: 
	tweetParser();
	//Parameterized constructor to hold values
	tweetParser(string, string, string, double dlatitude, double dlongitude) {
	this->reportType = reportType;
	this->detail = detail;
	this->location = location;
	this->latitude = dlatitude;
	this->longitude = dlongitude;
	}

	// Variables that the constructor will initialize.
	string detail;
	string reportType;
	string location;
	double longitude;
	double latitude;
};	
	
#endif
