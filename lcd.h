 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the AVR LCD driver
 *
 * Author: Kirollous Moheb
 *
 *******************************************************************************/
#ifndef LCD_H_
#define LCD_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LCD_DATA_PORT PORTC_ID
#define LCD_RS_PORT	  PORTD_ID
#define LCD_RW_PORT	  PORTD_ID
#define LCD_EN_PORT	  PORTD_ID

#define LCD_RS_PIN		  PIN4_ID
#define LCD_RW_PIN		  PIN5_ID
#define LCD_EN_PIN		  PIN6_ID
/*LCD COMMANDS*/

#define CLEAR_DISPLAY 				 0X01
#define RETURN_HOME  		       	 0X02
#define SHIFT_CURSOR_LEFT      	 	 0X04
#define SHIFT_DISPLAY_RIGHT     	 0X05
#define SHIFT_CURSOR_RIGHT       	 0X06
#define SHIFT_DISPLAY_LEFT      	 0X07
#define DISPLAY_OFF_CURSOR_OFF  	 0X08
#define DISPLAY_OFF_CURSOR_ON   	 0X0A
#define DISPLAY_ON_CURSOR_OFF   	 0X0C
#define DISPLAY_ON_CURSOR_ON    	 0X0E
#define DISPLAY_ON_CURSOR_BLINKING   0X0F
#define SHIFT_CURSOR_POSITION_LEFT   0X10
#define SHIFT_CURSOR_POSITION_RIGHT  0X14
#define SHIFT_ENTIRE_DISPLAY_LEFT    0X18
#define SHIFT_ENTIRE_DISPLAY_RIGHT   0X1C
#define CURSOR_FIRST_LINE            0X80
#define CURSOR_SECOND_LINE           0XC0
#define TWO_LINES_5X8                0X38

/*******************************************************************************
 *                      Functions Prototypes                                   *
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

void LCD_init(void);


/***************************************************************************************************
 * [Function Name]:          LCD_sendCommand
 *
 * [Description]:             Send the required command to the screen
 *
 * [Arguments]:               COMMAND
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/


void LCD_sendCommand(uint8 command);

/***************************************************************************************************
 * [Function Name]:          LCD_displayCharacter
 *
 * [Description]:             Send the required character to the screen
 *
 * [Arguments]:               character to be sent
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/
void LCD_displayCharacter(uint8 character);



/***************************************************************************************************
 * [Function Name]:          LCD_displayString
 *
 * [Description]:             Display the required string on the screen
 *
 * [Arguments]:               string to be sent
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/


void LCD_displayString(const char* str);
/***************************************************************************************************
 * [Function Name]:          LCD_moveCursor
 *
 * [Description]:             Move the cursor to a specified row and column index on the screen
 *
 * [Arguments]:              Rows and columns the cursor is to be moved at
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/

void LCD_moveCursor(uint8 row,uint8 col);
/***************************************************************************************************
 * [Function Name]:          LCD_displayStringRowColumn
 *
 * [Description]:             Display the required string in a specified row and column index on the screen
 *
 * [Arguments]:              String ,Row and column the cursor is to be moved at and print the string
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char* str);
/***************************************************************************************************
 * [Function Name]:          LCD_clearScreen
 *
 * [Description]:             Send the clear screen command
 *
 * [Arguments]:              VOID
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/

void LCD_clearScreen(void);
/***************************************************************************************************
 * [Function Name]:          LCD_integerToString
 *
 * [Description]:             Display the required decimal value on the screen
 *
 * [Arguments]:              integer to be displayed
 *
 * [Returns]:                 VOID
 ***************************************************************************************************/

void LCD_integerToString(int integer);

#endif /* LCD_H_ */
