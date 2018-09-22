################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/hadoop/桌面/tips/NTG/src/utils/gtring.cpp \
/home/hadoop/桌面/tips/NTG/src/utils/http.cpp \
/home/hadoop/桌面/tips/NTG/src/utils/scanroutine.cpp \
/home/hadoop/桌面/tips/NTG/src/utils/text.cpp \
/home/hadoop/桌面/tips/NTG/src/utils/threadpool.cpp \
/home/hadoop/桌面/tips/NTG/src/utils/url.cpp 

OBJS += \
./src/utils/gtring.o \
./src/utils/http.o \
./src/utils/scanroutine.o \
./src/utils/text.o \
./src/utils/threadpool.o \
./src/utils/url.o 

CPP_DEPS += \
./src/utils/gtring.d \
./src/utils/http.d \
./src/utils/scanroutine.d \
./src/utils/text.d \
./src/utils/threadpool.d \
./src/utils/url.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/gtring.o: /home/hadoop/桌面/tips/NTG/src/utils/gtring.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/utils/http.o: /home/hadoop/桌面/tips/NTG/src/utils/http.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/utils/scanroutine.o: /home/hadoop/桌面/tips/NTG/src/utils/scanroutine.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/utils/text.o: /home/hadoop/桌面/tips/NTG/src/utils/text.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/utils/threadpool.o: /home/hadoop/桌面/tips/NTG/src/utils/threadpool.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/utils/url.o: /home/hadoop/桌面/tips/NTG/src/utils/url.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/mysql" -I"/home/hadoop/桌面/tips/NTG/thirdparty/headers/zdb" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


