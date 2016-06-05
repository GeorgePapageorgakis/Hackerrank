/*
A word made of a series of letters (lower or upper) or numerics or an underscore _ ( ascii value 95).

We define a substring as follows.
    It is a part of a word.
    The given substring must be preceded and succeeded by letters or numerics or an underscore.

A substring will be surrounded by 1 or more occurrences of non-letter, non-numeric and non-underscore ( not an underscore ) characters - or the beginning or end of a line on one side.

<non letter, non-numeral ,non-underscore ><letters, numerals and underscore><non letter, non numerals, non underscore>

Given a sentence, find the total number of occurrences of the substring.

Input Format:
	First line is an integer N, N lines follow. Each line is a sentence as per the above definition.
	Nth sentence is immediately followed by an integer T, T lines follow.
	Each line has a substring on which you need to perform the prescribed query which returns the total number of occurrences of the substring in all strings N. 
*/
#include <iostream>
#include <regex>
#include <sstream>
#include <set>
#include <vector>
using namespace std;


int main() {
    vector<string> N_str;
    vector<string> T_str;
    string s, aux, k;
    int n, t, count=0;
    
    //get N strings
    getline(std::cin, aux);
    stringstream numberline(aux);
    numberline >> n;
    for(int i=0; i<n; ++i){
        //get string
        getline(cin, s);
        N_str.push_back(s);
    }
      
    //get T strings
    numberline.clear();
    getline(std::cin, aux);
    numberline.str(aux);
    numberline >> t;
    for(int i=0; i<t; ++i){
        //get string
        getline(cin, s);
        T_str.push_back(s);
    }
    
    //count substring instances
    for(int i=0; i<t; ++i){
        count = 0;
        aux = T_str[i];
        for(int j=0; j<n; ++j){            
            k = "\\w";
            k += aux;
            k += "\\w";
            s = N_str[j];
            //set regex matching and pattern
            std::smatch m;
            std::regex reg ( k );  

            while (std::regex_search (s,m,reg)) {
                ++count;
                s = m.suffix().str();
            }            
        }
        cout << count << endl;    
    }
    return 0;
}