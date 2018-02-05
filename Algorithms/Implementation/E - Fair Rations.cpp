/*
You are the benevolent ruler of Rankhacker Castle, and today you're distributing bread to a straight line of N subjects. Each ith subject (where 1 <= i <= N) already has Bi loaves of bread.

Times are hard and your castle's food stocks are dwindling, so you must distribute as few loaves as possible according to the following rules:

    Every time you give a loaf of bread to some person , you must also give a loaf of bread to the person immediately in front of or behind them in the line (i.e., persons i+1 or i-1). In other words, you can only give a loaf of bread each to two adjacent people at a time.
    After all the bread is distributed, each person must have an even number of loaves.

Given the number of loaves already held by each citizen, find and print the minimum number of loaves you must distribute to satisfy the two rules above. If this is not possible, print NO.

Sample Input 0
5
2 3 4 5 6

2 4 5 5 6 -> 2 4 6 6 6
Sample Output 0
4

Sample Input 1
2
1 2

2 3 -> odd number of odds

Sample Output 1
NO

Sample Input 1
4
4 2 6 12

Sample Output 1
0
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//We need the value of gap between indices of two odd numbers because 
//2*gap is minimum number of breads must be given to make that interval even. 
//If number of odds is odd this can't be done.
string countRations(vector<int> & B) {
	int count = 0, oddNumOfOdds = 0; 
	for(int i = 0; i < B.size(); ++i){
		if(B[i] % 2) {
			count++;
			oddNumOfOdds = count % 2? oddNumOfOdds - i : oddNumOfOdds + i;
		}
	}
	return (count % 2) && (count != 0) ? "NO" : to_string(oddNumOfOdds * 2);
}

int main(){
    int N;
    cin >> N;
    vector<int> B(N);
    for(int B_i = 0;B_i < N;B_i++){
       cin >> B[B_i];
    }	
	
	cout << countRations(B);	
    return 0;
}
