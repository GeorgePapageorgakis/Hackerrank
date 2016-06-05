/*
A word is defined as a set of characters; alphabets ( lower case and upper case ) and numbers (0-9) both included and an underscore '_' (ascii value 95). Given a series of sentences each of which contains valid ascii characters, find the total number of occurrences of a given word.

So, a word as a whole will be surrounded by 1 or more occurrences of characters which are neither alphabets, numbers or an underscore.

<non-letter, non-number or non-underscore ><letters, numbers or underscores><non-letter, non-number or non-underscore>

Input Format
The first line is an integer N. N lines follow. Each line is a sentence as per the definition given in the introductory paragraph.
The Nth sentence is immediately followed by an integer T. T lines follow, with the tests. Each line has a word. You need to find the total number of occurrences of this word in the given sentences.

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
    string s, aux;
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
    
    //count word instances
    for(int i=0; i<t; ++i){
        count = 0;
        aux = T_str[i];
        for(int j=0; j<n; ++j){            
            s = N_str[j];
            //set regex matching and pattern
            std::smatch m;
            std::regex reg ( "(\\W|^)" + aux + "(\\W|$)" );  

            while (std::regex_search (s,m,reg)) {
                ++count;
                s = m.suffix().str();
            }            
        }
        cout << count << endl;    
    }
    return 0;
}
