cmake_minimum_required(VERSION 3.20)
project(newest8)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(newest8 main.cpp UserSystem.cpp UserSystem.h User.cpp User.h)

target_link_libraries(newest8
${Boost_FILESYSTEM_LIBRARY}
${Boost_SYSTEM_LIBRARY}
)

target_link_libraries(newest8 jsoncpp)
