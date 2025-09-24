#ifndef TEMP_SIM_H
#define TEMP_SIM_H

#include <pthread.h>

typedef struct {
    float temperature;
    pthread_mutex_t lock;
} system_state_t;

// Simulate temperature changes
void *temp_sim_thread(void *arg);

#endif
