/*
 * LED--only.c
 *
 * Created: 14-06-2016 23:43:18
 * Author : rkkus
 */ 
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	
	DDRA=0b00000001;
    while (1) 
    {
		PORTA=0b00000001;
		_delay_ms(1000);
		PORTA=0b00000000;
		_delay_ms(1000);
		
    }
	
	return 0;
	
}

