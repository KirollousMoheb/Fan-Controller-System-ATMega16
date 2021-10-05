################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mini_Project3.c \
../adc.c \
../gpio.c \
../lcd.c \
../motor.c \
../temp_sensor.c \
../timer.c 

OBJS += \
./Mini_Project3.o \
./adc.o \
./gpio.o \
./lcd.o \
./motor.o \
./temp_sensor.o \
./timer.o 

C_DEPS += \
./Mini_Project3.d \
./adc.d \
./gpio.d \
./lcd.d \
./motor.d \
./temp_sensor.d \
./timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


