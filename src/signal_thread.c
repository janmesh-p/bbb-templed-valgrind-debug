#include "signal_thread.h"
#include <stdio.h>
#include <pthread.h>

//volatile sig_atomic_t stop_flag = 0;

void *signal_thread(void *arg) {
    signal_args_t *sargs = (signal_args_t *)arg;
    int sig;
    while (!stop_flag) {
        sigwait(sargs->set, &sig);
        if (sig == SIGUSR1) {
            pthread_mutex_lock(&sargs->ctrl->lock);
            sargs->ctrl->paused = !sargs->ctrl->paused;
            pthread_cond_signal(&sargs->ctrl->cond);
            pthread_mutex_unlock(&sargs->ctrl->lock);
            printf("[SIGNAL_THREAD] Toggled pause to %d\n", sargs->ctrl->paused);
        } else if (sig == SIGUSR2) { // Termination signal
            break; // Exit loop
        }
    }
    pthread_exit(NULL); // Clean exit
}
