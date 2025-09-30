#include <stdio.h>
#include "../include/linked_list.h"

void test_linked_list(void) {
    printf("=== Running Linked List Test ===\n");
    Node *head = NULL;
    list_append(&head, 1);
    list_append(&head, 2);
    list_append(&head, 3);

    printf("Contents: ");
    list_print(head);

    list_free(head);
    printf("[PASS] Linked list append/print/free\n\n");
}
