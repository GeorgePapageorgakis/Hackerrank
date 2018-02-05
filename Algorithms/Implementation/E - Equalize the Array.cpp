/*
Karl has an array of n integers defined as A = a0, a1, ... an-1. In one operation, he can delete any element from the array.

Karl wants all the elements of the array to be equal to one another. To do this, he must delete zero or more elements from the array. Find and print the minimum number of deletion operations Karl must perform so that all the array's elements are equal.

Constraints:
	1 <= n <= 100
	1 <= a1 <= 100
	
Sample Input
5
3 3 2 1 3

Sample Output
2   
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minNumOfDeletions(vector<int> &a) {
	vector<int> histogram(100, 0); //can also use hashmap or simple map
	
	for(int i =0; i < a.size(); ++i) {
		++histogram[a[i]];
	}
	return (a.size() - (*max_element(histogram.begin(), histogram.end())) );
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
	
	cout << minNumOfDeletions(a);
	
    return 0;
}