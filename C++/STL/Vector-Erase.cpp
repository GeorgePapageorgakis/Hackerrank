#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int x, a, b;
    cin >> x;
    vector<int> v(x,0);
    for(unsigned i=0; i<x; ++i){
        cin >> v[i];
    }
    cin >> x;
    cin >> a >> b;

    //remove single element
    if( x>0 && x<v.size() )
        v.erase(v.begin() + x -1);
    //remove range
    if( a<b &&  b<v.size() )
        v.erase(v.begin()+a-1, v.begin()+b-1);
    
    cout << v.size() << endl;
    for_each(v.begin(), v.end(), [&](int i){cout << i << ' ';});
    return 0;
}
