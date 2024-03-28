#include <stdbool.h>
typedef struct GraphRep *Graph;

typedef int Vertex;

typedef struct Edge {Vertex v; Vertex w;} Edge;

Graph newGraph(int V);
int numofVertices(Graph);
void insertEdge(Graph, Edge edge);
void removeEdge(Graph, Edge edge);
bool adjacent(Graph, Vertex, Vertex);
void  showGraph(Graph);        
void show_reverse(Graph);       // print all edges in a graph
void  freeGraph(Graph);