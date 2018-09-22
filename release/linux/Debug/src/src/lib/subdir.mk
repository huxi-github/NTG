################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/error.cpp \
/home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/string.cpp \
/home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/tcp_connect.cpp \
/home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/wrapsock.cpp \
/home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/wrapunix.cpp 

OBJS += \
./src/src/lib/error.o \
./src/src/lib/string.o \
./src/src/lib/tcp_connect.o \
./src/src/lib/wrapsock.o \
./src/src/lib/wrapunix.o 

CPP_DEPS += \
./src/src/lib/error.d \
./src/src/lib/string.d \
./src/src/lib/tcp_connect.d \
./src/src/lib/wrapsock.d \
./src/src/lib/wrapunix.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/lib/error.o: /home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/error.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/src/lib/string.o: /home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/string.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/src/lib/tcp_connect.o: /home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/tcp_connect.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/src/lib/wrapsock.o: /home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/wrapsock.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/src/lib/wrapunix.o: /home/hadoop/桌面/ntg\ gtihub/NTG/src/lib/wrapunix.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/ntg gtihub/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


