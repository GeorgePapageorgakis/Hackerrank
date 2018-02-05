/*
Gary is an avid hiker. He tracks his hikes meticulously, paying close attention to small details like topography. During his last hike, he took exactly n steps. For every step he took, he noted if it was an uphill or a downhill step. Gary's hikes start and end at sea level. We define the following terms:

    A mountain is a non-empty sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
    A valley is a non-empty sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.

Given Gary's sequence of up and down steps during his last hike, find and print the number of valleys he walked through.	

Constraints:
	2 <= N <= 10^5

Sample Input
8
UDDDUDUU

Sample Output
1

*/

#include <vector>
#include <iostream>
using namespace std;

int countValleys(vector<char> & ar) {
	int count = 0, seaLvl = 0;
	for(int i = 0; i < ar.size(); ++i) {
		if ( (seaLvl < 0) && (seaLvl +  (ar[i] == 'U' ? 1 : -1) == 0) ) {
			++count;
		}
		seaLvl += (ar[i] == 'U' ? 1 : -1);
    }	
	return count;
}

int main() {
    int n;
    cin >> n;
    vector<char> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = countValleys(ar);
    cout << result << endl;
    return 0;
}