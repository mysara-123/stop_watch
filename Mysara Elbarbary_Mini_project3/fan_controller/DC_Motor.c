/*
 * DCMotor.c
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */
#include "DC_Motor.h"
#include "gpio.h"
#include"PWM.h"

void DcMotor_init(void)
{
	GPIO_setupPinDirection(DCmotor_PORTA,DCMotor_PINA,PIN_OUTPUT);
	GPIO_setupPinDirection(DCmotor_PORTB,DCMotor_PINB,PIN_OUTPUT);

	GPIO_writePin(DCmotor_PORTA,DCMotor_PINA,LOGIC_LOW);
	GPIO_writePin(DCmotor_PORTB,DCMotor_PINB,LOGIC_LOW);

}
void DcMotor_Rotate(DCMotor_state a_state,uint8 a_speed)
{
	switch(a_state)
	{
	case 0:

		GPIO_writePin(DCmotor_PORTA,DCMotor_PINA,LOGIC_LOW);
		GPIO_writePin(DCmotor_PORTB,DCMotor_PINB,LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(DCmotor_PORTA,DCMotor_PINA,LOGIC_LOW);
		GPIO_writePin(DCmotor_PORTB,DCMotor_PINB,LOGIC_HIGH);
		break;
	case 2:
			GPIO_writePin(DCmotor_PORTA,DCMotor_PINA,LOGIC_HIGH);
			GPIO_writePin(DCmotor_PORTB,DCMotor_PINB,LOGIC_LOW);
			break;
	}
	if(a_speed<0 || a_speed>100)
	{

	}
	else
	{
		PWM_Timer0_Start((uint8)((uint32)(a_speed*255)/100));
	}
}
