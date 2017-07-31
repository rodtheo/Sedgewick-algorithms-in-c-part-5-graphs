#include "../IO.cc"

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

  int V = 10;
  SparseMultiGRAPH G(V);

  IO<SparseMultiGRAPH>::scanEZ (G);

  IO<SparseMultiGRAPH>::show (G);

  return 0;
}
