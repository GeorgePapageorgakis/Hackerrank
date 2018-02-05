/*
Consider two sets of positive integers, A = { a0, a1, ... an-1 } and B = { b1, b2, ... bm-1 }. We say that a positive integer, x, is between sets A and B if the following conditions are satisfied:

   1. All elements in A are factors of x.
   2. x is a factor of all elements in B.

In other words, some x is between A and B if that value of x satisfies x mod ai = 0 for every ai in A and also satisfies bi mod x = 0 for every bi in B. For example, if A = {2, 6} and B = {12}, then our possible x values are 6 and 12.

Given A and B, find and print the number of integers (i.e., possible x's) that are between the two sets.

Sample Input
2 3
2 4
16 32 96

Sample Output
3

O(n log(n)) solution.
1. find the LCM of all the integers of array A.
2. find the GCD of all the integers of array B.
3. Count the number of multiples of LCM that evenly divides the GCD.

/*Important Properties:
Commutative Law:
LCM(a, b) = LCM(b, a)
GCD(a, b) = GCD(b, a)

Associative Law:
LCM(a, b, c) = LCM(LCM(a, b), c)
GCD(a, b, c) = GCD(GCD(a, b), c)

This can be extended to any number of numbers.
*/
#include <bits/stdc++.h>
using namespace std;

//Euclidean Algorithm
int gcd(int a, int b) {
	while (b > 0) {
		int temp = b;
		b = a % b; //get remainder
		a = temp;
	}
	return a;
}


int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}


int getTotalX(vector < int > &a, vector < int > &b) {
	int count = 0;
	int a_lcm = a[0];
	int b_gcd = b[0];

	//calculate LCM of vector a
	for (int i = 1; i < a.size(); ++i) {
		a_lcm = lcm(a_lcm, a[i]);
	}
	
	//calculate GCD of vector b
	for (int i = 1; i < b.size(); ++i) {
		b_gcd = gcd(b_gcd, b[i]);
	}
	
	//Count the number of multiples of LCM that evenly divides the GCD.
	if (b_gcd < a_lcm){
        return 0;
    }
	for (int i = a_lcm; i < b_gcd+1; i += a_lcm) {
            if(b_gcd % i == 0) { 
				count++;
			}
        }
	return count;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}