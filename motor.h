 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.h
 *
 * Description: Header file for the AVR Motor driver
 *
 * Author: Kirollous Moheb
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PIN_IN1              PIN0_ID
#define MOTOR_PIN_IN2              PIN1_ID
#define MOTOR_PIN_IN3
#define MOTOR_PIN_IN4
#define MOTOR_PIN_EN1  			   PIN3_ID
#define MOTOR_PIN_EN2
#define MOTOR_PORT	   	           PORTB_ID


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	STOP,CLOCKWISE,ANTI_CLOCKWISE
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/




/***************************************************************************************************
 * [Function Name]:         DcMotor_Init
 *
 * [Description]:           The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 *
 * [Arguments]:             VOID
 *
 * [Returns]:               VOID
 ***************************************************************************************************/
void DcMotor_Init(void);




/***************************************************************************************************
 * [Function Name]:         DcMotor_Rotate
 *
 * [Description]:           The function is responsible for rotating the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 *	 	 	 	 	 	 	Send the required duty cycle to the PWM driver based on the required speed value.
 *
 * [Arguments]:             state: The required DC Motor state, it should be CW or A-CW or stop
 * 							speed: decimal value for the required motor speed, it should be from 0 -> 100
 *
 * [Returns]:               VOID
 ***************************************************************************************************/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);




#endif /* MOTOR_H_ */
