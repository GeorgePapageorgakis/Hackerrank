/*
A Phone number is of the following format

	[Country code]-[Local Area Code]-[Number]  

There might either be a '-' ( ascii value 45), or a ' ' ( space, ascii value 32) between the segments. Where the country and local area codes can have 1-3 numerals each and the number section can have 4-10 numerals each.

Your output will contain N lines.
	CountryCode=[Country Code],LocalAreaCode=[Local Area Code],Number=[Number]
*/
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

/**
    @param input list of phone numbers
    @return vector of splitted fields of phone numbers
*/
vector<string> splitPhoneNumbers(vector<string> text){
    vector<string> vs;
    //set regex matching and pattern
    std::smatch m;
    regex reg("^(\\d{1,3})[- ](\\d{1,3})[- ](\\d{4,10})$");
    //capture the 3 groups of numbers
    for(int i=0; i<text.size(); ++i){
        while (std::regex_search (text[i], m, reg)) {
            string aux = ("CountryCode=" + static_cast<string>(m[1]) + "," + "LocalAreaCode=" + static_cast<string>(m[2]) + "," + "Number=" + static_cast<string>(m[3]));
            vs.push_back(aux);
            text[i] = m.suffix().str();
        }
    }
    return vs;
}

int main() {
    vector<string> phoneNumbers;
    string s;
    int n;

    //get N phone numbers
    getline(std::cin, s);
    stringstream numberline(s);
    numberline >> n;
    for(int i=0; i<n; ++i){
        getline(cin, s);
        phoneNumbers.push_back(s);
    }

    //split all phone numbers to fields
	const vector<string>& ss = splitPhoneNumbers(phoneNumbers);

    //print
    std::vector<string>::const_iterator i = ss.begin();
    while ( i != ss.end()) {
        std::cout << *i << endl; 
        ++i;
    }
    return 0;
}