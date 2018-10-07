################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/mnt/hgfs/Documents/NTG10/src/lib/error.cpp \
/mnt/hgfs/Documents/NTG10/src/lib/tcp_connect.cpp \
/mnt/hgfs/Documents/NTG10/src/lib/wrapsock.cpp \
/mnt/hgfs/Documents/NTG10/src/lib/wrapunix.cpp 

OBJS += \
./src/lib/error.o \
./src/lib/tcp_connect.o \
./src/lib/wrapsock.o \
./src/lib/wrapunix.o 

CPP_DEPS += \
./src/lib/error.d \
./src/lib/tcp_connect.d \
./src/lib/wrapsock.d \
./src/lib/wrapunix.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/error.o: /mnt/hgfs/Documents/NTG10/src/lib/error.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/mysql" -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/lib/tcp_connect.o: /mnt/hgfs/Documents/NTG10/src/lib/tcp_connect.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/mysql" -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/lib/wrapsock.o: /mnt/hgfs/Documents/NTG10/src/lib/wrapsock.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/mysql" -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/lib/wrapunix.o: /mnt/hgfs/Documents/NTG10/src/lib/wrapunix.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/mysql" -I"/mnt/hgfs/Documents/NTG10/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


