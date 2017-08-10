#include "../../../17-Graph-Properties-and-Types/17-4-Adj-Lists-Representation/IO.cc"
#include "dagTS.cc"

using namespace std;

template<class Graph> void IO<Graph>::show (Graph& G){
  for (int s=0; s < G.V(); s++)
  {
    cout.width(2);
    cout << s << ":";
    typename Graph::adjIterator A(G, s);
    for (int t = A.beg(); !A.end(); t = A.nxt())
    {
      cout.width(2);
      cout << t << " ";
    }
    cout << endl;
  }
}

int main(){
  // Default
  int V = 6;
  // int V = 10;

  SparseMultiGRAPH D(V, true);

  IO<SparseMultiGRAPH>::scanEZ (D);


  dagTS<SparseMultiGRAPH> ts(D);

  cout << "index  ";
  for (int v=0; v < D.V(); v++)
    cout << v << " ";
  cout << endl;

  cout << "ts   ";
  for (int v=0; v < D.V(); v++)
    cout << ts.relabel(v) << " ";
  cout << endl;


  cout << "tsI  ";
  for (int v=0; v < D.V(); v++)
    cout << ts[v] << " ";

  cout << endl;

  return 0;
}
