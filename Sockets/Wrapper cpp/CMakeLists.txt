cmake_minimum_required(VERSION 3.2)

project("Wrapper cpp")

include_directories(${CMAKE_SOURCE_DIR})

add_library(Socket "Socket.cpp")

add_executable(trial "${CMAKE_SOURCE_DIR}/trial.cpp")

target_link_libraries(trial Socket)