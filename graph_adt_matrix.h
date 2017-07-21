// Graph ADT interface based on Sedgewick - Algorithms in C Graphs
// the interface defines two data types
// a simple Edge data type, including a constructor function EDGE that
// makes an Edge from two vertices
// and a Graph data type, which is defined with the standard representation
// independent

typedef struct { int v; int w; } Edge;

Edge EDGE (int, int);

struct graph {int V; int E; int **adj;};

typedef struct graph *Graph;

Graph GRAPHinit (int);

void GRAPHinsertE (Graph, Edge);

void GRAPHremoveE (Graph, Edge);

int GRAPHedges (Edge [], Graph G);

// Graph GRAPHcopy (Graph);
//
// void GRAPHdestroy (Graph);

void GRAPHshow (Graph G);
