cmake_minimum_required(VERSION 3.10)

# Project name
project(SuDoKu)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(interfaces queue logging)

# Find Boost
find_package(Boost REQUIRED COMPONENTS log log_setup)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_definitions(-DBOOST_LOG_DYN_LINK)
endif()

# Logging utilities sources
file(GLOB LOGGING_SOURCES "logging/*.cpp")

set(SOURCES
    SuDoKu.cpp
    ${LOGGING_SOURCES}
)

# Add executable
add_executable(sudoku ${SOURCES})

# Link Boost libraries
target_link_libraries(sudoku ${Boost_LIBRARIES})