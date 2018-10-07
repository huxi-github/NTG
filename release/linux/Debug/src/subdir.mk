################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/mnt/hgfs/Documents/NTG10/src/global.cpp \
/mnt/hgfs/Documents/NTG10/src/main.cpp \
/mnt/hgfs/Documents/NTG10/src/maintest.cpp 

OBJS += \
./src/global.o \
./src/main.o \
./src/maintest.o 

CPP_DEPS += \
./src/global.d \
./src/main.d \
./src/maintest.d 


# Each subdirectory must supply rules for building sources it contributes
src/global.o: /mnt/hgfs/Documents/NTG10/src/global.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/mysql" -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/main.o: /mnt/hgfs/Documents/NTG10/src/main.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/mysql" -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/maintest.o: /mnt/hgfs/Documents/NTG10/src/maintest.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/mysql" -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


