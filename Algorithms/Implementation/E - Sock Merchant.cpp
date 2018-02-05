/*
John's clothing store has a pile of n loose socks where each sock i is labeled with an integer, ci, denoting its color. He wants to sell as many socks as possible, but his customers will only buy them in matching pairs. Two socks, i and j, are a single matching pair if ci = cj.

Given n and the color of each sock, how many pairs of socks can John sell?

Sample Input
9
10 20 20 10 10 30 50 10 20

Sample Output
3

*/

#include <bits/stdc++.h>

using namespace std;

int sockMerchant(int n, vector<int> & ar) {
	int pairs = 0;
    //use hashing container for fast val access
	unordered_set<int> colorSock;
	colorSock.reserve(ar.size());
	
	for (int i = 0; i < ar.size(); ++i) {
		if ( !( colorSock.find(ar[i]) != colorSock.end() ) ) {
			colorSock.insert(ar[i]);
		}
		else {
			++pairs;
			colorSock.erase(ar[i]);
		}
	}
    return pairs;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}
