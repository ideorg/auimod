cmake_minimum_required(VERSION 3.7)
project(auimod)

set(CMAKE_CXX_STANDARD 11)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Werror=return-type")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

set(wxWidgets_ROOT_DIR /usr/include/wx-3.0)
set(wxWidgets_INCLUDE_DIRS /usr/include/wx-3.0)
set(wxWidgets_LIBRARIES/usr/lib/x86_64-linux-gnu)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES
        framemanager.cpp
        auibook.cpp
        tabmdi.cpp
        tabart.cpp
        tabartmsw.cpp
        dockart.cpp
        floatpane.cpp
        auibar.cpp
        )
add_library(auimod ${SOURCE_FILES})

target_link_libraries(auimod ${wxWidgets_LIBRARIES})