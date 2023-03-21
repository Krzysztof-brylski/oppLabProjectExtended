cmake_minimum_required(VERSION 3.23)
project(oppLabProjectExtended)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(
        oppLabProjectExtended
        main.cpp

        file/fileDriver.cpp
        cells/cellInterface.h
        cells/float/floatCell.cpp
        cells/int/intCell.cpp
        cells/string/stringCell.cpp
)
#views/viewInterface.h
#views/stack/viewStack.h
#views/sheet/create/createSheet.cpp
#views/sheet/display/displaySheetView.cpp
#views/stack/viewStack.cpp
#views/main/mainView.cpp
#views/error/errorView.cpp
#views/default/defaultView.cpp