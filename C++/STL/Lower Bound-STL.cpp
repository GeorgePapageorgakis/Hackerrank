/*
For each query you have to print "Yes"(without the quotes) if the number is present and at which index it is present separated by a space.
If the number is not present you have to print "No"(without the quotes) followed by the index of the next smallest number just greater than that number.
You have to output each query in a new line.

Sample Input
 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15

Sample Output
 Yes 1
 No 5
 Yes 6
 Yes 8
*/
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    cin >> N;
    vector<int> v(N,0);
    for(unsigned i=0; i<N; ++i){
        cin >> v[i];
    }
    //test cases
    cin >> Q;
    for(unsigned i=0; i<Q; ++i){
        cin >> N;
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), N);
        if(*it == N){
            cout<< "Yes " << distance(v.begin(), it)+1 << endl;
        }
        else{
            cout << "No " << distance(v.begin(), it)+1 << endl;
        }
    }
    return 0;
}
