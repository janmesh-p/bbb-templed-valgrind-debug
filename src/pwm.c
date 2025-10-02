#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SYSFS_PWM "/sys/class/pwm"

// Real mappings
static const char *PWM_PATHS[] = {
    [0] = "/sys/class/pwm/pwmchip0/pwm0", // LED1 - P9.42
    [1] = "/sys/class/pwm/pwmchip5/pwm0", // LED2 - P9.14
    [2] = "/sys/class/pwm/pwmchip5/pwm1"  // LED3 - P9.16
};

static const int NUM_CHANNELS = 3;

int pwm_write(int channel, int duty_percent) {
    int current_channel=0;
    if (channel==18) current_channel=0;
    else if (channel==19) current_channel=1;
    else if (channel==20) current_channel=2;
   // printf("\n-----CHANNEL CHANGED FROM %d TO %d\n",channel,current_channel);
    if (current_channel < 0 || current_channel >= NUM_CHANNELS) return -1;
    channel=current_channel;
    char path[128];
    char buf[32];
    int duty_ns;
    int period_ns = 1000000; // 1kHz
    //printf("Current duty: %d\t",duty_percent);
    if (duty_percent==50) duty_percent=100;
    printf("[PWM] channel %d = %d\n",channel,duty_percent);
//  printf("[PWM_DEBUG] Writing %d%% to %s\n", duty_percent, PWM_PATHS[channel]);
 // printf("New duty: %d\n",duty_percent);
    snprintf(path, sizeof(path), "%s/period", PWM_PATHS[channel]);
    FILE *f = fopen(path, "w");
    if (!f) return -1;
    fprintf(f, "%d", period_ns);
    fclose(f);

    duty_ns = (period_ns * duty_percent) / 100;
    snprintf(path, sizeof(path), "%s/duty_cycle", PWM_PATHS[channel]);
    f = fopen(path, "w");
    if (!f) return -1;
    fprintf(f, "%d", duty_ns);
    fclose(f);

    snprintf(path, sizeof(path), "%s/enable", PWM_PATHS[channel]);
    f = fopen(path, "w");
    if (!f) return -1;
    fprintf(f, "%d", (duty_percent > 0) ? 1 : 0);
    fclose(f);
//    printf("[PWM] channel %d = %d\n",channel,duty_percent);
    return 0;
}
