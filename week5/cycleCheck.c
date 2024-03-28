#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assert.h"
#include "Graph.h"

typedef struct GraphRep {
   int  **edges;   // adjacency matrix
   int    nV;      // #vertices
   int    nE;      // #edges
} GraphRep;

bool dfsCycleCheck(Graph G, int v, bool visited[], int from);
bool hasCycle(Graph g);

int *adjacentVertices(Graph g, int v, int *numadjacentver) {
    assert(g != NULL && v >= 0 && v < g->nV);
    int *adjList = (int *)malloc(g->nV * sizeof(int));
    assert(adjList != NULL);
    *numadjacentver = 0;
    for (int i=0; i<g->nV; i++) {
        if (adjacent(g, v, i)) {
            adjList[*numadjacentver] = i;
            (*numadjacentver) ++;
        }
    }
    adjList =(int *) realloc(adjList, (*numadjacentver)*sizeof(int));
    return adjList;
}

bool hasCycle(Graph g){
    if (g->nE <= 2) return false;
    bool *visited = (bool *)malloc(g->nV*sizeof(bool));
    assert(visited != NULL);
    for (int i=0; i<g->nV; i++) {
        visited[i] = false;
    }

    int startIndex=0;
    for (int i = 0; i < g->nV; i++) {
        int found = 0;
        for (int j = i+1; j < g->nV; j++) {
            if (g->edges[i][j]) {
                startIndex = i;
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    int from = startIndex;
    // free(visited);
    return dfsCycleCheck(g, startIndex, visited, from);
}

bool dfsCycleCheck(Graph G,int v, bool visited[], int from) {
    visited[v] = true;
    int numadjacentver;
    int *adjList = adjacentVertices(G, v, &numadjacentver);
    for (int w=0; w<numadjacentver; w++) {
        if (adjList[w] == from) continue;
        if (!visited[adjList[w]]) {
            
            if (dfsCycleCheck(G, adjList[w], visited, from = v)) {
                free(adjList);
                return true;
            }
        }
        else {
            free(adjList);
            return true;
        }
    }
    free(adjList);
    // free(visited);
    return false;
}

void dfsComponents(Graph G, int v, int* componentOf, int id) {
    componentOf[v] = id;
    for (int w = 0; w < numOfVertices(G); w++) {
        if (adjacent(G, v, w) && componentOf[w] == -1) {
            dfsComponents(G, w, componentOf, id);
        }
    }
}

Graph* findConnectedComponents(Graph G, int* numComponents) {
    int* componentOf = calloc(numOfVertices(G), sizeof(int));
    if (componentOf == NULL) {
        *numComponents = 0;
        return NULL;
    }

    int componentCount = 0;

    for (int v = 0; v < numOfVertices(G); v++) {
        componentOf[v] = -1;
    }

    for (int v = 0; v < numOfVertices(G); v++) {
        if (componentOf[v] == -1) {
            dfsComponents(G, v, componentOf, componentCount++);
        }
    }

    Graph* componentsArray = malloc(componentCount * sizeof(Graph));
    if (componentsArray == NULL) {
        *numComponents = 0;
        free(componentOf);
        return NULL;
    }

    for (int i = 0; i < componentCount; i++) {
        Graph subgraph = newGraph(numOfVertices(G));
        if (subgraph != NULL) {
            for (int v = 0; v < numOfVertices(G); v++) {
                if (componentOf[v] == i) {
                    for (int w = 0; w < numOfVertices(G); w++) {
                        if (adjacent(G, v, w)) {
                            insertEdge(subgraph, (Edge){v, w});
                        }
                    }
                }
            }
            componentsArray[i] = subgraph;
        }
    }

    *numComponents = componentCount;
    free(componentOf);
    return componentsArray;
}

int main(void) {
    int v,f,t;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    Graph g;
    g = newGraph(v);
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
    int *numComponents=malloc(sizeof(int));
    Graph *components_va = findConnectedComponents(g, numComponents);
    for (int i = 0; i<*numComponents; i++ ) {
        // showGraph(components_va[i]);
        if (hasCycle(components_va[i])) {
            printf("The graph has a cycle.\n");
            exit(1);
        }
    }
    printf("The graph is acyclic.\n");
    free(components_va);
    free(numComponents);
    freeGraph(g);
    
}   