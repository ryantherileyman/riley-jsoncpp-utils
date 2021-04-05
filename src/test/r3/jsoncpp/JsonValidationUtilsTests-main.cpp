
#include <assert.h>
#include <iostream>
#include <string>
#include <r3/jsoncpp/r3-jsoncpp-utils.hpp>

Json::Value createJsonValue(const std::string& jsonString) {
	std::stringstream stream(jsonString);

	Json::Value result;
	std::string parseErrors;

	Json::CharReaderBuilder builder = r3::JsonLoaderUtils::createStrictCharReaderBuilder();
	Json::parseFromStream(builder, stream, &result, &parseErrors);

	assert(parseErrors.length() == 0);

	return result;
}

bool testRequiredString(const Json::Value& jsonValue, const char* propertyName, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::requiredString(jsonValue, propertyName);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testOptionalString(const Json::Value& jsonValue, const char* propertyName, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::optionalString(jsonValue, propertyName);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testRequiredBool(const Json::Value& jsonValue, const char* propertyName, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::requiredBool(jsonValue, propertyName);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testRequiredInt(const Json::Value& jsonValue, const char* propertyName, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::requiredInt(jsonValue, propertyName);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testIntInRange(const Json::Value& jsonValue, const char* propertyName, const r3::validation::IntRange& range, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::intInRange(jsonValue, propertyName, range);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testRequiredFloat(const Json::Value& jsonValue, const char* propertyName, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::requiredFloat(jsonValue, propertyName);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testRequiredObject(const Json::Value& jsonValue, const char* propertyName, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::requiredObject(jsonValue, propertyName);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testRequiredArray(const Json::Value& jsonValue, const char* propertyName, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::requiredArray(jsonValue, propertyName);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testOptionalArray(const Json::Value& jsonValue, const char* propertyName, bool expectedResult) {
	bool actualResult = r3::JsonValidationUtils::optionalArray(jsonValue, propertyName);

	bool result = (actualResult == expectedResult);
	return result;
}

int main() {
	std::string jsonString = "{ "
		"\"someBool\": true, "
		"\"someInt\": 5, "
		"\"someFloat\": 2.78, "
		"\"someString\": \"testString\", "
		"\"someObject\": { \"nestedString\": \"testedNest\" }, "
		"\"someArray\": [ 3, 5, 2 ] "
		"}";
	const Json::Value jsonValue = createJsonValue(jsonString);

	assert(testRequiredString(jsonValue, "someString", true));
	assert(testRequiredString(jsonValue, "missingString", false));
	assert(testRequiredString(jsonValue, "nestedString", false));
	assert(testRequiredString(jsonValue["someObject"], "nestedString", true));
	assert(testRequiredString(jsonValue, "someBool", false));

	assert(testOptionalString(jsonValue, "someString", true));
	assert(testOptionalString(jsonValue, "missingString", true));
	assert(testOptionalString(jsonValue, "someBool", false));

	assert(testRequiredBool(jsonValue, "someBool", true));
	assert(testRequiredBool(jsonValue, "missingBool", false));
	assert(testRequiredBool(jsonValue, "someString", false));

	assert(testRequiredInt(jsonValue, "someInt", true));
	assert(testRequiredInt(jsonValue, "missingInt", false));
	assert(testRequiredInt(jsonValue, "someBool", false));

	assert(testIntInRange(jsonValue, "someInt", r3::validation::IntRange::createMax(5), true));
	assert(testIntInRange(jsonValue, "someInt", r3::validation::IntRange::createMax(4), false));
	assert(testIntInRange(jsonValue, "missingInt", r3::validation::IntRange::createMax(5), true));

	assert(testRequiredFloat(jsonValue, "someFloat", true));
	assert(testRequiredFloat(jsonValue, "missingFloat", false));
	assert(testRequiredFloat(jsonValue, "someBool", false));

	assert(testRequiredObject(jsonValue, "someObject", true));
	assert(testRequiredObject(jsonValue, "missingObject", false));
	assert(testRequiredObject(jsonValue, "someArray", false));

	assert(testRequiredArray(jsonValue, "someArray", true));
	assert(testRequiredArray(jsonValue, "missingArray", false));
	assert(testRequiredArray(jsonValue, "someObject", false));

	assert(testOptionalArray(jsonValue, "someArray", true));
	assert(testOptionalArray(jsonValue, "missingArray", true));
	assert(testOptionalArray(jsonValue, "someObject", false));

	std::cout << "All tests passed!\n";
	return 0;
}
