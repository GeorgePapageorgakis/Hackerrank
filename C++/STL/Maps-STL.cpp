/*
You are appointed as the assistant to a teacher in a school and she is correcting the answer sheets of the students.Each student can have multiple answer sheets.So the teacher has Q queries:

1 X Y: Add the marks YYto the student whose name is X.

2 X: Erase the marks of the students whose name is X.

3 X: Print the marks of the students whose name is X. (If X didn't get any marks print 0.)

Sample Input:
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

Sample Output:
30
20
0
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    map<string, int> m;
    int Q, type, x;
    string y;
    //test cases
    cin >> Q;
    for(unsigned i=0; i<Q; ++i){
		cin >> type >> y;
		map<string,int>::iterator it=m.find(y);
        
		switch ( type ) {
		case 1:
            cin >> x;
			if(it != m.end())
				it->second += x;
            else
                m.insert(make_pair(y,x));
			break;
		case 2:
			if(it != m.end())
				m.erase(it);
			break;
		case 3:
			if(it != m.end())
				cout << it->second << endl;
            else
                cout << 0 << endl;
			break;
		default:
			break;
		}
    }  
    return 0;
}

