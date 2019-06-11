cmake_minimum_required (VERSION 3.8)

project(cpp-pattern)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_subdirectory(11_Builder)
add_subdirectory(12_Factory)
add_subdirectory(13_Abstract_Factory)
add_subdirectory(14_Prototype)
add_subdirectory(15_Singleton)

add_subdirectory(99_template)
