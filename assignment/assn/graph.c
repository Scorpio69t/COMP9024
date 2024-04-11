#include "graph.h"
#include "list.h"
#include "pagerank.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    string vertex;
    int weight;
    double old_rank;
    double page_rank;
    struct Node *next;
} Node;

typedef struct Graph_Repr {
    Node **edges; // Adjacency list storing positive weights and vertex label
    int nV;       // Number of vertices
} Graph_Repr;

graph graph_create(void) {
    graph g = malloc(sizeof(Graph_Repr));
    if (g == NULL) {
        return NULL;
    } else {
        g->nV = 0;
        g->edges = NULL;
        return g;
    }
}

void graph_destroy(graph g) {
    if (g != NULL) {
        for (int i = 0; i < g->nV; i++) {
            Node *current = g->edges[i];
            while (current != NULL) {
                Node *temp = current;
                current = current->next;
                free(temp->vertex);
                free(temp);
            }
        }
        free(g->edges);
        free(g);
    }
}

void graph_show(graph g, FILE *f, list L) {
    if (g != NULL) {
        if (f == NULL) {
            f = stdout;
        }
        int i;
        for (i = 0; i < g->nV; i++) {
            Node *vertex = g->edges[i];
            if (!list_contains(L, vertex->vertex)) {
                fprintf(f, "%s\n", vertex->vertex);
            }
        }
        for (i = 0; i < g->nV; i++) {
            Node *head = g->edges[i];
            Node *adj;
            if (!list_contains(L, head->vertex)) {
                for (adj = head->next; adj != NULL; adj = adj->next) {
                    if (!list_contains(L, adj->vertex)) {
                        fprintf(f, "%s %s %d\n", head->vertex, adj->vertex,
                                adj->weight);
                    }
                }
            }
        }
    }
}

void graph_add_vertex(graph g, string vertex) {
    if (g != NULL && vertex != NULL && !graph_has_vertex(g, vertex)) {
        Node *new_vertex = malloc(sizeof(Node));
        assert(new_vertex != NULL);
        // Labelling vertex to new_vertex
        size_t vertex_leng = strlen(vertex);
        new_vertex->vertex = malloc((vertex_leng + 1) * sizeof(char));
        strcpy(new_vertex->vertex, vertex);

        new_vertex->next = NULL;
        // allocate memory for each row to another bigger memory
        g->edges = realloc(g->edges, (g->nV + 1) * sizeof(Node *));
        assert(g->edges != NULL);
        g->edges[g->nV] = new_vertex;
        g->nV++;
    }
}

// Find the source node whose label is vertex
void *find_source_node(graph g, string vertex, Node *src_node) {
    for (int i = 0; i < g->nV; ++i) {
        if (strcmp(g->edges[i]->vertex, vertex) == 0) {
            src_node = g->edges[i];
            break;
        }
    }
    return src_node;
}

bool graph_has_vertex(graph g, string vertex) {
    if (g == NULL || vertex == NULL)
        return false;
    else {
        int i;
        for (i = 0; i < g->nV; i++) {
            if (strcmp(g->edges[i]->vertex, vertex) == 0) {
                return true;
            }
        }
        return false;
    }
}

size_t graph_vertices_count(graph g) { return g->nV; }

void graph_add_edge(graph g, string v, string w, size_t weight) {
    if (g != NULL && v != NULL && w != NULL && !graph_has_edge(g, v, w) &&
        graph_has_vertex(g, v) && graph_has_vertex(g, w)) {
        Node *src_node = NULL;
        Node *new_edge = malloc(sizeof(Node));
        assert(new_edge != NULL);

        // Find source node of vertex v
        src_node = find_source_node(g, v, src_node);
        // new_edge->vertex = w;
        int data_length = strlen(w);
        new_edge->vertex = malloc((data_length + 1) * sizeof(char));
        strcpy(new_edge->vertex, w);
        new_edge->weight = weight;
        new_edge->next = NULL;
        if (src_node->next == NULL) {
            src_node->next = new_edge;
        } else {
            Node *current = src_node->next;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_edge;
        }
    }
}

bool graph_has_edge(graph g, string v, string w) {
    if (g != NULL && v != NULL && w != NULL && !graph_has_vertex(g, v) &&
        !graph_has_vertex(g, w))
        return false;
    else {
        // Find the node of vertex v
        Node *src_node = NULL;
        src_node = find_source_node(g, v, src_node);
        if (src_node == NULL)
            return false;
        // Find the adjacent vertex w of vertex v
        Node *adj = src_node->next;
        while (adj != NULL) {
            if (strcmp(adj->vertex, w) == 0)
                return true;
            adj = adj->next;
        }
        return false;
    }
}

void graph_set_edge(graph g, string v, string w, size_t weight) {
    if (g != NULL && v != NULL && w != NULL && graph_has_edge(g, v, w) &&
        graph_has_vertex(g, v) && graph_has_vertex(g, w)) {
        // Find the node of vertex v
        Node *src_node = NULL;
        src_node = find_source_node(g, v, src_node);

        // Find the adjacent vertex w of vertex v
        Node *adj = src_node->next;
        while (adj != NULL) {
            if (strcmp(adj->vertex, w) == 0) {
                adj->weight = weight;
                break;
            }
            adj = adj->next;
        }
    }
}

size_t graph_get_edge(graph g, string v, string w) {
    if (g == NULL || v == NULL || w == NULL || !graph_has_vertex(g, v) ||
        !graph_has_vertex(g, w))
        return 0;
    else {
        Node *src_node = NULL;
        src_node = find_source_node(g, v, src_node);

        Node *adj = src_node->next;
        while (adj != NULL) {
            if (strcmp(adj->vertex, w) == 0) {
                return adj->weight;
            }
            adj = adj->next;
        }
        return 0;
    }
}

