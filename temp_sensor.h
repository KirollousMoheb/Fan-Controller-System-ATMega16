/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Kirollous Moheb
 *
 *******************************************************************************/

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SENSOR_ADC_CHANNEL		2
#define SENSOR_MAX_TEMPERATURE 150
#define SENSOR_MAX_VOLTAGE		1.5
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/***************************************************************************************************
 * [Function Name]:          LM35_GetTemperature
 *
 * [Description]:            Function responsible for calculate the temperature from the ADC digital value.
 *
 * [Arguments]:              VOID
 *
 * [Returns]:                Measured Temperature
 ***************************************************************************************************/

uint8 LM35_GetTemperature(void);


#endif /* TEMP_SENSOR_H_ */
