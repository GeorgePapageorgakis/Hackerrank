/*
Sam's house has an apple tree and an orange tree that yield an abundance of fruit. In the diagram below, the red region denotes his house, where s is the start point and t is the end point. The apple tree is to the left of his house, and the orange tree is to its right. You can assume the trees are located on a single point, where the apple tree is at point a and the orange tree is at point b.

When a fruit falls from its tree, it lands d units of distance from its tree of origin along the x-axis. A negative value of d means the fruit fell d units to the tree's left, and a positive value of d means it falls d units to the tree's right.

Given the value of d for m apples and n oranges, can you determine how many apples and oranges will fall on Sam's house (i.e., in the inclusive range [s, t] )? Print the number of apples that fall on Sam's house as your first line of output, then print the number of oranges that fall on Sam's house as your second line of output.

Input Format

The first line contains two space-separated integers denoting the respective values of s and t.
The second line contains two space-separated integers denoting the respective values of a and b.
The third line contains two space-separated integers denoting the respective values of m and n.
The fourth line contains m space-separated integers denoting the respective distances that each apple falls from point a.
The fifth line contains n space-separated integers denoting the respective distances that each orange falls from point b.

Sample Input 0
7 11
5 15
3 2
-2 2 1
5 -6

Sample Output 0
1
1
**/
#include <bits/stdc++.h>
using namespace std;

int countWithinRange(const int &r1, const int &r2, const int &refPoint, const vector<int> &points){
	int count = 0;
	for ( vector<int>::const_iterator cit = points.begin(); cit != points.end(); ++cit ) {
		int dropPoint = refPoint + *cit;
		if ((dropPoint > r1-1) && (dropPoint < r2+1)) {
			++count;
		}
	}
	return count;
}

int main(){
    int s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    int m, n;
    cin >> m >> n;
	
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }
	
	cout << countWithinRange(s, t, a, apple) << endl;
	cout << countWithinRange(s, t, b, orange) << endl;
    return 0;
}
