#include "tweetParser.h"
#include <cstring>
using namespace std;



int main(int argc, char* argv[])
{
if(argc < 2) 
	{
	cout << "Not enough command line arguments." << endl;
	}
else	
	{
	ifstream inFP;
	inFP.open(argv[1]);
	tweetParse(inFP);
	}
}

void tweetParse(ifstream& fp)
{
string readString;

// These strings are default used
const string find = "#typ";
const string find2 = "#det";
const string find3 = "#loc";
const string find4 = "#lat";
const string find5 = "#lng";

string detail;
string reportType;
string latitude;
string location;
double dlatitude
string longitude;
double dlongitude;

for(int i = 0; i < 9; i++) {
getline(fp , readString);
size_t found = readString.find(find);
size_t found2 = readString.find(find2);
size_t found3 = readString.find(find3);
size_t found4 = readString.find(find4);
size_t found5 = readString.find(find5);

reportType = readString.substr(found + 5, (found2 - found - 7));
detail = readString.substr(found2 + 5, (found3 - found2 - 7));
location = readString.substr(found3 + 5, (found4 - found3 - 7));
latitude = readString.substr(found4 + 5, (found5 - found4 - 7));
longitude = readString.substr(found5 + 5);

// Converts string to double in stream so that it can be assigned
stringstream a(latitude);
a >> dlatitude;
stringstream b(longitude);
b >> dlongitude;

// Creating tweet object with details that are read from the file.
tweetParser tweet = tweetParser(reportType , detail , location , dlatitude , dlongitude);

// Prints out the type of tweet with all upper case letters.
cout << "Type:\t\t";
for(int j = 0; j < typ.size(); j++) {
	putchar(toupper(tweet.reportType[j]));
}
cout << endl;

cout << "Detail:\t\t" << tweet.detail << endl;
cout << "Location:\t" << tweet.location << endl;
cout << "Latitude:\t" << tweet.latitude << endl;
cout << "Longitude:\t" << tweet.longitude << endl << endl;
}
}

