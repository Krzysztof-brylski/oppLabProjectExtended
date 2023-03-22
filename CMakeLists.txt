cmake_minimum_required(VERSION 3.23)
project(oppLabProjectExtended)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(
        oppLabProjectExtended
        main.cpp
        sheet/sheet.cpp
        file/fileDriver.cpp
        math/math.cpp
        cells/cellInterface.h
        cells/float/floatCell.cpp
        cells/int/intCell.cpp
        cells/string/stringCell.cpp
        views/viewInterface.h
        views/stack/viewStack.h
        views/stack/viewStack.cpp
        views/main/mainView.cpp
        views/sheet/create/createSheet.cpp
        views/sheet/load/loadSheet.cpp
        views/sheet/resize/resizeSheet.cpp
        views/sheet/valueSetter/sheetCellValueSet.cpp
        views/sheet/saveInFIle/saveSheet.cpp
        views/sheet/display/displaySheetView.cpp
        views/default/defaultView.cpp
        views/error/errorView.cpp
)




