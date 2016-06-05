/*
Julius Caesar protected his confidential information by encrypting it in a cipher. Caesar's cipher rotated every letter in a string by a fixed number, K, making it unreadable by his enemies. Given a string, S, and a number, K, encrypt S and print the resulting string.

Note: The cipher only encrypts letters; symbols, such as -, remain unencrypted. 
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i=0; i<n; ++i){
        //for Upper case
        if (s[i] > 64 && s[i] < 91){
            s[i] = 65 + ( (s[i] - 65 + k)%26  );
        }
        //for Lower case
        else if (s[i] > 96 && s[i] < 123){
            s[i] = 97 + ( (s[i] - 97 + k)%26  );
        }  
    }
    cout << s;
    return 0;
}
