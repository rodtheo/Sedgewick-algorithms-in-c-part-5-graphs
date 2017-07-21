// #include "graph_adt_matrix.h"
#include "graph_adt_adj.h"
#include <stdio.h>

int main(){
  Graph G = GRAPHinit(4);
  Edge e = EDGE (0, 1);

  GRAPHinsertE (G, e);
  e = EDGE(0, 2);
  GRAPHinsertE (G, e);
  e = EDGE(1, 3);
  GRAPHinsertE (G, e);
  e = EDGE(2, 3);
  GRAPHinsertE (G, e);
  e = EDGE(0, 2);
  GRAPHinsertE (G, e);
  // Edge liste[G->E];
  // int j;
  // j = GRAPHedges(liste, G);
  //
  // int i;
  // for(i=0; i<G->E; i++)
  //   printf("%2d -> %2d\n", liste[i].w, liste[i].v);
  // printf("edges: %d", G->E);
  GRAPHshow(G);
  e = EDGE(2, 0);
  GRAPHremoveE (G, e);

  printf("\n\n");
  GRAPHshow(G);

  return 0;
}
