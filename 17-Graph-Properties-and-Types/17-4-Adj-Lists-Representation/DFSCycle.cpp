#include <iostream>
#include "sparseMultiGRAPH.cpp"
using namespace std;

template <class Graph> class DFSCycle
{
  const Graph &G;
  int depth, cnt, cntP;
  vector<int> pre, post;
  bool hasCycle;

  void show (char *a, Edge e)
  {
    for (int i=0; i < depth; i++) cout << " ";
    cout << e.v << "-" << e.w << a << endl;
  }

  bool dfsR (Edge e)
  {
    int w = e.w;
    show (" tree", e);
    pre[w] = cnt++;
    depth++;

    if (hasCycle == true)
      return hasCycle;

    typename Graph::adjIterator A(G, w);
    for (int t = A.beg(); !A.end(); t = A.nxt())
    {
      Edge x(w, t);
      if (pre[t] == -1) dfsR (x);
      else if (post[t] == -1) {show (" back", x); hasCycle = true; break;}
      else if (pre[t] > pre[w]) show (" down", x);
      else show (" cross", x);
    }
    post[w] = cntP++;
    depth--;
    return hasCycle;
  }

public:
  DFSCycle (const Graph &G) : G(G), cnt(0), cntP(0), pre(G.V(), -1), post(G.V(), -1), hasCycle(false) { for (int v=0; v < G.V(); v++) if (pre[v] == -1) dfsR(Edge(v,v)); }
};
