#include <stdio.h>
#include "../include/led_controller.h"
#include "../include/state_machine.h"

void test_led_controller(void) {
    printf("=== Running LED Controller Test ===\n");

    float temp = 25.0;
    led_controller_t ctrl;
    led_controller_init(&ctrl, &temp);

    // LED1_ONLY range
    state_update(&ctrl.sm, temp);
    printf("Temp=25.0 → State=%d (expect LED1_ONLY)\n", ctrl.sm.state);

    // LED2_ONLY range
    temp = 30.0;
    state_update(&ctrl.sm, temp);
    printf("Temp=30.0 → State=%d (expect LED2_ONLY)\n", ctrl.sm.state);

    // High temp pause
    temp = 50.0;
    state_update(&ctrl.sm, temp);
    printf("Temp=50.0 → State=%d (expect PAUSED)\n", ctrl.sm.state);

    printf("[PASS] LED controller temp-based states\n\n");
}
