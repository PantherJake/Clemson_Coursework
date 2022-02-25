#include "tweetParser.h"
using namespace std;

void tweetParse(ifstream& fp);

int main(int argc, char* argv[]) {
// inFP pointer is made to pass to tweet parse function.
ifstream inFP;
inFP.open(argv[1]);
tweetParse(inFP);
}

//Implementation of tweetParse function.
void tweetParse(ifstream& fp) {
string readString;

// These strings are default used
const string find = "#typ";
const string find1 = "#det";
const string find2 = "#loc";
const string find3 = "#lat";
const string find4 = "#lng";

string detail;
string reportType;
string location;

string latitude;
double dlatitude;

string longitude;
double dlongitude;

for(int i = 0; i < 9; i++) {
getline(fp, readString);

size_t found = readString.find(find);
size_t found1 = readString.find(find1);
size_t found2 = readString.find(find2);
size_t found3 = readString.find(find3);
size_t found4 = readString.find(find4);

reportType = readString.substr(found + 5, (found1 - found - 7));
detail = readString.substr(found1 + 5, (found2 - found1 - 7));
location = readString.substr(found2 + 5, (found3 - found2 - 7));
latitude = readString.substr(found3 + 5, (found4 - found3 - 7));
longitude = readString.substr(found4 + 5);

// Converts string to double in stream so that it can be assigned
stringstream a(latitude);
a >> dlatitude;

stringstream b(longitude);
b >> dlongitude;

// Creating tweet object with details that are read from the file.
tweetParser tweet = tweetParser(reportType, detail, location, dlatitude, dlongitude);

// Prints out the type of tweet with all upper case letters.
cout << "Type:\t\t";
for(int j = 0; j < reportType.size(); j++) {
	putchar(toupper(tweet.reportType[j]));
}
cout << endl;

cout << "Detail:\t\t" << tweet.detail << endl;
cout << "Location:\t" << tweet.location << endl;
cout << "Latitude:\t" << tweet.latitude << endl;
cout << "Longitude:\t" << tweet.longitude << endl << endl;
}
}

