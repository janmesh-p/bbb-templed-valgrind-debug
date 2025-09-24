#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* list_create(int value) {
    Node *n = malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "malloc failed\n");
        return NULL;
    }
    n->value = value;
    n->next = NULL;
    return n;
}

void list_append(Node **head, int value) {
    if (!head) return;
    Node *new_node = list_create(value);
    if (!new_node) return;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = new_node;
}

void list_print(const Node *head) {
    const Node *cur = head;
    while (cur) {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
    printf("NULL\n");
}

void list_free(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}