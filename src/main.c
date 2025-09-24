#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include "led_controller.h"
#include "temp_sim.h"
#include "signal_thread.h"  // minimal example

int main(void) {
    printf("=== LED Controller with Temp & Signal Thread ===\n");

    // Block SIGUSR1 in main thread
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    pthread_sigmask(SIG_BLOCK, &set, NULL);

    // Start temperature simulator
    system_state_t sys_state;
    pthread_mutex_init(&sys_state.lock, NULL);
    sys_state.temperature = 25.0;

    pthread_t temp_tid;
    pthread_create(&temp_tid, NULL, temp_sim_thread, &sys_state);

    // Init LED controller
    led_controller_t ctrl;
    led_controller_init(&ctrl, &sys_state.temperature);

    // Start signal thread
    pthread_t sig_tid;
    signal_args_t sargs = { .set = &set, .ctrl = &ctrl };
    pthread_create(&sig_tid, NULL, signal_thread, &sargs);

    // Start LED controller loop (main thread)
    led_controller_loop(&ctrl);

    return 0;
}
