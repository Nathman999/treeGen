cmake_minimum_required(VERSION 3.1)
project(SFMLTest)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(SFMLTest main.cpp)
target_link_libraries(SFMLTest ${CONAN_LIBS})