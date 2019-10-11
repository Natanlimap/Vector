cmake_minimum_required(VERSION 3.5)
project (GraalLibrary VERSION 1.0.0 LANGUAGES CXX )

#=== FINDING PACKAGES ===#

# Locate GTest package (library)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

#Include dir
include_directories( include )

#=== Test target ===

# Esse eh o primeiro "target" que gera o programa que executa os testes.
add_executable(run_tests "test/main.cpp")
# Link with the google test libraries.
target_link_libraries(run_tests PRIVATE ${GTEST_LIBRARIES} PRIVATE pthread )
#set_property(TARGET run_tests PROPERTY CXX_STANDARD 17)
target_compile_features(run_tests PUBLIC cxx_std_11)


# Esse eh o primeiro "target" que gera a aplicação de utiliza o vector apenas para depuração.
add_executable(driver_vector "src/app2.cpp")
#define C++11 as the standard.
target_compile_features(driver_vector PUBLIC cxx_std_11)

