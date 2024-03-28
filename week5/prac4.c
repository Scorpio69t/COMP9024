#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
   int data;
   struct node *next;
} NodeT;

NodeT *joinLL(NodeT *list, int v) {
   NodeT *new = malloc(sizeof(NodeT));
   assert(new != NULL);
   new->data = v;
   new->next = NULL;

   if (list == NULL) {  // list may be empty
      list = new;
   } else {
      NodeT *p = list;
      while (p->next != NULL) {
         p = p->next;
      }
      p->next = new;
   }
   return list;
}

void showLL(NodeT *list) {
   NodeT *p;
   for (p = list; p != NULL; p = p->next) {
      printf("%d", p->data);
      if (p->next != NULL)
         printf("-->");
   }
   putchar('\n');
}

void freeLL(NodeT *list) {
    NodeT *p = list;
    while (p != NULL) {
        NodeT *temp = p->next;
        free(p);
        p = temp;
    }
}

int main(void) {
   NodeT *all = NULL;
   int value;

   printf("Enter an integer: ");
   while (scanf("%d", &value) == 1) {
      all = joinLL(all, value);
      printf("Enter an integer: ");
   }
   if (all != NULL) {
      printf("Done. List is ");
      showLL(all);
      freeLL(all);                   // don't forget to free the list
   } else {
      printf("Done.\n");
   }
   return 0;
}