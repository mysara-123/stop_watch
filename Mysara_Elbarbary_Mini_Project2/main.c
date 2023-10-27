#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>

unsigned char sec_1=0;//number of seconds between 0 to 9
unsigned char sec_2=0;//number of seconds between 0 to 5
unsigned char min_1=0;//number of minits between 0 to 9
unsigned char min_2=0;//number of minits between 0 to 5
unsigned char hour_1=0;//number of hours between 0 to 9 which small of number 10
unsigned char hour_2=0;//number of hours between 0 to 9 which big of number 10 hours

void INT0_int(void){
	MCUCR |=(1<<ISC01);//falling edge
	SREG |=(1<<7);//Globol enable interrupt
	GICR |=(1<< INT0);
	DDRD &=~(1<<PD2);//enable for pin which spcialize for INT0 as output
}
ISR(INT0_vect){//  for RESET
	hour_2=hour_1=min_2=min_1=sec_1=sec_2=0;
	GIFR |=(1<<INTF0);
}
void INT1_int(void){
	MCUCR |=(1<< ISC10)| (1<<ISC11);//raising edge
	GICR |=(1<< INT1);
	SREG |=(1<<7);
	DDRD &=~(1<<PD3);//enable for pin which spcialize for INT1 as output
}
ISR(INT1_vect){// for paused
	TCCR1B &=0xf8;
	GIFR |=(1<<INTF1);
}
void INT2_int(void){
	MCUCSR &=~(1<< ISC2);//falling edge
	GICR |=(1<<INT2);
	SREG |=(1<<7);
	DDRB &=~(1<<PB2);//enable for pin which spcialize for INT2 as output
}
ISR(INT2_vect){//for resumed
	TCCR1B |=(1<<CS10)|(1<<CS12);
	GIFR |=(1<<INTF2);
}
void Timer1_CTC(void){
	TCCR1B=(1<<WGM12)|(1<<CS10)|(1<<CS12);//with prescaler /1024
	OCR1A=977;//top value
	TIMSK |=(1<<OCIE1B);//becouse we compare to value in A
}
ISR(TIMER1_COMPA_vect){
	if (sec_1 ==9 && sec_2 !=5)
	{
		sec_1=0;
		sec_2++;
	}
	else if (sec_1 ==9 && sec_2 ==5)
	{
		sec_2=sec_1=0;
		min_1++;
	}
	else
	{
		sec_1++;
	}
	if (min_1 ==9 && min_2 !=5)
	{
		min_1=0;
		min_2++;
	}
	else if (min_1 ==9 && min_2 ==5)
	{
		min_2=min_1=0;
		hour_1++;
	}
	if (hour_1 ==9 &&hour_2 !=5)
	{
		hour_1=0;
		hour_2++;
	}
	else if (hour_1 ==9 &&hour_2 ==5)
	{
		hour_2=hour_1=min_2=min_1=sec_1=sec_2=0;

	}
}

int main(void){
	SREG |(1<<7);
	DDRC |=0x0f;//first four pins for Decoder
	PORTC &=0xf0;
	DDRA |=0xf3;//six seven segment common anode at first six pins in portA
	PORTD |=(1<<PD2);
	DDRB &=~(1<<PB2);
	PORTB |=(1<<PB2);
	INT0_int();
	INT1_int();
	INT2_int();
	Timer1_CTC();
	while(1){
		PORTA &=~(0x3f);
		PORTA |=(0x01);
		PORTC =(PORTC & 0xf0) |(sec_1 & 0x0f);
		_delay_ms(3);
		PORTA &=~(0x3f);
		PORTA |=(0x02);
		PORTC =(PORTC & 0xf0) |(sec_2 & 0x0f);
		_delay_ms(3);
		PORTA &=~(0x3f);
		PORTA |=(0x04);
		PORTC =(PORTC & 0xf0) |(min_1 & 0x0f);
		_delay_ms(3);
		PORTA &=~(0x3f);
		PORTA |=(0x08);
		PORTC =(PORTC & 0xf0) |(min_2 & 0x0f);
		_delay_ms(3);
		PORTA &=~(0x3f);
		PORTA |=(0x10);
		PORTC =(PORTC & 0xf0) |(hour_1 & 0x0f);
		_delay_ms(3);
		PORTA &=~(0x3f);
		PORTA |=(0x30);
		PORTC =(PORTC & 0xf0) |(hour_2 & 0x0f);
		_delay_ms(3);
	}
}






























