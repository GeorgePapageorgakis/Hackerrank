/*
Given an array of integers, find and print the maximum number of integers you can select from the array such that the absolute difference between any two of the chosen integers is <= 1.

Constraints:
	2 <= n <= 100
	0 <= a_i <= 100
	answer will be >= 2

Sample Input 0
6
4 6 5 3 3 1

Sample Output 0
3
We choose the following multiset of integers from the array: {4,3,3}. Each pair in the multiset has an absolute difference <= 1 (i.e., |4-3| = 1 and |3-3| = 0), so we print the number of chosen integers, 3, as our answer.

Sample Input 1
6
1 2 2 3 1 2

Sample Output 1
5
We choose the following multiset of integers from the array: {1,2,2,1,2}. Each pair in the multiset has an absolute difference <= 1 (i.e., |2-1| = 1, |1-1| = 0, and |2-2| = 0), so we print the number of chosen integers, 5, as our answer.
**/
#include <iostream>
#include <vector>
using namespace std;

int pickNumbers (vector<int> &a){
	int max = 0;
	//find frequency of all the numbers
    vector<int> freqNum (100, 0);
    for(int i = 0; i < a.size(); ++i){
        ++freqNum[ a[i] ];
    }
	//if they are consequtive
    for(int i = 0; i < freqNum.size() - 1; ++i){
        if( (freqNum[i] + freqNum[i+1] > max) ) 
			max = freqNum[i] + freqNum[i+1];
    }
    return max;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
	cout << pickNumbers(a);
    return 0;
}


