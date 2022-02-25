#include "graphic.h"
using namespace std;

int main() {
    make_image();
}

void make_image() {
for (int y = h - 1; y >= 0; y--) {
    for (int x = 0; x < w; x++) {
        R[y][x] = 0.0;
        G[y][x] = 1.0;
        B[y][x] = 0.0;
    }
}

out = fopen("color.ppm", "w");
if (!out) {
    printf("Error in opening the image\n");
    return;
}

fprintf(out, "P6\n%d %d\n255\n", w, h);
for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
        r = (unsigned char)(R[i][j] * 255.0);
        g = (unsigned char)(G[i][j] * 255.0);
        b = (unsigned char)(B[i][j] * 255.0);

        fwrite(&r, sizeof(unsigned char), 1, out);
        fwrite(&g, sizeof(unsigned char), 1, out);
        fwrite(&b, sizeof(unsigned char), 1, out);
    }
}
}