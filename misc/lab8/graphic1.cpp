#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
int h = 480;
int w = 640;
int tid;
int numCores;
FILE* outFile;

float R[h][w];
float G[h][w];
float B[h][w];

#pragma omp parallel private(tid) 
{
if ((tid = omp_get_thread_num()) == 0) 
numCores = omp_get_num_threads();
}

fprintf(stderr, "Num of Cores: %d\n", numCores);
int chunk = h / numCores;

fprintf(stderr, "H: %d\n", h);
fprintf(stderr, "Chunk (%d/%d): %d\n", h, numCores, chunk);

#pragma omp parallel \
shared(w, h, R, G, B) \
private(tid)

#pragma omp for schedule(static, chunk) nowait

for (int y = h - 1; y >= 0; --y) {
	for (int x = 0; x < w; ++x) {
	tid = omp_get_thread_num();

	switch(tid % 7) {
	case 1:
	R[y][x] = 1.0;
	G[y][x] = 0.0;
	B[y][x] = 0.0;
	break;
	case 2:
	R[y][x] = 1.0;
	G[y][x] = 1.0;
	B[y][x] = 0.0;
	break;
	case 3:
	R[y][x] = 1.0;
	G[y][x] = 1.0;
	B[y][x] = 1.0;
	break;
	case 4:
	R[y][x] = 0.0;
	G[y][x] = 1.0;
	B[y][x] = 1.0;
	break;
	case 5:
	R[y][x] = 0.0;
	G[y][x] = 0.0;
	B[y][x] = 1.0;
	break;
	default:i][j]
	R[y][x] = 1.0;
	G[y][x] = 0.0;
	B[y][x] = 1.0;
	break;
	}
}
}

outFile = fopen("color.ppm", "w");
if (!out) {
printf("Error. Cannot open image.");
return -1;
}

fprintf(outFile, "P6\n%d %d\n255\n", w, h);
for (int i = 0; i < h; ++i) {
	for (int j = 0; j < w; ++j) {
		char r = (unsigned char) (R[i][j] * 255.0);
		char g = (unsigned char) (G[i][j] * 255.0);
		char b = (unsigned char) (B[i][j] * 255.0);
		
		fwrite(&r, sizeof(unsigned char), 1, outFile);
		fwrite(&g, sizeof(unsigned char), 1, outFile);
		fwrite(&b, sizeof(unsigned char), 1, outFile);
		}
	}
}





