/* 
 * File:   PWM.h
 * Author: simha
 *
 * Created on 14 January, 2022, 9:32 PM
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>
#include "delay.h"

#define SBIT_ADON     0
#define SBIT_CHS0     3
#define SBIT_ADFM     7
    
void PWM_Init();

void PWM_Write(int dutyCycle);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

