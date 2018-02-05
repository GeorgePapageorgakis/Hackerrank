/*
Maria plays n games of college basketball in a season. Because she wants to go pro, she tracks her points scored per game sequentially in an array defined as score = {s0, s1, ... sn-1}. After each game i, she checks to see if score si breaks her record for most or least points scored so far during that season.

Given Maria's array of scores for a season of n games, find and print the number of times she breaks her record for most and least points scored during the season.

Note: Assume her records for most and least points at the start of the season are the number of points scored during the first game of the season.

Input Format

The first line contains an integer denoting (the number of games).
The second line contains space-separated integers describing the respective values of s0, s1, ... sn-1.

Sample Input 0
9
10 5 20 20 4 5 2 25 1

Sample Output 0
2 4

Sample Input 1
10
3 4 21 36 10 28 35 5 24 42

Sample Output 1
4 0
*/
#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    int countHigh = 0, high = s[0];
    int countLow = 0, low = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] > high) {
            ++countHigh;
            high = s[i];
        }
        else if (s[i] < low) {
            ++countLow;
            low = s[i];
        }
    }
    return vector<int> {countHigh, countLow};
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}