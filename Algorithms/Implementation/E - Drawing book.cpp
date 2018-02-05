/*
to open their n-page book to page number p. Brie can either start turning pages from the front of the book (i.e., page number 1) or from the back of the book (i.e., page number n), and she always turns pages one-by-one (as opposed to skipping through multiple pages at once). When she opens the book, page 1 is always on the right side.

Each page in the book has two sides, front and back, except for the last page which may only have a front side depending on the total number of pages of the book (see the Explanation sections below for additional diagrams).

Given n and p, find and print the minimum number of pages Brie must turn in order to arrive at page p.

Constraints:
	1 <= n <= 10^5
	1 <= p <= n
	
Sample Input 0
6
2

Sample Output 0
1

Sample Input 1
5
4

Sample Output 1
0

*/
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int p){
	return min( p/2, ((n/2) - (p/2)) );	
}

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    int result = solve(n, p);
    cout << result << endl;
    return 0;
}
