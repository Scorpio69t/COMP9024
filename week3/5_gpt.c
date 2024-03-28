#include <stdio.h>
#include <stdlib.h>

// Define ListNode structure
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    if (newNode != NULL) {
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a new element into a sorted linked list
struct ListNode* insertOrderedLL(struct ListNode* head, int val) {
    struct ListNode* new_node = createNode(val);
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return head; // Return the original head if memory allocation fails
    }
    
    // If the linked list is empty or the new node should be inserted at the beginning
    if (!head || val < head->val) {
        new_node->next = head;
        return new_node;
    }
    
    struct ListNode* current = head;
    while (current->next && current->next->val < val) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
    
    return head;
}

// Function to print the linked list
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Function to free memory allocated for the linked list
void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Create the original linked list
    struct ListNode* head = createNode(17);
    head->next = createNode(26);
    head->next->next = createNode(54);
    head->next->next->next = createNode(77);
    head->next->next->next->next = createNode(93);

    printf("Original linked list:\n");
    printLinkedList(head);

    // Insert 31 into the linked list
    int new_number;
    printf("Enter your number: ");
    scanf("%d", &new_number);
    head = insertOrderedLL(head, new_number);
    printf("Linked list after inserting %d:\n", new_number);
    printLinkedList(head);

    // Free memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}
