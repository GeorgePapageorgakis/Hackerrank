/*
Lily has a chocolate bar consisting of a row of n squares where each square has an integer written on it. She wants to share it with Ron for his birthday, which falls on month m and day d. Lily wants to give Ron a piece of chocolate only if it contains m consecutive squares whose integers sum to d.

Given m, d, and the sequence of integers written on each square of Lily's chocolate bar, how many different ways can Lily break off a piece of chocolate to give to Ron?

For example, if m=2, and d=3 the chocolate bar contains n rows of squares with the integers [1, 2, 1, 3, 2] written on them from left to right, the following diagram shows two ways to break off a piece:

				  1 + 2 = 3
				| 1 | 2 | 1 | 3 | 2 |
					  2 + 1 = 3

Sample Input 0
5
1 2 1 3 2 
3 2

Sample Output 0
2

Sample Input 1
6
1 1 1 1 1 1
3 2

Sample Output 1
0
*/
#include <bits/stdc++.h>

using namespace std;

int solve(int & n, vector <int> & s, int & d, int & m){
    int count = 0, sum = 0;
	//case where m is greater than choco size
	if ( (s.size() < m) || ((s.size() == 1) && (s.size() < m)) )
		return 0;
    else if ( (s.size() == m == 1) ) {
        return 1;
    }
    //initialize sum
    for (int i = 0; i < m-1; ++i){
        sum += s[i];
    }
    //shift frame indexes and calculate the sum
    for ( int low = 0, high = m-1; high < s.size(); ++low, ++high){
        sum += s[high];
        if ( sum == d){
            ++count;
        }
        sum -= s[low];
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}
