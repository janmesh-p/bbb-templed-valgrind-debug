#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utils.h"

system_state_t* state_init(void) {
    system_state_t *s = malloc(sizeof(system_state_t));
    if (!s) {
        fprintf(stderr, "malloc failed\n");
        return NULL;
    }
    s->temperature = 0.0;
    pthread_mutex_init(&s->lock, NULL);
    return s;
}

void state_destroy(system_state_t *state) {
    if (!state) return;
    pthread_mutex_destroy(&state->lock);
    free(state);
}

void sleep_ms(int ms) {
    usleep(ms * 1000);
}