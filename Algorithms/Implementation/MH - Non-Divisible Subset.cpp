/*
Given a set, S, of n distinct integers, print the size of a maximal subset, S', of S where the sum of any 2 numbers in S' is not evenly divisible by k.

Constraints:
	1 <= n <= 10^5
	1 <= k <= 100
	1 <= ai <= 10^9
    All of the given numbers are distinct.


Sample Input
4 3
1 7 2 4

Sample Output
3

The largest possible subset of integers is S' = {1, 7, 4}, because no two integers will have a sum that is evenly divisible by k = 3:

    1 + 7 = 8, and 8 is not evenly divisible by 3.
    1 + 4 = 5, and 5 is not evenly divisible by 3.
    7 + 4 = 11, and 11is not evenly divisible by 3.

The number 2 cannot be included in our subset because it will produce an integer that is evenly divisible by k = 3 when summed with any of the other integers in our set:

    1 + 2 = 3, and 3/3 = 1 (remainder 0).
    4 + 2 = 6, and 6/3 = 2 (remainder 0).
    7 + 2 = 9, and 9/3 = 3 (remainder 0).

Thus, we print the length of S' on a new line, which is 3.


main logic 
if (a+b)%K=0(means evenly divisible) 
then (a%k+b%K=K)

6 9
422346306 940894801 696810740 862741861 85835055 313720373

5	_____________________________________
	|   |   |   |   |   |   |   |   |   |
	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
	|___|___|___|___|___|___|___|___|___|
			 313 422	 696	 940
				 858			 862

5 1
1 2 3 4 5

1

10 4
1 2 3 4 5 6 7 8 9 10

5
*/
#include <vector>
#include <iostream>
using namespace std;

int SizeOfNonDivSubset( vector<int>& s, int& k){
    int maxSubset = 0;
	
	//special case since all the numbers will be evenly divisible
	if (k == 1)
		return 1;

    //make a frequency array (histogram) to count values that are not divisible by k
    vector<int> remaindersHisto(k);
    
    //Insert values and frequencies in frequency array
	for(int i = 0; i < s.size(); ++i){
		++remaindersHisto[ s[i] % k ];   
	}
	//if k1 and k2 have remainders we have to include only the higher freq
	//check couple sum in remaindersHisto remainders, if its equal to k include only the higher frequency
	for(int i = 1; i <= k/2; ++i){
		if(i == k-i)
			maxSubset++;
		else
			maxSubset += max(remaindersHisto[i], remaindersHisto[k-i]);
	}
	if(remaindersHisto[0])
		maxSubset++;
		
    return maxSubset;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << SizeOfNonDivSubset(a, k) << endl; 
    return 0;
}