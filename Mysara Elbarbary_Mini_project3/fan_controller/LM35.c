/*
 * LM35.c
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */
#include "LM35.h"

 uint8 LM35_getTemp(void)
 {
	 uint8 temp_value=0;
	 uint16 adc_value=0;
	 adc_value=ADC_readChannel(SENSOR_CHANNEL_ID);
	 temp_value=(uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*
			 	 SENSOR_MAX_VOLT_VALUE));
	 return temp_value;
 }

