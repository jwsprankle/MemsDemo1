################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/bsp_lis3mdl.c \
../Core/Src/bsp_lsm6dsl.c \
../Core/Src/debug_analyzer.c \
../Core/Src/es_wifi_conf.c \
../Core/Src/freertos.c \
../Core/Src/main.c \
../Core/Src/mems_task.c \
../Core/Src/remote_comm_task.c \
../Core/Src/sensor_bus1.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_hal_timebase_tim.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c 

OBJS += \
./Core/Src/bsp_lis3mdl.o \
./Core/Src/bsp_lsm6dsl.o \
./Core/Src/debug_analyzer.o \
./Core/Src/es_wifi_conf.o \
./Core/Src/freertos.o \
./Core/Src/main.o \
./Core/Src/mems_task.o \
./Core/Src/remote_comm_task.o \
./Core/Src/sensor_bus1.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_hal_timebase_tim.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o 

C_DEPS += \
./Core/Src/bsp_lis3mdl.d \
./Core/Src/bsp_lsm6dsl.d \
./Core/Src/debug_analyzer.d \
./Core/Src/es_wifi_conf.d \
./Core/Src/freertos.d \
./Core/Src/main.d \
./Core/Src/mems_task.d \
./Core/Src/remote_comm_task.d \
./Core/Src/sensor_bus1.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_hal_timebase_tim.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx '-D_packed=__attribute__((__packed__))' '-D_weak=__attribute__((__weak__))' -c -I../Drivers/BSP/Components/lsm6dsl -I../Middlewares/Third_Party/SEGGER -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../WiFi/inc -I../X-CUBE-MEMS1/Target -I../Drivers/BSP/B-L475E-IOT01A1 -I../Drivers/BSP/Components/lis3mdl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/bsp_lis3mdl.d ./Core/Src/bsp_lis3mdl.o ./Core/Src/bsp_lis3mdl.su ./Core/Src/bsp_lsm6dsl.d ./Core/Src/bsp_lsm6dsl.o ./Core/Src/bsp_lsm6dsl.su ./Core/Src/debug_analyzer.d ./Core/Src/debug_analyzer.o ./Core/Src/debug_analyzer.su ./Core/Src/es_wifi_conf.d ./Core/Src/es_wifi_conf.o ./Core/Src/es_wifi_conf.su ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mems_task.d ./Core/Src/mems_task.o ./Core/Src/mems_task.su ./Core/Src/remote_comm_task.d ./Core/Src/remote_comm_task.o ./Core/Src/remote_comm_task.su ./Core/Src/sensor_bus1.d ./Core/Src/sensor_bus1.o ./Core/Src/sensor_bus1.su ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_hal_timebase_tim.d ./Core/Src/stm32l4xx_hal_timebase_tim.o ./Core/Src/stm32l4xx_hal_timebase_tim.su ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su

.PHONY: clean-Core-2f-Src

