/*
given a permutation f:{1,2,3, ... n} -> {1,2,3, ... n}
Output the f(f(x)) for all x ε {1,2,3, ... ν}
Sample Input:
	3
	2 3 1

Sample Output:
	3
	1
	2

Explanation: f(f(1)) = f(2) = 3 and so on...
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> permutateFunction(int& n){
    vector<int> function(n);
    vector<int> permutationsfunc(n);
    for (int i=0; i<n; ++i){
        cin >> function[i];
    }
    for (int i=0; i<n; ++i){
        permutationsfunc[i] = (function[function[i]-1]);
    }
    return permutationsfunc;
}

int main() {
    int n;
    cin >> n;
    const vector<int>& permutations = permutateFunction(n);
    for (auto i : permutations) cout << i << endl;
    return 0;
}