/*
Given an integer, N, traverse its digits (d1,d2,...,dn) and determine how many digits evenly divide N (i.e.: count the number of times N divided by each digit di has a remainder of 0). Print the number of evenly divisible digits.

Note: Each digit is considered to be unique, so each occurrence of the same evenly divisible digit should be counted (i.e.: for N=111, the answer is 3).
*/
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
Convert integers to digits and calculate digits' even division
*/
int findDigits (int & n){
    int count = 0;
    string s = to_string(abs(n));
    //ASCII code numbers start from 48.
    for(string::iterator it = s.begin(); it != s.end(); ++it) {
        int num = (int)*it - 48;
        if ((num!=0) && (n%num==0))
            ++count;   
    }
    return count;
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << findDigits(n) << endl;
    }
    return 0;
}
