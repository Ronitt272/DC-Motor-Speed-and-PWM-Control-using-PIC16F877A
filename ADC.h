/* 
 * File:   ADC.h
 * Author: simha
 *
 * Created on 14 January, 2022, 9:32 PM
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>
#include "delay.h"

#define SBIT_ADON     0
#define SBIT_CHS0     3
#define SBIT_ADFM     7
    
void ADC_Init();

int ADC_Read(unsigned char adcChannel);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

