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

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAX_VALUE   1023
#define ADC_REF_VOLTAGE 2.56


#define ADC0 (uint8)0
#define ADC1 (uint8)1
#define ADC2 (uint8)2
#define ADC3 (uint8)3
#define ADC4 (uint8)4
#define ADC5 (uint8)5
#define ADC6 (uint8)6
#define ADC7 (uint8)7

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum {
	AREF,AVCC,RESERVED,INTERNAL_VOLTAGE
}ADC_ReferenceVoltage;

typedef enum {
	F_CPU_CLOCK,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler 		 prescaler;

}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
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
void ADC_init(const ADC_ConfigType *Config_Ptr );

/***************************************************************************************************
 * [Function Name]:         ADC_readChannel
 *
 * [Description]:           The Function responsible for reading the digital value from an ADC Channel
 *
 * [Arguments]:             ADC Channel number
 *
 * [Returns]:               Returns the converted data from analog to digital
 ***************************************************************************************************/
uint16 ADC_readChannel(uint8 Ch_num);
#endif /* ADC_H_ */
