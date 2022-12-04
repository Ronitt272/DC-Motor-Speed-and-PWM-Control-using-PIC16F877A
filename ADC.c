#include "ADC.h"

void ADC_Init()
{
   ADCON0 = 0x00;            // sampling freq=osc_freq/2,ADC off initially
   ADCON1 = (1 << SBIT_ADFM);  // All pins are configured as Analog pins and ADC result is right justified  
}

int ADC_Read(unsigned char adcChannel)
{
    ADCON0 = (1 << SBIT_ADON) | (adcChannel << SBIT_CHS0);  //select required channel and turn ON adc

    delay_ms(2);                   //Acquisition Time(Wait for Charge Hold Capacitor to get charged )
   
    GO = 1;                           // Start ADC conversion
    while(GO_DONE == 1);              // Wait for the conversion to complete
                                    // GO_DONE bit will be cleared once conversion is complete

    return((ADRESH << 8) + ADRESL);   // return right justified 10-bit result
}