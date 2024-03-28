// Insertion sort ... COMP9024 24T1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "WGraph.h"

void insertionSort(float array[], int index[], int n) {
   int i;
   index[0] = 0;
   for (i = 1; i < n; i++) {
      float element = array[i];                 // for this element ...
      int j = i-1;
      while (j >= 0 && array[j] < element) {  // ... work down the ordered list
         array[j+1] = array[j];               // ... moving elements up
         index[j+1] = index[j];
         j--;
      }
      array[j+1] = element;                   // and insert in correct position
      index[j+1] = i;
   }
}

int main(void) {
   Edge e;
   int nV;
   printf("Enter the number of vertices: ");
   scanf("%d", &nV);
   float *in = calloc(nV, sizeof(float));
   assert(in != NULL);
   float *out = calloc(nV, sizeof(float));
   assert(out != NULL);
   float *pop = calloc(nV, sizeof(float));
   assert(pop != NULL);
   Graph g = newGraph(nV);
   printf("Enter an edge (from): ");
   while(scanf("%d", &e.v) == 1) {
      out[e.v]++;
      printf("Enter an edge (to): ");
      scanf("%d", &e.w);
      in[e.w]++;
      insertEdge(g, e);
      printf("Enter an edge (from): ");
   }
   printf("Done.\n\n");
   printf("Popularity ranking:\n");

   for (int i=0; i<nV; i++){
      if ((int) out[i] != 0) {pop[i] = in[i]/out[i];}
      else { out[i]=0.5; pop[i] = in[i]/out[i];}
   }
   int *index = malloc(nV*sizeof(int));
   assert(index != NULL);
   insertionSort(pop, index, nV);
   for (int i=0; i<nV; i++){
      printf("%d %.1f\n", index[i], pop[i]);
   }
   return 0;
}