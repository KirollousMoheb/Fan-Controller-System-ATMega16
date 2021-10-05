/******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: temp_sensor.c
 *
 * Description: Source file for the AVR Temperature Sensor driver
 *
 * Author: Kirollous Moheb
 *
 *******************************************************************************/
#include "temp_sensor.h"
#include "adc.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
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
uint8 LM35_GetTemperature(void){

	uint8 temperature_value = 0;

	uint16 digital_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	digital_value = ADC_readChannel(SENSOR_ADC_CHANNEL);

	/* Calculate the temperature from the ADC value*/
	temperature_value = (uint8)(((uint32)digital_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLTAGE)/(ADC_MAX_VALUE*SENSOR_MAX_VOLTAGE));

	return temperature_value;
}
