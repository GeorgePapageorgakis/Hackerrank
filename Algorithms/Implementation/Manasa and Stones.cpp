/*
Manasa is out on a hike with friends. She finds a trail of stones with numbers on them. She starts following the trail and notices that two consecutive stones have a difference of either a or b. Legend has it that there is a treasure trove at the end of the trail and if Manasa can guess the value of the last stone, the treasure would be hers. Given that the number on the first stone was 0, find all the possible values for the number on the last stone.

Note: The numbers on the stones are in increasing order.

Input Format
The first line contains an integer T, i.e. the number of test cases. T test cases follow; each has 3 lines. The first line contains n (the number of stones). The second line contains a, and the third line contains b. 
*/
#include <cmath>
#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Compute difference between min and max (of a, b), start a while loop at lowest possible answer; min*(n-1).
Subsequently add difference to the possible final value and iterate until final value = maxium output of max*(n-1).
*/
int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        int stones, a, b, min, max, diff, final;
        set<int> solutions;
        solutions.clear();
        cin >> stones; cin >> a; cin >> b;
        max = std::max(a,b);
        min = std::min(a,b);
        diff = max - min;
        final = min*(stones-1);
        if(!diff)
            cout << final;
        else{
            while( final < max*(stones-1)+1){
                solutions.insert(final);
                final += diff;
            }            
        }
        for_each(solutions.begin(), solutions.end(), [](int const& i) { cout << i << ' '; });
        cout << endl;
    }
    return 0;
}
