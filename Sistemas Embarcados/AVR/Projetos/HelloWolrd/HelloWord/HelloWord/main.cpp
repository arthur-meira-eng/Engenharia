/*
 * HelloWord.cpp
 *
 * Created: 02/02/2026 19:05:08
 * Author : Arthur H. S. Meira 
 */ 


#define F_CPU 16000000  //frequência de clock do Atmega328



//---Inclusão de bibliotecas---
#include <avr/io.h>
#include <util/delay.h>



//---Macros---
#define set_bit(reg, bit) (reg |=  (1<<bit))
#define clr_bit(reg, bit) (reg &= ~(1<<bit))


//---Função principal---
int main(void)
{   
	set_bit(DDRB , PORTB0);
	set_bit(DDRB , PORTB1);
	clr_bit(PORTB, PORTB0);
	clr_bit(PORTB, PORTB1);
	
	while (1) 
    {
		set_bit(PORTB, PORTB0);
		clr_bit(PORTB, PORTB1);
			_delay_ms(1000);
		set_bit(PORTB, PORTB1);
		clr_bit(PORTB, PORTB0);
			_delay_ms(1000);

    }
}

