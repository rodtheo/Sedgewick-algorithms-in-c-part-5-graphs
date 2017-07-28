#include <string>
#include <iostream>
#include <cstring>
#include "denseGRAPH.cc"
using namespace std;

template<class Graph>

class IO {
  public:
    static void show (const Graph&);

    static void scanEZ (Graph &);

    static void scan (Graph &);
};

template<class Graph>
void IO<Graph>::show (const Graph& G){
  int i, j;
  Edge e;

  for (i = 0; i < G.V(); i++)
    for (j = 0; j < G.V(); j++){
      e = Edge(i, j);
      cout << G.edge(e) << " ";}
    cout << endl;
}

template<class Graph>
void IO<Graph>::scanEZ (Graph & G){

  string linha;

  getline(cin, linha);

  cout << "linha=" << linha << endl;

  unsigned int n = 0;
  char *c = (linha+n);
  int g = 0;

  while (1) {
    if ((*c == EOF) || (*c == '\0')) {break;}
    else {
      cout << "g=" << g << endl;
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

int main(){

  int V = 20;
  DenseGRAPH G(V);

  IO<DenseGRAPH>::scanEZ (G);

  // IO<DenseGRAPH>::show (G);


  return 0;
}
