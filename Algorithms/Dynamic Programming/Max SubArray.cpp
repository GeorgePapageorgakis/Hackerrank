/*
Given an array A={a1, a2, ..., an} of elements, find the maximum possible sum of a
    1. Contiguous subarray
    2. Non-contiguous (not necessarily contiguous) subarray.

Empty subarrays/subsequences should not be considered.

Sample Input:
	2 
	4 
	1 2 3 4
	6
	2 -1 2 3 4 -5

Sample Output:
	10 10
	10 11
	
Method used:
s = max{ s + A[i], A[i]}
		   ___________
	|-2|-3|4|-1|-2|1|5|-3|
		  ^    ^  ^ ^ ^
	s(1) = -2
	s(2) = max{ s(1) + A(2), A(2) } = max{-5, -3} = -3
	s(3) = max{ -3 + 4, 4 } 	= 4
	s(4) = max{ 4 + (-1), -1 }	= 3
	s(5) = max{ 3 + (-2), -2 }	= 1
	s(6) = max{ 1 + 1, 1 }		= 2
	s(7) = max{ 2 + 5, 5 }		= 7		<- max
	s(8) = max{ 7 + (-3), -3 }	= 4
*/

#include <numeric>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned int t, n;
    long int Max, sum;
    vector<int> v;
    
    //get # of test cases
    cin >> t;
    for (unsigned int i=0; i<t; ++i){
        cin >> n;
        v.resize(n);
        //get array of ints
        for (unsigned int j=0; j<n; ++j)
            cin >> v[j];
        
        
        //Dynamic Calculation (with overlapping frame) of Max for Contiguous subarrays
        Max = LONG_MIN;
        sum = 0;
        for (unsigned int k=0; k<v.size(); ++k){
            sum = max(static_cast<long int>(sum + v[k]), static_cast<long int>(v[k]));
			if (sum > Max)
                Max = sum;
        }
        cout << Max << " ";
        
        
        //Calculate Max for Non-Contiguous subarrays
        sort(v.begin(), v.end(), greater<int>());
        sum = 0;
        for (unsigned int k=0; k<v.size(); ++k){
            if ((v[k] < 1) && (k > 0))
                break;
            sum += v[k];
        }
        cout << sum << endl;
    }
    return 0;
}