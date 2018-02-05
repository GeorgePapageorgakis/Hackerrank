/*
Colleen is turning years old! Therefore, she has n candles of various heights on her cake, and candle i has height height_i. Because the taller candles tower over the shorter ones, Colleen can only blow out the tallest candles.

Given the height_i for each individual candle, find and print the number of candles she can successfully blow out.

Input Format

The first line contains a single integer, n, denoting the number of candles on the cake.
The second line contains n space-separated integers, where each integer n describes the height of candle i.

Sample Input 0
4
3 2 1 3

Sample Output 0
2

*/
#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(int & n, vector<int> & ar) {
    return count(ar.begin(), ar.end(), *max_element(ar.begin(),ar.begin()+n));
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}