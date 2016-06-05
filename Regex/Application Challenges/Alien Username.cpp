/*
computer usernames follow a different format:

    It has to begin with either an underscore '_' (ascii value 95) or a dot '.' (ascii value 46)
    It has to be immediately followed by one or more occurrences of digits numbered 0-9
    It can then have letters, both uppercase or lowercase, 0 or more in number
    It can then end with an optional '_' (ascii value 95)

Your task is to validate whether a username is valid or not
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;


int main() {
    string s;
    int n;
    //set regex matching and pattern
    std::smatch m;
    std::regex reg ("^[_\\.]\\d+[a-zA-Z]*_{0,1}$");
    
    cin >> n;
    cin.clear();
    cin.ignore();
    for(int i=0; i<n; ++i){
        getline(cin, s);
        if (std::regex_match (s,m,reg)) {
            cout << "VALID" << endl;
        }
        else
            cout << "INVALID" << endl;
    }
    return 0;
}
