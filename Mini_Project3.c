/*
 ======================================================================================
 Name        : Mini_Project3.c
 Author      : Kirollous Moheb
 Description : Application File for Mini_Project 3
 Date        : 10/3/2021
 ======================================================================================
 */
#include "adc.h"
#include "lcd.h"
#include "temp_sensor.h"
#include "motor.h"
int main(void)
{
	uint8 temp;
	LCD_init();

	ADC_ConfigType adc_config={INTERNAL_VOLTAGE,F_CPU_8};
	ADC_init(&adc_config);

	DcMotor_Init();

	LCD_displayStringRowColumn(1,3,"Temp=     C");

	while(1)
	{
		temp=LM35_GetTemperature();

		if(temp<30){
			DcMotor_Rotate(STOP,0);
			LCD_displayStringRowColumn(0,3,"Fan is OFF");
		}else{
			LCD_displayStringRowColumn(0,3,"Fan is ON");
			LCD_displayCharacter(' ');

			if(temp>=30&&temp<60){
				DcMotor_Rotate(CLOCKWISE,25);
			}else if(temp>=60&&temp<90){
				DcMotor_Rotate(CLOCKWISE,50);
			}else if(temp>=90&&temp<120){
				DcMotor_Rotate(CLOCKWISE,75);
			}else{
				DcMotor_Rotate(CLOCKWISE,100);
			}
		}


		if(temp >= 100)
		{
			LCD_moveCursor(1,9);
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_moveCursor(1,9);
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

	}
}
