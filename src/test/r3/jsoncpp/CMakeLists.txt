
add_executable(
	JsonLoaderUtilsTests
	JsonLoaderUtilsTests-main.cpp
)
target_link_libraries(
	JsonLoaderUtilsTests PRIVATE
	r3-ValidationUtils-lib
	jsoncpp_static
	r3-JsonCppUtils-lib
)
target_include_directories(JsonLoaderUtilsTests PUBLIC "${PROJECT_SOURCE_DIR}/include")
add_custom_command(
	TARGET JsonLoaderUtilsTests
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/src/test-resources $<TARGET_FILE_DIR:JsonLoaderUtilsTests>/test-resources
)

add_executable(
	JsonValidationUtilsTests
	JsonValidationUtilsTests-main.cpp
)
target_link_libraries(
	JsonValidationUtilsTests
	r3-ValidationUtils-lib
	jsoncpp_static
	r3-JsonCppUtils-lib
)
target_include_directories(JsonValidationUtilsTests PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_test(NAME JsonLoaderUtils COMMAND JsonLoaderUtilsTests)
add_test(NAME JsonValidationUtils COMMAND JsonValidationUtilsTests)
