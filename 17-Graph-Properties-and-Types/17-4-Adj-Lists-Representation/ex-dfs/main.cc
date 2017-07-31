#include "../IO.cc"
#include "../DFS.cpp"

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

  int V = 13;

  SparseMultiGRAPH DAG(V, true);

  IO<SparseMultiGRAPH>::scanEZ (DAG);

  IO<SparseMultiGRAPH>::show (DAG);

  new DFS<SparseMultiGRAPH> (DAG);

  return 0;

}
