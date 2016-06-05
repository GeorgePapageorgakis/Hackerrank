/*
Use Regular Expressions to simplify your task. And remember that the "@" sign can be used for a variety of purposes!

Input Format

The first line contains an integer N (N<=100), which is the number of lines present in the text fragment which follows.
From the second line, begins the text fragment (of N lines) in which you need to search for e-mail addresses.

Output Format

All the unique e-mail addresses detected by you, in one line, in lexicographical order, with a semi-colon as the delimiter.

Valid email-address rules are :

	1. It should be of format : <local-part>@<domain-part>
	2. Local-part can contain Alphanumeric-character or .(dot)
	3. Domain-part can contain Alphanumeric-character or .(dot)

*/
#include <regex>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

/**
    @param input vector text
    @return set with all email addresses
*/
set<string> find_emails(const vector<string>& text){
    set<string> ss;
    string s;
    //set regex matching and pattern
    std::smatch m;
    std::regex reg ("[\\w\\.]+@[a-z\\.]+\\.[a-z]{2,3}");
    //check each text line for email pattern
    for(int i=0; i<text.size(); ++i){
        s = text[i];
        while (std::regex_search (s,m,reg)) {
            ss.insert(m[0]);
            s = m.suffix().str();
        }
    }
    return ss;
}


int main() {
    vector<string> N_str;
    //set<string> ss;
    string s, aux;
    int n;
    
    //get N strings
    getline(std::cin, aux);
    stringstream numberline(aux);
    numberline >> n;
    for(int i=0; i<n; ++i){
        //get string
        getline(cin, s);
        N_str.push_back(s);
    }
	
    //find all email addresses
	const set<string>& ss = find_emails(N_str);
    
    //print
    std::set<string>::iterator i = ss.begin();
    while ( i != ss.end()) {
        std::cout << *i; 
        ++i;
        if (i != ss.end())
            cout << ";";
    }
    return 0;
}