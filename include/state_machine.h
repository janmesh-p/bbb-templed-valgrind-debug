#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum {
    OFF,
    LED1_ONLY,
    LED2_ONLY,
    LED3_ONLY,
    LED1_2,
    LED2_3,
    LED1_3,
    ALL_ON,
    PAUSED
} led_state_t;

typedef struct {
    led_state_t state;
} state_machine_t;

void state_update(state_machine_t *sm, float temp);

#endif
