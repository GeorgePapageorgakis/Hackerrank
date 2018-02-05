/*
Happy Ladybugs is a board game having the following properties:

    The board is represented by a string, b, of length n. The ith character of the string, bi, denotes the ith cell of the board.
        If bi is an underscore (i.e., _), it means the ith cell of the board is empty.
        If bi is an uppercase English alphabetic letter (i.e., A through Z), it means the ith cell contains a ladybug of color bi.
        String b will not contain any other characters.
    A ladybug is happy only when its left or right adjacent cell (i.e., bi+-1) is occupied by another ladybug having the same color.
    In a single move, you can move a ladybug from its current position to any empty cell.

Given the values of n and b for g games of Happy Ladybugs, determine if it's possible to make all the ladybugs happy. For each game, print YES on a new line if all the ladybugs can be made happy through some number of moves; otherwise, print NO to indicate that no number of moves will result in all the ladybugs being happy.

Constraints:
	1 <= g <= 100
	1 <= n <= 100

Sample Input 0
4
7
RBY_YBR
6
X_Y__X
2
__
6
B_RRBR

Sample Output 0
YES
NO
YES
YES
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isSolvableHappyLadybugs(string s)  {
	
	//create a histogram of letter frequency.
	vector<int> histogram(27);
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != '_')
			++histogram[(int)s[i] - 65];
		else
			++histogram[26];
	}
    
	//if there is an odd quantity of a letter return false
	for (int i = 0; i < histogram.size() - 1 ; ++i) {
		if (histogram[i] == 1)
			return false;
	}
	//check if string is already solved in case of no '_' characters
	if (histogram[26] == 0) {
		for (int i = 1; i < s.length() - 1; ++i) {
			if ( (s[i] != s[i-1]) && (s[i] != s[i+1]) )
				return false;		
		}
	}
	return true;
}


int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int n;
        cin >> n;
        string b;
        cin >> b;
		cout << (isSolvableHappyLadybugs(b) ? "YES" : "NO" ) << endl;
    }
    return 0;
}