#include <fstream>
#include "pixelArt.h"
using namespace std;

int pixelArt::getPixel(int w, int h) {
return pixels[w][h];
}

int pixelArt::getHeight() {
return h;
}

int pixelArt::getWidth() {
return w;
}
// - OPERATOR
pixelArt pixelArt::operator - (int n) {
pixelArt x(w, h);
for(int i = 0; i < h; ++i) {
vector<int> img;
	for (int j = 0; j < w; ++j) {
	img.push_back(pixels[i][j]);
	}
x.pixels.push_back(img);
}
for (int i = 0; i < h; ++i) {
	for (int j = 0; j < w; ++j) {
	x.pixels[i][j] = pixels[i][j] - n;
	}
}

return x;
}

// + OPERATOR
pixelArt pixelArt::operator + (int n) {
pixelArt x(w, h);

for (int i = 0; i < h; i++) {
vector<int> img;
	for (int j = 0; j < w; j++) {
	img.push_back(pixels[i][j]);
	}
x.pixels.push_back(img);
}

for (int i = 0; i < h; ++i) {
	for (int j = 0; j < w; ++j) {
	x.pixels[i][j] = pixels[i][j] + n;
	}
}

return x;
}

pixelArt pixelArt::operator + (const pixelArt& x) {
pixelArt y(w, h);

for (int i = 0; i < h; ++i) {
vector<int> img;
	for (int j = 0; j < w; ++j) {
	img.push_back(pixels[i][j]);
	}
y.pixels.push_back(img);
}

for (int i = 0; i < h; ++i) {
	for (int j = 0; j < w; ++j) {
	y.pixels[i][j] = y.pixels[i][j] + x.pixels[i][j];
	}
}

return y;
}

// << OPERATOR
ostream& operator << (ostream& os, const pixelArt& x) {
for (int i = 0; i < x.h; ++i) {
	for (int j = 0; j < x.w; ++j) {
		if (x.pixels[i][j] != 9) {
		os << x.pixels[i][j];
		}
		else {
		os << " ";
		}
	}
os << endl;
}
return os;
}

//Read Function
void pixelArt::readArts(string filename) {
ifstream inFP;
inFP.open(filename.c_str());

if (inFP.is_open()) {
string parse, int a;

while(getline(inFP, parse)) {
vector<int> img;
	for (int i = 0; i < w; ++i) {
	a = parse[i] - '0';
	img.push_back(a);
	}
pixels.push_back(img);
}
inFP.close();
}
else {
cout << "File opening error." << endl;
}
}
	




