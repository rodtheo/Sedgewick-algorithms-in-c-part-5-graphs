#include "../IO.cc"
#include "../denseGRAPH.cpp"

template<class Graph> void IO<Graph>::scanEZ (Graph & G){

    vector<int> v;
    vector<int> w;

    Edge e;

    int n;
    int i = 0;
    while (cin >> n)
    {
      if (i%2 == 0){
        cout << n << endl;
        v.push_back (static_cast<int>(n));}
      else{
        cout << abs(n) << endl;
        w.push_back (static_cast<int>(abs(n)));}
      i++;
     }

     for (i=0; i < v.size(); i++)
      {
        e = Edge (v[i], w[i]);
        G.insert (e);
        cout << "Inserting edge " << e.v << "->" << e.w << endl;
      }
}

int main(){

  int V = 20;
  DenseGRAPH G(V);

  IO<DenseGRAPH>::scanEZ (G);

  IO<DenseGRAPH>::show (G);

  return 0;
}
