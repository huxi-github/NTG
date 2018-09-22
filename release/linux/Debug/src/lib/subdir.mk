################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/hadoop/桌面/tips/NTG/src/lib/error.cpp \
/home/hadoop/桌面/tips/NTG/src/lib/string.cpp \
/home/hadoop/桌面/tips/NTG/src/lib/tcp_connect.cpp \
/home/hadoop/桌面/tips/NTG/src/lib/wrapsock.cpp \
/home/hadoop/桌面/tips/NTG/src/lib/wrapunix.cpp 

OBJS += \
./src/lib/error.o \
./src/lib/string.o \
./src/lib/tcp_connect.o \
./src/lib/wrapsock.o \
./src/lib/wrapunix.o 

CPP_DEPS += \
./src/lib/error.d \
./src/lib/string.d \
./src/lib/tcp_connect.d \
./src/lib/wrapsock.d \
./src/lib/wrapunix.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/error.o: /home/hadoop/桌面/tips/NTG/src/lib/error.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/lib/string.o: /home/hadoop/桌面/tips/NTG/src/lib/string.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/lib/tcp_connect.o: /home/hadoop/桌面/tips/NTG/src/lib/tcp_connect.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/lib/wrapsock.o: /home/hadoop/桌面/tips/NTG/src/lib/wrapsock.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/lib/wrapunix.o: /home/hadoop/桌面/tips/NTG/src/lib/wrapunix.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


