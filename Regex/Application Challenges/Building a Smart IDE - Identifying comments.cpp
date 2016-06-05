/*
 Identifies the comments, in the source code of computer programs. 
 Assume, that the programs are written either in C, C++ or Java.
 Program will be tested on source codes of not more than 200 lines.
 */
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

/*
Take text input string
return a vector of strings with code comments
*/
vector<string> find_code_comments(string& s){
    vector<string> vs;
    //set regex matching and pattern
    std::smatch m;
    regex reg("(//.*|/\\*(.|\\n)*?\\*/)");  //my version
    //better regex with loop-unroll technique
    //regex reg(R"(//.*|/\*[^*]*\*+(?:[^/*][^*]*\*+)*/)");    

    //check each text line for comments pattern
    while (std::regex_search (s, m, reg)) {
        //remove leading whitespaces in the multi-line comments
        vs.push_back(std::regex_replace(m[1].str(), std::regex(R"((^|\n)[^\S\r\n]+)"), "$1"));
        s = m.suffix().str();
    }
    return vs;
}


int main() {
    vector<string> N_str;
    string s, aux;

    while ( getline(cin, s)){
        aux += s;  aux += "\n";
    }

    //find all comments
	const vector<string>& ss = find_code_comments(aux);
   
    //print comments
    std::vector<string>::const_iterator i = ss.begin();
    while ( i != ss.end()) {
        std::cout << *i << endl; 
        ++i;
    }
    return 0;
}