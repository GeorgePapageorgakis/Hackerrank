/*
if f = f^-1 then f is called an involution. 
In other words, a function is called an involution if f(f(x)) = x
Determine whether f is an involution or not.
*/
#include <vector>
#include <iostream>
//#include <algorithm>
using namespace std;

vector<int> inverseFunction(vector<int>& function){
    vector<int> inversefunc(function.size());
    for (int i=0; i<function.size(); ++i)
        inversefunc[function[i]-1] = i+1;
    return inversefunc;
}

bool involutionFunction(int& n){
    vector<int> function(n);
    for (int i=0; i<n; ++i){
        cin >> function[i];
    }
    const vector<int>& inverse = inverseFunction(function);
    for (int i=0; i<n; ++i){
        if(function[i] != inverse[i])
            return false;    
    }   
    //if (! std::equal(function.begin(), function.end(), function))
    //    return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    
    cout << (involutionFunction(n) ? "YES" : "NO");
    
    return 0;
}