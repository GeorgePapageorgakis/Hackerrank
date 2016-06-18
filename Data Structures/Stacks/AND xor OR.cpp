/*
Given an array A[] of N distinct elements. Let M1 and M2 be the smallest and the next smallest element in the interval [L, R] where 1<= L < R <= N.

	Si = (((M1 AND M2) XOR (M1 OR M2)) AND (M1 XOR M2))

Your task is to find the maximum possible value of Si.
Sample Input
5
9 6 3 5 2

Sample Output
15

we can furthe simplify the above boolean function:
(((A B) ^ (A + B)) (A ^ B)) =						apply A ^ B = (A'B) + (A B')
( ((A B)' (A + B)) + ((A B) (A + B)')) (A ^ B)) = 	apply DeMorgan law (X+Y+...)'=X'Y'Z'... and (XYZ...)'=X'+Y'+...
( ((A' + B') (A + B)) + ((A B) (A' B'))) (A ^ B)) =	apply Distributive Law X(Y+Z) = XY + XZ
(A'A + A'B + AB' + BB' + AA' + BB') (A ^ B) =		apply XX'= 0
(A'B + AB') (A ^ B) =								apply X+X=X, XX=X
(A ^ B) (A ^ B) = A ^ B = A xor B

The are mainly 2 cases:
1.	Element that is the "first smaller" or as the L in interval [L, R], hence we have to find the next smaller R in the whole range
2.	Element that is the "second smaller" or as the R in interval [L, R], hence we have to find the previous smaller L in the whole range.

based on http://stackoverflow.com/questions/32411196/find-largest-possible-value-of-ss-min2%E2%88%A7min-where-min2-min-are-smallest-n
*/

#include <stack>
#include <climits>
#include <iostream>
using namespace std;

/*
for each X in array A:
    while NOT stack.empty AND stack.top > X: 
		stack.pop
    if NOT stack.empty:
        result = max(result, X XOR stack.top)
    stack.push(X)
reverse array A and repeat
*/
long int calcMaxVal(stack<long int>& s){
    long int max_pair = LONG_MIN;
    stack<long int> st, rev;
    
    while(!s.empty()){
        while(!st.empty() && s.top() < st.top()){
            st.pop();
        }
		if (!st.empty())
			max_pair = max(s.top() ^ st.top(), max_pair);
        st.push(s.top());
        rev.push(s.top());
        s.pop();
    }
	
    //apply same technique to the reversed stack
    while(!rev.empty()){
        while(!st.empty() && rev.top() < st.top()){
            st.pop();
        }
        if (!st.empty())
            max_pair = max(rev.top() ^ st.top(), max_pair);
        st.push(rev.top());
        rev.pop();
    }

    return max_pair;
}


int main() {
    int n;
    stack<long int> A;
    cin >> n;

    while (cin >> n){
        A.push(n);
    }

    cout << calcMaxVal(A) << endl;

    return 0;
}