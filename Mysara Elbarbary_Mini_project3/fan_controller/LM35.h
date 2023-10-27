/*
 * LM35.h
 *
 *  Created on: Oct 12, 2023
 *      Author: hp
 */

#ifndef HAL_LM35_H_
#define HAL_LM35_H_

#include"std_types.h"
#include"ADC.h"

#define SENSOR_CHANNEL_ID   2
#define SENSOR_MAX_VOLT_VALUE  1.5
#define SENSOR_MAX_TEMPERATURE  150
uint8 LM35_getTemp (void);
#endif /* HAL_LM35_H_ */
