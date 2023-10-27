/*
 * DC_Motor.h
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */

#ifndef HAL_DC_MOTOR_H_
#define HAL_DC_MOTOR_H_


#include"std_types.h"


#define DCmotor_PORTA PORTB_ID
#define DCmotor_PORTB PORTB_ID

#define DCMotor_PINA PIN0_ID
#define DCMotor_PINB PIN1_ID

typedef enum
{
	STOP,ACW,CW
}DCMotor_state;


void DcMotor_init(void);

void DcMotor_Rotate(DCMotor_state a_state,uint8 a_speed);

#endif /* HAL_DC_MOTOR_H_ */
