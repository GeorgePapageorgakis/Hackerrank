/*
complete the function vector parseInts(string str). str will be a string consisting of comma-separated integers, and you have to return a vector of int representing the integers.

Input Format:   
23,4,56
The first and only line consists of n integers separated by commas.

Output Format:
23
4
56
*/
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> v;
    std::stringstream ss(str);
    int i;

    while (ss >> i){
        v.push_back(i);
        //peek returns the next character in the input sequence, without extracting it: 
        //The character is left as the next character to be extracted from the stream.
        if (ss.peek() == ',')   
            ss.ignore();
    }
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
