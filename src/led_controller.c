#include "led_controller.h"
#include "pwm.h"
#include <unistd.h>
#include <stdio.h>
#include "signal_thread.h"

void led_controller_init(led_controller_t *ctrl, float *temperature) {
    pthread_mutex_init(&ctrl->lock, NULL);
    pthread_cond_init(&ctrl->cond, NULL);
    ctrl->paused = 0;
    ctrl->temp_threshold = 43.0;
    ctrl->current_temp = temperature;
    ctrl->sm.state = OFF;
}

void led_controller_loop(led_controller_t *ctrl) {
    while (!stop_flag){
        pthread_mutex_lock(&ctrl->lock);

        state_update(&ctrl->sm, *ctrl->current_temp);

        switch(ctrl->sm.state) {
            case OFF:      pwm_write(18,0); pwm_write(19,0); pwm_write(20,0); break;
            case LED1_ONLY:pwm_write(18,50); pwm_write(19,0); pwm_write(20,0); break;
            case LED2_ONLY:pwm_write(18,0); pwm_write(19,50); pwm_write(20,0); break;
            case LED3_ONLY:pwm_write(18,0); pwm_write(19,0); pwm_write(20,50); break;
            case LED1_2:   pwm_write(18,50); pwm_write(19,50); pwm_write(20,0); break;
            case LED2_3:   pwm_write(18,0); pwm_write(19,50); pwm_write(20,50); break;
            case LED1_3:   pwm_write(18,50); pwm_write(19,0); pwm_write(20,50); break;
            case ALL_ON:   pwm_write(18,50); pwm_write(19,50); pwm_write(20,50); break;
            case PAUSED:   printf("[LED_CTRL] Paused due to high temp: %.1f°C\n", *ctrl->current_temp); break;
        }

        pthread_mutex_unlock(&ctrl->lock);
        usleep(1000000); // 0.5s per loop
    }
}
