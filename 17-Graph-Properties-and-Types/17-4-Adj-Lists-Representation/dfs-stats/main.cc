#include "../IO.cc"
#include "../DFSStats.cpp"

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

  int V = 110217;
  int cntTree, cntBack, cntDown, cntCross;

  SparseMultiGRAPH DAG(V, true);

  IO<SparseMultiGRAPH>::scanEZ (DAG);

  // IO<SparseMultiGRAPH>::show (DAG);

  DFS<SparseMultiGRAPH> dfstat(DAG);

  cntTree = dfstat.get_cntTree();
  cntBack = dfstat.get_cntBack();
  cntDown = dfstat.get_cntDown();
  cntCross = dfstat.get_cntCross();

  cout << "edges tree: " << cntTree << endl;
  cout << "edges back: " << cntBack << endl;
  cout << "edges down: " << cntDown << endl;
  cout << "edges cross: " << cntCross << endl;

  return 0;

}
