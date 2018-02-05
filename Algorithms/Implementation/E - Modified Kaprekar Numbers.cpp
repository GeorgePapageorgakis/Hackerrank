/*
A modified Kaprekar number is a positive whole number n with d digits, such that when we split its square into two pieces - a right hand piece r with d digits and a left hand piece l that contains the remaining d or d-1 digits, the sum of the pieces is equal to the original number (i.e. l + r = n).

Note: r may have leading zeros.

Here's an explanation from Wikipedia about the ORIGINAL Kaprekar Number (spot the difference!): In mathematics, a Kaprekar number for a given base is a non-negative integer, the representation of whose square in that base can be split into two parts that add up to the original number again. For instance, 45 is a Kaprekar number, because 45² = 2025 and 20+25 = 45.

You are given the two positive integers p and q, where p is lower than q. Write a program to determine how many Kaprekar numbers are there in the range between p and q(both inclusive) and display them all.

Constraints:
	0 < p < q < 100000
	
Output each Kaprekar number in the given range, space-separated on a single line. If no Kaprekar numbers exist in the given range, print INVALID RANGE.

Sample Input
1
100
Sample Output
1 9 45 55 99 

Sample Input:
400
700
Sample Output:
INVALID RANGE

1
99999
1 9 45 55 99 297 703 999 2223 2728 4950 5050 7272 7777 9999 17344 22222 77778 82656 95121 99999
*/

#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isKaprekarNumber(long i){
	/*
	//could also use this method for digit extraction
	int n = 12345;
	vector<int> digits;
	int i = 0;
	while ( n != 0) {
		digits.insert(digits.begin(), n%10);
		n /= 10;
	}
	*/
    if (i == 1)
        return true;
    if (i < 4)
        return false;
	string s;
    s = to_string((long long)(i*i));
	string s1, s2;
	s1.resize(s.length()/2);
	s2.resize(s.length()/2);
	
	copy (s.begin(), s.begin() + s.length()/2, s1.begin());
	copy (s.begin() + s.length()/2, s.end(), s2.begin());
	
	if (stoll(s1) + stoll(s2) == i)
		return true;
	return false;
}

int main() {
    bool rangeHasKaprekar = false;
    long p, q;
	cin >> p;
	cin >> q;
	
	for (long i = p; i < q + 1; ++i) {
		if (isKaprekarNumber(i)) {
            rangeHasKaprekar = true;
			cout << i << " ";
		}
	}
	if (!rangeHasKaprekar)
        cout << "INVALID RANGE" << endl;
    
    return 0;
}