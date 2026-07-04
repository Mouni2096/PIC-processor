/*
 * File:   newmain.c
 * Author: mouni
 *
 * Created on 4 July, 2026, 4:35 PM
 */


#include <xc.h>
#include<stdio.h>

#define _XTAL_FREQ 20000000UL
void UART_Init(void)
{
    TRISC6 = 0;     
    TRISC7 = 1;    

    SPBRG = 129;

    BRGH = 1;
    SYNC = 0;
    SPEN = 1;

    TXEN = 1;
    CREN = 1;
}

void UART_SendChar(char c)
{
    while(!TXIF);
    TXREG = c;
}

void UART_SendString(const char *s)
{
    while(*s)
    {
        UART_SendChar(*s++);
    }
}

void main(void)
{
    UART_Init();

    while(1)
    {
        UART_SendString("Hello\r\n");

        __delay_ms(1000);
    }
}