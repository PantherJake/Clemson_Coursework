#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include "graphics.h"
using namespace std;

/* Image code borrowed from our USA map demo... */
typedef pair<int, int> Node;
Node start;

vector<Node> all_nodes;
map<Node, int> dist;
map<Node, Node> pred;
map<Node, vector<Node>> nbrs;

struct Pixel {
  unsigned char r, g, b;
};

int width, height;
Pixel *image;

Pixel white = { 255, 255, 255 };
Pixel black = { 0, 0, 0 };
Pixel red = { 255, 0, 0 };

bool operator== (Pixel &a, Pixel &b) {
  return a.r==b.r && a.g==b.g && a.b==b.b;
}
bool operator!= (Pixel &a, Pixel &b) {
  return !(a==b);
}

Pixel &get_pixel(int x, int y)
{
  return image[y*width + x];
}

void read_image(const char *filename)
{
  FILE *fp = fopen (filename, "r");
  int dummy = fscanf (fp, "P6\n%d %d\n255%*c", &width, &height);
  image = new Pixel[width * height];
  dummy = fread (image, width*height, sizeof(Pixel), fp);
}

void set_pixel_red(int i, int j) {
  image[j*width + i].r = (255);
  image[j*width + i].g = (0);
  image[j*width + i].b = (0);
}

// Import this from your solution to the first part...
void set_pixel(int i, int j, int distance) {
  image[j*width + i].r = (255 * pow(0.9, distance));
  image[j*width + i].g = (255 * pow(0.9, distance));
  image[j*width + i].b = (255 * pow(0.9, distance));
}

void draw_blur() {
  Node x;
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      x = make_pair(i, j);
      set_pixel(i, j, dist[x]);
    }
  }
}

void bfs(Node source) {
  for(Node &a : all_nodes) dist[a] = all_nodes.size();
  dist[source] = 0;
  queue<Node> to_visit;

  to_visit.push(source);

  while(!to_visit.empty()) {
    Node x = to_visit.front();
    to_visit.pop();
    for(Node n : nbrs[x])
      if(dist[n] == all_nodes.size()) {
        //cout << dist[x] << endl;
        dist[n] = 1 + dist[x];
        pred[n] = x;
        to_visit.push(n);
      }
  }
}

bool seam_exists(void)
{
  for (int x=0; x<width; x++) if (get_pixel(x,0) == red) return true;
  return false;
}

void calculate_blur(void) {
  // Initializes all_nodes, sets distance of black equal to -1 & white equal to 0, and finds the start
  Node temp;
  for(int i = 0; i < height; ++i)
    for(int j = 0; j < width; ++j) {
      temp = make_pair(i, j);
      all_nodes.push_back(make_pair(i, j));
      if(get_pixel(i, j) == white) {
        dist[temp] = 0;
        start = make_pair(i, j);
      }
      else {
        dist[temp] = -1;
      }
    }

  // Mega Node Neighbor Initialization
  for(int i = 0; i < height; ++i)
    for(int j = 0; j < width; ++j)
      if(get_pixel(i, j) == white) {
        nbrs[start].push_back(make_pair(i, j));
      }

  // Initializes Neighbors
  int di[] = {+1, -1, 0, 0};
  int dj[] = {0, 0, +1, -1};
  for(int i = 1; i < height-1; ++i)
    for(int j = 1; j < width-1; ++j)
      for(int k = 0; k < 4; ++k) {
        Node x = make_pair(i, j);
        Node nbr = make_pair(i + di[k], j + dj[k]);
        if(nbr.first < 255528 && nbr.second < 255528) {
          //cout << "Found da snow" << endl;
          nbrs[x].push_back(nbr);
        }
      }

  // Finds each neighbor for each pixel
  bfs(start);

  //Draws blur
  draw_blur();
return;
}

void remove_seam(void)
{
  cout << "Removing seam to decrease width to " << width-1 << "\n";
  for (int y=0; y<height; y++) {
    int where_red = -1;
    for (int x=0; x<width; x++)
      if (get_pixel(x,y) == red)
	if (where_red!=-1) { cout << "Error: row " << y << " hass >1 red pixel set\n"; exit(0); }
	else where_red = x;
    if (where_red == -1) { cout << "Error: row " << y << " has 0 red pixels set\n"; exit(0); }
    for (int x=where_red; x<width-1; x++) get_pixel(x,y) = get_pixel(x+1,y);
  }

  // Create a new image with one smaller width
  Pixel *orig_image = image;
  width--;
  image = new Pixel[height * width];
  for (int x=0; x<width; x++)
    for (int y=0; y<height; y++)
	  get_pixel(x,y) = orig_image[y*(width+1)+x];
  delete [] orig_image;

  calculate_blur();
}

void calculate_seam(void) {
Node x;

for(int i = 0; i < height; ++i) {
  for(int j = 0; j < width; ++j) {
    x = make_pair(i, j);
    if(x == nbrs[x].back()) set_pixel_red(i, j);
  }
}
}

// To be written -- solve a shortest path problem to find a seam and color it red

/* Code to find and remove seams */

/* Simple 2D interactive graphics code... */

bool show_blurred_image = false;

// Called on each keypress
void keyhandler(int key)
{
  if (key == 'q') exit(0);

  // Toggle showing blurred image (off-white pixels)
  if (key == 'b') show_blurred_image = !show_blurred_image;

  // Find and remove one seam
  if (key == 's' && !seam_exists()) calculate_seam();

  // Find and remove 2...9 seams
  if ((key >= '2' && key <= '9') && !seam_exists())
    for (int i=0; i<key-'0'; i++) { calculate_seam(); remove_seam(); }
}

// Called any time the scene needs to be re-rendered
void render(void)
{
  // Always plot white and red pixels.  Show all other pixels if blur
  // mode is toggled on
  for (int x=0; x<width; x++)
    for (int y=0; y<height; y++) {
      Pixel p = get_pixel(x, y);
      if (show_blurred_image || p == white || p == red) {
	set_color (p.r, p.g, p.b);
	draw_pixel(x, y);
      }
    }

  // Fill in empty space at right from shrinking the image with blue
  set_color(0, 0, 255);
  for (int x=width; x<800; x++)
    draw_line (x,0,x,height-1);
}

// Called periodically (msec is amount of time since last called)
// Return true if a re-render is needed
// Right now this function waits a second after finding a seam to
// remove it (allowing it to be visualized briefly)
bool timer(int msec)
{
  static int cumulative = 0;
  static bool found_seam = false;
  cumulative += msec;
  if (cumulative > 1000) {
    cumulative -= 1000;
    if (seam_exists()) {
      if (found_seam) {
	remove_seam();
	found_seam = false;
	return true;
      }
      found_seam = true;
    }
  }
  return false;
}

int main(int argc, char *argv[])
{
  read_image("billboard.ppm");
  calculate_blur();
  init_graphics(argc, argv, width, height, render, keyhandler, timer);
}
