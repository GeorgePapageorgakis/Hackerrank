/*
Given set S={1,2,3,…,N} find two integers, A and B (where A<B), from set S such that the value of A&B is the maximum possible and also less than a given integer, K. In this case, & represents the bitwise AND operator.
*/
#include <string>
#include <bitset>
#include <cstdio>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n, k, max;
        cin >> n >> k;
        //cout << "n " << n << ' ' << "k " << k << endl;
        /*
        for(int i=1; i<n+1; ++i){
            cout << static_cast<bitset<8>>(i); 
            if(i == k-1)
                cout << " <- k-1";
            cout << endl;
        }
        */
        max=0;
        for(int i=1; i<n+1; ++i){
            int aux;
            for(int j=i+1; j<n+1; ++j){
                aux = i&j;
                if(aux < k && aux > max)
                    max = aux;
                    
                    //cout << i << " " << j << " = " << static_cast<bitset<8>>(i&j) << endl; 
                /*if(i&j > k)
                    cout << " > k";
                else if(i&j == k)
                    cout << " = k";
                cout << endl;*/
            }
        }
        cout << max << endl;
        //cout << "--------------------" << endl;
        
    }
    
    return 0;
}