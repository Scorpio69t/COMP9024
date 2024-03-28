// Starting code for Dijkstra's algorithm ... COMP9024 24T1

#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"
#include <string.h>

#define VERY_HIGH_VALUE 999999

void print(int v, int pred[]) {
    if (pred[v] == -1) {
        printf("%d", v);
    }
    else {
        print(pred[v], pred);
        printf("-%d", v);
    }
}

void dijkstraSSSP(Graph g, Vertex source) {
   int  dist[MAX_NODES];
   int  pred[MAX_NODES];
   bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
   int s;

   PQueueInit();
   int nV = numOfVertices(g);
   for (s = 0; s < nV; s++) {
      joinPQueue(s);
      dist[s] = VERY_HIGH_VALUE;
      pred[s] = -1;
      vSet[s] = true;
   }
   dist[source] = 0;
    while (!PQueueIsEmpty()) {
        Vertex v = leavePQueue(dist);
        // printf("Node %d\n", v);

        if (vSet[v]) {
            for (int i=0; i<nV; i++){
                if (adjacent(g, v, i)) {
                    // printf("%d\n",i);
                    if (pred[i] < 0 && vSet[i]) {
                        pred[i] = v;
                        dist[i] = dist[v]+ adjacent(g, v, i);
                    }
                    else if (pred[v]>=0 && vSet[i])
                        if (dist[v] + adjacent(g, v, i)  < dist[i]){
                            dist[i] = dist[v] + adjacent(g, v, i);
                            pred[i] = v;
                        }
                }
            }
        }
        //         for (int s=0; s<nV; s++) {
        //     printf("%d ",dist[s]);
        // }
        // printf("\n");
        // for (int s=0; s<nV; s++) {
        //     printf("%d ",pred[s]);
        // }
        // printf("\n");
        vSet[v] = false;
    }

    for (s=0; s<nV; s++) {
        if (dist[s] == VERY_HIGH_VALUE) {
            printf("%d: no path\n", s);
        }
        else {
            printf("%d: distance = %d, shortest path: ",s, dist[s]);
            print(s, pred);
            printf("\n");
        }

    }
   /* NEEDS TO BE COMPLETED */

}

void reverseEdge(Edge *e) {
   Vertex temp = e->v;
   e->v = e->w;
   e->w = temp;
}

int main(void) {
   Edge e;
   int  n, source;

   printf("Enter the number of vertices: ");
   scanf("%d", &n);
   Graph g = newGraph(n);

   printf("Enter the source node: ");
   scanf("%d", &source);
   printf("Enter an edge (from): ");
   while (scanf("%d", &e.v) == 1) {
      printf("Enter an edge (to): ");
      scanf("%d", &e.w);
      printf("Enter the weight: ");
      scanf("%d", &e.weight);
      insertEdge(g, e);
      reverseEdge(&e);               // ensure to add edge in both directions
      insertEdge(g, e);
      printf("Enter an edge (from): ");
   }
   printf("Done.\n");
   
   dijkstraSSSP(g, source);
   freeGraph(g);
   return 0;
}