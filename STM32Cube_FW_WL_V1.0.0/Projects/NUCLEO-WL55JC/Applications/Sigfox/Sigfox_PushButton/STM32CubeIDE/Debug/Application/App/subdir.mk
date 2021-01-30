################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/app_sigfox.c \
C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/ee.c \
C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/sgfx_app.c \
C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/sgfx_cstimer.c \
C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/sgfx_eeprom_if.c 

OBJS += \
./Application/App/app_sigfox.o \
./Application/App/ee.o \
./Application/App/sgfx_app.o \
./Application/App/sgfx_cstimer.o \
./Application/App/sgfx_eeprom_if.o 

C_DEPS += \
./Application/App/app_sigfox.d \
./Application/App/ee.d \
./Application/App/sgfx_app.d \
./Application/App/sgfx_cstimer.d \
./Application/App/sgfx_eeprom_if.d 


# Each subdirectory must supply rules for building sources it contributes
Application/App/app_sigfox.o: C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/app_sigfox.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../Sigfox/App -I../../Sigfox/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/Sigfox/Crypto -I../../../../../../../Middlewares/Third_Party/Sigfox/Monarch -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLib -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLibTest -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/App/app_sigfox.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/App/ee.o: C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/ee.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../Sigfox/App -I../../Sigfox/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/Sigfox/Crypto -I../../../../../../../Middlewares/Third_Party/Sigfox/Monarch -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLib -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLibTest -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/App/ee.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/App/sgfx_app.o: C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/sgfx_app.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../Sigfox/App -I../../Sigfox/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/Sigfox/Crypto -I../../../../../../../Middlewares/Third_Party/Sigfox/Monarch -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLib -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLibTest -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/App/sgfx_app.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/App/sgfx_cstimer.o: C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/sgfx_cstimer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../Sigfox/App -I../../Sigfox/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/Sigfox/Crypto -I../../../../../../../Middlewares/Third_Party/Sigfox/Monarch -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLib -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLibTest -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/App/sgfx_cstimer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/App/sgfx_eeprom_if.o: C:/Users/name/Desktop/SigfoxDemo/STM32Cube_FW_WL_V1.0.0/Projects/NUCLEO-WL55JC/Applications/Sigfox/Sigfox_PushButton/Sigfox/App/sgfx_eeprom_if.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../Sigfox/App -I../../Sigfox/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/Sigfox/Crypto -I../../../../../../../Middlewares/Third_Party/Sigfox/Monarch -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLib -I../../../../../../../Middlewares/Third_Party/Sigfox/SigfoxLibTest -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/App/sgfx_eeprom_if.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

