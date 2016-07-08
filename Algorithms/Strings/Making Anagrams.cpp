/*
We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings, and , that may or may not be of the same length, determine the minimum number of character deletions required to make and anagrams. Any characters can be deleted from either of the strings.
Sample Input
cde
abc

Sample Output
4
*/
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
    @param input strings
    @return minimum number of character deletions required to make and anagrams. Any characters can be deleted from either of the strings. 
*/
int minNumCharAnagram(std::string& s1, std::string& s2){
    int sum = 0;
    //increase corresponding element for each letter of first sting
    //reduce corresponding element for each letter of second sting
    std::vector<int> letters(26, 0);  
    for (std::string::iterator it=s1.begin(); it!=s1.end(); ++it) {
        ++letters.at(*it - 'a');
    }
    for (std::string::iterator it=s2.begin(); it!=s2.end(); ++it) {
        --letters.at(*it - 'a');
    }

    //calculate sum of chars to delete
    std::for_each(letters.begin(), letters.end(), [&] (int n) { sum += abs(n);});
    return sum;
}


int main() {
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;

    std::cout << minNumCharAnagram(s1, s2) << endl;
    
    return 0;
}