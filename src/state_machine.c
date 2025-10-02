#include "state_machine.h"

void state_update(state_machine_t *sm, float temp) {
    if (temp >= 20.0 && temp < 24.0) sm->state = OFF;
    else if (temp >= 24.0 && temp < 28.0) sm->state = LED1_ONLY;
    else if (temp >= 28.0 && temp < 32.0) sm->state = LED2_ONLY;
    else if (temp >= 32.0 && temp < 36.0) sm->state = LED3_ONLY;
    else if (temp >= 36.0 && temp < 40.0) sm->state = LED1_2;
    else if (temp >= 40.0 && temp < 44.0) sm->state = LED2_3;
    else if (temp >= 44.0 && temp < 48.0) sm->state = LED1_3;
    else if (temp >= 48.0 && temp < 52.0) sm->state = ALL_ON;
    else if (temp >= 52.0) sm->state = PAUSED;
    else sm->state = OFF;
}
