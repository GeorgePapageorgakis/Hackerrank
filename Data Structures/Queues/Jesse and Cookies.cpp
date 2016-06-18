/*
Jesse loves cookies. He wants the sweetness of all his cookies to be greater than value k. To do this, Jesse repeatedly mixes two cookies with the least sweetness. He creates a special combined cookie with:

sweetness = (Least sweet cookie + 2 * 2nd least sweet cookie).

He repeats this procedure until all the cookies in his collection have a sweetness >= k.
You are given Jesse's cookies. Print the number of operations required to give the cookies a sweetness >= k. Print -1 if this isn't possible.
Sample Input
6 7
1 2 3 9 10 12

Sample Output
2
*/
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int calcSweetness (priority_queue<int,vector<int>,greater<int>>& source, int& k){
    int count=0;
    while(source.top() < k) {
        if(source.size() > 1) {
            count++;
            int temp1 = source.top();
            source.pop();
            int temp2 = source.top();
            source.pop();
            source.push(temp1 + (temp2 * 2));
        }
        else {
            return -1;
        }
    }
    return count;
}

int main() {
    int N, k;
    bool gtk = true;
    priority_queue<int,vector<int>,greater<int>> sweetness;
    cin >> N >> k;

    while (cin >> N){
        //need to process cookie if sweetness >= k
        //only 1 cookie >= k is needed for lower bound sweetness case
        if(N < k)
            sweetness.push(N);
        else if (gtk){
            sweetness.push(N);
            gtk = false;
        }
    }
    
    cout << calcSweetness(sweetness, k);
    
    return 0;
}
