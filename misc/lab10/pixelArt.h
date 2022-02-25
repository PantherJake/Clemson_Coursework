#include <iostream>
#include <string>
#include <vector>
using namespace std;

class pixelArt {
private:
vector<vector<int>> pixels;
int w;
int h;

public:
pixelArt(int w, int h) {
this->w = w;
this->h = h;
}

int getWidth();
int getHeight();
int getPixel(int w, int h);
void readArts(string filename);
friend ostream& operator << (ostream& os, const pixelArt& x);
pixelArt operator - (int n);
pixelArt operator + (int n);
pixelArt operator + (const pixelArt& x);
};

void out(pixelArt& x);
	
