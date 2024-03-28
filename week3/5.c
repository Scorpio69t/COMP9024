#include <stdio.h>
#include "stdlib.h"
#include "assert.h"

struct ListNode {
    int value;
    struct ListNode *next;
};
struct ListNode insertOrderedLL(struct ListNode *head, int v);

struct ListNode insertOrderedLL(struct ListNode *head, int v) {
    while (head -> value < v) {
        head = head->next;
    }
    int temp = head -> value;
    head -> value = v;
    while (temp != NULL){
        head = head -> next;
        int temp_2 = head -> value;
        head -> value = temp;
        temp = temp_2;
    };
}

struct ListNode* createNode(int value) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    assert(newNode != NULL);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void showLL(struct ListNode *list) {
   struct ListNode *p;
   for (p = list; p != NULL; p = p->next)
      printf("%6d", p->value);
}

int main() {
    // Construct the linked list for "ABBA"
    struct ListNode* a = createNode(10);
    struct ListNode* b = createNode(20);
    struct ListNode* b2 = createNode(30);
    struct ListNode* a2 = createNode(40);
    struct ListNode* a3 = createNode(50);
    struct ListNode* b3 = createNode(60);
    a->next = b;
    b->next = b2;
    b2->next = a2;
    a2->next = a3;
    a3->next = b3;
    insertOrderedLL(a, 9);
    showLL(a);
}