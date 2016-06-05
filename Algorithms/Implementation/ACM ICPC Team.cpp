/*
 Given a list of N people who are attending ACM-ICPC World Finals. Each of them are either well versed in a topic or they are not. Find out the maximum number of topics a 2-person team can know. And also find out how many teams can know that maximum number of topics.

Note Suppose a, b, and c are three different people, then (a,b) and (b,c) are counted as two different teams.
Sample Input
	4 5
	10101
	11100
	11010
	00101

Sample Output
	5
	2
*/
#include <bitset>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

/**
	Finds the maximum number of topics a 2-person team can know and how many teams know the maximum # of topics.
    Could use dynamic bitset with Boost...
	
	@param input n persons and their topics known
    @returns a pair: max possible topics known and number of pair of teams that know the max
**/
pair<unsigned int, unsigned int> maxTopics(const int& n, const vector<string>& s ){
    unsigned int max_topics = 0, max_teams = 0;
    
    //find the maximum possible topics per pair
    for (unsigned i=0; i<n; ++i){
        for (unsigned j=i+1; j<n; ++j){
            bitset<500> bs = static_cast<bitset<500>>(s[i])|static_cast<bitset<500>>(s[j]);
            if (bs.count() > max_topics)
                max_topics = bs.count();
        }
    }
    //find # of pairs that form max possible topics
    for (unsigned i=0; i<n; ++i){
        for (unsigned j=i; j<n; ++j){
            bitset<500> bs = static_cast<bitset<500>>(s[i])|static_cast<bitset<500>>(s[j]);
            if (bs.count() == max_topics)
                ++max_teams;
        }
    }
    return make_pair(max_topics, max_teams);
}

int main(){
    int n;  //people
    int m;  //topics
    cin >> n >> m;
    //vector<bitset<m>> topic(n);
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    
    const pair<unsigned int, unsigned int>& pmax = maxTopics(n, topic);
    cout << pmax.first << endl << pmax.second << endl;
    
    return 0;
}