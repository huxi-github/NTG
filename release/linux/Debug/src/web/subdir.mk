################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/hadoop/桌面/tips/NTG/src/web/web.cpp 

OBJS += \
./src/web/web.o 

CPP_DEPS += \
./src/web/web.d 


# Each subdirectory must supply rules for building sources it contributes
src/web/web.o: /home/hadoop/桌面/tips/NTG/src/web/web.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


