// include "STACK.cc"
#include <vector>
#include <stack>

using namespace std;

template <class Graph> class SC
{
  const Graph &G;
  int cnt, scnt;
  vector<int> pre, low, id;
  stack<int> S;

  void scR(int w)
  {
    int t;
    int min = low[w] = pre[w] = cnt++;
    S.push(w);
    typename Graph::adjIterator A(G, V);
    for (t = A.beg(); !A.end(); t = A.nxt())
      {
        if (pre[t] == -1) scR(t);
        if (low[t] < min) min = low[t];
      } // end for
    if (min < low[w]) {low[w] = min; return;}
    do {
      id[t = S.pop()] = scnt; low[t] = G.V();
    } while(t != w);
    scnt++;
  }

public:
  SC(const Graph &G) : G(G), cnt(0), scnt(0), pre(G.V(), -1), low(G.V()), id(G.V()) {
    for (int v = 0; v < G.V(); v++)
      if (pre[v] == -1) scR(v);
  }

  int count() const { return scnt; }
  bool stronglyreachacle (int v, int w) const
    { return id[v] == id[w]; }
};
