/*
The equivalent of SSN in India is a PAN number, which is unique to each of its citizens. In any of the country's official documents, the PAN number is listed as follows

	<char><char><char><char><char><digit><digit><digit><digit><char>

Check out if the PAN number is valid or not. A valid PAN number will have all its letters in uppercase and digits in the same order as listed above.
*/
#include <regex>
#include <string>
#include <iostream>
#include <sstream>

/**
    @param input equivalent of SSN in India is a PAN number
    @return true if PAN number is valid, false otherwise
*/
bool checkValidPANFormat(const std::string& text){
    //set regex matching and pattern        
    std::regex reg ("^[A-Z]{5}\\d{4}[A-Z]$");
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
        if (checkValidPANFormat(s)){
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}