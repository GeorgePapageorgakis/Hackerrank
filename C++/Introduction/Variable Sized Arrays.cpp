/*
Sample Input
2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3

Sample Output
5
9
*/

#include <iostream>
using namespace std;

int main() {
    int N, Q, seqLen, a, b;
    cin >> N >> Q;
    int** array2d = new int* [N];
    //store length of each sequence to avoid Undefined Behavior
    int* arrSize = new int [N];
    
    for(unsigned i=0; i<N; ++i){
        cin >> arrSize[i];
        array2d[i] = new int[arrSize[i]];
        for(unsigned j=0; j<arrSize[i]; ++j){
            cin >> array2d[i][j];
        }
    }
    //print
	/*
    for(unsigned i=0; i< N; ++i){
        for(unsigned j=0; j<arrSize[i]; ++j){
            cout << array2d[i][j] << ' ';
        }
        cout << endl;
    }
	*/
    //check queries
    for(unsigned i=0; i<Q; ++i){
        cin >> a >> b;
        cout << array2d[a][b] << endl;
    }
   
    //deallocate memory
    delete [] arrSize;
    for(unsigned i=0; i<N; ++i){
        delete [] array2d[i];
    }
    delete [] array2d;

	return 0;
}
