/*
To lock the door he needs a key that is an anagram of a certain palindrome string.

The king has a string composed of lowercase English letters. Help him figure out whether any anagram of the string can be a palindrome or not. 
Sample Input :
aaabbbb

Sample Output :
YES
*/
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//figure out whether any anagram of the string can be a palindrome or not.
//If len(str) is even, count of each elemnt should be even.
//If len(str) is odd, count of ONLY one element should be odd, counts of all other elements should be even. 
int isPotentialPalindrome(string& s){
    bool oddStrLen = (s.size()&2 != 0);
    int odds = 0;
    std::vector<std::pair<char, int>> v(26);
    std::generate(v.begin(), v.end(), [&] { static char c = 'a'; return std::make_pair(c++, 0);} );
    if(s.size()>1){
        for (std::string::iterator it = s.begin(); it!=s.end(); ++it){
            ++v.at(*it - 'a').second; 
        }

        //check if every char instance is even number, allow only 1 to be odd if String Length is odd
        for (std::vector<std::pair<char, int>>::iterator it = v.begin(); it!=v.end(); ++it){
            if ((*it).second & 2 !=0){
                //if length is even it cannot be palindrome
                if(!oddStrLen)
                    return 0;
                ++odds;
            }
            if ((odds > 1) && oddStrLen)
                return 0;
        }
    }
    return 1;
}

int main() {
    string s;
    cin>>s;
    
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string      
    int flag = isPotentialPalindrome(s);

    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}