/*
Suppose you have a String, S, of length N that is indexed from 0 to N−1. You also have some String, R, that is the reverse of String S. S is funny if the condition |S[i]−S[i−1]|=|R[i]−R[i−1]| is true for every character i from 1 to N−1.

Note: For some String S, S[i] denotes the ASCII value of the ith 0-indexed character in S. The absolute value of an integer, x, is written as |x|. 
*/
#include <iterator>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


void isFunny(vector<string> & vs) {
	string rstr;
	bool fun = 1;

	for (unsigned i = 0; i<vs.size(); ++i){
		rstr.resize(vs[i].size());
		reverse_copy(vs[i].begin(), vs[i].begin() + vs[i].size(), rstr.begin());

		for (unsigned j = 1; j<vs[i].size(); ++j) {
			if (abs(vs[i][j] - vs[i][j - 1]) != abs(rstr[j] - rstr[j - 1])) {
				fun = 0;
			}
		}
		if (fun)
			cout << "Funny" << endl;
		else
			cout << "Not Funny" << endl;
        fun = 1;
	}
}

int main() {
    cin.ignore(8,'\n');
    vector<string> S( std::istream_iterator<string>( std::cin ), std::istream_iterator<string>() );

	isFunny(S);
    
    return 0;
}
