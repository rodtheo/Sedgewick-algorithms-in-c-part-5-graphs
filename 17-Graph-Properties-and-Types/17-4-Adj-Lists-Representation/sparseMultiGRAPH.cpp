#ifndef __sparseMultiGRAPH_H__
#define __sparseMultiGRAPH_H__

#include <vector>
using namespace std;

struct Edge {
  int v; int w;
  // the following is a constructor initializer
  // that assigns to member variables v and w the
  // corresponding value v or w if specified
  Edge (int v = -1, int w = -1): v(v), w(w) {}
};

class SparseMultiGRAPH
{
  public:
    SparseMultiGRAPH (int V, bool digraph = false): adj(V), Vcnt(V), Ecnt(0), digraph(digraph) {adj.assign(V, 0);}

    int V() const { return Vcnt; }
    int E() const { return Ecnt; }
    bool directed() const { return digraph; }
    void insert (Edge e)
    {
      int v = e.v, w = e.w;
      adj[v] = new node(w, adj[v]);
      if (!digraph) adj[w] = new node(v, adj[w]);
      Ecnt++;
    }
    void remove(Edge e);
    bool edge(int v, int w) const;
    class adjIterator;
    friend class adjIterator;

  private:
    int Vcnt, Ecnt;
    bool digraph;
    struct node
    {
        int v;
        node* next;
        node(int x, node* t) { v = x; next = t; }
    };
    typedef node *link;
    vector<link> adj;
};

class SparseMultiGRAPH::adjIterator {
  public:
    adjIterator (const SparseMultiGRAPH &G, int v): G(G), v(v) {t=0;}

    int beg()     {t = G.adj[v]; return t ? t->v : -1;}
    int nxt()     {if(t) t = t->next; return t ? t->v: -1;}
    bool end()    {return t == 0;}

  private:
    const SparseMultiGRAPH &G;
    int v;
    link t;
};

#endif
