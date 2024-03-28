#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

struct ListNode {
    int value;
    struct ListNode *next;
    };

struct ListNode *makeNode(int v);
struct ListNode *insertOrderedLL(struct ListNode *L,int d);
void showLL(struct ListNode *list);
void freeLinkedList(struct ListNode* head);

void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

struct ListNode *insertOrderedLL(struct ListNode *L, int d) {
    struct ListNode *current = L;
    struct ListNode *previous = NULL;
    while (current != NULL && current->value < d) { 
        previous = current;
        current = current->next;
    }
    struct ListNode *temp = makeNode(d);
    if (previous != NULL) {
        temp->next = current;
        previous->next = temp;
    }
    else {
        temp->next = L;
        L = temp;
    }
    return L;
}


struct ListNode *makeNode(int v){
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    assert(newNode!=NULL);
    newNode->value = v;
    newNode -> next = NULL;
    return newNode;
}

void showLL(struct ListNode *list) {
   struct ListNode *p;
   for (p = list; p != NULL; p = p->next)
      printf("%6d", p->value);
}


int main(void) {
    struct ListNode* a = makeNode(10);
    struct ListNode* b = makeNode(20);
    struct ListNode* b2 = makeNode(30);
    struct ListNode* a2 = makeNode(40);
    struct ListNode* a3 = makeNode(50);
    struct ListNode* b3 = makeNode(60);
    a->next = b;
    b->next = b2;
    b2->next = a2;
    a2->next = a3;
    a3->next = b3;
    a = insertOrderedLL(a, 9);
    showLL(a);
    freeLinkedList(a);
    return 0;
}