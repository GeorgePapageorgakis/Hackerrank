/*Erica wrote an increasing sequence of n numbers (a0, a1, ... an-1) in her notebook. She considers a triplet (ai, aj, ak) to be beautiful if:

	i < j < k
	a[j] - a[i] = a[k] - a[j] = d

Given the sequence and the value of d, can you help Erica count the number of beautiful triplets in the sequence?

Sample Input
7 3
1 2 4 5 7 8 10

Sample Output
3

Explanation
Our input sequence is 1, 2, 4, 5, 7, 8, 10, and our beautiful difference d = 3. There are many possible triplets (ai, aj, ak), but our only beautiful triplets are (1, 4, 7), (4, 7, 10) and (2, 5, 8). Please see the equations below:

7 - 4 = 4 - 1 = 3 = d
10 - 7 = 7 - 4 = 3 = d
8 - 5 = 5 - 2 = 3 = d
*/

#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countBeautifulTriplets( vector<int> & vals, int & d) {
	//use hashing for faster value lookup, guaranteed that values are unique
	unordered_map<int, int> mymap;
    transform(vals.begin(), vals.end(), inserter(mymap, mymap.end()), [&] (int v) { return make_pair(v, v); });
	
	//count if pairs of val+d and val+2*d exist in the hashing table
    int count = count_if( begin(vals), end(vals),
        [&](int val) {
            return (mymap.find(val + d) != mymap.end()) && (mymap.find(val + 2 * d) != mymap.end());
        });
	return count;
}

int main() {
	int n, d;
	cin >> n >> d;
	
    vector<int> vals(n);
    for (auto& val : vals)
        cin >> val;

    cout << countBeautifulTriplets(vals, d) << endl;
    return 0;
}