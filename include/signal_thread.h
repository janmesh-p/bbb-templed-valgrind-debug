#ifndef SIGNAL_THREAD_H
#define SIGNAL_THREAD_H

#include <pthread.h>
#include <signal.h>
#include "led_controller.h"

typedef struct {
    sigset_t *set;
    led_controller_t *ctrl;
} signal_args_t;
extern volatile sig_atomic_t stop_flag; 
void *signal_thread(void *arg);

#endif
