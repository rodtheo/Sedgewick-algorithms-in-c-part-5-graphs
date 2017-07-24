#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "../digraph_adt_adj.h"

static int cnt, cntP, pre[maxV], post[maxV];

void dfsR (Graph G, Edge e){
  link t;
  int i, v;
  w = e.w;
  Edge x;

  printf ("tree");
  pre[w] = cnt ++;
  for (t = G->adj[w]; t != NULL; t = t->next)
    if (pre[t->v] == -1)
      dfsR (G, EDGE (w, t->v));
    else
      {
        v = t->v;
        x = EDGE (w, v);
        if (post[v] == -1)
          printf("back %d->%d", x.v, x.w);
        else if (pre[v] > pre[w])
          printf("down %d->%d", x.v, x.w);
        else
          printf("cross %d->%d", x.v, x.w);
      }
  post[w] = cntP++;
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

  int N;


  imprime_lista(pLista);

  N = tamanho_lista(pLista);

  Graph G = GRAPHinit(N);

  t_elemento *ptr = pLista->primeiro;

  Edge e;

  while (ptr != NULL){
    e = EDGE(ptr->v, ptr->w);
    GRAPHinsertE (G, e);
    ptr = ptr->proximo;
  }

  apagar_lista(pLista);

  GRAPHshow(G);

  Graph R = GRAPHreverse (G);

  GRAPHshow(R);

  GRAPHdestroy (G);

  return 0;
}
