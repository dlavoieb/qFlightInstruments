cmake_minimum_required(VERSION 3.6)
project(qFlightInstruments)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

set(SOURCE_FILES
    main.cpp
    qFlightInstruments.cpp
    qFlightInstruments.h
    TestWin.cpp
    TestWin.h
    QAttitude.cpp
    QAttitude.h
    QCompass.cpp
    QCompass.h)

add_executable(qFlightInstruments ${SOURCE_FILES})

# Use the Widgets module from Qt 5.
target_link_libraries(qFlightInstruments Qt5::Widgets)