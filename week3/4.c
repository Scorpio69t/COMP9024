#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>

struct ListNode {
    char value;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head);
struct ListNode *reverseLinkedList(struct ListNode *head);
struct ListNode *createNode(char value);
void freeLinkedList(struct ListNode *head);

bool isPalindrome(struct ListNode *head) {
    if (head == NULL || head -> next == NULL) return true; 
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast -> next != NULL && fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    struct ListNode *secondHalfHead = reverseLinkedList(slow -> next);

    struct ListNode *firstHalf = head;
    while (secondHalfHead != NULL) {
        if (firstHalf -> value != secondHalfHead->value) return false;
        firstHalf = firstHalf -> next;
        secondHalfHead = secondHalfHead -> next;
    } 
    return true;
}


// Function to reverse a linked list
struct ListNode* reverseLinkedList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Function to create a new node
struct ListNode* createNode(char value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Example usage
int main() {
    // Construct the linked list for "ABBA"
    struct ListNode* a = createNode('A');
    struct ListNode* b = createNode('B');
    struct ListNode* b2 = createNode('B');
    struct ListNode* a2 = createNode('B');
    struct ListNode* a3 = createNode('B');
    struct ListNode* b3 = createNode('A');
    a->next = b;
    b->next = b2;
    b2->next = a2;
    a2->next = a3;
    a3->next = b3;

    // Check if the linked list is a palindrome
    if (isPalindrome(a))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    // Free the memory allocated for the linked list
    freeLinkedList(a);
    return 0;
}
