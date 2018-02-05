/*
Monica wants to buy exactly one keyboard and one USB drive from her favorite electronics store. The store sells different brands of keyboards and m different brands of USB drives. Monica has exactly s dollars to spend, and she wants to spend as much of it as possible (i.e., the total cost of her purchase must be maximal).

Given the price lists for the store's keyboards and USB drives, find and print the amount money Monica will spend. If she doesn't have enough money to buy one keyboard and one USB drive, print -1 instead.

Note: She will never buy more than one keyboard and one USB drive even if she has the leftover money to do so.

Constraints:
	1 <= n,m <= 1000
	1 <= s <= 10^6
	price of each item is in range [1, 10^6]

Sample Input 0
10 2 3
3 1
5 2 8

Sample Output 0
9

Sample Input 1
5 1 1
4
5

Sample Output 1
-1

Sort 1 in descending and the other in ascending order to visit each element once, 
since the sum of the element following the current will be greater/less than the 
current sum depending on the direction we iterate.

Time Complexity: O(n+m (log (n+m)))
*/
#include <bits/stdc++.h>

using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int s){
    int maxSpent = -1, sum = 0;
	
	sort (keyboards.begin(), keyboards.end());
	sort (drives.rbegin(), drives.rend());	//descending sort
	
	for(int i = 0, j = 0; i < drives.size(); ++i){
		for(; j < keyboards.size(); ++j){
			if(drives[i] + keyboards[j] > s)
				break;
			if(drives[i] + keyboards[j] > maxSpent)
				maxSpent = drives[i] + keyboards[j];
		}
	}
	return maxSpent;
}

int main() {
    int s, n, m;
    cin >> s >> n >> m;
    vector<int> keyboards(n);
    for(int keyboards_i = 0; keyboards_i < n; keyboards_i++){
       cin >> keyboards[keyboards_i];
    }
    vector<int> drives(m);
    for(int drives_i = 0; drives_i < m; drives_i++){
       cin >> drives[drives_i];
    }
    //  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    int moneySpent = getMoneySpent(keyboards, drives, s);
    cout << moneySpent << endl;
    return 0;
}