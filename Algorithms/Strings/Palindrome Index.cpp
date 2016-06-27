/*
Given a string, S, of lowercase letters, determine the index of the character whose removal will make S a palindrome. If S is already a palindrome or no such character exists, then print -1. There will always be a valid solution, and any correct answer is acceptable. For example, if S = "bcbc", we can either remove 'b' at index or 'c' at index 3.

Sample Input
3
aaab
baa
aaa

Sample Output
3
0
-1
*/
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str){
	int i = 0, j = str.length() - 1;
	while (i < j)
	{
		if (str[i] != str[j]) 
            return false;
		i++, j--;
	}
	return true;
}

/**
    @param input string
    @return index to be removed from string to become a palindrome, -1 otherwise
*/
int findPalindromeIndex(std::string& s){
    int i = 0, j = s.size()-1, index = -1;
    if (s.size()>1){
        for(; i<s.size()/2; ++i, --j){
            if(s.at(i) != s.at(j)){
                //if left should be removed and it forms a palindrome
                if ((s.at(i+1) == s.at(j)) && (isPalindrome(s.substr(i+1,j-i)))){
                    index = i;
                    break;
                }
                //if right should be removed and it forms a palindrome
                else if ((s.at(i) == s.at(j-1)) && (isPalindrome(s.substr(i,j-i)))){
                    index = j;
                    break;
                }
            }
        }
    }
    return index;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<string> vs( std::istream_iterator<string>( std::cin ), std::istream_iterator<string>() );
    
    for(string i : vs)
        std::cout << findPalindromeIndex(i) << endl;
    return 0;
}
