#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Set.h"

typedef struct SetNode {
    int value;
    struct SetNode *next;
} SetNode;

typedef struct SetRep {
    SetNode *head;
} SetRep;

set newSet(void){
    set s = malloc(sizeof(struct SetRep));
    assert(s!=NULL);
    s->head = NULL;
    return s;
}

void dropSet(set s) {
    assert(s!=NULL);
    SetNode *current = s->head;
    while (current != NULL) {
        SetNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(s);
} 

void setAdd(set s, int v){
    if (!setContains(s, v)) {
        SetNode *new = malloc(sizeof(SetNode));
        assert(new!=NULL);
        // printf("%d\n", s->head->value);
        new->value = v;
        new->next = s->head;
        s->head = new;
    }
}

void setRemove(set s, int v){
    assert(s!=NULL);
    if (setContains(s, v)) {
        SetNode *current = s->head;
        SetNode *prev=NULL;
        while(current->next != NULL){
            if (current->value == v){
                prev->next = current->next;
                current->next=NULL;
            }
            else {
                prev = current;
                current = current->next;}
            
        }
    }
}

bool setContains(set s, int v) {
    assert(s != NULL);
    SetNode *current = s->head;
    while (current != NULL) {
        if (current->value == v) {
            return true;
        }
        current = current->next;
    }
    return false;
}


void showSet(set s) {
    SetNode *current = s->head;
    printf("Elements in the set: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}