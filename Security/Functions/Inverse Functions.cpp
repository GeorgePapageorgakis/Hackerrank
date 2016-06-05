/*
Find the inverse of a function f(x)=x. 
It's the inverse of itself.

f(1)=2		f^-1(1)=3
f(2)=3		f^-1(2)=1
f(3)=1		f^-1(3)=2

Sample Input
	3
	2 3 1

Sample Output
	3
	1
	2
*/
#include <vector>
#include <iostream>
using namespace std;

vector<int> inverseFunction(int& n){
    vector<int> function(n);
    vector<int> inversefunc(n);
    for (int i=0; i<n; ++i){
        cin >> function[i];
    }
    for (int i=0; i<n; ++i){
        inversefunc[function[i]-1] = i+1;
    }
    return inversefunc;
}

int main() {
    int n;
    cin >> n;
    const vector<int>& inverse = inverseFunction(n);
    for (auto i : inverse) cout << i << endl;
    return 0;
}