/*
Lilah has a string, s, of lowercase English letters that she repeated infinitely many times.

Given an integer, ν, find and print the number of letter a's in the first n letters of Lilah's infinite string.

Constraints:
	1 <= |s| <= 100
	1 <= n <= 10^12
	for 25% of the test cases, n <= 10^6

Sample Input 0
aba
10

Sample Output 0
7

Sample Input 1
a
1000000000000

Sample Output 1
1000000000000


*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
unsigned long countRepeatedString(const string &s, const long &n) {
	unsigned long numOfa = 0;
	unsigned long numOfStrRepetitions = n / s.length();
	unsigned long numOfStrRemainder = n % s.length();
	
	numOfa = numOfStrRepetitions * (count(s.begin(), s.end(), 'a')) + count(s.begin(), s.begin() + numOfStrRemainder, 'a');
	return numOfa;
}

int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
	
	cout << countRepeatedString(s, n);
    return 0;
}