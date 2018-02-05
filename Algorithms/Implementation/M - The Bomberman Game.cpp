/*
Bomberman lives in a rectangular grid with R rows and C columns. Each cell in the grid either contains a bomb or nothing at all.

Each bomb can be planted in any cell of the grid but, once planted, it will detonate after exactly 3 seconds. Once a bomb detonates, it's destroyed — along with anything in its four neighboring cells. This means that if a bomb detonates in cell i, j, cells (i +- 1, j) and (i, j +- 1) are cleared (note that cells at the edge of the grid have less than four neighboring cells). If there is a bomb in a neighboring cell, the neighboring bomb is destroyed without detonating (i.e., no chain reaction occurs).

Bomberman is immune to bombs, so he can move freely throughout the grid. Here's what he does:

    1. Initially, Bomberman arbitrarily plants bombs in some of the cells.
    2. After one second, Bomberman does nothing.
    3. After one more second, Bomberman plants bombs in all cells without bombs, thus filling the whole grid with bombs. It is guaranteed that no bombs will detonate at this second.
    4. After one more second, any bombs planted exactly three seconds ago will detonate. Here, Bomberman stands back and observes.
    5. Bomberman then repeats steps 3 and 4 indefinitely.

Note that during every second Bomberman plants bombs, the bombs are planted simultaneously (i.e., at the exact same moment), and any bombs planted at the same time will detonate at the same time.

Given the initial configuration of the grid with the locations of Bomberman's first batch of planted bombs, determine the state of the grid after N seconds.

Constraints:
	1 <= R, C <= 200
	1 <= N <= 10^9

Sample Input
6 7 3
.......
...O...
....O..
.......
OO.....
OO.....

Sample Output
OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO

*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void updateGrid (vector<vector<char>> &bombGrid, vector<vector<char>> &statesGrid) {
    for (int i = 0; i < bombGrid.size(); ++i) {
        for (int j = 0; j < bombGrid[0].size(); ++j) {
            //update adjacent bombs and then reverse state
            if (bombGrid[i][j] == 'O') {
                if (i > 0)
                    statesGrid[i-1][j] = '.';
                if (i + 1 < bombGrid.size())
                    statesGrid[i+1][j] = '.';
                if (j > 0)
                    statesGrid[i][j-1] = '.';
                if (j + 1 < bombGrid[i].size())
                    statesGrid[i][j+1] = '.';
                statesGrid[i][j] = '.';
            }
        }
    }
}

void updateBombGridAfterTsec (vector<vector<char>> &bombGrid, const long &t) {
	vector<vector<char>> statesGrid(bombGrid.size(), vector<char>(bombGrid[0].size(), 'O'));
	//if t = 1 no changes occur
	if (t == 1)
		return;
	
	//if t is even return full bombs grid
	if (t % 2 == 0){
        for (int i = 0; i < bombGrid.size(); ++i) {
            copy( statesGrid[i].begin(), statesGrid[i].end(), bombGrid[i].begin() );
        }
    }
	//else return t % 4, either 1 or 3 will be returned which means either of the 2 states
	//in case of 3 we only have to detonate once
	else if (t % 4 == 1 || t % 4 == 3) {
		updateGrid(bombGrid, statesGrid);
		//copy stae to bombGrid
		for (int i = 0; i < statesGrid.size(); ++i) {
			copy ( statesGrid[i].begin(), statesGrid[i].end(), bombGrid[i].begin() );
		}
        //in case of 1 we have to detonate bombs twice accordingly
		if (t % 4 == 1) {
			for (int i = 0; i < statesGrid.size(); ++i) {
				for (int j = 0; j < statesGrid[0].size(); ++j) {
					statesGrid[i][j] = 'O';
				}
			}            
            updateGrid(bombGrid, statesGrid);
			//copy stae to bombGrid
			for (int i = 0; i < statesGrid.size(); ++i) {
				copy ( statesGrid[i].begin(), statesGrid[i].end(), bombGrid[i].begin() );
			}
		}
	}
}

int main() {
    int r, c;
	long n;
	cin >> r >> c >> n;
	vector<vector<char>> bombGrid(r, vector<char>(c, '.'));
	
    //get input grid
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> bombGrid[i][j];
		}
	}
	
	updateBombGridAfterTsec(bombGrid, n);
	
	//print output
	for (auto i : bombGrid) {
		for (auto j : i) {
			cout << j;
		}
		cout << endl;
	}
	
    return 0;
}

/*
.......		.......
...3...		...O...
....3..		....O..
.......		.......
33.....		OO.....
33.....		OO.....

1: (step 2)
.......		.......
...2...		...O...
....2..		....O..
.......		.......
22.....		OO.....
22.....		OO.....
___________________

2: (step 3)
3333333		ΟΟΟΟΟΟΟ
3331333		ΟΟΟΟΟΟΟ
3333133		ΟΟΟΟΟΟΟ
3333333		ΟΟΟΟΟΟΟ
1133333		ΟΟΟΟΟΟΟ
1133333		ΟΟΟΟΟΟΟ

3: (step 4)
222.222		ΟΟΟ.ΟΟΟ
22...22		ΟΟ...ΟΟ
222...2		ΟΟΟ...Ο
..22.22		..ΟΟ.ΟΟ
...2222		...ΟΟΟΟ
...2222		...ΟΟΟΟ

4: (step 3)
1113111		ΟΟΟΟΟΟΟ
1133311		ΟΟΟΟΟΟΟ
1113331		ΟΟΟΟΟΟΟ
3311311		ΟΟΟΟΟΟΟ
3331111		ΟΟΟΟΟΟΟ
3331111		ΟΟΟΟΟΟΟ

5: (step 4)
.......		.......
...2...		...O...
....2..		....O..
.......		.......
22.....		OO.....
22.....		OO.....
___________________

6: (step 3)
3333333		ΟΟΟΟΟΟΟ
3331333		ΟΟΟΟΟΟΟ
3333133		ΟΟΟΟΟΟΟ
3333333		ΟΟΟΟΟΟΟ
1133333		ΟΟΟΟΟΟΟ
1133333		ΟΟΟΟΟΟΟ

7: (step 4)
222.222		ΟΟΟ.ΟΟΟ
22...22		ΟΟ...ΟΟ
222...2		ΟΟΟ...Ο
..22.22		..ΟΟ.ΟΟ
...2222		...ΟΟΟΟ
...2222		...ΟΟΟΟ

8: (step 3)
1113111		ΟΟΟΟΟΟΟ
1133311		ΟΟΟΟΟΟΟ
1113331		ΟΟΟΟΟΟΟ
3311311		ΟΟΟΟΟΟΟ
3331111		ΟΟΟΟΟΟΟ
3331111		ΟΟΟΟΟΟΟ

9: (step 4)
.......		.......
...2...		...O...
....2..		....O..
.......		.......
22.....		OO.....
22.....		OO.....
 ___________________
 
 
 
..3.33..3.33		..O.OO..O.OO
......33...3		......OO...O
3......33..3		O......OO..O
.3.33333.3..		.O.OOOOO.O..
33...33.33.3		OO...OO.OO.O

1:
..2.22..2.22		..O.OO..O.OO
......22...2		......OO...O
2......22..2		O......OO..O
.2.22222.2..		.O.OOOOO.O..
22...22.22.2		OO...OO.OO.O
________________________________

2:
331311331311		OOOOOOOOOOOO
333333113331		OOOOOOOOOOOO
133333311331		OOOOOOOOOOOO
313111113133		OOOOOOOOOOOO
113331131131		OOOOOOOOOOOO

3:
2...........		O...........
.2.2.....2..		.O.O.....O..
..2.........		..O.........
............		............
............		............

4:
133333333333		OOOOOOOOOOOO
313133333133		OOOOOOOOOOOO
331333333333		OOOOOOOOOOOO
333333333333		OOOOOOOOOOOO
333333333333		OOOOOOOOOOOO

5:
..2.22222.22		..O.OOOOO.OO
.....222...2		.....OOO...O
2...22222.22		O...OOOOO.OO
22.222222222		OO.OOOOOOOOO
222222222222		OOOOOOOOOOOO
________________________________

6:
331311111311		OOOOOOOOOOOO
333331113331		OOOOOOOOOOOO
133311111311		OOOOOOOOOOOO
113111111111		OOOOOOOOOOOO
111111111111		OOOOOOOOOOOO

7:
2...........		O...........
.2.2.....2..		.O.O.....O..
..2.........		..O.........
............		............
............		............

8:
133333333333		OOOOOOOOOOOO
313133333133		OOOOOOOOOOOO
331333333333		OOOOOOOOOOOO
333333333333		OOOOOOOOOOOO
333333333333		OOOOOOOOOOOO

9:
..2.22222.22		..O.OOOOO.OO
.....222...2		.....OOO...O
2...22222.22		O...OOOOO.OO
22.222222222		OO.OOOOOOOOO
222222222222		OOOOOOOOOOOO
 */