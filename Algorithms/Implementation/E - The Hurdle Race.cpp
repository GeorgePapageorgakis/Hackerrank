/*
Dan is playing a video game in which his character competes in a hurdle race by jumping over n hurdles with heights h0, h1 ... hn-1. He can initially jump a maximum height of k units, but he has an unlimited supply of magic beverages that help him jump higher! Each time Dan drinks a magic beverage, the maximum height he can jump during the race increases by 1 unit.

Given n, k, and the heights of all the hurdles, find and print the minimum number of magic beverages Dan must drink to complete the race.

Sample Input 0
5 4
1 6 3 5 2

Sample Output 0
2

Sample Input 1
5 7
2 5 4 5 2

Sample Output 1
0

*/
#include <iostream>
#include <vector>
using namespace std;

int numOfOverheight(vector<int> & height, int k) {
    int totalBeverages = 0;
    
    for (int i = 0; i < height.size(); ++i) {
        if (height[i] > k) {
            totalBeverages += height[i] - k;
            k = height[i];
        }
    }
    return totalBeverages;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    cout << numOfOverheight(height, k);
    return 0;
}