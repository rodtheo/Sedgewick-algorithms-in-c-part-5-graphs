#include <stdio.h>
#include <stdlib.h>
#include "graph_adt.h"

Graph GRAPHinit (int V) {
  int i, j;
  Graph G = malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;

  G->adj = (int **)malloc(V*sizeof(int *));

  for(i=0; i<V; i++)
    *((G->adj)+i) = (int *)malloc(V*sizeof(int));

  for(i=0; i<V; i++)
    for(j=0; j<V; j++)
      G->adj[i][j] = 0;

  return G;
}

void GRAPHinsertE (Graph G, Edge e){
  int v = e.v;
  int w = e.w;

  if (G->adj[v][w] == 0) {
    G->E++;
    G->adj[v][w] = 1;
    // remove the reference above to turn into undirected graph
    // G->adj[w][v] = 1;
  }
}

void GRAPHremoveE (Graph G, Edge e){
  int v = e.v;
  int w = e.w;

  if (G->adj[v][w] == 1){
    G->E--;
    G->adj[v][w] = 0;
    // remove the reference above to turn into undirected graph
    // G->adj[w][v] = 0;
  }
}

int GRAPHedges (Edge a[], Graph G){
  int v, w, E=0;

  for (v = 0; v < G->V; v++)
    for (w = v+1; w < G->V; w++)
      if (G->adj[v][w] == 1)
        a[E++] = EDGE (v, w);
}

Edge EDGE (int v, int w){
  Edge* e = (Edge *)malloc(sizeof(Edge));
  e->v = v;
  e->w = w;

  return *e;
}

void GRAPHshow (Graph G){
  int i, j;
  printf("%d vertices, %d edges\n", G->V, G->E);

  for (i=0; i<G->V; i++){
    printf("%2d:", i);
    for (j=0; j<G->V; j++)
      if (G->adj[i][j] == 1)
        printf(" %2d", j);
      printf ("\n");
  }
}
