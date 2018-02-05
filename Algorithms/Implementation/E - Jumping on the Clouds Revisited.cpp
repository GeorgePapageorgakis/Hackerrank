/*
Aerith is playing a cloud game! In this game, there are n clouds numbered sequentially from 0 to n-1. Each cloud is either an ordinary cloud or a thundercloud.

Aerith starts out on cloud with energy level E=100. She can use 1 unit of energy to make a jump of size k to cloud (i + k) % n, and she jumps until she gets back to cloud . If Aerith lands on a thundercloud, her energy (E) decreases by 2 additional units. The game ends when Aerith lands back on cloud 0.

Given the values of n, k, and the configuration of the clouds, can you determine the final value of E after the game ends?


Input Format:
The first line contains two space-separated integers, n (the number of clouds) and k (the jump distance), respectively.
The second line contains n space-separated integers describing the respective values of clouds c0, c1, ... cn-1. Each cloud is described as follows:

    If ci = 0, then cloud i is an ordinary cloud.
    If ci = 1, then cloud i is a thundercloud.

Constraints:
	1 <= n <= 25
	1 <= k <= n
	n % k = 0
	ci ε {0, 1}

Sample Input
8 2
0 0 1 0 0 1 1 0

Sample Output
92

*/

#include <iostream>
#include <vector>

using namespace std;

int calcEnergyCloudJumps (vector<int> & c, int & k) {
	int energy = 100, i = 0;
	while(true) {
		i = (i + k) % c.size();
		--energy;
		if (c[i] == 1)
			energy -= 2;
        if (i == 0)
            break;
	}	
	return energy;
}
int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
	cout << calcEnergyCloudJumps(c, k) << endl;
    return 0;
}