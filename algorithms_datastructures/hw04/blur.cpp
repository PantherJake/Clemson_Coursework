#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>
#include <queue>
#include "graphics.h"
using namespace std;

typedef pair<int, int> Node;
Node start;

vector<Node> all_nodes;
map<Node, int> dist;
map<Node, Node> pred;
map<Node, vector<Node>> nbrs;
/* Image code borrowed from our USA map demo... */

struct Pixel {
  unsigned char r, g, b;
};

int width, height;
Pixel *image;

Pixel white = { 255, 255, 255 };
Pixel black = { 0, 0, 0 };

Pixel &get_pixel(int x, int y)
{
  return image[y*width + x];
}

void set_pixel(int i, int j, int distance) {
  image[j*width + i].r = (255 * pow(0.9, distance));
  image[j*width + i].g = (255 * pow(0.9, distance));
  image[j*width + i].b = (255 * pow(0.9, distance));
}

bool operator== (Pixel P1, Pixel P2) {
  if(P1.r == P2.r && P1.g == P2.g && P1.b == P2.b) return true;
  return false;
}

void read_image(const char *filename)
{
  FILE *fp = fopen (filename, "r");
  int dummy = fscanf (fp, "P6\n%d %d\n255%*c", &width, &height);
  image = new Pixel[width * height];
  dummy = fread (image, width*height, sizeof(Pixel), fp);
  fclose (fp);
}

void write_image(const char *filename)
{
  FILE *fp = fopen (filename, "w");
  fprintf (fp, "P6\n%d %d\n255\n", width, height);
  int dummy = fwrite (image, width*height, sizeof(Pixel), fp);
  fclose (fp);
}

/* To be completed from here on... */

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

void calculate_blur(void)
{
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

int main(void)
{
  read_image("paw.ppm");
  calculate_blur();
  write_image("paw2.ppm");
}
