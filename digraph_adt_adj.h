// Graph ADT interface for adjacency list graph representation
//  based on Sedgewick - Algorithms in C Graphs

// the interface defines two data types
// a simple Edge data type, including a constructor function EDGE that
// makes an Edge from two vertices
// and a Graph data type, which is defined with the standard representation
// independent

// To add an edge connecting v and w to this representation of the graph
// we add w to v's adjancency list and v to w's adjacency list
// This approach stills add new edges in constant time but the total
// amount of space used is proportional to number of vertices plus number
// of edges in constrast with matrix representation which requires V^2 of space

typedef struct node *link;
struct node {int v; link next;};
struct graph {int V; int E; link *adj;};

typedef struct { int v; int w; } Edge;

Edge EDGE (int, int);

typedef struct graph *Graph;

Graph GRAPHinit (int);

void GRAPHinsertE (Graph, Edge);

void GRAPHremoveE (Graph, Edge);

// Puts only one representation of each edge into Edge array
int GRAPHedges (Edge [], Graph G);

// Graph GRAPHcopy (Graph);
//
void GRAPHdestroy (Graph);

void GRAPHshow (Graph G);

Graph GRAPHreverse (Graph G);
