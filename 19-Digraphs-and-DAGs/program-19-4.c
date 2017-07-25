#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "../digraph_adt_adj.h"

#define maxV 13

static int cnt, cntP, pre[maxV], post[maxV];

static int globaldepth;

struct graph {int V; int E; link *adj; int **tc};

void MATRIXinit (int V, int Z, int value){
  int **M = (int **)malloc(V*sizeof(int *));

  for(i=0; i<V; i++)
    *(M+i) = (int *)malloc(V*sizeof(int));

  for(i=0; i<V; i++)
    for(j=0; j<V; j++)
      M[i][j] = value;

  return M;
}

/**
 * Functionally equivalent to Marshall's algorithm for computing transitive
 *  closure of digraphs. Otherwise, this implementation should be use for
 *  sparse digraphs, it computes the transitive
 *  closure by doing a separete DFS starting at each vertex to compute its set
 *  of reachable nodes. With DFS, the running time is proportional to V(V+E)
 *  and the space is proportional to V^2
 * @param G [description]
 * @param e [description]
 */
void TCdfsR (Graph G, Edge e) {
  link t;
  G->tc[e.v][e.w] = 1;
  for (t = G->adj[e.w]; t != NULL; t = t->next)
    if ( G->tc[e.v][t->v] == 0 )
      TCdfsR (G, EDGE (e.v, t->v));
}

void GRAPHtc (Graph G, Edge e){
  int v, w;
  G->tc = MATRIXint (G->V, G->V, 0);
  for (v = 0; v < G->V; v++)
    TCdfsR (G, EDGE (v, v));
}

int GRAPHreach (Graph G, int s, int t){
  return G->tc[s][t];
}


void constructFromStdin (t_lista* lista){
  char linha[1024];
  char v[10];
  char w[10];
  char *eof;
  linha[0] = '\0';
  linha[sizeof(linha)-1] =~ '\0';

  int n = 0;
  int nn;
  eof = fgets (linha, sizeof(linha), stdin);
  // fscanf (stdin, "%s[^\n]", linha);
  char *c = (linha+n);
  int g=0;
  while (1){
    if ((*c == EOF) || (*c == '\0')){break;}
    else {
      printf("g=%d\n", g);
      n = 0;
      while (*c != '-') {
        // printf("%c\n", *c);
        n = n + 1;
        c = (c+1);
      }
      printf("n=%d\n", n);
      strncpy (v, linha+g, n);
      puts (v);

      g = g + n;
      nn = 0;
      printf("nn=%d\n", nn);
      while(!isspace(*c)) {
        // printf("%c\n", *c);
        nn = nn + 1;
        c = (c + 1);
      }

      strncpy (w, linha+g+1, nn);
      puts (w);
      g = g+nn;

      inserir_final(atoi(v), atoi(w), lista);

      memset(v, 0, strlen(v));
      memset(w, 0, strlen(w));

      // add space after edges
      // c = c+1;
      g ++;
    }
    c = c+1;
  }
}


int main(void){

  t_lista*   pLista = get_lista();

  constructFromStdin (pLista);

  int N=13;

  imprime_lista(pLista);

  Graph G = GRAPHinit(N);

  t_elemento *ptr = pLista->primeiro;

  Edge e;

  while (ptr != NULL){
    e = EDGE(ptr->v, ptr->w);
    GRAPHinsertE (G, e);
    ptr = ptr->proximo;
  }

  apagar_lista (pLista);

  GRAPHshow (G);

  e = EDGE(0, 0);

  GRAPHtc (G);

    // Graph R = GRAPHreverse (G);
  //
  // GRAPHshow (R);

  GRAPHdestroy (G);

  return 0;
}
