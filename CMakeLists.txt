cmake_minimum_required(VERSION 3.16)
project(PID_PROJECT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_executable(pid_app
    src/main.cpp
    src/PID.cpp
    src/DCMotor.cpp
)   