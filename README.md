# ADC USING AVR
This example code enables you obtain analog sensor values into an AVR MCU.
The code makes use of Interrupts to make the ADC conversions and give a 10-bit ADC value.

## Initialize the ADC.
The first function used is adc_init() which is used to initialize the ADC.

### Step 1
Set the ADC prescaller since th ADC is slow.

    ADCSRA|=(1<<ADPS2);

### Step 2
Declare whether the ADC result is left or right adjusted.

    ADMUX|=(1<<ADLAR);

### Step 3
Set the ADC voltage reference whether the AVCC , AREF or the internal AVR voltage reference. Here the AVCC is used.

    ADMUX|=(1<<REFS0);

### Step 4
Enable both the global interrupts and the ADC conversion complete interrupt

    sei();
	ADCSRA|=(1<<ADIE);
  
### Step 5
Enable the ADC and start the first conversion

    ADCSRA|=(1<<ADEN);
	  ADCSRA|=(1<<ADSC)

## Reading the ADC Value
To read the ADC value we first read the low bits and shift them siz bits to the right, The high bits are then read and shifted two bits to the left, After reading we start a new conversion and wait for the next ADC end of conversion interrupt.

     int adc_read(){
      uint8_t theLow=ADCL;
      uint16_t tenbitValue=(theLow>>6)|(ADCH<<2);
      char adcResult[4];
      itoa(tenbitValue,adcResult,10);


      int data=atoi(adcResult);


      ADCSRA|=(1<<ADSC);
      return data;
    }
    
 ## ADC interrupt implementation.
 
     ISR(ADC_vect){
        int val=adc_read();
        char st[4]; 
        itoa(val,st,10);
        Lcd4_Clear();
        Lcd4_Set_Cursor(1,1);
        Lcd4_Write_String(st);
        _delay_ms(200);	
      }
 

  
