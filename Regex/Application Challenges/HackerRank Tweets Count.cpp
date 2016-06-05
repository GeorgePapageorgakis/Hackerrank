/*
Given a set of most popular tweets, your task is to find out how many of those tweets has the string hackerrank in it.

NOTE: simple solution in bash: grep -c -i "hackerrank"
*/
#include <string>
#include <vector>
#include <iostream>
#include <regex>

/**
    @param input vector text
    @return total number of tweet instances
*/
unsigned int findTweets(const std::vector<std::string>& text){
    using namespace std::regex_constants;
    unsigned int c=0;
    //check each text line case insensitive pattern
    for(int i=0; i<text.size(); ++i){
        std::string s = text[i];
        std::smatch m;
        std::regex reg (".*hackerrank.*", ECMAScript | icase);  //case insensitive
        while (std::regex_search (s,m,reg)) {
            ++c;
            s = m.suffix().str();
        } 
    }
    return c;
}

int main() {
    std::vector<std::string> N_str;
    std::string s;
    int n;

    //get N strings
    std::getline(std::cin, s);
    std::stringstream numberline(s);
    numberline >> n;
    for(int i=0; i<n; ++i){
        //get string
        std::getline(std::cin, s);
        N_str.push_back(s);
    }

    //find all tweets
    std::cout << findTweets(N_str) << std::endl;

    return 0;
}