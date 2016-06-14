/*
There are plants in a garden. Each of these plants has been added with some amount of pesticide. After each day, if any plant has more pesticide than the plant at its left, being weaker than the left one, it dies. You are given the initial values of the pesticide in each plant. Print the number of days after which no plant dies, i.e. the time after which there are no plants with more pesticide content than the plant to their left. 
Sample Input:
	7
	6 5 8 4 7 10 9

Sample Output:
	2

Use of the stock span problem ( http://www.geeksforgeeks.org/the-stock-span-problem/ )algorithm to find the "killers". 

Use stack to keep all the plants that are not destroyed and the number of days that they are in that state.
Reverse iterate all the elements that are stored in the vector

The top of the stack contains the latest tree from the back that is not destoyed. 
Until and unless the tree is dead we cant go more rightward.

For every element in trees.top() we compare it with the top of the stack to check if the tree.top() is greater than the top of the stack and then we push the pair tree.top() with 0 in the stack.
If the element tree.top() is less then the top of the stack it means the plant dies and the current value is max(days+1, max_days).

Repeat the process until the element tree.top() is lesser.
Push tree.top() value to the stack. At every iteration the max_days is updated as max(days, max_days).
The plant that dies is no more present in the day.


*/
#include <stack>
#include <iostream>
using namespace std;

// A stack based efficient method based on stock span problem
int calcMaxDaysKilled(stack<int>& s){
    int max_days = 0;
    // Create a stack and push index of first element from the end to it
    stack<pair<int, int>> st;
    st.push(make_pair(s.top(), 0));
    s.pop();

    // Calculate span values for rest of the elements
    while( !s.empty()){
        int days = 0;
        // Pop elements from stack while stack is not empty and top of
        // stack is larger than plant[i]
        while( (!st.empty()) && st.top().first > s.top()){
            days = max(days+1, st.top().second);
            st.pop();
        }
        //keep tracking calculated days
        max_days = max(max_days, days);
        // Push this element to stack
        st.push(make_pair(s.top(), days));
        s.pop();
    }
    return max_days;
}

int main(){
    int n;
    stack<int> s, ss;
    cin >> n;

    while (cin >> n){
        s.push(n);
    }
    /*
    for(auto i : s)
        cout << i << " ";
    cout << endl;
    */
    cout << calcMaxDaysKilled(s) << endl;
    return 0;
}
