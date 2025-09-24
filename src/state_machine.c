#include "state_machine.h"

void state_update(state_machine_t *sm, float temp) {
    if (temp >= 20.0 && temp < 22.0) sm->state = OFF;
    else if (temp >= 22.0 && temp <= 26.0) sm->state = LED1_ONLY;
    else if (temp >= 27.0 && temp <= 32.0) sm->state = LED2_ONLY;
    else if (temp >= 33.0 && temp <= 37.0) sm->state = LED3_ONLY;
    else if ((int)temp == 38) sm->state = LED1_2;
    else if ((int)temp == 39) sm->state = LED2_3;
    else if ((int)temp == 40) sm->state = LED1_3;
    else if (temp >= 41.0 && temp <= 43.0) sm->state = ALL_ON;
    else if (temp > 43.0) sm->state = PAUSED;
    else sm->state = OFF;
}
