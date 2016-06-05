/*
Given a time in AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24 hour clock.

Input Format:

A single string containing a time in 12-hour clock format (i.e.: hh:mm:ssAM or hh:mm:ssPM), where 01≤hh≤12.

Output Format

Convert and print the given time in 24-hour format, where 00≤hh≤23.
*/
#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    
    if ( time.find("PM") != std::string::npos) {
        if (stoi(time.substr(0,2)) != 12)
            time = to_string(stoi(time.substr(0,2)) + 12) + time.substr(2,8);
    }
    else if ((stoi(time.substr(0,2))) == 12){
        time = to_string(0) + to_string(0) + time.substr(2,8);
    }
	cout << time.substr(0,8) << endl;
    
    return 0;
}
