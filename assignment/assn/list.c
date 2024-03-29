#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

typedef struct ListNode {
    string value;
    struct ListNode *next;
} ListNode ;

typedef struct List_Repr {
    ListNode *top;
    ListNode *bot;
    int size;
} List_Repr;

list list_create(void) {
    list L = malloc(sizeof(List_Repr));
    if (L==NULL) {
        return NULL;
    }
    else {
        L->top = NULL;
        L->bot = NULL;
        L->size = 0;
        return L;
    }
}
void list_destroy(list L){
    if (L!=NULL) {
        if (L->size == 0) free(L);
        else {
        ListNode *current = L->top;
        while (current != NULL) {
            ListNode *temp = current->next;
            free(current->value);
            free(current);
            current = temp;
        }
        free(L);
        }

    }
}

bool list_is_empty(list L) {
    if (L==NULL) return true;
    return (L->size == 0);
}

size_t list_length(list L) {
    if (L==NULL) return list_is_empty(L);
    return L->size;
}

void list_push(list L, string s) {
    if (L==NULL || s==NULL) return;
    ListNode *node = malloc(sizeof(ListNode));
    size_t data_len = strlen(s);
    node->value = malloc((data_len + 1) * sizeof(char));
    strcpy(node->value, s);
    node->next = L->top;
    L->top = node;
    if (L->bot == NULL) {
        L->bot = node;
    }
    L->size++;
}

string list_pop(list L) {
    if (L!=NULL) {
        if (list_is_empty(L)) return NULL;
        else {
            ListNode *temp = L->top;
            string popped = temp->value;
            L->top = temp->next;
            free(temp);
            L->size--;
            return popped;
        }
    }
    else return NULL;
}

void list_enqueue(list L, string s) {
    if (L==NULL || s==NULL) return;
    ListNode *node = malloc(sizeof(ListNode));
    assert(node!=NULL);
    node->next = NULL;
    size_t data_len = strlen(s);
    node->value = malloc((data_len + 1) * sizeof(char));
    assert(node->value!=NULL);
    strcpy(node->value, s);
    if (L->top != NULL) {
        L->top->next = node;
        L->top = node;
    }
    else {
        L->top = node;
    }
    if (L->bot==NULL){
        L->bot = node;
    }
    L->size++;
}

string list_dequeue(list L) {
    if (L != NULL) {
        if (list_is_empty(L)) return NULL;
        else {
            ListNode *temp = L->bot;
            string popped = temp->value;
            L->bot = temp->next;
            // free(temp);
            L->size--;
            return popped;
        }
    }
    else return NULL;
}

bool list_contains(list L, string s) {
    if (L != NULL && s != NULL) {
        ListNode* temp = L->top;
        while (temp != NULL) {
            if (strcmp(temp->value, s) == 0) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    return false;
}

void list_add(list L, string s) {
    if (L != NULL && s != NULL && !list_contains(L, s)) {
        ListNode *node = malloc(sizeof(ListNode));
        assert(node!=NULL);
        int data_len = strlen(s);
        node->value = malloc((data_len+1)*sizeof(char));
        assert(node->value != NULL);
        strcpy(node->value, s);
        node->next = NULL;
        if (L->bot == NULL) {
            L->top = node;
        } else {
            L->bot->next = node;
        }
        L->bot = node;
        L->size++;
    }
}

void list_remove(list L, string s) {
    if (L != NULL && s != NULL && list_contains(L,s)) {
        ListNode *temp = L->top;
        ListNode *prev=NULL;
        while (temp!=NULL) {
            if (strcmp(temp->value, s) == 0) {
                if (prev == NULL) {
                    L->top = temp->next;
                    if (L->bot == temp) {
                        L->bot = NULL;
                    }
                }
                else {
                prev->next = temp->next;
                if (L->bot == temp) {
                    L->bot = prev;
                    }
                }
                free(temp->value);
                free(temp);
                L->size--;
                return;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
}
