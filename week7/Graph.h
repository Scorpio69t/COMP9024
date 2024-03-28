#include <stdbool.h>

typedef struct GraphRep *Graph;

typedef int Vertex;

typedef struct Edge {
    Vertex v;
    Vertex w;
} Edge;

Graph newGraph(int);
int numOfVertices(Graph);
void insertEdge(Graph, Edge);
void removeEdge(Graph, Edge);
bool adjacent(Graph, Vertex, Vertex);
void showGraph(Graph);
void freeGraph(Graph);
