/*
Given a number n, determine and print whether it's Prime or Not prime.
Note: If possible, try to come up with a O(√n) primality algorithm, or see what sort of optimizations you come up with for an O(n) algorithm.

Sample Input:
3
12
5
7

Sample Output:
Not prime
Prime
Prime
*/

/*
https://en.wikipedia.org/wiki/Primality_test

function is_prime(n : integer)
    if n ≤ 1
        return false
    else if n ≤ 3
        return true
    else if n mod 2 = 0 or n mod 3 = 0
        return false
    let i ← 5
    while i×i ≤ n
        if n mod i = 0 or n mod (i + 2) = 0
            return false
        i ← i + 6
    return true
------------------------------------------------
	*   Improved O( n^(1/2)) ) Algorithm
    *   Checks if n is divisible by 2 or any odd number from 3 to sqrt(n).
    *   The only way to improve on this is to check if n is divisible by KNOWN PRIMES from 2 to sqrt(n).
    *
    *   @param n An integer to be checked for primality.
    *   @return true if n is prime, false if n is not prime.
    *
*/
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

//modulo = expression & (constant-1) (only for power of 2)
bool is_prime(int& n){
    // check lower boundaries on primality
    if( n == 2 ){ 
        return true;
    } //1 is not prime, even numbers > 2 are not prime
    else if( n == 1 || n % 2 == 0){
        return false;
    }
    // Check for primality using odd numbers from 3 to sqrt(n)
    for(int i = 3; i < sqrt(n); i += 2){
        // n is not prime if it is evenly divisible by some 'i' in this range
        if( n % i == 0 ){ 
            return false;
        }
    }
    // n is prime
    return true;
}

int main() {
    int Q, k;
    cin >> Q;
    for (unsigned q=0; q<Q; ++q){
        cin >> k;   
        cout << (is_prime(k) ? "Prime" : "Not prime") << endl;
    } 
    return 0;
}