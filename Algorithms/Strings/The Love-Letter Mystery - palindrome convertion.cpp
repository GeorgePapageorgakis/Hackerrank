/*
changes all the words in the letter into palindromes.

To do this, he follows two rules:
    1. He can reduce the value of a letter, e.g. he can change d to c, but he cannot change c to d.
    2. In order to form a palindrome, if he has to repeatedly reduce the value of a letter, he can do it until the letter becomes a. Once a letter has been changed to a, it can no longer be changed.

Each reduction in the value of any letter is counted as a single operation. Find the minimum number of operations required to convert a given string into a palindrome.
Sample Input
4
abc
abcba
abcd
cba

Sample Output
2
0
4
2
*/

#include <string>
#include <exception>
#include <vector>
#include <iostream>
using namespace std;

//minimum number of operations required to convert a given string into a palindrome.
int minNumOpToPalindrome(string& s){
    int op, count = 0;
    for(int i=0; i<s.size()/2; ++i){
        op = abs(s.at(i) - s.at(s.size()-1-i));
        count += op;
    }
    return count;
}


int main() {
    std::vector<string> vs;
    string s;
    int n;
   
    try{
        cin >> n;
        cin.ignore();
        cin.clear();
        while (getline(cin, s)){
            vs.push_back(s);
        }
    }
    catch(istream::failure e){
        cerr << "Bad Input. Exception: " << e.what() << endl;
    }
    
    for(auto i : vs){
        cout << minNumOpToPalindrome(i) << endl;
    }
    
    return 0;
}
