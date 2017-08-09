#include "../../17-Graph-Properties-and-Types/17-4-Adj-Lists-Representation/IO.cc"
#include "BubbleSC.cc"

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
  // when using runl.sh please uncomment line bellow
  // int V = 13;
  int V = 9;

  SparseMultiGRAPH DAG(V, true);

  IO<SparseMultiGRAPH>::scanEZ (DAG);

  // IO<SparseMultiGRAPH>::show (DAG);

  delBack<SparseMultiGRAPH> *d;

  d = new delBack<SparseMultiGRAPH>(DAG, 0);

  // d = new DFS<SparseMultiGRAPH>(DAG);

  IO<SparseMultiGRAPH>::show (DAG);

  inTS<SparseMultiGRAPH> in_top(DAG);

  cout << "NOVO" << endl ;

  SparseMultiGRAPH *ord;
  //
  //

  ord = in_top.get_ordered_graph();

  IO<SparseMultiGRAPH>::show (*ord);

  

  // dagTS<SparseMultiGRAPH> ts(DAG);
  //
  // cout << "index  ";
  // for (int v=0; v < DAG.V(); v++)
  //   cout << v << " ";
  // cout << endl;
  //
  // cout << "ts   ";
  // for (int v=0; v < DAG.V(); v++)
  //   cout << ts.relabel(v) << " ";
  // cout << endl;
  //
  //
  // cout << "tsI  ";
  // for (int v=0; v < DAG.V(); v++)
  //   cout << ts[v] << " ";
  //
  // cout << endl;

//   for (int v=0; v < V; v++){
//     cout << v << " : ";
//     d->printStatus(v);
// }

  return 0;

}
