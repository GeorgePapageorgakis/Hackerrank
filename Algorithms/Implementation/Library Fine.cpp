/*
Local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:

    If the book is returned on or before the expected return date, no fine will be charged (i.e.: fine=0).
    If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, fine=15 Hackos × (the number of days late).
    If the book is returned after the expected return month but still within the same calendar year as the expected return date, the fine=500 Hackos × (the number of months late).
    If the book is returned after the calendar year in which it was expected, there is a fixed fine of 10000 Hackos.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d1, m1, y1;
    cin >> d1 >> m1 >> y1;
    int d2, m2, y2;
    cin >> d2 >> m2 >> y2;
    
    if (y1 > y2)           //if actual year is greater
        cout << 10000;
    else if (y1 < y2)      //if actual year is lower
        cout << 0;
    else{                 //else if year is the same
        if (m1 > m2)            //if actual months is greater
            cout << (m1-m2)*500;
        else if (m1 < m2)      //if actual months is lower
            cout << 0;
        else{ 
            if (d1 > d2)
                cout << (d1-d2)*15;
            else
                cout << 0;
        }
    }
    return 0;
}
