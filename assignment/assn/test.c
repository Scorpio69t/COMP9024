#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(void) {
    list L = list_create();
    string line = NULL;

    list_push(L, "a");
    list_push(L, "b");
    list_push(L, "c");
    list_push(L, "d");
    list_push(L, "e");
    while (!list_is_empty(L)) {
        line = list_pop(L);
        printf("Pop: %s\n", line);
        free(line);
    }
}