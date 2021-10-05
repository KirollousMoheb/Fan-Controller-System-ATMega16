 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the AVR LCD driver
 *
 * Author: Kirollous Moheb
 *
 *******************************************************************************/

#include "stdlib.h"
#include <util/delay.h>
#include "lcd.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/***************************************************************************************************
 * [Function Name]:          LCD_init
 *
 * [Description]:             Initialize the LCD:
 *							  1. Setup the LCD pins directions by use the GPIO driver.
 *							  2. Setup the LCD Data Mode 4-bits or 8-bits.
 *
 * [Arguments]:               VOID
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/
void LCD_init(){
	GPIO_setupPinDirection(LCD_RS_PORT,LCD_RS_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_RW_PORT,LCD_RW_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_EN_PORT,LCD_EN_PIN,PIN_OUTPUT);

	/* Configure the data port as output port */
	GPIO_setupPortDirection(LCD_DATA_PORT,PORT_OUTPUT);

	LCD_sendCommand(TWO_LINES_5X8); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */

	LCD_sendCommand(DISPLAY_ON_CURSOR_OFF); /* cursor off */

	LCD_sendCommand(CLEAR_DISPLAY); /* clear LCD at the beginning */
}


/***************************************************************************************************
 * [Function Name]:          LCD_sendCommand
 *
 * [Description]:             Send the required command to the screen
 *
 * [Arguments]:               COMMAND
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/
void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_RS_PORT,LCD_RS_PIN,LOGIC_LOW);
	GPIO_writePin(LCD_RW_PORT,LCD_RW_PIN,LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT,LCD_EN_PIN,LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT,command);
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT,LCD_EN_PIN,LOGIC_LOW);
	_delay_ms(1);
}

/***************************************************************************************************
 * [Function Name]:          LCD_displayCharacter
 *
 * [Description]:             Send the required character to the screen
 *
 * [Arguments]:               character to be sent
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/

void LCD_displayCharacter(uint8 character){
	GPIO_writePin(LCD_RS_PORT,LCD_RS_PIN,LOGIC_HIGH);
	GPIO_writePin(LCD_RW_PORT,LCD_RW_PIN,LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT,LCD_EN_PIN,LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT,character);
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT,LCD_EN_PIN,LOGIC_LOW);
	_delay_ms(1);
}


/***************************************************************************************************
 * [Function Name]:          LCD_displayString
 *
 * [Description]:             Display the required string on the screen
 *
 * [Arguments]:               string to be sent
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/
void LCD_displayString(const char* str){
	uint8 i=0;
	while(str[i]!='\0'){
		LCD_displayCharacter(str[i]);
		i++;
	}
}

/***************************************************************************************************
 * [Function Name]:          LCD_moveCursor
 *
 * [Description]:             Move the cursor to a specified row and column index on the screen
 *
 * [Arguments]:              Rows and columns the cursor is to be moved at
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/

void LCD_moveCursor(uint8 row,uint8 col){
	uint8 lcd_adress;
	switch(row){
	case 0:
		lcd_adress=col;
		break;
	case 1:
		lcd_adress=col+0x40;
		break;
	case 2:
		lcd_adress=col+0x10;
		break;
	case 3:
		lcd_adress=col+0x50;
		break;
	}
	LCD_sendCommand(lcd_adress|0x80);
}

/***************************************************************************************************
 * [Function Name]:          LCD_displayStringRowColumn
 *
 * [Description]:             Display the required string in a specified row and column index on the screen
 *
 * [Arguments]:              String ,Row and column the cursor is to be moved at and print the string
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char* str){
	LCD_moveCursor(row,col);
	LCD_displayString(str);
}

/***************************************************************************************************
 * [Function Name]:          LCD_clearScreen
 *
 * [Description]:             Send the clear screen command
 *
 * [Arguments]:               VOID
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/
void LCD_clearScreen(){
	LCD_sendCommand(CLEAR_DISPLAY);
}

/***************************************************************************************************
 * [Function Name]:          LCD_integerToString
 *
 * [Description]:             Display the required decimal value on the screen
 *
 * [Arguments]:              integer to be displayed
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/
void LCD_intgerToString(int integer)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(integer,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_displayString(buff); /* Display the string */
}

