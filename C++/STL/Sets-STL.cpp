/*
Given Q queries.Each query is of one of the three types:

1 x: Add an element x to the set.
2 x: Delete an element x from the set. (If the number x is not present in the set then do nothing).
3 x: If the number x is present in the set then print "Yes"(without quotes) else print "No"(without quotes).

Input Format:
	The first line of the input contains Q where Q is the number of queries. The next Q lines contain 1 query each. Each query consists of two integers y and x where y is the type of the query and x is an integer.

Output Format:
	For queries of type 3 print "Yes"(without quotes) if the number x is present in the set and if not present then print "No"(without quotes).
	Each query of type 3 should be printed in a new line.

Sample Input:
8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output:
Yes
No
No
*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int Q, x, y;
    set<int> s;

    //test cases
    cin >> Q;
    for(unsigned i=0; i<Q; ++i){
		cin >> y >> x;
		set<int>::iterator it = s.find(x);
		
		switch ( y ) {
		case 1:
			if(it == s.end())
				s.insert(x);
			break;
		case 2:
			if(it != s.end())
				s.erase(it);
			break;
		case 3:
			if(it != s.end())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			break;
		default:
			break;
		}
    }  
    return 0;
}
