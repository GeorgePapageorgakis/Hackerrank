/*
Your task is to help him find the minimum number of characters of the first string he needs to change to enable him to make it an anagram of the second string.

Note: A word x is an anagram of another word y if we can produce y by rearranging the letters of x.
Sample Input:
6
aaabbb
ab
abc
mnop
xyyx
xaxbbbxx

Sample Output:
3
1
-1
2
0
1
*/
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <numeric>      // std::accumulate
using namespace std;

/**
    @param input string
    @return minimum number of characters of the first string that needs to change to make an anagram of the second string
*/
int minNumCharAnagram(std::string& s){
    //if they have different length
    if(s.size() & 1){
        return -1;
    }
    //increase corresponding element for each letter of first sting
    //reduce corresponding element for each letter of second sting
    std::vector<int> letters(26, 0);  
    for (std::string::iterator it=s.begin(); it!=s.begin()+(s.size()/2); ++it) {
        ++letters.at(*it - 'a');
    }
    for (std::string::iterator it=s.begin()+(s.size()/2); it!=s.end(); ++it) {
        if(letters.at(*it - 'a') >0)
           --letters.at(*it - 'a');
    }
    //accumulate array
    return std::accumulate(letters.begin(),letters.end(),0);
}


int main() {
    std::string s;
    int n;
    std::cin >> n;
    std::vector<string> vs( std::istream_iterator<string>( std::cin ), std::istream_iterator<string>() );
    
    for(string i : vs)
        std::cout << minNumCharAnagram(i) << endl;

    return 0;
}
