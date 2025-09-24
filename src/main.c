#include <stdio.h>
#include <pthread.h>
#include "linked_list.h"
#include "utils.h"
#include "temp_sim.h"

int main(void) {
    printf("=== Mini2 Core Module Test ===\n");

    // Linked list test
    Node *head = NULL;
    list_append(&head, 1);
    list_append(&head, 2);
    list_append(&head, 3);
    list_print(head);
    list_free(head);

    // Temp sim test
    system_state_t *state = state_init();
    pthread_t tid;
    pthread_create(&tid, NULL, temp_sim_thread, state);

    // Let it run for ~10 seconds
    sleep_ms(10000);

    // Cleanup
    pthread_cancel(tid);
    pthread_join(tid, NULL);
    state_destroy(state);

    printf("=== Test Complete ===\n");
    return 0;
}