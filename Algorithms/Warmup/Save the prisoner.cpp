/*
 Ν prisoners, and each prisoner has a unique id number, S, ranging from 1 to N. There are M sweets that must be distributed to the prisoners.

The jailer decides the fairest way to do this is by sitting the prisoners down in a circle (ordered by ascending S), and then, starting with some random S, distribute one candy at a time to each sequentially numbered prisoner until all M candies are distributed. For example, if the jailer picks prisoner S=2, then his distribution order would be (2,3,4...n-1,n,1,2,3...) until all sweets are distributed.

But there's a catch, the very last sweet is poisoned! Find and print the ID number of the last prisoner to receive a sweet so he can be warned.
Sample Input
1 
5 2 1

Sample Output
2
*/
#include <iostream>
using namespace std;

int findID(long int& N, long int& M, long int& S){
    if ((M+S-1)%N == 0)
        return N;
    else
        return (M+S-1)%N;
}

int main() {
    int T;
    long int N, M, S;
    cin >> T;
    for (int i=0; i<T; ++i){
        cin >> N >> M >> S;
        cout << findID(N, M, S) << endl;
    }
    return 0;
}