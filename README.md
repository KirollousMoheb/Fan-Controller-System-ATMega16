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




### LCD




### ADC



### LM35


### Motor


### Timer





 
