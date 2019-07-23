#include <stdlib.h>
#include "main.h"
#include "pwm.h"

void pwm_init() {
    pwm_index    = malloc(sizeof(unsigned char));
    pwm_off_time = malloc(sizeof(unsigned char));
    pwm_period   = malloc(sizeof(unsigned char));

    *pwm_index = 0;
    *pwm_off_time = 3;
    *pwm_period = 10;
}

void pwm_update_port() {
    ++*pwm_index;
    if (*pwm_index >= *pwm_period) {
        *pwm_index = 0;
    }

    if (*pwm_index < *pwm_off_time) {
        GPIO_setOutputHighOnPin(PWM_PORT, PWM_PIN);
    } else {
        GPIO_setOutputLowOnPin (PWM_PORT, PWM_PIN);
    }
}

void pwm_update_direction(unsigned char direction) {
    if (direction) { // CCW
        GPIO_setOutputHighOnPin(PWM_A1_PORT, PWM_A1_PIN);
        GPIO_setOutputLowOnPin (PWM_A2_PORT, PWM_A2_PIN);
    } else { // CW
        GPIO_setOutputHighOnPin(PWM_A2_PORT, PWM_A2_PIN);
        GPIO_setOutputLowOnPin (PWM_A1_PORT, PWM_A1_PIN);
    }
}

void pwm_update_speed(unsigned char speed) {
    *pwm_off_time = speed;
}
