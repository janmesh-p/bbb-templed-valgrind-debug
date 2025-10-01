#include "temp_sim.h"
#include <unistd.h>
#include <stdio.h>
#include "signal_thread.h"

void *temp_sim_thread(void *arg) {
    system_state_t *state = (system_state_t *)arg;

    while(!stop_flag) {
        pthread_mutex_lock(&state->lock);
        state->temperature += 1.0;  // simple simulation
        if(state->temperature > 50.0) state->temperature = 20.0;
        printf("[TEMP_SIM] Temp = %.1f°C\n", state->temperature);
        pthread_mutex_unlock(&state->lock);

        usleep(1000000); // 1 second
//	if(state->temperature==49.0) goto endprocess;
    }
//    endprocess:
//	printf("Process ended");
    return NULL;
}
