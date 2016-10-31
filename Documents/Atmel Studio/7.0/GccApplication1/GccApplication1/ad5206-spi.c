/*
 * GccApplication1.c
 *
 * Created: 14-06-2016 15:23:56
 * Author : rkkus
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void spi_init_master(void)
{
	DDRB=(1<<5)|(1<<7);
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)
}

//void spi_init_slave(void){}

int SPI_Transmit(int cData){

	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
	;
	return SPDR;
}

int main(void)
{
	
    /* Replace with your application code */
	spi_init_master();
	//spi_init_slave();
	
	
	
    while (1) 
    {
		SPI_Transmit(5);
		SPI_Transmit(250);
		_delay_ms(1000);
		SPI_Transmit(5);
		SPI_Transmit(10);
		_delay_ms(1000);
    }
}

