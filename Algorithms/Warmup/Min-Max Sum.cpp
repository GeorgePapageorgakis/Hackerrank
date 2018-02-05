/*
Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers.

Input Format

A single line of five space-separated integers.

Constraints

    Each integer is in the inclusive range [1, 10^9].

Output Format

Print two space-separated long integers denoting the respective minimum and maximum values that can be calculated by summing exactly four of the five integers. (The output can be greater than 32 bit integer.)

Sample Input
1 2 3 4 5

Sample Output
10 14
*/

#include <bits/stdc++.h>

using namespace std;
pair<unsigned long int, unsigned long int> minMaxSum(vector<unsigned long int> &arr){
    vector<unsigned long int> minElem(4, ULONG_MAX);
    vector<unsigned long int> maxElem(4, unsigned(0));
    for ( vector<unsigned long int>::const_iterator cit = arr.cbegin(); cit != arr.cend(); ++cit){
        vector<unsigned long int>::iterator it;
        
        it = max_element(minElem.begin(),minElem.begin()+4);
        if (*cit < *it){
            *it = *cit;
        }
        it = min_element(maxElem.begin(),maxElem.begin()+4);
        if (*cit > *it){
            *it = *cit;
        }
    }    
    return make_pair(accumulate(minElem.begin(),minElem.begin()+4, unsigned(0)), 
                     accumulate(maxElem.begin(),maxElem.begin()+4, unsigned(0)));
}

int main() {
    vector<unsigned long int> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
    
    pair<unsigned long int, unsigned long int> solution = minMaxSum(arr);
    cout << solution.first << " " << solution.second;
    return 0;
}