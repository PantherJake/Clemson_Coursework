#include "ppm.h"
#include "pgm.h"

class Replicator {
	private: 
		static Replicator* instance;
		int data;
	public:
		Replicator();

		ppm rColorPixel(ifstream& fp);
		void wColorPixel(ofstream& fp, ppm a);

		pgm rGrayPixel(ifstream& fp);
		void wGrayPixel(ofstream& fp, pgm a);

		void BinaryGray(ifstream& fp);
};



