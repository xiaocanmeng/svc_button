cmake_minimum_required(VERSION 3.16)

project(SVC_command)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
# include_directories(/usr/include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fPIC")
#增加宏
add_definitions(-DIostream=1)

# Warning option Suppression
add_compile_options(-Wno-unused-parameter)
add_compile_options(-Wno-sign-conversion)


set(${PROJECT_NAME}
    ./src/sendcommand.cpp
    ./src/menu.cpp
    ./main.cpp)
# add debug
SET(CMAKE_BUILD_TYPE "Debug") 

# sudo apt-get install libjsoncpp-dev

find_package(Boost 1.62.0 REQUIRED
             COMPONENTS system filesystem thread)
find_package(Threads REQUIRED)


add_executable(${PROJECT_NAME}  ${SVC_command})
add_definitions("-Wall -g")
set(lib_DIR /usr/lib/x84_64-linux-gnu)
link_directories(${lib_DIR})
target_link_libraries(${PROJECT_NAME} libjsoncpp.so)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
# 添加链接 menu  库
target_link_libraries(${PROJECT_NAME} menu) 
# 添加链接 ncurses 库
target_link_libraries(${PROJECT_NAME} ncurses)
# 链接svc_hal库
# ARRCH64
target_link_directories(${PROJECT_NAME} PRIVATE /home/dev/work/sdk/20.0.A/sysroots/aarch64-arene-linux/opt/arene/lib)
target_link_libraries(${PROJECT_NAME}  libcamera_event_capture_hal.so)
# X64

# target_link_libraries(${PROJECT_NAME} halcomm)
# target_link_directories(${PROJECT_NAME} PRIVATE /home/dev/work/mengqingge/cpp_test/test_project)
# target_link_libraries(${PROJECT_NAME}  libcamera_event_capture_hal.a)

