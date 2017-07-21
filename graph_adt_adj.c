#include <stdlib.h>
#include "graph_adt_adj.h"
#include <stdio.h>

typedef struct node *link;
struct node {int v; link next;};
struct graph {int V; int E; link *adj;};

link NEW (int v, link next){
  link x = malloc(sizeof *x);
  x->v = v;
  x->next = next;
  return x;
}

Graph GRAPHinit (int V){
  int v;
  Graph G = malloc(sizeof *G);
  G->V = V;
  G->E = 0;

  G->adj = (link *)malloc(V*sizeof(link));
  for(v=0; v<V; v++)
    G->adj[v] = NULL;
  return G;
}

void GRAPHinsertE (Graph G, Edge e){
  int v = e.v;
  int w = e.w;

  G->adj[v] = NEW (w, G->adj[v]);
  G->adj[w] = NEW (v, G->adj[w]);

  G->E++;
}


int GRAPHedges (Edge a[], Graph G){
  int v, E=0;
  link t;

  for (v=0; v<G->V; v++)
    for (t = G->adj[v]; t != NULL; t = t->next)
      if (v < t->v)
        a[E++] = EDGE (v, t->v);
  return E;
}

Edge EDGE (int v, int w){
  Edge* e = (Edge *)malloc(sizeof(Edge));
  e->v = v;
  e->w = w;

  return *e;
}

void GRAPHshow (Graph G){
  int v;
  link t;
  printf("%d vertices, %d edges\n", G->V, G->E);

  for(v=0; v < G->V; v++){
    printf("%2d: ", v);
    for(t = G->adj[v]; t != NULL; t = t->next)
      printf(" %2d", t->v);
    printf("\n");
    }
}




void GRAPHremoveE (Graph G, Edge e){
  int v = e.v;
  int w = e.w;
  int i;
  link s, t;

  // Lets delete all vertices w within v's adjacency list
  // this includes the duplicates entries
  s = t = G->adj[v];

  for (t = G->adj[v]; t != NULL; t = t->next) {
    if (t->v == w) {
      if (t == G->adj[v]){
        G->adj[v] = t->next;
      }
      else{
        s->next = t->next;}
      free (t);
    }
    s = t;
  }

  // In a symmetric way lets delete the vertices v's contained in w
  //  adjacency list
  s = t = G->adj[w];

  for (t = G->adj[w]; t != NULL; t = t->next) {
    if (t->v == v) {
      if (t == G->adj[w]){
        G->adj[w] = t->next;
      }
      else{
        s->next = t->next;}
      free (t);
    }
    s = t;
  }

  G->E--;
}

void GRAPHdestroy (Graph G){
  int v;
  link s, t;

  for (v = 0; v < G->V; v++){
    s = G->adj[v];
    // for (t = s->next; t != NULL; t = t->next)
    while (s != NULL) {
      G->adj[v] = G->adj[v]->next;

      free (s);

      s = G->adj[v];
    } // end while
  } // end for

  free (G->adj);
}
