/*#ifndef GRAYPIXEL_H
#define GRAYPIXEL_H
#include <string>
using namespace std;

class GrayPixel
{
	private:
		string gray;

	public:
		GrayPixel();
		GrayPixel(string g)
		{
		string  = g;
		}
		float getGray() {return gray;}	
		~GrayPixel();
};

#endif*/

#ifndef GRAYPIXEL_H
#define GRAYPIXEL_H
#include <string>
using namespace std;

class GrayPixel
{
	private:
		string gray;

	public:
		GrayPixel();
		GrayPixel(string g)
		{
		gray = g;
		}
		string getGray() {return gray;}	
		~GrayPixel();
};

#endif
