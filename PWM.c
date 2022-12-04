#include "PWM.h"

void PWM_Init()
{
    CCP1CON = 0x0F; // Select the PWM mode.
    PR2 = 100;      // Set the Cycle time to 100 for varying the duty cycle from 0-100
    CCPR1L = 50;    // By default set the dutyCycle to 50
    TMR2ON = 1;     //Start the Timer for PWM generation
}

void PWM_Write(int dutyCycle)
{
    CCPR1L = dutyCycle;
}