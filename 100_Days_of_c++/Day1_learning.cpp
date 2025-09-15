/*
 * Author: Ashutosh Tiwari
 * Day no: 1
 * Date: 14th September 2025
 * File name: String class basics with c-string concepts
 */

#include <cctype>
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

enum class String_result {
	SUCCESS = 0,
	NULL_POINTER = -1,
	EMPTY_STRING = -2,
	INVALID_INPUT = -3,
	BUFFER_OVERFLOW = -4
};

enum class Character_type {
	LOWERCASE = 0,
	UPPERCASE = 1,
	NON_ALPHABETIC = 2,
	INVALID_CHAR = -1,

};

/**
 * @brief Function to calculate the string length (characters count)
 * @param str Character array pointer (input string)
 * @param length Pointer to store calculated length (output parameter)
 * @param max_safe_length Maximum safe length to prevent infinite loops
 * @return String_result indicating success or specific error type
 * @note Thread-safe, handles null inputs gracefully
 * @example
 *   size_t len;
 *   String_result result = calculate_string_length("hello", &len, 1000);
 *   if (result == String_result::SUCCESS) {
 *       cout << "Length: " << len << endl;
 *   }
 */

String_result calculate_string_length(const char *str, size_t *length,
		size_t max_safe_length = 100000) {
	if (!str) {
		return String_result::NULL_POINTER;
	}

	if (!length) {
		return String_result::INVALID_INPUT;
	}

	if (max_safe_length == 0) {
		return String_result::INVALID_INPUT;
	}

	*length = 0;

	// safety bounds checking - Maximum length limits

	size_t len = 0;
	while (str[len] != '\0' && len < max_safe_length) {
		++len;
	}

	// check for potential buffer overflow or unterminated string

	if (len >= max_safe_length && str[len] != '\0') {
		return String_result::BUFFER_OVERFLOW;
	}

	// edge case handling

	if (len == 0) {
		*length = 0;
		return String_result::EMPTY_STRING;
	}

	*length = len;
	return String_result::SUCCESS;
}

/**
 * @brief Checks if the given character is lowercase alphabetic
 * @param ch Character to be checked
 * @param char_type Pointer to store character type classification
 * @return String_result indicating success or error in classification
 * @note Pure function - no side effects, thread-safe
 * @example
 *   Character_type type;
 *   String_result result = check_character_case('a', &type);
 *   if (result == String_result::SUCCESS && type == Character_type::LOWERCASE)
 * { cout << "Character is lowercase" << endl;
 *   }
 */

String_result check_character_case(char ch, Character_type *char_type) {
	if (!char_type) {
		return String_result::INVALID_INPUT;
	}

	// safety bound checking -> cast to unsigned char for safety

	unsigned char uch = static_cast<unsigned char>(ch);

	// edge case handling -> non alphabetic characters
	if (!std::isalpha(uch)) {
		*char_type = Character_type::NON_ALPHABETIC;
		return String_result::SUCCESS;
	}

	// check case using standard library functions for robustness

	if (std::islower(uch)) {
		*char_type = Character_type::LOWERCASE;
	} else if (std::isupper(uch)) {
		*char_type = Character_type::UPPERCASE;
	} else {
		*char_type = Character_type::INVALID_CHAR;
		return String_result::INVALID_INPUT;
	}

	return String_result::SUCCESS;
}

/**
 * @brief Checks if character is specifically lowercase (helper function)
 * @param ch Character to check
 * @param is_lower Pointer to store boolean result
 * @return String_result indicating operation success/failure
 */

String_result is_character_lowercasecase(char ch, bool *is_lower) {
	if (!is_lower) {
		return String_result::INVALID_INPUT;
	}

	Character_type type;
	String_result result = check_character_case(ch, &type);

	if (result != String_result::SUCCESS) {
		return result;
	}

	*is_lower = (type == Character_type::LOWERCASE);
	return String_result::SUCCESS;
}

/**
 * @brief Checks if character is specifically uppercase (helper function)
 * @param ch Character to check
 * @param is_upper Pointer to store boolean result
 * @return String_result indicating operation success/failure
 */
String_result is_character_uppercase(char ch, bool *is_upper) {
	if (!is_upper) {
		return String_result::INVALID_INPUT;
	}

	Character_type type;
	String_result result = check_character_case(ch, &type);

	if (result != String_result::SUCCESS) {
		return result;
	}

	*is_upper = (type == Character_type::UPPERCASE);
	return String_result::SUCCESS;
}

