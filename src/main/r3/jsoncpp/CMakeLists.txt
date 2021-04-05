
set(R3_JSONCPP_UTILS_EXPORT_ALL_SYMBOLS ${CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

set(R3_JSONCPP_UTILS_SOURCES
	r3-jsoncpp-JsonLoaderUtils.cpp
	r3-jsoncpp-JsonValidationUtils.cpp
)

add_library(
	r3-JsonCppUtils-lib STATIC
	${R3_JSONCPP_UTILS_SOURCES}
)
target_link_libraries(
	r3-JsonCppUtils-lib PRIVATE
	jsoncpp_static
	r3-ValidationUtils-lib
)
target_include_directories(r3-JsonCppUtils-lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(
	r3-JsonCppUtils-shared SHARED
	${R3_JSONCPP_UTILS_SOURCES}
)
target_link_libraries(
	r3-JsonCppUtils-shared PRIVATE
	jsoncpp_lib
	r3-ValidationUtils-shared
)
target_include_directories(r3-JsonCppUtils-shared PUBLIC "${PROJECT_SOURCE_DIR}/include")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ${R3_JSONCPP_UTILS_EXPORT_ALL_SYMBOLS})
