
#include <xc.h>
#include "lcd.h"
#include "delay.h"

void lcd_wr(unsigned char val)
{
    LPORT = val;
}

void lcd_cmd(unsigned char val)
{
    LENA = 1;
    lcd_wr(val);
    LRS = 0;
    delay_ms(2);
    LENA = 0;
    delay_ms(2);
    LENA = 1;
}

void lcd_dat(unsigned char val)
{
    LENA = 1;
    lcd_wr(val);
    LRS = 1;
    delay_ms(2);
    LENA = 0;
    delay_ms(2);
    LENA = 1;
}

void lcd_init(void)
{
    LENA = 0;
    LRS = 0;
    delay_ms(20);
    LENA = 1;

    lcd_cmd(L_CFG);
    delay_ms(5);
    lcd_cmd(L_CFG);
    delay_ms(1);
    lcd_cmd(L_CFG); 
    lcd_cmd(L_OFF);
    lcd_cmd(L_ON); 
    lcd_cmd(L_CLR); 
    lcd_cmd(L_CFG); 
    lcd_cmd(L_L1);
}

void lcd_str(const char* str)
{
    unsigned char i = 0;
    while (str[i] != 0)
    {
        lcd_dat(str[i]);
        i++;
    }
}





