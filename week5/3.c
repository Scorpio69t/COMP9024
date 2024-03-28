#include <stdio.h>
#include "graph.h"

#define NODES 6
#define NODE_OF_INTEREST 1

int main(void) {
    Graph g = newGraph(NODES);
    Edge e;
    e.v = 0; e.w = 1; insertEdge(g, e);
    e.v = 0; e.w = 5; insertEdge(g, e);
    e.v = 1; e.w = 5; insertEdge(g, e);
    e.v = 2; e.w = 5; insertEdge(g, e);
    e.v = 3; e.w = 5; insertEdge(g, e);
    e.v = 4; e.w = 5; insertEdge(g, e);

    int v;
    for (v=NODES-1; v>=0; v--) {
        if (adjacent(g, v, NODE_OF_INTEREST)) {
            printf("%d\n", v);
        }
    }   
    freeGraph(g);
    return 0;

}