cmake_minimum_required(VERSION 3.1)
project(SFMLTest)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
include_directories(${SFML_DIR}../../../../include/src) 


set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS graphics audio system REQUIRED)

add_executable(SFMLTest main.cpp)
target_link_libraries(SFMLTest sfml-graphics sfml-audio sfml-system)