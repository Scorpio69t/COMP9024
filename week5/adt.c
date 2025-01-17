#include <stdio.h>
#include "graph_2.h"

#define NODES 4
#define NODE_OF_INTEREST 1

int main(void) {
    Graph g = newGraph(NODES);
    Edge e;
    e.v = 0; e.w = 1; insertEdge(g, e);
    e.v = 0; e.w = 3; insertEdge(g, e);
    e.v = 1; e.w = 3; insertEdge(g, e);
    e.v = 3; e.w = 2; insertEdge(g, e);

    int v;
    for (v=0; v<NODES; v++) {
        if (adjacent(g, v, NODE_OF_INTEREST)) {
            printf("%d\n", v);
        }
    }   
    freeGraph(g);
    return 0;

}