#include "list.h"
#include "pagerank.h"
#include "graph.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void){
    string I= "http://www.cse.unsw.edu.au/~cs9024/mini-web/index.html",
    A="http://www.cse.unsw.edu.au/~cs9024/mini-web/A.html",
    B="http://www.cse.unsw.edu.au/~cs9024/mini-web/B.html",
    C="http://www.cse.unsw.edu.au/~cs9024/mini-web/C.html",
    D="http://www.cse.unsw.edu.au/~cs9024/mini-web/D.html",
    I_A="http://www.cse.unsw.edu.au/~cs9024/mini-web/A/index.html",
    I_B="http://www.cse.unsw.edu.au/~cs9024/mini-web/B/index.html",
    A_1="http://www.cse.unsw.edu.au/~cs9024/mini-web/A/A1.html",
    A_2="http://www.cse.unsw.edu.au/~cs9024/mini-web/A/A2.html",
    A_3="http://www.cse.unsw.edu.au/~cs9024/mini-web/A/A3.html",
    B_1="http://www.cse.unsw.edu.au/~cs9024/mini-web/B/B1.html",
    B_2="http://www.cse.unsw.edu.au/~cs9024/mini-web/B/B2.html",
    B_3="http://www.cse.unsw.edu.au/~cs9024/mini-web/B/B3.html",
    B_4="http://www.cse.unsw.edu.au/~cs9024/mini-web/B/B4.html",
    B_5="http://www.cse.unsw.edu.au/~cs9024/mini-web/B/B5.html";
    list ignore_list = list_create();
    // list_add(ignore_list, Y);
    graph web = graph_create();
    graph_add_vertex(web, I);
    graph_add_vertex(web, A);
    graph_add_vertex(web, B);
    graph_add_vertex(web, C);
    graph_add_vertex(web, D);
    graph_add_vertex(web, I_A);
    graph_add_vertex(web, I_B);
    graph_add_vertex(web, A_1);
    graph_add_vertex(web, A_2);
    graph_add_vertex(web, A_3);
    graph_add_vertex(web, B_1);
    graph_add_vertex(web, B_2);
    graph_add_vertex(web, B_3);
    graph_add_vertex(web, B_4);
    graph_add_vertex(web, B_5);
    graph_add_edge(web, I, A, 1);
    graph_add_edge(web, I, B, 1);
    graph_add_edge(web, I, C, 1);
    graph_add_edge(web, I, D, 1);
    graph_add_edge(web, A, I_A, 1);
    graph_add_edge(web, A, I, 1);
    graph_add_edge(web, B, I_B, 1);
    graph_add_edge(web, C, A, 1);
    graph_add_edge(web, C, B, 1);
    graph_add_edge(web, C, D, 1);
    graph_add_edge(web, I_A, A, 1);
    graph_add_edge(web, I_A, A_1, 1);
    graph_add_edge(web, I_A, A_2, 1);
    graph_add_edge(web, I_A, A_3, 1);
    graph_add_edge(web, I_B, B_1, 1);
    graph_add_edge(web, I_B, B_2, 1);
    graph_add_edge(web, I_B, B_3, 1);
    graph_add_edge(web, I_B, B_4, 1);
    graph_add_edge(web, I_B, B_5, 1);
    graph_add_edge(web, I_B, B, 1);
    graph_add_edge(web, I_B, I, 1);
    graph_add_edge(web, A_1, I_A, 1);
    graph_add_edge(web, A_1, A, 1);
    graph_add_edge(web, A_1, I, 1);
    graph_add_edge(web, A_2, I_A, 1);
    graph_add_edge(web, A_2, A, 1);
    graph_add_edge(web, A_2, I, 1);
    graph_add_edge(web, A_3, I_A, 1);
    graph_add_edge(web, A_3, A, 1);
    graph_add_edge(web, A_3, I, 1);
    graph_add_edge(web, B_5, B, 1);
    graph_show(web, stdout, ignore_list);
    graph_pagerank(web, 0.85, 1e-6, ignore_list);
    graph_show_pagerank(web, stdout, ignore_list);
    graph_shortest_path(web, C, ignore_list);
    graph_show_path(web, stdout, A_1, ignore_list);
    list_destroy(ignore_list);
    graph_destroy(web);
}