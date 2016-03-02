cmake_minimum_required(VERSION 3.3)
project(tok)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})




set(SOURCE_FILES main.cpp src/ErrorHandler.cpp src/ErrorHandler.h src/SdlInitializer.cpp src/SdlInitializer.h src/Timer.cpp src/Timer.h src/StateInterface.cpp src/StateInterface.h src/StateMachine.cpp src/StateMachine.h src/MainClass.cpp src/MainClass.h)
add_executable(tok ${SOURCE_FILES})
target_link_libraries(tok ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})

