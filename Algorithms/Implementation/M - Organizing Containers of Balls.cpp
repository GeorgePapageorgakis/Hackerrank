/*
David has n containers and n different types of balls, both of which are numbered from 0 to n-1. The distribution of ball types per container are described by an n x n matrix of integers, M, where each Mc,t is the number of balls of type t in container c. For example, consider the following diagram for : M = [ [1,4], [2,3] ].

David wants to perform some number of swap operations such that both of the following conditions are satisfied:

    Each container contains only balls of the same type.
    No two balls of the same type are located in different containers.

You must perform q queries where each query is in the form of a matrix, M. For each query, print Possible on a new line if David can satisfy the conditions above for the given matrix; otherwise, print Impossible instead.

Input Format

The first line contains an integer denoting q (the number of queries). The subsequent lines describe each query in the following format:

    The first line contains an integer denoting n (the number of containers and ball types).
    Each line i of the n subsequent lines contains n space-separated integers describing row i in matrix M.

Constraints:
	1 <= q <= 10
	1 = n <= 100
	0 <= Mc,t <= 10^9
	
Sample Input 0
2
2
1 1
1 1
2
0 2
1 1

Sample Output 0
Possible
Impossible
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool  checkContainerSameBallType(vector< vector<int> > & M) {

	//count the number of balls that each container has
	vector<long long> ballsPerContainer (M[0].size(), 0);
	for(int contIdx = 0; contIdx < M[0].size(); ++contIdx) {
		ballsPerContainer[contIdx] = accumulate(M[contIdx].begin(), M[contIdx].end(), (long long)0 );
	}
	
	//count the number of balls that each ball type has
	vector<long long> ballsPerType (M[0].size(), 0);
	for(int BallTypeIdx = 0; BallTypeIdx < M[0].size(); ++BallTypeIdx) {
		unsigned long ballsPerType;
		ballsPerType = 0;
		//calculate balls per type
		for(int contIdx = 0; contIdx < M[0].size(); ++contIdx) {
			ballsPerType += M[contIdx][BallTypeIdx];
		}
		//check if ballsPerType match with a container size if not its impossible to distribute balls so return false
		vector<long long>::iterator it;
        it = find (ballsPerContainer.begin(), ballsPerContainer.end(), ballsPerType);
		if ( it != ballsPerContainer.end() ){
			*it = 0;
		}
		else 
			return false;
	}
	return true;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector< vector<int> > M(n,vector<int>(n));
        for(int M_i = 0; M_i < n; M_i++){
           for(int M_j = 0;M_j < n;M_j++){
              cin >> M[M_i][M_j];
           }
        }
        cout << (checkContainerSameBallType(M) ? "Possible" : "Impossible") << endl;
    }
    return 0;
}