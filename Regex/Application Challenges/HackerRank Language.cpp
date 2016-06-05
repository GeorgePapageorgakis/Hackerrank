/*
Every submission at HackerRank has a field called language which indicates the programming language which a hacker used to code his solution.

C:CPP:JAVA:PYTHON:PERL:PHP:RUBY:CSHARP:HASKELL:CLOJURE:BASH:SCALA: ERLANG:CLISP:LUA:BRAINFUCK:JAVASCRIPT:GO:D:OCAML:R:PASCAL:SBCL:DART: GROOVY:OBJECTIVEC

Sometimes, error-prone API requests can have an invalid language field. Could you find out if a given submission has a valid language field or not?

Sample Input:
	3
	11011 LUA
	11022 BRAINFUCK
	11044 X

Sample Output:
	VALID
	VALID
	INVALID
*/
#include <regex>
#include <string>
#include <iostream>
#include <sstream>

/**
    @param input code and language id
    @return true if language field is valid, false otherwise
*/
bool checkValidProgrammingLanguageCode(const std::string& text){
    //set regex matching and pattern        
    std::regex reg ("^\\d+?\\s(?:C|CPP|JAVA|PYTHON|PERL|PHP|RUBY|CSHARP|HASKELL|CLOJURE|BASH|SCALA|ERLANG|CLISP|LUA|BRAINFUCK|JAVASCRIPT|GO|D|OCAML|R|PASCAL|SBCL|DART|GROOVY|OBJECTIVEC)$");
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
        if (checkValidProgrammingLanguageCode(s)){
            std::cout << "VALID" << std::endl;
        }
        else{
            std::cout << "INVALID" << std::endl;
        }
    }
    return 0;
}