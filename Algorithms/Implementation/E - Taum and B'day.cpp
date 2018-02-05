/*
Taum is planning to celebrate the birthday of his friend, Diksha. There are two types of gifts that Diksha wants from Taum: one is black and the other is white. To make her happy, Taum has to buy B number of black gifts and W number of white gifts.

    The cost of each black gift is X units.
    The cost of every white gift is Y units.
    The cost of converting each black gift into white gift or vice versa is Z units.

Help Taum by deducing the minimum amount he needs to spend on Diksha's gifts.

Input Format

The first line will contain an integer T which will be the number of test cases.
There will be T pairs of lines. The first line of each test case will contain the values of integers B and W. Another line of each test case will contain the values of integers X, Y, and Z.

Constraints:
	1 <= T <= 10
	0 <= X, Y, Z, B, W <= 10^9

Sample Input
5
10 10
1 1 1
5 9
2 3 4
3 6
9 1 1
7 7
4 2 1
3 3
1 9 2

Sample Output
20
37
12
35
12
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long deduceMinAmountSpent (long &B, long &W, long &X, long &Y, long &Z) {
	long long total = 0;
	//if white gifts painted to black gifts cost less than original price of black gifts
	if (Z + Y < X)
		total = (B * (Y + Z)) + (W * Y);
	//else if black gifts painted to white gifts cost less than original price of white gifts
	else if (Z + X < Y)
		total = (B * X) + (W * (X + Z));
	else
		total = (B * X) + (W * Y);
	return total;
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long b;
        long w;
        cin >> b >> w;
        long x;
        long y;
        long z;
        cin >> x >> y >> z;
		cout << deduceMinAmountSpent(b, w, x, y, z) << endl;
    }
    return 0;
}