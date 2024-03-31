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
        for (i=0; i<g->nV; i++) {
            Node *head = g->edges[i];
            Node *adj;
            if (!list_contains(L, head->vertex)) {
                for (adj = head->next; adj!=NULL; adj=adj->next) {
                    if (!list_contains(L, adj->vertex)) {
                        fprintf(f, "%s %s %d\n", head->vertex, adj->vertex, adj->weight);
                    }
                }
            }
        }
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
        // allocate memory for each row to another bigger memory
        g->edges = realloc(g->edges, (g->nV + 1) * sizeof(Node *));
        assert(g->edges != NULL);
        g->edges[g->nV] = new_vertex;
        g->nV++;
    }
}

Node *find_source_node(graph g, string vertex) {
    Node *src_node = NULL;
    for (int i = 0; i < g->nV; ++i) {
        if (strcmp(g->edges[i]->vertex, vertex) == 0) {
            src_node = g->edges[i];
            break;
        }
    }
    return src_node;
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
    if (g!=NULL && v!=NULL && w!=NULL && !graph_has_edge(g, v, w) && graph_has_vertex(g, v) && graph_has_vertex(g, w)) {
        Node *src_node = NULL;
        Node *new_edge = malloc(sizeof(Node));
        assert(new_edge!=NULL);
        for (int i = 0; i < g->nV; ++i) {
            if (strcmp(g->edges[i]->vertex, v) == 0) {
                src_node = g->edges[i];
                break;
            }
        }
        int data_length = strlen(w);
        new_edge->vertex = malloc((data_length+1)*sizeof(char));
        strcpy(new_edge->vertex, w);
        new_edge->weight = weight;
        new_edge->next = NULL;
        if (src_node->next==NULL) {
            src_node->next = new_edge;
        }
        else {
            Node *current = src_node->next;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_edge;
        }
    }
}

bool graph_has_edge(graph g, string v, string w) {
    if (g != NULL || v != NULL || w != NULL || !graph_has_vertex(g, v) || !graph_has_vertex(g, w)) return false;
    else {
        //Find the node of vertex v
        Node *src_node = NULL;
        for (int i = 0; i < g->nV; ++i) {
            if (strcmp(g->edges[i]->vertex, v) == 0) {
                src_node = g->edges[i];
                break; 
            }
        }

        //Find the adjacent vertex w of vertex v
        Node *adj = src_node->next;
        while (adj!=NULL) {
            if (strcmp(adj->vertex, w) == 0) return true;
            adj = adj->next;
        }
        return false;
    }
}

void graph_set_edge(graph g, string v, string w, size_t weight) {
    if (g!=NULL && v!=NULL && w!=NULL && graph_has_edge(g, v, w) && graph_has_vertex(g, v) && graph_has_vertex(g, w)) {
        //Find the node of vertex v
        Node *src_node = NULL;
        for (int i = 0; i < g->nV; ++i) {
            if (strcmp(g->edges[i]->vertex, v) == 0) {
                src_node = g->edges[i];
                break; 
            }
        }        

        //Find the adjacent vertex w of vertex v
        Node *adj = src_node->next;
        while (adj!=NULL) {
            if (strcmp(adj->vertex, w) == 0) {
                adj->weight = weight;
                break;
            }
            adj = adj->next;
        }        
    }
}

size_t graph_get_edge(graph g, string v, string w) {
    if (g == NULL || v == NULL || w == NULL || !graph_has_vertex(g, v) || !graph_has_vertex(g, w)) return 0;
    else {
        Node *src_node = NULL;
        for (int i = 0; i < g->nV; ++i) {
            if (strcmp(g->edges[i]->vertex, v) == 0) {
                src_node = g->edges[i];
                break; 
            }
        }           
        Node *adj = src_node->next;
        while (adj!=NULL) {
            if (strcmp(adj->vertex, w) == 0) {
                return adj->weight;
            }
            adj = adj->next;
        }
        return 0;       
    }
}

size_t graph_edges_count(graph g, string vertex) {
    if (g == NULL || vertex == NULL || !graph_has_vertex(g, vertex)) return 0;
    else {
        size_t count = 0;
        Node *src_node = NULL;
        for (int i = 0; i < g->nV; ++i) {
            if (strcmp(g->edges[i]->vertex, vertex) == 0) {
                src_node = g->edges[i];
                break;
            }
        }
        Node *adj = src_node->next;
        while (adj!=NULL) {
            count++;
            adj = adj->next;
        }
        return count;
    }
}
