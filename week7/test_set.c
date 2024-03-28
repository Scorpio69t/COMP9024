#include <stdio.h>
#include "Set.h"
#include "Graph.h"
#define MAX_NODES 1000

set reachability(Graph g, Vertex v, set s){
    int i, nV = numOfVertices(g);
    for (i=0; i<nV; i++){
        if (adjacent(g, v, i)){
            setAdd(s, i);
        }
    }
    return s;
} 

int main(void) {
    Edge e;
    int nV;
    printf("Enter the number of vertices: ");
    scanf("%d", &nV);
    Graph g = newGraph(nV);
    printf("Enter an edge (from): ");
    while(scanf("%d", &e.v) == 1) {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");

    set s = newSet();
    int v = 0;
    s = reachability(g, v, s);
    showSet(s);
    
    return 0;
}