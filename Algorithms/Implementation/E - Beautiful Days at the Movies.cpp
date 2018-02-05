/*
Lily likes to play games with integers and their reversals. For some integer x, we define reversed(x) to be the reversal of all digits in x. For example, reversed(123) = 321, reversed(21) = 12, and reversed(120) = 21.

Logan wants to go to the movies with Lily on some day x satisfying i <= x <= j, but he knows she only goes to the movies on days she considers to be beautiful. Lily considers a day to be beautiful if the absolute value of the difference between x and reversed(x) is evenly divisible by k.

Given i, j, and k, count and print the number of beautiful days when Logan and Lily can go to the movies.

Constraints:
	1 <= i <= j <= 2*10^6
	1 <= k <= 2 <= 10^9

Sample Input
20 23 6

Sample Output
2

*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int reverseNumberBits (int i, int j, int k){
	int result = 0;
	int aux = 0;
	string s = "";
	for (; i < j + 1; ++i){
		s = to_string(i);
        reverse(s.begin(),s.end());
		aux = stoi(s);
		if ( (abs(i - aux) % k ) == 0 ){
			++result;
        }
	}	
    return result;
}

int main() {	
	vector<int> numbers ;
	int i, j, k;
	cin >> i >> j >> k;
	
	cout << reverseNumberBits(i, j, k);

    return 0;
}