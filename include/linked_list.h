#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Create a new node
Node* list_create(int value);

// Append to the end
void list_append(Node **head, int value);

// Print list values
void list_print(const Node *head);

// Free all nodes
void list_free(Node *head);

#endif