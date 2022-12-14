################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../WiFi/Src/es_wifi.c \
../WiFi/Src/es_wifi_io.c \
../WiFi/Src/wifi.c 

OBJS += \
./WiFi/Src/es_wifi.o \
./WiFi/Src/es_wifi_io.o \
./WiFi/Src/wifi.o 

C_DEPS += \
./WiFi/Src/es_wifi.d \
./WiFi/Src/es_wifi_io.d \
./WiFi/Src/wifi.d 


# Each subdirectory must supply rules for building sources it contributes
WiFi/Src/%.o WiFi/Src/%.su: ../WiFi/Src/%.c WiFi/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx '-D_packed=__attribute__((__packed__))' '-D_weak=__attribute__((__weak__))' -c -I../Drivers/BSP/Components/lsm6dsl -I../Middlewares/Third_Party/SEGGER -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../WiFi/inc -I../X-CUBE-MEMS1/Target -I../Drivers/BSP/B-L475E-IOT01A1 -I../Drivers/BSP/Components/lis3mdl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-WiFi-2f-Src

clean-WiFi-2f-Src:
	-$(RM) ./WiFi/Src/es_wifi.d ./WiFi/Src/es_wifi.o ./WiFi/Src/es_wifi.su ./WiFi/Src/es_wifi_io.d ./WiFi/Src/es_wifi_io.o ./WiFi/Src/es_wifi_io.su ./WiFi/Src/wifi.d ./WiFi/Src/wifi.o ./WiFi/Src/wifi.su

.PHONY: clean-WiFi-2f-Src

