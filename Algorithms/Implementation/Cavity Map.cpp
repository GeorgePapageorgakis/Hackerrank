/*
You are given a square map of size n×n. Each cell of the map has a value denoting its depth. We will call a cell of the map a cavity if and only if this cell is not on the border of the map and each cell adjacent to it has strictly smaller depth. Two cells are adjacent if they have a common side (edge).

You need to find all the cavities on the map and depict them with the uppercase character X. 
*/
#include <vector>
#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0;grid_i < n;++grid_i){
       cin >> grid[grid_i];
    }
    
    //modify grid
    for(int grid_i = 1; grid_i < n - 1; ++grid_i){
        for(int grid_j = 1; grid_j < n - 1; ++grid_j){
            if (grid[grid_i-1][grid_j] < grid[grid_i][grid_j] &&
                grid[grid_i][grid_j-1] < grid[grid_i][grid_j] &&
                grid[grid_i][grid_j+1] < grid[grid_i][grid_j] &&
                grid[grid_i+1][grid_j] < grid[grid_i][grid_j] )
                
                grid[grid_i][grid_j] = 'X';
        }
    }
    
    //print modified grid
    for(int grid_i = 0; grid_i < n; ++grid_i){
        cout << grid[grid_i] << endl;
    }
    return 0;
}
