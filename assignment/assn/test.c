#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(void) {
    list L = list_create();
    // string line = malloc(sizeof(string));
    list_push(L, "a");
    list_push(L, "b");
    list_push(L, "c");
    list_push(L, "d");
    list_push(L, "e");
    showList(L);
    while (!list_is_empty(L)) {
        string line = list_pop(L);
        printf("Pop: %s", line);
        // free(line);
    }
    showList(L);
    // string s = list_pop(L);
    // showList(L);
    // printf("Pop element is %s\n", s);
    // list_enqueue(L, "f");
    // showList(L);
    // s = list_dequeue(L);
    // showList(L);
    // list_destroy(L);
}