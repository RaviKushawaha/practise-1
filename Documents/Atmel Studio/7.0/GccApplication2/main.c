/*
 * GccApplication2.c
 *
 * Created: 15-06-2016 14:59:00
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
	
	DDRB=0b11111111;
	while (1)
	{
		PORTA=0b00001111;
	}
}
