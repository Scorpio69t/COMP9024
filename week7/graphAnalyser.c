#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "Graph.h"

#define MAX_NODES 1000

void degrees(Graph g) {
   int nV = numOfVertices(g);
   int v, w, degree;

   for (v = 0; v < nV; v++) {
      degree = 0;
      for (w = 0; w < nV; w++) {
         if (adjacent(g,v,w)) {
            degree++;
         }
      }
      printf("Degree of node %d: %d\n", v, degree);
   }
}

void show3Cliques(Graph g) {
    int i,j,k;
    int nV = numOfVertices(g);
    printf("3-cliques:\n");
    for (i=0;i<nV-2;i++){
        for(j=i+1;j<nV-1;j++){
            for(k=j+1;k<nV;k++){
                if (adjacent(g,i,j) && adjacent(g,i,k) && adjacent(g,k,j)) {
                    printf("%d-%d-%d\n", i, j, k);
                }
            }
        }
    }
}

void Density(Graph g) {
   int nV = numOfVertices(g);
   int nE = 0;
   int v, w;
   double density;

   for (v = 0; v < nV; v++) {
      for (w = v; w < nV; w++) {
         if (adjacent(g,v,w)) {
            nE++;
         }
      }
   }

   density = (2.0 * (double)nE) / ((double)nV * (double)nV);
   printf("Density: %.3lf\n", density);
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
    degrees(g);
    show3Cliques(g);
    Density(g);
    freeGraph(g);

    return 0;
}

// scp -r graphAnalyser.c vlab:
// /import/reed/4/z5522461/9024/tut/tut5/prac/graphAnalyser_result.c
