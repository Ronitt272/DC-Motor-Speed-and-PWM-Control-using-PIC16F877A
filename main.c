/*
 * File:   main.c
 * Author: Ronitt Mehra 
 *
 * Created on 14 January, 2022, 9:20 PM
 */

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "lcd.h"
#include "delay.h"
#include "ADC.h"
#include "PWM.h"

typedef unsigned char BOOL;
#define FALSE 0
#define TRUE  !FALSE

#define DELAY 5 // From 0 to 100.

#define MAX_ADC 1023
uint32_t max_speed = 70;
uint32_t current_speed = 0;
char message[16];
BOOL motor_direction = TRUE;

/******************************************************************************
 * Function:        void UserInit(void)
 *  This routine takes care of all of the application code
 *  initialization that is required. It performs the initializations required 
 *       
 *
 *****************************************************************************/
void UserInit(void)
{
    lcd_init();

    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("Max Speed: 100");
    lcd_cmd(L_L2);
    lcd_str("Cur Speed: 50");
    lcd_cmd(L_CursorOff);
    ADC_Init();
    PWM_Init();
}//end UserInit

/********************************************************************
 * Function:        static void InitializeSystem(void)
 * InitializeSystem is a centralize initialization
 * routine. All required initialization routines
 * are called from here.
 *
 * User application initialization routine should
 * also be called from here.                  
 *
 *******************************************************************/
static void InitializeSystem(void)
{
    TRISA = 0xFF;
    TRISB = 0x01;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;

    UserInit();
}//end InitializeSystem

/********************************************************************
 * Function:        void Write_LCD()
 * This function is responsible for providing arguments to the LCD Display.
 * This function will also be used to call the LCD interrupt.
 *                 
 *
 *******************************************************************/
void Write_LCD()
{
    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    sprintf(message, "Max Speed: %lu", max_speed);
    lcd_str(message);
    lcd_cmd(L_L2);
    sprintf(message, "Cur Speed: %lu", current_speed);
    lcd_str(message);
}

BOOL CheckButtonPressed(void)
{
    return PORTBbits.RB0;
}

void Motor_Direction_Write(BOOL dir)
{
    if(dir)
    {
        PORTB |= (1 << 1);
        PORTB &= ~(1 << 2);
    }
    else
    {
        PORTB &= ~(1 << 1);
        PORTB |= (1 << 2);
    }
}

void main(void)
{
    InitializeSystem();
    delay_ms(100);

    uint32_t adcValue = 0;
    
    while(1)
    {
        adcValue = ADC_Read(1);
        current_speed = (adcValue * 100) / MAX_ADC;
        Write_LCD();
        
        if(current_speed > max_speed)
        {
            PORTB |= (1 << 4); // PORTB = PORTB | (1 << 4);
        }
        else
        {
            PORTB &= ~(1 << 4);
        }
        
        if(CheckButtonPressed())
        {
            motor_direction = TRUE;
        }
        else
        {
            motor_direction = FALSE;
        }
        Motor_Direction_Write(motor_direction);
        PWM_Write(current_speed);
        
        delay_ms(100);
    }
}