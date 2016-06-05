/*
Given a base-10 integer, n, convert it to binary (base-2). Then find and print the base-10 integer denoting the maximum number of consecutive 1's in n's binary representation.
*/

#include <bitset>
#include <iostream>
using namespace std;

int maxConsecutiveBinary (int n){
    //for 32bit integers
    int max = 0;
    int count = 0;
    bitset<32> binary = bitset<32>(n);

    if (n == 0)
        return 0;   
    for(int i=0; i<binary.size(); ++i) {
        if (binary.test(i)){
            ++count;
        }
        else{ 
            if (count > max)
                max = count;
            count = 0;
        }   
    }
    return max;
}


int main(){
    int n;
    cin >> n;
    cout << maxConsecutiveBinary(n);
    
    return 0;
}
