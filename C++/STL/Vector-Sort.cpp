#include <iterator>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    //discard characters until newline is found
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 

    vector<int> v( std::istream_iterator<int>( std::cin ), std::istream_iterator<int>() );
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [&](int i){cout << i << ' ';});
    return 0;
}