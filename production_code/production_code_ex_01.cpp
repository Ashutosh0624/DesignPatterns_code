/**
 * @brief Production code example
 * @date 19th September 2025
 * @details
 * This code implements the priniciples of production code.
 * The important principles fo production code :
 *    -> Every function should have return status if possible.
 *    -> Clear documentation.
 *    -> Proper error handling 
 *    -> Ensuring safety check, safety boud code..
 */

#include<iostream>
#include<cstddef>
#include<iomanip>
#include<cstring>

#define MAX_LEN 10000

enum class string_utils{
	SUCCESS = 0,
	EMPTY_STRING = 1,
	DANGLING_STRING = -1,
	BUFFER_OVERFLOW = -2
};


/**
 * @brief Function to calculate the size of the string or length of the string.
 * @param const char* str or character array
 * @return 
 * if size of the str is calculate successfully, returns SUCCESS status, else the 
 * corresponding error code/status.
 */

[[nodiscard]] string_utils size_string(const char* str, const size_t max_len = MAX_LEN, size_t* length = nullptr){
	if(!str){
		return string_utils::DANGLING_STRING;
	}

	if(str[0] == '\0'){
		std::cout<<"string is valid but its empty"<<std::endl;
		return string_utils::EMPTY_STRING; 
	}

	size_t len = 0;
	for(size_t i = 0; str[i] !='\0'; ++i){
		++len;
	}

	if(len > max_len){
		return string_utils::BUFFER_OVERFLOW;
	}

	if(length){
		*length  = len;
	}
	return string_utils::SUCCESS;
}

int main(){
	const char* str {"Hello world"};
	size_t len = 0;
	string_utils res = size_string(str,MAX_LEN, &len);
	std::cout<<"length of the string: "<<len<<std::endl;
	std::cout<<"res "<<static_cast<int>(res)<<std::endl;
	return 0;
}




