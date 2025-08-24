/* An example json parse in c++ */

/* 

{
	"Key": "Value",
	"Key": 123.0 | 123,
	"Key": true | false,
	"Key": { }
}
	TODO: JSON Parser
		-1. Str, Str
		-2. Str, int
		-3. Str, 

	Functions:
	 	trim();
		checkEnds();
		eatWhiteSpace();
		readKey();
		readValue(); -> Str, Number, Bool, Nested Object

*/


#include <iostream>

void v_trim(std::string& _str) {
	std::string whitespace = " \t\n\r\f\v";
	size_t start = _str.find_first_not_of(whitespace);

	if (start == std::string::npos) {
		_str.clear();
		return;
	}

	size_t end = _str.find_last_not_of(whitespace);
	_str = _str.substr(start, end - start + 1);
	return;
}

bool b_checkEnds(std::string& _str) {
	if (_str[0] != '{' || _str[_str.length() - 1] != '}') {
		std::cout << "Ends of JSON Object aren't correct\n";
		return false;
	}
	std::cout << "Ends check Successful ...\n";
	return true;
}

void v_ltrim(std::string& _str) {
	std::string whitespace = " \t\n\r\f\v";
	size_t start = _str.find_first_not_of(whitespace);
	if (start == std::string::npos) {
		std::cout << "Error while eating whitespace\n";
		_str.clear();
		return;
	}
	_str = _str.substr(start, _str.length() - 1);
	return;
}

std::string str_readKey(std::string& _str) {
	if (_str[0] != '"') {
		std::cout << "Error: Keyname isn't starting w/ '\"' \n";
		return "";
	}

	// Find next occurance of '"'
	for (size_t i = 1; i < _str.length(); i++) {
		if (_str[i] == '"') {
			return _str.substr(1, i - 1);
		}
	}

	std::cout << "Error: Keyname isn't ending w/ '\"' \n";
	return "";
}


// TODO: check for ':' in between Key and Value;

std::string str_readValue(std::string& _str) {
	// Checks if value is of type std::string
	if (_str[0] != '"') {
		std::cout << "Error: Str_Value isn't starting w/ '\"' \n";
		return "";
	}

	// Find next occurance of '"'
	for (size_t i = 1; i < _str.length(); i++) {
		if (_str[i] == '"') {
			std::string valueStr = _str.substr(1, i - 1);
			v_trim(valueStr);
			return valueStr;
		}
	}

	std::cout << "Error: Str_Value isn't ending w/ '\"' \n";
	return "";
}

int main(void) {
	// int ip1;
	// std::string str1 = "  Hello World   \n";
	// std::string str1 = "  \t{   }\n";
	std::string str1 = "\" Keyname \"\n";
	std::cout << str1 << "\n";

	// v_trim(str1);
	// b_checkEnds(str1);
	// v_ltrim(str1);

	// str1 = str_readKey(str1);
	str1 = str_readValue(str1);
	std::cout << str1 << "\n";
	
	return 0;
}
