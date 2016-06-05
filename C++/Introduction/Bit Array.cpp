/*
You are given four integers: N, S, P, Q. You will use them in order to create the sequence a with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = (a[i-1]*P+Q) (modulo 2^31) 

Your task is to calculate the number of distinct integers in the sequence a.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //use bitwise operations where possible.
    //Use a mapping vector with mask to mimize memory size
    unsigned long N, S, P, Q, aux, 
    count = 1,
    mask = 32,  //for 32-bit integers
    pow_2_31 = static_cast<unsigned>(1<<31);  //2^31
    vector<int> * v = new vector<int>((pow_2_31/mask) ,0);
    
    cin >> N >> S >> P >> Q;
    
    //modulo = expression & (constant-1) (only if constant is power of 2)
    aux = S & (pow_2_31 - 1);
    //set bits of corresponding sequence number in vector element with OR operation
    v->at(aux/mask) |= (1 << (aux & (mask - 1)));
    
    //check all numbers in sequence
    for (unsigned i=1; i<N; ++i){
        aux = (aux*P + Q) & (pow_2_31 - 1);
        //check if the aux number's bit footprint is already set. AND operation.
        //If false it means that the number has not been seen again in sequence
        if ( !( v->at(aux/mask) & (1 << (aux & (mask - 1))) ) ){
            //set bits of corresponding sequence number in vector element with OR operation
            v->at(aux/mask) |= (1 << (aux & (mask - 1)));
            ++count;
        }
    }   
    cout << count;
    
    return 0;
}
