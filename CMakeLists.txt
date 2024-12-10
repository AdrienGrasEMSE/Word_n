# CMakeLists.txt for Word_n project

# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Word_n)

# Specify that we are using C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Add the include path for Word_n headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the Word_n_unitary submodule as a dependency
add_subdirectory(external/Word_n_unitary)



# Set the sources of your test executable
set(TEST_SOURCES
    tests/Tests_word_n.cpp
)

# Create the test executable
add_executable(Tests_word_n ${TEST_SOURCES})



# Link to the Word_n_unitary library
target_link_libraries(Tests_word_n PRIVATE Word_n_unitary_lib)
