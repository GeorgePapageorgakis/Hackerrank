/*
A queen is standing on an n x n chessboard. The chessboard's rows are numbered from 1 to n, going from bottom to top; its columns are numbered from 1 to n, going from left to right. Each square on the board is denoted by a tuple, (r, c), describing the row, r, and column, c, where the square is located.

The queen is standing at position (rq, cq) and, in a single move, she can attack any square in any of the eight directions (left, right, up, down, or the four diagonals). 

Constraints:
	0 <= n <= 10^5
	0 <= k <= 10^5
	A single cell may contain more than one obstacle; however, it is guaranteed that there will never be an obstacle at position (rq, cq) where the queen is located.

Sample Input 0
4 0
4 4

Sample Output 0
9


Sample Input 1
5 3
4 3
5 5
4 2
2 3

Sample Output 1
10
*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int numOfSquaresQueenAttack(vector<pair<int, int>> &obstacles, int &rQueen, int &cQueen, int &n) {
	//find max posible square hits in 8 directions (like compass)
	int N = n - rQueen;
	int NE = min(n - rQueen, n - cQueen);
	int E = n - cQueen;
	int SE = min(rQueen - 1, n - cQueen);
	int S = rQueen - 1;
	int SW = min(rQueen - 1, cQueen - 1);
	int W = cQueen - 1;
	int NW = min(n - rQueen, cQueen - 1);
	
	//PAIR: first for ROW, second for COLUMN
	int rObstacle = 0;
	int cObstacle = 0;
	//check the 4 major directions
	for(int i = 0; i < obstacles.size(); ++i) {
		rObstacle = obstacles[i].first;
		cObstacle = obstacles[i].second;
		
		//check perpendicular indices and exclude indices beyond obstacles
		if (cQueen == cObstacle) {
			//N
			if ((rObstacle > rQueen) && (rObstacle - rQueen - 1 < N))
				N = rObstacle - rQueen - 1;
			//S
			else if ((rObstacle < rQueen) && (rQueen - rObstacle - 1 < S))
				S = rQueen - rObstacle - 1;
		}
		//check horizontal indices
		else if (rQueen == rObstacle) {
			//E
			if ((cObstacle > cQueen) && (cObstacle - cQueen - 1 < E))
				E = cObstacle - cQueen - 1;
			//W
			else if ((cObstacle < cQueen) && (cQueen - cObstacle - 1 < W))
				W = cQueen - cObstacle - 1;
		}
		//check y = x indices
		else if (rObstacle - rQueen == cObstacle - cQueen) {
			//NE
			if ((rObstacle > rQueen) && (rObstacle - rQueen - 1 < NE))
				NE = rObstacle - rQueen - 1;
			//SW
			else if ((rQueen > rObstacle) && (rQueen - rObstacle - 1 < SW))
				SW = rQueen - rObstacle - 1;
		}
		//check y = -x indices
		else if (abs(rObstacle - rQueen) == abs(cObstacle - cQueen)) {
			//NW
			if ((rObstacle > rQueen) && (rObstacle - rQueen - 1 < NW))
				NW = rObstacle - rQueen - 1;
			//SE
			else if ((rQueen > rObstacle) && (rQueen - rObstacle - 1 < SE))
				SE = rQueen - rObstacle - 1;
		}
	}
	return N + NE + E + SE + S + SW + W + NW;	
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
	vector<pair<int, int>> obstacles(k);
    cin >> rQueen >> cQueen;
    for(int a0 = 0; a0 < k; a0++){
        cin >> obstacles[a0].first >> obstacles[a0].second;      
    }
	
	cout << numOfSquaresQueenAttack(obstacles, rQueen, cQueen, n);
    return 0;
}
