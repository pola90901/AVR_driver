################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
STepper_motor.lss \

FLASH_IMAGE += \
STepper_motor.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: STepper_motor.elf secondary-outputs

# Tool invocations
STepper_motor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,STepper_motor.map -mmcu=atmega32 -o "STepper_motor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

STepper_motor.lss: STepper_motor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S STepper_motor.elf  >"STepper_motor.lss"
	@echo 'Finished building: $@'
	@echo ' '

STepper_motor.hex: STepper_motor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex STepper_motor.elf  "STepper_motor.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: STepper_motor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 STepper_motor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) STepper_motor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
