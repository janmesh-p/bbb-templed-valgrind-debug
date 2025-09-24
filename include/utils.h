#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>
/*
typedef struct {
    double temperature;
    pthread_mutex_t lock;
} system_state_t;

system_state_t* state_init(void);
void state_destroy(system_state_t *state);*/
void sleep_ms(int ms);

#endif