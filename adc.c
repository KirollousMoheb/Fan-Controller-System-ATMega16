/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Kirollous Moheb
 *
 *******************************************************************************/
#include "avr/io.h"
#include "common_macros.h"
#include "adc.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/***************************************************************************************************
 * [Function Name]:         ADC_init
 *
 * [Description]:           The Function responsible for Choosing the Prescaler and the Reference voltage for an ADC Channel.
 *
 * [Arguments]:             Pointer to ConfigurationStructure
 *
 * [Returns]:               VOID
 ***************************************************************************************************/
void ADC_init(const ADC_ConfigType *Config_Ptr){
	ADMUX=(ADMUX&0X3F)|((Config_Ptr->ref_volt)<<REFS0);
	ADCSRA = (1<<ADEN);
	ADCSRA = (ADCSRA&0XF8)|((Config_Ptr->prescaler)&0X07);
}

/***************************************************************************************************
 * [Function Name]:         ADC_readChannel
 *
 * [Description]:           The Function responsible for reading the digital value from an ADC Channel
 *
 * [Arguments]:             ADC Channel number
 *
 * [Returns]:               Returns the converted data from analog to digital
 ***************************************************************************************************/
uint16 ADC_readChannel(uint8 Ch_num){
	ADMUX=(ADMUX&0XE0)|(Ch_num&0x1F);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;

}
