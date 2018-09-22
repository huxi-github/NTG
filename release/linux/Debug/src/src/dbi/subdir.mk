################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/hadoop/桌面/ntg\ gtihub/NTG/src/dbi/ntgs_mysql.cpp 

OBJS += \
./src/src/dbi/ntgs_mysql.o 

CPP_DEPS += \
./src/src/dbi/ntgs_mysql.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/dbi/ntgs_mysql.o: /home/hadoop/桌面/ntg\ gtihub/NTG/src/dbi/ntgs_mysql.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


