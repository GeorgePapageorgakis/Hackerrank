/*
You are given a sequence of n integers, p(1), p(2), ..., p(n). Each element in the sequence is distinct and satisfies 1 <= p(x) <= n. For each x where 1 <= x <= n, find any integer y such that p(p(y)) = x and print the value of y on a new line.

Input Format:

The first line contains an integer, n, denoting the number of elements in the sequence.
The second line contains n space-separated integers denoting the respective values of p(1), p(2), ... p(n).

Constraints:
	1 <= n <= 50;
	1 <= p(x) <= 50 where 1 <= x <= n
	Each element in the sequence is distinct.

Sample Input 0
3
2 3 1

Sample Output 0
2
3
1

Given the values of p(1) = 2, p(2) = 3, and p(3) = 1, we calculate and print the following values for each x from 1 to n:
    x = 1 = p(3) = p(p(2)) = p(p(y)), so we print the value of y = 2 on a new line.
    x = 2 = p(1) = p(p(3)) = p(p(y)), so we print the value of y = 3 on a new line.
    x = 3 = p(2) = p(p(1)) = p(p(y)), so we print the value of y = 1 on a new line.
*/
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    
	vector<int> p(n,0), p_reverse(n,0);
	
	//get input
	for (int i = 0; i < n; i++) {
        cin >> p[i];
        //find values of reverse function of P(x)
        p_reverse[ p[i] - 1] = i + 1;
    } 
	
	for (int i = 0; i < n; i++) 
		cout << p_reverse[p_reverse[i] - 1] << endl;
   
    return 0;
}