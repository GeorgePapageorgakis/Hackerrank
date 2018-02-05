/*
Day of the Programmer is an international professional day recognized in many technology companies and programming firms, that is celebrated on the 256th day of each year (September 13 during common years and on September 12 in leap years).

To test if its the Day of the Programmer (the 256th day of the year) during a year in the inclusive range from 1700 to 2700.

From 1700 to 1917, Russia's official calendar was the Julian calendar; since 1919 they used the Gregorian calendar system. The transition from the Julian to Gregorian calendar system occurred in 1918, when the next day after January 31st was February 14th. This means that in 1918, February 14 was the 32nd day of the year in Russia.

In both calendar systems, February is the only month with a variable amount of days; it has 29 days during a leap year, and 28 days during all other years. In the Julian calendar, leap years are divisible by 4; in the Gregorian calendar, leap years are either of the following:

    Divisible by 400.
    Divisible by 4 and not divisible by 100.

Given a year, y, find the date of the 256 day of that year according to the official Russian calendar during that year. Then print it in the format dd.mm.yyyy, where dd is the two-digit day, mm is the two-digit month, and yyyy is y.

Constraints:
	1700 <= y <= 2700
	
Sample Input 0
2017

Sample Output 0
13.09.2017

Sample Input 1
2016

Sample Output 1
12.09.2016
**/
#include <bits/stdc++.h>

using namespace std;

string solve(int year){
	short int day256 = 0;
	bool isLeapYear = false;
	short int sumEightMonths = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;

	if (year > 1918){
		isLeapYear = ( !(year%400) ) || ( !(year%4) && (year%100) );
		if (isLeapYear){
			day256 = 256 - sumEightMonths - 1;
		}
        else{
            day256 = 256 - sumEightMonths;
        }
	}
	else if (year < 1918){
		isLeapYear =  !(year%4);
		if (isLeapYear){
			day256 = 256 - sumEightMonths - 1; //1 extra day for Leap year Feb
		}
        else{
            day256 = 256 - sumEightMonths;
        }
	}
	//The transition from the Julian to Gregorian calendar system occurred in 1918, when the next day after January 31 was February 14. This means that in 1918, February 14 was the 32nd day of the year in Russia.
	//1918 is leap year
    else if (year == 1918){
		day256 = 26;
    }

	return to_string(day256) + ".09." + to_string(year);
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}