 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.c
 *
 * Description: Source file for the AVR Motor driver
 *
 * Author: Kirollous Moheb
 *
 *******************************************************************************/
#include "motor.h"
#include "avr/io.h"
#include "gpio.h"
#include "timer.h"
/*******************************************************************************
 *                      Functions Definitions                                   *
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

void DcMotor_Init(void){
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_PIN_IN1,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_PIN_IN2,PIN_OUTPUT);
	GPIO_writePin(MOTOR_PORT,MOTOR_PIN_IN1,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT,MOTOR_PIN_IN2,LOGIC_LOW);

}




/***************************************************************************************************
 * [Function Name]:         DcMotor_Rotate
 *
 * [Description]:           The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 *	 	 	 	 	 	 	Send the required duty cycle to the PWM driver based on the required speed value.
 *
 * [Arguments]:             state: The required DC Motor state, it should be CW or A-CW or stop
 * 							speed: decimal value for the required motor speed, it should be from 0 -> 100
 *
 * [Returns]:               VOID
 ***************************************************************************************************/

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	uint8 duty_cycle=((float)speed/100)*255;
	PWM_Timer0_Start(duty_cycle);
	if(state==STOP){
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN_IN1,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN_IN2,LOGIC_LOW);

	}else if(state==CLOCKWISE){
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN_IN1,LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN_IN2,LOGIC_LOW);
	}else{
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN_IN1,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT,MOTOR_PIN_IN2,LOGIC_HIGH);
	}




}
