/*
 find out how popular we are getting every day and have scraped conversations from popular sites. Each conversation fits in 1 line and there are N such conversations. Each conversation has at most 1 word that says hackerrank (all in lowercase). We would like you to help us figure out whether a conversation:

   1. Starts with hackerrank
   2. Ends with hackerrank
   3. Start and ends with hackerrank

For every line,
    - Print 1 if the conversation starts with hackerrank
    - Print 2 if the conversation ends with hackerrank
    - Print 0 if the conversation starts and ends with hackerrank
    - Print -1 if none of the above.
*/
#include <regex>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;


int main() {
    string s;
    int N;
    string pattern = "hackerrank";
    regex rx(pattern);
    std::getline(std::cin, s);
    std::stringstream numberline(s);
    numberline >> N;
    
    for(int i=0; i<N; ++i){
        std::getline(std::cin, s);
        for(auto it = std::sregex_iterator(s.begin(), s.end(), rx); it != std::sregex_iterator(); ++it){
            if (it->position() == 0){
                if (s.size()-pattern.size() == 0)
                    std::cout << 0 << endl;
                else 
                    std::cout << 1 << endl;
            }
            else if(it->position() == s.size() - pattern.size()){
                std::cout << 2 << endl;
            }
            else
                std::cout << -1 << endl;
        }
    }
    return 0;
}
