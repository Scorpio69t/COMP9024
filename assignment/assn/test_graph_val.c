#include "list.h"
#include "pagerank.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void){
    string I= "http://www.cse.unsw.edu.au/~cs9024/micro-web/index.html",
    X="http://www.cse.unsw.edu.au/~cs9024/micro-web/X.html",
    Y="http://www.cse.unsw.edu.au/~cs9024/micro-web/Y.html",
    Z="http://www.cse.unsw.edu.au/~cs9024/micro-web/Z.html";
    list ignore_list = list_create();
    list_add(ignore_list, I);
    graph web = graph_create();
    graph_add_vertex(web, I);
    graph_add_vertex(web, Y);
    graph_add_vertex(web, X);
    graph_add_vertex(web, Z);
    graph_add_edge(web, I, Y, 1);
    graph_add_edge(web, I, Z, 1);
    graph_add_edge(web, I, X, 1);
    graph_add_edge(web, Y, I, 1);
    graph_add_edge(web, X, I, 1);
    graph_show(web, stdout, ignore_list);
    graph_pagerank(web, 0.85, 1e-6, ignore_list);
    graph_show_pagerank(web, stdout, ignore_list);
    list_destroy(ignore_list);
    graph_destroy(web);
}