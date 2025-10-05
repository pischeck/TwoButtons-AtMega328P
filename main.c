/*
 * TwoButtonLED.c
 *
 * Created: 05.10.2025 21:18:04
 * Author : piszc
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define KEY_PRESSED !(PIND & (1 << PD5))
#define KEY_PRESSED2 !(PIND & (1 << PD6))

int main(void)
{
    DDRB |= (1 << PB0); // ustawienie pinu PB0 jako wyjœcia
	
	PORTD |= (1 << PD5) | (1 << PD6); //podstawienie 1 na PD5 i PD6 powoduje pod³¹czenie rezystorów podci¹gaj¹cych
	_delay_ms(15);
	
    while (1) 
    {
		if(KEY_PRESSED) PORTB = 0xFF;
		if(KEY_PRESSED2) PORTB = 0x00;
    }
	return 0;
}

