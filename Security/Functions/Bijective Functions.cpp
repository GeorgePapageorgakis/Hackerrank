/*
If the function f is both one-to-one and onto then f is a bijection from X to Y or, equivalently, 
f: X -> Y is a bijective function.

In this task, you'll be given an integer n and a function f: X -> Y where X = {1,2,3 ..., n}.
Determine whether the given function is a bijective function or not.

Sample Input
	3
	1 2 3

Sample Output
	YES

	There are 2 lines in the input.
	The first line contains a single positive integer n.
	The second line contains space separated integers, the values of f(1), f(2), f(3), ... f(n) respectively.
*/
#include <set>
#include <iostream>
using namespace std;

bool isBijectiveFunction(int& n){
    set<int> vals;
    for (int i=0; i<n; ++i){
        int k;
        cin >> k;
        if (vals.count(k))
            return false;
        else
            vals.insert(k);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << (isBijectiveFunction(n) ? "YES" : "NO");
    return 0;
}