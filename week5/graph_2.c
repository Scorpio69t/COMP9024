#include <stdio.h>
#include "graph_2.h"
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct GraphRep {
    int **edges;
    int nV;
    int nE;
}   GraphRep;

Graph newGraph(int V){
    assert(V>=0);
    int i;
    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V; g->nE = 0;
    g -> edges = malloc(V * sizeof(int *));
    assert(g->edges != NULL);
    for (i=0; i<V; i++) {
        g -> edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i] != NULL);
    }
    return g;
}

void freeGraph(Graph g) {
    if (g==NULL) return;

    int v = g->nV;
    int e = g->nE;
    for (int i=0; i<v; i++) {
        free(g->edges[i]); //Free row i
    }
    free(g->edges);
    free(g);
}

bool validV(Graph g, Vertex v) {
    return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));
    if (!g -> edges[e.v][e.w]) {
        g -> edges[e.v][e.w] = 1;
        g -> edges[e.w][e.v] = 1;
        g -> nE++;
    }
}

void removeEdge(Graph g, Edge e) {
    assert( g != NULL && validV(g, e.v) && validV(g, e.w));
    if (g -> edges[e.v][e.w]){
        g -> edges[e.v][e.w] = 0;
        g -> edges[e.w][e.v] = 0;
        g -> nE--;
    }
}

bool adjacent(Graph g, Vertex x, Vertex y) {
    assert(g!=NULL && validV(g,x) && validV(g,y));
    return (g->edges[x][y] != 0);
}

void show(Graph g) {
    for (int i=0; i<=g->nV -2; i++) {
        for (int j=i+1; j<= g->nV -1; j++) {
            if (g->edges[i][j]) {
                printf("i\"-\"j");
            }
        }
    }
}

void show_reverse(Graph g) {
    for (int i=g->nV; i>=0; i--) {
        for (int j=g->nV-1; j>=i+1; j--) {
            if (g->edges[i][j]) {
                printf("i\"-\"j");
            }            
        }
    }
}