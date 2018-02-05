/*
Bob has a strange counter. At the first second, t = 1, it displays the number 3. At each subsequent second, the number displayed by the counter decrements by 1.

The counter counts down in cycles. In the second after the counter counts down to 1, the number becomes x2 the initial number for that countdown cycle and then continues counting down from the new initial number in a new cycle. The diagram below shows the counter values for each time in the first three cycles:

	time value		time value		time value
	  1	   3	 	4     6	 		10	  12
	  2	   2		5	  5			11	  11
	  3	   1		6	  4			12	  10
					7	  3			13	  9
					8	  2			14	  8
					9	  1			15	  7
									...
									21	  1
Constraints:
	1 <= t <= 10^12

Sample Input:
4
Sample Output:
6

Sample Input:
1000000000000
Sample Output:
649267441662
*/
#include <iostream>

using namespace std;

long long calcStrangeCounterVal(long long t) {
    long long cycleNum = 3;
    while (t > cycleNum) {
        t = t - cycleNum;
        cycleNum *= 2;
    }
    return cycleNum - t + 1;
}
int main(){
    long long t;
    cin >> t;
    cout << calcStrangeCounterVal(t);
    return 0;
}