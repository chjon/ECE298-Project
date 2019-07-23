#include <msp430fr4133.h>

#ifndef PWM_H_
#define PWM_H_

#define PWM_PERIOD (10000)
#define PWM_NUM_CYCLES (5)

#define PWM_PORT GPIO_PORT_P1
#define PWM_PIN  GPIO_PIN7

unsigned int*      pwm_duty_cycles;
unsigned char*     pwm_selected_cycle;
unsigned char*     pwm_value;
unsigned long int* pwm_trigger_time;

void pwm_init();
void pwm_choose_cycle(unsigned char);
int pwm_get_value(unsigned long int);

void pwm_update_port(unsigned char, unsigned char);

#endif /* PWM */
