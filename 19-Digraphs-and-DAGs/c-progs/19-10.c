#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "../digraph_adt_adj.h"

#define maxV 13

static int cnt, cntP, pre[maxV], post[maxV];

static int globaldepth;

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

/**
 * Utility function used in Depth-first search implementation to printf
 *  spaces proportional to the level of recursion of the algorithm.
 * @param e          Edge
 * @param typeOfEdge String with the classification of the edge
 * @param depth      Number of spaces to print before the content
 */
void show (Edge e, char *typeOfEdge, int depth) {
  printf("%*c%d-%d %s\n", depth, ' ', e.v, e.w, typeOfEdge);
}

/**
 * Depth-first search recursion algorithm for digraphs. It classifies the
 *  edges into 4 types described in Sedgewick. The implementation is based
 *   on program 19.3. The running time is proportional to (V+E)
 * @param G Pointer for the graph structure
 * @param e Starting edge to compute the dfs-tree
 */
void dfsR (Graph G, Edge e){
  link t;
  int i, v;
  int w = e.w;
  Edge x;

  // printf ("tree %d-%d\n", e.v, e.w);
  show (e, "tree", globaldepth);
  globaldepth = globaldepth + 3;
  pre[w] = cnt ++;
  // printf("pre[%d]=%d\n", w, pre[w]);
  for (t = G->adj[w]; t != NULL; t = t->next){
    if (pre[t->v] == -1){
      // printf("w=%d & pre[%d] == -1\n", w, t->v);
      // globaldepth = globaldepth + 3;
      dfsR (G, EDGE (w, t->v));
    }
    else
      {
        v = t->v;
        x = EDGE (w, v);
        if (post[v] == -1)
          // printf("back %d->%d\n", x.v, x.w);
          show (x, "back", globaldepth);
        else if (pre[v] > pre[w])
          // printf("down %d->%d\n", x.v, x.w);
          show (x, "down", globaldepth);
        else
          // printf("cross %d->%d\n", x.v, x.w);
          show (x, "cross", globaldepth);
      } // end else
    } // end for
  post[w] = cntP++;
  globaldepth = globaldepth - 3;
}

void initializeDfsR (Graph G){
  // Test with echo '4-2 2-3 3-2 0-6 0-1 2-0 11-12 12-9 9-10 9-11 8-9 10-12 4-11 4-3 3-5 7-8 8-7 5-4 0-5 6-4 6-9 7-6' | ./19-10.x
  cnt = 0;
  cntP = 0;
  globaldepth = 0;
  int v;
  for (v = 0; v < G->V; v++){
    pre[v] = -1; post[v] = -1;
  }
  for (v = 0; v < G->V; v++)
    if (pre[v] == -1)
      dfsR (G, EDGE (v, v));
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

  initializeDfsR (G);

  int v;

  printf("\n");

  // dfsR (G, e);

  for(v=0; v<maxV; v++)
    printf("post[%d]=%d -- pre[%d]=%d ", v, post[v], v, pre[v]);

  // Graph R = GRAPHreverse (G);
  //
  // GRAPHshow (R);

  GRAPHdestroy (G);

  return 0;
}
