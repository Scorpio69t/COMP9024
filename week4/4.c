#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int main(void) {
    // Allocate memory for the struct node on the heap
    struct node *n = malloc(sizeof(struct node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Return error code if memory allocation fails
    }

    // Initialize the struct members
    n->value = 42;
    n->next = NULL;

    // Now you can use n as a pointer to the struct node allocated on the heap

    // Don't forget to free the memory when you're done using it
    free(n);

    return 0;
}
