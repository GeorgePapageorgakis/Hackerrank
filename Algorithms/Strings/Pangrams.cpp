/*
Roy wanted to increase his typing speed for programming contests. So, his friend advised him to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly, because it is a pangram. (Pangrams are sentences constructed by using every letter of the alphabet at least once.)

After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.

Given a sentence s, tell Roy if it is a pangram or not.
*/
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s, letters = "abcdefghijklmnopqrstuvwxyz";
    //get the sting
    getline(cin, s);
    //tranform all letters to lower case for comparison
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    //sort requirement for usage of "include"
    sort (s.begin(),s.end());
    if ( includes(s.begin(),s.end(), letters.begin(), letters.end()) )
        cout << "pangram";
    else
        cout << "not pangram";
    return 0;
}
