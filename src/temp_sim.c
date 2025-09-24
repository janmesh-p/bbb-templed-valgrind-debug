#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "temp_sim.h"
#include "utils.h"

void* temp_sim_thread(void *arg) {
    system_state_t *state = (system_state_t*)arg;
    if (!state) return NULL;

    while (1) {
        pthread_mutex_lock(&state->lock);
        state->temperature += 0.5;   // fake increase
        if (state->temperature > 40.0)
            state->temperature = 20.0; // reset
        double t = state->temperature;
        pthread_mutex_unlock(&state->lock);

        printf("[temp_sim] temperature = %.2f\n", t);
        sleep_ms(2000);
    }
    return NULL;
}