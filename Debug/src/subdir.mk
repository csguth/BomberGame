################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Arena.cpp \
../src/BombGame.cpp \
../src/CarryingBombs.cpp \
../src/Cell.cpp \
../src/KeyboardInput.cpp \
../src/SimpleBomb.cpp \
../src/SimpleBomberManWalkingState.cpp \
../src/SimpleBomberman.cpp \
../src/SimpleBombermanStandingState.cpp \
../src/SimpleBombermanStateDecorator.cpp \
../src/SimpleFire.cpp \
../src/VideoConfiguration.cpp \
../src/WalkableSimpleBomberMan.cpp \
../src/Wall.cpp \
../src/b2SFMLRenderWindowDrawer.cpp \
../src/main.cpp 

OBJS += \
./src/Arena.o \
./src/BombGame.o \
./src/CarryingBombs.o \
./src/Cell.o \
./src/KeyboardInput.o \
./src/SimpleBomb.o \
./src/SimpleBomberManWalkingState.o \
./src/SimpleBomberman.o \
./src/SimpleBombermanStandingState.o \
./src/SimpleBombermanStateDecorator.o \
./src/SimpleFire.o \
./src/VideoConfiguration.o \
./src/WalkableSimpleBomberMan.o \
./src/Wall.o \
./src/b2SFMLRenderWindowDrawer.o \
./src/main.o 

CPP_DEPS += \
./src/Arena.d \
./src/BombGame.d \
./src/CarryingBombs.d \
./src/Cell.d \
./src/KeyboardInput.d \
./src/SimpleBomb.d \
./src/SimpleBomberManWalkingState.d \
./src/SimpleBomberman.d \
./src/SimpleBombermanStandingState.d \
./src/SimpleBombermanStateDecorator.d \
./src/SimpleFire.d \
./src/VideoConfiguration.d \
./src/WalkableSimpleBomberMan.d \
./src/Wall.d \
./src/b2SFMLRenderWindowDrawer.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


