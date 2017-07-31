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

void SparseMultiGRAPH::remove (Edge e)
{
  int v = e.v, w = e.w;
  link s, t;
  int i;

  // Lets delete all vertices w within v's adjacency list
  // this includes the duplicates entries
  s = t = adj[v];

  for (t = adj[v]; t != NULL; t = t->next) {
    if (t->v == w) {
      // cout << "achado w = " << w << endl;
      if (t == adj[v]){
        adj[v] = t->next;
      }
      else{
        s->next = t->next;}
      free (t);
    }
    s = t;
  }


  if ( !digraph ) {
    for (t = adj[w]; t != NULL; t = t->next) {
      if (t->v == v) {
        // cout << "achado w = " << w << endl;
        if (t == adj[w]){
          adj[w] = t->next;
        }
        else{
          s->next = t->next;}
        free (t);
      }
      s = t;
    }
  } // end is directed

}

int main(){

  int V = 10;

  SparseMultiGRAPH G(V);

  IO<SparseMultiGRAPH>::scanEZ (G);

  IO<SparseMultiGRAPH>::show (G);

  Edge e = Edge(3, 7);

  cout << "Removing edge 3-7" << endl;

  G.remove (e);

  cout << "Showing new graph with removed edge..." << endl;

  IO<SparseMultiGRAPH>::show (G);

  return 0;
}
