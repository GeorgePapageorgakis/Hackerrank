/*
A new identification number is given and it has the following format.
    The string must begin with between 0-3 (inclusive) lowercase letters.
    Immediately following the letters, there must be a sequence of digits (0-9). The length of this segment must be between 2 and 8, both inclusive.
    Immediately following the numbers, there must be atleast 3 uppercase letters.

Find out if a given identification number is valid or not.
*/
#include <regex>
#include <string>
#include <iostream>
#include <sstream>

/**
    @param input username
    @return true if username is valid, false otherwise
*/
bool checkValidName(const std::string& text){
    //set regex matching and pattern        
    std::regex reg ("^[a-z]{0,3}\\d{2,8}[A-Z]{3,}$");
    //check each text line for email pattern

    if (std::regex_match (text,reg))
        return true;
    return false;
}


int main() {
    std::string s;
    int N;
    
    //get N strings
    std::getline(std::cin, s);
    std::stringstream numberline(s);
    numberline >> N;
    for(int i=0; i<N; ++i){
        std::getline(std::cin, s);
        if (checkValidName(s)){
            std::cout << "VALID" << std::endl;
        }
        else{
            std::cout << "INVALID" << std::endl;
        }
    }
    return 0;
}