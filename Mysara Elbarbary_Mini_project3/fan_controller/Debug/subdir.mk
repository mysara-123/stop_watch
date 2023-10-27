################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DC_Motor.c \
../LM35.c \
../PWM.c \
../gpio.c \
../lcd.c \
../main.c 

OBJS += \
./ADC.o \
./DC_Motor.o \
./LM35.o \
./PWM.o \
./gpio.o \
./lcd.o \
./main.o 

C_DEPS += \
./ADC.d \
./DC_Motor.d \
./LM35.d \
./PWM.d \
./gpio.d \
./lcd.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


