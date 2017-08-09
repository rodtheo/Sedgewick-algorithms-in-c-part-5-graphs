// #include "QUEUE.cc"
#include <vector>
#include <queue>
#include <iostream>
#include "../../17-Graph-Properties-and-Types/17-4-Adj-Lists-Representation/sparseMultiGRAPH.cpp"
#include "../19-6-Topological-Sorting/program-19-8-source-queue-topological-sort/dagTS.cc"

using namespace std;

template <class Graph> class delBack
{
  Graph &G;

  int depth, cnt, cntP;
  vector<int> pre, post;

  void show (char *a, Edge e)
  {
    for (int i=0; i < depth; i++) cout << " ";
    cout << e.v << "-" << e.w << " " << a << endl;
  }

  void dfsR (Edge e)
  {
    int w = e.w;
    cout << "w: " << w << endl;
    show ("tree", e);
    pre[w] = cnt++;
    depth++;

    typename Graph::adjIterator A(G, w);
    for (int t = A.beg(); !A.end(); t = A.nxt())
    {
      Edge x(w, t);
      if (pre[t] == -1) dfsR (x);
      else if (post[t] == -1){ show ("back", x); G.remove(x); }
      else if (pre[t] > pre[w]) show ("down", x);
      else show ("cross", x);
    }
    post[w] = cntP++;
    depth--;
  }

public:
  delBack (Graph &G, int start) : G(G), cnt(0), cntP(0), pre(G.V(), -1), post(G.V(), -1) { for(int v=start; v < G.V(); v++){
      // pre[4] = 0;
      if (pre[v] == -1){
        cout << "dfsR (" << v << ")" << endl;
        dfsR(Edge(v,v));}
    }
  }
  void printStatus (int v) { cout << pre[v] << " " << post[v] << endl; }
};

template <class Graph> class inTS
{
  const Graph &G;
  SparseMultiGRAPH *GTS;
  dagTS<SparseMultiGRAPH> *ts;

public:
  inTS(const Graph &G) : G(G)
  {
    ts = new dagTS<SparseMultiGRAPH> (G);
    GTS = new SparseMultiGRAPH(G.V(), true);
    for (int v = 0; v < G.V(); v++)
    {
      typename Graph::adjIterator A(G, v);
      for (int t=A.beg(); !A.end(); t = A.nxt()){
        GTS->insert(Edge(ts->relabel(v), ts->relabel(t)));
        cout << ts->relabel(v) << "->" << ts->relabel(t) << " (" << v << "->" << t << ")" <<  endl;}
    }
  }

  SparseMultiGRAPH* get_ordered_graph() { return GTS; }

};


template <class Dag> class isBubble
{
  const Dag &D;
  vector<int> in, ts, tsI;

public:
  isBubble (const Dag &D, int source, int sink): D(D), in(D.V(), 0), ts(D.V(), -1), tsI(D.V(), -1)
  {
    queue<int> Q;

    for (int v=0; v < D.V(); v++)
    {
      typename Dag::adjIterator A(D, v);
      for (int t = A.beg(); !A.end(); t = A.nxt())
        in[t]++;
    }

    for (int v=0; v < D.V(); v++)
      if (in[v] == 0) Q.push (v);

    for (int j=0; !Q.empty(); j++)
      {
        ts[j] = Q.front();
        Q.pop();
        tsI[ts[j]] = j;
        typename Dag::adjIterator A(D, ts[j]);
        for (int t = A.beg(); !A.end(); t = A.nxt())
          if (--in[t] == 0) Q.push(t);
      }
  }

  int operator[] (int v) const { return ts[v]; }

  int relabel (int v) const { return tsI[v]; }

};
