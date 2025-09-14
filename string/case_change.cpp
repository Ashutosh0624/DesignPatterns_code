/*
 * @breief : Funtion to change the case of string without using cctype functions
 * @param: char array or string (not constant)
 * @return: returns the toggled characters as per calle.
 * @author: Ashutosh Tiwari
 * @date: September 14
 * 
 */ 

#include<iostream>
#include<cstring>
#include<cstddef>
#include<iomanip>
using namespace std;


size_t stringLen(const char* str){
    /* @breief: This function calculates the size of the string.
     * @param: char array 
     * @return : size of the string 
     */ 
    size_t len = 0;
    while(str && str[len] != '\0'){
        ++len;
    }
    return len;

}

void stringtolower(char *str){
    /*
     * @brief: function to change upper case to lower.
     * @param: character array.
     * @return: No return. 
     */ 
    if(!str) return;
    for(size_t i = 0; str[i] != '\0'; ++i){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
     }
 }


void stringtoupper(char *str){
    /*
     * @brief: function to change lower case to upper.  
     * @param: character array 
     * @return: no return (void)
     */ 
    if(!str) return ;
    for(size_t i = 0; str[i] != '\0'; ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
         }
     }
}


void stringToggle(char *str){
    /*
     * @brief : function to toggle the characters of a string.
     * @param : character array 
     * @return : No return (void )
     */

    if(!str) return;
    for(size_t i = 0; str[i] != '\0'; ++i){
         if(str[i] >= 'A' && str[i] <= 'Z'){
              str[i] += 32;
          }
         else if(str[i] >= 'a' && str[i] <= 'z'){
              str[i] -= 32; 
           } 
    }
 }

int main(){
    char str1[] = {"HELLO"};
    char str2[] = {"hello"};
    char str3[] = {"HeLLo"};
    
    stringtolower(str1);
    cout<<"after case change: "<<std::setw(10)<<str1<<endl;
    stringtoupper(str2); 
    cout<<"after case change: "<<std::setw(10)<<str2<<endl;
    stringToggle(str3);
    cout<<"after case change: "<<std::setw(10)<<str3<<endl;

    return 0;
 }
