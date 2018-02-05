/**
You are given two arrays A and B each containing n integers. You need to choose exactly ONE number from A and exactly ONE number from B such that the index of the two chosen numbers is not same and the sum of the 2 chosen values is minimum.

Your objective is to find and print this minimum value. 

Sample Input 0
5
5 4 3 2 1
1 2 3 4 5

Sample Output 0
2

Explanation 
Minimum sum will be obtained by chosing number at the last index of first array and first index of the second array, i.e. 2.


smallest = a[0]
second = a[1]
if second < smallest:
    swap second with smallest
for each index 2 thru a.size :
    if a[index] < smallest:
        second = smallest
        smallest = a[index]
    else:
        if a[index] < second:
            second = a[index]
*/

#include <bits/stdc++.h>

using namespace std;

int twinArrays(vector <int> ar1, vector <int> ar2){
        int smallest = 0, second = 1;	//overal min, runner-up min
	
	
	if (ar1[smallest] > ar1[second]){
        smallest = 1;	//smallest is now index 1
        second = 0;		//second smallest is now index 0
    }
	for ( int i = 2; i < ar1.size(); ++i){
		if ( ar1[i] < ar1[smallest]){
			second = smallest;
			smallest = i;
		}
		else{
			if (ar1[i] < ar1[second]){
				second = i;
            }
		}
	}
	int idx_11 = smallest, idx_12 = second;

	
	smallest = 0; second = 1;
	
	if (ar2[smallest] > ar2[second]){
        smallest = 1;	//smallest is now index 1
        second = 0;		//second smallest is now index 0
    }
	for ( int i = 2; i < ar2.size(); ++i){
		if ( ar2[i] < ar2[smallest]){
			second = smallest;
			smallest = i;
		}
		else{
			if (ar2[i] < ar2[second]){
                second = i;
            }
		}
	}
	
	int idx_21 = smallest, idx_22 = second;
	
	//find minimum sum
    // min11 : min21
    // min12 : min22
	vector <int> minimums;
	if ( idx_11 != idx_21)
		minimums.push_back(ar1[idx_11] + ar2[idx_21]);
	if ( idx_11 != idx_22)
		minimums.push_back(ar1[idx_11] + ar2[idx_22]); 
	if ( idx_12 != idx_21)
		minimums.push_back(ar1[idx_12] + ar2[idx_21]);
	if ( idx_12 != idx_22)
		minimums.push_back(ar1[idx_12] + ar2[idx_22]);
	
	return *min_element(minimums.begin(),minimums.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> ar1(n);
    for(int ar1_i = 0; ar1_i < n; ar1_i++){
       cin >> ar1[ar1_i];
    }
    vector<int> ar2(n);
    for(int ar2_i = 0; ar2_i < n; ar2_i++){
       cin >> ar2[ar2_i];
    }
    int result = twinArrays(ar1, ar2);
    cout << result << endl;
    return 0;
}
