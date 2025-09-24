#ifndef PWM_H
#define PWM_H

#ifdef MOCK_PWM
#include <stdio.h>
#define pwm_write(ch, val) printf("[MOCK_PWM] Channel %d = %d\n", ch, val)
#else
#include <stdio.h>
int pwm_write(int channel, int duty);  // actual implementation for hardware
#endif

#endif // PWM_H
