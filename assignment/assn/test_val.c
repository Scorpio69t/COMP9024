#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void){
    string I="http://www.cse.unsw.edu.au/~cs9024/micro-web/index.html",
    X="http://www.cse.unsw.edu.au/~cs9024/micro-web/X.html",
    Y="http://www.cse.unsw.edu.au/~cs9024/micro-web/Y.html",
    Z="http://www.cse.unsw.edu.au/~cs9024/micro-web/Z.html";
    list stack = list_create();
    list queue = list_create();
    list set = list_create();
    
    string line = NULL;
    list_push(stack,I); printf("Push: %s\n", I);
    list_add(set,I);    printf("Add: %s\n", I);
    list_push(stack,X); printf("Push: %s\n", X);
    list_add(set,X);    printf("Add: %s\n", X);
    list_push(stack,Y); printf("Push: %s\n", Y);
    list_add(set,Y);    printf("Add: %s\n", Y);
    list_push(stack,Z); printf("Push: %s\n", Z);
    list_add(set,Z);    printf("Add: %s\n", Z);
    list_add(set,I);    printf("Add: %s\n", I);
    list_add(set,X);    printf("Add: %s\n", X);
    list_add(set,Y);    printf("Add: %s\n", Y);
    list_add(set,Z);    printf("Add: %s\n", Z);
    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    list_enqueue(queue,Z);         printf("Enqueue: %s\n", Z);
    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    list_enqueue(queue,Y);         printf("Enqueue: %s\n", Y);
    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    list_enqueue(queue,X);         printf("Enqueue: %s\n", X);
    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    list_enqueue(queue,I);         printf("Enqueue: %s\n", I);
    line = list_dequeue(queue);    printf("Dequeue: %s\n", line);
    free(line);
    list_push(stack,Z);            printf("Push: %s\n", Z);
    line = list_dequeue(queue);    printf("Dequeue: %s\n", line);
    free(line);
    list_push(stack,Y);            printf("Push: %s\n", Y);
    line = list_dequeue(queue);    printf("Dequeue: %s\n", line);
    free(line);
    list_push(stack,X);            printf("Push: %s\n", X);
    line = list_dequeue(queue);    printf("Dequeue: %s\n", line);
    free(line);
    list_push(stack,I);            printf("Push: %s\n", I);
    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    
    list_remove(set,I);            printf("Remove: %s\n", I);
    list_remove(set,X);            printf("Remove: %s\n", X);
    list_remove(set,Y);            printf("Remove: %s\n", Y);
    list_remove(set,Z);            printf("Remove: %s\n", Z);

    line = list_pop(stack);        printf("Pop: %s\n", line);
    free(line);
    line = list_dequeue(queue);    printf("Dequeue: %s\n", line);
    free(line);
    list_remove(set,Z);            printf("Remove: set is empty if length is 0\n");
    printf("Stack length: %zu\n", list_length(stack));
    printf("Queue length: %zu\n", list_length(queue));
    printf("Set length: %zu\n", list_length(set));
    list_destroy(stack);
    list_destroy(queue);
    list_destroy(set);
}