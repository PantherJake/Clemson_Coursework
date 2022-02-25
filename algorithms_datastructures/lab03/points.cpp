#include "points.h"
#include <fstream>
#include <iomanip>

using namespace std;

/*int myhash(double d, int b) {
unsigned int h = 0;
for (int i = 0; i < b; ++i) 
	h = (h * 2917 + (unsigned int)d) % b;
return h;
}*/

Points::Points() {
b = 100;

/*int *A = new int[b];
delete [] A;*/
A = new Node** [b];

for (int i = 0; i < b; ++i) 
A[i] = new Node *[b];

for (int i = 0; i < b; ++i) 
	for (int j = 0; j < b; ++j) 
	A[i][j] = NULL;
}

Points::~Points() {
Node *p = new Node();
for (int i = 0; i < b; ++i) {
	for (int j = 0; j < b; ++j) {
		p = A[i][j];
		while(p != NULL) {
			delete p;
			p = p->next;
		}
	}
	delete [] A[i];
}
delete [] A;
}

void Points::insert(double x, double y) {
int xInsert = (int)(x * b);
int yInsert = (int)(y * b);

Node* head;
Node* p;

if (A[xInsert][yInsert] == NULL) {
	head = new Node(x, y, NULL);
	A[xInsert][yInsert] = head;
}
else {
	p = A[xInsert][yInsert];
	if (p->next == NULL) {
		head = new Node(x, y, NULL);
		A[xInsert][yInsert];
	}
	p = p->next;
}

}

/*double Points::dist() {
double uno, dos;
double comp[b];

for (int i = 0; i < b; ++i) {
	for (int j = 0; j < b; ++j) {
		uno = A[i][j];
		dos = A[i+1][j+1];
		tres = A[i+2][j+2];
		quatro = A[i+3][j+3];
	}
	comp[i] = sqrt(pow(tres - uno, 2) + pow(quatro - dos, 2) * 1.0);
}
double scan = comp[0];
for (int i = 0; i < b; ++i) {
if (comp[i+1] < scan) {
scan = comp[i+1];
}
cout << scan << endl;

}*/







