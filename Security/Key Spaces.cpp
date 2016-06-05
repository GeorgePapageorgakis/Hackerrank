/*
K denotes a set called the key space. Any element of K is called a key.

Each element e ε K uniquely determines a bijection from M to C, denoted by E. The E is called an encryption function. Similarly for each d ε K, we have a bijection from C to M, denoted by D, and it is called a decryption function.

For this task, consider a message that consists of decimal digits and a key, e, which operates by shifting each digit by e places. Find the corresponding ciphertext.
Input
	391
	2
Output
	513
*/
#include <string>
#include <iostream>

using namespace std;

string encrypt(string& M, int& e){
    string s = "";
    for(char i : M){
        int k;
        k = static_cast<int>(i) - 48;
        k = (k+e)%10;
        s += to_string(k);
    }
    return s;
}

int main() {
    string M;
    int e;
    cin >> M;
    cin >> e;
    cout << encrypt(M, e);
    return 0;
}
