/*
 Each rock is composed of various elements, and each element is represented by a lower-case Latin letter from 'a' to 'z'. An element can be present multiple times in a rock. An element is called a gem-element if it occurs at least once in each of the rocks.

Given the list of N rocks with their compositions, display the number of gem-elements that exist in those rocks.

Sample Input
3
abcdde
baccd
eeabg

Sample Output
2
*/
#include <iterator>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

//Given the list of N rocks with their compositions, display the number of gem-elements that exist in those rocks.
int numGemElements(std::vector<string>& vs){
    std::bitset<26> gems, elems;
    gems.set();
    for (auto s : vs){
        elems.reset();
        for (auto c : s){
            elems.set(c - 'a');
        }
        gems &= elems;
    }
    return gems.count();
}


int main() {
    std::string s;
    int n;
    std::cin >> n;
    std::vector<string> vs( std::istream_iterator<string>( std::cin ), std::istream_iterator<string>() );
    
    std::cout << numGemElements(vs);

    return 0;
}
