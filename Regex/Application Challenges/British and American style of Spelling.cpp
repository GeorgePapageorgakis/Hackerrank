/*
words written in American English, which have a suffix ze often end in se in British English. Given the American-English spelling of a word which ends in ze your task is to find the total count of all its British and American variants in all the given sequences of words. i.e. you need to account for the cases where the word occurs as it is given to you (i.e. the version ending in -ze) and you also need to find the occurances of its British-English counterparts (i.e, the version ending in -se).

NOTE: Same for "or" and "our" words with slight modification in regex :
	reg("\\b" + s.substr(0, s.find_last_of('u')) + "u?" + s.substr(s.find_last_of('u')+1, s.size()) + "\\b");
*/
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

/**
    @param vector string with text lines
    @return	number of total words found that match US and EU style (se-ze) etc...
*/
int findUSUKWordInstances(const vector<string>& text, const string s){
    string aux;
    int count(0);
    aux = s;
    aux.pop_back();
    aux.pop_back();
    std::regex const reg("\\b" + aux + "[sz]" + s.back() + "\\b");
    //count instances per line
    for(unsigned i=0; i<text.size(); ++i){
        aux = text[i];
        //count matching EU-US words per line
        std::ptrdiff_t const match_count(std::distance(std::sregex_iterator(aux.begin(), aux.end(), reg), 
														std::sregex_iterator()));
        count += match_count;
    }
    return count;
}

int main() {
    vector<string> text;
    string s;
    int n, q;

    getline(std::cin, s);
    stringstream(s) >> n;
    for(int i=0; i<n; ++i){
        getline(cin, s);
        text.push_back(s);
    }
    
    getline(std::cin, s);
    stringstream(s) >> q;
    for(int i=0; i<q; ++i){
        getline(cin, s);
        cout << findUSUKWordInstances(text, s) << endl;
    } 
    return 0;
}
