################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GPA\ Calculator.cpp 

OBJS += \
./GPA\ Calculator.o 

CPP_DEPS += \
./GPA\ Calculator.d 


# Each subdirectory must supply rules for building sources it contributes
GPA\ Calculator.o: ../GPA\ Calculator.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"GPA Calculator.d" -MT"GPA\ Calculator.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


