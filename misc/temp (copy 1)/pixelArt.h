#include<iostream>
#include<vector>
#include<string>

using namespace std;



class pixelArt
{
public:
    pixelArt(int w, int h);
    int getW();
    int getH();
    int getPixel(int i, int j);
    void readArts(string fileName);
    pixelArt operator + (int num); 
    pixelArt operator - (int num); 
    pixelArt operator + (const pixelArt& pa); 
    friend ostream& operator<<(ostream& os, const pixelArt& pa);
private:
    vector<vector<int> > pixels;
    int w;
    int h;
};

void output(pixelArt& pa);


