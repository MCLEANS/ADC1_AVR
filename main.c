#ifndef F_CPU
#define F_CPU 1000000UL // 16 MHz clock speed
#endif
#define D4 eS_PORTB4
#define D5 eS_PORTB5
#define D6 eS_PORTB6
#define D7 eS_PORTB7
#define RS eS_PORTD2
#define EN eS_PORTD5

#include <avr/io.h>
#include <avr/interrupt.h>
#include <lcd.h> 
#include <stdlib.h>
#include <Util/delay.h>
#include "adc_mc.h"

int main(void){
	DDRB = 0b11110000;
    DDRD = 0b00100100;
	Lcd4_Init();
	adc_init();

	while(1){
	
	
	}
}
ISR(ADC_vect){

	int val=adc_read();
	char st[4]; 
	itoa(val,st,10);
	Lcd4_Clear();
	Lcd4_Set_Cursor(1,1);
	Lcd4_Write_String(st);
	_delay_ms(200);	
}
