/*
A Discrete Mathematics professor has a class of N students. Frustrated with their lack of discipline, he decides to cancel class if fewer than K students are present when class starts.

Given the arrival time of each student, determine if the class is canceled.
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int N, K, attend;
		attend=0;
        cin >> N >> K;
        vector<int> a(N);
        for(int a_i = 0; a_i < N; a_i++){
            cin >> a[a_i];
            if (a[a_i] < 1)
                ++attend;
        }
        if (attend >= K)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
