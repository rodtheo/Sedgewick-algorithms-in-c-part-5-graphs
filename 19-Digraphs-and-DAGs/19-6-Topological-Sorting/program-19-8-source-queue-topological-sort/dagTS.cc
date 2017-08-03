// #include "QUEUE.cc"
#include <vector>
#include <queue>
using namespace std;

template <class Dag> class dagTS
{
  const Dag &D;
  vector<int> in, ts, tsI;

public:
  dagTS (const Dag &D): D(D), in(D.V(), 0), ts(D.V(), -1), tsI(D.V(), -1)
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
