#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "Graph.h"

#define MAX_NODES 1000

int visited[MAX_NODES];

bool dfsCycleCheck(Graph g, Vertex v, Vertex u) {
    visited[v] = true;
    Vertex w;
    for(w=0; w<numOfVertices(g); w++){
        if (adjacent(g, v, w)) {
            if (!visited[w]) {
                if (dfsCycleCheck(g,w,v)) {
                    return true;
                }
                else {
                    if (w != u) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool hasCycle(Graph g) {
    int v, nV=numOfVertices(g);
    for (v=0; v<nV; v++){
        visited[v] = false;
    }
    for (v=0; v< nV; v++) {
        if (!visited[v]) {
            if (dfsCycleCheck(g, v, v)) {
                return true;
            }
        }
    }
    return false;
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
    if (hasCycle(g)) {
        printf("The graph has a cycle.\n");
    }
    else {
        printf("The graph is acyclic .\n");
    }
    freeGraph(g);
}