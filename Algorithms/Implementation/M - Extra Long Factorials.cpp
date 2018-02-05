/*
You are given an integer N. Print the factorial of this number.
	N! = N x (N-1) x (N-2) x ... x 3 x 2 x 1
	
Input:
	single integer N, where 1 <= N <= 100.

Output
	Print the factorial of N.

Example
For input 25, you would print 15511210043330985984000000.

Note: Factorials of N>20 can't be stored even in a 64-bit long long variable. Big integers must be used for such calculations. Languages like Java, Python, Ruby etc. can handle big integers, but we need to write additional code in C/C++ to handle huge values.
*/
#include <vector>
#include <iostream>

using namespace std;

#define MAX_DIGITS 500

void multiply(int x, vector<int> & res) {
    int carry = 0;
	int num_base = 10;

	// One by one multiply n with individual digits of res[]
    for (int i = 0; i < res.size(); ++i) {
        int prod = res[i] * x + carry;
        res[i] = prod % num_base;	// Store last digit of 'prod' in res[]
        carry  = prod / num_base;	// Put rest in carry
    }

	// Put carry in res and increase result size
    while (carry) {
        res.push_back(carry % num_base);
        carry = carry / num_base;
    }
}

// find factorial of large numbers and print them
void factorial(int n) {
    vector<int> res(0);
	res.reserve(MAX_DIGITS);
 
    // Initialize result
    res.push_back(1);
 
    // Simple factorial formula n! = 1 * 2 * 3 ... * n
    for (int i = 2; i < n + 1; ++i)
        multiply(i, res);
 
    for (int i = res.size() - 1; i >= 0; --i)
        cout << res[i];
}

int main(){
    int n;
	
    cin >> n;
    factorial(n);
	
    return 0;
}