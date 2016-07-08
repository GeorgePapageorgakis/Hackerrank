/*
two kangaroos on an x-axis ready to jump in the positive direction (i.e, toward positive infinity). The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump. The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump. Given the starting locations and movement rates for each kangaroo, can you determine if they'll ever land at the same location at the same time?
Sample Input 0
0 3 4 2

Sample Output 0
YES

The two kangaroos jump through the following sequence of locations:
0 -> 3 -> 6 -> 9 -> 12
4 -> 6 -> 8 -> 10 -> 12
Thus, the kangaroos meet after 4 jumps and we print YES.
*/
#include <iostream>
using namespace std;

int main(){
    int x1, v1, x2, v2;
    
    cin >> x1 >> v1 >> x2 >> v2;
    //if second kangoroo moves faster the first one will never reach it
    if ((v2 < v1) && ((x2 - x1) % (v2 - v1) == 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}