################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Fan-Controller-System-ATMega16/Mini_Project3.c \
../Fan-Controller-System-ATMega16/adc.c \
../Fan-Controller-System-ATMega16/gpio.c \
../Fan-Controller-System-ATMega16/lcd.c \
../Fan-Controller-System-ATMega16/motor.c \
../Fan-Controller-System-ATMega16/temp_sensor.c \
../Fan-Controller-System-ATMega16/timer.c 

OBJS += \
./Fan-Controller-System-ATMega16/Mini_Project3.o \
./Fan-Controller-System-ATMega16/adc.o \
./Fan-Controller-System-ATMega16/gpio.o \
./Fan-Controller-System-ATMega16/lcd.o \
./Fan-Controller-System-ATMega16/motor.o \
./Fan-Controller-System-ATMega16/temp_sensor.o \
./Fan-Controller-System-ATMega16/timer.o 

C_DEPS += \
./Fan-Controller-System-ATMega16/Mini_Project3.d \
./Fan-Controller-System-ATMega16/adc.d \
./Fan-Controller-System-ATMega16/gpio.d \
./Fan-Controller-System-ATMega16/lcd.d \
./Fan-Controller-System-ATMega16/motor.d \
./Fan-Controller-System-ATMega16/temp_sensor.d \
./Fan-Controller-System-ATMega16/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Fan-Controller-System-ATMega16/%.o: ../Fan-Controller-System-ATMega16/%.c Fan-Controller-System-ATMega16/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


