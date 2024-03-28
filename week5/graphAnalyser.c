#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "Graph.h"
#include <assert.h>

typedef struct GraphRep {
   int  **edges;   // adjacency matrix
   int    nV;      // #vertices
   int    nE;      // #edges
} GraphRep;


int main(void) {
    int v,f,t;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    Graph g = newGraph(v);
    Edge e;
    bool from = true, to = false;
    while (from || to) {
        printf("Enter an edge (from): " );
        if(scanf("%d", &f) == 1) {
            from = false;
            to = true;
            
            printf("Enter an edge (to): " );
            if(scanf("%d", &t) == 1) {
                from = true;
                to = false;
                e.v = f; e.w = t; insertEdge(g, e);}
            else {from = false; to=false;}
        }
        else {from = false; to=false;}
        }
    printf("Done.\n");
    for (int i = 0; i < g->nV; i++) {
        int degree = 0;
        for (int j = 0; j < g->nV; j++) {
            if (adjacent(g, i, j)) {
                degree++;
            }
        }
        printf("Degree of node %d: %d\n", i, degree);
    }
    // Iterate through all combinations of three vertices
    printf("3-cliques:\n");
    for (int i = 0; i < g->nV - 2; i++) {
        for (int j = i + 1; j < g->nV - 1; j++) {
            for (int k = j + 1; k < g->nV; k++) {
                // Check if all pairs of vertices are adjacent
                if (adjacent(g, i, j) && adjacent(g, i, k) && adjacent(g, j, k)) {
                    printf("%d-%d-%d\n", i, j, k);
                }
            }
        }
    }
    float density = (float) 2*g->nE/((g->nV)*(g->nV));
    printf("Density: %.3f", density);
    freeGraph(g);
    return 0;
}