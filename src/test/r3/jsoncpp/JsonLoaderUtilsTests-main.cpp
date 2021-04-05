
#include <assert.h>
#include <iostream>
#include <r3/jsoncpp/r3-jsoncpp-utils.hpp>

bool testLoadFromJsonFile_InvalidFile() {
	r3::JsonLoaderUtils::LoadJsonDataResult jsonDataResult = r3::JsonLoaderUtils::loadFromJsonFile("test-resources/r3/jsoncpp/invalid.json");
	bool result = (jsonDataResult.parseErrorString.length() > 0);
	return result;
}

bool testLoadFromJsonFile_ValidFile() {
	r3::JsonLoaderUtils::LoadJsonDataResult jsonDataResult = r3::JsonLoaderUtils::loadFromJsonFile("test-resources/r3/jsoncpp/valid.json");
	bool result =
		(jsonDataResult.parseErrorString.length() == 0) &&
		!jsonDataResult.jsonValue["weWontGetHere"].asBool();
	return result;
}

int main() {
	assert(testLoadFromJsonFile_InvalidFile());
	assert(testLoadFromJsonFile_ValidFile());

	std::cout << "All tests passed!\n";
	return 0;
}
