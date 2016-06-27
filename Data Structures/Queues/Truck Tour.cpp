/*
Suppose there is a circle. There are N petrol pumps on that circle. Petrol pumps are numbered 0 to N-1 (both inclusive). You have two pieces of information corresponding to each of the petrol pump: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.

Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps. Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one kilometer for each litre of the petrol.
Sample Input
3
1 5
10 3
3 4

Sample Output
1

Simple solution with integration, the starting point has the total minimum
Since we read input in a queue fashion we do not need to store anything
The accumulated difference (pump liters - liters needed for next station) points a global minimum in the function
no matter where we start. Starting from different station only affects the global minimum value and nothing more as it is still a global minimum.
*/

#include <utility>
#include <iostream>
#include <climits>
using namespace std;

int main() {
    //Petrol pumps are numbered 0 to N-1 (both inclusive).
    //queue<type>'s type must make use of std::pair<type,type>
    int N, curr = 0, idx = 0, min = INT_MAX;
    
    cin >> N;
    for(int i=0; i<N; ++i){
        pair<int, int> aux;
        cin >> aux.first >> aux.second;
        curr += (aux.first - aux.second);
        if (curr < min){
            min = curr;
            idx = i+1;
        }        
    }
	//we can also add a condition here if we get minimum from last element it means that its the first one and not the N+1.
    cout << idx;
    return 0;
}
