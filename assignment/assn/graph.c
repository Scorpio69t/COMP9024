#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"

typedef struct Node {
    string vertex;
    int weight;
    struct Node *next;
} Node ;

typedef struct Graph_Repr {
    Node **edges; // Adjacency list storing positive weights and vertex label
    int nV;  // Number of vertices
} Graph_Repr;

graph graph_create(void) {
    graph g = malloc(sizeof(Graph_Repr));
    if (g==NULL) {
        return NULL;
    }
    else {
        g->nV = 0;
        g->edges = NULL;
        return g;
    }
}

void graph_destroy(graph g) {
    if (g != NULL) {
        for (int i=0; i<g->nV; i++) {
            free(g->edges[i]->vertex);
            free(g->edges[i]);
        }
        free(g->edges);
        free(g);
    }
}

void graph_show(graph g, FILE *f, list L){
    if (g!=NULL) {
        if (f==NULL) {
            f = stdout;
        }
        int i;
        for (i=0; i<g->nV; i++) {
            Node *vertex = g->edges[i];
            if (!list_contains(L, vertex->vertex)) {
                fprintf(f, "%s\n", vertex->vertex);
            }
        }
        list dest = list_create();
        for (i=0; i<g->nV; i++) {
            Node *vertex = g->edges[i];
            Node *adj;
            if (!list_contains(L, vertex->vertex)) {
                for (adj = vertex->next; adj!=NULL; adj=adj->next) {
                    if (!list_contains(L, adj->vertex)) {
                        list_push(dest, adj->vertex);
                    }
                }
                int j;
                int k=list_length(dest);
                for(j=0; j<k; j++){
                    string des = list_pop(dest);
                    fprintf(f, "%s %s %zu\n", vertex->vertex, des, graph_get_edge(g, vertex->vertex, des));
                }
            }
        }
        list_destroy(dest);
    }
}

void graph_add_vertex(graph g, string vertex) {
    if (g != NULL && vertex != NULL && !graph_has_vertex(g, vertex) ) {
        Node *new_vertex = malloc(sizeof(Node));
        assert(new_vertex != NULL);
        //Labelling vertex to new_vertex
        size_t vertex_leng = strlen(vertex);
        new_vertex->vertex = malloc((vertex_leng+1)*sizeof(char));
        strcpy(new_vertex->vertex, vertex);

        new_vertex->next = NULL;
        // allocate memory for each row
        g->edges = malloc((g->nV + 1) * sizeof(Node *));
        assert(g->edges != NULL);
        g->edges[g->nV] = new_vertex;
        g->nV++;
    }
}

bool graph_has_vertex(graph g , string vertex) {
    if (g==NULL || vertex == NULL) return false;
    else {
        int i;
        for (i=0; i<g->nV; i++) {
            if (strcmp(g->edges[i]->vertex, vertex) == 0) {
                return true;
            }
        }
        return false;
    }
}

size_t graph_vertices_count(graph g) {
    return g->nV;
}

void graph_add_edge(graph g, string v, string w, size_t weight) {
    if (g!=NULL && v!=NULL && w!=NULL && !graph_has_edge(g, v, w)) {
        Node *src_node = NULL;
        Node *dest_node = NULL;
        Node *new_edge = malloc(sizeof(Node));
        assert(new_edge!=NULL);
        for (int i = 0; i < g->nV; ++i) {
            if (strcmp(g->edges[i]->vertex, v) == 0) {
                src_node = g->edges[i];
            }
            if (strcmp(g->edges[i]->vertex, w) == 0) {
                dest_node = g->edges[i];
            }
        }
        new_edge->vertex = dest_node->vertex;
        new_edge->weight = weight;
        new_edge->next = src_node->next;
        src_node->next = new_edge;
    }
}

bool graph_has_edge(graph g, string source, string dest) {
    if (g == NULL || source == NULL || dest == NULL) return false;

    for (int i = 0; i < g->nV; ++i) {
        if (strcmp(g->edges[i]->vertex, source) == 0) {
            Node *src_node = g->edges[i];
            
            for (Node *adj = src_node->next; adj != NULL; adj = adj->next) {
                if (strcmp(adj->vertex, dest) == 0) {
                    return true;
                }
            }
            break; 
        }
    }
    return false; 
}

void graph_set_edge(graph g, string v, string w, size_t weight) {
    if (g!=NULL && v!=NULL && w!=NULL && graph_has_edge(g, v, w)) {
        for (int i = 0; i < g->nV; ++i) {
            if (strcmp(g->edges[i]->vertex, v) == 0) {
                Node *src_node = g->edges[i];
                for (Node *adj = src_node->next; adj != NULL; adj = adj->next) {
                    if (strcmp(adj->vertex, w) == 0) {
                        adj->weight = weight;
                        return; 
                    }
                }
                break; 
            }
        }
    }
}

size_t graph_get_edge(graph g, string source, string dest) {
    if (g == NULL || source == NULL || dest == NULL) return 0;
    for (int i = 0; i < g->nV; ++i) {
        if (strcmp(g->edges[i]->vertex, source) == 0) {
            Node *src_node = g->edges[i];
            
            for (Node *adj = src_node->next; adj != NULL; adj = adj->next) {
                if (strcmp(adj->vertex, dest) == 0) {
                    return adj->weight;
                }
            }
            break; 
        }
    }
    return 0; 
}

size_t graph_edges_count(graph g, string vertex) {
    if (g == NULL || vertex == NULL) return 0;
    for (int i = 0; i < g->nV; ++i) {
        if (strcmp(g->edges[i]->vertex, vertex) == 0) {
            size_t count = 0;
            Node *src_node = g->edges[i];
            for (Node *adj = src_node->next; adj != NULL; adj = adj->next) {
                ++count;
            }
            return count;
        }
    }
    return 0;
}
