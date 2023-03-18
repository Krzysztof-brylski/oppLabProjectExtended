cmake_minimum_required(VERSION 3.23)
project(oppLabProjectExtended)

set(CMAKE_CXX_STANDARD 23)

add_executable(oppLabProjectExtended main.cpp views/viewInterface.h views/stack/viewStack.h file/fileDriver.cpp views/stack/viewStack.cpp views/main/mainView.cpp)
