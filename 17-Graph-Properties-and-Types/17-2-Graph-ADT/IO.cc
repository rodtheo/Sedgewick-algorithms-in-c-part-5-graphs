#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "denseGRAPH.cpp"

using namespace std;

template<class Graph>
class IO {
  public:
    static void show (Graph &);

    static void scanEZ (Graph &);

    static void scan (Graph &);
};


template<class Graph> void IO<Graph>::show (Graph& G){
  int i, j;
  Edge e;

  for (i = 0; i < G.V(); i++){
    for (j = 0; j < G.V(); j++){
      e = Edge(i, j);
      cout << G.edge(e) << " ";}
    cout << "\n";
  }
}
