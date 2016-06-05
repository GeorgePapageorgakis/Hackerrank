/*
Markov takes out his Snakes and Ladders game and stares at the board, and wonders: If he had absolute control on the die, and could get it to generate any number (in the range 1-6) he desired, what would be the least number of rolls of the die in which he'd be able to reach the destination square (Square Number 100) after having started at the base square (Square Number 1)?

Rules:
    1. Markov has total control over the die and the face which shows up every time he tosses it. You need to help him figure out the minimum number of moves in which he can reach the target square (100) after starting at the base (Square 1).

    2. A die roll which would cause the player to land up at a square greater than 100, goes wasted, and the player remains at his original square. Such as a case when the player is at Square Number 99, rolls the die, and ends up with a 5.

    3. If a person reaches a square which is the base of a ladder, (s)he has to climb up that ladder, and he cannot come down on it. If a person reaches a square which has the mouth of the snake, (s)he has to go down the snake and come out through the tail - there is no way to climb down a ladder or to go up through a snake.

Input:
2
2
5 66
9 88
1
67 8
1
3 90
7
99 10
97 20
98 30
96 40
95 50
94 60
93 70

Output:
4
-1
*/
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>      // std::pair, std::make_pair
#include <climits>    //INT_MAX

using namespace std;

//assume 0-99 for possible board coordinates
void initAdjacentList(vector<vector<pair<int,int>>>& edges){
	//reset
	edges.clear();
    edges.resize(100);
    
	//add normal routes of cost=1
	for(int v = 0; v<edges.size(); ++v){
		for(int i = 1; i<7; i++){
			if(i+v > edges.size()-1)
				break;
			else{
				edges[v].push_back(make_pair(1, v+i));
			}
		}
	}
    return;
}

void updateAdjacentMatrix(vector<vector<pair<int,int>>>& edges, pair<int,int>& edge){
    edges[edge.first-1].resize(1);
    edges[edge.first-1][0] = make_pair(0, edge.second-1);
}

void printAdjacentMatrix(vector<vector<pair<int,int>>>& edges){
    //print graph
    for(int v = 0; v<edges.size(); ++v){
        for(int i = 0; i<edges[v].size(); ++i){
            cout << edges[v][i].first << "-" << edges[v][i].second << "  ";
        }
        cout << endl;
    }
    return;
}

int shortestPathDijkstra(vector<vector<pair<int,int>>>& edges, int source, int target){
    //create vertex set Q smallest element to appear as the top()
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    //Unknown distance from source to v
    vector<int> dist(100, INT_MAX);
    // Predecessor of v -1 stands for unreached vertex
    vector<int> prev(100, -1);
    
    // Initialization
    dist[0] = 0;    
    //Instead of filling the priority queue with all nodes in the initialization phase, 
    //it is also possible to initialize it to contain only source
    Q.push(make_pair (0, 0));
    
    // The main loop
    while(!Q.empty()){
        //u ← Q.extract_min() Remove and return best vertex
        //if we find target break loop since we already have the min path due to prio_queue
        //if (Q.top().second == target) break;
        pair<int,int> edge = Q.top();
        Q.pop();
        int current = edge.second;
        //for each neighbor v of u - only v that is still in Q
        for (vector<pair<int,int>>::iterator it=edges[current].begin(); it!=edges[current].end(); ++it){
            // A shorter path to v has been found
            if (dist[current] + it->first < dist[it->second]){
                dist[it->second] = dist[current] + it->first;
                prev[it->second] = current;
                Q.push (make_pair(dist[it->second], it->second));
            }
        }
    } 
    return (dist[99]<INT_MAX ? dist[99] : -1);
}


int main() {
    int T, N;
	//pair is <weight, destination>, index corresponds to vertex
    vector<vector<pair<int, int>>> edges(0);   

    /**
		** Adjacency List for graph representation **
		ladders and snakes have a cost = 0, normal cost is 1
    */
	//# of test cases 
    cin >> T;
    for(unsigned t=0; t<T; ++t){
		pair<int, int> edge;       
        //initialize array
        initAdjacentList(edges);
		//print graph
		//printAdjacentMatrix(edges);
	
        //get ladders
        cin >> N;
        for(unsigned j=0; j<N; ++j){
            cin >> edge.first >> edge.second;
            updateAdjacentMatrix(edges, edge);
        }
        //get snakes
        cin >> N;
        for(unsigned j=0; j<N; ++j){
            cin >> edge.first >> edge.second;
            updateAdjacentMatrix(edges, edge);
        }
        //printAdjacentMatrix(edges);
        
        cout << shortestPathDijkstra(edges, 0, 99) << endl;
    }
    return 0;
}