// ✅ 7. Proper Error Messages - User-friendly error reporting
const char *get_error_message(String_result result) {
	switch (result) {
		case String_result::SUCCESS:
			return "✅ Operation completed successfully";
		case String_result::NULL_POINTER:
			return "❌ Error: Null pointer provided";
		case String_result::EMPTY_STRING:
			return "ℹ️  Info: Empty string detected";
		case String_result::INVALID_INPUT:
			return "❌ Error: Invalid input parameters";
		case String_result::BUFFER_OVERFLOW:
			return "❌ Error: String too long or not null-terminated";
		default:
			return "❌ Error: Unknown error occurred";
	}
}

const char *get_character_type_name(Character_type type) {
	switch (type) {
		case Character_type::LOWERCASE:
			return "lowercase alphabetic";
		case Character_type::UPPERCASE:
			return "uppercase alphabetic";
		case Character_type::NON_ALPHABETIC:
			return "non-alphabetic";
		case Character_type::INVALID_CHAR:
			return "invalid character";
		default:
			return "unknown type";
	}
}

// ✅ 8. Memory Safety - Safe printing with error handling
void print_character_analysis_safely(char ch) {
	Character_type type;
	String_result result = check_character_case(ch, &type);

	if (result != String_result::SUCCESS) {
		cout << "❌ Error analyzing character '" << ch
			<< "': " << get_error_message(result) << endl;
		return;
	}

	cout << "Character '" << ch << "' is " << get_character_type_name(type)
		<< endl;
}

// Test function with comprehensive error handling
void run_comprehensive_tests() {
	cout << "\n=== Production-Grade String Operations Test Suite ===" << endl;

	// Test 1: String length calculation
	cout << "\n--- Test 1: String Length Calculation ---" << endl;
	const char *test_strings[] = {"Hello World", "", "A", nullptr};

	for (int i = 0; i < 4; ++i) {
		size_t length;
		String_result result = calculate_string_length(test_strings[i], &length);

		if (test_strings[i]) {
			cout << "String: \"" << test_strings[i] << "\" -> ";
		} else {
			cout << "String: nullptr -> ";
		}

		if (result == String_result::SUCCESS ||
				result == String_result::EMPTY_STRING) {
			cout << "Length: " << length << " (" << get_error_message(result) << ")"
				<< endl;
		} else {
			cout << get_error_message(result) << endl;
		}
	}

	// Test 2: Character case analysis
	cout << "\n--- Test 2: Character Case Analysis ---" << endl;
	char test_chars[] = {'A', 'b', '5', ' ', '@', 'Z', 'x'};

	for (char ch : test_chars) {
		print_character_analysis_safely(ch);
	}

	// Test 3: Boolean helper functions
	cout << "\n--- Test 3: Boolean Helper Functions ---" << endl;
	char test_char = 'B';
	bool is_lower, is_upper;

	String_result lower_result = is_character_lowercasecase(test_char, &is_lower);
	String_result upper_result = is_character_uppercase(test_char, &is_upper);

	if (lower_result == String_result::SUCCESS &&
			upper_result == String_result::SUCCESS) {
		cout << "Character '" << test_char << "' -> ";
		cout << "Lowercase: " << (is_lower ? "Yes" : "No") << ", ";
		cout << "Uppercase: " << (is_upper ? "Yes" : "No") << endl;
	}
}

int main() {
	// ✅ 4. Consistent Naming - snake_case throughout
	// ✅ 5. Clear Documentation - All functions documented

	cout << "Production-Grade String Operations Demo" << endl;
	cout << "=======================================" << endl;

	// Original test case (improved)
	char test_character = 'B';
	bool is_lower_result;

	String_result result =
		is_character_lowercasecase(test_character, &is_lower_result);

	if (result == String_result::SUCCESS) {
		if (is_lower_result) {
			cout << "✅ Character '" << test_character << "' is lowercase" << endl;
		} else {
			cout << "✅ Character '" << test_character << "' is NOT lowercase" << endl;
		}
	} else {
		cout << "❌ Error checking character: " << get_error_message(result) << endl;
		return static_cast<int>(result);
	}

	// Run comprehensive tests
	run_comprehensive_tests();

	return 0;
}


