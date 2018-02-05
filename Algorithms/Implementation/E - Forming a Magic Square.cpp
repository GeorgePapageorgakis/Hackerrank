/*
We define a magic square to be an n x n matrix of distinct positive integers from 1 to n^2 where the sum of any row, column, or diagonal (of length n) is always equal to the same number (i.e., the magic constant).

Consider a 3 x 3 matrix, s, of integers in the inclusive range [1,9]. We can convert any digit, a, to any other digit, b, in the range [1,9] at cost |a-b|.

Given s, convert it into a magic square at minimal cost by changing zero or more of its digits. Then print this cost on a new line.

Note: The resulting magic square must contain distinct integers in the inclusive range [1,9].

Constraints:
	All integers in s are in range [1,9]
	
Sample Input 0
4 9 2
3 5 7
8 1 5

Sample Output 0
1

Observe that it's not yet magic, because not all rows, columns, and center diagonals sum to the same number.
If we change the bottom right value, s[2][2], from 5 to 6 at a cost of |6-5| = 1, s becomes a magic square at the minimum possible cost. Thus, we print the cost, 1, on a new line.
4 9 2
3 5 7
8 1 6

Sample Input 1
4 8 2
4 5 7
6 1 6

Sample Output 1
4
Considering 0 - based indexing if we make s[0][1]->9 at a cost of : |9-8| = 1, s[1][0]->3 at a cost of :|3-4| = 1 and s[2][0]->8 at a cost of :|8-6| = 2, then net cost will be (1 + 1 + 2 = 4).
4 9 2
3 5 7
8 1 6
*/

#include <bits/stdc++.h>

using namespace std;
int minCostTransformToMagicSquare(vector<vector<int>> s ) {
	int magicConstant = ( s[0].size() * ((s[0].size() * s[0].size()) + 1) )/2;
	
}
int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];
       }
    }
    //  Print the minimum cost of converting 's' into a magic square
	cout << minCostTransformToMagicSquare(s);
    return 0;
}