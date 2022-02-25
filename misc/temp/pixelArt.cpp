#include<fstream>
#include"pixelArt.h"

void pixelArt::readArts(string fileName) {
ifstream inFP;
inFP.open(fileName.c_str());

if(inFP.is_open()){
int ia; 
string parse;

while(getline(inFP, parse)){
vector<int> img;
  for(int i = 0; i < w; i++){
  ia = parse[i] - '0';
  img.push_back(ia);
  }
pixels.push_back(img);
}

inFP.close();
}
else{
cout << "Error opening file." << endl;
}
}

pixelArt::pixelArt(int iw, int ih):w(iw),h(ih) {
  h = ih;
  w = iw;
}

int pixelArt::getPixel(int i, int j) {
return pixels[i][j];
}

int pixelArt::getW() {
return w;
}

int pixelArt::getH() {
return h;
}

//OP functions
pixelArt pixelArt::operator + (int num) {
pixelArt x(w, h);

for(int i = 0; i < h; i++){
vector<int> img;
  for(int j = 0; j < w; j++){
  img.push_back(pixels[i][j]);
  }
x.pixels.push_back(img);
}

for(int i = 0; i < h; i++){
  for(int j = 0; j < w; j++){
  x.pixels[i][j] = pixels[i][j] + num;
  }
}

return x;
}

pixelArt pixelArt::operator - (int num) {
pixelArt x(w, h);

for(int i = 0; i < h; i++){
vector<int> img;
  for(int j = 0; j < w; j++){
  img.push_back(pixels[i][j]);
  }
x.pixels.push_back(img);
}

for(int i = 0; i < h; i++){
  for(int j = 0; j < w; j++){
  x.pixels[i][j] = pixels[i][j] - num;
  }
}

return x;
}

pixelArt pixelArt::operator + (const pixelArt& pa) {
pixelArt x(w, h);

for(int i = 0; i < h; i++){
vector<int> img;
  for(int j = 0; j < w; j++){
  img.push_back(pixels[i][j]);
  }
x.pixels.push_back(img);
}

for(int i = 0; i < h; i++){
  for(int j = 0; j < w; j++){
  x.pixels[i][j] = x.pixels[i][j] + pa.pixels[i][j];
  }
}

return x;
}

ostream& operator<<(ostream& os, const pixelArt& pa) {
for (int i = 0; i < pa.h; ++i) {
  for(int j = 0; j < pa.w; ++j) {
    if(pa.pixels[i][j] != 9) {
    os << pa.pixels[i][j];
    }
    else {
    os << " ";
    }
  }
os << endl;
}

return os;
}
