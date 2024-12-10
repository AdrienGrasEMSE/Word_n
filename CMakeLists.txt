# CMakeLists.txt for Word_n project

# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Word_n)

# Specify that we are using C++17
set(CMAKE_CXX_STANDARD 17)



# Set the path to include the headers of the library
include_directories(${PROJECT_SOURCE_DIR}/include)          # Local headers of Word_n
include_directories("../Word_n_unitary/include")            # Headers of Word_n_unitary
link_directories("../Word_n_unitary/build")                 # Path to the compiled library

# Ajoute les sources de ton projet
set(SOURCES
    src/Main.cpp
)



# Create the main executable
add_executable(Word_n ${SOURCES})

# Link to the library
target_link_libraries(Word_n Word_n_unitary_lib)



# Enable testing
#enable_testing()

# Ajouter les tests si nécessaire
#add_executable(Tests_word_n tests/Tests_word_n.cpp)
#target_link_libraries(Tests_word_n Word_n_unitary_lib)
