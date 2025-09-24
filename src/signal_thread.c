#include "signal_thread.h"
#include <stdio.h>

void *signal_thread(void *arg) {
    signal_args_t *sargs = (signal_args_t *)arg;
    int sig;
    while (1) {
        sigwait(sargs->set, &sig);
        if (sig == SIGUSR1) {
            pthread_mutex_lock(&sargs->ctrl->lock);
            sargs->ctrl->paused = !sargs->ctrl->paused;
            pthread_cond_signal(&sargs->ctrl->cond);
            pthread_mutex_unlock(&sargs->ctrl->lock);
            printf("[SIGNAL_THREAD] Toggled pause to %d\n", sargs->ctrl->paused);
        }
    }
    return NULL;
}
