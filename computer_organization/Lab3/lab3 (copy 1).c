#include <stdio.h>
#include <stdlib.h>

struct NODE{
	int a;
	struct NODE *b;
	struct NODE *c;
};

struct NODE 	nodes[5] = {
	{20,	nodes + 3, 	NULL},
	{59,	nodes + 2, 	nodes + 4},
	{8,	NULL,		nodes + 1},
	{44, 	nodes + 4, 	nodes},
	{32, 	nodes + 1, 	nodes + 3}
};

struct NODE  *np  = nodes + 2;
struct NODE  **npp = &nodes[1].b;

int main() {
  printf("nodes:         %p\n", nodes);
  printf("nodes.a:       %d\n", nodes.a);
  printf("nodes[3].a:    %d\n", nodes[3].a);
  printf("nodes[3].c:    %p\n", nodes[3].c);
  printf("nodes[3].c->a: %d\n", nodes[3].c->a);
  printf("*nodes.a:      %p\n", *nodes.a);
  printf("(*nodes).a:    %d\n", (*nodes).a);
  printf("nodes->a:      %d\n", nodes->a);
  printf("nodes[3].b->b: %p\n", nodes[3].b->b);
  printf("&nodes:        %p\n", &nodes);
  printf("&nodes[3].a:   %p\n", &nodes[3].a);
  printf("&nodes[3].c:   %p\n", &nodes[3].c);
  printf("&nodes[3].c->a:%p\n", &nodes[3].c->a);
  printf("&nodes->a:     %p\n", &nodes->a);
  printf("np:            %p\n", np);
  printf("np->a:         %d\n", np->a);
  printf("npp:           %p\n", npp);
  printf("npp->a:        %p\n", npp->a);
  printf("*npp:          %p\n", *npp);
  printf("*npp->a:       %p\n", *npp->a);
  printf("(*npp)->a:     %d\n", (*npp)->a);
  printf("&np:           %p\n", &np);
  return 0;
}
