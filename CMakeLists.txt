cmake_minimum_required(VERSION 3.3)
project(tok)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})



set(SOURCE_FILES main.cpp src/ErrorHandler.cpp src/ErrorHandler.h src/SdlInitializer.cpp src/SdlInitializer.h src/Timer.cpp src/Timer.h src/StateMachine.cpp src/StateMachine.h src/MainClass.cpp src/MainClass.h src/Sprite.cpp src/Sprite.h src/Locamap.cpp src/Locamap.h src/MainCharacter.cpp src/MainCharacter.h src/GameMenu.cpp src/GameMenu.h src/Buildings.cpp src/Buildings.h src/CollisionRect.cpp src/CollisionRect.h src/EnviromentObjects.cpp src/EnviromentObjects.h src/TreeObject.cpp src/TreeObject.h)
add_executable(tok ${SOURCE_FILES})
target_link_libraries(tok ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})

add_custom_command(TARGET tok POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:tok>/assets)

add_custom_command(TARGET tok POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/maps
        $<TARGET_FILE_DIR:tok>/maps)

