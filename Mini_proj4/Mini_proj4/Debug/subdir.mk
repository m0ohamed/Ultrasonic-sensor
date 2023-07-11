################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD.c \
../My_GPIO.c \
../Ultrasonic.c \
../Ultrasonic_sensor.c \
../icu.c 

OBJS += \
./LCD.o \
./My_GPIO.o \
./Ultrasonic.o \
./Ultrasonic_sensor.o \
./icu.o 

C_DEPS += \
./LCD.d \
./My_GPIO.d \
./Ultrasonic.d \
./Ultrasonic_sensor.d \
./icu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


