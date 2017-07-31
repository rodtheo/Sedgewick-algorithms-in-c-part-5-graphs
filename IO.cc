#include <string>
#include <iostream>
#include <vector>
#include "denseGRAPH.cc"
using namespace std;

template<class Graph>
class IO {
  public:
    static void show (Graph&);

    static void scanEZ (Graph &);

    static void scan (Graph &);
};

template<class Graph> void IO<Graph>::show (Graph& G){
  int i, j;
  Edge e;

  for (i = 0; i < G.V(); i++)
    for (j = 0; j < G.V(); j++){
      e = Edge(i, j);
      cout << G.edge(e) << " ";}
    cout << endl;
}

template<class Graph> void IO<Graph>::scanEZ (Graph & G){

    vector<int> v;
    vector<int> w;

    Edge e;

    int n;
    // int v, w;
    int i = 0;
    while (cin >> n)
    {
      if (i%2 == 0){
        cout << n << endl;
        v.push_back (static_cast<int>(n));}
      else{
        cout << abs(n) << endl;
        w.push_back (static_cast<int>(abs(n)));}
      i++;
     }

     for (i=0; i < v.size(); i++)
      {
        e = Edge (v[i], w[i]);
        G.insert (e);
        cout << e.v << " -> " << e.w << endl;
      }

}

int main(){

  int V = 20;
  DenseGRAPH G(V);

  IO<DenseGRAPH>::scanEZ (G);

  IO<DenseGRAPH>::show (G);


  return 0;
}
