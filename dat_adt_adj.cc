struct Edge {
  int v, int w;
  Edge (int v = -1, int w = -1): v(v), w(w) {}
}

class GRAPH {
  private:
    // Implementation-dependent code
  public:
    GRAPH (int, bool);
    GRAPH();
    int V() const;
    int N() const;
    bool directed() const;
    int insert (Edge);
    int remove (Edge);
    bool edge (int, int);
    class adjIterator {
      public:
        adjIterator(const GRAPH &, int);
        int beg();
        int nxt();
        bool end();
    };
};

template <class Graph>

class IO{
  public:
    static void show (const Graph &G);

    static void scanEZ (Graph &);

    static void scan (Graph &);
}

void IO<Graph>::show (const Graph &G){
  for (int s=0; s<G.V(); s++){
    cout.width(2);
    cout << s << ":";
    typename Graph::adjIterator A(G, s);
    for (int t = A.beg(); !A.end(); t = A.nxt())
      {cout.width(2); cout << t << " ";}
  }
}
