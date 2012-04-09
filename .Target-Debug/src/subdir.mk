################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DatabaseForm.cpp \
../src/DatabaseItems.cpp \
../src/Form1.cpp \
../src/WatchList.cpp \
../src/WatchListEntry.cpp 

OBJS += \
./src/DatabaseForm.o \
./src/DatabaseItems.o \
./src/Form1.o \
./src/WatchList.o \
./src/WatchListEntry.o 

CPP_DEPS += \
./src/DatabaseForm.d \
./src/DatabaseItems.d \
./src/Form1.d \
./src/WatchList.d \
./src/WatchListEntry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/sdk/include" -I"C:/bada/sdk/WatchList/inc" -O0 -g -Wall -c -funsigned-char -fshort-wchar -fpic -mthumb -mthumb-interwork -mfpu=vfp -mfloat-abi=softfp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"C:/bada/sdk/include" -I"C:/bada/sdk/WatchList/inc" -O0 -g -Wall -E -funsigned-char -fshort-wchar -fpic -mthumb -mthumb-interwork -mfpu=vfp -mfloat-abi=softfp -o"C:/bada/sdk/repository/WatchList/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


