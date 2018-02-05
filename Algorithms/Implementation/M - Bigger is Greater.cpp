/*
Given a word w, rearrange the letters of w to construct another word s in such a way that is lexicographically greater than w. In case of multiple possible answers, find the lexicographically smallest one among them.

Input Format

The first line of input contains t, the number of test cases. Each of the next t lines contains w.

Constraints:
	1 <= t <= 10^5
	1 <= |w| <= 100

Sample Input 0
5
ab
bb
hefg
dhck
dkhc

Sample Output 0
ba
no answer
hegf
dhkc
hcdk

Explanation 0
    Test case 1:
    There exists only one string greater than ab which can be built by rearranging ab. That is ba.
    Test case 2:
    Not possible to rearrange bb and get a lexicographically greater string.
    Test case 3:
    hegf is the next string lexicographically greater than hefg.
    Test case 4:
    dhkc is the next string lexicographically greater than dhck.
    Test case 5:
    hcdk is the next string lexicographically greater than dkhc.

Condensed mathematical description:
    1. Find largest index i such that array[i − 1] < array[i].
    (If no such i exists, then this is already the last permutation.)

    2. Find largest index j such that j ≥ i and array[j] > array[i − 1].

    3. Swap array[j] and array[i − 1].

    4. Reverse the suffix starting at array[i].
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
//easy solution with STL algo:
string convertWordToGreaterLexi(string s){
    if (next_permutation(s.begin(), s.end()))
        return s;
	return "no answer";
}
*/

/* 
 * Computes the next lexicographical permutation of the specified
 * vector in place, returning whether a next permutation existed.
 * (Returns false when the argument is already the last possible
 * permutation.)
 */
bool convertWordToGreaterLexi(string &array) {
    // Find non-increasing suffix
    if (array.size() == 0)
        return false;
	//find longest non increasing suffix (starting from the end)
    string::iterator i = array.end() - 1;
    while (i > array.begin() && *(i - 1) >= *i)
        --i;
	
    //If the entire sequence is non-decreasing – then this is already the last permutation.
    if (i == array.begin())
        return false;

    // Find successor to pivot (the element immediately to the left of the suffix)
    string::iterator j = array.end() - 1;
    while (*j <= *(i - 1))
        --j;
	//If we swap the pivot with the smallest element in the suffix that is greater 
	//than the pivot, then the prefix is minimized.
    iter_swap(i - 1, j);

    // Reverse suffix
    std::reverse(i, array.end());
    return true;
}


int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
		string s;
		cin >> s;
		cout << (convertWordToGreaterLexi(s) ? s : "no answer") << endl;
    } 
    return 0;
}