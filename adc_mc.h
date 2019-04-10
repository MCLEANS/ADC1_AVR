#ifndef _adc_mc
#define _adc_mc

#include <string.h>



void adc_init(void){
	//configure adc
	//set prescaler since adc is slow
	ADCSRA|=(1<<ADPS2);
	//left or right adjusted
	ADMUX|=(1<<ADLAR);
	//set voltage reference
	ADMUX|=(1<<REFS0);
	
	//enable global interrupts
	sei();
	//enable adc interrupts
	ADCSRA|=(1<<ADIE);
	
	 
	//enable adc
	ADCSRA|=(1<<ADEN);
	//first adc conversion
	ADCSRA|=(1<<ADSC);
}

int adc_read(){
	uint8_t theLow=ADCL;
	uint16_t tenbitValue=(theLow>>6)|(ADCH<<2);
	char adcResult[4];
	itoa(tenbitValue,adcResult,10);
	

	int data=atoi(adcResult);
	
	
	ADCSRA|=(1<<ADSC);
	return data;
}


#endif //_adc_mc
