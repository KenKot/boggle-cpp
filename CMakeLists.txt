cmake_minimum_required(VERSION 3.16)
project(boggle-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create executable
add_executable(boggle 
    DictMain.cpp 
    Dict.cpp
)

add_custom_target(run
    COMMAND boggle
    DEPENDS boggle
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Building and running boggle..."
)
