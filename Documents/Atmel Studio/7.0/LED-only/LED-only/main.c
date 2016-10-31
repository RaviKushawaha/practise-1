/*
 * LED-only.c
 *
 * Created: 14-06-2016 16:30:44
 * Author : rkkus
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
    /* Replace with your application code */
	DDRA=0b00100001;
	PORTA=0b00000001;
    while (1) 
    {
		
		
    }
}

