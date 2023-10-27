#include "ADC.h"
#include<avr/interrupt.h>
#include <avr/io.h>
#include "commn_macros.h"


void ADC_init(const ADC_ConfigType*Config_Ptr){
	ADMUX=(ADMUX &(0x3f))|((Config_Ptr ->Ref_volt)<<6);
	ADCSRA |=(1<<ADEN);
	ADCSRA=(ADCSRA &(0xf8))|(Config_Ptr ->prescaler);
}


uint16 ADC_readChannel(uint8 ch_num){
	ADMUX =(ADMUX & 0xE0)|(ch_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
