
cmake_minimum_required(VERSION 3.19)

project(RileyJsonCppUtils VERSION 1.0)

add_subdirectory(dependencies/riley-cpp-utils)
add_subdirectory(dependencies/json-cpp)

option(RILEY_JSONCPP_UTILS_WITH_TESTS "Build and run RileyJsonCppUtils test executables" ON)

add_subdirectory(src/main/r3/jsoncpp)

if (${RILEY_JSONCPP_UTILS_WITH_TESTS})
	enable_testing()
	add_subdirectory(src/test/r3/jsoncpp)
endif()
