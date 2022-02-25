#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
/* Initializing dimensions for the ppm image with h and w and initializing the variables
to store the number of cores along with the file pointer to write a ppm image in */
int h = 480;
int w = 640;
int tid;
int ncores;
FILE* outFile;

/* Variables used to store the color selections */
float R[h][w];
float G[h][w];
float B[h][w];

/* This tests to make sure that the operation is working correctly and if it is
the ncores variable is assigned to the number of working cores */
#pragma omp parallel private(tid) 
{
if ((tid = omp_get_thread_num()) == 0) 
ncores = omp_get_num_threads();
}

/* This is printed to the terminal so that the user can see the number of cores working
the height of the image and the chunks */
fprintf(stderr, "Num of Cores: %d\n", ncores);
int chunk = h / ncores;

fprintf(stderr, "H: %d\n", h);
fprintf(stderr, "Chunk (%d/%d): %d\n", h, ncores, chunk);

#pragma omp parallel \
shared(w, h, R, G, B) \
private(tid)

#pragma omp for schedule(static, chunk) nowait

/* This operation distributes the color of the ppm image to different cores so
that each core is working on a part of the ppm image */
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
	default:
	R[y][x] = 1.0;
	G[y][x] = 0.0;
	B[y][x] = 1.0;
	break;
	}
}
}

/* Here is the code for writing the ppm image into the file */
outFile = fopen("color.ppm", "w");
if (!outFile) {
printf("Error in opening output image.");
return -1;
}

/*Header for ppm image along with code for writing it */
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





