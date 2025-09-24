#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <pthread.h>
#include "state_machine.h"

typedef struct {
    state_machine_t sm;
    float *current_temp;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int paused;
    float temp_threshold;
} led_controller_t;

void led_controller_init(led_controller_t *ctrl, float *temperature);
void led_controller_loop(led_controller_t *ctrl);

#endif
