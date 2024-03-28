#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete a node from the doubly linked list
void Delete(struct Node** headRef, struct Node** tailRef, struct Node* elem) {
    // Check if the element to be deleted is NULL
    if (elem == NULL)
        return;

    // Case 1: If elem is the head of the list
    if (*headRef == elem)
        *headRef = elem->next;

    // Case 2: If elem is not the head of the list
    if (elem->prev != NULL)
        elem->prev->next = elem->next;

    // Case 3: If elem is the tail of the list
    if (*tailRef == elem)
        *tailRef = elem->prev;

    // Case 4: If elem is not the tail of the list
    if (elem->next != NULL)
        elem->next->prev = elem->prev;

    // Free memory allocated for the node
    free(elem);
}

// Function to print the doubly linked list
void PrintList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a sample doubly linked list
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Insert elements into the list
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 10;
    node1->prev = NULL;
    node1->next = NULL;
    head = node1;
    tail = node1;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 20;
    node2->prev = tail;
    node2->next = NULL;
    tail->next = node2;
    tail = node2;

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 30;
    node3->prev = tail;
    node3->next = NULL;
    tail->next = node3;
    tail = node3;

    // Print the initial list
    printf("Initial list: ");
    PrintList(head);

    // Delete the second node (node2) from the list
    Delete(&head, &tail, node2);

    // Print the updated list after deletion
    printf("List after deletion: ");
    PrintList(head);

    // Free memory allocated for the remaining nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