size_t graph_edges_count(graph g, string vertex) {
    if (g == NULL || vertex == NULL || !graph_has_vertex(g, vertex))
        return 0;
    else {
        size_t count = 0;
        Node *src_node = NULL;
        src_node = find_source_node(g, vertex, src_node);

        Node *adj = src_node->next;
        while (adj != NULL) {
            count++;
            adj = adj->next;
        }
        return count;
    }
}

bool check_condition(graph g, list ignore, double epsilon) {
    int n = g->nV;
    int i;
    for (i = 0; i < n; i++) {
        Node *node = g->edges[i];
        if (!list_contains(ignore, node->vertex)) {
            if (fabs(node->page_rank - node->old_rank) <= epsilon)
                return false;
        }
    }
    return true;
}

double round_to_three_decimal_places(double num) {
    return round(num * 1000.0) / 1000.0;
}

double count_number_of_valid_vertex(graph g, list ignore) {
    int i;
    int n = g->nV;
    double count = 0.0;
    for (i = 0; i < n; i++) {
        Node *node = g->edges[i];
        node->old_rank = 0;
        if (!list_contains(ignore, node->vertex)) {
            count += 1.0;
        }
    }
    return count;
}

void graph_pagerank(graph g, double dampling, double epsilon, list ignore) {
    if (g != NULL) {
        int n = g->nV;
        int i;
        double count = count_number_of_valid_vertex(g, ignore);
        if (count > 0) {
            // Assign page_rank for all nodes
            for (i = 0; i < n; i++) {
                Node *node = g->edges[i];
                if (!list_contains(ignore, node->vertex)) {
                    node->page_rank = (float)1 / count;
                }
            }
            // Find edges have no outbound, it means len(g->edges[i]) - number
            // of has_edge() in ignore
            list stack_no_outbound = list_create();
            for (i = 0; i < n; i++) {
                size_t adj_vertex_number;
                Node *node = g->edges[i];
                adj_vertex_number = graph_edges_count(g, node->vertex);
                Node *adj = node->next;
                while (adj != NULL) {
                    if (list_contains(ignore, adj->vertex)) {
                        adj_vertex_number--;
                    }
                    adj = adj->next;
                }
                if (adj_vertex_number == 0 &&
                    !list_contains(ignore, node->vertex)) {
                    list_push(stack_no_outbound, node->vertex);
                }
            }

            while (check_condition(g, ignore, epsilon)) {
                for (i = 0; i < n; i++) {
                    Node *node = g->edges[i];
                    node->old_rank = node->page_rank;
                }
                double sink = 0.0;
                for (i = 0; i < n; i++) {
                    Node *node = g->edges[i];

                    if (list_contains(stack_no_outbound, node->vertex)) {
                        sink =
                            sink + (dampling * ((float)node->old_rank / count));
                    }
                }
                for (i = 0; i < n; i++) {
                    Node *node = g->edges[i];
                    if (!list_contains(ignore, node->vertex)) {
                        node->page_rank = sink + ((1.0 - dampling) / count);
                        for (int j = 0; j < n; j++) {
                            Node *node_j = g->edges[j];
                            size_t adj_vertex_number;
                            adj_vertex_number =
                                graph_edges_count(g, node_j->vertex);
                            if (i != j &&
                                graph_has_edge(g, node_j->vertex,
                                               node->vertex) &&
                                !list_contains(ignore, node_j->vertex)) {
                                Node *adj = node_j->next;

                                while (adj != NULL) {
                                    if (list_contains(ignore, adj->vertex)) {
                                        adj_vertex_number--;
                                    }
                                    adj = adj->next;
                                }
                                node->page_rank =
                                    node->page_rank +
                                    ((dampling * node_j->old_rank) /
                                     adj_vertex_number);
                            }
                        }
                    }
                }
            }
            list_destroy(stack_no_outbound);
        }
    }
}

void insertionSort(double array[], string index[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        double element = array[i];
        int j = i - 1;
        string temp = index[i];
        while (j >= 0 && array[j] < element) {
            array[j + 1] = array[j];
            index[j + 1] = index[j];
            j--;
        }

        while (j >= 0 && array[j] == element && strcmp(temp, index[j]) < 0) {
            array[j + 1] = array[j];
            index[j + 1] = index[j];
            j--;
        }
        array[j + 1] = element;
        index[j + 1] = temp;
    }
}

void graph_show_pagerank(graph g, FILE *f, list ignore) {
    if (g != NULL && g->nV != 0) {
        if (g->nV != 0) {
            if (f == NULL) {
                f = stdout;
            }
            double count = count_number_of_valid_vertex(g, ignore);
            int n = (int)count;
            string *index = malloc(n * sizeof(string));
            assert(index != NULL);
            double *pagerank = calloc(n, sizeof(double));
            assert(pagerank != NULL);

            int i = 0;
            int j = 0;
            while (j < g->nV) {
                if (!list_contains(ignore, g->edges[j]->vertex)) {
                    index[i] = g->edges[j]->vertex;
                    pagerank[i] = g->edges[j]->page_rank;
                    i++;
                }
                j++;
            }
            insertionSort(pagerank, index, n);
            for (i = 0; i < n; i++) {
                printf("%s: %.3f\n", index[i], pagerank[i]);
            }
            free(index);
            free(pagerank);
        }
    }
}
