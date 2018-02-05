/*
Anna and Brian order n items at a restaurant, but Anna declines to eat any of the k item (where 0 <= k < n) due to an allergy. When the check comes, they decide to split the cost of all the items they shared; however, Brian may have forgotten that they didn't split the k item and accidentally charged Anna for it.

You are given n, k, the cost of each of the n items, and the total amount of money that Brian charged Anna for her portion of the bill. If the bill is fairly split, print Bon Appetit; otherwise, print the amount of money that Brian must refund to Anna.

Constraints:
	2 <= n <= 10^5
	0 <= k < n
	0 <= c[i] <= 10^4
	0 <= b <= Σ c[i]

Sample Input 0
4 1
3 10 2 9
12

Sample Output 0
5

Sample Input 1
4 1
3 10 2 9
7

Sample Output 1
Bon Appetit
**/
#include <bits/stdc++.h>

using namespace std;

string bonAppetit(int n, int k, int bCharged, vector<int> & ar) {
	string result = "";
	int bActual = 0;
    
	for (int i = 0; i < ar.size(); ++i) {
		bActual += ar[i];
	}
    bActual -= ar[k];
    bActual /= 2;
    
	if ( bCharged != bActual ) {
		result = to_string(bCharged - bActual);
	}
	else {
		result = "Bon Appetit";
	}
	return result;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int b;
    cin >> b;
    string result = bonAppetit(n, k, b, ar);
    cout << result << endl;
    return 0;
}