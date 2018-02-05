/*
You have a string, s, of lowercase English alphabetic letters. You can perform two types of operations on s:

    1. Append a lowercase English alphabetic letter to the end of the string.
    2. Delete the last character in the string. Performing this operation on an empty string results in an empty string.

Given an integer, k, and two strings, s and t, determine whether or not you can convert s to t by performing exactly k of the above operations on s. If it's possible, print Yes; otherwise, print No.

Sample Input 0
hackerhappy
hackerrank
9

Sample Output 0
Yes

Explanation 0
We perform 5 delete operations to reduce string s to hacker. Next, we perform 4 append operations (i.e., r, a, n, and k), to get hackerrank. Because we were able to convert s to t by performing exactly k=9 operations, we print Yes.

Sample Input 1
aba
aba
7

Sample Output 1
Yes

Explanation 1
We perform 4 delete operations to reduce string s to the empty string (recall that, though the string will be empty after 3 deletions, we can still perform a delete operation on an empty string to get the empty string). Next, we perform 3 append operations (i.e., a, b, and a). Because we were able to convert s to t by performing exactly k=7 operations, we print Yes.

*/
#include <iostream>
#include <string>

using namespace std;

bool CheckStrPossibleConversion(string &s, string &t, int &k) {
	bool convertable	= false;
	int commonSubStrLen = 0;
	
	//if there is any, find the length of common substring.
	for (int i = 0; i < min(s.length(), t.length()); ++i) {
		if ( s.at(i) == t.at(i) )
			++commonSubStrLen;
		else
			break;
	}
	
	//if k is bigger than the difference in length of the two strings 
	//we need a bigger k, so s is not convertable to t
	if( (s.length() + t.length() - 2 * commonSubStrLen) <= k ) {
		//exactly k moves must be done only if k odd/even matches 
		//the odd/even of number of different digits will such cases pass.
		if ((s.length() + t.length() - 2 * commonSubStrLen ) % 2 == k % 2)
			convertable = true;
		//or if we can overcome odd/even problem if you are able to completely delete 
		//one string, as the deletion action on an empty string results in another empty string.
		if (( s.length() + t.length()) < k )		
			convertable = true;
	}
	return convertable;
}


int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
	
	cout << (CheckStrPossibleConversion(s, t, k) ? "Yes" : "No");
	
    return 0;
}