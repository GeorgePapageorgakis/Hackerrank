/*
Given the time in numerals we may convert it into words, as shown below:

	5:00 five o' clock
	5:01 one minute past five
	5:10 te minutes past five
	5:15 quarter past five
	5:30 half past five
	5:40 twenty minutes to six
	5:45 quarter to six
	
Write a program which prints the time in words for the input given in the format mentioned above.

Constraints:
	1 <= H < 12
	0 <= M < 60
	
Sample Input
5  
47  

Sample Output
thirteen minutes to six
*/
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getTimeInWords(int h, int m) {
	string timeStr = "";
	map <int, string> timeMap = {
		{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, 
		{6, "six"}, {7, "seven"}, {8, "eigth"}, {9, "nine"}, {10, "ten"}, 
		{11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "quarter"},
		{16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"},
		{21, "twenty one"},{22, "twenty two"}, {23, "twenty three"}, {24, "twenty four"}, {25, "twenty five"},
		{26, "twenty six"},{27, "twenty seven"},{28, "twenty eight"},{29, "twenty nine"},{30, "half"}};
	
	
	if (m == 0)
		timeStr = timeMap[h] + " o' clock";
	else
        timeStr = (m > 30 ? timeMap[60 - m] : timeMap[m])
		+ (m != 1 ? ((m % 15) != 0 ? " minutes" : "" ) : " minute") 
		+ (m > 30 ? " to " : " past ") 
		+ (m > 30 ? timeMap[(h+1)] : timeMap[h]);
	return timeStr;
}
int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
	cout << getTimeInWords(h, m);
    return 0;
}
