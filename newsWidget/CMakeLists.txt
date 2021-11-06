cmake_minimum_required(VERSION 3.20)
project(NewsProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(BOOST_ROOT"/home/darwin/Desktop/Boost/boost_1_61_0")
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Boost 1.57.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Can't Find Boost")
endif()

set(Qt5_DIR "/usr/lib/x86_64-linux-gnu")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)


add_executable(NewsProject main.cpp APIRequest.cpp APIRequest.h articleData.cpp articleData.h)
target_link_libraries(NewsProject Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network)
