/*
Emma is playing a new mobile game involving n clouds numbered from 0 to n-1. A player initially starts out on cloud c0, and they must jump to cloud cn-1. In each step, she can jump from any cloud i to cloud i+1 or cloud i+2.

There are two types of clouds, ordinary clouds and thunderclouds. The game ends if Emma jumps onto a thundercloud, but if she reaches the last cloud (i.e., ), she wins the game!

Sample Input 0
7
0 0 1 0 0 1 0

Sample Output 0
4

Sample Input 1
6
0 0 0 0 1 0

Sample Output 1
3
*/
#include <iostream>
#include <vector>

using namespace std;

int numOfCloudJumps(vector<int> &c) {
	int jumps = 0;
	int i = 0;
	while(i < c.size() - 1){
		if ( (i + 2 < c.size()) && (c[i + 2] == 0) )
			i += 2;
		else 
			++i;
		++jumps;
	}
	return jumps;
}
int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
	cout << numOfCloudJumps(c);
    return 0;
}