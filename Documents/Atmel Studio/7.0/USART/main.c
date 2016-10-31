/*
 * USART.c
 *
 * Created: 14-06-2016 20:17:10
 * Author : rkkus
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <inttypes.h>
#include<util/delay.h>

//This function is used to initialize the USART
//at a given UBRR value
//UART needs a signal clock that determines baud rate

void USARTInit(uint16_t ubrr_value)
{

   //Set Baud rate

   UBRRL = ubrr_value;       //uart baud rate register-to set clock
   UBRRH = (ubrr_value>>8);

   /*Set Frame Format


   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit

   >> char size 8

   */
//UCSR-USART control and status register

   UCSRC=(1<<URSEL)|(3<<UCSZ0);          //usart register select  


   //Enable The receiver and transmitter

   UCSRB=(1<<RXEN)|(1<<TXEN);


}


//This function is used to read the available data
//from USART. This function will wait untill data is
//available.
char USARTReadChar()
{
   //Wait untill a data is available

   while(!(UCSRA & (1<<RXC)))      
   {
      //Do nothing
   }

   //Now USART has got data from host
   //and is available is buffer

   return UDR;
}


//This fuction writes the given "data" to
//the USART which then transmit it via TX line
void USARTWriteChar(char data)
{
   //Wait untill the transmitter is ready

   while(!(UCSRA & (1<<UDRE)))                   //USART data register ran empty
   {
      //Do nothing
   }

   //Now write the data to USART buffer

   UDR=data;
}

void main()
{
   

   //function for using the USART for data communication

   
   char data;

   /*
   
   for Baud rate = 9600bps

   UBRR value = 51

   */

   USARTInit(51);    //UBRR = 51

  

   while(1)        //output on the terminal
   {
      //Read data
      data=USARTReadChar();

      
     //write the recieved data 
      
      USARTWriteChar(data);
      

   }
}
