/*
Given two points P and Q, output the symmetric point of point P about Q.
Sample Input
2
0 0 1 1
1 1 2 2

Sample Output
2 2
3 3
*/
#include <utility>
#include <iostream>

using namespace std;

pair<int, int> symmetricPoint(pair<int, int>& P, pair<int, int>& Q){
    int x, y;
    x = Q.first - P.first;
    y = Q.second - P.second;    
    return make_pair(Q.first + x, Q.second + y);
}

int main() {
    int t;
    pair<int, int> P, Q, res;
    
    cin >> t;
    for (int i=0; i<t; ++i){
        cin >> P.first >> P.second >> Q.first >> Q.second;
        res = symmetricPoint(P, Q);
        cout << res.first << " " << res.second << endl;        
    }
    return 0;
}