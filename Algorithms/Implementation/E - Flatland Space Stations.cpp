/*
Flatland is a country with n cities, m of which have space stations. Each city, ci, is numbered with a distinct index from 0 to n-1, and each city ci is connected to city ci+1 by a bidirectional road that is 1km in length.

For example, if n = 5 and cities c0 and c4 have space stations, then Flatland looks like this:

	[0]---1---2---3---[4]

For each city, determine its distance to the nearest space station and print the maximum of these distances. 

Constraints
	1 <= n <= 10^5
	1 <= m <= n
    It is guaranteed that there will be at least 1 city with a space station, and no city has more than one.

Sample Input 0
5 2
0 4

Sample Output 0
2

Sample Input 1
6 6
0 1 2 4 3 5

Sample Output 1
0
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxNearestStation(vector<int> c, int n) {
	int maxNearest = 0;
    
    if (c.size() == n)
        return 0;
    
    sort(c.begin(), c.end());
    //if first stations is towards the end
    maxNearest = max(maxNearest, c[0]);
        
	for (int i = 0; i < c.size() - 1; ++i) {
		maxNearest = max(maxNearest, (c[i+1]-(c[i]))/2 );
	}
    
    //if last station are towards the begining
    maxNearest = max(maxNearest, (n-1) - c[c.size() - 1]);
	return maxNearest;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
	cout << maxNearestStation(c, n);
    return 0;
}