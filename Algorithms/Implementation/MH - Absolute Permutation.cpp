/*
We define P to be a permutation of the first N natural numbers in the range [1,N]. Let posi denote the position of i in permutation P (please use 1-based indexing).

P is considered to be an absolute permutation if abs(posi - i) = K holds true for every i ε [1,N].

Given N and K, print the lexicographically smallest absolute permutation, P; if no absolute permutation exists, print -1.

Constraints:
	1 <= T <=10
	1 <= N <= 10^5
	0 <= K < N

Sample Input
3
2 1
3 0
3 2

Sample Output
2 1
1 2 3
-1

Input:
1
100 2

Output: (notice period of + -)
+ + - - + + - - +  +  -  -  +  +  -  -  +  +  -  -  +  +  -  -  +  +
3 4 1 2 7 8 5 6 11 12 9 10 15 16 13 14 19 20 17 18 23 24 21 22 27 28 25 26 31 32 29 30 35 36 33 34 39 40 37 38 43 44 41 42 47 48 45 46 51 52 49 50 55 56 53 54 59 60 57 58 63 64 61 62 67 68 65 66 71 72 69 70 75 76 73 74 79 80 77 78 83 84 81 82 87 88 85 86 91 92 89 90 95 96 93 94 99 100 97 98

Input:
10
92 40
94 70
95 49
92 14
96 2
98 7
92 85
90 15
92 10
94 0

Output:
-1
-1
-1
-1
3 4 1 2 7 8 5 6 11 12 9 10 15 16 13 14 19 20 17 18 23 24 21 22 27 28 25 26 31 32 29 30 35 36 33 34 39 40 37 38 43 44 41 42 47 48 45 46 51 52 49 50 55 56 53 54 59 60 57 58 63 64 61 62 67 68 65 66 71 72 69 70 75 76 73 74 79 80 77 78 83 84 81 82 87 88 85 86 91 92 89 90 95 96 93 94
8 9 10 11 12 13 14 1 2 3 4 5 6 7 22 23 24 25 26 27 28 15 16 17 18 19 20 21 36 37 38 39 40 41 42 29 30 31 32 33 34 35 50 51 52 53 54 55 56 43 44 45 46 47 48 49 64 65 66 67 68 69 70 57 58 59 60 61 62 63 78 79 80 81 82 83 84 71 72 73 74 75 76 77 92 93 94 95 96 97 98 85 86 87 88 89 90 91
-1
16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75
-1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// class generator:
struct c_unique {
  int current;
  c_unique() {current = 0;}
  int operator()() {return ++current;}
} UniqueNumber;


vector<int> isAbsolutePermutation (int n, int k) {
    vector<int> v;
    v.resize(n);
    generate(v.begin(), v.end(),UniqueNumber);
	//If k=0 just print 1...n, if not check permutations
    if(k != 0) {
		//if n is even and multiple of period 2*k perform permutations
		if(n % (2*k) == 0) {
			for(int i = 0; i < n; ++i) {
				v[i] += k;
				//periodic change of sign
				if(v[i] % k == 0) {
                    k *= -1;
                }
			}
		}
		else {
			return vector<int>(1,-1);
		}
    }
    return v;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;

        for (auto & i : isAbsolutePermutation(n,k))
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}