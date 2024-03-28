#include <stdio.h>
#include "stdlib.h"
#include <assert.h>
#include "stdbool.h"
#include "string.h"

struct NodeT {
    int value;
    struct NodeT *next;
};

void freeLL(struct NodeT *list) ;
void showLL(struct NodeT *list) ;
struct NodeT *joinLL(struct NodeT *list, int v);
struct NodeT *createNode(int v);
bool isNumber(const char *input);

bool isNumber(const char *input) {
    int i = 0;

    if (input[i] == '-') {
        i++;
    }
    while (input[i] != '\0') {
        if (input[i] < '0' || input[i] > '9') {
            return false;
        }
        i++;
    }
   if (strlen(input) ==0) return false; 
   else return true;
}
void showLL(struct NodeT *list) {
   struct NodeT *p;
   printf("Done. List is ");
   for (p = list; p != NULL; p = p->next)
      if (p->next == NULL) printf("%d\n", p->value);
      else printf("%d-->", p->value);
}

void freeLL(struct NodeT *list) {
   struct NodeT *p, *temp;

   p = list;
   while (p != NULL) {
      temp = p->next;
      free(p);
      p = temp;
   }
}

struct NodeT *createNode(int v) {
   struct NodeT *new = malloc(sizeof(struct NodeT));
   assert(new != NULL);
   new->value = v;
   new->next = NULL;
   return new;
}

struct NodeT *joinLL(struct NodeT *list, int v){
   struct NodeT *new = createNode(v);
   if (list == NULL) {
      return new;
   }
   struct NodeT *temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    return list;
}

int main(void) {
   struct NodeT *all = NULL;
   all = NULL;
    char *n = NULL; 
    size_t input_size = 0; 
   while (1) {
   printf("Enter an integer: ");
    if (getline(&n, &input_size, stdin) == -1) {
        perror("Error reading input");
        return 1;
    }
    n[strcspn(n, "\n")] = '\0';
   if (isNumber(n)) {
      int v = atoi(n);
      all = joinLL(all, v);
   }
   else {
      if (all == NULL) {
         printf("DONE.\n");
      }
      else {
         showLL(all);
      }
      break;
   }
}
   free(n);
   freeLL(all);
}