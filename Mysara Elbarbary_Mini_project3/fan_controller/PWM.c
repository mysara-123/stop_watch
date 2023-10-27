/*
 * PWM.c
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */
#include<avr/io.h>
#include"std_types.h"
#include"PWM.h"


void PWM_Timer0_Start(uint8 a_dutyCycle)
{
	TCNT0=0;
	 OCR0=a_dutyCycle;
	DDRB= DDRB |(1<<PB3) ;
	TCCR0 =(1<<COM01)|(1<<CS01)|(1<<WGM00)|(1<<WGM01);
}

