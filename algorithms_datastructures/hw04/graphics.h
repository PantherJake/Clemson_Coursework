#ifndef GRAPHICS_H
#define GRAPHICS_H

#define  KEY_LEFT       0x0164
#define  KEY_UP         0x0165
#define  KEY_RIGHT      0x0166
#define  KEY_DOWN       0x0167

void set_color(int r, int g, int b); // Each in range 0..255
void draw_pixel (int x, int y);      // (0,0) is top-left corner
void draw_line (int x1, int y1, int x2, int y2); 

int init_graphics(int argc, char **argv,
		  int window_xsize, int window_ysize,
		  void (* render)(void),
		  void (* keyhandler)(int key),
		  bool (* timerhandler)(int msec));

#endif
