# Fan Controller system using ATMega16
# Description

> The aim of this project is to design a temperature-controlled fan using ATmega16
microcontroller, in which the fan is automatically turned ON or OFF according to the 
temperature. Use ATmega16 Microcontroller with frequency 1Mhz.

>The LM35 temperature sensor will give continuous analog output 
corresponding to the temperature sensed by it. This analog signal is given to the ADC, 
which converts the analog values to digital values

>The temperature is displayed on the LCD. 

>The microcontroller will continuously monitor the temperature and based on the 
temperature value, the microcontroller will drive the fan like that:

>a. If the temperature is less than 30C turn off the fan.

>b.If the temperature is greater than or equal 30C turn on the fan with 25% of its 
maximum speed.

>c. If the temperature is greater than or equal 60C turn on the fan with 50% of its 
maximum speed.

>d. If the temperature is greater than or equal 90C turn on the fan with 75% of its 
maximum speed.

>e. If the temperature is greater than or equal 120C turn on the fan with 100% of its 
maximum speed.

## Video Link
>https://youtu.be/NrGwtGJOiwo

## Table of Contents

- [Connections](#connections)
  * [LCD](#lcd)
  * [LM35](#lm35)
  * [Motor](#motor)
- [Drivers](#drivers)
  * [GPIO](#gpio)
  * [LCD](#lcd)
  * [ADC](#adc)
  * [LM35](#lm35)
  * [Motor](#motor)
  * [Timer](#timer)





## Connections

![Capture](https://user-images.githubusercontent.com/66686446/136054057-6ebb1eda-ea1b-4c49-8626-0aad95a5e051.PNG)

### LCD



```c
/****************************************************/   
/*
*  Hardware Connentions
*
* [PC0 - PC7] -> [ D0- D7 ]  Data
* [PD4 - PD6] -> [Rs-Rw-E]   Control
 
****************************************************/
```


### LM35

```c
/****************************************************/   
/*
*  Hardware Connentions
*
* ADC Channel 2 -> Pin PA2
* 
*  
****************************************************/
```
### Motor

```c
/****************************************************/   
/*
*  Hardware Connentions
*
* IN1 -> PB0
* IN2->  PB1
* EN1->  PB2
*  
****************************************************/
```


## Drivers

### GPIO
* `void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)`: Setup the direction of the required pin input/output.
* `void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)`:  Write the value Logic High or Logic Low on the required pin.
* `uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)`:Setup the direction of the required port all pins input/output.
* `void GPIO_setupPortDirection(uint8 port_num, uint8 direction)`: Setup the direction of the required port all pins input/output.
* `void GPIO_writePort(uint8 port_num, uint8 value)`:  Write the value on the required port.
* `uint8 GPIO_readPort(uint8 port_num)`:  Read and return the value of the required port.




### LCD
* `void LCD_init(void)`:Initialize the LCD.
1. Setup the LCD pins directions by use the GPIO driver.
2. Setup the LCD Data Mode 4-bits or 8-bits.
* `void LCD_sendCommand(uint8 command)`:  Send the required command to the screen.
* `void LCD_displayString(const char* str)`:Display the required string on the screen.
* `void LCD_moveCursor(uint8 row,uint8 col)`: Move the cursor to a specified row and column index on the screen.
* `void LCD_displayStringRowColumn(uint8 row,uint8 col,const char* str)`: Display the required string in a specified row and column index on the screen.
* `void LCD_clearScreen(void)`:  Send the clear screen command
* `void LCD_integerToString(int integer)`:   Display the required decimal value on the screen


### ADC
* `void ADC_init(const ADC_ConfigType *Config_Ptr )`: The Function responsible for Choosing the Prescaler and the Reference voltage for an ADC Channel
* `uint16 ADC_readChannel(uint8 Ch_num)`:  The Function responsible for reading the digital value from an ADC Channel



### LM35
* `uint8 LM35_GetTemperature(void)`:  Function responsible for calculate the temperature from the ADC digital value.


### Motor
* `void DcMotor_Init(void)`:The Function responsible for setup the direction for the two motor pins through the GPIO driver.
* `void DcMotor_Rotate(DcMotor_State state,uint8 speed)`: The function is responsible for rotating the DC Motor CW/ or A-CW or stop the motor based on the state input state value and send the required duty cycle to the PWM driver based on the required speed value

### Timer
* `void PWM_Timer0_Start(uint8 duty_cycle)`:Generate PWM Signal on TIMER0 with a specific duty cycle.

## OPTIONS
The timer driver will be updated in the next projects to suit all timers with all modes


 
