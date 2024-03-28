#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

typedef struct {
    int value;
    DoubleLL *next, *prev;
} DoubleLL;

void delete(DoubleLL *head, DoubleLL *tail, DoubleLL *elem);
DoubleLL *makeNode(int v);
// a b c d e -> 
void delete(DoubleLL *head, DoubleLL *tail, DoubleLL *elem){
    if (head == elem) {
        head = elem->next;
    }
    else {
        elem->prev->next = elem->next;
    }

    if (elem == tail) {
        tail = elem->prev;
    }
    else {
        elem->next->prev = elem->prev;
    }
    free(elem);
}

DoubleLL *makeNode(int v) {
    DoubleLL *new_node = malloc(1000*sizeof(DoubleLL));
    new_node->value = v;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int main(void) {
    DoubleLL *head, *tail = NULL;
    DoubleLL *node_a = makeNode(10);
    node_a->next=NULL;
    node_a->prev=NULL;
    head = tail = node_a;

    DoubleLL *node_b = makeNode(20);
    node_b->next = NULL;
    node_b->prev = tail;
    tail->next = NULL;
    tail = node_b;

    DoubleLL *node_c = makeNode(30);
    node_c->next = NULL;
    node_c->prev = tail;
    tail->next = NULL;
    tail = node_c;
    
    

}