/*
Two cats named A and B are standing at integral points on the x-axis. Cat A is standing at point x and cat  is standing at point y. Both cats run at the same speed, and they want to catch a mouse named C that's hiding at integral point z on the x-axis. Can you determine who will catch the mouse?

You are given q queries in the form of x, y, and z. For each query, print the appropriate answer on a new line:

    If cat A catches the mouse first, print Cat A.
    If cat B catches the mouse first, print Cat B.
    If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes.

Constraints:
	1 <= q <= 100
	1 <= x,y,z <= 100

Sample Input 0
3
1 2 3
1 3 2
2 1 3

Sample Output 0
Cat B
Mouse C
Cat A
*/
#include <iostream>

using namespace std;

string distanceCatch(int x, int y, int z){
	string result = "";
	int A_Cdistance = abs(z - x);
	int B_Cdistance = abs(z - y);
	
	if (A_Cdistance < B_Cdistance) {
		result =  "Cat A";
	}
	else if (A_Cdistance > B_Cdistance) {
		result = "Cat B";
	}
	else {
		result = "Mouse C";
	}
	return result;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
		cout << distanceCatch(x,y,z);
    }	
    return 0;
}
