#include "pwm.h"


int pwm_write(int ch, int val) {
    printf("[MOCK_PWM] Channel %d = %d\n", ch, val);
    return 0;
}

