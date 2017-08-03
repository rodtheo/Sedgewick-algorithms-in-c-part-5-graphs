/**
 * Reverse Topological sort (aka postorder numbering) of the DFS forest
 *  (program 19.6)
 * @param v [description]
 */

#include <vector>
using namespace std;

template <class Dag> class dagTS
{
  const Dag &D;
  int cnt, tcnt;
  vector<int> pre, post, postI;
  void tsR(int v)
  {
    pre[v] = cnt++;
    typename Dag::adjIterator A(D, v);
    for (int t = A.beg(); !A.end(); t = A.nxt())
      if (pre[t] == -1) tsR(t);
    post[v] = tcnt;
    postI[tcnt++] = v;
  }

public:
  dagTS(const Dag &D): D(D), tcnt(0), cnt(0), pre(D.V(), -1), post(D.V(), -1), postI(D.V(), -1) { for (int v=0; v < D.V(); v++)
                        if (pre[v] == -1) tsR(v); }
  int operator[] (int v) const { return postI[v]; }
  int relabel (int v) const { return post[v]; }
};
