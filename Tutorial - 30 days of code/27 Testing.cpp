#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime> 
/*
Create and print one or more test cases for the problem above that meet the following criteria:
  *  T≤5T
  *  1≤N≤200
  *  1≤K≤N
  *  −1000≤ai≤1000,where i∈[1,N]
  *  The value of N should be distinct across all the test cases.
  *  Array a must have at least 1 zero, 1 positive integer, and 1 negative integer.
*/

int main(){
    int T, N, zero, pos, neg;
    std::vector<int> N_vals;
    std::srand((unsigned)std::time(NULL));
    
    T = 5;
    std::cout << T << std::endl;
    
    //distinct values of N
    while (N_vals.size() < T){
        int i = (std::rand() % 200) + 1;
        if(find(N_vals.begin(), N_vals.end(), i) == N_vals.end() )
            N_vals.push_back(i);
    }
    
    for (int i=0; i<T; ++i){
        //generate random index for a mandatory zero, negative and positive
        zero = std::rand() % N_vals[i];
        do{         
            neg = std::rand() % N_vals[i];
            pos = std::rand() % N_vals[i];
        }while( zero!=neg && neg!=pos && zero!=pos);
        
        //print N and K
        std::cout << N_vals[i] << ' '<< (std::rand()%N_vals[i]) + 1 << std::endl;
        //print the a values
        for (int j=0; j<N_vals[i]; ++j){
            if(j==zero)
                std::cout << 0 << ' ';
            else if(j==neg)
                std::cout << (std::rand() % (1000) ) - 1000 << ' ';
            else if(j==pos)
                std::cout << (std::rand() % (1000)) + 1 << ' ';
            else
                std::cout << (std::rand() % (2001) ) - 1000 << ' ';
        }
        std::cout << std::endl;
    }    
    return 0;
}