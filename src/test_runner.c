#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "temp_sim.h"
#include "utils.h"

int main(void) {
    printf("=== Running unit tests ===\n");

    // ---- Linked List Test ----
    Node *head = NULL;
    list_append(&head, 1);
    list_append(&head, 2);
    list_append(&head, 3);

    printf("[TEST] Linked list contents: ");
    list_print(head);
    list_free(head);

    // ---- Temp Sim Test ----
    system_state_t state;
    pthread_mutex_init(&state.lock, NULL);
    state.temperature = 25.0;

    pthread_t tid;
    if (pthread_create(&tid, NULL, temp_sim_thread, &state) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // Let the temp simulator run for a few cycles
    sleep_ms(5000);

    pthread_cancel(tid);        // stop the thread
    pthread_join(tid, NULL);    // cleanup
    pthread_mutex_destroy(&state.lock);

    printf("[TEST] Temp sim thread test completed.\n");

    return 0;
}