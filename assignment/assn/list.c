#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

typedef struct ListNode {
    string s;
    struct ListNode *prev, *next;
} ListNode ;

typedef struct List_Repr {
    ListNode *top;
    ListNode *bot;
    int size;
} List_Repr;

ListNode *create_node(string s){
    ListNode *node = malloc(sizeof(ListNode));
    assert(node!=NULL);
    node->next = NULL;
    node->prev = NULL;
    node->s = s;
    return node;
}

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
    if (L==NULL) return;
    ListNode *current = L->bot;
    int d = L->size;
    while (d>1) {
        ListNode *temp = current->next;
        free(current);
        current = temp;
        current->prev = NULL;
        L->bot = current;
        d--;
    }
    free(L->top);
    free(L);
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
    ListNode *node = create_node(s);
    if (L->size == 0) {
        L->top = node;
        L->bot = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else {
        node->next = NULL;
        node->prev = L->top;
        L->top->next = node;
        L->top = node;
    }
    L->size++;

}

string list_pop(list L) {
    if (L!=NULL) {
        if (list_is_empty(L)) return NULL;
        else {
            showList(L);
            int d = L->size;
            d = d-1;
            L->size = d;
            ListNode *current = L->top;
            string s = current->s;
            if (L->top == NULL) {
                L->bot = NULL;
            }
            current->prev->next = NULL;
            L->top = current->prev;
            return s;
        }
    }
    else return NULL;
}

void list_enqueue(list L, string s) {
    if (L==NULL || s==NULL) return ;
    list_push(L, s);
}

string list_dequeue(list L) {
    if (L != NULL) {
        if (list_is_empty(L)) return NULL;
        else {
            int d = L->size;
            d = d-1;
            L->size = d;
            ListNode *current = L->bot;
            string s = current->s;
            if (L->bot == NULL) {
                L->top = NULL;
            }
            L->bot = current->next;
            current->next->prev = NULL;
            return s;
        }
    }
    else return NULL;
}

void showList(list L) {
    ListNode *current = L->top;
    ListNode *top = L->top;
    ListNode *bot = L->bot;
    int d = L->size;
    printf("Number is %d\n", d);
    printf("Bot is %s\n", bot->s);
    printf("Top is %s\n", top->s);

    while (current != NULL) {
        string s=current->s;
        printf("element is: %s \n", s);
        // if (current->prev!=NULL) printf("prev is: %s \n", current->prev->s);
        // if (current->next!=NULL) printf("next is: %s \n", current->next->s);
        
        current = current->prev;
    }
}

bool list_contains(list L, string s) {
    assert(s != NULL);
    ListNode *current = L->bot;
    while (current != NULL) {
        if (current->s == s) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void list_add(list L, string s) {
    if (L != NULL || s != NULL || !list_contains(L, s)) {
        return; 
    }
}

void list_remove(list L, string s) {
    return;
}

