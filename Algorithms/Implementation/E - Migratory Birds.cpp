/*
A flock of m birds is flying across the continent. Each bird has a type, and the different types are designated by the ID numbers 1, 2, 3, 4, and 5.

Given an array of integers where each integer describes the type of a bird in the flock, find and print the type number of the most common bird. If two or more types of birds are equally common, choose the type with the smallest ID number.

Input Format

The first line contains an integer denoting (the number of birds).
The second line contains space-separated integers describing the respective type numbers of each bird in the flock.

Constraints:
	5 <= n <= 2 x 10^5
    It is guaranteed that each type is 1, 2, 3, 4, or 5.
*/
#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int & n, vector<int> &ar) {
    vector<int> types(5,0);
	int max = 0;
	for (int i = 0; i < ar.size(); ++i) {
		++types[ar[i]-1];
		if ( types[ar[i]-1] > max){
			max = types[ar[i]-1];
		}
	}
	for (int i = 0; i < types.size(); ++i){
		if ( types[i] == max ){
			max = i+1;
		}
	}
	return max;
}
int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}