#include <stdio.h>
#include "../include/state_machine.h"

void test_state_machine(void) {
    printf("=== Running State Machine Test ===\n");

    state_machine_t sm;

    state_update(&sm, 21.0);  printf("21.0°C → %d (expect OFF)\n", sm.state);
    state_update(&sm, 25.0);  printf("25.0°C → %d (expect LED1_ONLY)\n", sm.state);
    state_update(&sm, 30.0);  printf("30.0°C → %d (expect LED2_ONLY)\n", sm.state);
    state_update(&sm, 35.0);  printf("35.0°C → %d (expect LED3_ONLY)\n", sm.state);
    state_update(&sm, 38.0);  printf("38.0°C → %d (expect LED1_2)\n", sm.state);
    state_update(&sm, 39.0);  printf("39.0°C → %d (expect LED2_3)\n", sm.state);
    state_update(&sm, 40.0);  printf("40.0°C → %d (expect LED1_3)\n", sm.state);
    state_update(&sm, 42.0);  printf("42.0°C → %d (expect ALL_ON)\n", sm.state);
    state_update(&sm, 50.0);  printf("50.0°C → %d (expect PAUSED)\n", sm.state);

    printf("[PASS] State machine temp→state mapping\n\n");
}
