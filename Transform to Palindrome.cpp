/**
The Orion alphabet system consists of n letters, denoted by the integers from 1 to n. The ith Orion letter is denoted by the integer i.

Some Orion letters can be transformed to other Orion letters. A transformation is denoted by a pair of two Orion letters, x->y. Using this transformation, you can replace letter x with letter y.

Transformations also have additional properties:

   1. If letter x can be transformed to letter y using a transformation, then letter y can be transformed to letter x as well.
   2. If letter x can be transformed to letter x and letter y can be transformed to letter z, then letter x can be transformed to letter z as well.

You are given a sequence S comprising of m Orion letters. You are given k transformations that can be applied to S. You may apply transformations to zero or more letters in the sequence. When a transformation is applied to a letter, the other letters of the string remain unaffected. You can also apply a single transformation multiple times on the same sequence.

Print the length of the longest possible palindromic subsequence after applying zero or more transformations on the letters of the given sequence.

For example, in the sequence below, transformation 4->3 is first applied to the sequence 1 4 5 9 3 1 to obtain 1 3 5 9 3 1. The Longest Palindrome Subsequence is then obtained from the resulting transformed sequence by removing letter 9.

	1 4 5 9 3 1		4->3	1 3 5 9 3 1		delete 9 	1 3 5 3 1

Input Format

The first line contains three space separated integers n, k and m. The following k lines each contain two space separated integers x and y, denoting a transformation from letter x to letter y. The last line contains m positive integers (elements of the string).

Sample Input 0
10 7 6
1 3
5 7
3 5
2 6
2 4
8 4
10 9
1 9 2 3 10 3

Sample Output 0
5


Sample Input 1
10 8 15
1 2
1 3
2 7
3 1
4 5
6 8
9 6
10 5
1 4 5 7 9 8 1 3 10 4 5 10 2 7 8

Sample Output 1
10

An undirected graph can be built where letters are the nodes and tranformations are edges. Using DFS, we can find out the connected components in the graph. We can then find out whether 2 letters can be transformed to each other by checking whether they belong to the same connected component in constant time complexity.

Let DP[i][j] denote the length of the longest Palindromic Subsequence between the indices i and j (both i and j inclusive) in the string. Clearly, DP[i][i]=1 for all indices 0<= i <L. Consider the letters x and y present in the string at positions i and j respectively such that i<j.

    - If x and y can be transformed to each other and j>i+1, then DP[i][j] = DP[i+1][j-1] + 2
    - If x and y can be transformed to each other and j=i+1, then DP[i][j] = 2
    - If x and y cannot be transformed to each other then DP[i][j] = max(DP[i+1][j], DP[i][j-1])
*/

#include <bits/stdc++.h>
using namespace std;

//Find Longest Palindromic Subsequence
int LPS( vector<int> & s, vector<vector<int>> & inTrans, vector<int> & graphConComp ){
	//memoisation array
	vector< vector<int> > memoArray (s.size(), vector <int>(s.size(), 0));

	//set diagonal elements of array to 1
	for (int i = 0; i < s.size(); ++i) {
		memoArray[i][i] = 1;
	}
	
	for (int i = 0; i < s.size(); ++i) {
		//reference to memoArray
		int row = 0;
		int col = i+1;
		while ( (row < s.size()) && (col < s.size()) ) {
			//check if elements are equal, check if transform is possible
			//if equal get n+2
			if ( graphConComp[ s[row] ] ==  graphConComp[ s[col] ]) {
				memoArray[row][col] = memoArray[row + 1][col - 1] + 2;				
			}
			//else get the max from left or bottom element
			else{
				memoArray[row][col] = max( memoArray[row][col - 1], memoArray[row + 1][col]);
			}
			++row;
			++col;
		}
	}
/*
	//print memoization array
	for(int a0 = 0; a0 < s.size(); a0++) {
		for(int a1 = 0; a1 < s.size(); a1++) {
			cout << memoArray[a0][a1] << " ";
		}
		cout << endl;
	}
*/
	//longest palindromic subsequence is on top right element of Memoization Array
	return	memoArray[0][s.size()-1];
}


//Recursive DFS of connected component. Set the same cc in graphConComp
void dfs( int &s, int &cc, vector<int> & graphConComp, vector<vector<int>> & inTrans ) {
    graphConComp[s] = cc;
    for ( vector<int>::iterator it = inTrans[s].begin(); it != inTrans[s].end(); ++it ) {
        if ( !graphConComp[*it] ) {
            dfs( *it, cc, graphConComp, inTrans );
		}
	}
	return;
}

//get input for available transformations and store as Adjacency vector
void getTransformations(int & k, vector<vector<int>> & inTrans) {
    for ( int i = 0; i < k; ++i ) {
        int x, y;
        cin >> x >> y;
		//due to 1st defined property
		inTrans[x].push_back(y);
		inTrans[y].push_back(x);
    }
	return;
}


int main() {
	//n letters
	//k # of transformations
	//m length of sequence
    int n, k, m;
    cin >> n >> k >> m;

	vector<vector<int>> inTrans(n+1);
	getTransformations(k, inTrans);
	
	vector<int> graphConComp(n+1, 0);
	int cc = 1;
	//find connected components in the Graph
    for ( int i = 1; i < graphConComp.size(); ++i ) {
        if ( !graphConComp[i] ) {
            dfs(i, cc, graphConComp, inTrans);
            ++cc;
        }
	}
	
	//get input sequence to be processed
    vector<int> s(m);
    for(int i = 0; i < m; ++i){
       cin >> s[i];
    }

/*
	//print aplhabetTransform
	for(int a0 = 1; a0 < inTrans.size(); a0++){
        cout << a0 << " ";
        if (!inTrans[a0].empty()){         
            for(set<int>::const_iterator cit = inTrans[a0].begin(); cit != inTrans[a0].end(); ++cit){
                cout << *cit << " ";
            }
        }
		cout << endl;
    }
*/
	cout << LPS(s, inTrans, graphConComp);

    return 0;
}