################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
OBJS += \
./src/src/web/web.o 

CPP_DEPS += \
./src/src/web/web.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/web/web.o: /home/hadoop/桌面/ntg\ gtihub/NTG/src/web/web.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


